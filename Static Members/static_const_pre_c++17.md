<img width="1728" height="699" alt="Screenshot 2025-12-11 141701" src="https://github.com/user-attachments/assets/862fdf03-5189-43c4-838c-2c5fdee9c18a" />


---

# **Static const Before C++17 — Notes**

## **1. Background**

Before C++17, initialization rules for class member variables were more restrictive. Specifically:

* **Only static const integral types and enums** could be initialized **inside the class definition**.
* All other static members (strings, floats, arrays, pointers, etc.) **must be defined and initialized in a .cpp file**.
* `inline` static members did not exist before C++17, so automatic in-class initialization was not available for non-integral static members.

---

# **2. What CAN be initialized in-class (pre-C++17)?**

Only these types:

### **2.1 Allowed**

* `static const int`
* `static const enum`

### **Example**

```cpp
class Cylinder {
public:
    static const int int_constant = 10;
    enum Color { RED, GREEN, BLUE };
    static const Color color_constant = GREEN;
};
```

These compile successfully before C++17.

---

# **3. What CANNOT be initialized inside the class (pre-C++17)?**

All other static members must be defined and initialized **in a .cpp file**:

* `static const double`
* `static const float`
* `static const char*`
* `static const std::string`
* `static const Arrays`
* Any non-integral constant static type

### **3.1 Example of required .cpp file initialization**

**Header:**

```cpp
class Cylinder {
public:
    static const double PI;
    static const std::string name;
    static const float float_constant;
    static const char* c_string_constant;
    static const int int_array[5];
};
```

**CPP:**

```cpp
#include "Cylinder.h"

const double Cylinder::PI = 3.14159265358979;
const std::string Cylinder::name{"CylinderClass"};
const float Cylinder::float_constant = 6.98f;
const char* Cylinder::c_string_constant = "Hello";
const int Cylinder::int_array[5] = {1,2,3,4,5};
```

---

# **4. Non-static const member variables**

For **non-static const** members:

* They belong to each object, not the class.
* They **must** be initialized using a **constructor initializer list**.
* Initialization **inside the constructor body is not allowed**.

### **Example**

**Header:**

```cpp
class Cylinder {
private:
    const float weird_float;
    const char* weird_cstring;
    const int weird_int_array[3];

public:
    Cylinder();
};
```

**CPP:**

```cpp
Cylinder::Cylinder()
    : weird_float{45.3},           // narrowing OK but compiler may warn
      weird_cstring{"Hello"},      // initialize with string literal
      weird_int_array{1,2,3}       // array initialization
{
    // NOT allowed:
    // weird_float = 10;   // error: assignment to const
}
```

---

# **5. You MUST use an initializer list for const non-static members**

Why?

* Initialization lists run *before* any assignment in the constructor body.
* Const members can only be set once.
* Constructor body assignments represent reassignment → illegal.

---

# **6. Static Initialization Order Fiasco**

A key danger with static members is that:

> **The initialization order of static variables across different translation units is NOT guaranteed.**

Meaning:

* A static variable in one `.cpp` file might not be initialized before another `.cpp` file tries to use it.
* This can lead to uninitialized reads, incorrect values, or application crashes.

### **Example of the problem**

```cpp
// Bird.cpp
const float Bird::weight = Cylinder::float_constant;
```

If `Cylinder::float_constant` is not yet initialized, `Bird::weight` may receive garbage.

### **When does this happen?**

* Different compilation units (.cpp files)
* Variables with static storage duration
* Runtime order varies by compiler, build flags, platform, and even build runs

### **Best practice:**

Avoid initializing one static variable with another static variable across translation units. Use static variables **only after main() begins** or refactor into functions that guarantee initialization order.

---

# **7. Summary of Rules (Pre-C++17)**

### **In-class initialization allowed:**

* `static const int`
* `static const enum`

### **In-class initialization NOT allowed:**

(MUST go to .cpp file)

* `static const double`
* `static const float`
* `static const char*`
* `static const std::string`
* `static arrays`
* any non-integral static const type

### **Const non-static members:**

* Must be initialized via **constructor initializer list**
* Cannot be assigned in constructor body

### **Static Initialization Order Fiasco:**

* Avoid initializing static members with other static members across translation units.

---

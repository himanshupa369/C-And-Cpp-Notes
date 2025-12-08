# ✅ Default Parameters in Constructors — C++ OOP Notes

---

## 🔷 1. Concept Overview

In C++, **constructors can have default parameters**, just like normal functions.
This allows objects to be created with **fewer arguments**, while the compiler automatically fills in the remaining values.

✅ This improves **flexibility**, **readability**, and **reduces constructor overloads**.

---

## 🔷 2. Basic Syntax

```cpp
class Cylinder {
public:
    Cylinder(double radius, double height = 10);
};
```

Here:

* `radius` → required parameter
* `height` → **default parameter (10)**

---

## 🔷 3. How It Works

With this constructor:

```cpp
Cylinder c1(5);         // height = 10 (default)
Cylinder c2(5, 20);    // height = 20 (overrides default)
```

✅ If an argument is **not provided**, the compiler:

* Automatically substitutes the **default value**

---

## 🔷 4. Important Rule (Very Important for Exams)

> ✅ **Default arguments must always be at the END of the parameter list.**

✅ Valid:

```cpp
Cylinder(double r, double h = 10);
```

❌ Invalid:

```cpp
Cylinder(double r = 5, double h);   // ❌ Compiler error
```

Why?

* The compiler **cannot guess missing values in the middle** of parameters.

---

## 🔷 5. Using Default Parameters with Header + CPP Files

### ✅ In Header File (.h)

```cpp
class Cylinder {
public:
    Cylinder(double radius = 1.0, double height = 1.0);
};
```

### ✅ In Implementation File (.cpp)

```cpp
Cylinder::Cylinder(double radius, double height)
    : m_radius{radius}, m_height{height} {}
```

⚠️ **Rule:**

> ❌ Do NOT repeat default parameters in the `.cpp` file
> ✅ Default arguments must appear **only once → in the declaration**

---

## 🔷 6. Conflict with Default Constructor (Compiler Ambiguity)

### ❌ Problem Case

```cpp
class Cylinder {
public:
    Cylinder();                              // default constructor
    Cylinder(double r = 1, double h = 1);    // default parameters
};
```

Now this call is **AMBIGUOUS**:

```cpp
Cylinder c;
```

❌ Compiler Confusion:

* Should it call:

  * `Cylinder()`
  * OR `Cylinder(double r = 1, double h = 1)` ?

✅ **Result: Compiler Error**

---

### ✅ Correct Solution

You must **choose only one**:

✅ Option 1:

```cpp
Cylinder();
```

✅ Option 2:

```cpp
Cylinder(double r = 1, double h = 1);
```

❌ Never keep both together.

---

## 🔷 7. Practical Example (Simplified Cylinder Class)

```cpp
class Cylinder {
public:
    Cylinder(double radius, double height = 10)
        : m_radius{radius}, m_height{height} {}

    double volume() const {
        return 3.14159 * m_radius * m_radius * m_height;
    }

private:
    double m_radius{1};
    double m_height{1};
};
```

### ✅ Usage

```cpp
Cylinder c1(5);        // height = 10
Cylinder c2(5, 2);     // height = 2
```

---

## 🔷 8. Key Advantages

✅ Reduces number of constructor overloads
✅ Improves code readability
✅ Safer than using multiple constructors
✅ Cleaner object initialization
✅ Common in real-world libraries and APIs

---

## 🔷 9. Common Mistakes (Very Important)

| Mistake                                           | Result                             |
| ------------------------------------------------- | ---------------------------------- |
| Default parameter before non-default              | ❌ Compile-time error               |
| Default specified in .cpp file                    | ❌ Redefinition error               |
| Default constructor + default parameters together | ❌ Ambiguous call                   |
| Assuming default always used                      | ❌ User arguments override defaults |

---

## 🔷 10. Interview One-Liner

> **Default parameters in constructors allow object creation with optional arguments, where missing values are automatically filled by the compiler.**

---

## 🔷 11. C++ Version Support

✅ Available since **C++98**
✅ Fully supported in **C++11 → C++23**

---

## 🔷 12. Quick Exam Summary Box

* ✅ Default parameters work like function defaults
* ✅ Must be placed at the **end**
* ✅ Defined only in **declaration**
* ❌ Cannot coexist with default constructor if signatures overlap
* ✅ Reduce constructor overloads

---

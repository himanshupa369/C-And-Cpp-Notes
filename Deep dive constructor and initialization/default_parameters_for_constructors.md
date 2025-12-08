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

# ✅ Default Constructors vs Default Arguments in Constructors (C++)

## 🔹 Topic

**Interaction between Default Constructor and Constructor with Default Parameters**

---

## 🔹 C++ Version

* ✅ Supported since: **C++98**
* ✅ Still valid in: **C++11–C++23**

---

## 🔹 Given Code (Your Example)

```cpp
#include <iostream>

class Test {
public:
    Test(){
        std::cout << "default constructor called" << std::endl;
    }

    // Works fine
    Test(int x, int y = 10) {
        std::cout << "default argument constructor called" << std::endl;
        std::cout << "x = " << x << ", y = " << y << std::endl;
    }
};

int main(){
    Test a;        
    std::cout << "build is done" << std::endl;
    return 0;
}
```

---

## ✅ What Happens in This Program?

```cpp
Test a;
```

### 🔹 Which constructor is called?

✅ **Output:**

```
default constructor called
build is done
```

✔️ The **default constructor `Test()`** is called
✔️ The constructor with default arguments is **NOT considered**, because:

```cpp
Test(int x, int y = 10)
```

❌ Still requires **at least 1 argument (`x`)**

✅ So there is **NO ambiguity in this program**
✅ Your code is **100% valid and correct**

---

## ❌ When Does the ERROR Occur?

If you write this instead:

```cpp
class Test {
public:
    Test(){}

    Test(int x = 5, int y = 10) {}
};
```

And call:

```cpp
Test a;
```

### ❌ Compiler Error:

```
error: call of overloaded 'Test()' is ambiguous
```

### ❓ Why Ambiguous?

Because now the compiler sees:

| Constructor               | Can it be called with `Test a;`? |
| ------------------------- | -------------------------------- |
| `Test()`                  | ✅ YES                            |
| `Test(int x=5, int y=10)` | ✅ YES                            |

❌ Compiler cannot decide → **AMBIGUITY ERROR**

---

## ✅ Core Rule (Very Important)

> ✅ If a constructor can be called with **zero arguments**, and another constructor also accepts **zero arguments due to defaults**, the program becomes **AMBIGUOUS**.

---

## ✅ Valid Default Argument Usage

```cpp
Test(int x, int y = 10);
```

✅ Works with:

```cpp
Test a(5);      // x=5, y=10
Test b(5, 20); // x=5, y=20
```

❌ Does NOT allow:

```cpp
Test c; // because x has no default
```

---

## ✅ Invalid Default Argument Pattern

```cpp
Test(int x = 5, int y); // ❌ ILLEGAL
```

✅ Rule:

> Once a parameter has a default value, **all parameters to its right must also have defaults**.

---

## ✅ Pros

✅ Reduces constructor overload count
✅ Makes object creation flexible
✅ Cleaner APIs
✅ Widely used in STL and libraries

---

## ❌ Cons

❌ Can cause **constructor ambiguity**
❌ Harder to debug in large codebases
❌ Dangerous when mixed with multiple overloads

---

## ✅ Real-World Use Cases

* Graphics libraries (width default, height optional)
* Networking sockets (timeout default)
* STL-style APIs
* Game engines (default physics values)
* Database connection configs

---

## ✅ Final One-Line Summary (Interview Ready)

> A constructor with default parameters can behave like multiple overloads, but if it overlaps with a default constructor, it causes ambiguity and results in a compile-time error.

---

## ✅ Your Code Verdict

| Feature                      | Status                      |
| ---------------------------- | --------------------------- |
| Default constructor          | ✅ Valid                     |
| Constructor with default arg | ✅ Valid                     |
| Object creation (`Test a;`)  | ✅ Calls default constructor |
| Ambiguity                    | ❌ NOT present               |
| Design correctness           | ✅ Proper                    |

---


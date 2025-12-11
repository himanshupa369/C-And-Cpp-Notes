
---

# C++ Static Constants

## **1. What Are Static Constants?**

Static constants are **constant values shared by all objects of a class**, stored once per class rather than once per object.

They provide:

* A single shared constant instance
* No memory waste (unlike per-object `const` members)
* Logical cohesion (constants that belong to a class conceptually stay inside it)

---

# **2. Why Use Static Constants in a Class?**

Example: A `Cylinder` class needs `π` for volume calculation.
Design goals:

* `π` is **not unique per object**
* Should not be defined externally in global scope
* Should not be duplicated in each object
* Should be accessible as `Cylinder::PI`

Thus, use:

```cpp
inline static const double PI = 3.14159265358979;
```

---

# **3. Static Member Variable Requirements (Recap)**

### **Regular static member variable**

Before C++17, static data members cannot be initialized inside the class:

```cpp
class Cylinder {
    static double PI;  // Declaration only
};

// In Cylinder.cpp
double Cylinder::PI = 3.14159265358979;  // Definition required
```

Because:

* The class definition is usually in the header (.h)
* Initializing here would cause **multiple definitions across translation units**
* Violates ODR (One Definition Rule)

---

# **4. Modern C++ (C++17+) — Inline Static Constants**

From **C++17 onward**, static constants can be initialized directly inside the class using `inline`.

### **Key rule**

`inline` tells the compiler:

* This definition may appear in multiple translation units
* But all are treated as **one single definition**
* Therefore, safe in header files

### **Syntax**

```cpp
class Cylinder {
public:
    inline static const double PI{3.14159265358979};
    inline static const std::string DEFAULT_COLOR{"Red"};
};
```

### **Benefits**

* Cleaner design (single location)
* No need for .cpp definitions
* No global variables
* Header-only classes become easier to maintain
* Safe from ODR violations

---

# **5. Accessing Static Constants**

Static constants belong to the class, not the object.

### **Preferred syntax**

```cpp
std::cout << Cylinder::PI;
std::cout << Cylinder::DEFAULT_COLOR;
```

### **Object access also works (but not recommended)**

```cpp
Cylinder c;
std::cout << c.DEFAULT_COLOR;    // Allowed
```

---

# **6. Example: Using Static Constant PI in Volume Calculation**

### **Header**

```cpp
class Cylinder {
public:
    Cylinder(double radius, double height);

    double volume() const;

private:
    double m_radius{};
    double m_height{};

public:
    inline static const double PI{3.141592653589793};
    inline static const std::string DEFAULT_COLOR{"Blue"};
};
```

### **CPP**

```cpp
double Cylinder::volume() const {
    return PI * m_radius * m_radius * m_height;
}
```

---

# **7. Without C++17 (Old Method)**

If the compiler does not support inline static members:

### **Header**

```cpp
class Cylinder {
public:
    static const double PI;   // Declaration only
};
```

### **CPP**

```cpp
const double Cylinder::PI = 3.141592653589793;
```

This is necessary to avoid:

* Multiple definitions
* Linker errors

---

# **8. When to Use Static Constants**

Use static constants when:

* The value belongs to the class, not objects
* The value is universal and fixed
* The value is required for all calculations related to the class
* You want to avoid global variables

Examples:

* Mathematical constants (`PI`, `E`, `G`)
* Physical constants (`speed_of_light`)
* Default configuration (colors, limits, default capacity)
* Enum-like named constants

---

# **9. Summary Table**

| Feature                         | `static const` (old) | `inline static const` (C++17+) |
| ------------------------------- | -------------------- | ------------------------------ |
| Initialization inside class     | Not allowed          | Allowed                        |
| Must define in .cpp             | Yes                  | No                             |
| ODR-safe in header              | No                   | Yes                            |
| Requires extra code maintenance | Yes                  | No                             |
| Memory                          | Shared               | Shared                         |

---

# **10. Key Takeaways**

* Use `inline static const` for constants from C++17 onward.
* It keeps all constant definitions inside the class.
* Eliminates separate definitions in `.cpp` files.
* Improves code structure, clarity, and maintainability.
* Perfect for class-level constants such as mathematical or configuration values.

---

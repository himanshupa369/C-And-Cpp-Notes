
---

# Notes: Namespaces Across Multiple Files in C++

## 1. Concept Overview

In C++, **namespaces can span multiple files** (header and source files).
Declaring the same namespace name in different files **does not create separate namespaces**.
All declarations and definitions with the same namespace name are **merged by the compiler**.

This is essential for:

* Large projects
* Modular design
* Clean separation of declarations and implementations

---

## 2. Namespace with Classes

Classes can be declared **inside a namespace** just like functions or variables.

Example structure:

```cpp
namespace Geom {
    class Point {
        // members
    };
}
```

The class now belongs to the `Geom` namespace and **is not in the global namespace**.

---

## 3. Header and Source File Organization

### Header File (`.h`)

* Contains **class declaration**
* Wrapped inside a namespace

Example:

```cpp
namespace Geom {
    class Point {
    public:
        Point(double x, double y);
        void print() const;
    private:
        double x;
        double y;
    };
}
```

### Source File (`.cpp`)

* Contains **member function definitions**
* Uses the **same namespace**

Example:

```cpp
namespace Geom {
    Point::Point(double x, double y) : x{x}, y{y} {}

    void Point::print() const {
        // print logic
    }
}
```

⚠️ Important:

* The namespace in the `.cpp` file **extends** the namespace from the header
* Different files ≠ different namespaces

---

## 4. Using Multiple Classes in the Same Namespace

### Example Classes

* `Point` → models a 2D point
* `Line` → composed of two `Point` objects
* `Cylinder` → geometric solid with radius and height

All classes live inside the **same namespace**:

```cpp
namespace Geom {
    class Line { };
    class Cylinder { };
}
```

This allows:

* Logical grouping
* Cleaner APIs
* Avoiding naming conflicts

---

## 5. Inter-Class Relationships Inside a Namespace

Classes inside the same namespace can:

* Use each other directly
* Share types without extra qualification inside the namespace

Example:

```cpp
class Line {
    Point start;
    Point end;
};
```

---

## 6. Using Namespaced Classes in `main()`

### Step 1: Include Headers

```cpp
#include "point.h"
#include "line.h"
#include "cylinder.h"
```

### Step 2: Prefix with Namespace

Since classes are **not in the global namespace**, you must qualify them:

```cpp
Geom::Point p1(10, 20);
Geom::Point p2(3.5, 6.1);
```

Without `Geom::`, compilation fails.

---

## 7. Creating Objects and Calling Methods

### Point

```cpp
Geom::Point p1(10, 20);
p1.print();
```

### Line

```cpp
Geom::Line l1(p1, p2);
l1.print();
```

### Cylinder

```cpp
Geom::Cylinder c1(1.4, 10);
std::cout << c1.volume();
```

Each object is created and accessed using the namespace-qualified name.

---

## 8. Key Compiler Behavior

* The compiler **combines namespace blocks** across:

  * Multiple files
  * Multiple declarations
* Namespace scope is resolved at compile time
* The linker connects implementations automatically

---

## 9. Key Takeaways

* Namespaces can span **multiple headers and source files**
* Same namespace name = same namespace (regardless of file)
* Classes inside namespaces must be accessed using `Namespace::Class`
* Enables scalable, modular, and conflict-free C++ design
* Standard practice in real-world C++ projects and libraries

---

## 10. Practical Benefits

* Clean project structure
* Avoids global namespace pollution
* Improves code readability
* Essential for libraries and frameworks
* Aligns with professional C++ coding standards

---

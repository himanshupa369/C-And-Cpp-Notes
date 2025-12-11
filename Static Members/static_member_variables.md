
---

# **Static Member Variables in C++ –**

## **1. What Are Static Member Variables?**

A **static member variable** is a data member that:

* Belongs to the **class itself**, not to individual objects.
* Has **only one shared copy** across all objects of that class.
* Exists **for the entire program lifetime**, not tied to object lifetime.
* Gets initialized **before `main()` starts executing**.

### Key difference:

| Normal Member Variable                | Static Member Variable             |
| ------------------------------------- | ---------------------------------- |
| Stored inside each object instance    | Stored once for the class          |
| Each object has its own separate copy | Shared among all objects           |
| Lifetime = object lifetime            | Lifetime = entire program          |
| Accessed via object                   | Accessed via `ClassName::variable` |

---

## **2. Why Use Static Member Variables?**

They are useful when:

* You need to share data across all objects.
* You want some data to persist independently from any object.
* You need counters such as:

  * Number of objects created
  * Unique IDs assignment
  * Global configuration shared across objects

**Example use case:**
Tracking number of `Point` objects created:

* Increment counter in constructor.
* Decrement counter in destructor.

---

## **3. Syntax for Declaring Static Member Variables**

### **Declaration (inside class)**

```cpp
class Point {
public:
    static size_t point_count; // Declaration only
};
```

### **Important**

You **cannot initialize** static members inside the class (unless they are `constexpr` or integral constants).

This is illegal:

```cpp
static size_t point_count{0};  // ERROR
```

---

## **4. Definition and Initialization (in .cpp file)**

Static members must be **defined exactly once** in a .cpp file:

```cpp
#include "Point.h"

size_t Point::point_count{0};   // Definition + initialization
```

This is required so that:

* Memory is allocated
* Linker resolves its storage

---

## **5. Accessing Static Member Variables**

### **Preferred way: using class name**

```cpp
std::cout << Point::point_count;
```

### **Also accessible through objects (not recommended)**

```cpp
Point p;
std::cout << p.point_count;   // Works, but confusing
```

---

## **6. Static Member Variable Lifetime**

Static members:

* Are created and initialized **before `main()` starts**.
* Are destroyed automatically when the program ends.
* Exist independent of any object creation.

This is why you can do:

```cpp
std::cout << Point::point_count; // Works without creating any Point object
```

---

## **7. Using Static Members for Object Counting**

### In Constructor:

```cpp
Point::Point(double x, double y) {
    ++point_count;
}
```

### In Destructor:

```cpp
Point::~Point() {
    --point_count;
}
```

Now your class can always tell how many `Point` objects currently exist.

---

## **8. Example: Complete Implementation**

### **Point.h**

```cpp
class Point {
public:
    Point(double x, double y);
    Point(double xy);     // x=y
    Point();              // default ctor
    Point(const Point&);  // copy ctor
    ~Point();

    static size_t point_count;

private:
    double m_x{};
    double m_y{};
};
```

---

### **Point.cpp**

```cpp
#include "Point.h"
#include <cmath>

size_t Point::point_count{0}; // Initialization

Point::Point(double x, double y) : m_x{x}, m_y{y} {
    ++point_count;
}

Point::Point(double xy) : Point(xy, xy) {}

Point::Point() : Point(0.0, 0.0) {}

Point::Point(const Point& p) : Point(p.m_x, p.m_y) {}

Point::~Point() {
    --point_count;
}
```

---

### **main.cpp**

```cpp
#include <iostream>
#include "Point.h"

int main() {

    std::cout << "Initial count: " << Point::point_count << "\n";

    Point p1(10, 20);
    std::cout << "After creating p1: " << Point::point_count << "\n";

    Point points[] = { Point(1,1), Point(), Point(4) };
    std::cout << "After array creation: " << Point::point_count << "\n";

    return 0;
}
```

---

## **9. Output Explanation**

Expected behavior:

* Before creating any objects → count = 0
* `p1` created → count = 1
* Array of 3 points → count = 4
* At program exit, destructors run and count returns to 0 (optional to print via debugging).

---

## **10. Key Rules to Remember**

1. **Declare** static variable inside class.
2. **Define + initialize** it in exactly one .cpp file.
3. Static variable is **shared** across all objects.
4. Static variable exists **even without objects**.
5. Useful for global counters, configuration, shared state.
6. Access via **ClassName::variable**.

---

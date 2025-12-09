
---

# Move Constructor – Complete Notes (C++ OOP)

## 1. Motivation

A **move constructor** allows an object to *steal* resources from another object, usually a **temporary (rvalue)** that is about to be destroyed.

Reasons:

* Avoid expensive deep copies.
* Avoid allocating new memory unnecessarily.
* Improve performance when objects contain expensive resources (heap memory, buffers, large objects).

---

# 2. Copy vs Move: Core Idea

## 2.1 Copy Constructor (Deep Copy)

* Parameter: `const T&`
* Creates an **independent copy**.
* Allocates new memory and duplicates data.

Example:

```cpp
Point::Point(const Point& src)
    : x(new double(*src.x)),
      y(new double(*src.y))
{}
```

This is required because *shallow copy* would copy pointer addresses and both objects would share memory → double delete.

---

## 2.2 Move Constructor (Steal Resources)

* Parameter: `T&&` (rvalue reference)
* Transfers ownership of resources.
* Does **NOT** allocate new memory.
* After stealing, invalidates source so its destructor is safe.

Example (conceptual):

```cpp
Point::Point(Point&& src)
    : x(src.x), y(src.y)
{
    src.x = nullptr;
    src.y = nullptr;
}
```

---

# 3. When Move Constructor is Used

The compiler uses the move constructor when:

* Building from a **temporary object**:

  ```cpp
  Point p = Point(1,2);  // temporary
  ```

* Using `std::move()`:

  ```cpp
  Point p3(std::move(p1));  // p1 treated as temporary
  ```

Why `std::move`?

* It **forces** the compiler to treat an object as an rvalue.
* Without it, the copy constructor is used.

---

# 4. Steps of a Move Constructor

### Given object `src` (temporary or moved-from):

1. **Steal pointers**
   Assign `src.x` and `src.y` directly to the new object's members.

2. **Invalidate src**
   Set `src.x = nullptr` and `src.y = nullptr`
   (prevents double free in src destructor).

3. **Do NOT allocate**
   Move constructor avoids heavy work.

---

# 5. Example from Your Code (Final Form)

### Move constructor:

```cpp
Point::Point(Point&& source)
    : x(source.steal_x()),
      y(source.steal_y())
{
    std::cout << "Body of move constructor" << std::endl;
}

```

### Steal functions:

```cpp

double* Point::steal_x() {
    double* old = x;
    x = nullptr;
    return old;
}

double* Point::steal_y() {
    double* old = y;
    y = nullptr;
    return old;
}
```

---

# 6. Behavior Demonstration

```cpp
Point p3(std::move(Point(20.5, 5.8)));
```

Execution order:

1. Temporary `Point(20.5,5.8)` constructed.
2. The move constructor steals its pointers.
3. Temporary object’s pointers are invalidated.
4. Temporary is destroyed (safe—pointers are null).
5. `p3` now owns resources.

---

# 7. Important Notes

### A. Why invalidate source?

Because both objects would point to the same heap memory → double-delete crash.

### B. Moved-from Object State

A moved-from object must be **valid but unspecified**.

### C. When to implement a move constructor?

When your class:

* Manages heap memory.
* Manages file handles, sockets, buffers, etc.
* Has expensive resources (large containers).

---

# 8. Rule of Five

If your class manages resources with:

* custom destructor
* copy constructor
* copy assignment
* **then you must also implement**
* move constructor
* move assignment operator

---

# 9. Summary Table

| Feature              | Copy Constructor | Move Constructor      |
| -------------------- | ---------------- | --------------------- |
| Parameter Type       | `const T&`       | `T&&`                 |
| Transfer ownership?  | No               | Yes                   |
| Allocates new memory | Yes              | No                    |
| Invalidates source?  | No               | Yes                   |
| When used?           | lvalues          | rvalues (temporaries) |

---

---



```cpp
#include "point.h"

Point::Point(double x_param, double y_param) 
    : x(new double(x_param)),
      y(new double(y_param))
{
    std::cout << "Point constructed  : " << this << std::endl;
}

// Copy constructor (deep copy)
Point::Point(const Point& source_point)
    : x(new double(*(source_point.get_x()))),
      y(new double(*(source_point.get_y())))
{
    std::cout << "Body of copy constructor" << std::endl;
}

// Move constructor
Point::Point(Point&& source_point)
    : x(source_point.steal_x()),
      y(source_point.steal_y())
{
    std::cout << "Body of move constructor" << std::endl;
}

// Destructor
Point::~Point()
{
    delete x;
    delete y;
    std::cout << "Point destroyed : " << this << std::endl;
}
```

---

# 2. Short, Clean Explanation (for your GitHub notes)

### Move Constructor — Summary

A **move constructor** steals resources from a temporary object instead of copying them.
Syntax:

```cpp
Point(Point&& other);
```

Key actions performed:

1. Steal the resource (pointer) from the source object
2. Set the source’s pointers to `nullptr`
3. Avoid allocating new memory
4. Avoid expensive deep copy work

This improves performance when working with large or heavy resources.

### Why `std::move`?

`std::move` **does not move anything**.
It simply **casts an lvalue to an rvalue reference**, telling the compiler:

“This object can be moved from.”

### When is the move constructor used?

When the source is:

* A temporary object
* An object explicitly cast via `std::move`
* Returned from functions (under some conditions)

### Benefits

* Avoid unnecessary heap allocations
* Avoid large data copies
* Performance improvement in containers (`std::vector`, etc.)

---


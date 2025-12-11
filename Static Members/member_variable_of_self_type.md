
---

# **Member Variables of Self Type in C++ (Notes)**

**Concept:**
A *class cannot contain a direct data member of its own type* because the class is incomplete at the point of member declaration. The compiler does not yet know the full size/layout of the type, so it cannot embed an object of that type.

This leads to the **incomplete type error**.

---

# **1. Why Direct Self-Type Members Are Not Allowed**

### Example

```cpp
class Point {
public:
    Point p1;             // ERROR: incomplete type
    const Point p2;       // ERROR
    static inline const Point p3{1,2}; // ERROR
};
```

### Error

```
error: field ‘p1’ has incomplete type ‘Point’
```

### Root Cause

The compiler must know the **complete object size** at declaration time.
Inside the class body, the type is still **incomplete**, so:

* Embedding `Point` inside `Point` is impossible.
* Embedding `const Point` is also impossible.
* Even `static inline` forces **in-class initialization**, which again requires the complete type.

---

# **2. Valid Scenarios (How To Use Self Type Correctly)**

There are **three valid techniques**.

---

## **2.1 Using a Pointer to Self Type**

Pointers are allowed because:

* A pointer has a fixed size known at compile time.
* It does not require the full definition of the pointed-to type.

### Example

```cpp
class Point {
public:
    Point* origin = nullptr;    // VALID
};
```

### Important Rule

You **must NOT** allocate using `new Point` inside the constructor initializer list of the same class:

```cpp
Point::Point() : origin(new Point)  // DANGEROUS!
```

This causes **infinite recursion**, because:

* Creating `Point` calls the constructor again
* That constructor again calls `new Point`
* Recursion continues indefinitely until memory exhaustion

### Correct Way

Initialize the pointer to `nullptr` in the constructor and set it later:

```cpp
Point::Point() : origin(nullptr) {}

void Point::initialize_pointer(double x, double y) {
    origin = new Point(x, y);   // Safe (object already constructed)
}
```

---

## **2.2 Using Static Data Members (Non-inline)**

Static members do not need object layout at compile time because:

* They are stored separately, not inside each object
* They are defined later in a .cpp file

### Class Declaration

```cpp
class Point {
public:
    static const Point origin1;  
    static Point origin2;
};
```

### Definition in .cpp File

```cpp
const Point Point::origin1{4,5};
Point Point::origin2{3,8};
```

### Why This Works

* The compiler only checks declaration in the class.
* Initialization occurs **after** the class is fully defined.
* The linker resolves the actual object at link-time.

### When This Does NOT Work

If you attempt:

```cpp
static inline const Point p{1,2}; // ERROR
```

`inline` forces *in-class* initialization → requires complete type → invalid.

---

# **3. Summary: Allowed vs Not Allowed**

| Technique                | Valid? | Reason                                     |
| ------------------------ | ------ | ------------------------------------------ |
| `Point p;`               | No     | Incomplete type, requires full object size |
| `const Point p;`         | No     | Same as above                              |
| `static inline Point p;` | No     | Requires in-class initialization           |
| `Point* p;`              | Yes    | Pointer has known size                     |
| `static Point p;`        | Yes    | Initialization deferred to .cpp            |
| `static const Point p;`  | Yes    | Same as above                              |

---

# **4. Key Takeaways**

1. **You cannot embed an object of the same class type inside the class.**
2. **Pointers work** because the compiler only needs pointer size, not object layout.
3. Avoid `new Point` inside the same class’s constructor → **infinite recursion**.
4. **Static (non-inline) members** of self type work because initialization occurs outside the class body.
5. `inline static` breaks the rule because in-class initialization requires a fully complete type.

---

# **5. Clean Example**

### point.h

```cpp
class Point {
public:
    double x{}, y{};

    // Valid: pointer to self
    Point* origin = nullptr;

    // Valid: static members declared only
    static const Point ORIGIN1;
    static Point ORIGIN2;

    Point();
    void init_origin(double, double);
    void print() const;
};
```

### point.cpp

```cpp
#include "point.h"
#include <iostream>

const Point Point::ORIGIN1{0, 0};
Point Point::ORIGIN2{1, 1};

Point::Point() : origin(nullptr) {}

void Point::init_origin(double a, double b) {
    origin = new Point{a, b};
}

void Point::print() const {
    std::cout << "Point(" << x << ", " << y << ")\n";
}
```

---

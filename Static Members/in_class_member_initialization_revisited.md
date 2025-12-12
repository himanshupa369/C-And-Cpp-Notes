
---

# In-Class Member Initialization — Personal Notes

## 1. Purpose

In-class member initialization allows setting default values for data members **directly in the class body**, avoiding uninitialized (junk) values and making constructors simpler.

Example:

```cpp
class Point {
private:
    double m_x = 0.0;     // in-class initialization
    double m_y{0.0};      // brace init
};
```

This mechanism ensures that every constructor begins with predictable initial values for these members.

---

# 2. Behavior Without In-Class Initialization

If no initialization is provided inside the class or constructor:

* **Fundamental types** (int, double, etc.) contain **indeterminate (garbage) values**.
* Default constructor alone does not auto-initialize members unless you explicitly initialize them.

Example:

```cpp
class P {
    double x;  // garbage
    double y;  // garbage
public:
    P() {}     // does nothing → members stay uninitialized
};
```

---

# 3. Valid In-Class Initialization Forms

## A. Assignment Initialization

```cpp
double m_x = 0.1;
double m_y = 0.1;
```

* Explicit assignment.
* Clear and readable.
* Works for all types starting from C++11.

## B. Brace Initialization (Empty)

```cpp
double m_x{};    // becomes 0.0
double m_y{};    // becomes 0.0
```

* For fundamental types: zero-initialization.
* For user-defined types: calls the default constructor.

## C. Brace Initialization (Explicit Value)

```cpp
double m_x{0.1};
double m_y{0.1};
```

* Preferred in modern C++.
* Ensures no narrowing conversions.

---

# 4. Using In-Class Initialization with Custom Types

In-class initialization also works for user-defined types.

Example:

```cpp
class Integer {
public:
    Integer() { std::cout << "default constructor called\n"; }
};

class Point {
private:
    Integer i{};   // calls Integer() automatically
};
```

When a `Point` object is created, the default constructor of `Integer` is invoked.

---

# 5. Evolution Across C++ Standards

### Before C++11

In-class member initialization was extremely limited:

* Only allowed for **static const integral types** or **enum constants**.
  Examples:

  ```cpp
  static const int MAX = 10;
  static const size_t Size = 64;
  enum { VALUE = 3 };
  ```

### Since C++11 (Modern C++)

* You can initialize **any** member type inside the class.
* Works with:

  * fundamental types
  * `std::string`, vectors, containers
  * user-defined classes
  * default initialization, braced initialization, assignment

---

# 6. Interaction with Constructors

If a constructor initializes a member in its initializer list, it **overrides** the in-class initialization.

Example:

```cpp
class Point {
    double m_x = 1.0;
    double m_y = 1.0;
public:
    Point(double x) : m_x(x) {}  // m_y remains 1.0
};
```

In-class initialization acts as a **fallback default**, not a hard override.

---

# 7. Debugging Insight

Creating an object without initialization:

* Shows garbage values in debugger (locals window).
* Using assignment or braces prevents this.

Useful to verify initialization behavior.

---

# 8. Important Rules & Notes

* In-class initialization happens **before** constructor body executes.
* Cannot initialize **static** data members this way (unless declared `inline static` starting C++17).
* Brace initialization is safer than assignment due to narrowing protection.
* For custom types, braces call the appropriate constructor automatically.

---

# 9. Summary (Quick Reference)

| Form            | Meaning                      | Use Case                          |
| --------------- | ---------------------------- | --------------------------------- |
| `int x;`        | Uninitialized                | Avoid unless performance-critical |
| `int x = 5;`    | Assignment initialization    | Clear & explicit                  |
| `int x{};`      | Zero-initialization          | Best for ensuring non-garbage     |
| `int x{5};`     | Direct braced initialization | Most modern & safe                |
| `MyType obj{};` | Calls default constructor    | User-defined types                |

---


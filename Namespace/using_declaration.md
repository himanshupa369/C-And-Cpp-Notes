
---

# Using Declarations in C++

## Topic

**Using Declarations & Using Directives (Namespaces in C++)**

---

## Purpose

Using declarations allow you to **use names from a namespace without repeatedly qualifying them** with the namespace name (`::`).

This helps reduce verbosity but must be used carefully to avoid **name conflicts**.

---

## Background: Namespaces Recap

* Namespaces group related classes, functions, and variables.
* Prevent name collisions in large projects.
* Example:

```cpp
namespace geom {
    class Point {};
    class Line {};
    class Cylinder {};
}
```

Usage without `using`:

```cpp
geom::Point p;
geom::Line l;
```

---

## Problem Statement

* Repeatedly typing `geom::` or `std::` can be annoying.
* Using declarations provide a way to **avoid repeated namespace prefixes**.

---

## Two Ways to Use Namespaces

### 1. Using Declaration (Import a Specific Name) ✅ **Recommended**

Brings **only one name** from a namespace.

#### Syntax

```cpp
using namespace_name::name;
```

#### Example

```cpp
using geom::Point;

Point p1;   // No need for geom::Point
```

✔ Safe
✔ Minimal pollution
✔ Clear intent

---

### 2. Using Directive (Import Entire Namespace) ⚠️ **Use Carefully**

Brings **all names** from a namespace into the current scope.

#### Syntax

```cpp
using namespace namespace_name;
```

#### Example

```cpp
using namespace geom;

Point p;
Line l;
Cylinder c;
```

⚠ Can cause name conflicts
⚠ Makes code harder to understand
⚠ Readers must search to know where symbols come from

---

## Using Declarations with Standard Library

### Import Specific Names (Good Practice)

```cpp
using std::cout;
using std::endl;

cout << "Hello World" << endl;
```

### Import Entire std Namespace (Not Recommended)

```cpp
using namespace std;
```

❌ May conflict with your own identifiers
❌ Discouraged in production code and headers

---

## Function Name Conflicts Example

### Global Function

```cpp
double Add(double a, double b) {
    return a + b + 0.555;
}
```

### Namespaced Function

```cpp
namespace math {
    double Add(double a, double b) {
        return a + b;
    }
}
```

### Case 1: No using

```cpp
Add(10, 20);       // Calls global Add
math::Add(10,20); // Calls math::Add
```

---

### Case 2: Using Directive Causes Ambiguity ❌

```cpp
using namespace math;

Add(10, 20);  // ❌ Compiler error: ambiguous call
```

Compiler sees:

* `::Add`
* `math::Add`

Cannot decide → **compile-time error**

---

### Correct Way to Resolve Ambiguity ✅

Explicit qualification:

```cpp
math::Add(10, 20);
```

Or import only what you need:

```cpp
using math::Add;
Add(10,20);
```

---

## Nested Namespaces Example

```cpp
namespace math {
    namespace weighted {
        double Add(double a, double b) {
            return a + b - 1;
        }
    }
}
```

Usage:

```cpp
math::weighted::Add(10, 20);
```

---

## Key Rules & Best Practices

### ✅ DO

* Prefer **`using namespace::name`**
* Use explicit namespace qualification in headers
* Use `using` in `.cpp` files only
* Resolve ambiguity with `::`

### ❌ DON’T

* Use `using namespace std;` in headers
* Import large namespaces globally
* Rely on implicit name resolution

---

## Comparison Summary

| Feature         | Using Declaration | Using Directive |
| --------------- | ----------------- | --------------- |
| Scope Pollution | Minimal           | High            |
| Safety          | High              | Low             |
| Readability     | Good              | Risky           |
| Recommended     | ✅ Yes             | ⚠ Limited use   |

---

## C++ Version

* Namespaces: **C++98**
* Using declarations: **C++98**

---

## Real-World Use Cases

* Large codebases with modular design
* Geometry, Math, Networking libraries
* Avoiding repetitive namespace qualifiers
* Improving local readability without breaking global scope

---

## Final Takeaway

> **Using declarations are powerful but dangerous when misused.**
> Use them **sparingly**, **locally**, and **explicitly** to keep code clean, readable, and safe.

---

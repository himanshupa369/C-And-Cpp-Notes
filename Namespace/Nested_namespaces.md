
---

# Nested Namespaces in C++

## Topic

**Nested Namespaces**

---

## Definition

A **nested namespace** is a namespace declared **inside another namespace**.
C++ allows namespaces to be hierarchically organized to group related code.

```cpp
namespace Hello {
    namespace World {
        // members
    }
}
```

---

## Why Nested Namespaces Are Used

* Organize large codebases logically
* Avoid name collisions
* Group related components under a common scope
* Improve code readability and structure

---

## Basic Syntax

```cpp
namespace Outer {
    // outer members

    namespace Inner {
        // inner members
    }
}
```

---

## Access Rules (Very Important)

### 1. Inner Namespace → Outer Namespace

✔ **Inner namespaces have direct access to names declared in outer namespaces**

```cpp
namespace Hello {
    int age = 30;

    namespace World {
        void saySomething() {
            std::cout << age; // Direct access
        }
    }
}
```

✔ No need to prefix `Hello::age` inside `World`

---

### 2. Outer Namespace → Inner Namespace

❌ **Outer namespaces do NOT have direct access to inner namespace members**

```cpp
namespace Hello {
    namespace World {
        int localVar = 44;
    }

    void doSomething() {
        std::cout << localVar; // ❌ ERROR
    }
}
```

✔ Correct way:

```cpp
std::cout << World::localVar;
```

---

## Rule Summary

| Direction     | Access Allowed | Namespace Prefix Needed |
| ------------- | -------------- | ----------------------- |
| Inner → Outer | ✅ Yes          | ❌ No                    |
| Outer → Inner | ❌ No           | ✅ Yes                   |

---

## Accessing Nested Namespaces from Outside

To access members from outside (e.g., `main()`), you must **fully qualify the path**.

```cpp
Hello::World::saySomething();
```

---

## Example: Full Working Code

```cpp
#include <iostream>

namespace Hello {

    int age = 25;

    namespace World {
        int localVar = 44;

        void saySomething() {
            std::cout << "Hello there\n";
            std::cout << "Age: " << age << std::endl;
        }
    }

    void doSomething() {
        std::cout << "Using localVar: " << World::localVar << std::endl;
    }
}

int main() {
    Hello::World::saySomething();
    Hello::doSomething();
}
```

---

## Common Compiler Error

If namespace qualification is missing:

```cpp
localVar was not declared in this scope
```

✔ Fix by specifying the correct namespace:

```cpp
World::localVar
```

---

## Important Observations

* Nested namespaces behave like **scope hierarchies**
* Name lookup follows **scope resolution rules**
* Compiler enforces strict access boundaries
* Namespace paths must be followed correctly

---

## Best Practices

* Use nested namespaces for large projects
* Keep namespace depth reasonable (avoid over-nesting)
* Prefer clear and meaningful namespace names
* Always qualify names when accessing inner scopes from outside

---

## C++ Version

* **Introduced in:** C++98
* **Still actively used and recommended**

---

## One-Line Takeaway

> Nested namespaces allow you to structure C++ code hierarchically, where inner namespaces can access outer members directly, but outer scopes must explicitly qualify inner namespace names.

---

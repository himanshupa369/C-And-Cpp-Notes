
---

# Notes: Creating and Using Namespaces in C++

## 1. Purpose of Namespaces

Namespaces exist to **prevent name collisions** when different parts of a program (or different libraries) define **functions, variables, or classes with the same name**.

Example problem:

* Two functions named `add(double, double)` with different logic.
* Without namespaces, the compiler reports a **redefinition error** because they share the same signature.

Namespaces allow:

* Multiple entities to share the same identifier.
* Logical grouping of code.
* Separation of functionality (e.g., “adjusted” vs. “non-adjusted” operations).

---

## 2. Declaring a Namespace

Syntax:

```cpp
namespace Name {
    // functions, variables, classes
}
```

You can define:

* Free functions
* Variables
* Classes
* Enums
* Nested namespaces

Example:

```cpp
namespace NoAdjust {
    double add(double x, double y) {
        return x + y;
    }
}
```

Another namespace with the same function name:

```cpp
namespace Adjust {
    double add(double x, double y) {
        return x + y - adjustment;
    }
}
```

Both versions of `add` now coexist safely.

---

## 3. Using Namespaces

To call something inside a namespace, prefix with the namespace and `::`.

Example:

```cpp
double r1 = NoAdjust::add(2, 3);   // uses normal version
double r2 = Adjust::add(2, 3);     // uses adjusted version
```

**Important:** If ambiguity exists and namespaces are not specified, the compiler cannot decide which version to use → compile-time error.

---

## 4. Splitting Declarations and Definitions Across Blocks

Namespaces do **not** need to be continuous; they can be extended in multiple blocks.

Example:

```cpp
namespace Adjust {
    double mult(double x, double y);
    double div(double x, double y);
}

// ... later in the file ...

namespace Adjust {
    double mult(double x, double y) {
        return x * y - adjustment;
    }

    double div(double x, double y) {
        return x / y - adjustment;
    }
}
```

The compiler merges these blocks into one namespace internally.

Useful for:

* Separating interface and implementation
* Large codebases
* Organizing class declarations vs. definitions

---

## 5. Namespaces Work Across Multiple Files

Although the transcript focuses on one file, the same logic applies across multiple files:

* A namespace block in one file
* Another block in another file
  Both merge into the same namespace during compilation.

---

## 6. Practical Usage Example Summary

You can maintain multiple versions of operations:

* `NoAdjust::add`, `NoAdjust::mult`, `NoAdjust::div`
* `Adjust::add`, `Adjust::mult`, `Adjust::div`

Each namespace provides a different behavior while keeping the function names identical.

---

## 7. Key Benefits

* Prevent name collisions.
* Organize large codebases.
* Logical grouping of related functionality.
* Enable multiple implementations of the same function signature.
* Allow separation between declarations and definitions.

---

## 8. Personal Observations

* Namespaces are essential in modern C++ software engineering.
* Similar to packages in Java or modules in other languages.
* Using namespaces eliminates the need to rename functions to avoid conflicts.
* Ideal when working on libraries or large-scale multi-file systems.

---

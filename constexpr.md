
---

# 🧠 C++ `constexpr` — Compile-Time Constants

## 🔹 Introduction

`constexpr` (introduced in **C++11**) allows defining **constants and functions** that can be **evaluated at compile time** instead of runtime.

This helps:

* Improve **performance**, since heavy computations are done **once at compile time**.
* Ensure **immutability** — values are **guaranteed constant** after initialization.

---

## 🔹 Why `constexpr`?

Before C++11:

* All computations were done **at runtime**.
* Even if a value was logically constant, the compiler couldn’t optimize it.

With `constexpr`:

* The compiler performs **constant evaluation** whenever possible.
* If compile-time evaluation is not possible, it may still run at **runtime** (depending on context).

---

## 🔹 Key Characteristics

| Feature                     | Description                                                                  |
| --------------------------- | ---------------------------------------------------------------------------- |
| **Compile-time evaluation** | Values are computed by the compiler if all inputs are known at compile time. |
| **Immutability**            | `constexpr` variables are **constants** – they **cannot be reassigned**.     |
| **Improved performance**    | Moves potentially heavy computations to compile time.                        |
| **Validation**              | Can be used with `static_assert` for compile-time checks.                    |

---

## 🔹 Syntax

```cpp
constexpr type variable_name {value};
```

✅ **Rules:**

1. Must be initialized with a **compile-time constant expression**.
2. The **initializer must be known** at compile time.
3. The variable is **implicitly const**.

---

## 🔹 Example Code Explanation

```cpp
#include <iostream>

int main() {
    constexpr int SOME_LIB_MAJOR_VERSION {1237};
    constexpr int eye_count {2};
    constexpr double PI {3.14};

    std::cout << "eye count : " << eye_count << std::endl;
    std::cout << "PI : " << PI << std::endl;

    // int leg_count {2};                // Non-constexpr
    // constexpr int arm_count{leg_count}; // ❌ Error: leg_count not known at compile time

    constexpr int room_count{10};
    constexpr int door_count{room_count};  // ✅ OK - known at compile time

    const int table_count{5};
    constexpr int chair_count{ table_count * 5 }; // ✅ Works, since table_count is const initialized with literal

    // static_assert( SOME_LIB_MAJOR_VERSION == 1237 ); // ✅ Compile-time check

    std::cout << "App doing its thing..." << std::endl;

    return 0;
}
```

### 🧩 Output:

```
eye count : 2
PI : 3.14
App doing its thing...
```

---

## 🔹 Compile-Time Validation with `static_assert`

`static_assert` ensures conditions are **verified at compile time**, not at runtime.

```cpp
constexpr int version = 2;
static_assert(version == 2, "Version mismatch!"); // ✅ OK
```

If the condition fails, compilation stops with the provided error message.

---

## 🔹 Common Mistakes

| Mistake                                                     | Reason                               |
| ----------------------------------------------------------- | ------------------------------------ |
| Using a non-constant variable in `constexpr` initialization | Value not known at compile time      |
| Trying to modify a `constexpr` variable                     | They are **read-only**               |
| Using runtime input for a `constexpr`                       | Compile-time evaluation not possible |

Example ❌:

```cpp
int x = 10;
constexpr int y = x; // Error: x not constexpr
```

---

## 🔹 Difference Between `const` and `constexpr`

| Aspect                | `const`                 | `constexpr`                      |
| --------------------- | ----------------------- | -------------------------------- |
| **Introduced in**     | C++98                   | C++11                            |
| **Evaluation Time**   | Runtime                 | Compile-time (if possible)       |
| **Value Requirement** | Can be runtime constant | Must be compile-time constant    |
| **Usage**             | Prevents modification   | Enables compile-time computation |
| **Example**           | `const int a = f();`    | `constexpr int b = 5 * 10;`      |

---

## 🔹 `constexpr` Functions (C++11 and beyond)

You can also define **functions** as `constexpr`, enabling compile-time evaluation if inputs are known at compile time.

```cpp
constexpr int square(int n) {
    return n * n;
}

int main() {
    constexpr int s = square(5); // Computed at compile time
    int x = 10;
    int y = square(x);           // Computed at runtime
}
```

---

## 🔹 Summary

| Concept           | Explanation                                             |
| ----------------- | ------------------------------------------------------- |
| **Purpose**       | Move computation from runtime → compile time            |
| **Introduced in** | C++11                                                   |
| **Eval Time**     | Compile-time if all inputs are constexpr                |
| **Mutability**    | Immutable (cannot reassign)                             |
| **Use Cases**     | Constants, compile-time validation, constexpr functions |
| **Benefit**       | Faster runtime performance, safer code                  |

---

## 🧭 Quick Takeaway

> “Use `constexpr` to let the compiler do the heavy lifting before your program even runs.”

---

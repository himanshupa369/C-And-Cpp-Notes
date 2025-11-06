
---

## 🧩 What is `if constexpr` in C++?

`if constexpr` is a **compile-time conditional statement** — similar to `if`, but **the condition is evaluated during compilation**, not at runtime.

It allows you to **include or exclude code** *at compile time* depending on a **compile-time constant expression** (like a `constexpr` value, a type trait, or a template parameter).

---

### 🔹 Syntax

```cpp
if constexpr (compile_time_condition) {
    // Code compiled only if condition is true
} else {
    // Code compiled only if condition is false
}
```

> 🧠 The key difference from a normal `if`:
> In `if constexpr`, the *non-taken branch* is completely **discarded** by the compiler — it’s as if it never existed.

---

### 🔹 Why We Use `if constexpr`

When writing **templates** or **generic code**, sometimes you want to write code that depends on a **type property** — but without causing compilation errors for invalid code paths.

✅ With `if constexpr`, only the valid path is compiled.
❌ With normal `if`, both branches must be *syntactically valid*, even if one is never executed.

---

### 🔹 Example 1: Normal `if` vs `if constexpr`

```cpp
#include <iostream>
#include <type_traits>

template<typename T>
void printTypeInfo(T value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << value << " is an integer type\n";
    } else {
        std::cout << value << " is not an integer type\n";
    }
}

int main() {
    printTypeInfo(10);       // int → integer type
    printTypeInfo(3.14);     // double → not integer type
}
```

🧾 **Output:**

```
10 is an integer type
3.14 is not an integer type
```

✔ Here, depending on the template type `T`, **only one branch is compiled**.
If `T` is an integer, only the first block is compiled.
If `T` is not integral, the second block is compiled instead.

---

### 🔹 Example 2: Avoiding Compilation Errors

Suppose we try to call `.size()` on a type that might not have it:

❌ **Without `if constexpr` (compilation error):**

```cpp
template<typename T>
void show(T x) {
    if (std::is_class_v<T>) {
        std::cout << x.size() << std::endl;  // error if T has no .size()
    }
}
```

✅ **With `if constexpr` (safe and correct):**

```cpp
template<typename T>
void show(T x) {
    if constexpr (std::is_class_v<T>) {
        std::cout << x.size() << std::endl;
    } else {
        std::cout << x << std::endl;
    }
}
```

Now, if `T` is a built-in type (like `int`), the `.size()` branch isn’t even compiled, so there’s **no error**.

---

### 🔹 Example 3: Compile-Time Type Decisions

```cpp
#include <iostream>
#include <type_traits>

template<typename T>
void describe() {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integral type\n";
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Floating point type\n";
    } else {
        std::cout << "Other type\n";
    }
}

int main() {
    describe<int>();      // Integral type
    describe<double>();   // Floating point type
    describe<std::string>(); // Other type
}
```

---

### 🔹 Key Properties of `if constexpr`

| Property                       | Description                                              |
| ------------------------------ | -------------------------------------------------------- |
| **Evaluated at compile time**  | The condition must be a compile-time constant expression |
| **Eliminates unused branch**   | The non-taken branch is *not even compiled*              |
| **Avoids invalid code errors** | Helps write type-safe generic code                       |
| **Used mostly in templates**   | For type-dependent compile-time logic                    |
| **Introduced in**              | C++17                                                    |

---

### 🔹 Comparison: `if` vs `if constexpr`

| Feature                     | `if`         | `if constexpr`          |
| --------------------------- | ------------ | ----------------------- |
| Evaluated                   | Runtime      | Compile-time            |
| Both branches must be valid | ✅ Yes        | ❌ No                    |
| Used in                     | General code | Templates / type traits |
| Eliminates branch code      | ❌ No         | ✅ Yes                   |

---

### ✅ **Summary Notes**

* `if constexpr` → *compile-time conditional branching*.
* Only one branch is compiled — no runtime cost.
* Prevents compilation errors in template code.
* Great for *type-based specialization*.
* Introduced in **C++17**.

---


---

# 📌 `if constexpr` in C++

A compile-time conditional execution mechanism

### ✔ Introduced in **C++17**

### Header Required:

```cpp
#include <type_traits>
```

---

## 🔥 What is `if constexpr`?

`if constexpr` allows **compile-time branching**, meaning the compiler selects only the valid branch and **discards others completely**.
Unlike normal `if`, unused code is **not instantiated**, reducing compilation bloat & preventing invalid code from being compiled.

---

### Why is it useful?

| Normal `if`                                                | `if constexpr`                                |
| ---------------------------------------------------------- | --------------------------------------------- |
| Condition evaluated at runtime                             | Condition evaluated at compile-time           |
| Both branches are compiled                                 | Only valid branch is compiled, others removed |
| Invalid code in unused branch still triggers compile-error | Invalid branch safely discarded               |
| Slower, sometimes heavier                                  | Faster & cleaner template instantiations      |

---

## When is `if constexpr` needed?

✔ In **templates** where behavior changes based on type
✔ When selecting implementations for integral, floating, boolean, pointer types
✔ To avoid SFINAE/enable_if complexity
✔ When you want **different code paths at compile time**

---

## 📌 Example from Lecture

```cpp
#include <iostream>
#include <type_traits>

void func_floating_point(double d) {
    std::cout << "func_floating_point called...\n";
} 
void func_integral(int i) {
    std::cout << "func_integral called...\n";
} 

template <typename T>
void func(T t)
{
    if constexpr(std::is_integral_v<T>)
        func_integral(t);
    else if constexpr(std::is_floating_point_v<T>)
        func_floating_point(t);
    else
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>,
                      "Argument must be integral or floating point");
}

int main() {
    func(12);        // calls func_integral -> integral branch only exists
    func(12.5);      // calls func_floating_point
    // func("Hello"); // ❌ compile-time error (static_assert triggers)
}
```

---

## 🧠 Key Learning

| Feature                   | Meaning                                                |
| ------------------------- | ------------------------------------------------------ |
| `if constexpr(condition)` | Runs only when condition true → compile-time           |
| Uses `type_traits`        | `std::is_integral_v<T>`, `std::is_floating_point_v<T>` |
| No unused code included   | Other branches removed from binary completely          |
| Safer than normal `if`    | prevents unused invalid code                           |

---

## Advantages

✔ Compile-time dispatch → **Zero runtime overhead**
✔ Eliminates invalid code paths → **safer template programming**
✔ Smaller & optimized output binary
✔ Replaces complex SFINAE and `enable_if` patterns
✔ Improves readability & maintainability

---

## Limitations / When Not Needed

❌ Not useful for runtime decisions
❌ Only works when conditions are **constexpr-evaluatable**
❌ Introduced in C++17 → not available in older compilers

---

## Real-World Use Cases

| Scenario                              | Example                                       |
| ------------------------------------- | --------------------------------------------- |
| Writing type-dependent template logic | Handling int, float, pointer differently      |
| Serialization based on type           | print differently for arithmetic vs struct    |
| Numerical libraries                   | optimized integer vs floating math            |
| Generic container utils               | detect iterator category & optimize execution |

---

---

### 📝 Summary

`if constexpr` is one of the most powerful tools in Modern C++ template programming.
It enables **compile-time branching**, removing unnecessary code paths and giving safer, optimized, shorter template instantiations.

> **Compile-time conditions → clean templates → fast binary**

---
U can also prepare:

🔸 Comparison with `enable_if` & Concepts (C++20+)
🔸 More examples (switch-like type dispatch, tag dispatching, iterator-specific behavior)



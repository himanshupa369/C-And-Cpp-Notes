
---

# ⚙️ `constinit` in C++20 — Compile-Time Initialization Guarantee

---

## 🔹 Introduction

`constinit` is a **C++20 keyword** that ensures a **variable is initialized at compile time**.
It **does not make the variable constant**, but it **guarantees** that initialization happens **before runtime**.

Think of it as:

> 🔸 "`constexpr` ensures compile-time value evaluation."
> 🔸 "`constinit` ensures compile-time initialization."

---

## 🔹 Why `constinit`?

Before C++20, there were problems with the **order of initialization** of **global or static variables** across multiple translation units (known as the *Static Initialization Order Fiasco*).

`constinit` was introduced to:

* Prevent **uninitialized global/static variables**.
* Ensure **deterministic initialization**.
* Avoid **runtime initialization delays**.

---

## 🔹 Key Properties

| Property              | Description                                                                                       |
| --------------------- | ------------------------------------------------------------------------------------------------- |
| **Initialization**    | Must occur **at compile time**.                                                                   |
| **Mutability**        | Variable **can be modified** after initialization (unlike `const` or `constexpr`).                |
| **Scope restriction** | Can only be applied to **static** or **thread storage duration** variables (not local variables). |
| **Error enforcement** | If initialization can’t be done at compile time → ❌ **Compiler error**.                           |
| **Combination**       | Can be combined with `const`, but **not** with `constexpr`.                                       |

---

## 🔹 Syntax

```cpp
constinit data_type variable_name = compile_time_value;
```

---

## 🔹 Example Code with Explanation

```cpp
#include <iostream>

const int val1 {33};
constexpr int val2 {34};
int val3 {35}; // Runtime value

constinit int age = 88;             // ✅ Initialized at compile time
const constinit int age1 {val1};    // ✅ const + constinit can be combined
constinit int age2 {age1};          // ✅ OK, age1 is const
// constinit int age3 {val3};       // ❌ Error: val3 is a runtime variable

const constinit double weight {33.33};
// constexpr constinit double scale_factor{3.11}; // ❌ Error: can't combine constexpr and constinit

int main() {
    // constinit double height{1.72}; // ❌ Can't use constinit inside main()

    std::cout << "age : " << age << std::endl;
    std::cout << "age1 : " << age1 << std::endl;
    std::cout << "age2 : " << age2 << std::endl;

    age = 33; // ✅ OK - constinit variables are mutable
    std::cout << "age : " << age << std::endl;

    std::cout << "weight : " << weight << std::endl;
    // weight = 44.44; // ❌ Error - constinit + const = immutable

    return 0;
}
```

---

## 🔹 Output

```
age : 88
age1 : 33
age2 : 33
age : 33
weight : 33.33
```

---

## 🔹 Notes from the Slide (Simplified)

* `constinit` says a variable **should be initialized at compile time**.
  It’s a **C++20 keyword**.

* If initialization cannot be evaluated at compile time → ❌ compiler error.

* Such variables are said to be **const-initialized**.

* Can be applied **only** to variables with **static** or **thread storage duration**, e.g. globals or static locals (not automatic local variables).

* Helps **avoid initialization order issues** of global/static variables defined in different translation units.

* `constinit` variables **must be initialized** with a **const** or **literal** value.

* ✅ `const` and `constinit` **can be combined**.
  ❌ `constexpr` and `constinit` **cannot be combined**.

* ⚠️ **Important Distinction:**
  `constinit` **does not make a variable constant**, it only enforces **compile-time initialization**.

---

## 🔹 Difference Between `constexpr`, `const`, and `constinit`

| Feature                         | `constexpr`                 | `const`                 | `constinit`                            |
| ------------------------------- | --------------------------- | ----------------------- | -------------------------------------- |
| **Introduced in**               | C++11                       | C++98                   | C++20                                  |
| **Evaluation**                  | Compile-time (if possible)  | Runtime or compile-time | Must initialize at compile-time        |
| **Mutability**                  | Immutable                   | Immutable               | Mutable                                |
| **Guarantee**                   | Value known at compile time | Value doesn’t change    | Initialization happens at compile time |
| **Can appear inside functions** | ✅ Yes                       | ✅ Yes                   | ❌ No                                   |
| **Can combine with**            | `const`                     | `constexpr`             | `const` only                           |
| **Example**                     | `constexpr int x = 5;`      | `const int y = 10;`     | `constinit int z = 15;`                |

---

## 🔹 Quick Takeaway

> 🧩 `constinit` = “Initialize at compile time, but allow modification later.”
> It prevents *static initialization order fiasco* and ensures *deterministic startup behavior*.

---

## 🧠 Summary

| Concept                   | Meaning                                                               |
| ------------------------- | --------------------------------------------------------------------- |
| `const`                   | Value is constant (read-only)                                         |
| `constexpr`               | Value is computed and known at compile time                           |
| `constinit`               | Variable is initialized at compile time, but not necessarily constant |
| `constinit` + `const`     | Initialized at compile time and immutable                             |
| `constinit` + `constexpr` | ❌ Not allowed                                                         |

---

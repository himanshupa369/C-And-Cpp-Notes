

---

## 🧠 **Preprocessor Interview Questions (C++)**

---

### ✅ **1. What is a preprocessor in C/C++?**

> The preprocessor is a tool that runs **before compilation**. It handles **directives** like `#define`, `#include`, `#ifdef`, etc., modifying the code before it reaches the compiler.

---

### ✅ **2. Name the commonly used preprocessor directives.**

* `#define` – Macro definition
* `#include` – File inclusion
* `#undef` – Macro undefinition
* `#ifdef` / `#ifndef` – Conditional compilation
* `#if`, `#elif`, `#else`, `#endif`
* `#pragma` – Compiler-specific directives
* `#error`, `#line`

---

### ✅ **3. What is the difference between `#include <file>` and `#include "file"`?**

| `#include <file>`       | `#include "file"`           |
| ----------------------- | --------------------------- |
| Searches in system dirs | Searches in local dir first |
| For standard headers    | For user-defined headers    |

---

### ✅ **4. What is the purpose of header guards?**

> To **prevent multiple inclusion** of the same header file.

```cpp
#ifndef MY_HEADER_H
#define MY_HEADER_H
// content
#endif
```

Or use `#pragma once` (C++20 or supported compilers)

---

### ✅ **5. What is the output of this code?**

```cpp
#define VAL 10
#undef VAL
cout << VAL;
```

**🧠 Output:**

* **Compilation error** – `VAL` is undefined.

---

### ✅ **6. Can preprocessor directives be inside functions?**

> ❌ No. Preprocessor directives are executed **before compilation** and must be at **global/file scope**.

---

### ✅ **7. What is the difference between a macro and an inline function?**

| Macro                   | Inline Function              |
| ----------------------- | ---------------------------- |
| Handled by preprocessor | Handled by compiler          |
| No type checking        | Type-checked                 |
| Debugging is hard       | Easier to debug              |
| May cause side effects  | More reliable in expressions |

---

### ✅ **8. Explain `#ifdef` and `#ifndef` with example.**

```cpp
#define DEBUG
#ifdef DEBUG
cout << "Debug mode\n";
#endif

#ifndef RELEASE
cout << "Not in release mode\n";
#endif
```

---

### ✅ **9. What is the role of `#error` directive?**

```cpp
#ifndef VERSION
#error "VERSION is not defined"
#endif
```

> Forces compilation to stop with a message — used for enforcing requirements.

---

### ✅ **10. What does `#pragma` do?**

* Compiler-specific command, not standardized.
* Example:

```cpp
#pragma once  // prevents multiple inclusion
#pragma pack(1)  // change struct alignment
```

---

## 🔍 **Code-Based Preprocessor Questions**

---

### ✅ **11. What is the output?**

```cpp
#define MUL(x, y) ((x)*(y))
int a = 2;
cout << MUL(a + 1, a + 2);
```

**🧠 Expansion:**
`((a + 1)*(a + 2)) = (3 * 4) = 12 ✅`

---

### ✅ **12. Predict output:**

```cpp
#define PRINT cout << "Hello"
#define ENDL endl
int main() {
    PRINT << ENDL;
}
```

✅ Output:

```
Hello
```

---

### ✅ **13. What is the use of `#` and `##`?**

| Operator | Usage           | Example                   |
| -------- | --------------- | ------------------------- |
| `#`      | Stringification | `#define STR(x) #x`       |
| `##`     | Token Pasting   | `#define JOIN(x, y) x##y` |

---

### ✅ **14. Can macros be undefined?**

> Yes, using `#undef`.

```cpp
#define SIZE 10
#undef SIZE
```

---

### ✅ **15. What is the output?**

```cpp
#define A 10
#define B A + 5
cout << B * 2;
```

**🧠 Expansion:**

* `A + 5 * 2 = 10 + 10 = 20 ❌`
* Actually → `10 + 5 * 2 = 10 + 10 = 20 ✅`

To fix:

```cpp
#define B (A + 5)
```

---

## 🔄 **Practical Usage of Preprocessors**

### 💡 Real use-cases:

* Debug logging (`#ifdef DEBUG`)
* Header guards
* Platform-specific code (`#ifdef _WIN32`)
* Memory packing (`#pragma pack(1)`)
* Preventing outdated compiler versions (`#error`)

---



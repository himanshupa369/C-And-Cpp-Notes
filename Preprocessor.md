### 🧠 What are Preprocessor Directives in C?

**Preprocessor directives** in C are **commands that are processed before the actual compilation** of code begins. They start with a **`#` symbol** and **instruct the compiler to perform specific actions** before compiling the source code.

---

### 🔧 Common Preprocessor Directives

| Directive                         | Description                             | Example              |
| --------------------------------- | --------------------------------------- | -------------------- |
| `#include`                        | Includes header files                   | `#include <stdio.h>` |
| `#define`                         | Defines macros (constants or functions) | `#define PI 3.14`    |
| `#undef`                          | Undefines a macro                       | `#undef PI`          |
| `#ifdef`                          | Checks if a macro is defined            | `#ifdef DEBUG`       |
| `#ifndef`                         | Checks if a macro is NOT defined        | `#ifndef VERSION`    |
| `#if`, `#else`, `#elif`, `#endif` | Conditional compilation                 | `#if AGE > 18`       |
| `#pragma`                         | Special commands for the compiler       | `#pragma once`       |

---

### 🧪 Example:

```c
#include <stdio.h>
#define PI 3.14

int main() {
    float radius = 2.0;
    float area = PI * radius * radius;
    printf("Area = %.2f\n", area);
    return 0;
}
```

---

### 🔍 How It Works:

* Before the compiler sees your code, the **preprocessor**:

  1. Replaces `#define PI 3.14` with the value `3.14` wherever `PI` is used.
  2. Inserts the contents of `stdio.h` into the code.

---

### ✅ Summary:

* **Preprocessor directives** make code **modular, readable, and portable**.
* They are **not C statements** (they don’t end with `;`).
* Handled **before compilation**, during the **preprocessing phase**.

---


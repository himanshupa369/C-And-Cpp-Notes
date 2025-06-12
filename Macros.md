

---

## 🧠 **Basics of Macros in C/C++**

### ✅ **1. What is a macro in C/C++?**

> A macro is a **preprocessor directive** (defined using `#define`) that performs **text substitution** before compilation.

```cpp
#define PI 3.14
```

---

## ❓ **Interview Questions on Macros**

### ✅ **2. What’s the difference between a macro and an inline function?**

| Macro                           | Inline Function                |
| ------------------------------- | ------------------------------ |
| Preprocessed (text replacement) | Compiled (type-safe)           |
| No type checking                | Type checking enforced         |
| Hard to debug                   | Easier to debug and maintain   |
| Can lead to side effects        | Safer in expression evaluation |

---

### ✅ **3. Can macros have parameters? Give an example.**

```cpp
#define SQUARE(x) (x * x)
```

⚠️ **Side-effect trap:**

```cpp
int a = 5;
int b = SQUARE(a++);  // Expands to (a++ * a++) ⇒ undefined behavior
```

---

### ✅ **4. What is the use of `#` and `##` in macros?**

* `#`: Converts argument into a string.

```cpp
#define STR(x) #x
cout << STR(Hello); // Output: "Hello"
```

* `##`: Token pasting (concatenation).

```cpp
#define JOIN(x, y) x##y
int xy = 10;
cout << JOIN(x, y);  // Output: 10
```

---

### ✅ **5. What is the output?**

```cpp
#define MUL(a, b) a * b
int main() {
    int x = 2;
    int y = 3;
    cout << MUL(x + 1, y + 1);
}
```

🧠 Output:

* Expands to: `x + 1 * y + 1` ⇒ `2 + 1 * 3 + 1 = 2 + 3 + 1 = 6`
* ❌ Wrong! Precedence issue.
  ✅ Should be: `#define MUL(a, b) ((a) * (b))`

---

### ✅ **6. Can macros be multi-line? How?**

Yes, using `\` at the end of each line.

```cpp
#define LOG(msg) \
    cout << "LOG: " << msg << endl;
```

---

### ✅ **7. Can you undefine a macro?**

```cpp
#define VAL 10
#undef VAL
```

---

### ✅ **8. What is a conditional macro?**

```cpp
#ifdef DEBUG
#define LOG(x) cout << x
#else
#define LOG(x)
#endif
```

🧠 Used to include/exclude debug logs in builds.

---

### ✅ **9. Why are macros discouraged in modern C++?**

* No type safety
* Difficult to debug
* Inline functions / `constexpr` / templates are safer alternatives.

---

### ✅ **10. What’s the difference between `#include <file>` and `#include "file"`?**

| `#include <file>` | Searches in system directories first       |
| ----------------- | ------------------------------------------ |
| `#include "file"` | Searches in current dir first, then system |

---

## 🧪 **Tricky Macro-Based Questions**

### ✅ **11. Can a macro call itself recursively?**

> No. Preprocessor doesn’t support **recursion** or loops.

---

### ✅ **12. What is the use of `__FILE__`, `__LINE__`, `__DATE__`, `__TIME__`?**

They are **predefined macros**:

```cpp
cout << __FILE__ << __LINE__ << __DATE__ << __TIME__;
```

---

### ✅ **13. What is the danger of using macros for constants?**

```cpp
#define LIMIT 10
int arr[LIMIT];  // Works
```

But `LIMIT` is not scoped — might **accidentally clash** with other code.

✅ Use:

```cpp
const int LIMIT = 10; // Scoped, type-safe
```

---

### ✅ **14. Can a macro be used inside a class?**

Yes, but it’s not a **class member**. It's replaced **before compilation**.

```cpp
#define MAX(a,b) ((a) > (b) ? (a) : (b))
class A {
    int getMax(int x, int y) {
        return MAX(x, y);
    }
};
```

---

### ✅ **15. How do you debug macros?**

> Use:

* `g++ -E file.cpp` to see preprocessed code
* Replace with inline functions when possible

---

Great! Let's continue with **more advanced and code-based macro interview questions in C++** — especially those used in systems, embedded, or compiler-level interviews.

---

## 🧠 **Advanced Macro Interview Questions with Code Examples**

---

### ✅ **16. What is the output of this macro?**

```cpp
#define INCREMENT(x) ++x

int main() {
    int a = 5;
    cout << INCREMENT(a) * INCREMENT(a);  
}
```

**🔍 Expansion:**

```cpp
++a * ++a;
```

**🧠 Output:**

* **Undefined behavior** due to **sequence point violation** — modifying `a` more than once without an intervening sequence point.

---

### ✅ **17. Can macros be used to implement inline logging or debugging?**

```cpp
#define DEBUG_LOG(x) cout << "DEBUG: " << #x << " = " << x << endl

int main() {
    int val = 10;
    DEBUG_LOG(val);  // Expands to: cout << "DEBUG: val = 10"
}
```

🧠 Useful for conditional debugging.

---

### ✅ **18. Implement a macro to find the maximum of three numbers.**

```cpp
#define MAX3(a, b, c) ((a > b && a > c) ? a : ((b > c) ? b : c))
```

🧠 Be careful with parentheses to avoid evaluation errors.

---

### ✅ **19. Create a macro that returns the size of an array (not a pointer).**

```cpp
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main() {
    int a[] = {1, 2, 3, 4, 5};
    cout << ARRAY_SIZE(a); // Output: 5
}
```

⚠️ Only works with actual arrays, not pointers.

---

### ✅ **20. What’s wrong with this macro?**

```cpp
#define SQUARE(x) x * x
int main() {
    int a = 3 + 2;
    cout << SQUARE(a); // Output?
}
```

**🔍 Expansion:**

```cpp
3 + 2 * 3 + 2 → 3 + 6 + 2 = 11  ❌ Wrong!
```

✅ Fix:

```cpp
#define SQUARE(x) ((x) * (x))
```

---

### ✅ **21. Write a macro to swap two variables.**

```cpp
#define SWAP(a, b, type) { type temp = a; a = b; b = temp; }

int main() {
    int x = 5, y = 10;
    SWAP(x, y, int);
    cout << x << " " << y;  // Output: 10 5
}
```

---

### ✅ **22. Can we define a macro inside a function?**

No. Macros are **preprocessor directives** and must be defined **outside functions** (at global scope or file scope).

---

### ✅ **23. Can macros be used with class member functions?**

Yes, but with caution:

```cpp
#define PRINT_FUNC cout << __FUNCTION__ << endl

class A {
public:
    void show() {
        PRINT_FUNC;  // prints: show
    }
};
```

---

### ✅ **24. What is the purpose of header guards?**

To prevent **multiple inclusion** of the same header file.

```cpp
#ifndef MY_HEADER_H
#define MY_HEADER_H

// contents

#endif
```

✅ Alternative in C++20:

```cpp
#pragma once
```

---

### ✅ **25. What is token pasting and how is it useful?**

**Token Pasting** with `##` lets you generate code dynamically:

```cpp
#define CREATE_VAR(x) int var_##x = x

int main() {
    CREATE_VAR(10);  // becomes: int var_10 = 10;
    cout << var_10;  // Output: 10
}
```

---

## 🔄 **Macro Best Practices Recap**

| ❌ Avoid                 | ✅ Prefer                             |
| ----------------------- | ------------------------------------ |
| Function-like macros    | Inline/`constexpr` functions         |
| Reusing macro arguments | Evaluate once or use `auto`          |
| Macros for constants    | `const`, `constexpr`, `enum class`   |
| Overusing `#define`     | Namespaces, templates, and functions |

---



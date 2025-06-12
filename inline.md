
---

## ✅ What is an Inline Function?

> An **inline function** is a function whose **function call is replaced with the function code (body)** by the compiler, to reduce overhead of a function call.

---

## ✅ Syntax

```cpp
inline int add(int a, int b) {
    return a + b;
}
```

When `add(2, 3)` is called, it may get **replaced with `2 + 3` directly** in the code during compilation.

---

## ✅ Key Features

| Property        | Details                                    |
| --------------- | ------------------------------------------ |
| Keyword         | `inline`                                   |
| Purpose         | Reduce function call overhead              |
| Scope           | Can be defined inside or outside the class |
| Works well with | Small, frequently called functions         |
| Allowed for     | Both free and member functions             |

---

## ✅ Example

```cpp
#include <iostream>
using namespace std;

inline int square(int x) {
    return x * x;
}

int main() {
    cout << square(5);  // Outputs 25
    return 0;
}
```

---

## 🧠 How Inline Works (Conceptually)

```cpp
cout << square(5);  
// Becomes:
cout << (5 * 5);
```

---

## ✅ When Not to Use Inline

The compiler **may ignore the `inline` request** in these cases:

* Function has **loops**, **recursion**, **switch**, or **complex logic**.
* Function definition is **not visible** at call site.
* Inline is only a **request**, not a command.

---

## 🔧 Inline in Class Definitions

All **member functions defined inside a class are implicitly inline**.

```cpp
class MyClass {
public:
    int square(int x) { return x * x; } // Implicitly inline
};
```

---

## 🚀 Common Interview Questions

---

### 1. ❓ **What is the use of inline functions?**

* Saves overhead of function calls.
* Improves performance for small functions.
* Helps in writing readable code with minimal performance penalty.

---

### 2. ❓ **Are inline functions always inlined?**

> ❌ No. Inline is just a **suggestion** to the compiler.

---

### 3. ❓ **Can a recursive function be inlined?**

> ❌ Usually **not inlined**, since it defeats the purpose due to multiple self-calls.

---

### 4. ❓ **Can a virtual function be inline?**

> Technically yes, but practically **not useful**. Virtual functions are **resolved at runtime**, inline is resolved at **compile time**.

---

### 5. ❓ **What’s the difference between macro and inline function?**

| Aspect       | `#define` Macro | Inline Function |
| ------------ | --------------- | --------------- |
| Type-safe    | ❌ No            | ✅ Yes           |
| Debuggable   | ❌ No            | ✅ Yes           |
| Preprocessor | ✅ Yes           | ❌ No            |
| Scope        | Global          | Scoped          |

---

### 6. ❓ **Does inlining affect binary size?**

> Yes, it may **increase code size** if the function is used many times (code bloat).

---

## 📝 Summary

| Feature         | Inline Function                |
| --------------- | ------------------------------ |
| Goal            | Reduce call overhead           |
| Best for        | Small, simple functions        |
| Implicit Inline | Class-defined member functions |
| Limitation      | Compiler may ignore `inline`   |
| Not good for    | Recursion, large logic         |

---


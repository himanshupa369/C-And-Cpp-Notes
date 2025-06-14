

---

## 🔸 What is `std::auto_ptr`?

`std::auto_ptr` is a deprecated smart pointer from **C++98** that provided basic ownership semantics.
It automatically deletes the object it owns when it goes out of scope, but its behavior is unsafe in modern C++.

---

## 🧠 Interview Questions on `auto_ptr` in C++

---

### 🔹 1. **What is `std::auto_ptr`? Why was it introduced?**

**Answer:**
`auto_ptr` was introduced in C++98 as a smart pointer to help manage **dynamic memory** and avoid manual `delete`. It tries to implement **RAII**.

Example:

```cpp
#include <memory>
std::auto_ptr<int> p1(new int(5));
```

> ⚠️ `std::auto_ptr` is **deprecated in C++11** and **removed in C++17**. Use `std::unique_ptr` instead.

---

### 🔹 2. **Why was `auto_ptr` deprecated?**

**Answer:**
Because it has **broken copy semantics**: copying an `auto_ptr` **transfers ownership**, leaving the source pointer **null**.

```cpp
std::auto_ptr<int> a(new int(10));
std::auto_ptr<int> b = a; // Now a is null, b owns the memory!
```

This makes it:

* Dangerous in **function calls**
* Unsafe for **containers (like vector)**

---

### 🔹 3. **What happens when you copy an `auto_ptr`?**

**Answer:**
Ownership is transferred, and the original pointer becomes null. This violates standard copy semantics.

```cpp
std::auto_ptr<int> a(new int(100));
std::auto_ptr<int> b = a;
std::cout << *b << "\n"; // OK
// std::cout << *a << "\n"; // ❌ Undefined behavior, a is now nullptr
```

---

### 🔹 4. **What replaces `auto_ptr` in modern C++?**

**Answer:**
`std::unique_ptr` (since C++11) is the correct replacement.
It:

* Supports **move semantics** (not copy)
* Works with **containers**
* Is safer and more predictable

---

### 🔹 5. **Can `auto_ptr` be used in STL containers?**

**Answer:**
❌ No. It **breaks** STL containers like `std::vector` because copying `auto_ptr` during reallocation causes loss of ownership.

---

### 🔹 6. **Does `auto_ptr` support custom deleters?**

**Answer:**
❌ No. Unlike `unique_ptr`, `auto_ptr` doesn't support custom deleters. It always uses `delete`.

---

### 🔹 7. **Is `auto_ptr` move-aware?**

**Answer:**
❌ No. `auto_ptr` predates move semantics and simulates them with **copy constructors**, which is misleading and error-prone.

---

### 🔹 8. **Should you use `auto_ptr` in modern code?**

**Answer:**
❌ Absolutely not. It’s deprecated and **removed** in C++17.

Use `std::unique_ptr` or `std::shared_ptr` instead.

---

## 🔄 Summary: `auto_ptr` vs `unique_ptr`

| Feature            | `auto_ptr`    | `unique_ptr`  |
| ------------------ | ------------- | ------------- |
| Introduced in      | C++98         | C++11         |
| Ownership transfer | Via copy      | Via move      |
| STL compatibility  | ❌ No          | ✅ Yes         |
| Custom deleter     | ❌ No          | ✅ Yes         |
| Deprecated         | ✅ Yes (C++11) | ❌ No          |
| Removed            | ✅ C++17       | ❌ Still valid |

---

## ⚠️ Bonus Trap for Interviews

> 💡 If an interviewer asks you to choose between `auto_ptr` and `unique_ptr`, always say:
> "**I would use `unique_ptr` because `auto_ptr` is deprecated and unsafe.**"

---

## 🧪 Code Snippet: Behavior of `auto_ptr`

```cpp
#include <iostream>
#include <memory>

int main() {
    std::auto_ptr<int> p1(new int(42));
    std::auto_ptr<int> p2 = p1;  // Ownership transferred

    if (p1.get() == nullptr)
        std::cout << "p1 is null after transfer\n";

    std::cout << *p2 << "\n";  // Safe
}
```

---

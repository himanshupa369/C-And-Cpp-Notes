
---

# 🧠 **When `new` Fails in C++**

## 📍 Overview

The `new` operator dynamically allocates memory on the **heap**.
However, in **rare cases**, memory allocation can **fail** — for example:

* The heap is exhausted (out of RAM or virtual memory).
* The request size is unrealistically large (e.g. `new int[10^12]`).
* The system cannot satisfy the allocation due to fragmentation.

---

## ⚠️ **Default Behavior (Throws Exception)**

When `new` fails, by default it throws a **`std::bad_alloc`** exception.

```cpp
#include <iostream>
#include <new> // For std::bad_alloc

int main() {
    try {
        int *data = new int[10000000000000000ULL]; // absurdly large
    } catch (const std::bad_alloc &ex) {
        std::cout << "Memory allocation failed: " << ex.what() << std::endl;
    }

    std::cout << "Program continues safely" << std::endl;
    return 0;
}
```

### ✅ Output:

```
Memory allocation failed: std::bad_alloc
Program continues safely
```

### 💡 Key Point:

If you don’t catch this exception, the program **terminates (crashes)** with an **unhandled exception**.

---

## 💬 **Alternative: Use `std::nothrow`**

If you don’t want exceptions, you can tell `new` **not** to throw, but instead to return a **`nullptr`** when allocation fails.

```cpp
#include <iostream>
#include <new> // For std::nothrow

int main() {
    for (size_t i{0}; i < 100; ++i) {
        int *data = new(std::nothrow) int[1000000000]; // large allocation

        if (data != nullptr) {
            std::cout << "Data allocated successfully\n";
            delete[] data;
        } else {
            std::cout << "Data allocation failed\n";
        }
    }

    std::cout << "Program ending well\n";
    return 0;
}
```

### ✅ Output:

```
Data allocated successfully
Data allocation failed
Program ending well
```

Here, `new(std::nothrow)` does **not** throw an exception.
It simply returns `nullptr` if the allocation fails — safe and predictable.

---

## ⚙️ **Comparison Table: Exception vs. `std::nothrow`**

| Feature          | Default `new`                         | `new (std::nothrow)`                |
| ---------------- | ------------------------------------- | ----------------------------------- |
| On failure       | Throws `std::bad_alloc`               | Returns `nullptr`                   |
| Error handling   | Requires `try-catch`                  | Use `if (ptr != nullptr)`           |
| Recommended for  | Exception-safe programs               | Low-level or embedded systems       |
| Overhead         | Slightly higher (exception mechanism) | Slightly lower                      |
| Typical use case | Modern C++ (RAII, smart pointers)     | Legacy or performance-critical code |

---

## 🧱 **Code Example (Exception Handling)**

```cpp
for (size_t i = 0; i < 100; ++i) {
    try {
        int *data = new int[1000000000];
        std::cout << "Data allocated successfully" << std::endl;
        delete[] data;
    } catch (std::bad_alloc &ex) {
        std::cout << "Allocation failed: " << ex.what() << std::endl;
    }
}
```

---

## 💡 **Why Does `new` Fail Rarely in Practice?**

Because:

* Most OSes provide **virtual memory**, which delays actual allocation.
* `malloc()` (which `new` uses underneath) may succeed even when physical memory is insufficient — until the program actually uses that memory.
* Desktop systems usually have gigabytes of memory and swap space.

However, in **embedded systems**, **high-performance servers**, or **real-time apps**, failure is more likely and critical.

---

## 🧠 **Best Practices**

| Tip                                             | Explanation                                                       |
| ----------------------------------------------- | ----------------------------------------------------------------- |
| ✅ Prefer exceptions (default `new`)             | Easier to handle errors cleanly.                                  |
| ✅ Use `nothrow` only if exceptions are disabled | For small systems or low-level code.                              |
| 🧹 Always `delete` allocated memory             | Prevent leaks if allocation succeeded.                            |
| 🔍 Always check pointer validity (`nullptr`)    | Especially with `nothrow`.                                        |
| 🧠 Consider using smart pointers                | `std::unique_ptr` or `std::shared_ptr` free memory automatically. |

---

## 🧩 **Visual Summary**

```
Request memory with new
        │
        ▼
 ┌───────────────────────────┐
 │ Allocation successful?    │
 └───────────────────────────┘
      │                │
      │ yes            │ no
      ▼                ▼
  Return pointer     Throw std::bad_alloc
  to allocated mem   (or return nullptr if nothrow)
```

---

## 🚀 **In Modern C++ (C++11 and beyond)**

You usually don't handle raw `new` / `delete` directly anymore.
Instead, use:

```cpp
#include <memory>
auto data = std::make_unique<int[]>(1000000); // Automatic cleanup
```

If allocation fails → `std::bad_alloc` is thrown automatically, and you can still catch it globally.

---

## 🧾 **Summary Notes**

| Concept          | Meaning                                     |
| ---------------- | ------------------------------------------- |
| `new`            | Allocates memory on heap                    |
| `delete`         | Frees allocated heap memory                 |
| When `new` fails | Throws `std::bad_alloc` (default)           |
| `std::nothrow`   | Prevents exceptions, returns `nullptr`      |
| Common cause     | Out of heap memory                          |
| Handling methods | Try-catch OR nullptr check                  |
| Modern solution  | Smart pointers (`unique_ptr`, `shared_ptr`) |

---

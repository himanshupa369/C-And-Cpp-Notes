
---

## ✅ Basic Interview Questions on RAII in C++

---

### 🔹 1. **What is RAII in C++?**

**Answer:**
RAII stands for **Resource Acquisition Is Initialization**.
It means that **resources (memory, file handles, locks, etc.) are tied to object lifetimes** and acquired during object construction, and released during destruction.

---

### 🔹 2. **Why is RAII important?**

**Answer:**
It:

* Ensures **exception-safe** code.
* Prevents **resource leaks** (like memory or file handles).
* Makes **resource management deterministic** and automatic.
* Removes the need for `delete`, `close()`, or `free()` calls in user code.

---

### 🔹 3. **What types of resources can be managed by RAII?**

**Answer:**

* Memory (`new`/`delete`)
* File handles
* Network sockets
* Mutex locks
* Database connections
* GPU/CPU resources

---

### 🔹 4. **Give an example of RAII using smart pointers.**

```cpp
#include <memory>

void useResource() {
    std::unique_ptr<int> ptr(new int(10)); // resource acquired
    // Use ptr...
} // ptr goes out of scope, resource released automatically
```

---

### 🔹 5. **How does RAII help with exception safety?**

**Answer:**
When an exception is thrown, destructors of local RAII objects are called automatically, which **cleans up resources**.

---

### 🔹 6. **What are some standard C++ features that implement RAII?**

**Answer:**

* `std::unique_ptr` and `std::shared_ptr` (smart pointers)
* `std::lock_guard` and `std::scoped_lock` (mutex locks)
* `std::fstream` (file I/O)
* `std::vector`, `std::string`, etc. (automatic memory management)

---

### 🔹 7. **What happens if you don’t use RAII?**

**Answer:**

* Manual cleanup required (`delete`, `fclose`, etc.)
* Easy to forget cleanup → **leaks**, crashes, or resource exhaustion
* Error-prone in presence of **exceptions or early returns**

---

### 🔹 8. **Can you implement your own RAII wrapper class?**

**Answer:**
Yes, for any resource. Here's an example for a file:

```cpp
#include <cstdio>

class FileRAII {
    FILE* f;
public:
    FileRAII(const char* filename, const char* mode) {
        f = fopen(filename, mode);
    }
    ~FileRAII() {
        if (f) fclose(f);
    }
    FILE* get() { return f; }
};
```

---

## 🔍 Conceptual & Advanced RAII Questions

---

### 🔹 9. **What’s the difference between RAII and garbage collection?**

| RAII                      | Garbage Collection            |
| ------------------------- | ----------------------------- |
| Deterministic destruction | Non-deterministic destruction |
| Immediate cleanup (scope) | Delayed cleanup (GC cycle)    |
| Used in C++               | Used in Java, Python, etc.    |
| Great for performance     | May introduce pause time      |

---

### 🔹 10. **Is RAII related to the Rule of 5?**

**Answer:**
Yes. Since RAII classes often own resources, they need:

* Copy constructor
* Move constructor
* Copy assignment
* Move assignment
* Destructor
  This is the **Rule of 5** in C++11+.

---

### 🔹 11. **How is RAII used with mutexes?**

```cpp
std::mutex mtx;

void threadFunc() {
    std::lock_guard<std::mutex> lock(mtx); // Lock acquired
    // Critical section
} // lock is released when `lock` goes out of scope
```

---

## ⚠️ Common Traps in Interviews

* ❌ Confusing RAII with garbage collection
* ❌ Forgetting that RAII is **automatic**, but still requires correct scoping
* ❌ Not realizing RAII **does not only apply to memory**
* ❌ Failing to explain how destructors help in exception safety

---

## 🧠 Bonus: Rapid-Fire Questions

| Question                                        | Answer                                  |
| ----------------------------------------------- | --------------------------------------- |
| Is RAII a language feature or a design pattern? | A design idiom (pattern), not a keyword |
| Can RAII be used in C?                          | No, C lacks classes/destructors         |
| Does `std::vector` use RAII?                    | Yes                                     |
| Does RAII guarantee no leaks?                   | If implemented correctly, yes           |
| What makes RAII exception safe?                 | Destructors auto-run on stack unwind    |

---


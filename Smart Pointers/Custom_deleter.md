
---

# Custom Deleter in C++

## 1. What Is a Custom Deleter?

A **custom deleter** is a callable object that defines **how a resource should be released** when a smart pointer (`std::unique_ptr` or `std::shared_ptr`) goes out of scope.

By default:

* `std::unique_ptr<T>` uses `delete`
* `std::unique_ptr<T[]>` uses `delete[]`

A custom deleter allows you to **override this behavior**.

---

## 2. Why Do We Need Custom Deleters?

Not all resources are released using `delete`.

### Real-World Resources

| Resource                 | Release Function                   |
| ------------------------ | ---------------------------------- |
| `FILE*`                  | `fclose()`                         |
| POSIX file descriptor    | `close()`                          |
| Socket                   | `closesocket()`                    |
| `malloc` memory          | `free()`                           |
| OS handles               | OS-specific APIs                   |
| Objects from C libraries | Library-specific destroy functions |

Using `delete` for these resources is **undefined behavior**.

---

## 3. Where Are Custom Deleters Used?

### Common Use Cases

1. Wrapping **C APIs** in RAII
2. Managing OS resources
3. Managing memory allocated by `malloc`
4. Closing files and sockets
5. Ensuring exception-safe cleanup
6. Implementing ownership semantics

---

## 4. Smart Pointers That Support Custom Deleters

| Smart Pointer     | Supports Custom Deleter    |
| ----------------- | -------------------------- |
| `std::unique_ptr` | Yes (part of type)         |
| `std::shared_ptr` | Yes (type erased)          |
| `std::weak_ptr`   | Inherits from `shared_ptr` |

---

## 5. Custom Deleter Using a Functor (Function Object)

### Example: Closing a `FILE*`

```cpp
#include <memory>
#include <cstdio>

struct FileCloser
{
    void operator()(FILE* fp) const
    {
        if (fp)
            fclose(fp);
    }
};

int main()
{
    std::unique_ptr<FILE, FileCloser> file(fopen("data.txt", "r"));
}
```

### Key Points

* Functor type becomes part of `unique_ptr` type
* Zero runtime overhead
* Preferred for performance-critical code

---

## 6. Custom Deleter Using a Function Pointer

### Example

```cpp
#include <memory>
#include <cstdio>

void fileCloser(FILE* fp)
{
    if (fp)
        fclose(fp);
}

int main()
{
    std::unique_ptr<FILE, void(*)(FILE*)> file(fopen("data.txt", "r"), fileCloser);
}
```

### Characteristics

* Deleter type is a function pointer
* Slight runtime overhead (indirection)
* Increases `unique_ptr` size

---

## 7. Custom Deleter Using a Lambda

### Example (Stateless Lambda)

```cpp
#include <memory>
#include <cstdio>

int main()
{
    auto deleter = [](FILE* fp) {
        if (fp)
            fclose(fp);
    };

    std::unique_ptr<FILE, decltype(deleter)> file(fopen("data.txt", "r"), deleter);
}
```

### Stateful Lambda Example

```cpp
#include <iostream>
#include <memory>

int flag = 1;

auto deleter = [flag](int* p) {
    if (flag)
        delete p;
};

std::unique_ptr<int, decltype(deleter)> ptr(new int(10), deleter);
```

---

## 8. Custom Deleters with `std::shared_ptr`

### Example

```cpp
#include <memory>
#include <cstdio>

int main()
{
    std::shared_ptr<FILE> file(
        fopen("data.txt", "r"),
        [](FILE* fp) {
            if (fp)
                fclose(fp);
        }
    );
}
```

### Important Difference

* Deleter is **not part of the type**
* Stored in the **control block**
* Easier to use but slightly more memory overhead

---

## 9. `unique_ptr` vs `shared_ptr` with Custom Deleters

| Feature              | `unique_ptr`        | `shared_ptr`     |
| -------------------- | ------------------- | ---------------- |
| Deleter part of type | Yes                 | No               |
| Size impact          | Yes                 | Control block    |
| Performance          | Faster              | Slightly slower  |
| Best use case        | Exclusive ownership | Shared ownership |

---

## 10. Best Practices

1. Prefer **RAII wrappers** over raw pointers
2. Use **functor or stateless lambda** for zero overhead
3. Avoid `std::function` as a deleter (heavy)
4. Prefer `unique_ptr` unless sharing is required
5. Ensure deleter is **noexcept**

---

## 11. Interview-Ready One-Liner

> A custom deleter in C++ allows smart pointers to release resources using user-defined cleanup logic instead of `delete`, enabling RAII-based management of non-memory resources.

---

## 12. Key Takeaway

> **If you acquire a resource in a non-`new` way, you must release it with a custom deleter.**


* Demonstrate pitfalls with `shared_ptr` custom deleters
* Compare custom deleters vs wrapper classes

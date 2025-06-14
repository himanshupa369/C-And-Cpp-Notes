
---

## ✅ Interview Questions on Raw Pointers in C++

---

### 🔹 1. **What is a raw pointer in C++?**

**Answer:**
A **raw pointer** is a built-in pointer type that holds the **memory address of another variable**. It does not manage ownership or lifetime.

```cpp
int x = 10;
int* ptr = &x;
```

---

### 🔹 2. **How are raw pointers different from smart pointers?**

| Feature            | Raw Pointer              | Smart Pointer (`unique_ptr`, `shared_ptr`) |
| ------------------ | ------------------------ | ------------------------------------------ |
| Ownership tracked? | ❌ No                     | ✅ Yes                                      |
| Auto delete?       | ❌ No (must use `delete`) | ✅ Automatically deallocates                |
| Safer?             | ❌ No                     | ✅ Yes                                      |

---

### 🔹 3. **What happens if you forget to delete a raw pointer?**

**Answer:**
You get a **memory leak** — the dynamically allocated memory is never reclaimed.

```cpp
int* ptr = new int(5); // allocated
// delete ptr; <-- If forgotten, memory is leaked
```

---

### 🔹 4. **Can a raw pointer be `nullptr`?**

**Answer:**
Yes. C++11 introduced the keyword `nullptr` to represent a null pointer.

```cpp
int* p = nullptr;
```

---

### 🔹 5. **How do you allocate and deallocate memory with raw pointers?**

```cpp
int* arr = new int[5]; // allocation
delete[] arr;          // deallocation
```

---

### 🔹 6. **What is a dangling pointer?**

**Answer:**
A dangling pointer **points to a memory location that has been freed**.

```cpp
int* p = new int(5);
delete p;
*p = 10; // ❌ Undefined behavior (dangling)
```

---

### 🔹 7. **What is a wild pointer?**

**Answer:**
A pointer that is **declared but not initialized**, leading to undefined behavior when accessed.

```cpp
int* p; // wild pointer
*p = 10; // ❌ Dangerous
```

---

### 🔹 8. **What is pointer arithmetic?**

**Answer:**
Operations like `++`, `--`, `+`, and `-` are valid on raw pointers to navigate arrays:

```cpp
int arr[3] = {1, 2, 3};
int* p = arr;
p++; // now points to arr[1]
```

---

### 🔹 9. **Can raw pointers be used with classes?**

**Answer:**
Yes, but you need to manually manage memory using `new` and `delete`:

```cpp
class MyClass {};
MyClass* obj = new MyClass();
delete obj;
```

---

### 🔹 10. **When should raw pointers be avoided?**

**Answer:**
Avoid when:

* Ownership needs to be tracked.
* Exceptions might cause `delete` to be skipped.
* Smart pointers (`unique_ptr`, `shared_ptr`) are more suitable.

---

## ⚠️ Pitfalls of Raw Pointers

| Problem          | Example                         | Safer Alternative        |
| ---------------- | ------------------------------- | ------------------------ |
| Memory Leak      | `new` without `delete`          | Use `unique_ptr`         |
| Dangling Pointer | Access after `delete`           | Set pointer to `nullptr` |
| Double Deletion  | Deleting the same pointer twice | Avoid reuse              |
| Wild Pointer     | Uninitialized pointer           | Initialize to `nullptr`  |

---

### 🔹 11. **Can you pass raw pointers to functions?**

**Yes** — but ownership must be well-documented.

```cpp
void printValue(int* ptr) {
    if (ptr) std::cout << *ptr;
}
```

---

### 🔹 12. **What are pointer to pointer and const pointer types?**

```cpp
int x = 5;
int* p = &x;
int** pp = &p;        // pointer to pointer

const int* p1 = &x;   // pointer to const data
int* const p2 = &x;   // const pointer
const int* const p3 = &x; // both const
```

---

### 🔹 13. **When is it still okay to use raw pointers?**

* For **non-owning** references (e.g., function arguments).
* For **low-level system or hardware programming**.
* Inside legacy codebases.

---

### 🔹 14. **What is `nullptr` and how is it different from `NULL`?**

```cpp
int* p = nullptr; // type-safe null pointer (C++11+)
```

* `nullptr` is **type-safe**.
* `NULL` is just `0` and can lead to ambiguities.

---

## ✅ Summary

| Feature            | Raw Pointer                                    |
| ------------------ | ---------------------------------------------- |
| Ownership tracking | ❌ No                                           |
| Memory safety      | ❌ Manual delete                                |
| Modern alternative | ✅ Smart pointers (`unique_ptr`, `shared_ptr`)  |
| Use-case           | Legacy, system-level, or non-owning references |

---



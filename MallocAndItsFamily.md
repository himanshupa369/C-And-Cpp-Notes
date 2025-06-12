---

## 🧠 **Basic Understanding Questions**

### 1. ✅ **What is `malloc()` and how does it work?**

> Allocates a block of memory of specified size (in bytes). Returns a `void*` to the allocated space. Memory is **not initialized**.

```c++
int* ptr = (int*) malloc(5 * sizeof(int));
```

---

### 2. ✅ **What is `calloc()` and how is it different from `malloc()`?**

> `calloc()` also allocates memory but **initializes all bits to zero**.

```c++
int* ptr = (int*) calloc(5, sizeof(int));  // 5 elements of int, zero initialized
```

| Function | Initialization | Syntax             |
| -------- | -------------- | ------------------ |
| `malloc` | No             | `malloc(n * size)` |
| `calloc` | Yes (zero)     | `calloc(n, size)`  |

---

### 3. ✅ **What is `realloc()` used for?**

> Used to **resize** previously allocated memory.

```c++
int* ptr = (int*) malloc(5 * sizeof(int));
ptr = (int*) realloc(ptr, 10 * sizeof(int)); // expands to 10 ints
```

---

### 4. ✅ **What does `free()` do?**

> Deallocates memory previously allocated by `malloc`, `calloc`, or `realloc`.

```c++
free(ptr);
ptr = nullptr; // Best practice
```

---

## 🧪 **Code-Based Questions**

### 5. ✅ **What is the output of the following code?**

```cpp
int* p = (int*) malloc(3 * sizeof(int));
for(int i = 0; i < 3; i++)
    cout << p[i] << " ";
```

**Output:**

> Garbage values (uninitialized memory)

---

### 6. ✅ **What happens if you `free()` the same memory twice?**

> **Undefined behavior**. Might crash the program.

---

### 7. ✅ **Can `realloc()` shrink memory? What happens to data?**

> Yes. Data is preserved up to the new size.

```cpp
int* p = (int*) malloc(10 * sizeof(int));
p = (int*) realloc(p, 5 * sizeof(int));  // data beyond 5th element lost
```

---

### 8. ✅ **What happens if `realloc()` fails?**

> Returns `NULL`, but original memory block is **not freed**.

```cpp
int* temp = realloc(ptr, new_size);
if (temp != nullptr)
    ptr = temp;
else
    // realloc failed, ptr is still valid
```

---

### 9. ✅ **Why should you set a pointer to NULL after calling `free()`?**

> To avoid **dangling pointer** issues.

```cpp
free(ptr);
ptr = nullptr;
```

---

### 10. ✅ **What is memory leak? How does `malloc()` contribute to it?**

> When dynamically allocated memory is not freed, it leads to a **memory leak** — used memory becomes inaccessible.

---

## 💡 **Tricky/Conceptual Questions**

### 11. ✅ **Can `malloc()` return a `nullptr`?**

> Yes. If memory allocation fails, it returns `NULL` (in C) or `nullptr` in C++ if casted.

---

### 12. ✅ **Can we use `malloc()` in C++? Is it recommended?**

> Technically **yes**, but **not recommended**. C++ provides `new` and `delete` with type safety and constructor calls.

---

### 13. ✅ **What is the return type of `malloc()`? Why do we typecast it in C++?**

> `void*`. In **C++**, typecasting is **required** because implicit conversion from `void*` to other types is not allowed.

---

### 14. ✅ **What is the difference between stack and heap memory allocation?**

| Stack                   | Heap                         |
| ----------------------- | ---------------------------- |
| Compile-time allocation | Runtime (dynamic) allocation |
| Fast & limited          | Slower & large               |
| Freed automatically     | Must be freed manually       |

---

### 15. ✅ **Is it safe to use memory after calling `free()`?**

> No. Doing so leads to **undefined behavior** (dangling pointer).

---

## 🧾 Bonus: Best Practices

* Always check if `malloc` / `calloc` / `realloc` returned `nullptr`.
* Always `free()` every `malloc` or `calloc`.
* Avoid using memory after it’s freed.
* Prefer `new`/`delete` in C++.

---
---

## 🔢 **Code-Based Questions on malloc, calloc, realloc, and free**

---

### ✅ **1. What is the output of this code?**

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int* ptr = (int*)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        cout << ptr[i] << " ";
    }
    free(ptr);
    return 0;
}
```

**🧠 Expected Answer:**

* **Undefined or garbage values**, since `malloc` doesn’t initialize memory.

---

### ✅ **2. Identify the issue in the code:**

```cpp
int* ptr = (int*)malloc(5 * sizeof(int));
ptr[5] = 10;  // Assigning to the 6th element
free(ptr);
```

**🧠 Answer:**

* **Out-of-bounds write**. Index 5 is invalid in a `5`-element array (0–4).
* May cause **heap corruption** or crash.

---

### ✅ **3. What happens in this code?**

```cpp
int* ptr = (int*)calloc(4, sizeof(int));
for (int i = 0; i < 4; i++) {
    cout << ptr[i] << " ";
}
free(ptr);
```

**🧠 Output:**

* `0 0 0 0`
* `calloc` initializes all elements to zero.

---

### ✅ **4. Will this program crash? Why or why not?**

```cpp
int* ptr = (int*)malloc(sizeof(int));
free(ptr);
free(ptr);  // Double free
```

**🧠 Answer:**

* Yes, it **might crash** due to **double free**, which is **undefined behavior**.

---

### ✅ **5. Find the memory leak:**

```cpp
int* ptr = (int*)malloc(10 * sizeof(int));
ptr = (int*)malloc(20 * sizeof(int));
```

**🧠 Answer:**

* First allocation is **leaked** (10 ints) since `ptr` was overwritten.
* Always `free(ptr)` before reassigning.

---

### ✅ **6. What does `realloc()` do here?**

```cpp
int* ptr = (int*)malloc(3 * sizeof(int));
ptr[0] = 1; ptr[1] = 2; ptr[2] = 3;
ptr = (int*)realloc(ptr, 5 * sizeof(int));
ptr[3] = 4; ptr[4] = 5;
for(int i=0; i<5; i++) cout << ptr[i] << " ";
free(ptr);
```

**🧠 Output:**

* `1 2 3 4 5`
* Reallocation preserved old data and added new space.

---

### ✅ **7. Dangerous mistake — spot it:**

```cpp
int* ptr = (int*)malloc(5 * sizeof(int));
free(ptr);
ptr[0] = 100;
```

**🧠 Answer:**

* Accessing memory **after `free`** ⇒ **Dangling pointer**, undefined behavior.

---

### ✅ **8. Proper use of realloc with null check:**

```cpp
int* ptr = (int*)malloc(5 * sizeof(int));
int* temp = (int*)realloc(ptr, 10 * sizeof(int));
if (temp != nullptr)
    ptr = temp;
else
    cout << "Realloc failed!";
```

**🧠 Question: Why use `temp` instead of directly assigning to `ptr`?**

**Answer:**

* If `realloc` fails, it returns `NULL`, and original `ptr` would be lost (memory leak).

---

### ✅ **9. Can you dynamically allocate a 2D array using `malloc()`?**

```cpp
int** arr = (int**)malloc(3 * sizeof(int*));
for (int i = 0; i < 3; i++) {
    arr[i] = (int*)malloc(4 * sizeof(int));
}
```

**🧠 Follow-up: How would you free it?**

```cpp
for (int i = 0; i < 3; i++) {
    free(arr[i]);
}
free(arr);
```

---

### ✅ **10. What is the issue here?**

```cpp
int* ptr = (int*)calloc(1000000000, sizeof(int));
if (ptr == NULL)
    cout << "Memory allocation failed\n";
```

**🧠 Answer:**

* May **fail silently** if OS uses **lazy allocation**.
* Always **check `NULL`** after memory allocation.

---

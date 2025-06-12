
---

## 🧠 Why Dynamic Memory?

In C++, if you don't know the size of data **at compile time**, you use **dynamic memory allocation**:

* **Stack memory**: for fixed-size variables.
* **Heap memory**: for runtime-sized variables (via `new` and `delete`).

---

## 🔸 `new` Operator – Allocating Memory

### Syntax:

```cpp
data_type* pointer = new data_type;           // Single variable
data_type* array = new data_type[size];       // Array
```

### Example:

```cpp
int* p = new int;       // Allocates memory for 1 int
*p = 10;
cout << *p;             // Output: 10
```

```cpp
int* arr = new int[5];  // Allocates array of 5 ints
```

---

## 🔸 `delete` Operator – Deallocating Memory

### Syntax:

```cpp
delete pointer;        // For single variable
delete[] pointer;      // For arrays
```

### Example:

```cpp
delete p;       // Frees memory for int
delete[] arr;   // Frees memory for array
```

---

## ⚠️ Common Mistakes

| Mistake                     | Why it’s wrong                         |
| --------------------------- | -------------------------------------- |
| Using `delete` on array     | Should use `delete[]` instead          |
| Forgetting to delete        | Causes memory leak                     |
| Double `delete`             | Undefined behavior (can crash program) |
| Using uninitialized pointer | Can lead to segmentation fault         |

---

## 🧪 Full Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int* a = new int(42);        // Allocate and initialize
    cout << *a << endl;          // Output: 42
    delete a;                    // Free memory

    int* arr = new int[3]{1, 2, 3};
    for (int i = 0; i < 3; ++i)
        cout << arr[i] << " ";   // Output: 1 2 3
    delete[] arr;                // Free array memory
}
```

---

## 🚨 Memory Leak Example

```cpp
void leak() {
    int* a = new int[100];
    // No delete → memory leak
}
```

---

## ✅ Best Practice

* Always `delete` what you `new`.
* Prefer **smart pointers** (`std::unique_ptr`, `std::shared_ptr`) in modern C++ to avoid manual memory management.

---

### ✅ Interview Quick Q\&A

**Q1:** What is the difference between `malloc` and `new`?

| Feature        | `malloc` | `new`            |
| -------------- | -------- | ---------------- |
| Language       | C / C++  | C++ only         |
| Initialization | No       | Yes              |
| Syntax         | Function | Operator         |
| Return type    | `void*`  | Exact type       |
| Use `free()`   | Yes      | No, use `delete` |

---

**Q2:** What happens if `new` fails?

* By default, it throws `std::bad_alloc`.
* Use `nothrow` to avoid exceptions:

```cpp
int* p = new(nothrow) int;
if (!p) cout << "Allocation failed";
```

---


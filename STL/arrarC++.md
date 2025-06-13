

---

## 📌 **Basic Interview Questions on `std::array`**

### 🔹 Q1: What is `std::array` in C++?

> `std::array` is a **container** that encapsulates **fixed-size arrays**.
> Introduced in **C++11**, it is a **wrapper over C-style arrays**.

---

### 🔹 Q2: How is `std::array` different from C-style arrays?

| Feature           | C-style array | `std::array`                    |
| ----------------- | ------------- | ------------------------------- |
| Size info         | Not available | Stored internally               |
| Member functions  | ❌ None        | ✅ Yes (like `.size()`, `.at()`) |
| STL compatibility | ❌ No          | ✅ Yes (iterators, algorithms)   |
| Bounds checking   | ❌ No          | ✅ `.at()` throws exception      |

---

### 🔹 Q3: Syntax to define a `std::array`?

```cpp
#include <array>

std::array<int, 5> arr = {1, 2, 3, 4, 5};
```

---

## 🧪 **Intermediate/Code-Based Questions**

### 🔹 Q4: How to get the size of a `std::array`?

```cpp
arr.size();  // returns 5
```

---

### 🔹 Q5: How to access elements safely?

```cpp
arr.at(2);  // returns 3, throws std::out_of_range if index invalid
```

---

### 🔹 Q6: Can `std::array` be passed to functions?

✅ Yes, either by **value**, **reference**, or **const reference**:

```cpp
void printArray(const std::array<int, 5>& a);
```

---

### 🔹 Q7: Can you sort a `std::array`?

```cpp
#include <algorithm>

std::sort(arr.begin(), arr.end());
```

---

### 🔹 Q8: Can you use range-based `for` loop?

```cpp
for (int x : arr) cout << x << " ";
```

---

## 🧠 **Advanced Interview Questions**

### 🔹 Q9: Can `std::array` be dynamically resized?

❌ No. It has a **fixed size known at compile time**.

---

### 🔹 Q10: Is `std::array` stored on the heap or stack?

✅ **Stack** — unless manually allocated on the heap.

---

### 🔹 Q11: What happens if you use `.at()` with out-of-range index?

> It throws a **`std::out_of_range`** exception.

---

### 🔹 Q12: How to fill a `std::array` with a value?

```cpp
arr.fill(0);  // fills all elements with 0
```

---

### 🔹 Q13: How to swap two arrays?

```cpp
arr1.swap(arr2);
```

---

### 🔹 Q14: Difference between `.data()` and `.begin()`?

* `.data()` → returns **raw pointer**
* `.begin()` → returns **iterator**

---

### 🔹 Q15: When should you prefer `std::array` over `std::vector`?

> When the size is:

* **Fixed at compile time**
* **Performance-critical**
* **No need to dynamically resize**

---

## ✅ Quick Example for Practice

```cpp
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    std::array<int, 5> arr = {5, 2, 3, 1, 4};
    
    sort(arr.begin(), arr.end());
    
    for (int x : arr)
        cout << x << " ";
    return 0;
}
```

---

## 📘 Summary

| Feature         | `std::array`       |
| --------------- | ------------------ |
| Fixed size      | ✅ Yes              |
| STL support     | ✅ Yes              |
| Safe access     | ✅ `.at()`          |
| Resizable       | ❌ No               |
| Memory location | Stack (by default) |

---

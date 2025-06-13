
---

## 📦 Basic Interview Questions on `std::vector`

### 🔹 Q1: What is `std::vector`?

> `std::vector` is a **dynamic array** in C++ STL. It can **resize itself** automatically when elements are inserted or deleted.

---

### 🔹 Q2: How is `std::vector` different from arrays?

| Feature       | C-style array | `std::vector`    |
| ------------- | ------------- | ---------------- |
| Size change   | ❌ Fixed       | ✅ Dynamic        |
| Bounds check  | ❌ No          | ✅ `.at()` method |
| STL functions | ❌ No          | ✅ Yes            |
| Memory        | Stack         | Heap             |

---

### 🔹 Q3: How do you declare and initialize a `vector`?

```cpp
#include <vector>
std::vector<int> v = {1, 2, 3};
```

---

### 🔹 Q4: How do you add and remove elements?

```cpp
v.push_back(4);   // Add to end
v.pop_back();     // Remove last element
```

---

## 🧪 Intermediate + Practical Questions

### 🔹 Q5: What is the difference between `.at()` and `[]`?

| Operator  | Bounds Checking | Exception                    |
| --------- | --------------- | ---------------------------- |
| `v[i]`    | ❌ No            | ❌ No                         |
| `v.at(i)` | ✅ Yes           | ✅ throws `std::out_of_range` |

---

### 🔹 Q6: What happens when a vector exceeds its capacity?

> The vector automatically **allocates more memory**, **copies** the old data, and **frees** the old memory. This is expensive and causes **reallocations**.

---

### 🔹 Q7: How to avoid frequent reallocations?

```cpp
v.reserve(100);  // Pre-allocate memory
```

---

### 🔹 Q8: How to insert or erase in the middle?

```cpp
v.insert(v.begin() + 2, 99);      // insert 99 at index 2
v.erase(v.begin() + 2);           // erase element at index 2
```

---

### 🔹 Q9: How to clear a vector?

```cpp
v.clear();   // Empties vector but keeps capacity
```

---

### 🔹 Q10: Difference between `capacity()` and `size()`?

| Method       | Meaning                                                |
| ------------ | ------------------------------------------------------ |
| `size()`     | Number of elements currently held                      |
| `capacity()` | Number of elements vector can hold before reallocating |

---

## 🧠 Advanced & Conceptual Questions

### 🔹 Q11: What is the time complexity of `push_back()`?

* **Amortized O(1)**
* But **O(n)** when resizing is needed.

---

### 🔹 Q12: Can we store objects in a vector?

> ✅ Yes. You can store both objects and pointers.
> Remember: Storing large objects may cause performance issues due to copying.

---

### 🔹 Q13: What happens to iterators after `insert()` or `erase()`?

> **Invalidation may occur**.
> Any iterator **after the point of insert or erase** may become invalid.

---

### 🔹 Q14: How to shrink capacity to fit size?

```cpp
v.shrink_to_fit();  // Non-binding request
```

---

### 🔹 Q15: Difference between `resize()` and `reserve()`?

| Method       | Effect on size | Effect on capacity  |
| ------------ | -------------- | ------------------- |
| `resize(n)`  | ✅ changes      | ✅ changes if needed |
| `reserve(n)` | ❌ no change    | ✅ allocates         |

---

## 🔹 Q16: How to iterate through a vector?

```cpp
for (int x : v) cout << x << " ";
```

Or using iterators:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
```

---

## 🔹 Q17: Can vector store user-defined types?

✅ Yes:

```cpp
struct Student {
    string name;
    int roll;
};

std::vector<Student> students;
```

---

## ✅ Summary: Commonly Used Member Functions

| Function          | Purpose                    |
| ----------------- | -------------------------- |
| `push_back()`     | Add element                |
| `pop_back()`      | Remove last                |
| `size()`          | Current size               |
| `capacity()`      | Allocated space            |
| `clear()`         | Remove all elements        |
| `insert()`        | Insert at position         |
| `erase()`         | Remove from position       |
| `resize()`        | Change size                |
| `reserve()`       | Reserve capacity           |
| `shrink_to_fit()` | Request capacity reduction |
| `at(i)`           | Safe access                |
| `[]`              | Fast but unsafe access     |

---

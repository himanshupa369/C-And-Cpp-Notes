---

# 📘 `std::array` — Fixed-Size STL Container

## What is `std::array`?

`std::array` is a **fixed-size sequence container** that wraps a **raw C-style array** while providing STL-style safety and functionality.

* Size is **fixed at compile time**
* Cannot grow or shrink
* Stored **contiguously in memory**
* Designed for **performance, safety, and predictability**

---

## Header Requirement

```cpp
#include <array>
```

---

## Key Characteristics

* Fixed number of elements
* No dynamic memory allocation
* Safer alternative to raw arrays
* Supports STL features (iterators, algorithms, member functions)

📌 If you need resizing → use `std::vector`
📌 If size is known and constant → use `std::array`

---

## Template Parameters

```cpp
std::array<T, N>
```

| Parameter | Meaning                                    |
| --------- | ------------------------------------------ |
| `T`       | Type of elements                           |
| `N`       | Number of elements (compile-time constant) |

---

## Creating `std::array` Objects

### 1️⃣ Uninitialized Array (Contains Garbage)

```cpp
std::array<int, 3> arr;
```

⚠️ Values are **undefined**

---

### 2️⃣ Partial Initialization

```cpp
std::array<int, 3> arr{1, 2};
```

Result:

```
{1, 2, 0}
```

Unspecified elements are **zero-initialized**

---

### 3️⃣ Full Initialization

```cpp
std::array<int, 3> arr{1, 2, 3};
```

---

### 4️⃣ Zero Initialization

```cpp
std::array<int, 3> arr{};
```

Result:

```
{0, 0, 0}
```

---

### 5️⃣ Size Deduction (C++17+)

```cpp
std::array arr{1, 2, 3};
```

✔ Compiler deduces:

```cpp
std::array<int, 3>
```

---

## ❌ Invalid Initialization (Compile-Time Error)

```cpp
std::array<int, 3> arr{1, 2, 3, 4};
```

Reason:

* `std::array` **cannot resize**
* Violates fixed-size design

---

## Accessing Elements

### 1️⃣ Index Operator `[]`

```cpp
arr[0];
```

* Fast
* No bounds checking

---

### 2️⃣ `at()` Method

```cpp
arr.at(1);
```

* Bounds-checked
* Safer than `[]`

---

### 3️⃣ `front()` and `back()`

```cpp
arr.front(); // first element
arr.back();  // last element
```

---

## Capacity & Utility Methods

| Method        | Description                   |
| ------------- | ----------------------------- |
| `size()`      | Number of elements            |
| `empty()`     | Always false unless size = 0  |
| `fill(value)` | Assigns value to all elements |

Example:

```cpp
arr.fill(500);
```

---

## Adding / Removing Elements ❌

🚫 **Not supported**

* No `push_back`
* No `pop_back`
* No resizing

📌 Data must be provided **at creation time**

---

## Looping Through `std::array`

### Using Indexing

```cpp
for (size_t i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
}
```

---

## Accessing Underlying Raw Array

### `data()` Method

```cpp
int* ptr = arr.data();
```

* Returns pointer to underlying C-style array
* Useful for legacy APIs or raw-array functions

Example:

```cpp
print_raw_array(arr.data(), arr.size());
```

---

## Printing `std::array` Using Templates

```cpp
template<typename T, size_t N>
void print_array(const std::array<T, N>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}
```

---

## ⚠️ `std::make_array` (Non-Standard)

```cpp
#include <experimental/array>
auto arr = std::experimental::make_array(1, 2, 3);
```

❌ Not portable
❌ GCC-specific
❌ Not supported by MSVC / Clang

📌 **Avoid in production code**

---

## `std::array` vs Raw Array

| Feature            | Raw Array | `std::array` |
| ------------------ | --------- | ------------ |
| STL compatible     | ❌         | ✅            |
| Size info          | ❌         | ✅            |
| Safer access       | ❌         | ✅            |
| Algorithms support | ❌         | ✅            |

---

## When to Use `std::array`

✅ Use when:

* Size is known at compile time
* No resizing required
* Performance is critical
* Stack allocation preferred

❌ Avoid when:

* Frequent insertions/deletions are needed
* Size changes dynamically

---

## One-Line Summary

> **`std::array` is a fixed-size, stack-allocated STL container that provides safer and richer functionality than raw arrays.**

---


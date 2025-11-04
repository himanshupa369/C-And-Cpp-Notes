
---

# ⚙️ Overflow and Underflow in C++

---

## 🔹 Introduction

In C++, **overflow** and **underflow** occur when numeric operations exceed the **maximum** or **minimum** limits that a variable type can store.

| Term          | Meaning                                                              |
| ------------- | -------------------------------------------------------------------- |
| **Overflow**  | When a value becomes **larger than the maximum limit** of its type.  |
| **Underflow** | When a value becomes **smaller than the minimum limit** of its type. |

---

## 🔹 Key Concepts

* For **unsigned types**, overflow and underflow **wrap around** (cyclic behavior).
* For **signed types**, overflow is **undefined behavior** (unpredictable result).
* The limits depend on the **number of bits** used by the type.

Example:
`unsigned char` → 8 bits → valid range **[0, 255]**

---

## 🔹 Example Code

```cpp
#include <iostream>

int main() {
    // ---------- OVERFLOW ----------
    unsigned char data {250}; // Range: 0–255

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl; // 251

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl; // 252

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl; // 253

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl; // 254

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl; // 255

    ++data; // Overflow: wraps around to 0
    std::cout << "data : " << static_cast<int>(data) << std::endl; // 0

    // ---------- UNDERFLOW ----------
    data = 1;

    --data; // Goes below 0 → wraps to 255
    std::cout << "data : " << static_cast<int>(data) << std::endl; // 255

    --data; // 254
    std::cout << "data : " << static_cast<int>(data) << std::endl; // 254

    return 0;
}
```

---

## 🔹 Output

```
data : 251
data : 252
data : 253
data : 254
data : 255
data : 0      // Overflow wrap-around
data : 255    // Underflow wrap-around
data : 254
```

---

## 🔹 Visual Representation (Unsigned 8-bit)

```
Range: 0 → 255

Overflow: 255 + 1 → 0
Underflow: 0 - 1 → 255
```

---

## 🔹 Notes

| Type       | Overflow Behavior                 | Underflow Behavior |
| ---------- | --------------------------------- | ------------------ |
| `unsigned` | Wraps around (modular arithmetic) | Wraps around       |
| `signed`   | Undefined behavior                | Undefined behavior |

---

## 🔹 Example (Signed Overflow ❌)

```cpp
int a = 2147483647; // Max value for 32-bit int
a = a + 1;          // ❌ Undefined behavior (overflow)
std::cout << a;     // Unpredictable output
```

---

## 🧭 Summary

| Concept            | Meaning                                                                       |
| ------------------ | ----------------------------------------------------------------------------- |
| **Overflow**       | Value exceeds max limit → wraps (unsigned) or undefined (signed)              |
| **Underflow**      | Value drops below min limit → wraps (unsigned) or undefined (signed)          |
| **Unsigned types** | Safe, cyclic wrap-around                                                      |
| **Signed types**   | Undefined behavior                                                            |
| **Prevention**     | Use wider data types (`int`, `long long`) or check before increment/decrement |

---

✅ **Quick Tip:**
Use `<limits>` header to check type limits:

```cpp
#include <limits>
std::cout << (int) std::numeric_limits<unsigned char>::max(); // 255
```

---


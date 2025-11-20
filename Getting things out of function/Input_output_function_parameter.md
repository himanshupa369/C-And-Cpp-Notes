
---

# ⭐ Input & Output Function Parameters in C++

In modern C++ (industry standard), we classify function parameters into **three categories**:

1. **Input parameters**
2. **Output parameters**
3. **Input–Output parameters**

Below is the **professional way** to pass them.

---

# 🔹 1. Output Parameters

An **output parameter** is something the function is expected to **modify and return via its argument**.

### ✔ How to pass output parameters

* **Non-const reference** → `T&`
* **Pointer** → `T*`

### ✔ Which is recommended?

**References are preferred in modern C++**, because:

| Reference (`T&`) | Pointer (`T*`)                  |
| ---------------- | ------------------------------- |
| Cannot be null ✔ | Can be null (must be checked) ❌ |
| Cleaner syntax ✔ | More verbose ❌                  |
| Clear intent ✔   | Looks like C-style ❌            |

### Example

```cpp
void compute_sum(int a, int b, int& result) { // output param
    result = a + b;
}
```

---

# 🔹 2. Input Parameters

These parameters must be **read-only** inside the function.
They represent values that the function should *use*, not modify.

### ✔ How to pass input parameters

Three recommended ways:

1. **const reference** → `const T&`
2. **pointer to const** → `const T*`
3. **const pointer to const** → `const T* const` (rare, strict)

### Why const?

* Prevents accidental modification.
* Enables compiler optimizations.
* Enforces read-only semantics.

### Example

```cpp
void print_name(const std::string& name);        // most common
void show(const int* value);                     // pointer to const
void display(const double* const ptr);           // neither pointer nor value can change
```

---

# 🔹 3. Input–Output Parameters

These are for situations where a function should **read and modify** the same argument.

### ✔ Use

* Non-const reference
* Non-const pointer

---

# 🌟 Summary Table (Professional Standard)

| Purpose                 | Correct Passing Method                   | Why                              |
| ----------------------- | ---------------------------------------- | -------------------------------- |
| **Input** (read only)   | `const T&`, `const T*`, `const T* const` | Prevents modification, efficient |
| **Output** (write only) | `T&`, `T*`                               | Allows modifying caller's data   |
| **Input + Output**      | `T&`, `T*`                               | Allows read/modify               |

---

# ✔ General Industry Recommendation (Modern C++)

### 🟦 **Always prefer references over pointers**

Unless you specifically need:

* null-checks
* array semantics
* optional parameters

### 🟦 For string inputs → ALWAYS use `std::string_view`

This avoids unnecessary copies.

### 🟦 For other read-only parameters → use `const T&`

---

# 💡 Best Practice Example (Real Code)

```cpp
void process_data(
    const std::string_view name, // input
    int& result,                 // output
    double& value                // in-out
) {
    result = name.size();
    value = value * 2.5;
}
```

This style is **modern, efficient, and production-ready**.

---

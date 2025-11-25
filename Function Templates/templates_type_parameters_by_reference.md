
---

# ✅ **1. Introduction**

Template functions normally accept parameters **by value**, meaning arguments are **copied** into the function.
However, template parameters can also be passed **by reference**, allowing the function to operate directly on the original objects instead of copies.

Passing template parameters by reference is useful for performance and correctness, especially with large or non-copyable objects.

---

# ✅ **2. Syntax**

### **By value (default)**

```cpp
template <typename T>
T maximum(T a, T b);   // copy of a and b
```

### **By reference**

```cpp
template <typename T>
const T& maximum(const T& a, const T& b); // reference to original a and b
```

The syntax is exactly like using references with normal functions — simply add `&` to the template parameter.

---

# ✅ **3. Behavior Difference (Value vs Reference)**

### **Pass by Value**

* Arguments are **copied** into function parameters.
* Inside the function, parameters have **different memory addresses**.
* Modifying them does **not** affect originals.
* Useful when working with small, cheap types (`int`, `double`).

### **Pass by Reference**

* Function receives a **reference** to original variables.
* Inside and outside addresses are **the same**.
* Safer when using `const T&` (read-only).
* Efficient for large objects (e.g., `std::string`, vectors, custom classes).

---

# ✅ **4. Example: Passing Template Parameters by Reference**

### ✔ Declaration + Definition separated

*(Valid and commonly used with templates)*

```cpp
#include <iostream>

template <typename T>
const T& maximum(const T& a, const T& b); // Declaration

int main() {

    double a {23.5};
    double b {51.2};

    std::cout << "Out - &a: " << &a << std::endl;

    auto result = maximum(a, b);

    std::cout << "Out - &a: " << &a << std::endl;

    return 0;
}

// Definition
template <typename T>
const T& maximum(const T& a, const T& b){
    std::cout << "In - &a: " << &a << std::endl;
    return (a > b) ? a : b;
}
```

### **Output (conceptual)**

```
Out - &a: 0x7ffd...DE0
In  - &a: 0x7ffd...DE0   <-- SAME address → passed by reference
Out - &a: 0x7ffd...DE0
```

---

# ✅ **5. Why `const T&` Instead of `T&`?**

### ✔ Reasons to use `const T&`

* Prevents accidental modification.
* Allows binding to temporary objects (rvalues).
* Makes function usable with literals or expressions.

### ❌ Using just `T&`:

* Cannot bind to temporaries.
* You might accidentally modify passed arguments.

So the most common and safe signature is:

```cpp
template <typename T>
const T& maximum(const T& a, const T& b);
```

---

# ✅ **6. Template Instantiation (What Actually Happens)**

For a call like:

```cpp
double x = 10.5, y = 7.2;
maximum(x, y);
```

Compiler generates:

```cpp
const double& maximum(const double& a, const double& b);
```

This is **template type deduction**.

---

# ✅ **7. Address Difference Proof (Value vs Reference)**

### **By value → Different addresses**

```cpp
template <typename T>
T maximum(T a, T b){
    std::cout << "In - &a: " << &a << std::endl;
    return (a > b) ? a : b;
}
```

→ `a` inside function is a **copy** → different memory address.

### **By reference → Same addresses**

```cpp
template <typename T>
const T& maximum(const T& a, const T& b){
    std::cout << "In - &a: " << &a << std::endl;
    return (a > b) ? a : b;
}
```

→ Same address → passed by reference.

---

# ✅ **8. ⚠️ Important Rule: DO NOT Overload Value & Reference Versions Together**

This will cause **ambiguity**:

```cpp
template <typename T>
T maximum(T a, T b);  // by value

template <typename T>
const T& maximum(const T& a, const T& b); // by reference
```

Compiler error:

```
error: call to 'maximum' is ambiguous
```

Reason:
Both overloads match the call → compiler cannot choose.

---

# ✅ **9. Pros and Cons**

### **✔ Pass by Reference (`const T&`) — Pros**

* No copying → **faster**, especially for large objects.
* Same memory address inside/outside.
* Can return references.

### **✖ Pass by Reference — Cons**

* Cannot modify parameters (when const).
* Requires object must outlive the function (not for temporaries if `T&`).
* May be confusing for beginners.

---

# ✔ **10. When to Use What?**

| Type                                   | Use by Value     | Use by Const Reference |
| -------------------------------------- | ---------------- | ---------------------- |
| `int`, `char`, `double`                | ✔ Fast and small | OK but unnecessary     |
| `std::string`, `vector`, class objects | ❌ Expensive copy | ✔ Best choice          |
| Non-copyable types                     | ❌ Impossible     | ✔ Required             |
| For modifying arguments                | ❌ Not possible   | Use `T&` (non-const)   |

---

# 🎯 **Summary (Quick Recall)**

* Templates pass by value by default → copies.
* Use `const T&` to avoid copying and improve performance.
* Avoid overloading “by value” and “by reference” templates → ambiguous.
* Reference parameters show same memory address inside/outside.
* Safer to use const reference for read-only behavior.

---

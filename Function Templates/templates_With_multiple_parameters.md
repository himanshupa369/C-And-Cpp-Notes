
---

# 📘 **Function Templates with Multiple Parameters in C++**

**Introduced in:** C++98 <br>
**Header:** No special header required (only `iostream` for printing). <br>
Return type is not deduced by compiler in case of templates. <br>
Function templates can have **more than one template parameter**. This allows functions to operate on **different types at the same time**.

---

# ⭐ **1. Basic Syntax**

```cpp
template <typename T, typename P>
T maximum_basic(T a, P b) {
    return (a > b) ? a : b;
}
```

### ❗ Problem

Return type **depends on order of arguments**, which is *bad design*.

---

# ⭐ **2. Correct Approach — Add a Separate Return-Type Template Parameter**

This fixes the return-type ambiguity.

```cpp
template <typename R, typename T, typename P>
R maximum(T a, P b) {
    return (a > b) ? a : b;    // type of R must support conversion
}
```

✔ Return type no longer depends on argument order
✔ Compiler cannot deduce `R` → You must specify it manually

---

# ⭐ **3. How to Call**

### ✔ Specify return type (R).

Other template parameters (T and P) are deduced automatically.

```cpp
int main() {
    char x{'A'};
    long y{98765};

    // R = int (manually specified)
    // T = char (deduced)
    // P = long (deduced)
    int r1 = maximum<int>(x, y);

    // Specify R and T; P deduced
    int r2 = maximum<int, char>(x, y);

    std::cout << r1 << "\n";
}
```

---

# ⭐ **4. Why Compiler Cannot Deduce Return Type?**

Because deduction works only from **function parameters**, not from the **function body** or return expression.

So this fails:

```cpp
auto r = maximum(x, y);   // ❌ compiler cannot deduce R
```

---

# ⭐ **5. Ordering Template Parameters Affects Flexibility**

### ✔ Best Design:

Put **return-type template parameter first**.

```cpp
template <typename R, typename T, typename P>
R maximum(T a, P b);
```

### Why?

You can call:

* `maximum<R, T, P>()`
* `maximum<R, T>()`
* `maximum<R>()`

But NOT:

* `maximum()` ❌ (return type cannot be deduced)

---

# ⭐ **6. Complete Short Example (Clean + Commented)**

```cpp
#include <iostream>

// Function template with 3 parameters:
// R = return type
// T = type of first argument
// P = type of second argument
template <typename R, typename T, typename P>
R maximum(T a, P b) {
    return (a > b) ? a : b;
}

int main() {
    int a = 5;
    double b = 6.7;

    // Must specify return type (R)
    // T and P are deduced automatically
    double r1 = maximum<double>(a, b);

    // Specify R and T; P deduced
    int r2 = maximum<int, double>(b, a);

    std::cout << "r1 = " << r1 << "\n";
    std::cout << "r2 = " << r2 << "\n";
}
```

---

# ⭐ **7. Pros & Cons**

### ✔ Pros

* Flexible: works with mixed types (e.g., `int` + `double`)
* Return type fully controllable
* Avoids ambiguity caused by argument order

### ❌ Cons

* Must manually specify return type
* Too many template parameters can reduce readability
* Better modern alternative: **auto return type + decltype**

---

# ⭐ **8. Real-World Use Cases**

* Generic math utilities (min/max/avg)
* Working with different numeric types in simulations
* Generic comparison logic
* Library utilities in template-heavy codebases (STL-like code)

---

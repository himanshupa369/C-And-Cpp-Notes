

---

### ✅ **1. What is `auto` in C++?**

**Answer:**
The `auto` keyword allows the compiler to **automatically deduce** the type of a variable from its initializer.
It was **repurposed in C++11** for type inference.

---

### ✅ **2. Can you declare a variable using `auto` without initialization?**

**Answer:**
No, it's a **compile-time error**.
`auto` requires an **initializer** to deduce the type.

```cpp
auto x; // ❌ Error: 'auto' requires an initializer
```

---

### ✅ **3. What type is deduced here?**

```cpp
auto x = 10;
auto y = 3.14;
auto z = 'A';
```

**Answer:**

* `x`: `int`
* `y`: `double`
* `z`: `char`

---

### ✅ **4. Does `auto` preserve `const`?**

```cpp
const int x = 5;
auto y = x;
```

**Answer:**
No, `y` is deduced as `int`, not `const int`.
To preserve const, use:

```cpp
const auto y = x;
```

---

### ✅ **5. What is the difference between `auto`, `auto&`, and `const auto&` in loops?**

**Answer:**

```cpp
std::vector<int> v = {1, 2, 3};
for (auto x : v)      // copy
for (auto& x : v)     // reference
for (const auto& x : v) // const reference
```

---

### ✅ **6. Can `auto` deduce function parameter types?**

**Answer:**
Not before C++14. In C++14 and later, you can write:

```cpp
auto func(auto x) { return x + 1; } // Valid in C++20
```

---

### ✅ **7. Does `auto` work with pointers and references?**

**Answer:**
Yes.

```cpp
int x = 5;
auto* p = &x;    // int*
auto& r = x;     // int&
const auto& cr = x; // const int&
```

---

### ✅ **8. What is the difference between `auto` and `decltype(auto)`?**

**Answer:**

* `auto` drops references and const-qualifiers unless specified.
* `decltype(auto)` deduces the **exact type**, including references and qualifiers.

Example:

```cpp
int x = 10;
int& rx = x;

auto a = rx;         // int (reference dropped)
decltype(auto) b = rx; // int& (reference preserved)
```

---

### ✅ **9. Can `auto` be used with lambda expressions?**

**Answer:**
Yes.

```cpp
auto f = [](int x) { return x * x; };
```

Here, `f` is a lambda object with an overloaded `operator()`.

---

### ✅ **10. What happens in this code?**

```cpp
auto x = {1, 2, 3};
```

**Answer:**
Deduces `x` as `std::initializer_list<int>`

---

### ✅ **11. Can we use `auto` as a function return type?**

**Answer:**

* **C++11:** Use **trailing return type**.

```cpp
auto func() -> int { return 10; }
```

* **C++14+:** Use deduced return type.

```cpp
auto func() { return 10; }
```

---

### ✅ **12. What are the benefits of using `auto`?**

**Answer:**

* Reduces code verbosity
* Improves maintainability
* Helps with complex types (e.g., iterators, lambdas)

---

### ✅ **13. What are the drawbacks of using `auto`?**

**Answer:**

* Can reduce code readability
* Might deduce unintended types if not careful
* Not allowed without initialization

---

### ✅ **14. Predict the output:**

```cpp
int x = 42;
int& rx = x;

auto a = rx;   // ?
auto& b = rx;  // ?
```

**Answer:**

* `a` is `int`
* `b` is `int&`

---

### ✅ **15. Can `auto` be used in class member declarations?**

**Answer:**
**C++14 onwards:** Yes, with immediate initialization:

```cpp
class Test {
    auto x = 10;  // OK in C++14+
};
```

---

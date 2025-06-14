

---

## ✅ `decltype` Interview Questions with Answers

---

### 🔹 **1. What is `decltype` in C++?**

**Answer:**
`decltype` is a C++ keyword that **inspects the declared type** of an expression **without evaluating it**, and deduces its type exactly as-is.

Introduced in **C++11**.

---

### 🔹 **2. What's the difference between `auto` and `decltype`?**

**Answer:**

| Feature         | `auto`                                 | `decltype`                       |
| --------------- | -------------------------------------- | -------------------------------- |
| Deduction       | Based on initializer                   | Based on expression type         |
| Evaluation      | Requires initialization                | Does **not** evaluate expression |
| Reference/const | Removes const/reference (unless asked) | Preserves exactly                |

---

### 🔹 **3. What is the output type of the following?**

```cpp
int x = 10;
decltype(x) a; // what is a?
```

**Answer:**
`a` is of type `int`.

---

### 🔹 **4. What is the output type here?**

```cpp
int x = 10;
int& rx = x;
decltype(rx) b = x;
```

**Answer:**
`b` is of type `int&`, because `decltype` preserves references.

---

### 🔹 **5. Can `decltype` be used without initializing the variable?**

**Answer:**
Yes. Since `decltype` does **not evaluate**, you can use:

```cpp
int x = 5;
decltype(x) y; // y is declared as int
```

---

### 🔹 **6. Can `decltype` be used with expressions?**

**Answer:**
Yes.

```cpp
int a = 1, b = 2;
decltype(a + b) sum; // sum is int
```

---

### 🔹 **7. What's the type of the following?**

```cpp
int x = 0;
decltype((x)) y = x; // Note the parentheses
```

**Answer:**
`y` is `int&` — because `(x)` is an **lvalue expression**, and `decltype((x))` returns a **reference type**.

Without parentheses:

```cpp
decltype(x) y = x; // y is int
```

---

### 🔹 **8. How can `decltype` be used in templates?**

**Answer:**

```cpp
template<typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}
```

Used for **return type deduction** when types are expressions.

---

### 🔹 **9. Can `decltype` be used in trailing return types?**

**Answer:**
Yes.

```cpp
template<typename T, typename U>
auto multiply(T a, U b) -> decltype(a * b) {
    return a * b;
}
```

---

### 🔹 **10. What's the output type?**

```cpp
int x = 5;
const int y = 6;

decltype(x) a = 10;   // ?
decltype(y) b = 20;   // ?
```

**Answer:**

* `a` is `int`
* `b` is `const int`

---

### 🔹 **11. Can `decltype` be used to create an alias for a complicated type?**

**Answer:**
Yes.

```cpp
std::vector<int> v;
decltype(v.begin()) it; // iterator type
```

---

### 🔹 **12. How is `decltype(auto)` different from `auto`?**

**Answer:**

```cpp
int x = 10;
int& rx = x;

auto a = rx;         // int
decltype(auto) b = rx; // int&
```

* `auto` drops reference.
* `decltype(auto)` preserves full type.

---

### 🔹 **13. Can `decltype` be used in function parameters?**

**Answer:**
No, directly using `decltype` as function parameter type like this:

```cpp
void func(decltype(x) val); // ❌ Not valid unless x is in scope
```

However, you can use it **inside function templates or with `decltype(auto)`** in return type.

---

### 🔹 **14. What is the type of this?**

```cpp
int x = 0;
decltype(++x) a = x;
```

**Answer:**
`a` is `int&` — because `++x` is an **lvalue expression returning a reference**.

---

### 🔹 **15. What is the use of `decltype` in generic programming?**

**Answer:**
In templates, where the return type of a function depends on operations on generic types:

```cpp
template<typename T, typename U>
decltype(std::declval<T>() + std::declval<U>()) add(T a, U b) {
    return a + b;
}
```

---

## 🚀 Summary Table of `decltype` Use Cases

| Expression | `decltype` result       |
| ---------- | ----------------------- |
| `x`        | `int` (if `x` is `int`) |
| `(x)`      | `int&`                  |
| `10`       | `int`                   |
| `x + y`    | Type of expression      |
| `++x`      | `int&`                  |
| `x++`      | `int`                   |

---



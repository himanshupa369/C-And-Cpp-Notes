
---

# ⭐ What Are **auto Function Templates** in C++?

In modern C++ (C++14 and above), you can write **function templates without explicitly writing template parameters** by using `auto` in the function parameters or return type.
<br>Supported in C++20. <br>
This concept is called:

### ✔ **Auto-deduced function templates**

or

### ✔ **Abbreviated function templates** (C++20)

These allow the compiler to automatically treat the function as a **template**, even when you don't write `template<typename T>` manually.

---

# 🧩 1. Auto-Deduced Return Type (C++14)

You can write:

```cpp
auto add(int a, double b) {
    return a + b;
}
```

But this is **NOT** a template. Types are fixed (`int`, `double`).

However, if parameters also use `auto`, the function becomes a **function template automatically**:

---

# 🧩 2. **Auto in Function Parameters = Function Template (C++20)**

This is the true meaning of **auto function templates**.

### Example:

```cpp
auto maximum(auto a, auto b) {
    return (a > b ? a : b);
}
```

This becomes:

```cpp
template <typename T, typename P>
auto maximum(T a, P b);
```

✔ No need to write template syntax
✔ Compiler creates separate instantiations for each type pair

---

# 📌 Key Features

### ✔ 1. No need to write template header

```cpp
// OLD
template <typename T>
T square(T x);

// NEW
auto square(auto x) {
    return x * x;
}
```

### ✔ 2. Return type is deduced automatically (like normal auto functions)

### ✔ 3. Compiler automatically converts `auto` parameters into **template type parameters**

---

# ✔ Example

```cpp
#include <iostream>

auto maximum(auto a, auto b){
    return (a > b) ? a : b;
}

int main(){
    std::cout << maximum(3, 5) << '\n';         // int
    std::cout << maximum(3.1, 2.8) << '\n';     // double
    std::cout << maximum(3, 5.7) << '\n';       // mixed types
}
```

---

# 🎯 When Are Auto Function Templates Useful?

### ✔ Cleaner syntax

### ✔ Great for small helper utilities

### ✔ Perfect for generic lambdas and one-liners

### ✔ Works well with modern C++ style

---

# ⚠️ Limitations

| Limitation                                        | Reason                             |
| ------------------------------------------------- | ---------------------------------- |
| Can't separate declaration and definition         | Must write entire function inline  |
| Hard to specify explicit template arguments       | No syntax like `maximum<int>(...)` |
| Can't use `auto` for non-type template parameters | Auto only works for type templates |

---

# 🧠 Difference: `auto maximum(auto a, auto b)` VS `template <typename T> T maximum(T a, T b)`

| Feature                      | auto function template | classic template |
| ---------------------------- | ---------------------- | ---------------- |
| Syntax                       | shortest               | longer           |
| Explicit template args       | ❌ Not possible         | ✔ Possible       |
| Declaration/definition split | ❌ Not allowed          | ✔ Allowed        |
| Clarity for beginners        | ✔ very easy            | harder           |

---

# 📌 Summary (GitHub-Style)

**Auto function templates** (C++20) allow writing templates using `auto` in function parameters, removing the need for explicit `template<typename T>` syntax.

Example:

```cpp
auto maximum(auto a, auto b) {
    return (a > b ? a : b);
}
```

* Equivalent to a template
* Return type deduced
* Cleaner, modern style
* Cannot split into declaration + definition

---



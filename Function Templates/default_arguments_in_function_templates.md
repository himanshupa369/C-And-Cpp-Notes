
---

# 📘 Default Arguments in Function Templates — C++ Notes

## ✅ **1. What Are Default Template Arguments?**

Default template arguments allow you to **specify default values** for template parameters in function templates.

Just like default function parameters, if the caller does **not explicitly specify a template argument**, the compiler uses the default.

---

## ✅ **2. Why Do We Need Default Template Arguments?**

Normally, for function templates:

* The compiler **can deduce parameter types** from function arguments ✔️
* BUT the compiler **cannot deduce return type** ❌

Example (won’t compile without help):

```cpp
template <typename R, typename T, typename P>
R maximum(T a, P b); // compiler can't deduce R
```

To help the compiler, we can:

1. Specify **explicit template arguments**, OR
2. Use **default template arguments** → preferred for convenience.

---

# ⭐ **3. Syntax**

### **Default return type placed first**

```cpp
template <typename ReturnType = double, typename T, typename P>
ReturnType maximum(T a, P b);
```

### **Default return type placed last**

```cpp
template <typename T, typename P, typename ReturnType = double>
ReturnType minimum(T a, P b);
```

➡️ Both are allowed, but order matters:

* When template arguments are partially provided, the compiler fills remaining ones using defaults.

---

# 🧠 **4. Rules to Remember**

### ✔️ **1. Explicit template arguments override defaults**

```cpp
maximum<int>(a, b);  // ReturnType becomes int (overrides default double)
```

### ✔️ **2. Compiler deduces remaining template parameters**

Only specify what you need:

```cpp
maximum<double>(a, b); // T and P deduced, ReturnType = double
```

### ✔️ **3. Default arguments allow separating declaration & definition**

Because return type is not deduced automatically.

### ❌ **4. CANNOT use default arguments with `auto` return type deduction**

This is why `decltype(auto)` versions **cannot** have declaration and definition separated.

---

# 📌 **5. Full Example Code**

```cpp
#include <iostream>

template <typename ReturnType = double , typename T, typename P>
ReturnType maximum ( T a, P b){
    return (a > b) ? a : b;
}

template < typename T, typename P, typename ReturnType = double>
ReturnType minimum ( T a, P b){
    return (a < b) ? a : b;
}

int main(){

    double a{6};
    double b{9.5};

    auto result = minimum <int,double,int> (a,b);
    std::cout << "result : " << result << std::endl;
    std::cout << "sizeof(result) : " << sizeof(result) << std::endl;//4
   
    return 0;
}
```

---

# 🔍 **6. Explanation of the Output**

Call:

```cpp
minimum <int, double, int>(a,b);
```

Template parameter mapping:

| Template Param | Value    | Meaning                        |
| -------------- | -------- | ------------------------------ |
| `T`            | `int`    | First function parameter type  |
| `P`            | `double` | Second function parameter type |
| `ReturnType`   | `int`    | Overrides default `double`     |

Then:

* `a` (double 6) → **converted to int → 6**

* `b` (double 9.5) stays double

* expression `(a < b)` → produces **double result 6.0**

* return type is **int**, so narrowing:

  ```
  double → int → 6
  ```

* `sizeof(result)` = **4 bytes** (int)

---

# 🏁 **7. Key Benefits**

✔ Makes templates easier to use
✔ Eliminates need for explicit template arguments
✔ Allows splitting declaration and definition
✔ Keeps code clean and expressive

---

# 📝 **Short Summary (for GitHub README.md)**

> **Default arguments in function templates** allow us to provide fallback template values when the caller does not specify them.
> Most commonly used for specifying the **return type**, since C++ cannot deduce return types automatically.
> Explicit template arguments override defaults. Easy to use and useful for generic utility functions such as `maximum()` or `minimum()`.

---

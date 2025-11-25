
---

# ⭐ Named Template Parameters for Lambdas in C++20

*(Also called “templated lambdas with named template parameters”)*

C++20 introduced the ability to declare **template parameters directly inside a lambda**, giving lambdas the same power as normal function templates.

This feature is used to:

✔ Create generic lambdas
✔ Control / constrain template types
✔ Prevent mixed-type operations
✔ Write cleaner generic code without a separate function template

---

# 🔥 1. **Basic auto lambda (C++14/17)**

Before C++20 you could write:

```cpp
auto func = [](auto a, auto b) {
    return a + b;
};
```

This becomes a **templated lambda**, but **template parameters are unnamed** and **not controllable**.

You cannot force both parameters to have the same type.

---

# 🔥 2. **C++20: Named template parameters for lambdas**

Syntax:

```
[] <template parameters> (function parameters) { body }
```

Example:

```cpp
auto func = [] <typename T>(T a, T b) {
    return a + b;
};
```

### ✔ Now `T` is a **named template parameter**

✔ Both arguments must be the **same type**
✔ If you pass different types → **compiler error**

---

# 🎯 Why this is useful?

Sometimes you don’t want:

* `int + double`
* `char + float`
* or any unpredictable mixed-type return

Named template parameters let you **enforce type constraints**.

---

# ⭐ 3. Allowing different types (multiple template parameters)

```cpp
auto func = [] <typename T, typename P>(T a, P b) {
    return a + b;
};
```

✔ Now `T` and `P` can be different
✔ Return type will be deduced using usual C++ rules (largest type wins)

---

# 🧩 Your Working Example

```cpp
#include <iostream>

int main() {

    auto func = [] <typename T, typename P> (T a, P b) {
        return a + b;
    };

    char a {'c'};
    int b {63};

    auto result = func(a, b);

    std::cout << "result : " << result << std::endl;
    std::cout << "sizeof(result) : " << sizeof(result) << std::endl;

    return 0;
}
```

### Output explanation:

* `'c'` has ASCII value **99**
* `99 + 63 = 162`
* Result type is `int`
* `sizeof(result) = 4`

---

# 📘 Summary (Perfect for Notes)

### ✔ **Before C++20**

Templated lambdas used only `auto` parameters — **unnamed** and **unconstrained**.

### ✔ **C++20 Adds named template parameters for lambdas**

```
[] <typename T> (T a, T b) { ... }
```

### ✔ Benefits:

* Control template behavior
* Enforce same type or multiple types
* Works like `template<typename T>` functions
* Cleaner than writing a separate function template

### ✔ Multiple parameters:

```
[] <typename T, typename P> (T a, P b) { ... }
```

---


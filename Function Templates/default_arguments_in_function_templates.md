
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

---

````md
# 📘 Default Arguments in Function Templates (C++)

Default arguments in **function templates** work almost the same way as in normal functions, but with
important template-specific rules worth remembering.

---

# ⭐ 1. Basic Example

```cpp
#include <iostream>

template <typename T>
void greet(T name, int times = 1) {   // default argument
    while(times--) {
        std::cout << "Hello " << name << "\n";
    }
}

int main() {
    greet("Himanshu");        // times = 1 (default)
    greet("Pathak", 3);       // times = 3
}
````

✔ Default arguments work exactly as expected
✔ The template parameter `T` does not need to have a default

---

# ⭐ 2. Default Template Arguments (Separate Concept)

You can also provide default arguments *for the template parameters themselves*:

```cpp
template <typename T = int, typename P = double>
auto add(T a, P b) {
    return a + b;
}

int main() {
    auto r1 = add(2, 3.5);     // T=int, P=double (implicit)
    auto r2 = add<int>(7, 4);  // T=int, P=double (default P)
}
```

### ✔ Default function argument

→ belongs to function **parameter list**

### ✔ Default template argument

→ belongs to template **parameter list**

These are independent features.

---

# ⭐ 3. Where Default Arguments Are Allowed

### ✔ Allowed in function template *declaration*

```cpp
template <typename T>
void foo(T a, int b = 100);
```

### ✔ Valid even with separate definition

```cpp
template <typename T>
void foo(T a, int b);      // no default here!

template <typename T>
void foo(T a, int b /* no default */) {
    std::cout << a << " " << b;
}
```

### ❗ IMPORTANT RULE:

> **Default arguments must appear only in the first declaration, never in the definition.**

---

# ⭐ 4. Cannot Put Default Argument in Multiple Declarations

❌ This will not compile:

```cpp
template<typename T>
void foo(T, int b = 10);

template<typename T>
void foo(T, int b = 20);    // ERROR – default given twice
```

---

# ⭐ 5. Default Arguments + Explicit Template Arguments

You can mix both:

```cpp
template <typename T = int>
void show(T value = T{}) {
    std::cout << value << "\n";
}

int main() {
    show();          // T = int, value = 0
    show<double>();  // T = double, value = 0.0
    show(55);        // T deduced = int
}
```

✔ Works fine
✔ Deduction + defaults behave consistently

---

# ⭐ 6. When Template and Function Defaults Interact

Example:

```cpp
template <typename T = double>
T scale(T x = T{1}, double factor = 2.0) {
    return x * factor;
}

int main() {
    scale();            // T=double, x=1.0, factor=2.0
    scale<int>();       // T=int, x=1, factor=2.0
}
```

The rules:

1. If template parameter default is used → affects the type of default function parameters
2. Defaults are always applied **after template argument deduction** completes

---

# ⭐ 7. Summary (Perfect for Interviews & README)

* C++ allows **default arguments** inside function templates.
* They work the same as in normal functions.
* **Default template parameters** and **default function parameters** are separate concepts.
* Default arguments must appear **only once** (in the first declaration).
* You *can* separate declaration & definition, but **default parameters must stay in the declaration**.
* Defaults interact cleanly with template argument deduction.

---


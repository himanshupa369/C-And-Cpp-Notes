
---

# ✅ Structured Bindings in C++

**C++ Version Introduced:** ✅ **C++17** <br>
**Lambda Capture with Structured Bindings:** ✅ **C++20** <br>

---

## ✅ What Are Structured Bindings?

Structured Bindings allow you to **unpack multiple values from an object into separate variables using a simple syntax**.

They work with:

* `struct`
* `class` (only with **public members**)
* `std::pair`
* `std::tuple`
* Arrays

---

## ✅ Basic Syntax

```cpp
auto [a, b] = object;
```

This means:

* `a` → gets first member
* `b` → gets second member
  ✅ **Order matters**

---

## ✅ Example with `struct`

```cpp
struct Point {
    double x;
    double y;
};

Point p{5, 6};

auto [a, b] = p;

std::cout << a << ", " << b;   // Output: 5, 6
```

✅ `a` gets `x`
✅ `b` gets `y`

---

## ✅ Important Rule: Members MUST Be Public

❌ This will FAIL:

```cpp
class Point {
    double x;
    double y;
};
auto [a, b] = p;  // ❌ ERROR: private members
```

✅ This will work:

```cpp
class Point {
public:
    double x;
    double y;
};
```

---

## ✅ Structured Bindings Create **COPIES**

```cpp
auto [a, b] = point1;

point1.x = 44.1;
point1.y = 55.2;

std::cout << a << ", " << b;   // Still prints OLD values
```

✅ `a` and `b` **do NOT change**
✅ They are **independent copies**

---

## ❌ Reference Structured Bindings with `&` (Not Allowed This Way)

```cpp
auto [&a, &b] = point1;   // ❌ INVALID SYNTAX
```

⛔ This syntax is **not allowed**
✅ Correct way (C++17):

```cpp
auto& [a, b] = point1;   // ✅ Proper reference binding
```

---

## ✅ Structured Bindings in Lambda (C++20)

You can **capture structured binding variables inside a lambda**.

```cpp
auto [a, b] = point1;

auto func = [=]() {
    std::cout << a << std::endl;
    std::cout << b << std::endl;
};

func();
```

✅ Works only from **C++20 onward**
❌ If you **don’t capture `a` and `b`**, compiler error occurs

---

## ✅ Why `auto` Is Mandatory

❌ This is INVALID:

```cpp
double [a, b] = point1;   // ❌ ERROR
```

✅ Only valid syntax:

```cpp
auto [a, b] = point1;
```

---

## ✅ Your Program’s Behavior Summary

| Step                 | Output Behavior    |
| -------------------- | ------------------ |
| Initial print        | `(5, 6)`           |
| Structured binding   | `a=5, b=6`         |
| Modify point         | `(44.1, 55.2)`     |
| Print `a`, `b` again | Still `5, 6`       |
| Lambda capture       | Prints same copies |

---

## ✅ Advantages

* ✅ Clean and readable code
* ✅ No `.x`, `.y`, `.first`, `.second`
* ✅ Works with tuples, maps, arrays
* ✅ Great for modern C++ style

---

## ❌ Limitations

* ❌ Only works with **public members**
* ❌ Always uses **auto**
* ❌ Creates **copies by default**
* ❌ Direct reference binding syntax with `&` inside brackets is tricky
* ❌ Lambda capture works properly only from **C++20**

---

## ✅ Real-World Use Cases

* Iterating `std::map`
* Tuple return values
* Clean struct access
* Lambda data processing
* Competitive programming

---

## ✅ Interview One-Line Answer

> Structured binding is a C++17 feature that allows unpacking object data into individual variables using `auto [a, b]`, and it creates copies unless bound by reference.

---


# Structured Bindings within Lambdas (C++)

**C++ Version Introduced:**

* Structured Bindings → **C++17**
* Use inside lambdas → **C++17**

---

## ✅ What are Structured Bindings?

Structured bindings allow you to **decompose objects into named variables** in a clean way.

Instead of:

```cpp
std::pair<int, int> p{10, 20};
int x = p.first;
int y = p.second;
```

You write:

```cpp
auto [x, y] = p;
```

---

## ✅ Using Structured Bindings inside Lambdas

Structured bindings **cannot appear directly in lambda parameter lists (until C++23)**, BUT you can:

### ✅ Method 1: Use structured binding **inside the lambda body**

```cpp
#include <iostream>
#include <utility>

int main() {
    auto lambda = [](const std::pair<int, int>& p) {
        auto [x, y] = p;   // Structured binding inside lambda body
        std::cout << x << " " << y << std::endl;
    };

    lambda({10, 20});
}
```

---

### ✅ Method 2: With `std::map` or containers

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> data{
        {1, "A"}, {2, "B"}
    };

    auto lambda = [](const auto& pair) {
        auto [key, value] = pair;
        std::cout << key << " -> " << value << std::endl;
    };

    for (const auto& element : data) {
        lambda(element);
    }
}
```

---

### ✅ Method 3: Using `auto` parameter + structured binding

```cpp
auto lambda = [](auto pair) {
    auto [a, b] = pair;
    std::cout << a + b << std::endl;
};

lambda(std::pair{5, 7});
```

---

## 🚫 What is NOT Allowed (Before C++23)

This is ❌ NOT allowed in C++17/C++20:

```cpp
// ❌ Invalid before C++23
auto lambda = [](auto [x, y]) {
    std::cout << x << y;
};
```

✅ This becomes valid only in **C++23**.

---

## ✅ Using Structured Bindings with Lambda Captures

You **cannot structured-bind directly in capture**, but you can do this:

```cpp
std::pair<int, int> p{3, 4};

auto lambda = [p]() {
    auto [x, y] = p;   // Binding after capture
    std::cout << x * y << std::endl;
};

lambda();
```

---

## ✅ Reference Structured Bindings in Lambdas

```cpp
std::pair<int, int> p{10, 20};

auto lambda = [&p]() {
    auto& [x, y] = p;  // Reference binding
    x = 100;
};

lambda();
std::cout << p.first; // Output: 100
```

---

## ✅ With `std::tuple`

```cpp
#include <tuple>

auto lambda = [](const std::tuple<int, double>& t) {
    auto [a, b] = t;
    std::cout << a << " " << b << std::endl;
};

lambda({5, 3.14});
```

---

## ✅ Real-World Use Cases

| Use Case                   | Benefit                  |
| -------------------------- | ------------------------ |
| Iterating `map` in lambdas | Cleaner key–value access |
| Callback data processing   | Readable decomposition   |
| Functional pipelines       | Cleaner logic            |
| Logging/debug lambdas      | Direct variable access   |

---

## ✅ Advantages

* ✅ Cleaner and more readable code
* ✅ No `.first` / `.second` clutter
* ✅ Works with `pair`, `tuple`, arrays, structs
* ✅ Improves lambda readability

---

## ❌ Limitations

* ❌ Cannot be used directly in lambda parameters before C++23
* ❌ Can increase copies if not used with references
* ❌ Requires C++17 minimum

---

## ✅ Interview One-Line Answer

> Structured bindings inside lambdas are supported from C++17 by unpacking objects **inside the lambda body**, but they cannot appear directly in parameter lists until C++23.

---



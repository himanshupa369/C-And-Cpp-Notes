

---

## ✅ **C++ Lambda Expressions – Interview Questions with Answers**

---

### 🔹 **1. What is a lambda in C++?**

**Answer:**
A **lambda expression** is an **anonymous function** defined inline using the `[]` syntax. Introduced in **C++11**, it allows defining function objects concisely.

---

### 🔹 **2. What is the basic syntax of a lambda?**

```cpp
[capture](parameters) -> return_type {
    // function body
};
```

Example:

```cpp
auto add = [](int a, int b) -> int {
    return a + b;
};
std::cout << add(2, 3); // 5
```

---

### 🔹 **3. What are the parts of a lambda expression?**

| Part       | Meaning                |
| ---------- | ---------------------- |
| `[]`       | Capture clause         |
| `(params)` | Parameter list         |
| `-> type`  | Return type (optional) |
| `{}`       | Function body          |

---

### 🔹 **4. What is a capture clause in lambda?**

**Answer:**
The capture clause `[ ]` defines **which variables from the outer scope** are accessible inside the lambda.

Examples:

```cpp
int x = 10, y = 20;

[=]() { std::cout << x << y; }  // Capture by value
[&]() { x++; y++; }             // Capture by reference
[x]() { std::cout << x; }       // Capture specific by value
[&x]() { x++; }                 // Capture specific by reference
```

---

### 🔹 **5. Can lambdas be used with STL algorithms?**

**Answer:**
Yes! Lambdas are commonly used with STL functions like `sort`, `for_each`, `transform`, etc.

```cpp
std::vector<int> v = {3, 1, 4};
std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
```

---

### 🔹 **6. Can lambda expressions be stored in variables or passed to functions?**

**Answer:**
Yes. You can store lambdas in `auto`, `std::function`, or pass them directly to functions.

```cpp
auto square = [](int x) { return x * x; };
std::cout << square(5); // 25
```

---

### 🔹 **7. What is a generic lambda (C++14)?**

**Answer:**
Introduced in C++14, it allows **templated lambdas** using `auto` in parameter list.

```cpp
auto print = [](auto x) {
    std::cout << x << "\n";
};

print(10);     // int
print("text"); // const char*
```

---

### 🔹 **8. Can a lambda have a mutable keyword?**

**Answer:**
Yes. By default, captured-by-value variables are **read-only**. Use `mutable` to allow modification.

```cpp
int a = 5;
auto l = [a]() mutable { a++; std::cout << a; };
l();  // Outputs 6
```

---

### 🔹 **9. What's the difference between lambdas and functors?**

| Feature     | Lambda                   | Functor                              |
| ----------- | ------------------------ | ------------------------------------ |
| Syntax      | Concise                  | Verbose (needs class + `operator()`) |
| Reusability | Limited (usually inline) | High (defined as class)              |
| State       | Yes (via capture)        | Yes (via member variables)           |
| Introduced  | C++11                    | From early C++                       |

---

### 🔹 **10. How are lambdas implemented internally?**

**Answer:**
The compiler generates an unnamed class with an overloaded `operator()`. Lambdas are **syntactic sugar** for functors.

---

### 🔹 **11. Can you return a lambda from a function?**

**Answer:**
Yes. Use `auto` or `std::function` as the return type.

```cpp
auto getAdder(int x) {
    return [x](int y) { return x + y; };
}
auto add5 = getAdder(5);
std::cout << add5(3); // 8
```

---

### 🔹 **12. Can lambdas capture `this` pointer?**

**Answer:**
Yes, using `[this]` to access class members inside lambdas.

```cpp
class Demo {
    int x = 10;
public:
    void show() {
        auto f = [this]() { std::cout << x; };
        f();
    }
};
```

---

### 🔹 **13. Can lambdas be recursive?**

**Answer:**
Yes, but you must use `std::function` to refer to itself:

```cpp
std::function<int(int)> fact = [&](int n) {
    return n <= 1 ? 1 : n * fact(n - 1);
};
```

---

### 🔹 **14. Can you use lambdas in multithreading?**

**Answer:**
Yes, lambdas are widely used with `std::thread`.

```cpp
#include <thread>

std::thread t([](){
    std::cout << "Running in thread\n";
});
t.join();
```

---

### 🔹 **15. Can a lambda be `constexpr`?**

**Answer:**
Yes, from **C++17** onward. You can declare lambdas as `constexpr`.

```cpp
constexpr auto square = [](int x) { return x * x; };
static_assert(square(3) == 9);
```

---

## 🚀 Bonus: Short Coding Interview Task

**Q: Use a lambda to filter even numbers from a vector.**

```cpp
std::vector<int> v = {1, 2, 3, 4, 5, 6};
v.erase(std::remove_if(v.begin(), v.end(), [](int x) { return x % 2 != 0; }), v.end());
// v = {2, 4, 6}
```

---


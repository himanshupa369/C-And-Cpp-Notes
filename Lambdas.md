

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

---

## ✅ **Lambda Functions in C++ – Pitfalls & Interview Questions**

---

### 🔹 **1. What are common pitfalls of using lambda functions in C++?**

**Answer:**

Some common pitfalls include:

* **Incorrect capture mode** (capturing by value when reference is needed or vice versa).
* **Dangling reference** from captured variables.
* **Overusing mutable**, leading to bugs.
* **Undefined behavior** if capturing moved/destroyed objects.
* **Performance issues** if large objects are captured by value.
* **Misuse in multithreaded contexts** (data races).
* **Incompatibility with older compilers** (e.g., no generic lambdas in C++11).

---

### 🔹 **2. Can you explain a bug caused by capturing by value instead of reference?**

**Answer:**

```cpp
int x = 10;
auto f = [x]() { return x + 1; };
x = 20;
std::cout << f();  // Output: 11, not 21
```

Here, `x` was captured **by value**, so changes to the original `x` are **not reflected**.

---

### 🔹 **3. What happens if you capture a local variable by reference, but the lambda outlives it?**

**Answer:** **Dangling reference**, causing **undefined behavior**.

```cpp
auto getLambda() {
    int x = 10;
    return [&]() { return x; }; // x will be destroyed!
}
```

Using the returned lambda is **dangerous** — it refers to a destroyed variable.

---

### 🔹 **4. Why can capturing `this` be risky inside lambdas?**

**Answer:**
If the object is deleted or moved before the lambda executes, then using `[this]` can lead to **dangling pointer access**.

✅ Safer option in modern C++ (C++20+): use `[=, *this]` to **capture a copy** of `this`.

---

### 🔹 **5. What is the danger of using `mutable` in lambda functions?**

**Answer:**
Using `mutable` allows modifying captured-by-value variables, which may confuse developers:

```cpp
int a = 10;
auto f = [a]() mutable { a++; };
f();
std::cout << a;  // Still prints 10!
```

✅ Modification affects only the **captured copy**, not the original.

---

### 🔹 **6. Is capturing by default `[=]` or `[&]` safe?**

**Answer:**
No. Default captures can be **unsafe or unclear**:

* `[=]`: silently copies everything (may be costly).
* `[&]`: risks **dangling references** or **unintended modification**.

🔺 **Best practice**: use explicit capture `[x, &y]` for clarity and safety.

---

### 🔹 **7. Can capturing large objects by value cause performance issues?**

**Answer:**
Yes. Capturing large containers (e.g., `std::vector`) by value causes **deep copies**, which can be expensive.

🔁 Use reference capture `[&vec]` or smart pointers where appropriate.

---

### 🔹 **8. What problems can occur in multithreaded code with lambdas?**

**Answer:**
Lambdas can **capture shared variables**, and if multiple threads modify them without synchronization, it causes **data races**.

🔒 Use `std::mutex`, `std::atomic`, or avoid shared capture entirely.

---

### 🔹 **9. Can you use lambda in a loop safely? What should be avoided?**

**Answer:**

Loop variable capture may cause **unexpected values**:

```cpp
std::vector<std::function<void()>> fs;
for (int i = 0; i < 3; ++i) {
    fs.push_back([&]() { std::cout << i << " "; });
}
for (auto& f : fs) f();  // Outputs: 3 3 3
```

✅ Fix: capture by value `[i]`.

---

### 🔹 **10. What happens if you capture a moved-from object in a lambda?**

**Answer:**
Capturing a **moved-from** object by value results in an invalid or empty object inside the lambda.

```cpp
std::string s = "hello";
auto f = [s = std::move(s)]() { std::cout << s; };
std::cout << s;  // undefined or empty
f();             // prints "hello"
```

✅ Safe but must be **intentionally** handled.

---

## ⚠️ Summary of Lambda Pitfalls

| Pitfall                       | Description                           |
| ----------------------------- | ------------------------------------- |
| Capturing wrong variable type | Value vs reference confusion          |
| Lifetime issues               | Dangling reference from local capture |
| Overhead                      | Copying large objects by value        |
| Mutable misuse                | Confusing behavior for copied values  |
| Thread safety                 | Unsafe shared access                  |
| Loop variable capture         | Wrong values due to late binding      |

---



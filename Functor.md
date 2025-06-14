

---

## ✅ **C++ Functor Interview Questions with Answers**

---

### 🔹 **1. What is a functor in C++?**

**Answer:**
A **functor** (function object) is a **class or struct** that **overloads the `operator()`** so it can be used like a function.

---

### 🔹 **2. Why use a functor instead of a regular function?**

**Answer:**

* Functors can **maintain state** across calls (functions cannot).
* Can be **inlined** by the compiler.
* Work well with STL algorithms (`sort`, `for_each`, etc.).
* Provide **better performance** than function pointers (no virtual call overhead).
* Easily customizable via constructors or template parameters.

---

### 🔹 **3. How do you define a functor in C++?**

**Answer:**

```cpp
#include <iostream>
class Multiply {
public:
    int operator()(int a, int b) const {
        return a * b;
    }
};

int main() {
    Multiply mul;
    std::cout << mul(3, 4); // Output: 12
}
```

---

### 🔹 **4. Can a functor hold state? Give an example.**

**Answer:**
Yes, unlike regular functions, functors can store data as member variables.

```cpp
class AddFixed {
    int fixed;
public:
    AddFixed(int f) : fixed(f) {}
    int operator()(int x) const {
        return x + fixed;
    }
};

// Usage
AddFixed add5(5);
std::cout << add5(10); // 15
```

---

### 🔹 **5. How are functors used in STL algorithms?**

**Answer:**
Functors are commonly used in algorithms like `sort`, `for_each`, `transform`, etc.

```cpp
#include <vector>
#include <algorithm>

struct Greater {
    bool operator()(int a, int b) {
        return a > b;
    }
};

std::vector<int> v = {4, 2, 5, 1};
std::sort(v.begin(), v.end(), Greater()); // Sort descending
```

---

### 🔹 **6. What is the difference between a functor and a lambda function?**

| Feature     | Functor                       | Lambda Expression                  |
| ----------- | ----------------------------- | ---------------------------------- |
| Syntax      | Verbose                       | Compact                            |
| Stateful    | Yes                           | Yes                                |
| Type        | User-defined class            | Compiler-generated anonymous class |
| Readability | Less readable for small logic | Better for short logic             |
| Reusability | Better (defined and reused)   | Usually used inline and discarded  |

---

### 🔹 **7. Can functors be templated?**

**Answer:**
Yes, you can define a **template functor** to work with generic types.

```cpp
template<typename T>
struct Adder {
    T operator()(T a, T b) {
        return a + b;
    }
};
```

---

### 🔹 **8. What's the difference between function pointer and functor?**

| Feature     | Function Pointer          | Functor                    |
| ----------- | ------------------------- | -------------------------- |
| State       | Stateless                 | Can hold state             |
| Performance | May require indirect call | Can be inlined             |
| Syntax      | Procedural style          | Object-oriented            |
| Flexibility | Limited                   | More flexible and reusable |

---

### 🔹 **9. Can a functor throw exceptions?**

**Answer:**
Yes, just like any function, a functor can throw exceptions from inside `operator()`.

---

### 🔹 **10. Can `std::function` store a functor?**

**Answer:**
Yes. `std::function` can store lambdas, function pointers, or functors.

```cpp
#include <functional>

std::function<int(int, int)> f = Multiply();
std::cout << f(3, 4); // 12
```

---

### 🔹 **11. What are disadvantages of functors?**

**Answer:**

* Slightly more complex syntax than function pointers or lambdas.
* More verbose to define.
* Compiler-generated lambda objects often offer the same power with simpler syntax.

---

### 🔹 **12. How are functors implemented internally?**

**Answer:**
A functor is just a class with an overloaded `operator()`. The compiler treats `obj(args...)` as a call to `obj.operator()(args...)`.

---

### 🔹 **13. What is a polymorphic functor?**

**Answer:**
A functor with a **templated `operator()`**, allowing it to accept multiple types of input:

```cpp
struct Print {
    template<typename T>
    void operator()(T x) const {
        std::cout << x << " ";
    }
};
```

---


---

# 📌 **Concepts in C++**

### **Header Required:**

```cpp
#include <concepts>     // For predefined standard concepts (C++20)
```

### **Introduced in:**

**C++20**

---

## 🔷 **What are Concepts?**

**Concepts** are **compile-time constraints** placed on template parameters.
They allow you to specify what kind of types a template can accept (e.g., type must be integral, must support `<`, must be iterable etc.)

Think of concepts like **requirements / filters for templates**.

They help us write **cleaner, safer, more readable templates**, avoiding long compiler errors.

---

## 🧠 Why needed?

Before C++20, if you passed the wrong type to a template, errors were long & messy.
Concepts make template requirements explicit → resulting in **clear and short compile-time errors.**

---

## 🔥 Syntax

### 1. Basic Syntax

```cpp
template <typename T>
requires std::integral<T>   // Concept applied here
T add(T a, T b){
    return a + b;
}
```

### 2. Shorthand Syntax

```cpp
auto add(std::integral auto a, std::integral auto b){
    return a + b;
}
```

---

## ✔ Example: Without Concepts (Old C++ Templates)

```cpp
template <typename T>
T square(T x){      
    return x * x;   // Works for int, float, but also wrongly for string
}

int main(){
    std::cout << square(5);          // OK
    std::cout << square(std::string("Hi")); // ❌ Bad, but compiles with huge error
}
```

---

## ✔ Example: With Concepts (C++20)

```cpp
#include <iostream>
#include <concepts>

template <std::integral T>
T square(T x){
    return x * x;
}

int main(){
    std::cout << square(5);        // OK
    // std::cout << square(5.5);  // ❌ Compile-time error: not integral
}
```

**Error becomes clean** such as:
➡ *"T must satisfy std::integral"*
instead of long template trace.

---

## ⭐ Common Standard Concepts (C++20)

| Concept                     | Meaning                    |
| --------------------------- | -------------------------- |
| `std::integral<T>`          | Only integer types allowed |
| `std::floating_point<T>`    | float/double allowed       |
| `std::signed_integral<T>`   | signed ints only           |
| `std::unsigned_integral<T>` | unsigned ints only         |
| `std::ranges::range<T>`     | Type must be iterable      |

---

## 🏗 Creating Your Own Concept

```cpp
#include <concepts>

template<typename T>
concept Number = std::integral<T> || std::floating_point<T>;

Number auto multiply(Number auto a, Number auto b){
    return a * b;
}

int main(){
    std::cout << multiply(10, 3.5);    // ✔ int + double valid
    // std::cout << multiply("Hi", 3); // ❌ not a number
}
```

---

## 🔥 Pros & Cons

### ✔ Advantages

| Benefit                                          | Explanation                        |
| ------------------------------------------------ | ---------------------------------- |
| Better compile-time errors                       | Clear, readable diagnostics        |
| More readable templates                          | Intent is visible directly         |
| Avoid unintended instantiation                   | Wrong types get rejected early     |
| Allows function overloading based on constraints | More powerful template programming |

### ❗ Disadvantages

| Drawback                                | Explanation                            |
| --------------------------------------- | -------------------------------------- |
| C++20 required                          | Older compilers may not support        |
| Slight learning curve                   | Especially for custom concepts         |
| Overuse may reduce template flexibility | Too many restrictions limit generality |

---

## 📌 Real-World Use Cases

| Use Case                          | Example                                       |
| --------------------------------- | --------------------------------------------- |
| Generic math libraries            | Accept only numeric types                     |
| STL ranges & algorithms (C++20)   | `std::ranges::sort`, `views::filter`          |
| Constraint-based overloads        | Different algorithms for floating vs integral |
| Safer template APIs in frameworks | Boost, Eigen, HFT systems, compilers          |

---


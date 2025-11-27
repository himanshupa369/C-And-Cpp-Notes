
---

# 📘 **Building Your Own Concepts in C++**

### **Header**

```cpp
#include <concepts>      // Required for concepts
#include <type_traits>   // Optional: Needed when using type traits
```

### **Introduced in**

**C++20**

---

## 🔷 What are User-Defined Concepts?

User-defined concepts allow you to **create your own compile-time constraints** for template parameters.

You define rules such as:

✓ Type must be integral
✓ Type must support `+`, `*`, `++`
✓ Type must be incrementable, multipliable, comparable, iterable, etc.

A concept passes only if the expression is **valid syntactically at compile time**.

> ⚠ Concepts check ** syntax**, not runtime **values**.

---

## 🔑 Syntax Rules

### 🟩 1. Using type traits (`std::is_integral_v`, `is_floating_point_v`, etc.)

```cpp
template <typename T>
concept MyIntegral = std::is_integral_v<T>;  // true only for integral types
```

Usage:

```cpp
MyIntegral auto add(MyIntegral auto a, MyIntegral auto b){
    return a + b;
}
```

---

### 🟩 2. Using `requires` clause to enforce syntax

```cpp
template <typename T>
concept Multipliable = requires(T a, T b) {
    a * b;  // Only checks if a*b is a valid expression
};
```

Usage:

```cpp
template <typename T>
requires Multipliable<T>
T multiply(T a, T b) {
    return a * b;
}
```

---

### 🟩 3. Multiple requirements inside a concept

```cpp
template <typename T>
concept Incrementable = requires(T a){
    a += 1;   // must support a+=1
    ++a;      // must support prefix increment
    a++;      // must support postfix increment
};
```

Usage:

```cpp
template <Incrementable T>
T add(T a, T b){
    return a + b;
}
```

---

## 🚦 Example Program — Custom Concepts

```cpp
#include <iostream>
#include <type_traits>
#include <concepts>

// Custom concept using type trait
template <typename T>
concept MyIntegral = std::is_integral_v<T>;

// Concept validating multiplication operation
template <typename T>
concept Multipliable = requires(T a, T b) {
    a * b;  
};

// Concept validating increment operations
template <typename T>
concept Incrementable = requires(T a) {
    a += 1;
    ++a;
    a++;
};

// Using our concept in templates
template <typename T>
requires Incrementable<T>
T add(T a, T b){
    return a + b;
}

int main(){
    double x{6}, y{7};
    // std::string x{"Hello"}, y{"World"};  // ❌ Increment not allowed → fails

    add(x,y); // ✔ Valid for double
    std::cout << "Done!\n";
}
```

---

## 🧠 Key Points to Remember

| Point                                      | Meaning                               |
| ------------------------------------------ | ------------------------------------- |
| Concepts fail at compile time              | Safer templates, no runtime surprises |
| They check only syntax                     | Not values of expressions             |
| Can use type traits or requires-clause     | Depends on complexity                 |
| Useful for template-heavy and generic code | Makes API safer & readable            |

---

## ⭐ Pros & Cons

### ✔ Advantages

* Clean & readable template constraints
* Short & meaningful compiler errors
* Enables type-safe generic programming
* Supports overload resolution with rules

### ❗ Limitations

* Works only on compile-time syntax checks
* Requires C++20 (older compilers will fail)
* Over-constraining may reduce generality

---

## 📌 Real-World Use Cases

| Use-case                    | Concept example                               |
| --------------------------- | --------------------------------------------- |
| Generic math libraries      | `incrementable`, `multipliable`, `addable`    |
| Writing safer template APIs | Constrain types instead of documentation only |
| Improving compile clarity   | Clear errors if incorrect type is passed      |
| Ranges & algorithms         | Basis of modern STL (C++20 ranges)            |

---

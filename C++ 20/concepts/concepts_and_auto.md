
---

# 📘 C++20 Concepts with `auto`

### **Introduced in**

✔ **C++20**

---

## 🔹 Key Idea

`auto` automatically deduces types.
With **concepts**, we can constrain `auto` so only certain types are allowed.

We can apply concepts to:

| Where               | Example                              |
| ------------------- | ------------------------------------ |
| Function parameters | `std::integral auto a`               |
| Return type         | `std::integral auto add(...)`        |
| Variables           | `std::floating_point auto x = 3.14;` |

---

## 1️⃣ Concepts Applied to `auto` in Function Parameters

```cpp
std::integral auto add(std::integral auto a, std::integral auto b){
    return a + b;
}
```

✔ Only allows **integral types** → `int`, `long`, `short`, etc.
❌ Rejects floating types → `double`, `float`

### Example

```cpp
add(5, 8);     // ✔ valid
add(5.6, 7.2); // ❌ error — violates std::integral
```

---

## 2️⃣ Concepts on Auto Variables (Return-Type Constrained)

```cpp
std::floating_point auto x = add(5,8);   // ❌ ERROR
```

Reason → `add()` returns an integer, but variable requires **floating_point**.

---

## 3️⃣ Concepts Applied to Variables Independently

```cpp
std::floating_point auto x = 3.9;   // ✔ OK — 3.9 is double
std::floating_point auto y = 7;     // ❌ ERROR — 7 is int
```

✔ Valid only if assigned type matches the concept.

---

## 🧪 Full Code Reference

```cpp
#include <iostream>
#include <concepts>

// Constrains auto parameters to integral values
std::integral auto add(std::integral auto a, std::integral auto b){
    return a + b;
}

int main(){

    std::floating_point auto x = add(5,8); // ❌ error: return type is int

    return 0;
}
```

---

## 📌 When is this Useful?

### Good Use Cases

| Scenario                              | Explanation                 |
| ------------------------------------- | --------------------------- |
| Functions with unknown return types   | Helps enforce expected type |
| Templates without writing `<T>`       | Cleaner syntax              |
| Prevent accidental wrong-type results | Gives compile-time errors   |

### Not Very Useful When

| Situation                                     |
| --------------------------------------------- |
| You already know the literal type you assign  |
| Used for trivial variables like `auto x = 5;` |

---

## ✔ Pros

* Cleaner than template syntax (`template <typename T>`)
* Compile-time enforcement → safer code
* Great for generic functions using `auto`

## ❗ Cons

* Rarely necessary for simple variable declarations
* Overuse may reduce readability

---

### 🔥 Summary

| Feature                     | Benefit                     |
| --------------------------- | --------------------------- |
| `concept + auto (function)` | Easy constrained templates  |
| `concept + auto (variable)` | Type safety but limited use |
| Errors at compile-time      | Better reliability          |

---


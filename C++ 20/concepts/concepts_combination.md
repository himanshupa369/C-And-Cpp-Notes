
---

# 📘 Concepts Combination using `&&` and `||` (C++20)

### **Header**

```cpp
#include <concepts>
#include <type_traits>
```

### **Introduced in**

**C++20**

---

## 🔹 Why Combine Concepts?

Sometimes a type must satisfy **multiple constraints**
or at least **one of several constraints**.

C++20 allows concept combination using:

| Operator | Meaning                          |   |                                        |
| -------- | -------------------------------- | - | -------------------------------------- |
| `&&`     | AND → both concepts must be true |   |                                        |
| `        |                                  | ` | OR → at least one concept must be true |

---

## 1️⃣ Example Concept — `TinyType`

Checks type size using a **simple + nested requirement**

```cpp
template <typename T>
concept TinyType = requires (T t) {
    sizeof(T) <= 4;           // ✔ syntax must be valid (simple)
    requires sizeof(T) <= 4;  // ✔ expression must be true (nested)
};
```

### Meaning:

| Requirement                | Purpose                       |
| -------------------------- | ----------------------------- |
| `sizeof(T) <= 4;`          | Only checks expression exists |
| `requires sizeof(T) <= 4;` | Must evaluate to **true**     |

So allowed types → `char, short, bool, int (on most systems)`

---

## 2️⃣ Using OR (`||`) to Combine Concepts

Allow type if it is **integral OR floating point**

```cpp
template <typename T>
requires std::integral<T> || std::floating_point<T>
T add(T a, T b){
    return a + b;
}
```

✔ Works for → `int, long, double, float`
❌ Fails for → `std::string`

---

## 3️⃣ Using AND (`&&`) to Combine Concepts

Require a type to be **integral AND TinyType**

```cpp
template <typename T>
requires std::integral<T> && TinyType<T>
T add(T a, T b){
    return a + b;
}
```

✔ Allowed → `int, short, char`
❌ Rejected → `long long`, `double`

Because `long long` is integral but **not tiny** (size > 4)

---

## 4️⃣ Inline Concept Definition (Valid but Ugly)

You can define constraint inside `requires`:

```cpp
template <typename T>
requires std::integral<T> &&
         requires (T t) {
             sizeof(T) <=4;
             requires sizeof(T) <=4;
         }
T add(T a, T b){
    return a + b;
}
```

⚠ This compiles but makes code hard to read → avoid this style.

---

---

## 🧪 Full Working Program (From Your Final Code)

```cpp
#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires (T t){
    sizeof(T) <= 4;          // simple requirement
    requires sizeof(T) <= 4; // nested requirement → MUST be true
};

template <typename T>
// requires std::integral<T> || std::floating_point<T>       // OR Example
// requires std::integral<T> && TinyType<T>                  // AND Example
requires std::integral<T> && requires ( T t) {               // Inline Example
    sizeof(T) <=4;
    requires sizeof(T) <=4;
}
T add(T a, T b){
    return a + b;
}

int main(){

    long long int x{7};
    long long int y{5};

    add(x,y); // ❌ Will fail because long long > 4 bytes

    return 0;
}
```

💥 Output → compile-time failure
Because `long long int` is **integral but not TinyType**.

---

## 📌 Summary Table

| Syntax                | Meaning                        |    |                               |
| --------------------- | ------------------------------ | -- | ----------------------------- |
| `requires A && B`     | Must satisfy **both** concepts |    |                               |
| `requires A           |                                | B` | Must satisfy **at least one** |
| Inline requires block | Works but reduces readability  |    |                               |

---

## ✔ Pros

* Stronger type safety for templates
* Cleaner constraint error messages
* Allows API contracts at compile-time
* Reduces misuse of templates

---

## ❗ Cons

* Nested `requires` looks complex for beginners
* Inline concept definitions hurt readability
* Code becomes strict if over-constrained

---

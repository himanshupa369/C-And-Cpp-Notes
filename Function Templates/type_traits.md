
---

# 📌 **Type Traits in C++ (Notes)**

### 🔷 Introduced in: **C++11**, `*_v` helper variable templates added in **C++17**

### 🔷 Header Required:

```cpp
#include <type_traits>
```

---

## 🔥 What are Type Traits?

**Type Traits** are compile-time utilities used to **query information about a type**.
They allow the compiler to **check, detect, and enforce type constraints** when using templates.

### They answer questions like:

| Type Trait                  | Meaning                                |
| --------------------------- | -------------------------------------- |
| `std::is_integral<T>`       | Is `T` an integer type?                |
| `std::is_floating_point<T>` | Is `T` a floating type (float/double)? |
| `std::is_array<T>`          | Is `T` an array type?                  |
| `std::is_enum<T>`           | Is `T` an enum?                        |
| `std::is_reference<T>`      | Is `T` a reference?                    |

---

## Two Ways to Access Result

### 1️⃣ Traditional form (C++11):

```cpp
std::is_integral<int>::value   // returns bool at compile-time
```

### 2️⃣ Short `_v` alias (C++17 preferred):

```cpp
std::is_integral_v<int>        // cleaner & recommended
```

---

## Usage Example

```cpp
std::cout << std::boolalpha;
std::cout << std::is_integral<int>::value << '\n';       // true
std::cout << std::is_floating_point<int>::value << '\n'; // false

// Using modern syntax (C++17+)
std::cout << std::is_integral_v<int> << '\n';            // true
std::cout << std::is_floating_point_v<int> << '\n';      // false
```

---

# 🚦 Enforcing Template Rules Using `static_assert + type_traits`

### `static_assert()` performs compile-time validation.

If the condition is **false**, **compilation stops** with a custom error message.

---

### Example: Function Only Accepts Integral Types

```cpp
#include <iostream>
#include <type_traits>

template <typename T>
void print_number(T n) {
    static_assert(std::is_integral_v<T>, 
                  "print_number() can only be called with integral types");
    std::cout << "number : " << n << std::endl;
}
```

```cpp
int main() {
    print_number(10);   // ✔ OK
    print_number(5.5);  // ❌ Compile-time ERROR
}
```

---

# 🔥 Templated Lambda + Type Traits Support (C++20)

C++20 allows naming template parameters inside a lambda.

```cpp
auto func = []<typename T>(T a, T b){
    static_assert(std::is_integral_v<T>,
                  "func can only be called with integral types");
    return a + b;
};
```

### Test:

```cpp
func(5, 3);    // ✔ OK
func(5.5, 2.2); // ❌ Compile-time ERROR
```

---

# Why Type Traits Matter?

✔ Enable **safe**, **restricted**, and **predictable** templates
✔ Prevent accidental wrong-type usage
✔ Make libraries more robust and error-proof
✔ Compile-time checking → Zero runtime cost

---

# Summary Table

| Feature                  | Purpose                          | Benefit                     |
| ------------------------ | -------------------------------- | --------------------------- |
| `std::type_traits`       | Query type features              | Compile-time reflection     |
| `.value`                 | Traditional boolean result       | (C++11) More verbose        |
| `_v` form                | Cleaner result access            | (C++17) Modern + preferred  |
| `static_assert()`        | Compile-time rule enforcement    | Stops invalid template use  |
| Templated Lambda (C++20) | Lambda with named type parameter | Allows constraints & traits |

---

# 📄 Final Code Used in Lecture (Clean Version)

```cpp
#include <iostream>
#include <type_traits>

template <typename T>
void print_number(T n){
    static_assert(std::is_integral_v<T>,
                  "print_number() can only be called with integral types");
    std::cout << "number : " << n << std::endl;
}

int main(){

    auto func = []<typename T>(T a, T b){
        static_assert(std::is_integral_v<T>,
                      "func can only be called with integral types");
        return a + b;
    };

    int x = 7, y = 6;
    func(x,y);      // OK

    double a=7,b=6;
    func(a,b);      // ❌ Compilation error

    return 0;
}
```

---
 You can also prepare:

🔸 Comparison with C++20 Concepts (`requires std::integral<T>`)
🔸 Real-world use cases (smart pointers, containers, numerical libs)
🔸 A markdown page ready to put directly into your GitHub docs



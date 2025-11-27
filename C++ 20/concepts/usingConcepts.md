
---

# 📘 **Using Concepts in C++20**

### **📌 Header**

```cpp
#include <concepts>
```

### **Introduced in**

**C++20**

---

## 🔷 What Are Concepts?

✔ *Concepts are compile-time constraints applied to template parameters.*

They allow you to specify what kind of types a template can accept.

Example:

* only integers (using `std::integral`)
* only floating points (`std::floating_point`)
* custom rules (user-defined concepts)

If someone calls your template with a type that **does not satisfy the concept**, the compiler will throw an **error before instantiation**.

---

## 🔥 Why Use Concepts?

| Before C++20 (templates only)               | With Concepts                                      |
| ------------------------------------------- | -------------------------------------------------- |
| Wrong types produce long unreadable errors  | Clear and meaningful compile-time errors           |
| Needed static_assert + type traits manually | Requirement directly visible in function signature |
| Less controlled type usage                  | Strong constraints → safer templates               |

Concepts simplify template error messages and make code self-documenting.

---

## 🧠 Types of Concepts

1. **Standard (built-in)** — provided by STL (`<concepts>`)
2. **User-defined concepts** — we can create custom rules (covered later)

In this lecture we use **standard library concepts**, mainly:

| Concept                                                 | Meaning                                    |
| ------------------------------------------------------- | ------------------------------------------ |
| `std::integral<T>`                                      | Only integer (char, short, int, long etc.) |
| `std::floating_point<T>`                                | Only float/double                          |
| `std::signed_integral<T>` / `std::unsigned_integral<T>` | Specific integer category                  |

---

## 🔑 Using Concepts to Restrict Template Functions

We want a template function `add()` that works **only with integral types**.

Below are **4 syntaxes** that achieve the same thing.

---

### 🟩 **Syntax 1 – requires clause after template declaration**

```cpp
template <typename T>
requires std::integral<T>
T add(T a, T b){
    return a + b;
}
```

---

### 🟩 **Syntax 2 – concept directly in template parameter**

```cpp
template <std::integral T>
T add(T a, T b){
    return a + b;
}
```

---

### 🟩 **Syntax 3 – using concept with auto (deduced template)**

```cpp
auto add(std::integral auto a, std::integral auto b){
    return a + b;
}
```

---

### 🟩 **Syntax 4 – requires clause after function signature**

```cpp
template <typename T>
T add(T a, T b) requires std::integral<T> {
    return a + b;
}
```

All four versions are valid — use whichever reads best for your use-case.

---

## 🧪 Example Program from Lecture

```cpp
#include <iostream>
#include <concepts>

//Syntax4 (active)
template <typename T>
T add( T a, T b) requires std::integral<T>{
    return a + b;
}

int main(){
	char a_0{10};
	char a_1{20};
	std::cout << "result_a : " << static_cast<int>(add(a_0,a_1)) << std::endl;

	int b_0{11};
	int b_1{5};
	std::cout << "result_b : " << add(b_0,b_1) << std::endl;

	double c_0 {11.1};
	double c_1 {1.9};
	std::cout << "result_c : " << add(c_0,c_1) << std::endl; // ❌ constraint violated
}
```

### Output:

```
result_a : 30
result_b : 16
error: use of function ‘add’ with unsatisfied constraints
```

Double fails because `std::integral<double>` is **false**.

---

## 💡 Key Takeaways

| Feature                   | Benefit                                 |
| ------------------------- | --------------------------------------- |
| Compile-time validation   | Prevents invalid template instantiation |
| Cleaner errors            | Says directly which concept failed      |
| Flexible syntax           | Four ways to apply constraints          |
| Safer generic programming | Function accepts only intended types    |

---


---

## ✅ 1. **What is a template in C++?**

**Answer:**
A **template** allows writing **generic and reusable code**. It lets you define functions or classes that work with any data type.

---

## ✅ 2. **Types of Templates in C++**

* **Function Templates**
* **Class Templates**
* **Variable Templates** (C++14)
* **Alias Templates** (C++11)
* **Template Template Parameters**

---

## ✅ 3. **Function Template Example**

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add<int>(2, 3);      // Outputs: 5
    std::cout << add<double>(2.1, 3.5); // Outputs: 5.6
}
```

---

## ✅ 4. **Class Template Example**

```cpp
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    void show() { std::cout << value; }
};
```

---

## ✅ 5. **What is Template Specialization?**

Used to customize behavior for a specific data type:

```cpp
template <typename T>
class Printer {
public:
    void print() { std::cout << "Generic"; }
};

template <>
class Printer<int> {
public:
    void print() { std::cout << "Integer specialization"; }
};
```

---

## ✅ 6. **What is Template Instantiation?**

When a template is used with a specific type, the compiler **generates code** (instantiates) for that type.

```cpp
add<int>(10, 20);  // Compiler generates an int version of add()
```

---

## ✅ 7. **What are Non-type Template Parameters?**

```cpp
template <typename T, int size>
class Array {
    T arr[size];
};
```

Here, `size` is a **non-type template parameter**.

---

## ✅ 8. **What are Variadic Templates (C++11)?**

Used to accept **multiple template arguments**.

```cpp
template <typename T, typename... Args>
void printAll(T first, Args... rest) {
    std::cout << first << "\n";
    if constexpr (sizeof...(rest) > 0)
        printAll(rest...);
}
```

---

## ✅ 9. **What is SFINAE in Templates?**

**SFINAE**: *Substitution Failure Is Not An Error*
Used in **template metaprogramming** to enable/disable functions based on conditions.

---

## ✅ 10. **Can templates be overloaded or specialized?**

* ✅ **Overloaded**: Yes, you can provide a regular function and a template with different signatures.
* ✅ **Specialized**: Yes, via full or partial specialization.

---

## ✅ 11. **What are Constraints and Concepts (C++20)?**

Concepts define **requirements** for template parameters.

```cpp
template<typename T>
requires std::integral<T>
T square(T x) {
    return x * x;
}
```

---

## ✅ 12. **Interview Trick Question:**

**Q:** Can you create a vector of a class template?
**A:** Yes, but the template must be instantiated with a concrete type.

```cpp
std::vector<Box<int>> v;  // Okay
```

---

## 🧠 Summary Table

| Feature                        | Description                        |
| ------------------------------ | ---------------------------------- |
| `template<typename T>`         | Generic type template              |
| Specialization                 | Custom logic for specific types    |
| Non-type parameter             | Template accepts int, char, etc.   |
| Variadic templates             | Multiple types accepted            |
| SFINAE                         | Compile-time substitution checking |
| Concepts & Constraints (C++20) | Type-safe template filtering       |

---


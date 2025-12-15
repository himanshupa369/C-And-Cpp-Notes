
---

# Notes: Built-in Namespaces in C++

## 1. What Built-in Namespaces Are

* Built-in namespaces are namespaces **provided by the C++ Standard Library**
* They group standard classes, functions, objects, and utilities
* The most commonly used built-in namespace is **`std`**

---

## 2. `std` Namespace

* `std` contains almost everything from the C++ Standard Library
* Examples include:

  * Input/output streams
  * Containers
  * Strings
  * Algorithms
  * Utilities

Commonly used members:

```cpp
std::cout
std::endl
std::string
```

---

## 3. Why `std::` Is Required

* The compiler does **not automatically search inside `std`**
* Without `std::`, names like `cout`, `endl`, and `string` are **undefined**

Example (invalid):

```cpp
cout << "Hello";
```

Compiler error:

```
'cout' was not declared in this scope
```

Correct usage:

```cpp
std::cout << "Hello" << std::endl;
```

---

## 4. `std::cout` and `std::endl`

* `cout` is an object used for console output
* `endl` inserts a newline and flushes the output buffer
* Both live inside the `std` namespace

```cpp
std::cout << "Hello World" << std::endl;
```

---

## 5. `std::string`

* `string` is a class for handling text
* It belongs to the `std` namespace

Example:

```cpp
std::string message = "Hello World";
std::cout << message << std::endl;
```

Without `std::`, the compiler will not recognize `string`.

---

## 6. Built-in Namespaces vs User-Defined Namespaces

| Aspect      | Built-in Namespace         | User-Defined Namespace |
| ----------- | -------------------------- | ---------------------- |
| Provided by | C++ Standard Library       | Programmer             |
| Example     | `std`                      | `My_Thing`, `Geom`     |
| Purpose     | Organize standard features | Avoid name conflicts   |
| Access      | `std::name`                | `namespace::name`      |

Syntax is **exactly the same**.

---

## 7. C++ Standard Library Structure

* The standard library is large and modular
* Contains:

  * Containers (`vector`, `map`)
  * Algorithms (`sort`, `find`)
  * Utilities (`stoi`, `to_string`)
  * Streams (`iostream`)
  * Math, memory, threading, coroutines (modern C++)

All of these are under:

```cpp
std::
```

---

## 8. Example: String to Number Utilities

Functions like:

```cpp
std::stoi
std::stod
```

* Convert strings to numeric types
* Also part of the `std` namespace

---

## 9. Key Observations

* We have been using namespaces since day one (`std::cout`)
* `std` behaves exactly like any custom namespace
* Missing `std::` leads to compile-time errors
* Knowing this helps understand:

  * Compiler errors
  * Name lookup rules
  * Clean code practices

---

## 10. Important Takeaways

* Built-in namespaces prevent name collisions in large libraries
* `std` must be explicitly used unless imported
* Namespace syntax is consistent across:

  * Custom namespaces
  * Built-in namespaces
* Understanding this is critical for:

  * Debugging
  * Interviews
  * Writing professional C++ code

---

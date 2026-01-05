
---

# Resource Management Rules in C++

Modern C++ defines **three important design rules** to manage resources safely and efficiently:

* **Rule of Three**
* **Rule of Five**
* **Rule of Zero**

These rules guide how and when to implement **special member functions**.

---

## 1. Rule of Three (Pre-C++11 – Resource Ownership)

### Definition

If a class **manages a resource** (dynamic memory, file handle, mutex, etc.) and **defines any one** of the following, it **must define all three**:

1. **Destructor**
2. **Copy Constructor**
3. **Copy Assignment Operator**

---

### Why the Rule of Three Exists

Before C++11, the compiler-generated versions perform **shallow copies**, which leads to:

* Memory leaks
* Double deletion
* Dangling pointers
* Shared ownership bugs

---

### Special Member Functions Involved

```cpp
~ClassName();                          // Destructor
ClassName(const ClassName&);           // Copy constructor
ClassName& operator=(const ClassName&);// Copy assignment
```

---

### Example

```cpp
class Buffer {
    int* data;
public:
    Buffer(int size) : data(new int[size]) {}

    ~Buffer() {
        delete[] data;
    }

    Buffer(const Buffer& other) {
        data = new int[*other.data];
    }

    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            data = new int[*other.data];
        }
        return *this;
    }
};
```

---

### Why It Is Important

* Prevents memory leaks
* Ensures deep copy semantics
* Avoids double deletion
* Ensures predictable object behavior

---

### When to Use Rule of Three

* When managing **raw resources**
* When using `new` / `delete`
* In **legacy or pre-C++11 code**

---

## 2. Rule of Five (C++11 and Later – Ownership + Performance)

### Definition

The **Rule of Five** extends the Rule of Three by adding **move semantics**, introduced in **C++11**.

If a class **owns a resource**, you should define **all five**:

1. Destructor
2. Copy constructor
3. Copy assignment operator
4. **Move constructor**
5. **Move assignment operator**

---

### Special Member Functions Involved

```cpp
~ClassName();
ClassName(const ClassName&);
ClassName& operator=(const ClassName&);
ClassName(ClassName&&) noexcept;
ClassName& operator=(ClassName&&) noexcept;
```

---

### Why Rule of Five Is Needed

* Avoids expensive deep copies
* Enables efficient **move semantics**
* Improves performance for large objects
* Ensures correct ownership transfer

---

### Example

```cpp
class Buffer {
    int* data;
public:
    Buffer(int size) : data(new int[size]) {}

    ~Buffer() { delete[] data; }

    Buffer(const Buffer& other) {
        data = new int[*other.data];
    }

    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            data = new int[*other.data];
        }
        return *this;
    }

    Buffer(Buffer&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};
```

---

### Why It Is Important

* Prevents memory leaks and dangling pointers
* Enables fast transfers instead of copies
* Improves runtime performance
* Ensures safe ownership semantics

---

### When to Use Rule of Five

* Classes managing **dynamic memory**
* File handles, sockets, mutexes
* Performance-critical code
* Large objects passed by value

---

## 3. Rule of Zero (Modern C++ – No Ownership)

### Definition

If a class **does not directly manage resources**, **do not write any special member functions**.

Let the compiler generate everything.

---

### Key Idea

> **Delegate resource management to RAII types**
> (`std::vector`, `std::string`, `std::unique_ptr`, etc.)

---

### Example

```cpp
class Person {
    std::string name;
    std::vector<int> scores;
};
```

✔ No destructor
✔ No copy/move constructors
✔ No assignment operators

The compiler generates everything correctly.

---

### Why Rule of Zero Is Preferred

* Eliminates boilerplate code
* Prevents memory bugs
* Increases exception safety
* Leverages well-tested STL components
* Encourages modern C++ design

---

### Important Notes

* Writing **any one** special member function may:

  * Disable compiler-generated move operations
* RAII types already follow Rule of Five internally

---

### When to Use Rule of Zero

1. When using **smart pointers**
2. When using **STL containers**
3. When no raw resource ownership exists
4. In modern, maintainable C++ codebases

---

## Comparison Summary

| Rule          | Resource Ownership | C++ Version | Special Functions                       |
| ------------- | ------------------ | ----------- | --------------------------------------- |
| Rule of Three | Yes                | Pre-C++11   | Destructor, Copy ctor, Copy assign      |
| Rule of Five  | Yes + Performance  | C++11+      | Rule of Three + Move ctor + Move assign |
| Rule of Zero  | No                 | Modern C++  | None                                    |

---

## One-Line Definitions (Interview Friendly)

* **Rule of Three**:
  *If a class owns a resource, define destructor, copy constructor, and copy assignment.*

* **Rule of Five**:
  *Extend Rule of Three by adding move constructor and move assignment for efficiency.*

* **Rule of Zero**:
  *Avoid defining special member functions by relying on RAII and STL.*

---

## Key Takeaway

> **Prefer Rule of Zero → Use Rule of Five only when necessary → Rule of Three is legacy**

---

```cpp

/*

Rule of 3 :-(Resource allocation)

   * If a class manages a resource (e.g., dynamic memory, file handle) and defines any of the following, it should define all three:
   1)* Destructor
   2)* Copy Constructor
   3)* Copy Assignment Operator
   * This rule ensures proper resource management for classes with value semantics, particularly before C++11.
   * The compiler-generated default versions perform shallow copies, which can lead to:
    * Memory leaks
    * Double deletion
    * Incorrect resource sharing
   Why is the Rule of Three Important?
   1)Prevents memory leaks and dangling pointers.
   2)Ensures proper copying behavior for dynamically allocated resources.
   3)Avoids double deletion issues in destructors.

Rule Of 5 :- (ownership)
   *The Rule of Five extends the Rule of Three in C++ by adding move semantics introduced in C++11.
   It ensures efficient resource management and prevents unnecessary deep copies.
   * Consequently, you should implement the rule of 5 for such classes
   * If a class has ownership semantics, then you must provide a user-defined
     * Destructor
     * Copy constructor
     * Copy assignment operator
     * Move constructor
     * Move assignment operator
   * This is to ensure proper handling of the underlying resource
   * Why is the Rule of Five Important?
     *Prevents memory leaks and dangling pointers.
     *Ensures efficient resource management.
     *Enables move semantics for better performance.
     *Avoids unnecessary deep copies, improving speed.
   *When to Use the Rule of Five?
     *When a class manages dynamic memory.
     *When implementing resource-managing classes (e.g., file handles, sockets, smart pointers).
     *When dealing with large objects where moving is preferable to copying.

Rule of 0 :-(Renting)
   *The Rule of Zero is a modern C++ design principle that states that user-defined special member functions (destructor, copy/move constructors, and copy/move assignment operators) should be avoided
   by leveraging RAII (Resource Acquisition Is Initialization) and standard library containers like std::unique_ptr and std::shared_ptr for resource management.
   * If a class does not have ownership semantics, then do not provide any user defined function from the rule of 5
   * This is called the "rule of 0"
   * This way the compiler will automatically synthesize the necessary functions
   * Providing user-defined implementation of some functions will prevent the compiler from synthesizing others
   * Basically is totally depends on RAII concept.
   *Why Use the Rule of Zero?
      *Reduces boilerplate code and manual resource management.
      *Avoids memory leaks and dangling pointers.
      *Increases exception safety.
      *Takes advantage of modern C++ features (smart pointers, containers, etc.).
   *When to Use the Rule of Zero?
      1)When using RAII (Resource Acquisition Is Initialization).
      2)When working with standard library containers (e.g., std::vector, std::string, std::shared_ptr).
      3)When writing modern, maintainable C++ code that avoids manual memory management.



*/
```

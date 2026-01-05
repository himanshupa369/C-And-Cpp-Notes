
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

---

## Extra Concepts

* Rule of Zero
* Rule of One
* Rule of Five

---

# Rule of Three, Rule of Five, and Rule of Zero in C++

These rules describe **how a class should manage resources** such as dynamic memory, file handles, mutexes, sockets, etc., and guide you in deciding **which special member functions to define**.

---

## 1) Rule of Three (Pre–C++11, Resource Ownership)

### Introduction

The **Rule of Three** states that **if a class manages a resource and defines any one of the following special member functions, it should explicitly define all three**.
This rule is critical for classes that use **manual resource management** (e.g., `new/delete`).

---

### The Three Special Member Functions

1. **Destructor**

   * `~ClassName()`
   * Releases the owned resource.

2. **Copy Constructor**

   * `ClassName(const ClassName& other)`
   * Creates a **deep copy** of the resource.

3. **Copy Assignment Operator**

   * `ClassName& operator=(const ClassName& other)`
   * Replaces the current resource with a deep copy of another object’s resource.

---

### Why the Rule of Three Is Important

* Prevents **memory leaks**
* Prevents **double deletion**
* Avoids **dangling pointers**
* Ensures correct **copy semantics**
* Necessary when the compiler-generated versions would perform **shallow copies**

---

### When to Use the Rule of Three

* When a class **owns a raw resource**
* When using `new` / `delete`
* In **legacy or pre–C++11 codebases**

---

## 2) Rule of Five (C++11+, Ownership + Performance)

### Introduction

The **Rule of Five** extends the Rule of Three by adding **move semantics**, introduced in **C++11**.
It ensures **efficient ownership transfer** and avoids unnecessary deep copies.

---

### The Five Special Member Functions

1. **Destructor**

   * `~ClassName()`

2. **Copy Constructor**

   * `ClassName(const ClassName& other)`

3. **Copy Assignment Operator**

   * `ClassName& operator=(const ClassName& other)`

4. **Move Constructor**

   * `ClassName(ClassName&& other) noexcept`
   * Transfers ownership from a temporary object.

5. **Move Assignment Operator**

   * `ClassName& operator=(ClassName&& other) noexcept`
   * Transfers ownership during assignment.

---

### Why the Rule of Five Is Important

* Prevents memory leaks and dangling pointers
* Enables **move semantics**
* Improves performance by avoiding deep copies
* Supports efficient handling of **temporary objects**
* Essential for modern C++ resource-managing classes

---

### When to Use the Rule of Five

* When a class **owns resources**
* When implementing **custom resource managers**
* When performance matters and **moving is cheaper than copying**
* Examples:

  * File handles
  * Sockets
  * Custom smart pointers
  * Large dynamically allocated buffers

---

## 3) Rule of Zero (Modern C++, Renting Resources)

### Introduction

The **Rule of Zero** states that **you should not define any special member functions yourself** if your class does **not directly own resources**.
Instead, rely on **RAII-enabled types** from the standard library.

---

### Core Idea

> *“If you don’t manage resources manually, let the compiler do everything for you.”*

---

### How Rule of Zero Works

* Use **RAII types** such as:

  * `std::vector`
  * `std::string`
  * `std::unique_ptr`
  * `std::shared_ptr`
* Let these types manage destruction, copying, and moving.
* The compiler will automatically generate:

  * Destructor
  * Copy constructor
  * Copy assignment operator
  * Move constructor
  * Move assignment operator

---

### Why Use the Rule of Zero

* Eliminates boilerplate code
* Avoids memory leaks and dangling pointers
* Improves exception safety
* Produces cleaner, safer, and more maintainable code
* Encourages modern C++ best practices

---

### When to Use the Rule of Zero

* When using **standard library containers**
* When using **smart pointers**
* When following **RAII**
* When writing **modern, production-quality C++**

---

## Rule Comparison Summary

| Rule          | Resource Ownership      | Special Functions                  | Typical Usage            |
| ------------- | ----------------------- | ---------------------------------- | ------------------------ |
| Rule of Three | Manual (raw pointers)   | Destructor, Copy Ctor, Copy Assign | Legacy / pre-C++11       |
| Rule of Five  | Manual + Move Semantics | All five                           | Modern ownership classes |
| Rule of Zero  | No manual ownership     | None                               | Modern, clean C++        |

---

## Interview Key Takeaways

* **Rule of Three**: For manual resource management (copy only)
* **Rule of Five**: For ownership + move semantics
* **Rule of Zero**: Prefer this whenever possible
* Modern C++ strongly favors **Rule of Zero**
* Smart pointers reduce the need for custom destructors

---

---

# Rule of One in C++ (Non-Copyable / Exclusive Ownership)

## What Is the Rule of One?

The **Rule of One** states:

> If a class has **exclusive ownership of a resource**, you should define **exactly one special member function** to control that ownership, and **explicitly disable copying**.

In practice, this usually means:

* The class **owns a resource**
* The resource **must not be copied**
* Only **one object** can manage that resource at a time

---

## Typical Characteristics

* Copying is **not allowed**
* Moving may or may not be allowed
* Used for **unique, non-shareable resources**

Examples of such resources:

* `std::mutex`
* File descriptors
* Sockets
* Hardware handles
* `std::unique_ptr`

---

## Why the Rule of One Exists

Copying certain resources:

* Makes **no logical sense**
* Can cause **undefined behavior**
* Can break **system invariants**

Example:

* Copying a mutex → two objects think they own the same lock
* Copying a file descriptor → double close
* Copying a socket → protocol corruption

---

## Example 1: Non-Copyable, Non-Movable Class

### Scenario

A class managing a **hardware device handle** that must never be duplicated.

### Implementation

```cpp
class DeviceHandle {
public:
    DeviceHandle(int handle) : handle_(handle) {}

    ~DeviceHandle() {
        closeDevice(handle_);
    }

    // Rule of One: disable copying
    DeviceHandle(const DeviceHandle&) = delete;
    DeviceHandle& operator=(const DeviceHandle&) = delete;

private:
    int handle_;

    void closeDevice(int h) {
        // close hardware handle
    }
};
```

### Explanation

* Destructor is required to release the resource
* Copy constructor and copy assignment are **deleted**
* Only **one instance** can exist per handle

This class follows the **Rule of One** because:

* Ownership is exclusive
* Copying is forbidden
* Only one special member decision matters: **disallow copy**

---

## Example 2: Rule of One + Move Semantics (Common in Modern C++)

This is the **most practical form** of Rule of One.

### Scenario

A class managing a file descriptor that:

* Cannot be copied
* Can be **moved**

### Implementation

```cpp
class File {
public:
    explicit File(int fd) : fd_(fd) {}

    ~File() {
        if (fd_ != -1)
            close(fd_);
    }

    // Disable copying
    File(const File&) = delete;
    File& operator=(const File&) = delete;

    // Allow moving
    File(File&& other) noexcept : fd_(other.fd_) {
        other.fd_ = -1;
    }

    File& operator=(File&& other) noexcept {
        if (this != &other) {
            close(fd_);
            fd_ = other.fd_;
            other.fd_ = -1;
        }
        return *this;
    }

private:
    int fd_;
};
```

### Explanation

* Copying is forbidden
* Ownership can be **transferred**, not duplicated
* Similar to how `std::unique_ptr` works
* Still conceptually **Rule of One**: exclusive ownership

---

## Example 3: Standard Library Example — `std::unique_ptr`

```cpp
std::unique_ptr<int> p1 = std::make_unique<int>(10);

// std::unique_ptr<int> p2 = p1;   ❌ ERROR (copy not allowed)

std::unique_ptr<int> p2 = std::move(p1);  // ✅ ownership transferred
```

### Why `std::unique_ptr` Follows Rule of One

* Exclusive ownership
* Copy operations deleted
* Move operations allowed
* Exactly one owner at any time

---

## Rule of One vs Rule of Five vs Rule of Zero

| Rule         | Ownership Model  | Copy | Move     | Typical Example              |
| ------------ | ---------------- | ---- | -------- | ---------------------------- |
| Rule of Zero | No ownership     | Yes  | Yes      | `std::vector`, `std::string` |
| Rule of One  | Exclusive        | No   | Optional | `std::mutex`, `unique_ptr`   |
| Rule of Five | Manual ownership | Yes  | Yes      | Custom resource manager      |

---

## Interview-Ready Summary

* **Rule of One** applies to **non-copyable classes**
* Used when **only one object may own a resource**
* Copy operations are explicitly **deleted**
* Move operations may be enabled
* Common in **systems programming**, **concurrency**, and **low-level resource management**

> If copying breaks correctness, apply the **Rule of One**.

---



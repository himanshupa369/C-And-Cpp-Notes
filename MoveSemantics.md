

---

## ✅ C++ Move Constructor & Move Assignment – Interview Questions with Answers

---

### 🔹 1. **What is a move constructor in C++?**

**Answer:**
A **move constructor** transfers ownership of resources from a **temporary (rvalue)** object to a new object to avoid deep copy overhead.

```cpp
ClassName(ClassName&& other);  // move constructor
```

---

### 🔹 2. **What is the syntax of a move assignment operator?**

```cpp
ClassName& operator=(ClassName&& other); // move assignment
```

---

### 🔹 3. **Why do we need move semantics?**

**Answer:**
To:

* **Avoid deep copies**
* **Improve performance**
* **Enable efficient return-by-value**
* Handle **temporary (rvalue) objects** efficiently

---

### 🔹 4. **What is the difference between copy and move constructors?**

| Feature           | Copy Constructor                 | Move Constructor                  |
| ----------------- | -------------------------------- | --------------------------------- |
| Signature         | `ClassName(const ClassName&)`    | `ClassName(ClassName&&)`          |
| Used for          | Copying lvalue                   | Moving from rvalue                |
| Resource handling | Deep copy                        | Transfer ownership (shallow move) |
| Cost              | Higher (may allocate new memory) | Lower (no allocations if moved)   |

---

### 🔹 5. **Write a move constructor example.**

```cpp
class MyClass {
    int* data;
public:
    MyClass(int val) { data = new int(val); }

    // Move constructor
    MyClass(MyClass&& other) noexcept {
        data = other.data;
        other.data = nullptr;  // Release ownership
    }

    ~MyClass() { delete data; }
};
```

---

### 🔹 6. **What happens if you don’t define a move constructor?**

**Answer:**

* The compiler generates a default one **only if**:

  * No custom copy constructor/assignment/destructor is defined
* Otherwise, move operations fall back to **copy** (which may be inefficient or unsafe)

---

### 🔹 7. **What is Rule of 5 in C++11?**

**Answer:**

If your class needs any one of these, you usually need all five:

1. Copy constructor
2. Copy assignment
3. Move constructor
4. Move assignment
5. Destructor

---

### 🔹 8. **How does `std::move` work with move constructor?**

**Answer:**

`std::move` **casts an lvalue to an rvalue**, enabling move constructor/assignment.

```cpp
MyClass a(5);
MyClass b = std::move(a);  // Move constructor called
```

---

### 🔹 9. **How to implement a move assignment operator?**

```cpp
MyClass& operator=(MyClass&& other) noexcept {
    if (this != &other) {
        delete data;  // clean up
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}
```

---

### 🔹 10. **What is the danger of not nullifying the source in move?**

**Answer:**

* **Double deletion** when both objects try to free the same resource.
* **Dangling pointer** errors.

---

## 🧠 Bonus Tips:

| Mistake                                | Fix                                |
| -------------------------------------- | ---------------------------------- |
| Not checking for self-assignment       | `if (this != &other)`              |
| Not setting `other.data = nullptr`     | Prevents double delete             |
| Using `const ClassName&&` in move ctor | ❌ Invalid – can't move from const  |
| Forgetting `noexcept`                  | May disable move in STL containers |

---

## ✅ Interview Traps:

* What if you pass an rvalue by reference instead of rvalue-reference?
* Can you move a `const` object? (❌ No – move constructor requires non-const)
* What is the return type of move assignment? (`ClassName&`)
* Why `noexcept` is important in move semantics? (Ensures safety in STL containers)

---

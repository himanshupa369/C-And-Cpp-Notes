
---

## ✅ Interview Questions on `std::shared_ptr` in C++

---

### 🔹 1. **What is `std::shared_ptr`?**

**Answer:**
`std::shared_ptr` is a smart pointer provided by C++11 that **allows multiple shared owners** of a dynamically allocated resource.
It uses **reference counting** to keep track of how many `shared_ptr` instances own the same object.

---

### 🔹 2. **How does `shared_ptr` work internally?**

**Answer:**

* Maintains a **reference count**.
* When a `shared_ptr` is copied, the count increases.
* When a `shared_ptr` is destroyed, the count decreases.
* When the count reaches zero, the object is **deleted**.

---

### 🔹 3. **How do you create a `shared_ptr`?**

```cpp
#include <memory>
auto p1 = std::make_shared<int>(10); // preferred
std::shared_ptr<int> p2(new int(20)); // also valid
```

---

### 🔹 4. **What is `make_shared` and why is it preferred?**

**Answer:**
`std::make_shared<T>(...)` allocates:

* The object **and**
* The control block (reference counter)
  **in one memory block**, making it more **efficient and exception-safe**.

---

### 🔹 5. **Can a `shared_ptr` be assigned or copied?**

**Answer:**
✅ Yes. That’s the core idea — **shared ownership**.

```cpp
std::shared_ptr<int> a = std::make_shared<int>(5);
std::shared_ptr<int> b = a; // Reference count increases
```

---

### 🔹 6. **How do you check the current reference count?**

```cpp
std::shared_ptr<int> p = std::make_shared<int>(100);
std::cout << p.use_count();  // prints 1
```

---

### 🔹 7. **What happens when the last `shared_ptr` is destroyed?**

**Answer:**
When the **last shared\_ptr** owning a resource is destroyed or reset, the resource is **automatically deleted**.

---

### 🔹 8. **What is `weak_ptr` and how is it related to `shared_ptr`?**

**Answer:**
`std::weak_ptr` is a **non-owning** reference to a shared object.
Used to **break cyclic references** that `shared_ptr` alone can't handle.

```cpp
std::shared_ptr<A> a;
std::weak_ptr<A> w = a;
```

---

### 🔹 9. **Can you store `shared_ptr` in STL containers?**

**Answer:**
✅ Yes. `shared_ptr` is **copyable and assignable**, so it works perfectly in containers:

```cpp
std::vector<std::shared_ptr<int>> vec;
vec.push_back(std::make_shared<int>(10));
```

---

### 🔹 10. **What are the drawbacks of `shared_ptr`?**

* **Overhead** due to reference counting
* **Cyclic references** can lead to memory leaks
* Slower than `unique_ptr`

---

## ⚠️ Common Mistakes

| Mistake                                      | Fix                                    |
| -------------------------------------------- | -------------------------------------- |
| Using `shared_ptr` when ownership is unique  | Use `unique_ptr` instead               |
| Creating cycles (`A → B → A`)                | Use `weak_ptr` to break cycles         |
| Mixing raw pointers and shared\_ptr          | Avoid — manage all with smart pointers |
| Creating multiple `shared_ptr<T>` from `new` | Use `make_shared<T>()`                 |

---

### 🔹 11. **Can two `shared_ptr`s manage the same raw pointer?**

**Answer:**
❌ No! Doing this causes **double delete**:

```cpp
int* raw = new int(5);
std::shared_ptr<int> a(raw);
std::shared_ptr<int> b(raw); // ❌ DANGEROUS
```

Always use one `shared_ptr` and copy it.

---

### 🔹 12. **When should you prefer `shared_ptr` over `unique_ptr`?**

**Answer:**
Use `shared_ptr` when:

* You need **shared ownership**.
* Object is **used in multiple places**.
* You cannot enforce single ownership.

---

## 💡 Example: Cyclic Reference Problem

```cpp
struct B;
struct A {
    std::shared_ptr<B> bptr;
};
struct B {
    std::shared_ptr<A> aptr; // ❌ cycle
};

// Use weak_ptr to fix:
struct B_fixed {
    std::weak_ptr<A> aptr;
};
```

---

## 🧠 Advanced Concepts

### 🔹 13. **What is the size of a `shared_ptr`?**

Usually 2 pointers:

* One for the object
* One for the control block (ref count, deleter, etc.)

---

### 🔹 14. **Can you use custom deleters with `shared_ptr`?**

✅ Yes.

```cpp
auto deleter = [](FILE* f) { fclose(f); };
std::shared_ptr<FILE> file(fopen("data.txt", "r"), deleter);
```

---

### 🔹 15. **How is `shared_ptr` implemented internally?**

* Uses **reference-counted control block**
* Internally uses **atomic operations**
* May involve **thread-safe** operations for `use_count()`

---

## ✅ Summary Table

| Feature                | `shared_ptr`                         |
| ---------------------- | ------------------------------------ |
| Copyable               | ✅ Yes                                |
| Moveable               | ✅ Yes                                |
| Reference count access | `use_count()`                        |
| Non-owning companion   | `weak_ptr`                           |
| STL support            | ✅ Yes                                |
| Cyclic leak safe?      | ❌ Use `weak_ptr` to prevent          |
| Performance            | ⚠️ Slightly slower than `unique_ptr` |

---

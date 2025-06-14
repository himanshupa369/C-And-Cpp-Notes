
---

## ✅ `std::weak_ptr` Interview Questions in C++

---

### 🔹 1. **What is `std::weak_ptr`?**

**Answer:**
`std::weak_ptr` is a **non-owning smart pointer** that references a shared resource managed by `std::shared_ptr` **without increasing its reference count**.

It is used to:

* Observe a shared object without taking ownership.
* **Break cyclic dependencies** between shared pointers.

---

### 🔹 2. **How do you create a `weak_ptr`?**

```cpp
#include <memory>
std::shared_ptr<int> sp = std::make_shared<int>(10);
std::weak_ptr<int> wp = sp; // No ownership, no ref count increment
```

---

### 🔹 3. **Does `weak_ptr` increase reference count?**

**Answer:**
❌ No. It does **not** affect the lifetime of the object. It just observes it.

---

### 🔹 4. **How do you access the object from a `weak_ptr`?**

Use `.lock()` to get a `shared_ptr` (if the object still exists):

```cpp
if (auto temp = wp.lock()) {
    std::cout << *temp << std::endl;
} else {
    std::cout << "Object no longer exists.\n";
}
```

---

### 🔹 5. **How does `weak_ptr` help with cyclic references?**

**Answer:**
Cyclic references between `shared_ptr` objects **prevent destruction** due to non-zero reference counts.

Using `weak_ptr` for one of the links **breaks the cycle**.

```cpp
struct B;
struct A {
    std::shared_ptr<B> b;
};
struct B {
    std::weak_ptr<A> a; // weak_ptr breaks the cycle
};
```

---

### 🔹 6. **How can you check if the object has expired?**

Use `.expired()`:

```cpp
if (wp.expired()) {
    std::cout << "Object is gone\n";
}
```

---

### 🔹 7. **What is the difference between `use_count()` in `shared_ptr` and `weak_ptr`?**

**Answer:**

* `shared_ptr.use_count()` → number of shared owners.
* `weak_ptr.use_count()` → same as the shared count of the object it observes.

```cpp
std::shared_ptr<int> sp = std::make_shared<int>(5);
std::weak_ptr<int> wp = sp;

std::cout << sp.use_count(); // 1
std::cout << wp.use_count(); // also 1
```

---

### 🔹 8. **Can you reset or assign a new object to a `weak_ptr`?**

✅ Yes.

```cpp
wp.reset(); // now points to nothing
wp = another_shared_ptr; // reassign
```

---

### 🔹 9. **Is `weak_ptr` thread-safe?**

**Answer:**
Yes, it is **thread-safe** for `.lock()` and `.expired()` operations, but not for shared data access — you must manage that yourself.

---

### 🔹 10. **What happens if the shared object is destroyed?**

The `weak_ptr` becomes **expired**. `.lock()` will return a **null shared\_ptr**.

---

### 🔹 11. **Can `weak_ptr` be used in STL containers?**

✅ Yes. `weak_ptr` is copyable and assignable, so it works with containers.

```cpp
std::vector<std::weak_ptr<int>> cache;
```

---

## 🧪 Practical Example: Break Shared Cycle

```cpp
struct B; // forward declare

struct A {
    std::shared_ptr<B> b_ptr;
};

struct B {
    std::weak_ptr<A> a_ptr; // weak_ptr breaks the cycle
};
```

Without `weak_ptr`, this would cause a **memory leak** due to mutual `shared_ptr` ownership.

---

## 🔁 `shared_ptr` vs `weak_ptr`

| Feature              | `shared_ptr`  | `weak_ptr`              |
| -------------------- | ------------- | ----------------------- |
| Ownership?           | ✅ Yes         | ❌ No                    |
| Increases ref count? | ✅ Yes         | ❌ No                    |
| Access via?          | Direct or `*` | `.lock()` → shared\_ptr |
| Prevents cycles?     | ❌ No          | ✅ Yes                   |
| Lifetime control?    | ✅ Yes         | ❌ No                    |

---

## 🧠 Common Interview Traps

| ❌ Mistake                              | ✅ Correct Way                             |
| -------------------------------------- | ----------------------------------------- |
| Using `shared_ptr` for back-references | Use `weak_ptr` to prevent memory leak     |
| Accessing `weak_ptr` without `.lock()` | Always use `.lock()` before dereferencing |
| Thinking `weak_ptr` keeps object alive | It doesn’t — just observes it             |

---

## 🛠️ Summary

* `weak_ptr` is best used **alongside** `shared_ptr`.
* It helps manage **object lifetimes** safely and break **ownership cycles**.
* It must be **checked or locked** before use.

---


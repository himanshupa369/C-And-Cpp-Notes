
---

## 1. What `unique_ptr` Does (Conceptual)

* Owns **exactly one object**
* **Cannot be copied**
* **Can be moved**
* Automatically deletes the object in destructor (RAII)
* Zero overhead abstraction

---

## 2. Core Design Idea

A `unique_ptr` internally stores:

* A **raw pointer**
* No reference count
* Ownership is transferred **only via move**

---

## 3. Simplified Internal Implementation

### Minimal Educational `UniquePtr`

```cpp
#include <iostream>

template <typename T>
class SimpleUniquePtr
{
private:
    T* ptr;

public:
    // 1. Constructor
    explicit SimpleUniquePtr(T* p = nullptr)
        : ptr(p)
    {
    }

    // 2. Destructor
    ~SimpleUniquePtr()
    {
        delete ptr;
    }

    // 3. Delete copy constructor (no copying)
    SimpleUniquePtr(const SimpleUniquePtr&) = delete;

    // 4. Delete copy assignment (no copying)
    SimpleUniquePtr& operator=(const SimpleUniquePtr&) = delete;

    // 5. Move constructor
    SimpleUniquePtr(SimpleUniquePtr&& other) noexcept
        : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    // 6. Move assignment
    SimpleUniquePtr& operator=(SimpleUniquePtr&& other) noexcept
    {
        if (this != &other)
        {
            delete ptr;          // release current resource
            ptr = other.ptr;     // take ownership
            other.ptr = nullptr;
        }
        return *this;
    }

    // 7. Dereference operator
    T& operator*() const
    {
        return *ptr;
    }

    // 8. Arrow operator
    T* operator->() const
    {
        return ptr;
    }

    // 9. Get raw pointer
    T* get() const
    {
        return ptr;
    }

    // 10. Release ownership (does NOT delete)
    T* release()
    {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // 11. Reset pointer
    void reset(T* p = nullptr)
    {
        if (ptr != p)
        {
            delete ptr;
            ptr = p;
        }
    }
};
```

---

## 4. Example Usage

```cpp
int main()
{
    SimpleUniquePtr<int> p1(new int(42));

    // SimpleUniquePtr<int> p2 = p1;   // ❌ Compile-time error

    SimpleUniquePtr<int> p2 = std::move(p1);  // ownership transfer

    if (p1.get() == nullptr)
        std::cout << "p1 is empty\n";

    std::cout << "p2 value = " << *p2 << "\n";

    return 0;
}
```

### Output

```
p1 is empty
p2 value = 42
```

---

## 5. Why `unique_ptr` Is Better Than `auto_ptr`

| Feature           | auto_ptr          | unique_ptr    |
| ----------------- | ----------------- | ------------- |
| Copy allowed      | Yes (dangerous)   | ❌ No          |
| Move support      | Implicit via copy | Explicit move |
| STL safe          | ❌ No              | ✔ Yes         |
| Ownership clarity | Hidden            | Explicit      |

---

## 6. Key Interview Points

* `unique_ptr` enforces **single ownership**
* Uses **move semantics**
* Zero runtime overhead
* Preferred smart pointer in modern C++
* Use `shared_ptr` **only when sharing is required**

---

## 7. What This Implementation Skips (By Design)

| Feature              | Real `std::unique_ptr` |
| -------------------- | ---------------------- |
| Custom deleter       | Supported              |
| Array specialization | `unique_ptr<T[]>`      |
| `make_unique`        | Safe factory           |
| constexpr support    | Yes                    |

---

## 8. One-Line Industry Rule

> **Default to `unique_ptr`. Move to `shared_ptr` only if ownership must be shared.**

---

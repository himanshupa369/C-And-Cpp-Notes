
---

## 1. What `shared_ptr` Does (Conceptual)

* Manages a dynamically allocated object
* Allows **multiple owners**
* Uses **reference counting**
* Deletes the object **only when the last owner releases it**
* RAII-compliant

---

## 2. Internal Design (Simple & Clear)

A `shared_ptr` internally stores:

1. **Raw pointer** → actual object
2. **Reference counter** → how many `shared_ptr`s own it

---

## 3. Simplified Internal Implementation

### Minimal Educational `SharedPtr`

```cpp
#include <iostream>

template <typename T>
class SimpleSharedPtr
{
private:
    T* ptr;            // managed object
    int* refCount;     // shared reference counter

    void release()
    {
        if (refCount)
        {
            (*refCount)--;

            if (*refCount == 0)
            {
                delete ptr;
                delete refCount;
            }
        }
    }

public:
    // 1. Constructor
    explicit SimpleSharedPtr(T* p = nullptr)
        : ptr(p), refCount(nullptr)
    {
        if (p)
        {
            refCount = new int(1);
        }
    }

    // 2. Copy constructor
    SimpleSharedPtr(const SimpleSharedPtr& other)
        : ptr(other.ptr), refCount(other.refCount)
    {
        if (refCount)
        {
            (*refCount)++;
        }
    }

    // 3. Copy assignment
    SimpleSharedPtr& operator=(const SimpleSharedPtr& other)
    {
        if (this != &other)
        {
            release();   // release current resource

            ptr = other.ptr;
            refCount = other.refCount;

            if (refCount)
            {
                (*refCount)++;
            }
        }
        return *this;
    }

    // 4. Destructor
    ~SimpleSharedPtr()
    {
        release();
    }

    // 5. Dereference
    T& operator*() const
    {
        return *ptr;
    }

    // 6. Arrow operator
    T* operator->() const
    {
        return ptr;
    }

    // 7. Get raw pointer
    T* get() const
    {
        return ptr;
    }

    // 8. Use count
    int use_count() const
    {
        return refCount ? *refCount : 0;
    }

    // 9. Reset
    void reset(T* p = nullptr)
    {
        release();

        if (p)
        {
            ptr = p;
            refCount = new int(1);
        }
        else
        {
            ptr = nullptr;
            refCount = nullptr;
        }
    }
};
```

---

## 4. Example Usage

```cpp
int main()
{
    SimpleSharedPtr<int> p1(new int(10));

    std::cout << "p1 count = " << p1.use_count() << "\n";

    {
        SimpleSharedPtr<int> p2 = p1;
        std::cout << "After copy:\n";
        std::cout << "p1 count = " << p1.use_count() << "\n";
        std::cout << "p2 count = " << p2.use_count() << "\n";
    } // p2 destroyed here

    std::cout << "After p2 destroyed:\n";
    std::cout << "p1 count = " << p1.use_count() << "\n";

    return 0;
}
```

### Output

```
p1 count = 1
After copy:
p1 count = 2
p2 count = 2
After p2 destroyed:
p1 count = 1
```

---

## 5. How Deletion Happens (Key Insight)

* Every copy → `refCount++`
* Every destruction/reset → `refCount--`
* When `refCount == 0`:

  * managed object is deleted
  * counter is deleted

This is the **heart of shared_ptr**.

---

## 6. What This Implementation Does NOT Handle (Important)

| Feature              | Real `std::shared_ptr`       |
| -------------------- | ---------------------------- |
| Thread safety        | Uses atomic reference count  |
| `weak_ptr`           | Prevents cyclic memory leaks |
| Custom deleters      | Supported                    |
| Aliasing constructor | Supported                    |
| Control block        | Separate structure           |

---

## 7. Major Pitfall: Cyclic Dependency

```cpp
struct A {
    SimpleSharedPtr<A> other;
};
```

* Two objects referencing each other
* `refCount` never reaches zero
* **Memory leak**

This is why **`std::weak_ptr` exists**.

---

## 8. Interview-Ready Summary

* `shared_ptr` uses **reference counting**
* Deletion happens when **count reaches zero**
* Copying increases count
* Cycles cause leaks
* Thread safety requires atomic counters

---



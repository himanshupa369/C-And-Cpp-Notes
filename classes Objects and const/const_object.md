
---

## ✅ 1. What is a **const object** in C++?

A **const object** is an object whose **state cannot be modified** after creation.

```cpp
class Car {
public:
    int speed;
};

int main() {
    const Car c{100};
    // c.speed = 120; ❌ ERROR: Cannot modify const object
}
```

➡ Once created, **data members cannot be changed directly**.

---

## ✅ 2. What is a **non-const object**?

A **non-const object** is a normal object whose **state can be modified freely**.

```cpp
Car c{100};
c.speed = 120; ✅ Allowed
```

---

## ✅ 3. Key Differences Between const & non-const Object

| Feature                              | const Object     | non-const Object |
| ------------------------------------ | ---------------- | ---------------- |
| Modification                         | ❌ Not allowed    | ✅ Allowed        |
| Can call non-const member functions? | ❌ No             | ✅ Yes            |
| Can call const member functions?     | ✅ Yes            | ✅ Yes            |
| Data safety                          | ✅ High           | ❌ Less           |
| Used for                             | Read-only access | Read + Write     |

---

## ✅ 4. Member Function Restriction

### ✅ Non-const member function

```cpp
class Test {
public:
    void modify() {
        // can modify data
    }
};
```

### ✅ Const member function

```cpp
class Test {
public:
    void read() const {
        // Cannot modify data
    }
};
```

### 🔴 Rule:

| Object Type      | Can Call                 |
| ---------------- | ------------------------ |
| const object     | ✅ const functions only   |
| non-const object | ✅ both const & non-const |

---

## ✅ 5. Example Showing Limitation

```cpp
class Student {
public:
    int marks;

    void setMarks(int m) {
        marks = m;
    }

    int getMarks() const {
        return marks;
    }
};

int main() {
    const Student s{90};

    s.getMarks(); ✅ Allowed
    s.setMarks(100); ❌ ERROR: const object can't call non-const function
}
```

---

## ✅ 6. const Object with Mutable

`mutable` allows modification inside const objects.

```cpp
class Logger {
public:
    mutable int count;

    void log() const {
        count++; ✅ Allowed
    }
};
```

---

## ✅ 7. const Object and Pointers

| Declaration        | Meaning               |
| ------------------ | --------------------- |
| `const T* p`       | Cannot modify value   |
| `T* const p`       | Cannot change pointer |
| `const T* const p` | Nothing can change    |

---

## ✅ 8. Limitations of const Object

❌ Cannot modify **any non-mutable data**
❌ Cannot call **non-const member functions**
❌ Cannot be assigned after initialization
❌ Must be initialized immediately
❌ Cannot use setters unless they are `const`

---

## ✅ 9. Advantages of const Object

✅ Prevents accidental modification
✅ Improves program safety
✅ Helps compiler optimization
✅ Enables const-correct APIs
✅ Required for function parameters passed as `const &`

---

## ✅ 10. When to Use What?

| Use Case             | Use              |
| -------------------- | ---------------- |
| Read-only object     | const object     |
| Object needs updates | non-const object |
| Function parameter   | `const T&`       |
| Shared object access | const            |

---

## ✅ Final One-Line Summary

> A **const object cannot modify its state and can only call const member functions**, whereas a **non-const object can modify state and call both const and non-const functions**.

---

---

# 📘 Const Objects in C++

**C++ Version:** C++11+
**Topic Type:** Object Const-Correctness
**Used With:** Classes, Pointers, References, Member Functions

---

## ✅ 1. What is a `const` Object?

A **const object** is an object whose **state cannot be modified after creation**.

```cpp
const Dog dog1("Fluffy","Shepherd",2);
```

✅ You **can only read data** from a const object
❌ You **cannot modify any member variable**

---

## ✅ 2. What is Allowed & Not Allowed on Const Objects?

| Operation                     | Allowed? | Reason                             |
| ----------------------------- | -------- | ---------------------------------- |
| Call setter                   | ❌        | Modifies data                      |
| Call getter (non-const)       | ❌        | Compiler assumes it *might modify* |
| Call non-const print function | ❌        | Uses `this` pointer                |
| Assign to non-const pointer   | ❌        | Breaks const safety                |
| Assign to non-const reference | ❌        | Breaks const safety                |
| Assign to const pointer       | ✅        | Safe                               |
| Assign to const reference     | ✅        | Safe                               |

---

## ✅ 3. Why Do Getters FAIL on Const Objects?

Your getters are written as:

```cpp
std::string_view get_name();
```

❌ This tells the compiler:

> “This function **MAY modify the object**”

Internally, the compiler converts:

```cpp
return m_name;
```

into:

```cpp
return this->m_name;
```

Since `this` becomes:

```cpp
const Dog* this;
```

❌ The compiler **blocks the call**, assuming modification might happen.

---

## ✅ 4. Problem Summary

When an object is declared `const`:

✅ The compiler protects it from:

* Setter calls
* Direct modification
* Modification via pointer
* Modification via reference

❌ But **ALL member functions are blocked**, including:

* `get_name()`
* `get_breed()`
* `get_age()`
* `print_info()`

➡ Because they are **NOT marked `const`**

---

## ✅ 5. Pointer & Reference Behavior with Const Objects

### ❌ Pointer to Non-Const (INVALID)

```cpp
Dog* dog_ptr = &dog1;   // ❌ Compiler error
```

### ❌ Non-Const Reference (INVALID)

```cpp
Dog& dog_ref = dog1;   // ❌ Compiler error
```

### ✅ Pointer to Const (VALID)

```cpp
const Dog* const_dog_ptr = &dog1;  // ✅ Allowed
```

But:

```cpp
const_dog_ptr->set_name("Milou");  // ❌
const_dog_ptr->get_name();        // ❌ (because getter is not const)
```

---

### ✅ Const Reference (VALID)

```cpp
const Dog& const_dog_ref = dog1;   // ✅ Allowed
```

But:

```cpp
const_dog_ref.set_name("Milou");   // ❌
const_dog_ref.get_name();         // ❌
```

---

## ✅ 6. Root Cause of All Errors

> ❗ **Member functions are NOT marked `const`**

So the compiler assumes:

* They *might modify* the object
* `this` is treated as `Dog*`, not `const Dog*`

---

## ✅ 7. The Real Solution (Preview of Next Lecture)

To FIX this issue, you must mark read-only functions as `const`:

### ✅ Correct Getter Declarations:

```cpp
std::string_view get_name() const;
std::string_view get_breed() const;
unsigned int get_age() const;
void print_info() const;
```

### ✅ Correct Definitions:

```cpp
std::string_view Dog::get_name() const {
    return m_name;
}
```

Now the compiler treats:

```cpp
this  -->  const Dog*
```

✅ Reading allowed
❌ Writing blocked
✅ Const correctness fully enforced

---

## ✅ 8. Pros & Cons of Const Objects

### ✅ PROS

* Prevents accidental modification
* Improves program safety
* Helps compiler optimize
* Required for API design & threading
* Enforces clean architecture

### ❌ CONS (If not used properly)

* Without `const` member functions → object becomes unusable
* Breaks function calls until fixed
* Requires careful design

---

## ✅ 9. Real-World Use Cases

* Read-only configuration objects
* Constant database records
* Thread-safe shared objects
* STL containers passed by `const&`
* Game engines (immutable components)
* Financial systems (fixed transaction records)

---

## ✅ Final Interview Summary ✅

> A `const` object in C++ cannot be modified in any way. If its member functions are not marked `const`, the compiler assumes they might modify the object and blocks their usage. To allow safe reading, getters and utility functions **must be declared `const`**.

---

�


---

# ✅ Copy Constructors in C++

## 🔹 Header

**Topic:** Copy Constructor
**Language:** C++
**Feature Available Since:** ✅ **C++98**
**Related Concepts:** Shallow Copy, Deep Copy, Rule of Three, Dynamic Memory Management

---

## 🔹 Definition

A **copy constructor** is a special constructor that is **automatically called when a new object is created from an existing object of the same class**.

### ✅ One-Line Definition (Exam / Interview)

> A copy constructor initializes a new object using an existing object of the same class.

---

## 🔹 Syntax

```cpp
ClassName(const ClassName& source);
```

✅ Always pass by **const reference**
❌ Passing by value is **illegal**

---

## 🔹 When Is a Copy Constructor Called?

| Scenario                           | Example                              |
| ---------------------------------- | ------------------------------------ |
| Object created from another object | `Person p2 = p1;`                    |
| Copy initialization                | `Person p2(p1);`                     |
| Pass object by value               | `func(p1);`                          |
| Return object by value             | `return p1;`                         |
| Object stored in containers        | `vector<Person> v; v.push_back(p1);` |

---

## 🔹 Default (Compiler-Generated) Copy Constructor

If **you do not define a copy constructor**, C++ **automatically creates one** that performs:

> ✅ **Memberwise (shallow) copy**

That means:

* `int`, `double` → copied safely
* `std::string` → deep copy internally
* ❌ **Raw pointers → only the address is copied**

---

## 🔹 The Core Problem: Copying Pointer Members

### ❌ Shallow Copy Problem (Pointer Sharing)

```cpp
int* age;
```

Default copy behavior:

```
Person p1 -----> age (heap)
Person p2 -----> SAME age (heap)
```

### ❗ Problem Created:

* Changing `p1.age` changes `p2.age`
* Double deletion risk in destructor
* Data corruption

---

## 🔹 ❌ Invalid Copy Constructor (Passing by Value)

```cpp
Person(Person source);   // ❌ ILLEGAL
```

### 🔴 Why This Is Forbidden:

* To pass `source` by value → copy constructor must be called again
* Leads to **infinite recursion**
* C++ **explicitly disallows this**

---

## 🔹 ❌ Bad Copy Constructor (Shallow Copy)

```cpp
Person(const Person& src)
    : last_name(src.last_name),
      first_name(src.first_name),
      age(src.age) {}   // ❌ Pointer copied blindly
```

### 🚨 Problem:

* Both objects point to **same memory**
* Violates object independence

---

## ✅ Correct Copy Constructor (Deep Copy)

```cpp
Person(const Person& src)
    : last_name(src.last_name),
      first_name(src.first_name),
      age(new int(*src.age)) {}   // ✅ Deep copy
```

### ✅ What This Fixes:

* New memory created for `age`
* Both persons are independent
* No shared memory
* No double delete

---

## ✅ Copy Constructor Using Delegation (Best Design)

```cpp
Person(const Person& src)
    : Person(src.getLastName(),
             src.getFirstName(),
             *src.getAge()) {}
```

### ✅ Advantage:

* Reuses existing memory-safe constructor
* Avoids duplicate allocation logic
* Clean and maintainable

---

## 🔹 Destructor Requirement (Rule of Three)

If your class has **any of the following**, you MUST implement all three:

| Function                   | Purpose              |
| -------------------------- | -------------------- |
| ✅ Destructor               | Frees dynamic memory |
| ✅ Copy Constructor         | Deep copy            |
| ✅ Copy Assignment Operator | Safe reassignment    |

### ✅ Correct Destructor Example

```cpp
~Person() {
    delete age;
}
```

---

## 🔹 What the Debugger Proves

| Case                     | Result                     |
| ------------------------ | -------------------------- |
| Default copy             | Same pointer address       |
| Custom deep copy         | Different memory addresses |
| After modifying `p1.age` | `p2.age` unchanged ✅       |

---

## 🔹 Real-World Use Cases

* Classes managing:

  * Dynamic memory (`new`, `delete`)
  * Files (`fstream`)
  * Network sockets
  * Database connections
  * Game characters
  * Simulation entities

---

## ✅ Advantages of Custom Copy Constructors

| Benefit                       | Reason                |
| ----------------------------- | --------------------- |
| ✅ Prevents shared memory bugs | Deep copy             |
| ✅ Prevents double delete      | Safe destruction      |
| ✅ Object independence         | No side effects       |
| ✅ Works safely with STL       | `vector`, `map`, etc. |

---

## ❌ Disadvantages / Risks

| Risk                       | Explanation        |
| -------------------------- | ------------------ |
| ❌ Manual memory management | Error-prone        |
| ❌ Forgetting destructor    | Memory leaks       |
| ❌ Shallow copy by mistake  | Data corruption    |
| ❌ Rule of Three violations | Crashes at runtime |

---

## ✅ Best Practices

* ✔ Always use:

  ```cpp
  Class(const Class& obj);
  ```

* ✔ Deep copy **all raw pointers**

* ✔ Always implement destructor if using `new`

* ✔ Prefer:

  * `std::unique_ptr`
  * `std::shared_ptr`
  * `std::string`
  * `std::vector`

* ❌ Avoid raw pointers unless absolutely necessary

---

## ✅ Quick Interview Summary

* Compiler creates **shallow copy constructor by default**
* **Raw pointers must be deep copied**
* Copy constructor must take:

  ```cpp
  const Class&
  ```
* If destructor is custom → copy constructor MUST be custom
* Delegation is the cleanest implementation

---


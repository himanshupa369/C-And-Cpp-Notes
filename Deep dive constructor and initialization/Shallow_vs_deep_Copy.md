<img width="1750" height="636" alt="Screenshot 2025-12-09 152721" src="https://github.com/user-attachments/assets/d9a14b18-a22a-4655-9fa5-b6d9076a0857" />

---
---

# **Shallow Copy vs Deep Copy in C++ (OOP)**

### *Understanding Copying Semantics for Classes with Pointer Members*

---

## **1. Introduction**

In C++ Object-Oriented Programming, copying objects is a fundamental operation.
When an object is copied, C++ can perform two types of copying:

1. **Shallow Copy**
2. **Deep Copy**

Knowing the difference is crucial when your class contains **pointer member variables** or manually managed resources (heap memory, file handles, sockets, etc.).

---

# **2. Shallow Copy**

### **Definition**

A **shallow copy** performs **member-wise copying** of the object.

The compiler-generated default copy constructor does this:

* Copies each data member **as-is**.
* If the class contains a raw pointer, **the pointer address is copied**, not the data it points to.

### **Behavior**

* Two objects end up **sharing the same memory** for pointer members.
* Both objects refer to the **same heap resource**.

### **Illustration**

```
P1.age → 0x100 (value = 25)
P2.age → 0x100 (same address!)
```

Both objects point to the **same int** in memory.

### **Problem with Shallow Copy**

* **Double deletion**: Both destructors try to free the same memory → undefined behavior.
* Unexpected modification: Changing data through one object affects the other.

### **When does shallow copy happen?**

* When you do not define a custom copy constructor.
* When your class contains only normal (non-pointer) members, shallow copy is safe.

---

# **3. Deep Copy**

### **Definition**

A **deep copy** duplicates not only the object, but also **the dynamically allocated data it owns**.

This means:

* Allocate a new memory location.
* Copy the *content* from the source pointer into the new memory.

### **Behavior**

```
P1.age → 0x100 (value = 25)
P2.age → 0x200 (value = 25) // new separate memory
```

Objects are **independent**.

### **Advantages**

* No double deletion.
* No shared mutable state.
* Safe and predictable behavior.

### **When is deep copy needed?**

* Whenever your class allocates memory using `new`, `new[]`, `malloc`, or any resource that must be uniquely owned.

---

# **4. Example of Deep Copy in Copy Constructor**

### **Deep Copy Implementation**

```cpp
Person(const Person& source)
    : last_name(source.last_name),
      first_name(source.first_name),
      age(new int(*(source.age))) // deep copy
{
    std::cout << "Copy constructor called for " << last_name << std::endl;
}
```

### **Explanation**

* Allocate new memory: `new int(...)`
* Copy the *value* using `*(source.age)`
* Now each object has its **own separate memory block**

---

# **5. How Shallow Copy Would Look**

(What compiler generates by default)

```cpp
Person(const Person& source)
    : last_name(source.last_name),
      first_name(source.first_name),
      age(source.age)   // shallow copy: copies address only
{}
```

### Why this is dangerous:

* Both objects share the same pointer.
* Destructor of both objects tries to `delete age`.

---

# **6. Summary Table**

| Feature            | Shallow Copy                 | Deep Copy                       |
| ------------------ | ---------------------------- | ------------------------------- |
| Pointer data       | Address copied               | New memory allocated            |
| Resource ownership | Shared                       | Independent                     |
| Memory safety      | Risk of double free, crashes | Safe                            |
| Performance        | Faster                       | Slightly slower                 |
| Compiler default   | Yes                          | No (you must write custom code) |

---

# **7. Key Takeaways**

* **If your class uses raw pointers → always implement deep copy** using a custom copy constructor.
* Shallow copy works only when class contains **no pointers**.
* Deep copy ensures objects **own their own resources**.
* Deep copy avoids undefined behavior related to double deletion and shared pointers.
* Modern C++ prefers **smart pointers (unique_ptr, shared_ptr)** to avoid manual deep/shallow management.

---


---

# **Personal Notes – Member Variables of Other Types in C++**

## **1. Overview**

When designing a class, the member variables inside it can be primitive types (int, double, etc.), custom classes, pointers, or static members.
The rules and limitations depend heavily on whether the member variable's type is **the same as the class** or **a different class**.

These notes focus on what happens when the member variable belongs to **another class**, such as embedding an `Integer` class inside a `Point` class.

---

# **2. Using Member Variables of Another Class**

### **2.1 Direct Object Members**

If class `Point` contains an object of class `Integer`, such as:

```cpp
Integer i1;
const Integer i2;
```

this is always allowed because `Integer` is a fully known type at the moment `Point` is parsed.

Key points:

* The constructors of `Point` will call constructors of `Integer`.
* No recursion occurs.
* No incomplete-type issues arise.

---

# **3. Inline Static Members (C++17 and later)**

Static object members may be declared **inline** and initialized directly inside the class:

```cpp
static inline Integer i3{10};
```

Why this works:

* Inline tells the compiler to allow definition inside the class.
* Prevents multiple-definition errors across translation units.
* Works only in C++17 and above.

Without `inline`, the definition must be placed in a `.cpp` file.

---

# **4. Static Members (Non-inline)**

Static members marked **without inline** cannot be initialized inside the class.
They *must be defined* in the implementation file:

Header:

```cpp
static Integer i6;
static const Integer i7;
```

Implementation:

```cpp
Integer Point::i6{100};
const Integer Point::i7{200};
```

Notes:

* `i6` can be modified.
* `i7` is constant and cannot be modified.

---

# **5. Pointer Member Variables**

Pointers to other types behave normally:

```cpp
Integer* i4 = nullptr;
```

Key points:

* Pointer initialization inside the class is allowed.
* The constructor can safely allocate memory in the initializer list:

```cpp
Point() : i4(new Integer(5)) {}
```

Reason this is safe:

* No recursive constructor calls (unlike embedding the same class inside itself).
* `Point` constructor calls the `Integer` constructor once.

---

# **6. Comparison with Embedding the Same Class**

### **When member type = same class**

This fails:

```cpp
class Node {
    Node child;  // Illegal (incomplete type)
};
```

Because:

* The compiler does not yet know the full layout of `Node`.
* Construction would recursively call itself infinitely.

### **When member type = different class**

All of the following work:

* regular object members
* const members
* inline static members
* non-inline static members
* pointers
* dynamic allocation

There is no recursive construction problem.

---

# **7. Const-Correctness and Member Access**

Examples of valid and invalid operations:

### **Modifiable member**

```cpp
i1.set_value(50);  // OK (i1 is not const)
```

### **Const member**

```cpp
i2.set_value(20);  // ERROR (i2 is const)
```

### **Static non-const**

```cpp
Point::i6.set_value(33);  // OK
```

### **Static const**

```cpp
Point::i7.set_value(33);  // ERROR
```

---

# **8. Summary of Key Understanding**

1. Embedding objects of *different* types inside a class is always valid.
2. Inline static members work well for cross-class objects (C++17+).
3. Static (non-inline) members must be defined in a `.cpp` file.
4. Pointer members are safe to initialize directly or in constructors.
5. No recursive constructor issues occur unless the type is the same as the class itself.
6. Const static and const object members enforce read-only access.

---

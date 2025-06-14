
---

## ✅ `dynamic_cast` – C++ Interview Questions & Answers

---

### 🔹 1. **What is `dynamic_cast` in C++?**

**Answer:**
`dynamic_cast` is used to **safely convert pointers or references** within an **inheritance hierarchy** when using polymorphism. It performs a **runtime type check** using **RTTI (Run-Time Type Information)**.

```cpp
Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b); // ✅ Safe downcast
```

---

### 🔹 2. **When should you use `dynamic_cast`?**

**Answer:**

* When you’re not sure about the **dynamic type** of the object.
* When performing **safe downcasting** (from base to derived).
* When working with **polymorphic types** (i.e., base class has at least one `virtual` function).

---

### 🔹 3. **What happens if the cast fails?**

* For **pointers**: returns `nullptr`
* For **references**: throws `std::bad_cast`

```cpp
Base* b = new Base();
Derived* d = dynamic_cast<Derived*>(b); // d == nullptr
```

---

### 🔹 4. **What are the requirements for using `dynamic_cast`?**

✅ You **must** have:

* A **polymorphic base class** (`virtual` function is required)
* A **valid inheritance hierarchy**

```cpp
class Base { public: virtual void f() {} }; // required
class Derived : public Base {};
```

---

### 🔹 5. **Can `dynamic_cast` be used with non-polymorphic types?**

❌ No. It will cause a **compiler error** if the base class has no virtual function.

---

### 🔹 6. **How is `dynamic_cast` different from `static_cast`?**

| Feature            | `dynamic_cast`              | `static_cast`           |
| ------------------ | --------------------------- | ----------------------- |
| Safety             | ✅ Runtime-checked           | ❌ No runtime check      |
| Overhead           | ✅ Yes (uses RTTI)           | ❌ No                    |
| Returns `nullptr`? | ✅ If pointer cast fails     | ❌ Undefined behavior    |
| Throws exception?  | ✅ On reference cast failure | ❌ Never                 |
| Use-case           | Uncertain polymorphic cast  | Safe, known conversions |

---

### 🔹 7. **Code Example – Successful Downcast**

```cpp
class Animal { public: virtual ~Animal() {} };
class Dog : public Animal {};

Animal* a = new Dog();
Dog* d = dynamic_cast<Dog*>(a); // ✅ Safe, succeeds
```

---

### 🔹 8. **Code Example – Failed Downcast**

```cpp
class Cat : public Animal {};
Animal* a = new Cat();
Dog* d = dynamic_cast<Dog*>(a); // ❌ Returns nullptr
```

---

### 🔹 9. **How is `dynamic_cast` used with references?**

```cpp
Animal& a = Cat();
try {
    Dog& d = dynamic_cast<Dog&>(a); // ❌ Throws std::bad_cast
} catch (std::bad_cast& e) {
    std::cout << "Cast failed: " << e.what();
}
```

---

### 🔹 10. **What is RTTI and how is it related to `dynamic_cast`?**

**Answer:**
RTTI (Run-Time Type Information) is a mechanism that allows the type of an object to be determined during program execution. `dynamic_cast` relies on RTTI to check whether the actual object type matches the target type during a cast.

---

### 🔹 11. **Can you use `dynamic_cast` with `void*`?**

❌ No, `dynamic_cast` **cannot cast to/from `void*`**. Use `static_cast` instead.

---

### 🔹 12. **Is `dynamic_cast` slower than `static_cast`?**

**Yes**, `dynamic_cast` introduces a small **runtime cost** due to RTTI. But it is much **safer** for complex hierarchies.

---

### 🔹 13. **When should `dynamic_cast` be avoided?**

* In **performance-critical code** (use design patterns instead like Visitor)
* When the cast is **known to be safe** (use `static_cast`)
* When frequent casting indicates a **bad design** (use virtual functions instead)

---

## 🧪 Real-Life Scenario – Interface Detection

```cpp
class Drawable {
public:
    virtual void draw() = 0;
};

class Circle : public Drawable {
public:
    void draw() override { std::cout << "Drawing Circle\n"; }
};

void tryDraw(Drawable* obj) {
    Circle* c = dynamic_cast<Circle*>(obj);
    if (c) c->draw(); // ✅ Only draw if it's really a Circle
}
```

---

## ✅ Summary Table

| Feature                  | `dynamic_cast`                 |
| ------------------------ | ------------------------------ |
| Cast Type                | Safe polymorphic downcast      |
| Runtime check            | ✅ Yes (via RTTI)               |
| Failure on pointer       | Returns `nullptr`              |
| Failure on reference     | Throws `std::bad_cast`         |
| Needs virtual function   | ✅ Yes (polymorphic base)       |
| Safer than static\_cast? | ✅ Yes                          |
| Use-case                 | Unknown actual type at runtime |

---


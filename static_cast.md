
---

## ✅ `static_cast` in C++ – Interview Questions & Answers

---

### 🔹 1. **What is `static_cast` in C++?**

**Answer:**
`static_cast` is a **compile-time type conversion** in C++. It is used for **safe and explicit conversions** between compatible types.

```cpp
double d = 3.14;
int i = static_cast<int>(d); // truncates decimal
```

---

### 🔹 2. **What kinds of conversions can `static_cast` perform?**

✅ Allowed:

* Basic type conversions (int → float, float → int)
* Pointer conversions in class hierarchy (base ↔ derived)
* Enum to int and vice versa
* void\* ↔ typed pointer

---

### 🔹 3. **Can `static_cast` be used between unrelated classes?**

❌ **No**. It only works with types that have a known conversion path (like base/derived).

```cpp
class A {};  
class B {};  
// B* b = static_cast<B*>(new A()); ❌ Compile-time error
```

---

### 🔹 4. **How is `static_cast` different from `dynamic_cast`?**

| Feature     | `static_cast`      | `dynamic_cast`               |
| ----------- | ------------------ | ---------------------------- |
| Type check? | ✅ Compile-time     | ✅ Runtime (RTTI)             |
| Overhead?   | ❌ No               | ✅ Slight runtime overhead    |
| Safety?     | ❌ No type check    | ✅ Returns `nullptr` if fails |
| Use-case    | Known-safe up/down | Polymorphic base conversion  |

---

### 🔹 5. **Can `static_cast` be used for upcasting and downcasting?**

✅ **Yes**, but with caution for **downcasting**.

```cpp
class Base { public: void speak() { std::cout << "Base\n"; } };
class Derived : public Base { public: void speak() { std::cout << "Derived\n"; } };

Base* b = new Derived();
Derived* d = static_cast<Derived*>(b); // works if b actually points to Derived
```

⚠️ If `b` doesn't point to a `Derived`, you get **undefined behavior**.

---

### 🔹 6. **Can `static_cast` be used to cast from `void*`?**

✅ Yes, and it’s the **preferred** way to cast from `void*`.

```cpp
void* vp = new int(42);
int* ip = static_cast<int*>(vp);
```

---

### 🔹 7. **Can `static_cast` remove `const`?**

❌ **No**, it cannot cast away `const`. Use `const_cast` for that.

```cpp
const int a = 5;
// int* p = static_cast<int*>(&a); ❌ Error
```

---

### 🔹 8. **What happens if `static_cast` fails?**

It can result in:

* Compile-time error (for incompatible types)
* **Undefined behavior at runtime** (for invalid downcasting)

---

### 🔹 9. **Can `static_cast` be used with references?**

✅ Yes.

```cpp
int a = 10;
double b = static_cast<double>(a);
```

Or with class references:

```cpp
Base b;
Derived& d = static_cast<Derived&>(b); // ⚠️ Dangerous if `b` is not really Derived
```

---

### 🔹 10. **Give an example where `static_cast` is dangerous.**

```cpp
class A { virtual void foo() {} };
class B : public A {};
class C : public A {};

A* a = new C();
B* b = static_cast<B*>(a); // ❌ compiles, but runtime crash
```

---

## 🧪 Example: Upcast and Downcast

```cpp
class Animal { public: void sound() { std::cout << "Animal\n"; } };
class Dog : public Animal { public: void sound() { std::cout << "Dog\n"; } };

void play(Animal* a) {
    Dog* d = static_cast<Dog*>(a); // Unsafe if a is not actually Dog
    d->sound(); // Undefined behavior if a is Animal*
}
```

---

## ✅ When to Use `static_cast`

| Use-case                     | Example                            |
| ---------------------------- | ---------------------------------- |
| Narrowing/widening types     | `double → int`                     |
| Enum ↔ int                   | `Color c = static_cast<Color>(1);` |
| Upcast/downcast (safe known) | `Base* → Derived*`                 |
| void\* to typed pointer      | `int* = static_cast<int*>(void*)`  |

---

## ❌ When Not to Use `static_cast`

| Don't Use For              | Use Instead       |
| -------------------------- | ----------------- |
| Removing const/volatile    | `const_cast`      |
| Type-safe downcasting      | `dynamic_cast`    |
| Completely unrelated types | Don't cast at all |

---

## 🧠 Bonus: `static_cast` vs C-style cast

```cpp
int x = 10;
float y = (float)x;         // C-style
float z = static_cast<float>(x); // C++ style ✅ safer & clearer
```

---

### 🚫 Drawbacks of C-style Cast:

* Ambiguous: could be static, const, or reinterpret
* Error-prone and hard to debug
* `static_cast` is **explicit**, **readable**, and **compiler-checked**

---

## ✅ Summary

* `static_cast` is safe for **compile-time** known conversions.
* It’s ideal for **numeric conversions**, **upcasting**, **void* casts*\*.
* ⚠️ Use with care when **downcasting** — better to use `dynamic_cast` if polymorphic.

---


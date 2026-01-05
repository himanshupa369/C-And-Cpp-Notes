
---

# `static_cast` in C++

## Overview

`static_cast` is a **compile-time type conversion operator** in C++.
It performs **checked, explicit conversions** that are considered **safe by the compiler**, but **does not perform runtime type checking**.

---

## Syntax

```cpp
static_cast<target_type>(expression)
```

---

## Why `static_cast` Exists

* Replaces **C-style casts**
* Makes conversions **explicit and readable**
* Prevents unsafe conversions that C-style casts allow
* Helps the compiler catch errors early

---

## What `static_cast` Can Do

---

### 1. Primitive Type Conversions

```cpp
double d = 10.5;
int x = static_cast<int>(d);   // x = 10
```

✔ Allowed
✔ Compile-time conversion
❌ No runtime checks

---

### 2. Pointer Conversions (Upcasting)

```cpp
class Base {};
class Derived : public Base {};

Derived d;
Base* b = static_cast<Base*>(&d);
```

✔ Safe
✔ Always allowed
✔ No runtime cost

---

### 3. Pointer Conversions (Downcasting – Unsafe)

```cpp
Base* b = new Derived();
Derived* d = static_cast<Derived*>(b); // Compiles, but risky
```

⚠ Compiles
❌ No runtime check
⚠ Undefined behavior if object is not actually `Derived`

👉 Prefer `dynamic_cast` here.

---

### 4. Enum ↔ Integer Conversion

```cpp
enum Color { Red = 1, Green = 2 };

int x = static_cast<int>(Red);
Color c = static_cast<Color>(2);
```

✔ Explicit
✔ Safer than implicit conversion

---

### 5. Removing `const`? ❌ Not Allowed

```cpp
const int x = 10;
int* p = static_cast<int*>(&x); // ERROR
```

❌ Use `const_cast` instead.

---

### 6. Conversion Between Related Types

```cpp
void func(void* data) {
    int* p = static_cast<int*>(data);
}
```

✔ Common in low-level APIs
⚠ Programmer must ensure correctness

---

## What `static_cast` Cannot Do

| Operation                        | Allowed |
| -------------------------------- | ------- |
| Remove `const`                   | ❌       |
| Cast unrelated pointer types     | ❌       |
| Runtime checked downcast         | ❌       |
| Cast through private inheritance | ❌       |

---

## `static_cast` vs C-Style Cast

| Feature               | `static_cast` | C-Style Cast |
| --------------------- | ------------- | ------------ |
| Explicit intent       | ✅             | ❌            |
| Compile-time checking | ✅             | ❌            |
| Readability           | High          | Low          |
| Safety                | Safer         | Risky        |

---

## `static_cast` vs Other Casts

| Cast               | Purpose                          |
| ------------------ | -------------------------------- |
| `static_cast`      | Safe compile-time conversions    |
| `dynamic_cast`     | Runtime-checked polymorphic cast |
| `const_cast`       | Add/remove const/volatile        |
| `reinterpret_cast` | Low-level, unsafe bit casts      |

---

## Real-World Use Cases

* Numeric conversions
* Enum conversions
* Upcasting in inheritance
* API callbacks
* STL iterator conversions

---

## Best Practices

* Prefer `static_cast` over C-style casts
* Avoid downcasting with `static_cast`
* Use `dynamic_cast` when runtime safety is needed
* Keep casts minimal and intentional

---

## Common Interview Questions

### Q1. Does `static_cast` perform runtime checking?

❌ No. It only performs compile-time checks.

---

### Q2. Is `static_cast` safer than C-style cast?

✅ Yes, because it restricts unsafe conversions.

---

### Q3. Can `static_cast` remove `const`?

❌ No. Use `const_cast`.

---

### Q4. When to use `static_cast` vs `dynamic_cast`?

* Use `static_cast` for **known, safe conversions**
* Use `dynamic_cast` when **runtime verification is required**

---

## Example Summary Code

```cpp
class Base {};
class Derived : public Base {};

Base* b = new Derived();
Derived* d1 = static_cast<Derived*>(b);   // Risky
Derived* d2 = dynamic_cast<Derived*>(b);  // Safe
```

---

## Key Takeaway

> `static_cast` is **explicit, fast, and compile-time checked**, but **trusts the programmer**.

---

```cpp
//... static cast ...

/* static_cast is a type of casting operator in C++ that is used for compile-time type conversion. 
It is safer and more explicit than C-style casting ((type)value).*/

// Key Features of static_cast:

//✔ Used for converting between related types(like int to float, double to int, pointer conversions, etc.).
//✔ Performed at compile time(does not involve runtime checks).
//✔ Safer than C - style casting but does not check for correctness at runtime.
//✔ Cannot be used for converting between completely unrelated types(e.g., int to std::string).

// When NOT to Use static_cast
//❌ Between unrelated types(e.g., int to std::string).
//❌ If you need runtime safety(use dynamic_cast for polymorphic types).
//❌ For casting away const (use const_cast).

#include <iostream>
using namespace std;

class Base {};
class Derived : public Base {};

enum Color { RED, GREEN, BLUE };

int main() {

   //Basic Type Conversion (Primitive Types)
   double pi = 3.14159;
   int intPi = static_cast<int>(pi); // Explicit conversion (float to int)
   cout << "Integer value: " << intPi << endl; // Output: 3


   // Pointer Type Conversion (Base to Derived and Vice Versa)
   Derived d;
   Base* basePtr = static_cast<Base*>(&d);  // Derived* → Base* 
   Derived* derivedPtr = static_cast<Derived*>(basePtr); // Base* → Derived* 


   //Enum to Integer Conversion

   Color c = GREEN;
   int colorValue = static_cast<int>(c); // Enum to int conversion
   cout << "Enum value: " << colorValue << endl; // Output: 1

   return 0;
}
```

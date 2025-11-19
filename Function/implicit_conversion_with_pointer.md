
---

# ✅ **Implicit Conversion With Pointer Function Parameters in C++**

In C++, **implicit conversions work for values—but NOT for pointers** (except in very specific safe cases).

Pointers represent **addresses**, not values.
So the compiler cannot convert one pointer type to another unless it's explicitly allowed.

---

# ✔ **1. What implicit conversions ARE allowed (safe)**

### **(A) `Derived*` → `Base*` conversion (Upcasting)**

Safe, implicit, always allowed.

```cpp
class Base {};
class Derived : public Base {};

void func(Base* ptr) {}

int main() {
    Derived d;
    func(&d);   // OK: Derived* → Base*
}
```

---

### **(B) `T*` → `const T*`**

You can always add const-qualification.

```cpp
void print(const int* p) {}

int main() {
    int x = 10;
    print(&x);   // OK
}
```

---

# ❌ **2. What implicit conversions are NOT allowed**

### **(A) No int → int* conversion**

Values cannot become pointers implicitly.

```cpp
void func(int* p) {}

int main() {
    int x = 10;
    func(x);        // ❌ ERROR: int → int* does NOT happen
}
```

---

### **(B) No double* → int* conversion**

Pointer types must match exactly unless a valid relationship exists.

```cpp
void func(int* p) {}

int main() {
    double d = 5.5;
    func(&d);      // ❌ ERROR: double* cannot convert to int*
}
```

---

### **(C) No temporary → non-const pointer**

Pointers cannot bind to temporaries at all.

```cpp
void func(int* p) {}

func(&10);   // ❌ ERROR: cannot take address of temporary literal
```

---

# ⚠ **3. Special Case — NULL/0 literal**

Historically:

```cpp
void func(int* p) {}

func(0);   // ✔ OK: 0 converts to NULL pointer
```

Modern C++:

```cpp
func(nullptr);   // ✔ BEST PRACTICE
```

---

# 📌 **4. Why implicit conversions FAIL with pointers**

Because the compiler must guarantee:

* **type safety**
* **memory correctness**
* **valid object layout**

Example:

```cpp
void func(int* p);

double d = 9.3;
func(&d);      // ❌ NOT ALLOWED
```

If this were allowed, `func` would treat the memory containing a `double` (8 bytes) as an `int` (4 bytes) → **undefined behavior**, memory corruption.

So C++ prevents it.

---

# ⭐ Final Notes — Industry Takeaways

* **Pointer parameters almost never allow implicit conversion.**
* Only allowed:

  * `T* -> const T*`
  * `Derived* -> Base*`
  * `0` or `nullptr` to any pointer
* Everything else requires **explicit cast** (and should be avoided).
```cpp
#include <iostream>

void print_sum(int* param1, int* param2){
	std::cout << "sum : " << (*param1 + *param2) << std::endl;
}

int main(){

    // int a{3};
    // int b{12};
    print_sum(&a,&b); // work fine
    double a{3.2};
    double b{12.8};
    print_sum(&a,&b); //cannot convert 'double*' to 'int*'
   
    return 0;
}

```
---

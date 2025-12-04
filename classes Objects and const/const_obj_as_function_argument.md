
---

# ✅ Passing `const` Objects as Function Parameters in C++

## 📌 Header

**Topic:** Const Objects as Function Parameters
**Language:** C++
**Concept Type:** Object Passing, Const Correctness
**Required Knowledge:** References, Pointers, `const`, Copy vs Reference
**Applies From:** C++98 → Present (C++11+ recommended)

---

## 🎯 Core Idea

A **`const` object**:

* ✅ Can be **copied**
* ❌ Cannot be **modified**
* ❌ Cannot be bound to a **non-const reference**
* ❌ Cannot be passed to a **pointer-to-non-const**
* ✅ Can be passed to:

  * `const` reference
  * pointer-to-`const`

But still:

> If your member functions are **NOT marked `const`**, even reading fails!

---

## ✅ Case 1: Passing `const` Object by **Value** ✔️ (ALWAYS WORKS)

```cpp
void function_taking_dog(Dog dog){
    dog.set_name("Internal Dog");   // Allowed
    dog.print_info();              // Allowed
}

const Dog dog1("Fluffy", "Shepherd", 2);
function_taking_dog(dog1); // ✅ Works
```

### ✅ Why It Works

* A **COPY** is created
* Original `const` object is **not modified**
* `const` protection remains intact

✅ **Best when you need modification on a copy**

⚠️ **Drawback:** Expensive for large objects

---

## ❌ Case 2: Passing by **Non-const Reference** (`Dog&`) ❌

```cpp
void function_taking_dog_ref(Dog& dog_ref) {}

function_taking_dog_ref(dog1); // ❌ Compiler Error
```

### ❌ Why It Fails

* `Dog&` allows modification
* `dog1` is `const`
* Compiler **blocks modification risk**

📌 **Rule:**

> ❌ You can NEVER bind a `const` object to a non-const reference

---

## ✅ Case 3: Passing by **Const Reference** (`const Dog&`) ⚠️

```cpp
void function_taking_const_dog_ref(const Dog& const_dog_ref){
    // const_dog_ref.set_name("Hillo"); ❌ Not allowed
    // const_dog_ref.print_info();     ❌ Also error if not const-qualified
}
```

### ⚠️ Problem Here

Even **reading fails** if:

```cpp
void Dog::print_info(); // ❌ NOT marked const
```

Because:

* Compiler assumes it **might modify the object**
* `const` reference forbids modification

✅ Works **only if getters are declared `const`**

---

## ❌ Case 4: Passing by **Pointer to Non-Const** (`Dog*`) ❌

```cpp
void function_taking_dog_p(Dog* p_dog){}
function_taking_dog_p(&dog1); // ❌ Compiler Error
```

### ❌ Reason

* `Dog*` → allows modification
* `&dog1` → is `const Dog*`
* Unsafe → Compiler blocks it

📌 **Rule:**

> ❌ `const Dog*` → cannot convert to `Dog*`

---

## ✅❌ Case 5: Passing by **Pointer to Const** (`const Dog*`) ⚠️

```cpp
void function_taking_pointer_to_const_dog(const Dog* const_p_dog){
    // const_p_dog->set_name("Hillo"); ❌
    // const_p_dog->print_info();     ❌ if not const function
}
```

### ✅ Allowed

* Safe access to object
* No modification possible

### ❌ Still Fails If:

* `print_info()` not marked `const`

---

## 🚨 The REAL PROBLEM (Biggest Takeaway)

Even when you pass:

* ✅ `const Dog&`
* ✅ `const Dog*`

You **CANNOT even READ the object** unless:

```cpp
void print_info() const;   // MUST be const
```

📌 Otherwise:

* Compiler treats it as:

  > "This function MAY modify the object"

Hence:

> ❗ Your `const` object becomes **almost useless**

---

## ✅ Correct Solution (What Next Lecture Fixes)

You must declare **getter-type member functions as `const`**:

```cpp
class Dog {
public:
    std::string get_name() const;
    void print_info() const;   // ✅ REQUIRED
};
```

Only then:

* `const Dog&` ✅ usable
* `const Dog*` ✅ usable
* Safe read-only access ✅

---

## ✅ Summary Table

| Passing Method                     | Allowed with `const` object? | Can Modify?       | Efficiency |
| ---------------------------------- | ---------------------------- | ----------------- | ---------- |
| By Value (`Dog`)                   | ✅ YES                        | ✅ Yes (copy only) | ❌ Slow     |
| By Ref (`Dog&`)                    | ❌ NO                         | ✅ Yes             | ✅ Fast     |
| By Const Ref (`const Dog&`)        | ✅ YES                        | ❌ No              | ✅ Best     |
| By Pointer (`Dog*`)                | ❌ NO                         | ✅ Yes             | ✅ Fast     |
| By Pointer to Const (`const Dog*`) | ✅ YES                        | ❌ No              | ✅ Fast     |

---

## ✅ Real-World Use Cases

* APIs that only **READ** data → use:

  ```cpp
  const Object& obj
  const Object* obj
  ```

* Game engines → avoid unnecessary copies

* Embedded systems → strict memory safety

* Competitive programming → fast + safe

---

## ✅ Pros & Cons

### ✅ Pros

* Protects objects from accidental modification
* Enforces clean design
* Enables safe sharing
* Prevents bugs

### ❌ Cons

* If `const` member functions are missing → object becomes unusable
* Requires strict discipline in class design

---

## ✅ Final One-Line Rule (Most Important)

> **If you want `const` objects to be useful, ALL your getter functions MUST be marked `const`.**

---

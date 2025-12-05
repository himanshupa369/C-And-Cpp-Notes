
---

# ✅ Const Member Functions in C++

## 📌 Header

**Topic:** Const Member Functions <br>
**Language:** C++ <br>
**Concept Type:** Const Correctness, OOP Safety <br>
**Applies From:** C++98 → Present <br>
**Used With:** `const` objects, references, pointers <br>

---

## 🎯 Problem Recap (From Previous Lectures)

When using a **`const` object**:

```cpp
const Dog dog1("Fluffy", "Shepherd", 2);
```

You faced this issue:

* ❌ Could NOT call `print_info()`
* ❌ Could NOT call getters
* ❌ Compiler assumed **all functions may modify the object**

So:

> **The const object became almost useless.**

---

## ✅ The Solution → **Const Member Functions**

We tell the compiler:

> "This function will NEVER modify the object."

We do this by writing:

```cpp
return_type function() const;
```

✅ The `const` is written **after the parameter list**

---

## ✅ Example: Marking Getters as `const`

### ✅ In `dog.h`

```cpp
class Dog {
public:
    std::string get_name() const;
    std::string get_breed() const;
    int get_age() const;

    void print_info() const;

    void set_name(std::string name);  // NOT const (modifies object)

private:
    std::string m_name;
    std::string m_breed;
    int m_age;
};
```

---

### ✅ In `dog.cpp`

```cpp
std::string Dog::get_name() const {
    return m_name;
}

std::string Dog::get_breed() const {
    return m_breed;
}

int Dog::get_age() const {
    return m_age;
}

void Dog::print_info() const {
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Breed: " << m_breed << std::endl;
    std::cout << "Age: " << m_age << std::endl;
}
```

---

## ✅ What `const` Member Functions Guarantee

Inside a `const` member function:

| Allowed                      | Not Allowed               |
| ---------------------------- | ------------------------- |
| ✅ Read data                  | ❌ Modify data             |
| ✅ Call other `const` methods | ❌ Call non-const methods  |
| ✅ Access members safely      | ❌ Change member variables |

### ❌ Illegal Example

```cpp
int Dog::get_age() const {
    m_age = 5;   // ❌ Compilation Error
    return m_age;
}
```

---

## ✅ Now `const` Objects Work Properly

```cpp
const Dog dog1("Fluffy","Shepherd",2);

dog1.print_info();    // ✅ Works
dog1.get_name();      // ✅ Works
dog1.set_name("Tom"); // ❌ Error (setter modifies object)
```

✅ Exactly what we WANT.

---

## ✅ Passing `const` Objects After Fix

### ✅ By Value → Works (Copy Made)

```cpp
void func(Dog dog);  
func(dog1);  // ✅ Works (copy created)
```

---

### ✅ By Const Reference → Works

```cpp
void func(const Dog& dog_ref);
func(dog1);  // ✅ Works
```

* No copy
* No modification
* Same memory address inside & outside

---

### ❌ By Non-Const Reference → Still Fails

```cpp
void func(Dog& dog);
func(dog1); // ❌ Error
```

---

### ✅ By Pointer to Const → Works

```cpp
void func(const Dog* p_dog);
func(&dog1); // ✅ Works
```

Inside:

```cpp
p_dog->print_info(); // ✅ Works
p_dog->set_name();  // ❌ Error
```

---

## ✅ Memory Behavior Summary

| Passing Method      | Inside Address Same? | Copy? |
| ------------------- | -------------------- | ----- |
| By Value            | ❌ No                 | ✅ Yes |
| By Const Reference  | ✅ Yes                | ❌ No  |
| By Pointer to Const | ✅ Yes                | ❌ No  |

---

## 🔁 Function Overloading Using `const`

You **can overload based on `const`**:

```cpp
void show();        // For non-const objects
void show() const; // For const objects
```

Compiler decides based on calling object.

---

## ✅ Why Const Member Functions Are CRITICAL

Without them:

* ❌ Const objects are unreadable
* ❌ APIs become unsafe
* ❌ You break const-correctness
* ❌ No support for safe references & pointers

With them:

* ✅ Safe read-only access
* ✅ Better compiler protection
* ✅ Clean and professional design
* ✅ Industry standard C++ practice

---

## ✅ Best Practice Rule (Interview Gold)

> ✅ **Every function that does NOT modify the object MUST be marked `const`.**
> ❌ **Every function that modifies the object must NOT be `const`.**

---

## ✅ Real-World Use Cases

* Game engines (safe object sharing)
* APIs and SDKs
* Embedded systems
* Multi-threaded applications
* Competitive programming
* Financial systems (HFT, trading bots)

---

## ✅ Pros & Cons

### ✅ Pros

* Enforces immutability
* Prevents bugs
* Enables const references & pointers
* Improves performance (no copies)
* Required for clean API design

### ❌ Cons

* Requires discipline
* Forgetting `const` breaks usability
* Needs consistent design

---

## ✅ One-Line Final Summary

> **Const member functions allow `const` objects to be safely read without allowing modifications.**

---

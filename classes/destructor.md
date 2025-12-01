
---

# 🐶 **Destructors in C++ — Complete Notes**

### 📌 **Definition**

A **Destructor** is a special member function of a class that is **automatically called when an object is destroyed**.
Its purpose is to free resources such as **dynamic memory, file handles, network connections**, etc.

<img width="1401" height="748" alt="Screenshot 2025-12-01 141243" src="https://github.com/user-attachments/assets/e3d4662c-98a0-41c1-b558-0531a8e6012a" />

---

### 🔥 **Syntax**

```cpp
~ClassName();
```

* Uses **tilde (~)** before class name.
* Has **no return type**.
* Cannot have **parameters**.
* Only **one destructor** allowed per class (no overloading).

---

### 👇 When is a Destructor Called?

| Situation                                  | Destructor Called?                         | Reason                |
| ------------------------------------------ | ------------------------------------------ | --------------------- |
| Local object goes out of scope             | ✔                                          | Stack cleanup         |
| `delete` on dynamically allocated object   | ✔                                          | Release heap memory   |
| Temporary object ends                      | ✔                                          | Lifetime ends         |
| Object returned by value (function return) | ⚠ may or may not depending on optimization | RVO / NRVO            |
| Program exits `main()`                     | ✔                                          | All objects destroyed |

---

### 🚨 Why is Destructor Important?

Especially needed when:

✔ Class allocates **dynamic memory** using `new`
✔ Objects acquire resources that must be **manually released**

If not handled → leads to **memory leaks 💀**

---

# 📍 Example Demonstrating Destructor Behavior

```cpp
#include <iostream>
#include <string_view>

class Dog {
public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);
    ~Dog(); // Destructor

private:
    std::string name;
    std::string breed;
    int *p_age{nullptr}; // dynamically allocated
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
    : name(name_param), breed(breed_param) {
    
    p_age = new int;       // allocate memory on heap
    *p_age = age_param;
    std::cout << "Dog constructor called for " << name << std::endl;
}

Dog::~Dog() {
    delete p_age; // releasing memory
    std::cout << "Dog destructor called for : " << name << std::endl;
}

void some_func() {
    Dog* p_dog = new Dog("Fluffy", "Shepherd", 2);
    delete p_dog;  // Destructor invoked here
}

int main() {
    some_func();
    std::cout << "Done!" << std::endl;
}
```

---

### 🧠 Execution Flow

1. `some_func()` creates a `Dog` object using `new`
   → Constructor runs
2. `delete p_dog;`
   → Destructor runs (memory freed)
3. `main()` prints **Done!**

🟩 **Output**

```
Dog constructor called for Fluffy
Dog destructor called for : Fluffy
Done!
```

---

### ⚠️ Important Notes

| Rule                                                           | Explanation          |
| -------------------------------------------------------------- | -------------------- |
| Destructor cannot be overloaded                                | Only one per class   |
| Always free heap memory inside destructor                      | else → memory leak   |
| Destructor runs automatically except on `new` objects          | must call `delete`   |
| Good practice → use **smart pointers instead of raw pointers** | avoids manual delete |

---

# 💡 In Short

> Destructor = Cleanup function for an object.
> Essential when using `new`.
> Prevents memory leaks and resource loss.

---

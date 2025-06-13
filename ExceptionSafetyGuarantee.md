
---

````markdown
# 🔐 Exception Safety Guarantees in C++

When writing code that may throw exceptions, C++ defines **four levels of safety** to describe how safely your code can handle exceptions.

---

## ✅ Why Exception Safety Guarantees Matter

- Predictable behavior during exceptions
- Safe object states after errors
- Better resource management (`RAII`, smart pointers)
- Cleaner error handling without leaks

> **Exception safety isn't about preventing exceptions — it’s about ensuring your program remains valid and safe when exceptions happen.**

---

## 🚦 **The 4 Exception Safety Guarantees (Best to Worst)**

| Level | What It Means |
|-------|----------------|
| **1️⃣ No-Throw Guarantee** | Will never throw exceptions |
| **2️⃣ Strong Guarantee**   | If an exception occurs, state remains unchanged |
| **3️⃣ Basic Guarantee**    | Object remains valid, but may be changed |
| **4️⃣ No Guarantee**       | Object may be corrupted if exception occurs |

---

## ✅ **1️⃣ No-Throw Guarantee (`noexcept`)**

**Definition:**  
The function guarantees it will never throw.

```cpp
// ❌ Violation Example
// void closeFile(std::ofstream& file) noexcept {
//     file.close();  // ⚠️ Might throw!
// }

// ✅ Correct Version
void closeFile(std::ofstream& file) noexcept {
    try {
        file.close();
    } catch (...) {
        // Log or silently handle to maintain noexcept
    }
}
````

**Another Example:**

```cpp
#include <iostream>
#include <vector>

void no_throw_clear(std::vector<int>& v) noexcept {
    v.clear();  // `clear` is noexcept
}

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    no_throw_clear(vec);
    std::cout << "Size after clear: " << vec.size() << std::endl;
    return 0;
}
```

✅ **Use cases:**

* Destructors
* `swap` functions
* `clear` methods on STL containers

---

## ✅ **2️⃣ Strong Exception Guarantee**

**Definition:**
If an exception is thrown, the program state remains **unchanged** — like a transaction.

👉 **"Commit or rollback"**
✅ **Technique:** Copy-and-Swap Idiom

```cpp
// ❌ Violation
void addElement(std::vector<std::string>& v, const std::string& s) {
    v.push_back(s);  // May throw → partial change
}

// ✅ Correct
void addElement(std::vector<std::string>& v, const std::string& s) {
    std::vector<std::string> temp = v;  // Copy
    temp.push_back(s);                   // Risky on copy
    v = std::move(temp);                 // Commit
}
```

**Example:**

```cpp
#include <iostream>
#include <string>

class StrongSafe {
    std::string data;
public:
    void set(const std::string& new_value) {
        std::string temp = new_value;  // May throw
        data.swap(temp);                // Commit
    }

    void print() { std::cout << "Data: " << data << std::endl; }
};

int main() {
    StrongSafe obj;
    try {
        obj.set("Hello");
        obj.print();
        obj.set("World");
        obj.print();
    } catch (...) {
        std::cout << "Unhandled Exception\n";
    }
    return 0;
}
```

---

## ✅ **3️⃣ Basic Exception Guarantee**

**Definition:**
If an exception is thrown, the object remains **valid**, but may be **modified**.

```cpp
// ❌ Violation
void transfer(int& from, int& to, int amount) {
    from -= amount;
    if (amount > 100) throw std::runtime_error("Limit exceeded");
    to += amount;
}

// ✅ Correct
void transfer(int& from, int& to, int amount) {
    if (amount > 100) throw std::runtime_error("Limit exceeded");
    from -= amount;
    to += amount;
}
```

**Example:**

```cpp
#include <iostream>
#include <vector>

class BasicSafe {
    std::vector<int> data;
public:
    void add(int value) {
        data.push_back(value);  // May throw
    }

    void print() {
        for (int v : data) std::cout << v << " ";
        std::cout << std::endl;
    }
};

int main() {
    BasicSafe obj;
    try {
        obj.add(10);
        obj.add(20);
        obj.add(30);
        obj.print();
    } catch (...) {
        std::cout << "Exception caught\n";
    }
    return 0;
}
```

---

## ✅ **4️⃣ No Guarantee**

**Definition:**
No promises — object may be corrupted if an exception occurs.

**⚠️ Example:**

```cpp
class Risky {
    int* arr;
public:
    void resize(int newSize) {
        delete[] arr;           // Release old memory
        arr = new int[newSize]; // May throw → now `arr` is dangling!
    }
};
```

**Safer with RAII:**

```cpp
#include <iostream>
#include <stdexcept>

class Unsafe {
    int* ptr = nullptr;
public:
    void reset(int size) {
        delete[] ptr;
        ptr = new int[size];  // May throw → dangling if failed!
    }

    ~Unsafe() {
        delete[] ptr;
    }
};

int main() {
    Unsafe obj;
    try {
        obj.reset(5);
        obj.reset(-1);  // Undefined or throws bad_alloc
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
```

---

## ✅ **Key Takeaways**

| Guarantee        | Description               | Risk Level  | How to Achieve                     |
| ---------------- | ------------------------- | ----------- | ---------------------------------- |
| **No-Throw**     | Never throws              | ✅ Safe      | `noexcept`, RAII, safe types       |
| **Strong**       | Rollback, no state change | ✅ Safe      | Copy-and-Swap, transactional logic |
| **Basic**        | Valid state, may change   | ⚠️ Medium   | STL containers usually             |
| **No Guarantee** | May corrupt state         | ❌ Dangerous | Manual memory, unsafe code         |

---

## ✅ **Best Practices**

* Prefer `noexcept` for destructors, move constructors, `swap()`
* Use RAII and smart pointers to manage resources
* Favor **Strong** or **Basic** guarantees
* STL containers provide at least Basic Guarantee

**RAII:** Bind resource lifetime to an object’s lifetime — allocate in constructor, release in destructor.

---

## 🎓 **FAQ**

**Q: What happens if `noexcept` is violated?**
➡️ Leads to `std::terminate()`.

**Q: Which STL containers offer strong guarantees?**
➡️ Most offer at least **Basic**, some operations like `std::vector::push_back` have **Strong** under certain conditions.

---

## ✅ **Strong vs Basic Guarantee**

| Feature          | Strong Guarantee         | Basic Guarantee |
| ---------------- | ------------------------ | --------------- |
| **State Change** | None if exception thrown | May change      |
| **Validity**     | Always valid             | Always valid    |
| **Rollback**     | Yes                      | No              |

```cpp
// ✅ Strong: Copy first, assign after
void safeAssign(std::string& a, const std::string& b) {
    std::string temp = b;
    a = std::move(temp);
}

// ⚠️ Basic: Risky direct assignment
void riskyAssign(std::string& a, const std::string& b) {
    a = b;  // If throws, 'a' may be changed
}
```

---

**✨ *Use guarantees to write safe, robust C++!***

```

---


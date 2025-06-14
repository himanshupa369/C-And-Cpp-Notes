

---

## ✅ **C++ Callback Functions – Interview Questions with Answers**

---

### 🔹 1. **What is a callback function in C++?**

**Answer:**
A **callback function** is a function that is **passed as an argument** to another function and is **invoked (called back)** at a later time.

It enables **custom behavior** to be injected into generic code.

---

### 🔹 2. **How can we implement a callback in C++?**

**Answer:**
There are **3 main ways**:

1. **Function pointer**
2. **Function object (functor)**
3. **Lambda expression**

---

### 🔹 3. **Example using function pointer as a callback:**

```cpp
void greet() {
    std::cout << "Hello, callback!\n";
}

void execute(void (*func)()) {
    func(); // callback here
}

int main() {
    execute(greet); // passing function
    return 0;
}
```

---

### 🔹 4. **What are the disadvantages of using function pointers for callbacks?**

**Answer:**

* **Type-unsafe** (e.g., wrong signature passed)
* Can't carry state (no data members)
* Not compatible with capturing lambdas
* Harder to use with templates and polymorphism

---

### 🔹 5. **How can we use lambda as a callback function?**

**Answer:**

```cpp
void runCallback(const std::function<void()> &callback) {
    callback();
}

int main() {
    runCallback([](){ std::cout << "Lambda callback!\n"; });
}
```

✅ This is **type-safe**, allows capturing variables, and is widely used in modern C++.

---

### 🔹 6. **What is `std::function` and why is it preferred in callbacks?**

**Answer:**
`std::function` is a **polymorphic function wrapper** that can store any callable (function pointer, functor, or lambda).

It is:

* Type-safe
* Can store stateful lambdas
* Used in APIs, event handlers, multithreading, etc.

---

### 🔹 7. **Can member functions be used as callbacks?**

**Answer:**
Yes, but you need to use:

* `std::bind`, or
* Lambdas capturing `this` pointer

Example:

```cpp
class A {
public:
    void say() { std::cout << "Callback from class\n"; }
};

int main() {
    A a;
    auto cb = std::bind(&A::say, &a);
    cb();  // invokes a.say()
}
```

---

### 🔹 8. **What are some real-world uses of callback functions?**

**Answer:**

* **Event handling** (e.g., button click)
* **Custom sorting (`std::sort`)**
* **Asynchronous programming (e.g., thread completion)**
* **Signal-slot systems (e.g., Qt framework)**
* **Interfacing with C libraries**

---

### 🔹 9. **What is the difference between callback and function pointer?**

| Feature     | Callback                           | Function Pointer           |
| ----------- | ---------------------------------- | -------------------------- |
| Concept     | Higher-level pattern               | Language feature           |
| Includes    | Lambdas, std::function, bind, etc. | Just a pointer to function |
| Flexibility | High                               | Low                        |
| Type safety | High (`std::function`)             | Low                        |

---

### 🔹 10. **Can callback functions be templated?**

**Answer:**
Yes, templates allow passing callbacks of any type.

```cpp
template<typename Func>
void apply(Func f) {
    f();
}

int main() {
    apply([](){ std::cout << "Generic callback\n"; });
}
```

---

## ⚠️ Callback Best Practices

| Practice                    | Reason                                 |
| --------------------------- | -------------------------------------- |
| Use `std::function`         | Type-safety and flexibility            |
| Avoid raw function pointers | Error-prone and outdated               |
| Use lambdas where possible  | Cleaner and capture support            |
| Watch for object lifetime   | Don’t capture `this` if object may die |

---


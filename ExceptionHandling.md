

---

## ✅ BASIC INTERVIEW QUESTIONS

### 1. **What is exception handling in C++?**

**Answer:** Exception handling is a mechanism to handle **runtime errors** using:

* `try` block → code that may throw an exception
* `throw` → to throw an exception
* `catch` → to handle the thrown exception

---

### 2. **Syntax Example:**

```cpp
try {
    throw 10;
} catch (int e) {
    std::cout << "Caught: " << e;
}
```

---

### 3. **What types of exceptions can be thrown in C++?**

* Built-in types (e.g., `int`, `char`, `std::string`)
* Objects (user-defined classes)
* Standard exceptions (`std::runtime_error`, `std::out_of_range`, etc.)

---

### 4. **What is the base class for standard exceptions?**

**Answer:**
`std::exception` is the base class for all standard C++ exceptions.

---

## ✅ INTERMEDIATE LEVEL

### 5. **Can you catch all exceptions in C++?**

**Yes**, using an **ellipsis catch block**:

```cpp
try {
    // risky code
} catch (...) {
    std::cout << "Caught unknown exception";
}
```

---

### 6. **What is stack unwinding in C++?**

When an exception is thrown, the destructors of all **local objects in the call stack** are automatically called to release resources.

---

### 7. **What is RAII and how is it related to exception safety?**

RAII (Resource Acquisition Is Initialization) ensures that resources are released automatically via destructors, providing **exception-safe code**.

---

### 8. **Can a constructor throw an exception?**

✅ Yes! But if it does, the destructor won’t be called (because object construction wasn’t completed).

---

### 9. **What is the difference between `throw;` and `throw e;` in catch block?**

```cpp
catch (...) {
    throw;  // Re-throws the current exception (preserves original type/info)
}
```

---

## ✅ ADVANCED + TRICKY

### 10. **What happens if an exception is thrown but not caught?**

The program terminates by calling `std::terminate()`.

---

### 11. **Can destructors throw exceptions?**

No! It’s strongly discouraged. If a destructor throws during stack unwinding, it calls `std::terminate()`.

---

### 12. **What are custom/user-defined exceptions?**

Create a class that inherits from `std::exception` and override `what()`:

```cpp
class MyError : public std::exception {
public:
    const char* what() const noexcept override {
        return "My custom exception";
    }
};
```

---

### 13. **Can exceptions be disabled in C++?**

Yes, by compiling with `-fno-exceptions` (GCC/Clang). But then you can’t use `try`, `throw`, `catch`.

---

### 14. **How is `noexcept` used in exception handling?**

```cpp
void func() noexcept;  // Promise: this function won't throw

// If it throws despite noexcept, std::terminate() is called
```

---

### 15. **What is exception specification?**

Old C++98/03 supported:

```cpp
void f() throw(int, double); // Only throws int or double
```

But now **deprecated**. Use `noexcept` instead.

---

### 16. **Difference between `std::bad_alloc` and `std::bad_cast`?**

| Exception Type      | Thrown When                            |
| ------------------- | -------------------------------------- |
| `std::bad_alloc`    | `new` fails (out of memory)            |
| `std::bad_cast`     | Invalid `dynamic_cast` with references |
| `std::out_of_range` | Access beyond container bounds         |

---

## ✅ Practical Code-Based Question

### Q: Write code to handle division by zero safely.

```cpp
double safe_divide(double a, double b) {
    if (b == 0)
        throw std::runtime_error("Divide by zero");
    return a / b;
}

int main() {
    try {
        std::cout << safe_divide(5, 0);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what();
    }
}
```

---

## ✅ Summary Table

| Concept             | Keyword          |
| ------------------- | ---------------- |
| Start of risky code | `try`            |
| Throw exception     | `throw`          |
| Handle exception    | `catch`          |
| Base class          | `std::exception` |
| Catch-all           | `catch (...)`    |
| Prevent throwing    | `noexcept`       |

---



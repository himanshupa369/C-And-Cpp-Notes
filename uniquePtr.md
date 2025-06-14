

---

## ✅ Interview Questions on `unique_ptr` in C++

---

### 🔹 1. **What is `std::unique_ptr` in C++?**

**Answer:**
`std::unique_ptr` is a **smart pointer** that **owns and manages** a dynamically allocated object and **deletes it automatically** when the `unique_ptr` goes out of scope.
Ownership is **unique** — only one `unique_ptr` can own a resource at a time.

---

### 🔹 2. **How is `unique_ptr` different from `shared_ptr`?**

| Feature   | `unique_ptr`        | `shared_ptr`                 |
| --------- | ------------------- | ---------------------------- |
| Ownership | Single              | Shared (reference counted)   |
| Copyable  | ❌ No                | ✅ Yes                        |
| Overhead  | Minimal             | Higher (due to ref counting) |
| Use case  | Exclusive ownership | Shared ownership             |

---

### 🔹 3. **How do you create a `unique_ptr`?**

```cpp
std::unique_ptr<int> p1(new int(10));        // Old way
auto p2 = std::make_unique<int>(20);         // Recommended (C++14+)
```

---

### 🔹 4. **Can you copy a `unique_ptr`?**

**Answer:**
❌ No. `unique_ptr` **cannot be copied** — ownership is exclusive.

```cpp
std::unique_ptr<int> a = std::make_unique<int>(5);
std::unique_ptr<int> b = a;  // ❌ Compile error
```

---

### 🔹 5. **How do you transfer ownership of a `unique_ptr`?**

**Answer:**
Use `std::move()` to transfer ownership:

```cpp
std::unique_ptr<int> a = std::make_unique<int>(5);
std::unique_ptr<int> b = std::move(a);  // OK
```

After move:

* `a` is null
* `b` now owns the resource

---

### 🔹 6. **What happens when a `unique_ptr` goes out of scope?**

**Answer:**
The managed object is automatically deleted using its deleter.

---

### 🔹 7. **What is `make_unique` and why is it better than `new`?**

**Answer:**
`std::make_unique<T>(args...)`:

* Is safer (prevents memory leaks on exceptions)
* Is shorter and cleaner
* Introduced in C++14

Example:

```cpp
auto ptr = std::make_unique<MyClass>(arg1, arg2);
```

---

### 🔹 8. **Can `unique_ptr` work with custom deleters?**

**Answer:**
Yes. Example with a custom deleter:

```cpp
auto deleter = [](FILE* f) { if (f) fclose(f); };
std::unique_ptr<FILE, decltype(deleter)> fptr(fopen("data.txt", "r"), deleter);
```

---

### 🔹 9. **Can you use `unique_ptr` with arrays?**

**Answer:**
Yes, but you must use:

```cpp
std::unique_ptr<int[]> arr(new int[10]);
```

or in C++20:

```cpp
std::make_unique<int[]>(10);
```

---

### 🔹 10. **What is the syntax to access members of an object via `unique_ptr`?**

```cpp
std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
ptr->method();     // Access method
(*ptr).field;      // Access member variable
```

---

## ⚠️ Common Pitfalls

| Mistake                                  | Fix                                 |
| ---------------------------------------- | ----------------------------------- |
| Copying a `unique_ptr`                   | Use `std::move()`                   |
| Forgetting to use `std::make_unique`     | Prefer it over `new`                |
| Using raw pointers with no ownership     | Avoid mixed raw/smart pointer usage |
| Forgetting custom deleters for FILE etc. | Always use a `lambda` deleter       |

---

## 🧠 Advanced Questions

### 🔸 11. **Can a `unique_ptr` be stored in a container like `std::vector`?**

✅ Yes, but you must use `std::move` when inserting:

```cpp
std::vector<std::unique_ptr<MyClass>> vec;
vec.push_back(std::make_unique<MyClass>());
```

---

### 🔸 12. **Can `unique_ptr` be used with incomplete types?**

✅ Yes — as long as the **destructor is not used** in the header where the type is incomplete.

---

### 🔸 13. **Why use `unique_ptr` instead of raw pointer?**

* Prevents memory leaks
* Cleaner, safer code
* Automatic resource management
* Integrates with STL and exception-safe

---

## ✅ Final Rapid-Fire Quiz

| Question                                | Answer                    |
| --------------------------------------- | ------------------------- |
| Can `unique_ptr` be copied?             | ❌ No                      |
| Can `unique_ptr` be moved?              | ✅ Yes                     |
| Is `make_unique` preferred?             | ✅ Yes                     |
| Does `unique_ptr` automatically delete? | ✅ Yes                     |
| Can `unique_ptr` be used for arrays?    | ✅ Yes (`unique_ptr<T[]>`) |

---

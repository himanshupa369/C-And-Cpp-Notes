
---

# 🧠 What is a Memory Leak?

A **memory leak** happens when:

* You allocate memory dynamically using `new` (on the **heap**),
* But you **lose all pointers (references)** to that memory **before calling `delete`**.

➡️ The memory remains allocated (unusable), even though your program can’t access it anymore.
➡️ The OS will reclaim it when your program ends, but in **long-running processes**, leaks can cause:

* Increased RAM usage
* Slowdowns
* Crashes (when heap is exhausted)

---

# ⚙️ Memory Leak Conditions in Your Code

Let’s examine the **three situations** demonstrated.

---

## 🧩 Case 1 — Pointer Reassignment Before Delete

```cpp
int *p_number {new int{67}}; // address1 (heap)
int number{55};              // address2 (stack)
p_number = &number;          // now points to address2
```

### 🔍 What happens:

1. `new int{67}` allocates memory on the heap (say, at address1).
2. You store that address in `p_number`.
3. Then, `p_number` is reassigned to point to `number` (a stack variable at address2).
4. The program **loses the only pointer** to address1 — the heap block is **unreachable**.
5. ❌ Memory Leak: `int{67}` is never `delete`d.

✅ **Fix:**

```cpp
delete p_number;
p_number = nullptr;
p_number = &number;
```

---

## 🧩 Case 2 — Double Allocation (Overwriting Pointer)

```cpp
int *p_number1 {new int{55}};  // addressA
p_number1 = new int{44};       // addressB
```

### 🔍 What happens:

1. You allocate heap memory for `55` (addressA).
2. Then, you allocate **again**, overwriting the pointer with a new address (addressB).
3. The pointer to addressA is lost forever — another **leak**.

✅ **Fix:**
Always `delete` before overwriting:

```cpp
delete p_number1;   // free old memory
p_number1 = new int{44};
```

✅ Even better — set it to `nullptr` after deleting:

```cpp
delete p_number1;
p_number1 = nullptr;
```

---

## 🧩 Case 3 — Scope-based Leak (Missing Delete Before Scope Ends)

```cpp
{
    int *p_number2 {new int{57}};
    std::cout << *p_number2 << std::endl;
} // p_number2 goes out of scope here
```

### 🔍 What happens:

* Inside the block, `p_number2` is a local pointer.
* It’s destroyed automatically when the block ends.
* But the memory allocated on the heap (`new int{57}`) **still exists**.
* Since no pointer references it anymore — the memory is leaked.

✅ **Fix:**
Call `delete` before exiting the scope:

```cpp
{
    int *p_number2 {new int{57}};
    std::cout << *p_number2 << std::endl;
    delete p_number2;
    p_number2 = nullptr;
}
```

---

# 🧾 Summary Table — Memory Leak Conditions

| Condition                              | Description                                     | Example                           | Fix                                    |
| -------------------------------------- | ----------------------------------------------- | --------------------------------- | -------------------------------------- |
| **Pointer reassignment before delete** | Old heap memory becomes unreachable             | `p = new int; p = &x;`            | `delete p; p = &x;`                    |
| **Double allocation**                  | New allocation overwrites pointer to old memory | `p = new int{1}; p = new int{2};` | `delete p; p = new int{2};`            |
| **Leaving scope without delete**       | Pointer destroyed but heap memory remains       | `{ int* p = new int; }`           | `delete p;`                            |
| **Forgot to call delete at all**       | Heap memory never freed                         | `int* p = new int(10);`           | `delete p;`                            |
| **Exception before delete**            | Program exits scope before cleanup              | Throwing before `delete`          | Use smart pointers (`std::unique_ptr`) |

---

# 🧰 Tools & Modern Solutions

To **avoid leaks**, modern C++ strongly encourages:

### ✅ Smart Pointers

Use **RAII (Resource Acquisition Is Initialization)** — resources automatically cleaned up when going out of scope.

```cpp
#include <memory>

{
    std::unique_ptr<int> p = std::make_unique<int>(57);
    std::cout << *p << std::endl;
} // automatically freed here, no leak
```

---

# ⚙️ How to Detect Memory Leaks

### 🧪 Tools:

* **Valgrind** (Linux):

  ```bash
  valgrind --leak-check=full ./a.out
  ```
* **Visual Studio**:
  Use **CRT Debug Heap** or **Diagnostic Tools** → Memory Usage.
* **Address Sanitizer (ASan)**:
  Compile with:

  ```bash
  g++ -fsanitize=address -g file.cpp
  ./a.out
  ```

---

# 🧩 Summary Diagram (Conceptual Flow)

```
+--------------------+        +------------------------+
| Stack (automatic)  |        | Heap (dynamic memory)  |
| int *p = new int;  | -----> |  [int value]           |
+--------------------+        +------------------------+
            ↑                          |
            | (delete p)               |
            +--------------------------+
```

If `delete p` is skipped or pointer lost → memory leak.

---

# 🧠 Key Takeaways

* Heap memory must always be manually released with `delete` (or `delete[]`).
* Losing all pointers to an allocated block → **leak**.
* Reassigning pointers or letting them go out of scope without cleanup causes leaks.
* Prefer **smart pointers** to handle this automatically.

---

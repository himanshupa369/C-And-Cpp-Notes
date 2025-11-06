
---

# 🌀 **C++ For Loops — Complete Notes**

---

## 🧠 **1. What is a For Loop?**

A **for loop** in C++ is a **control flow structure** used to execute a block of code **multiple times**.
It’s ideal for **repetitive tasks**, such as iterating over arrays, printing sequences, or performing calculations repeatedly.

---

## 🧩 **2. Syntax**

```cpp
for(initialization; condition; increment){
    // Loop body (statements to be repeated)
}
```

---

## 🏗️ **3. Pillars of Any Loop**

Every loop (including `for`, `while`, `do-while`) is built upon **five essential pillars**:

| Pillar                    | Description                                                  |
| ------------------------- | ------------------------------------------------------------ |
| **Iterator**              | Variable that controls loop progression.                     |
| **Starting Point**        | The initial value assigned to the iterator.                  |
| **Test (Condition)**      | Expression that decides whether the loop continues or stops. |
| **Increment / Decrement** | Step that updates the iterator each iteration.               |
| **Loop Body**             | The actual work to be done inside the loop.                  |

### Example:

```cpp
for(size_t i{0}; i < 10; ++i){
    std::cout << i << " : I love C++" << std::endl;
}
```

---

## ⚙️ **4. Step-by-Step Flow**

1. **Initialization** — runs once before the loop starts.
2. **Condition** — checked before every iteration.
3. **Body** — executes if the condition is true.
4. **Increment/Decrement** — updates the iterator.
5. **Repeat** until condition becomes false.

---

## 📘 **5. Using `size_t` in Loops**

`size_t` is **not a new type** — it’s a **type alias** for an **unsigned integer type** chosen by the compiler to represent object sizes.

### 💡 Definition:

```cpp
typedef unsigned int size_t;          // On 32-bit systems
typedef unsigned long long size_t;    // On 64-bit systems
```

### ✅ Use Case:

* Representing **sizes**, **lengths**, or **counts**
* Returned by `sizeof()`, STL containers like `vector::size()`, and functions like `strlen()`

### Example:

```cpp
for(size_t i{0}; i < 5; ++i){
    std::cout << "Iteration: " << i << std::endl;
}
```

### 🧾 Note:

> `size_t` ensures safe, platform-independent representation of size-related values — always non-negative.

---

## 🧱 **6. Scope of the Loop Variable**

### 🔹 Scoped Within the Loop

A variable declared in the initialization part of the `for` loop is **only visible inside that loop’s body**.

```cpp
for(size_t i{0}; i < 10; ++i){
    std::cout << i << std::endl; // ✅ OK
}
std::cout << i << std::endl;     // ❌ ERROR: 'i' not in scope
```

### ✅ To Use It Outside:

Declare the variable **before** the loop:

```cpp
size_t i{0};
for(; i < 10; ++i){
    std::cout << i << std::endl;
}
std::cout << "Final i = " << i << std::endl; // ✅ Works fine
```

### 📘 Remember:

> The lifetime (scope) of the iterator begins at its declaration and ends at the closing brace `}` of the loop block.

---

## ⚙️ **7. Example Program**

```cpp
#include <iostream>

int main() {
    const size_t COUNT{5};

    for(size_t i{0}; i < COUNT; ++i){
        std::cout << i << " : I love C++" << std::endl;
    }

    std::cout << "Loop done!" << std::endl;

    return 0;
}
```

**Output:**

```
0 : I love C++
1 : I love C++
2 : I love C++
3 : I love C++
4 : I love C++
Loop done!
```

---

## 🧩 **8. Infinite Loop Example**

```cpp
for(;;){
    std::cout << "Running forever..." << std::endl;
}
```

⚠️ Use only when intentional (e.g., servers, event loops, embedded systems).

---

## 🧠 **9. Summary Table**

| Concept                 | Description                                       |
| ----------------------- | ------------------------------------------------- |
| **Iterator**            | Controls the number of loop iterations            |
| **Starting Point**      | Initial value before first check                  |
| **Condition**           | Stops the loop when false                         |
| **Increment/Decrement** | Changes iterator each time                        |
| **Loop Body**           | Code that repeats                                 |
| **Scope**               | Iterator visible only inside loop block           |
| **size_t**              | Unsigned type alias for representing sizes safely |

---

## 💎 **10. Best Practices**

✅ Use `size_t` for non-negative counters or array indexing
✅ Keep loop code simple and readable
✅ Prefer braces `{}` even for one-line bodies
✅ Avoid hardcoding constants — use `const` variables
✅ Be careful with scope of the loop variable
✅ Avoid signed/unsigned mix-ups in comparisons

---

### 🏁 **Key Takeaway**

> A `for` loop in C++ rests on five strong pillars —
> **Iterator, Starting Point, Test, Increment/Decrement, and Loop Body**.
>
> Use `size_t` as a safe, portable counter type,
> and always remember: **loop variables are scoped inside the loop**.

---


---

## 🧠 **1. What is a For Loop?**

A **for loop** in C++ is a **control flow structure** used to execute a block of code **multiple times**.

It’s ideal for **repetitive tasks** (e.g., printing something 10 times, iterating over arrays, etc.)

---

## 🧩 **2. Syntax**

```cpp
for(initialization; condition; increment){
    // Loop body (statements to be repeated)
}
```

### Breakdown of Parts:

| Part                   | Description                                                                                  |
| ---------------------- | -------------------------------------------------------------------------------------------- |
| **Initialization**     | Declares and initializes the loop variable (iterator). Runs **once** before the loop starts. |
| **Condition**          | Checked **before each iteration**. If `true`, the loop runs; if `false`, the loop stops.     |
| **Increment / Update** | Runs **after each iteration** to modify the iterator (e.g., `++i`).                          |
| **Loop Body**          | Contains the statements to repeat while the condition is true.                               |

---

## ⚙️ **3. Basic Example**

```cpp
for(unsigned int i{0}; i < 10; ++i){
    std::cout << i << " : I love C++" << std::endl;
}
std::cout << "Loop done!" << std::endl;
```

🧾 **Explanation:**

* Start → `i = 0`
* Test → Is `i < 10`?

  * ✅ Yes → execute loop body, print message
  * 🔁 Increment `i` (`++i`)
  * Repeat until `i = 10`
* When `i = 10` → test fails → loop ends → next statements execute.

---

## 💡 **4. Why Use Loops?**

Without loops, repetitive code must be written manually:

❌ **Bad way:**

```cpp
std::cout << "I love C++" << std::endl;
std::cout << "I love C++" << std::endl;
// ...
```

✅ **Good way (using for loop):**

```cpp
for(int i{0}; i < 10; ++i)
    std::cout << "I love C++" << std::endl;
```

---

## 🧮 **5. Using `size_t` as the Iterator Type**

`size_t` is a **platform-dependent unsigned integer type** (usually 8 bytes on 64-bit systems).
It is used for representing **sizes and counts** — values that can never be negative.

### Example:

```cpp
for(size_t i{0}; i < 10; ++i){
    std::cout << i << " : I love C++" << std::endl;
}
```

✅ `size_t` is preferred for:

* Array indexing
* Container sizes
* Counting iterations

### Check its size:

```cpp
std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl;
```

Example output:

```
sizeof(size_t) : 8
```

---

## 🧭 **6. Scope of the Loop Variable**

* The **iterator declared inside the `for` loop** is **scoped only inside the loop**.
* You **cannot use it outside** the loop’s closing brace.

### Example (❌ Error)

```cpp
for(size_t i{0}; i < 10; ++i){
    std::cout << i << std::endl;
}
std::cout << i << std::endl; // ❌ ERROR: 'i' not declared in this scope
```

✅ **Fix — Declare outside the loop:**

```cpp
size_t i{0};  // Iterator declared outside
for(i; i < 10; ++i){
    std::cout << i << std::endl;
}
std::cout << "Final i = " << i << std::endl; // Works!
```

---

## 🧱 **7. Leaving Out the Declaration Part**

If you already declared the iterator outside, you can omit it inside the loop:

```cpp
size_t i{0};
for(; i < 10; ++i){
    std::cout << i << " : I love C++" << std::endl;
}
```

This is valid and sometimes useful, but **less common** for clarity reasons.

---

## ⚠️ **8. Avoid Hardcoding Values**

❌ **Bad Design:**

```cpp
for(size_t i{0}; i < 10; ++i){ ... }
```

✅ **Better Design:**

```cpp
const size_t COUNT{10};

for(size_t i{0}; i < COUNT; ++i){
    std::cout << i << " : I love C++" << std::endl;
}
```

**Benefits:**

* Only one place to change the loop limit.
* Easier to maintain and reuse code.

---

## 🔄 **9. Changing Loop Range**

You can start and stop at any values, not just from 0.

```cpp
for(size_t i{30}; i <= 55; ++i){
    std::cout << i << std::endl;
}
```

This prints numbers from 30 to 55 inclusive.

---

## 🧱 **10. Loop Without Braces**

If the loop body contains **only one statement**, braces `{}` are optional.

```cpp
for(size_t i{0}; i < 5; ++i)
    std::cout << "I love C++" << std::endl;
```

✅ Works fine, but ⚠️ **recommended** to always use braces for readability and safety.

---

## ⚙️ **11. How a For Loop Works (Step-by-Step)**

1. **Initialization** — executed once (e.g., `size_t i{0};`)
2. **Condition** — checked before every iteration (`i < 10`)
3. **Body** — executes if condition is true
4. **Increment** — modifies iterator (`++i`)
5. **Repeat** → go back to step 2
6. **Exit** → when condition becomes false

---

## 🧩 **12. Infinite Loops**

You can make a loop run forever if the condition never fails.

```cpp
for(;;){
    std::cout << "Running forever..." << std::endl;
}
```

⚠️ Use only when intentional (e.g., servers, embedded systems).

---

## 🧠 **13. Summary Table**

| Part               | Example               | Runs                  | Description                |
| ------------------ | --------------------- | --------------------- | -------------------------- |
| **Initialization** | `size_t i{0}`         | Once                  | Creates loop variable      |
| **Condition**      | `i < COUNT`           | Before each iteration | Stops loop when false      |
| **Increment**      | `++i`                 | After each iteration  | Moves loop forward         |
| **Body**           | `{ std::cout << i; }` | Repeatedly            | Code executed each time    |
| **Scope**          | Inside `{}`           | —                     | Variable only visible here |

---

## 💎 **14. Best Practices**

✅ Use `size_t` for counting and sizes (non-negative integers).
✅ Avoid hardcoding constants — use `const` variables.
✅ Keep loops clean and readable.
✅ Prefer braces `{}` even for single-line bodies.
✅ Don’t access iterator outside its scope unless needed.
✅ Use meaningful names (e.g., `index`, `count`, `i`) for clarity.

---

## 🧰 **15. Example — Complete Program**

```cpp
#include <iostream>

int main(){
    const size_t COUNT{10};

    for(size_t i{0}; i < COUNT; ++i){
        std::cout << i << " : I love C++" << std::endl;
    }

    std::cout << "Loop done!" << std::endl;

    return 0;
}
```

**Output:**

```
0 : I love C++
1 : I love C++
...
9 : I love C++
Loop done!
```

---

### 🏁 **Key Takeaway**

> A `for` loop in C++ is made of **five conceptual parts**:
> **Iterator**, **Starting Point**, **Test (Condition)**, **Incrementation**, and **Loop Body**.
>
> Mastering this structure gives you the foundation for **all kinds of iteration logic** — from simple counting to complex data traversal.

---

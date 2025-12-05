### 📌 Boundary Alignment in Object Size (C++ OOPs)

**Boundary Alignment** (or **memory alignment**) refers to how data members of a class/struct are arranged in memory so that each member starts at an address that is a multiple of its natural alignment size.

---

### 🔥 Why Alignment Exists?

The CPU reads memory most efficiently when data is stored at addresses it can fetch in fixed word-size chunks (like 4 or 8 bytes).
If members are not naturally aligned, the compiler **inserts padding bytes** to maintain alignment → this directly affects **object size**.

---

### 🧠 Alignment Rules

1. Every data type has an *alignment boundary* (1,2,4,8... bytes)
2. Each member of a class/struct is placed on memory at a boundary suitable for its size
3. Compiler may insert extra bytes (*padding*) between members or at the end
4. Final object size becomes **total data + internal padding + end padding**

---

### Example 1 — Mis-Ordered Members = Bigger Object

```cpp
struct A {
    char a;   // 1 byte
    int  b;   // 4 bytes
    char c;   // 1 byte
};
```

Memory layout (with padding):

| Member  | Size | Alignment | Actual occupied |
| ------- | ---- | --------- | --------------- |
| a       | 1B   | 1         | 1B              |
| padding | —    | —         | 3B              |
| b       | 4B   | 4         | 4B              |
| c       | 1B   | 1         | 1B              |
| padding | —    | —         | 3B              |

📌 **Total size = 12 bytes (not 6 bytes)**

---

### Example 2 — Properly Ordered Members = Smaller Object

```cpp
struct B {
    int  b;   // 4
    char a;   // 1
    char c;   // 1
};
```

Now layout:

| Member  | Size                    | Actual |
| ------- | ----------------------- | ------ |
| b       | 4B                      |        |
| a       | 1B                      |        |
| c       | 1B                      |        |
| padding | 2B   (end padding only) |        |

📌 **Total size = 8 bytes (memory efficient)**

Ordering larger types first reduces padding → better packing.

---

### ➤ Object Size Formula

```
Object Size = Sum of (member size + padding)
Alignment = size of largest member
```

---

### Key Points to Remember

| Concept           | Meaning                                       |
| ----------------- | --------------------------------------------- |
| Alignment         | Members stored at addresses optimal for CPU   |
| Padding           | Extra bytes inserted for alignment            |
| Natural Alignment | Member stored at address multiple of its size |
| Largest Member    | Defines overall object alignment boundary     |

---

### 💡 Why it Matters in OOP and Systems?

✔ Optimizes performance (faster CPU access)
✔ Affects `sizeof(object)`
✔ Important in low-level modules, game engines, HFT, memory-critical systems
✔ Helps in designing efficient structures/classes

---


# 🔥 `#pragma pack` in C++

`#pragma pack` is used to **change the default memory alignment of structure/class members**.
This allows struct members to be packed tightly with **reduced (sometimes zero) padding**.

> ⚠️ Useful in memory-critical applications, but misalignment may slow down performance.

---

### 📌 Example Without `#pragma pack`

```cpp
#include <iostream>

struct Normal {
    char a;   //1
    int  b;   //4
    char c;   //1
};

int main() {
    std::cout << sizeof(Normal) << std::endl; // Output: 12 (padding inserted)
}
```

---

### 📌 With `#pragma pack(1)`

```cpp
#include <iostream>
#pragma pack(push,1)     // Force 1-byte alignment

struct Packed {
    char a;   //1
    int  b;   //4 (stored without padding)
    char c;   //1
};

#pragma pack(pop)       // Restore default packing

int main() {
    std::cout << sizeof(Packed) << std::endl; // Output: 6 (No padding)
}
```

✔ Memory reduced from **12 bytes → 6 bytes**
⚠ Could be **slower on some architectures** due to misaligned access.

---

# 🚀 Packing & Alignment Tricks (Interview-Useful)

---

### 🔹 Trick 1 — Always order data members from largest → smallest

Bad (more padding):

```cpp
struct S {
    char c;
    double d;
    int i;
};
```

Good (less padding):

```cpp
struct S_opt {
    double d;
    int i;
    char c;
};
```

---

### 🔹 Trick 2 — Use grouping of small types

```cpp
struct Compact {
    int  a;
    char b, c, d, e; // small types grouped → no padding inside
};
```

---

### 🔹 Trick 3 — Using `alignas()` for custom alignment

```cpp
#include <iostream>

struct alignas(16) Vec4 {
    float x, y, z, w;
};

int main() {
    std::cout << sizeof(Vec4) << std::endl; // 16 bytes, aligned to 16 boundary
}
```

Useful in SIMD, GPU programming, game engines.

---

### 🔹 Trick 4 — `#pragma pack` only when necessary

✔ Embedded systems
✔ Network protocols
✔ File format headers
❗ Avoid for compute-heavy objects (can reduce performance)

---

### 🔹 Trick 5 — Padding is also added at end of object

When largest member is 8 bytes → object size rounded to multiple of **8**.

```cpp
struct Sample {
    double x;  // 8B
    char   y;  // 1B
};
// sizeof(Sample) == 16 (not 9)
```

---

### 🔥 Quick Summary Table

| Feature  | Normal Alignment | `#pragma pack(1)`       |
| -------- | ---------------- | ----------------------- |
| Padding  | Yes              | No/Minimal              |
| Speed    | Fast             | Can be slower           |
| Memory   | Larger           | Smaller                 |
| Use case | General OOP      | Low-level data transfer |

---
# 📘 Notes — Size of Class/Struct Objects in C++

### 1. Object size depends on member variables only

In C++, `sizeof(object)` returns the memory footprint of the **member variables inside the object**, *not* including:

| Counted                                   | Not counted                  |
| ----------------------------------------- | ---------------------------- |
| Data members (variables inside the class) | Member functions             |
| Padding + alignment bytes                 | Dynamically allocated memory |
| Pointer variables (just size of pointer)  | Data the pointer points to   |

✔ Functions belong to the **class**, not each object → they do **not** increase object size.

---

## 📌 Example

```cpp
class Dog{
public:
    Dog() = default;
    void prin_info(){}
    void do_something(){}

private:
    size_t leg_count;  // 8 bytes
    size_t arm_count;  // 8 bytes
    int* p_age;        // 8 bytes (only pointer counted, not what it points to)
};
```

```cpp
Dog dog1;
std::cout << sizeof(dog1);  // Output → 24 bytes
```

### Why **24 bytes**?

```
leg_count    -> 8 bytes
arm_count    -> 8 bytes
p_age pointer-> 8 bytes
------------------------
Total        → 24 bytes
```

---

# 🔥 Strings and pointer-based members

```cpp
std::string name{"I am the king of the universe!"};
std::cout << sizeof(name);    // commonly 24 or 32 bytes depending on system
```

Even if string length changes — the `sizeof(string)` remains same!

### Because a string stores:

```
pointer to char data   → fixed size
size of string         → integer stored inside object
capacity allocated     → integer stored inside object
```

Only these fields are counted — **not the actual text stored on heap**.

---

# 🧠 Key Concepts

| Concept                                      | Meaning                             |
| -------------------------------------------- | ----------------------------------- |
| **Size of object = sum of member variables** | Not functions                       |
| **Pointers only contribute pointer size**    | Not what they point to              |
| **std::string has fixed size**               | Content lives in heap               |
| **Dynamic memory doesn’t contribute**        | `sizeof()` ignores heap allocations |

---

# Alignment & Padding (Important)

Sometimes total size ≠ simple sum → due to **boundary alignment**.

📌 CPUs read memory faster if variables start at aligned boundaries (e.g., 4/8 bytes).

Compilers insert **padding bytes** to achieve this.

Example:

```cpp
struct Example {
    char a;     // 1 byte
    int b;      // requires 4-byte alignment
};
```

Memory layout:

| a | padding | b(4 bytes) |
| - | ------- | ---------- |

`sizeof(Example)` → 8 bytes (not 5)

---

# Final Takeaways

✔ `sizeof()` counts size of variables inside object
❗ Does NOT count function size or allocated string storage
🔹 String always has fixed size regardless of text length
⚙ Alignment may increase size due to padding

---

# `#pragma once` in C++

`#pragma once` is a **header guard directive** used to ensure a header file is included **only once** during compilation.

### Why do we need it?

When multiple files include the same header file — directly or indirectly — the compiler may try to include it repeatedly, causing:

✔ redefinition errors
✔ multiple symbol definitions
✔ longer compile time

`#pragma once` prevents this.

---

### 📌 Syntax

```cpp
// MyHeader.h
#pragma once

class MyClass {
public:
    void show();
};
```

This guarantees this file will be included only once, even if:

```
A.cpp → includes MyHeader.h
B.cpp → includes MyHeader.h
main.cpp → includes A.h + B.h → both include MyHeader.h
```

👉 Still included only one time.

---

# Without `#pragma once` (Traditional Header Guards)

```cpp
#ifndef MYHEADER_H
#define MYHEADER_H

class MyClass {
public:
    void show();
};

#endif
```

Both do the same job — but `#pragma once` is:

| Feature          | `#pragma once`     | `#ifndef HEADER`          |
| ---------------- | ------------------ | ------------------------- |
| Easy to type     | ✔ very easy        | ❌ needs macro name        |
| Error-proof      | ✔ avoids typo      | ❌ depends on unique macro |
| Standard C++     | ❌ not in standard  | ✔ standard                |
| Compiler support | ✔ widely supported | ✔ universal               |

💡 Almost every modern compiler supports `#pragma once`.

---

### When to use which?

| Prefer `#pragma once` when     | Prefer `#ifndef/#define` when       |
| ------------------------------ | ----------------------------------- |
| Fast development               | Maximum portability (old compilers) |
| Big projects with many headers | Working on embedded/legacy systems  |

> In 99% of modern C++ projects — **`#pragma once` is preferred**.

---



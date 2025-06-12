### 🧠 **Structure Padding vs Union  in C++**

#### 📌 **Padding** is the extra unused bytes added by the compiler to align data in memory according to CPU architecture, improving access speed.

---

### 🧱 1. **Structure Padding**

In a **`struct`**, each member is placed in memory in **sequence**, and **padding** may be added between them to align them properly.

#### ✅ Example:

```cpp
#include <iostream>
using namespace std;

struct MyStruct {
    char a;    // 1 byte
    int b;     // 4 bytes
    char c;    // 1 byte
};

int main() {
    cout << "Size of MyStruct: " << sizeof(MyStruct) << endl;
    return 0;
}
```

#### 🧾 Memory Layout:

```
| a | _ _ _ | b b b b | c | _ _ _ |
         ↑        ↑        ↑
     padding  aligned  padding
```

* Likely total size: **12 bytes** (depends on compiler/architecture)

---

### 🤝 2. **Union: No Padding Between Members**

In a **`union`**, **all members share the same memory location**, so only the size of the **largest member** is used.
No padding is needed between members because only **one member is active at a time**.

#### ✅ Example:

```cpp
#include <iostream>
using namespace std;

union MyUnion {
    char a;    // 1 byte
    int b;     // 4 bytes
    char c;    // 1 byte
};

int main() {
    cout << "Size of MyUnion: " << sizeof(MyUnion) << endl;
    return 0;
}
```

* Size: **4 bytes** (size of `int` — the largest member)

---

### ⚖️ **Comparison Table**

| Feature           | `struct`                        | `union`                       |
| ----------------- | ------------------------------- | ----------------------------- |
| Memory Allocation | Separate memory for each member | Shared memory for all members |
| Padding           | Yes, for alignment              | No padding between members    |
| Size              | Sum of members + padding        | Size of largest member        |
| Use Case          | Store multiple values together  | Store one value at a time     |

---

### 🧪 Check Padding with `pragma pack` (to remove padding):

```cpp
#pragma pack(1) // disable padding
struct PackedStruct {
    char a;
    int b;
    char c;
};
```

* This will reduce the size but **may reduce performance** on some CPUs due to unaligned access.

---


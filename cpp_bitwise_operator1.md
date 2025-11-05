
---

# ⚙️ Bitwise Operators & Bit Shifting in C++

---

## 🔹 Introduction

Bitwise operators allow you to manipulate **individual bits** of integral types (`int`, `char`, `short`, `long`, etc.).
They are often used in **low-level programming**, **embedded systems**, **optimization**, and **bitmasking**.

---

## 🔹 Supported Types

✅ Bitwise operations are **only supported for integral types**:
`int`, `char`, `short`, `long`, `long long`, and their unsigned versions.

❌ Not supported for:
`float`, `double`, or user-defined types.

---

## 🔹 Bitwise Operators Overview

| Operator | Description | Example  | Meaning                              |    |                             |
| -------- | ----------- | -------- | ------------------------------------ | -- | --------------------------- |
| `&`      | AND         | `a & b`  | Bit is 1 if both bits are 1          |    |                             |
| `        | `           | OR       | `a                                   | b` | Bit is 1 if either bit is 1 |
| `^`      | XOR         | `a ^ b`  | Bit is 1 if bits differ              |    |                             |
| `~`      | NOT         | `~a`     | Inverts bits (1→0, 0→1)              |    |                             |
| `<<`     | Left Shift  | `a << n` | Shifts bits **left by n** positions  |    |                             |
| `>>`     | Right Shift | `a >> n` | Shifts bits **right by n** positions |    |                             |

---

## 🔹 Bitwise Shifting

### 🔸 Left Shift (`<<`)

* Shifts all bits to the **left** by `n` positions.
* Vacant bits on the **right** are filled with **0s**.
* Equivalent to multiplying the number by `2ⁿ`.
* ⚠️ **Overflow** can occur if bits are shifted beyond the data size — data is lost permanently.

### 🔸 Right Shift (`>>`)

* Shifts all bits to the **right** by `n` positions.
* Vacant bits on the **left** are filled with **0s** (for unsigned) or **sign bit** (for signed).
* Equivalent to dividing the number by `2ⁿ`.

---

## 🔹 ⚠️ Important Rule

> If data is lost during bit shifting, you **cannot recover it** by reversing the operation —
> once bits are shifted out, they’re **gone forever**.

---

## 🔹 Example 1 — Displaying Number in Different Formats

```cpp
#include <iostream>
#include <bitset>

int main() {
    unsigned short int data {20};

    std::cout << "data (dec) : " <<std::showbase <<  std::dec << data << std::endl;
    std::cout << "data (oct) : " <<std::showbase <<  std::oct << data << std::endl;
    std::cout << "data (hex) : " <<std::showbase <<  std::hex << data << std::endl;
    std::cout << "data (bin) : " << std::bitset<16>(data) << std::endl;

    return 0;
}
```

### 🔹 Output:

```
data (dec) : 20
data (oct) : 024
data (hex) : 0x14
data (bin) : 0000000000010100
```

✅ Here, the number `20` is represented as binary `00000000000000010100` (20 bits).
You can visualize how shifting will affect each bit.

---

## 🔹 Example 2 — Bit Shifting Demonstration

```cpp
#include <iostream>
#include <bitset>

int main() {
    unsigned short int value {0xff0u};  // Binary: 0000 1111 1111 0000

    std::cout << "Size of short int: " << sizeof(short int) << " bytes\n"; // 2 bytes → 16 bits

    std::cout << "Initial value : " << std::bitset<16>(value)
              << " , dec : " << value << std::endl;

    // Shift left by 1 bit (multiply by 2)
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "Left shift 1 : " << std::bitset<16>(value)
              << " , dec : " << value << std::endl;

    // Repeated left shifts
    value = static_cast<unsigned short int>(value << 1);
    std::cout << "Left shift 2 : " << std::bitset<16>(value)
              << " , dec : " << value << std::endl;

    value = static_cast<unsigned short int>(value << 1);
    std::cout << "Left shift 3 : " << std::bitset<16>(value)
              << " , dec : " << value << std::endl;

    value = static_cast<unsigned short int>(value << 1);
    std::cout << "Left shift 4 : " << std::bitset<16>(value)
              << " , dec : " << value << std::endl;

    // Shift right by one bit (divide by 2)
    value = static_cast<unsigned short int>(value >> 1);
    std::cout << "Right shift 1: " << std::bitset<16>(value)
              << " , dec : " << value << std::endl;

    // Shift right by multiple bits (divide by 2⁴)
    value = static_cast<unsigned short int>(value >> 4);
    std::cout << "Right shift 4: " << std::bitset<16>(value)
              << " , dec : " << value << std::endl;

    return 0;
}
```

---

## 🔹 Example Output (Approx.)

```
Size of short int: 2 bytes
Initial value : 0000111111110000 , dec : 4080
Left shift 1 : 0001111111100000 , dec : 8160
Left shift 2 : 0011111111000000 , dec : 16320
Left shift 3 : 0111111110000000 , dec : 32640
Left shift 4 : 1111111100000000 , dec : 65280
Right shift 1: 0111111110000000 , dec : 32640
Right shift 4: 0000011111111000 , dec : 2040
```

---

## 🔹 Bit Shift Math Interpretation

| Operation    | Effect         | Example                |
| ------------ | -------------- | ---------------------- |
| `value << 1` | Multiply by 2  | 10 (1010) → 20 (10100) |
| `value << n` | Multiply by 2ⁿ | 5 << 3 = 5 × 8 = 40    |
| `value >> 1` | Divide by 2    | 20 (10100) → 10 (1010) |
| `value >> n` | Divide by 2ⁿ   | 40 >> 3 = 5            |

---

## 🔹 Bit Size Limitations

> Bit shifting is **not defined for types smaller than 8 bits** (e.g., `bool` or `char` on some systems).
> The compiler usually promotes such values to `int` before performing shifts.

---

## 🧠 Summary Table

| Concept                | Description                                                  |                          |
| ---------------------- | ------------------------------------------------------------ | ------------------------ |
| **Bitwise operators**  | Manipulate bits directly (`&`, `                             | `, `^`, `~`, `<<`, `>>`) |
| **Left shift (`<<`)**  | Multiplies by 2ⁿ (may lose data on overflow)                 |                          |
| **Right shift (`>>`)** | Divides by 2ⁿ (may lose data on underflow)                   |                          |
| **Data loss**          | Once shifted out, bits are **permanently lost**              |                          |
| **Unsigned types**     | Shifting fills empty bits with 0                             |                          |
| **Signed types**       | Right shift behavior depends on compiler (may keep sign bit) |                          |

---

✅ **Quick Tip:**
Use `std::bitset<N>(value)` to visualize the binary form of any number while debugging bitwise operations.

---

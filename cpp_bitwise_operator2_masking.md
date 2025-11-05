
---

# 🧠 Bit Masking and Bitwise Operations in C++

---

## 🔹 What is a **Bit Mask**?

A **bit mask** is a binary number used to **select**, **modify**, or **check** specific bits in another number.

Each bit in the mask represents whether we want to affect the **corresponding bit** in the target variable.

✅ **Example:**

```cpp
unsigned char mask_bit_3 = 0b00001000; // Bit 3 is ON, others are OFF
```

This mask can be used to operate only on **bit 3** of another variable.

---

## 🔹 Common Bit Masks for 8-bit Variables

| Bit | Mask (binary) | Decimal | Example Constant |
| --- | ------------- | ------- | ---------------- |
| 0   | `00000001`    | 1       | `mask_bit_0`     |
| 1   | `00000010`    | 2       | `mask_bit_1`     |
| 2   | `00000100`    | 4       | `mask_bit_2`     |
| 3   | `00001000`    | 8       | `mask_bit_3`     |
| 4   | `00010000`    | 16      | `mask_bit_4`     |
| 5   | `00100000`    | 32      | `mask_bit_5`     |
| 6   | `01000000`    | 64      | `mask_bit_6`     |
| 7   | `10000000`    | 128     | `mask_bit_7`     |

---

## 🔹 Bitwise Assignment Operators Used in Masking

| Operator   | Name                   | Meaning                        |                             |
| ---------- | ---------------------- | ------------------------------ | --------------------------- |
| `          | =`                     | Bitwise OR assignment          | Set (turn ON) specific bits |
| `&=`       | Bitwise AND assignment | Reset (turn OFF) specific bits |                             |
| `^=`       | Bitwise XOR assignment | Toggle (flip) specific bits    |                             |
| `&` + `>>` | Bitwise AND + Shift    | Check if a bit is ON or OFF    |                             |

---

## 🔹 1. Setting (Turning ON) a Bit

To **set** a bit (make it `1`), use:

```cpp
var |= mask;
```

**Example:**

```cpp
var |= mask_bit_1; // Turn ON bit 1
```

✅ Explanation:

* `|=` ensures that the specified bit is **forced to 1**, no matter what its previous state was.

---

## 🔹 2. Resetting (Turning OFF) a Bit

To **reset** a bit (make it `0`), use:

```cpp
var &= ~mask;
```

**Example:**

```cpp
var &= ~mask_bit_5; // Turn OFF bit 5
```

✅ Explanation:

* `~mask` flips all bits in the mask (1 becomes 0, and 0 becomes 1).
* `&=` keeps all bits the same **except** the one being reset (set to 0).

---

## 🔹 3. Toggling (Flipping) a Bit

To **toggle** (invert) a bit, use:

```cpp
var ^= mask;
```

**Example:**

```cpp
var ^= mask_bit_0; // Flip bit 0 (0→1 or 1→0)
```

✅ Explanation:

* XOR (`^`) with 1 flips the bit, and XOR with 0 leaves it unchanged.

---

## 🔹 4. Checking Whether a Bit is Set

To **check** if a bit is ON or OFF, use:

```cpp
bool isSet = (var & mask) >> bit_position;
```

or simply:

```cpp
bool isSet = (var & mask);
```

**Example:**

```cpp
bool bit3 = (var & mask_bit_3);  // true if bit 3 is ON
```

✅ Explanation:

* `&` isolates the bit of interest.
* If that bit is 1, the result is nonzero → **true**.

---

## 🔹 5. Setting or Resetting Multiple Bits Together

You can combine multiple masks using `|` or `&`:

**Set multiple bits:**

```cpp
var |= (mask_bit_0 | mask_bit_2 | mask_bit_4);
```

**Reset multiple bits:**

```cpp
var &= ~(mask_bit_0 | mask_bit_2 | mask_bit_4);
```

**Toggle multiple bits:**

```cpp
var ^= (mask_bit_7 | mask_bit_6 | mask_bit_5 | mask_bit_4);
```

---

## 🔹 6. Checking All Bit States Example

```cpp
std::cout << "bit0: " << ((var & mask_bit_0) >> 0) << std::endl;
std::cout << "bit1: " << ((var & mask_bit_1) >> 1) << std::endl;
std::cout << "bit2: " << ((var & mask_bit_2) >> 2) << std::endl;
```

* Here, `(var & mask_bit_N)` isolates bit `N`.
* Shifting right by `N` gives a `0` or `1` result directly.

---

## 🔹 Example Output (Step by Step)

| Operation          | Result (binary) | Description         |
| ------------------ | --------------- | ------------------- |
| Initial `var`      | `00000000`      | All bits off        |
| Set bit 1          | `00000010`      | Bit 1 ON            |
| Set bit 5          | `00100010`      | Bit 5 ON            |
| Reset bit 1        | `00100000`      | Bit 1 OFF           |
| Set all bits       | `11111111`      | All bits ON         |
| Reset bits 0,2,4,6 | `10101010`      | Alternate bits OFF  |
| Toggle bit 0       | `10101011`      | Bit 0 flipped       |
| Toggle bit 7       | `00101011`      | Bit 7 flipped       |
| Toggle bits 4–7    | `11001011`      | Higher bits flipped |

---

## 🧩 Summary Table

| Operation      | Operator Used | Example               | Description          |                |               |
| -------------- | ------------- | --------------------- | -------------------- | -------------- | ------------- |
| **Set bit**    | `             | =`                    | `var                 | = mask_bit_1;` | Turn ON bit 1 |
| **Reset bit**  | `&= ~`        | `var &= ~mask_bit_1;` | Turn OFF bit 1       |                |               |
| **Toggle bit** | `^=`          | `var ^= mask_bit_7;`  | Flip bit 7           |                |               |
| **Check bit**  | `&`           | `(var & mask_bit_3)`  | Check if bit 3 is ON |                |               |

---

## 💡 Key Notes

* **Bit masking** is crucial for **low-level programming**, **embedded systems**, and **bitwise optimization**.
* Operates fastest on **unsigned** integers (e.g., `unsigned char`, `unsigned int`).
* Avoid using bitwise operations on **floating-point** types or **signed** integers (may cause undefined behavior due to sign bits).

---

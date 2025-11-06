
---

# 🎨 Packing Color Using Bitwise Operators in C++

---

## 🔹 Concept

A **color** is usually represented by 3 components:

* **Red (R)**
* **Green (G)**
* **Blue (B)**

Each component is typically **8 bits (1 byte)** — i.e., values from `0` to `255`.

That means we can combine them into a single **32-bit integer** like this:

```
Bits: [00000000][RRRRRRRR][GGGGGGGG][BBBBBBBB]
```

* Bit 24–31 → Alpha (optional, transparency)
* Bit 16–23 → Red
* Bit 8–15  → Green
* Bit 0–7   → Blue

---

## 🔹 Packing RGB into a 32-bit Integer

We can combine R, G, and B using **bitwise shifts** and **OR** (`|`):

### ✅ Example Code

```cpp
#include <iostream>
#include <iomanip>
#include <bitset>

int main() {
    unsigned char red   = 0xAA; // 170 in decimal
    unsigned char green = 0xBB; // 187 in decimal
    unsigned char blue  = 0xCC; // 204 in decimal

    // Pack R, G, B into one 32-bit integer
    unsigned int color = 0;

    color |= (red << 16);   // Move Red to bits 16–23
    color |= (green << 8);  // Move Green to bits 8–15
    color |= blue;          // Blue stays in bits 0–7

    std::cout << std::hex << std::showbase;
    std::cout << "Packed Color (hex): " << color << std::endl;
    std::cout << "Packed Color (binary): " << std::bitset<32>(color) << std::endl;

    return 0;
}
```

### 🧾 Output

```
Packed Color (hex): 0xaabbcc
Packed Color (binary): 00000000101010101011101111001100
```

✅ Meaning:

```
Red   = AA (170)
Green = BB (187)
Blue  = CC (204)
```

---

## 🔹 Unpacking the Color Back into RGB

We can extract (unpack) each color by using **bitwise AND (&)** and **bit shifting (>>) operations**.

### ✅ Example Code

```cpp
#include <iostream>
#include <iomanip>

int main() {
    unsigned int color = 0xAABBCC; // Packed color

    unsigned char red   = (color >> 16) & 0xFF; // Mask and shift to extract red
    unsigned char green = (color >> 8)  & 0xFF; // Mask and shift to extract green
    unsigned char blue  = color & 0xFF;         // Mask for blue (no shift needed)

    std::cout << std::hex << std::showbase;
    std::cout << "Red   : " << static_cast<int>(red) << std::endl;
    std::cout << "Green : " << static_cast<int>(green) << std::endl;
    std::cout << "Blue  : " << static_cast<int>(blue) << std::endl;

    return 0;
}
```

### 🧾 Output

```
Red   : 0xaa
Green : 0xbb
Blue  : 0xcc
```

---

## 🔹 With Alpha Channel (RGBA)

We can add **Alpha (A)** (transparency) as an extra 8 bits.

### ✅ Example Code

```cpp
#include <iostream>
#include <bitset>

int main() {
    unsigned char alpha = 0xFF; // 255 (fully opaque)
    unsigned char red   = 0x11; // 17
    unsigned char green = 0x22; // 34
    unsigned char blue  = 0x33; // 51

    unsigned int color = 0;
    color |= (alpha << 24);
    color |= (red << 16);
    color |= (green << 8);
    color |= blue;

    std::cout << std::hex << std::showbase;
    std::cout << "Packed RGBA: " << color << std::endl;
    std::cout << "Binary : " << std::bitset<32>(color) << std::endl;

    // Unpack
    unsigned char a = (color >> 24) & 0xFF;
    unsigned char r = (color >> 16) & 0xFF;
    unsigned char g = (color >> 8) & 0xFF;
    unsigned char b = color & 0xFF;

    std::cout << "\nUnpacked Channels:" << std::endl;
    std::cout << "A = " << static_cast<int>(a)
              << ", R = " << static_cast<int>(r)
              << ", G = " << static_cast<int>(g)
              << ", B = " << static_cast<int>(b)
              << std::endl;

    return 0;
}
```

---

## 🔹 How the Bitwise Operators Work Here

| Operation | Description                                                          |                                                 |
| --------- | -------------------------------------------------------------------- | ----------------------------------------------- |
| `<< n`    | Shifts bits left by `n` positions (moves to higher bit slots).       |                                                 |
| `         | `                                                                    | Combines bits using OR — merges color channels. |
| `& mask`  | Extracts specific bits using a binary mask (e.g. `0xFF` = 11111111). |                                                 |
| `>> n`    | Shifts bits right by `n` positions (brings the desired bits down).   |                                                 |

---

## 🔹 Visual Representation (Packing RGB)

| Channel | 8 bits     | Position   |
| ------- | ---------- | ---------- |
| Red     | `RRRRRRRR` | bits 16–23 |
| Green   | `GGGGGGGG` | bits 8–15  |
| Blue    | `BBBBBBBB` | bits 0–7   |

Final 32-bit color:

```
00000000 RRRRRRRR GGGGGGGG BBBBBBBB
```

---

## 🧩 Summary Table

| Task                      | Operation              | Example        |     |                             |
| ------------------------- | ---------------------- | -------------- | --- | --------------------------- |
| **Pack RGB**              | `color = (r << 16)     | (g << 8)       | b;` | Combines three 8-bit values |
| **Unpack R**              | `(color >> 16) & 0xFF` | Extracts red   |     |                             |
| **Unpack G**              | `(color >> 8) & 0xFF`  | Extracts green |     |                             |
| **Unpack B**              | `color & 0xFF`         | Extracts blue  |     |                             |
| **Unpack A (if present)** | `(color >> 24) & 0xFF` | Extracts alpha |     |                             |

---

## 💡 Key Takeaways

* **Bit packing** reduces memory usage and is fast for storage or graphics.
* Each color component fits into one byte (8 bits).
* Use **unsigned types** to avoid sign-extension issues.
* Common in **graphics**, **image processing**, **network packets**, and **embedded systems**.

---

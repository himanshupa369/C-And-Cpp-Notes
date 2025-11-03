
---

## 🧩 **`<iomanip>` — Input/Output Manipulators**

The **`<iomanip>`** (Input/Output Manipulator) header in C++ provides **functions (manipulators)** that help **format the output** (and sometimes input) when using `cin`, `cout`, etc.

It stands for **“I/O manipulators”** — they let you **control how data is displayed** (width, precision, alignment, base, fill characters, etc.) without manually formatting strings.

---

## 🔹 1. Including the Header

```cpp
#include <iostream>
#include <iomanip>
using namespace std;
```

---

## 🔹 2. Commonly Used Manipulators

| Manipulator       | Description                                      | Example                                        |
| ----------------- | ------------------------------------------------ | ---------------------------------------------- |
| `setw(n)`         | Sets the **width** of the next output field      | `cout << setw(5) << 42;`                       |
| `setfill(ch)`     | Fills empty space with given character           | `cout << setfill('*') << setw(5) << 42;`       |
| `setprecision(n)` | Sets number of digits for floating-point         | `cout << setprecision(3) << 3.14159;`          |
| `fixed`           | Forces decimal notation (not scientific)         | `cout << fixed << setprecision(2) << 3.14159;` |
| `scientific`      | Displays number in scientific (exponential) form | `cout << scientific << 12345.678;`             |
| `left`            | Left-aligns output in field                      | `cout << left << setw(10) << "C++";`           |
| `right`           | Right-aligns output in field                     | `cout << right << setw(10) << "C++";`          |
| `boolalpha`       | Displays `true/false` instead of `1/0`           | `cout << boolalpha << true;`                   |
| `noboolalpha`     | Displays `1/0` instead of `true/false`           | `cout << noboolalpha << true;`                 |
| `showbase`        | Shows base prefix (`0`, `0x`) for octal/hex      | `cout << showbase << hex << 255;`              |
| `noshowbase`      | Hides base prefix                                | `cout << noshowbase << hex << 255;`            |
| `showpos`         | Shows `+` sign for positive numbers              | `cout << showpos << 42;`                       |
| `noshowpos`       | Hides `+` sign                                   | `cout << noshowpos << 42;`                     |
| `uppercase`       | Prints hex/scientific letters in uppercase       | `cout << uppercase << hex << 255;`             |
| `nouppercase`     | Prints hex/scientific letters in lowercase       | `cout << nouppercase << hex << 255;`           |
| `dec`             | Sets base to decimal (10)                        | `cout << dec << 255;`                          |
| `oct`             | Sets base to octal (8)                           | `cout << oct << 255;`                          |
| `hex`             | Sets base to hexadecimal (16)                    | `cout << hex << 255;`                          |

---

## 🔹 3. Example Program

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n = 255;
    double pi = 3.1415926535;

    cout << "Default decimal: " << n << endl;
    cout << "Hexadecimal: " << hex << n << endl;
    cout << "Octal: " << oct << n << endl;

    cout << showbase << uppercase;  // show base prefix and use uppercase
    cout << "\nHex with showbase: " << hex << n << endl;

    cout << "\nPI with precision control:" << endl;
    cout << fixed << setprecision(2) << pi << endl;
    cout << scientific << setprecision(4) << pi << endl;

    cout << "\nWidth and fill example:" << endl;
    cout << setfill('*') << setw(10) << right << 42 << endl;
}
```

### 🧾 Output:

```
Default decimal: 255
Hexadecimal: ff
Octal: 377

Hex with showbase: 0XFF

PI with precision control:
3.14
3.1416e+00

Width and fill example:
********42
```

---

## 🔹 4. Notes

* Manipulators **affect only the next output** (like `setw`) or remain **persistent** (like `hex`, `showbase`) until changed back.
* Combine multiple manipulators for fine control over formatting.
* `std::fixed` and `std::setprecision()` are often used together for decimal formatting.

---

## ✅ **Summary Table**

| Category           | Manipulators                                          |
| ------------------ | ----------------------------------------------------- |
| **Number base**    | `dec`, `oct`, `hex`, `showbase`, `noshowbase`         |
| **Floating-point** | `fixed`, `scientific`, `setprecision(n)`              |
| **Alignment**      | `left`, `right`, `internal`, `setw(n)`, `setfill(ch)` |
| **Boolean**        | `boolalpha`, `noboolalpha`                            |
| **Sign & case**    | `showpos`, `noshowpos`, `uppercase`, `nouppercase`    |

---


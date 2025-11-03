
---

## 🧩 **Numeric Constants and Their Representations in C++**

In C++, **literals (constants)** can be written in different **bases (number systems)** or **types** by using **specific prefixes and suffixes**.

---

### 🔹 **1. Integer Literals**

You can represent integers in **four different number systems**:

| Number System   | Prefix Used             | Example           | Base    | Meaning                       |
| --------------- | ----------------------- | ----------------- | ------- | ----------------------------- |
| **Decimal**     | *(no prefix)*           | `int a = 10;`     | Base 10 | Normal numbers                |
| **Octal**       | `0` (zero)              | `int b = 012;`    | Base 8  | 0 × 8² + 1 × 8¹ + 2 × 8⁰ = 10 |
| **Hexadecimal** | `0x` or `0X`            | `int c = 0xA;`    | Base 16 | 10 in decimal                 |
| **Binary**      | `0b` or `0B` *(C++14+)* | `int d = 0b1010;` | Base 2  | 10 in decimal                 |

#### ✅ Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int dec = 10;      // Decimal
    int oct = 012;     // Octal (prefix 0)
    int hex = 0xA;     // Hexadecimal (prefix 0x)
    int bin = 0b1010;  // Binary (prefix 0b, C++14+)

    cout << "Decimal: " << dec << endl;
    cout << "Octal: " << oct << endl;
    cout << "Hexadecimal: " << hex << endl;
    cout << "Binary: " << bin << endl;
}
```

🧾 **Output:**

```
Decimal: 10
Octal: 10
Hexadecimal: 10
Binary: 10
```

---

### 🔹 **2. Floating-Point Literals**

Floating-point numbers can include:

* A **decimal point (.)**, or
* An **exponent (e or E)** part.

#### ✅ Example:

```cpp
float a = 3.14f;       // 'f' or 'F' → float
double b = 3.14;       // no suffix → double (default)
long double c = 3.14L; // 'L' or 'l' → long double
```

| Type            | Suffix     | Example                  | Notes                            |
| --------------- | ---------- | ------------------------ | -------------------------------- |
| **float**       | `f` or `F` | `float x = 1.23f;`       | 4 bytes                          |
| **double**      | *(none)*   | `double y = 1.23;`       | 8 bytes (default for decimals)   |
| **long double** | `l` or `L` | `long double z = 1.23L;` | 10–16 bytes (platform-dependent) |

---

### 🔹 **3. Exponential (Scientific) Notation**

You can use **`e`** or **`E`** to represent numbers with exponents (powers of 10).

#### ✅ Example:

```cpp
double val1 = 3.45e2;   // 3.45 × 10² = 345
double val2 = 1.2E-3;   // 1.2 × 10⁻³ = 0.0012
```

🧠 **Useful for:** large or very small floating-point numbers.

---

### 🔹 **4. Using Underscores for Readability (C++14+)**

C++14 introduced **digit separators** (underscore `_`) for better readability:

```cpp
int num = 1'000'000;     // same as 1000000
double pi = 3.141'592'653;  // improves clarity
```

---

### 🔹 **5. Combining Modifiers**

You can combine **base prefixes** and **type suffixes** for clarity:

| Example    | Meaning                                    |
| ---------- | ------------------------------------------ |
| `0xFFu`    | Hexadecimal **unsigned int**               |
| `0b1010L`  | Binary **long**                            |
| `1234UL`   | Unsigned long                              |
| `45.67F`   | Float literal                              |
| `12.34e2L` | Long double literal in scientific notation |

---

### ✅ **Summary Table**

| Category    | Example                  | Prefix/Suffix | Type          |
| ----------- | ------------------------ | ------------- | ------------- |
| Decimal     | `int a = 25;`            | —             | `int`         |
| Octal       | `int b = 031;`           | `0`           | `int`         |
| Hexadecimal | `int c = 0x1F;`          | `0x` / `0X`   | `int`         |
| Binary      | `int d = 0b1010;`        | `0b` / `0B`   | `int`         |
| Float       | `float e = 3.14f;`       | `f` / `F`     | `float`       |
| Double      | `double f = 3.14;`       | —             | `double`      |
| Long Double | `long double g = 3.14L;` | `l` / `L`     | `long double` |
| Scientific  | `double h = 1.2e3;`      | `e` / `E`     | `double`      |

---

### 🔹 **Quick Example Program**

```cpp
#include <iostream>
using namespace std;

int main() {
    int dec = 10;
    int oct = 012;
    int hex = 0xA;
    int bin = 0b1010;
    float f = 3.14f;
    double d = 3.14;
    long double ld = 3.14L;

    cout << "Decimal: " << dec << "\n";
    cout << "Octal: " << oct << "\n";
    cout << "Hexadecimal: " << hex << "\n";
    cout << "Binary: " << bin << "\n";
    cout << "Float: " << f << "\n";
    cout << "Double: " << d << "\n";
    cout << "Long Double: " << ld << "\n";
}
```

---

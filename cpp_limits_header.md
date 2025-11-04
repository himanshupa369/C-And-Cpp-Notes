
---

# ⚙️ **`#include <limits>` in C++**

---

## 🔹 **What It Is**

`<limits>` is a **C++ standard header** that provides **information about the properties of arithmetic types** — like their **minimum and maximum possible values**, precision, and special characteristics.

It defines the **class template `std::numeric_limits<T>`**, which allows you to query **type limits** (for `int`, `float`, `double`, `char`, etc.) **at compile time**.

---

## 🔹 **Header Syntax**

```cpp
#include <limits>
```

---

## 🔹 **Purpose**

To determine:

* The **minimum and maximum** value of a data type
* Whether a type supports **infinity** or **NaN**
* The **precision** or **digits** available in floating-point types
* Whether a type is **signed or unsigned**

---

## 🔹 **Class Template**

```cpp
template <class T>
class numeric_limits;
```

You can access properties as **static members**, like:

```cpp
std::numeric_limits<int>::max();
std::numeric_limits<float>::lowest();
std::numeric_limits<double>::epsilon();
```

---

## 🔹 **Commonly Used Members**

| Member Function | Description                                                    | Example                                          |
| --------------- | -------------------------------------------------------------- | ------------------------------------------------ |
| `max()`         | Returns the **maximum value** of type                          | `numeric_limits<int>::max()` → 2147483647        |
| `min()`         | Returns the **smallest positive** value (for integers)         | `numeric_limits<int>::min()` → -2147483648       |
| `lowest()`      | Returns the **lowest (most negative)** value                   | `numeric_limits<float>::lowest()` → -3.40282e+38 |
| `epsilon()`     | Smallest difference between 1 and the next representable value | `numeric_limits<float>::epsilon()`               |
| `infinity()`    | Returns positive infinity (for floating types)                 | `numeric_limits<float>::infinity()`              |
| `quiet_NaN()`   | Returns “Not a Number” (NaN) value                             | `numeric_limits<double>::quiet_NaN()`            |
| `is_signed`     | `true` if type is signed                                       | `numeric_limits<int>::is_signed`                 |
| `is_integer`    | `true` if type is integer                                      | `numeric_limits<int>::is_integer`                |
| `digits`        | Number of **bits** (binary digits) in the mantissa             | `numeric_limits<float>::digits`                  |
| `digits10`      | Number of **decimal digits** precision                         | `numeric_limits<double>::digits10`               |

---

## 🔹 **Example 1 — Integer Limits**

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    cout << "int min: " << numeric_limits<int>::min() << endl;
    cout << "int max: " << numeric_limits<int>::max() << endl;
    cout << "int is signed: " << numeric_limits<int>::is_signed << endl;
    return 0;
}
```

🧾 **Output:**

```
int min: -2147483648
int max: 2147483647
int is signed: 1
```

---

## 🔹 **Example 2 — Floating-Point Properties**

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    cout << "float min: " << numeric_limits<float>::min() << endl;
    cout << "float max: " << numeric_limits<float>::max() << endl;
    cout << "float lowest: " << numeric_limits<float>::lowest() << endl;
    cout << "float epsilon: " << numeric_limits<float>::epsilon() << endl;
    cout << "float infinity: " << numeric_limits<float>::infinity() << endl;
    return 0;
}
```

🧾 **Output (approx.):**

```
float min: 1.17549e-38
float max: 3.40282e+38
float lowest: -3.40282e+38
float epsilon: 1.19209e-07
float infinity: inf
```

---

## 🔹 **Example 3 — Checking for NaN**

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    double x = numeric_limits<double>::quiet_NaN();
    cout << "Is NaN supported: " << numeric_limits<double>::has_quiet_NaN << endl;
    cout << "NaN value: " << x << endl;
}
```

🧾 **Output:**

```
Is NaN supported: 1
NaN value: nan
```

---

## 🔹 **Useful Constants Summary**

| Constant      | Meaning                              | Type             |
| ------------- | ------------------------------------ | ---------------- |
| `min()`       | Minimum representable positive value | Integer/Floating |
| `max()`       | Maximum representable value          | Integer/Floating |
| `lowest()`    | Most negative finite value           | Floating         |
| `epsilon()`   | Floating-point precision             | Floating         |
| `infinity()`  | Represents ∞                         | Floating         |
| `quiet_NaN()` | Not-a-Number                         | Floating         |
| `digits`      | Binary precision                     | All              |
| `digits10`    | Decimal precision                    | All              |

---

## 🔹 **Example: Generic Range Template**

```cpp
#include <iostream>
#include <limits>
using namespace std;

template <typename T>
void showRange() {
    cout << "Type: " << typeid(T).name() << endl;
    cout << "Min: " << numeric_limits<T>::min() << endl;
    cout << "Max: " << numeric_limits<T>::max() << endl;
    cout << "Is signed: " << numeric_limits<T>::is_signed << endl;
    cout << "------------------" << endl;
}

int main() {
    showRange<int>();
    showRange<float>();
    showRange<unsigned int>();
}
```

---

## ✅ **Summary**

| Purpose            | Description                                                   |
| ------------------ | ------------------------------------------------------------- |
| **Header**         | `<limits>`                                                    |
| **Main Class**     | `std::numeric_limits<T>`                                      |
| **Use**            | To get range, precision, and special values of data types     |
| **Useful For**     | Type-safe numeric computations, preventing overflow/underflow |
| **Common Members** | `min()`, `max()`, `epsilon()`, `infinity()`, `is_signed`      |

---



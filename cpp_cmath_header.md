
---

## 🧠 Purpose:

The `<cmath>` header allows you to perform **mathematical operations** such as:

* Trigonometric
* Exponential
* Logarithmic
* Power and root
* Rounding
* Absolute value, etc.

---

## 📘 Commonly Used Functions:

| Category              | Function     | Description                       | Example            |
| --------------------- | ------------ | --------------------------------- | ------------------ |
| **Trigonometric**     | `sin(x)`     | Sine of `x` (radians)             | `sin(3.14)`        |
|                       | `cos(x)`     | Cosine of `x`                     | `cos(0)`           |
|                       | `tan(x)`     | Tangent of `x`                    | `tan(1.57)`        |
| **Inverse Trig**      | `asin(x)`    | Arc sine                          | `asin(1)`          |
|                       | `acos(x)`    | Arc cosine                        | `acos(0)`          |
|                       | `atan(x)`    | Arc tangent                       | `atan(1)`          |
| **Exponential / Log** | `exp(x)`     | eˣ                                | `exp(2)`           |
|                       | `log(x)`     | Natural log (base *e*)            | `log(2.718)`       |
|                       | `log10(x)`   | Log base 10                       | `log10(100)`       |
| **Power / Root**      | `pow(x, y)`  | xʸ                                | `pow(2, 3)` → 8    |
|                       | `sqrt(x)`    | Square root                       | `sqrt(25)` → 5     |
|                       | `cbrt(x)`    | Cube root                         | `cbrt(27)` → 3     |
| **Rounding**          | `ceil(x)`    | Round up                          | `ceil(3.2)` → 4    |
|                       | `floor(x)`   | Round down                        | `floor(3.8)` → 3   |
|                       | `round(x)`   | Round to nearest                  | `round(3.6)` → 4   |
|                       | `trunc(x)`   | Remove fractional part            | `trunc(3.9)` → 3   |
| **Absolute**          | `fabs(x)`    | Absolute value of floating number | `fabs(-5.5)` → 5.5 |
| **Min/Max**           | `fmin(x, y)` | Smallest of two                   | `fmin(3, 9)` → 3   |
|                       | `fmax(x, y)` | Largest of two                    | `fmax(3, 9)` → 9   |

---

## ⚙️ Example Program:

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 9.0;

    cout << "Square root of 9 = " << sqrt(x) << endl;
    cout << "Power (2^3) = " << pow(2, 3) << endl;
    cout << "Ceil of 4.3 = " << ceil(4.3) << endl;
    cout << "Floor of 4.7 = " << floor(4.7) << endl;
    cout << "Absolute of -9.5 = " << fabs(-9.5) << endl;
    cout << "Sine of π/2 = " << sin(M_PI / 2) << endl; // Requires #define _USE_MATH_DEFINES (on some compilers)

    return 0;
}
```

---

## 💡 Notes:

* All functions are in the **`std`** namespace (`std::sqrt()`, `std::pow()`, etc.)
* To use constants like `M_PI`, you may need:

  ```cpp
  #define _USE_MATH_DEFINES
  #include <cmath>
  ```
* Works with types `float`, `double`, `long double` through function overloading.

---



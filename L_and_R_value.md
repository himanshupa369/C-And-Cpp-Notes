
---

# L-values and R-values in C++

Understanding **L-values** and **R-values** is fundamental to mastering **references, move semantics, and performance optimization** in C++.

---

## 1. L-value (Locator Value)

### Definition

An **L-value** represents an object that:

* Has a **persistent memory location**
* Can appear on the **left-hand side** of an assignment

---

### Key Characteristics

| Feature         | Description                                       |
| --------------- | ------------------------------------------------- |
| Name            | Has a name                                        |
| Memory          | Has a stable memory address                       |
| Lifetime        | Persists beyond a single expression               |
| Assignment      | Can be assigned a value                           |
| Variables       | All named variables are L-values                  |
| Function Return | Functions returning by reference produce L-values |
| Reference Type  | Binds to **L-value references (`&`)**             |

---

### Examples

```cpp
int x = 10;      // x is an L-value
int& ref = x;   // L-value reference
```

```cpp
int& Transform(int& x) {
    return x;   // returns an L-value
}
```

---

## 2. R-value (Read Value / Temporary Value)

### Definition

An **R-value** represents a **temporary value** that:

* Does **not have a persistent memory location**
* Cannot be assigned to
* Usually appears on the **right-hand side** of an assignment

---

### Key Characteristics

| Feature         | Description                                   |
| --------------- | --------------------------------------------- |
| Name            | Does not have a name                          |
| Memory          | Temporary                                     |
| Lifetime        | Exists only within the expression             |
| Assignment      | Cannot be assigned                            |
| Expressions     | Literals, temporary results                   |
| Function Return | Functions returning by value produce R-values |
| Reference Type  | Binds to **R-value references (`&&`)**        |

---

### Examples

```cpp
5 + 3          // R-value
10             // R-value literal
Add(3, 5)      // R-value (returned by value)
```

---

## 3. L-value Reference (`&`)

### Definition

An **L-value reference** can only bind to **L-values**.

---

### Rules

* Cannot bind to temporaries
* Can modify the referenced object
* `const` L-value references can bind to R-values

---

### Examples

```cpp
int x = 10;
int& ref = x;         // OK
// int& ref2 = 10;    // ERROR

const int& cref = 10; // OK (const allows binding to R-value)
```

---

## 4. R-value Reference (`&&`) – C++11

### Definition

An **R-value reference** is a reference that binds to **temporary objects**, enabling **move semantics**.

---

### Key Characteristics

| Feature        | Description                        |
| -------------- | ---------------------------------- |
| Definition     | Reference to a temporary           |
| Syntax         | `&&`                               |
| Binds To       | Only R-values                      |
| Cannot Bind To | L-values (unless cast)             |
| Purpose        | Enable efficient resource transfer |

---

### Examples

```cpp
int&& r1 = 5 + 3;      // OK
int&& r2 = 10;         // OK

int x = 5;
// int&& r3 = x;       // ERROR (x is L-value)
```

---

## 5. `std::move` and `static_cast<int&&>`

### Purpose

Both convert an **L-value into an R-value expression**.

---

### Important Note

> **`std::move` does NOT move anything**
> It only **casts** an L-value to an R-value reference.

---

### Examples

```cpp
Print(std::move(i));            // Preferred
Print(static_cast<int&&>(i));   // Equivalent but less readable
```

✔ `std::move` is preferred for **readability and intent**

---

## 6. Function Return and Value Category

| Function Return Type | Result  |
| -------------------- | ------- |
| Return by value      | R-value |
| Return by reference  | L-value |

---

### Example

```cpp
int Add(int x, int y) {
    return x + y;   // R-value
}

int& Transform(int& x) {
    return x;       // L-value
}
```

---

## 7. Function Overloading with L and R-values

### Example

```cpp
void Print(int& x) {
    std::cout << "L-value\n";
}

void Print(const int& x) {
    std::cout << "Const L-value\n";
}

void Print(int&& x) {
    std::cout << "R-value\n";
}
```

---

### Calls

```cpp
int i = 10;

Print(i);               // L-value
Print(10);              // R-value
Print(std::move(i));    // R-value
```

---

## 8. Summary Table

### L-value vs R-value

| Feature            | L-value | R-value   |
| ------------------ | ------- | --------- |
| Has name           | Yes     | No        |
| Memory address     | Yes     | Temporary |
| Assignment allowed | Yes     | No        |
| Lifetime           | Long    | Short     |
| Reference type     | `T&`    | `T&&`     |

---

## 9. Interview One-Liners

* **L-value**: An object with identity and persistent storage.
* **R-value**: A temporary object without persistent identity.
* **R-value reference**: Enables move semantics.
* **`std::move`**: Casts L-value to R-value reference.
* **Const L-value reference**: Can bind to both L-values and R-values.

---

## 10. Key Takeaways

* Every variable is an **L-value**
* Temporaries are **R-values**
* `&&` enables **efficient moves**
* Prefer `std::move` over `static_cast`
* Value categories directly affect **performance and correctness**

---

* **Value categories (glvalue, prvalue, xvalue)**
* **Perfect forwarding**
* **Universal references**
* **Move constructor internals**

```cpp
//L value and R value
/*
| **Feature * *        | **L - value  Locator* *                                    | **R - value * *                                 |
| ------------------ - | ------------------------------------------------ - | -------------------------------------------- -  |
| **Name * *           | Has a name                                         | Does not have a name                            |
| **Variable Type * *  | All variables are L - values                       | R - value is a temporary value                  |
| **Assignment * *     | Can be assigned values                             | Cannot be assigned values                       |
| **Expressions * *    | Some expressions return L - values                 | Some expressions return R - values              |
| **Persistence * *    | Persists beyond the expression                     | Does not persist beyond the expression          |
| **Function Return * *| Functions that return by reference return L - value| Functions that return by value return R - value |
| **Reference Type * * | Reference to L - value(L - value reference)        | Reference to R - value(R - value reference)     |

//R- value reference

| **Feature**                | **Description**                               |
| -------------------------- | --------------------------------------------- |
| **Definition**             | A reference created to a temporary            |
| **Represents**             | A temporary value                             |
| **Syntax**                 | Created with `&&` operator                    |
| **Can Bind To**            | Only R-values (temporaries)                   |
| **Cannot Bind To**         | L-values                                      |
| **Binding Rule**           | R-value references always bind to temporaries |
| **L-value Reference Rule** | L-value references (&) always bind to L-values    |

int&& ref=5+3
int& ref1=x;
*/

//#include <iostream>
//
//// Returns r-value
//int Add(int x, int y) {
//    return x + y;
//}
//
//// Returns l-value
//int& Transform(int& x) {
//    x *= x;
//    return x;
//}
//
//// Print accepts l-value reference
//void Print(int& x) {
//    std::cout << "Lvalue : Print(int&)" << std::endl;
//}
//
//// Print accepts const l-value reference
//void Print(const int& x) {
//    std::cout << "Const Lvalue: Print(const int&)" << std::endl;
//}
//
// //Print accepts r-value reference
//void Print(int&& x) {
//    std::cout << "Rvalue : Print(int&&)" << std::endl;
//}
//
//int main() {
//    // x is an l-value
//    int x = 10;
//    int y=x;
//    int z=5+3;
//    // ref is an l-value reference
//    int& ref = x;
//
//    // Transform returns an l-value
//    int& ref2 = Transform(x);
//
//    // rv is an r-value reference
//    int&& rv = 8;
//
//    // Add returns a temporary (r-value)
//    int&& rv2 = Add(3, 5);
//
//    // The following lines would cause an error because an l-value cannot bind to an r-value reference
//     /*int var = 0;
//     int &&r1 = var;*/
//
//    // But an l-value can bind to a const l-value reference
//    const int& r2 = 3;
//
//    // Function call demonstrations
//    int i = 10;
//    Print(i);                        // L-value
//    Print(10);                       // R-value
//    Print(std::move(i));            // move() converts l-value into r-value
//    Print(static_cast<int&&>(i));   // Explicit cast to r-value reference
//    //Note:- static_cast and move both perform same operation ,
//    //But we use it most of the time as move just avoid ambiguity and increase readability.
// 
//
//    return 0;
//}
```


```cpp
#include <iostream>

//Marking a function as constexpr gives it the potential 
//to be evaluated at compile time
constexpr int get_value(int multiplier){
    return 3 * multiplier;
}


int main(){

    /*
        For the evaluation to take place at compile time, we have 
        to remember to store the return value in a constexpr result variable
        Thanks to Reza for catching this error and reporting it. 

    */
    //4 is compile time variable
    constexpr int result = get_value(4); // Compile time
    std::cout << "result : " << result << std::endl;

    /*
    int some_var{5}; // Run time variable
    int result = get_value(some_var); // Run time
    std::cout << "result : " << result << std::endl;
    */
   
    return 0;
}
```

---

# ⭐ **`constexpr` Function in C++ —**

A **`constexpr` function** is a function that **can be evaluated at compile time** *if* all its inputs are known at compile time.

✔ It *can* run at compile time
✔ It *can also* run at runtime (if arguments are not constexpr)
✔ It guarantees that the function body is suitable for constant evaluation

---

# ✅ **1. Basic Syntax**

```cpp
constexpr int add(int a, int b) {
    return a + b;
}
```

---

# ✅ **2. Compile-Time Usage**

```cpp
constexpr int x = add(10, 20);  // evaluated at compile time
```

✔ Valid, because all arguments are compile-time constants.

---

# ✅ **3. Runtime Usage**

```cpp
int a = 5;
int b = 7;
int r = add(a, b);   // evaluated at runtime
```

✔ Same function
✔ Two different behaviors

---

# 🔥 **4. Key Rules for `constexpr` Functions**

### ✔ Rule 1 — Function must be very simple

Must contain only statements allowed in constant expressions:

Allowed:

* return statements
* local variables
* if / else (C++14+)
* loops (C++14+)
* recursion (C++14+)
* `switch` (C++14+)

Not allowed:

* dynamic memory (`new`, `delete`)
* virtual functions
* try/catch
* modifying static local variable
* I/O operations

---

# ✨ **C++ Versions**

| C++ Version | `constexpr` rules                                            |
| ----------- | ------------------------------------------------------------ |
| C++11       | Only return statements, no loops                             |
| C++14       | Loops, if, recursion allowed                                 |
| C++20       | Even `consteval` added for mandatory compile-time evaluation |

---

# 📌 **5. Examples**

---

## **Example A: Compile-Time + Runtime Duality**

```cpp
constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int a = square(5);   // compile time
    int y = 10;
    int b = square(y);             // runtime
}
```

---

## **Example B: Loops allowed (C++14+)**

```cpp
constexpr int sum(int n) {
    int s = 0;
    for(int i = 1; i <= n; i++) {
        s += i;
    }
    return s;
}

constexpr int result = sum(10);   // compile time
```

---

## **Example C: Using `constexpr` with objects**

```cpp
struct Point {
    int x, y;

    constexpr Point(int a, int b) : x(a), y(b) {}
};

constexpr Point p{10, 20};   // compile-time object
```

---

# ⚠️ **6. Common Mistakes**

---

### ❌ Using non-constexpr input

```cpp
int x = 20;
constexpr int y = square(x);   // ERROR (x is not constexpr)
```

---

### ❌ Returning non-const state

```cpp
int global = 10;

constexpr int get() {
    return global;   // ❌ NOT allowed (global is not constexpr)
}
```

---

### ❌ Using operations not allowed at compile time

```cpp
constexpr int fun(int x) {
    int* p = new int;    // ❌ new not allowed
    return x;
}
```

---

# 🎯 **7. Difference Between `const` vs. `constexpr` vs. `consteval`**

| Keyword               | Meaning                                       |
| --------------------- | --------------------------------------------- |
| **const**             | value cannot change (runtime or compile-time) |
| **constexpr**         | *can be* compile-time but not mandatory       |
| **consteval** (C++20) | must run at compile time (always)             |

---

# 🚀 **8. Real-World Advantage**

Why use `constexpr`?

✔ Faster execution
✔ Zero runtime cost
✔ Stable compile-time validation
✔ Often used in **embedded**, **HFT**, **game engines**, **C++ templates**, **metaprogramming**

---

# ⭐ Summary (short point form)

* `constexpr` function **can** run at compile time
* Must have compile-time friendly code
* If inputs are constexpr → evaluated at compile time
* If inputs are runtime → evaluated at runtime
* C++14+ allows loops, branches, recursion
* For mandatory compile-time → use `consteval`

---


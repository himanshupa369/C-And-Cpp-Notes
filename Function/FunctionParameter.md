
# ⭐ *Pass by Value in C++*
---

# 📘 **Pass by Value in C++**

**Header:** `<iostream>`
**Introduced:** **C++98** (available since earliest versions)

---

# 🔹 **1. What is Pass by Value?**

In **pass by value**, when a function is called:

* The **actual arguments** are **copied** into the **function’s parameters**.
* The function works on these **copies**, not on the original variables.
* Changes inside the function **do NOT affect** the original values.

---

# 🔹 **2. Syntax**

```cpp
void fun(int x) {
    x = x + 10;
}

int main() {
    int a = 5;
    fun(a);   // value 5 is copied into x
}
```

Here:

* `a` → original variable
* `x` → copy inside function

---

# 🔹 **3. How Pass by Value Works Internally**

### STEP 1 — Function Call

```cpp
fun(a);
```

Compiler copies the value of `a` to parameter `x`.

### STEP 2 — Inside the Function

`x` is now a **separate variable**.

If you modify `x`, only **the copy** changes.

### STEP 3 — Function Ends

Copies are destroyed.
Original data remains unchanged.

---

# 🔹 **4. Block Diagram (Memory Concept)**

```
      main()                           fun(x)

   a = 10                         x = COPY OF a = 10
   --------                      ----------------------
   | 10 |  --------------------> | 10 |   (separate)
   --------                      ----------------------
       (original)                     (local copy)

If x changes → a remains same
```

---

# 🔹 **5. Example Program**

```cpp
#include <iostream>
using namespace std;

void increment(int x) {
    cout << "Inside function (before): " << x << endl;
    x++;
    cout << "Inside function (after): " << x << endl;
}

int main() {
    int num = 5;

    cout << "Outside function (before): " << num << endl;
    increment(num);
    cout << "Outside function (after): " << num << endl;

    return 0;
}
```

### ✔ Output:

```
Outside function (before): 5
Inside function (before): 5
Inside function (after): 6
Outside function (after): 5
```

➡ Notice how the original variable **remains unchanged**.

---

# 🔹 **6. Pros & Cons**

### ✔ Pros

| Benefit         | Explanation                                   |
| --------------- | --------------------------------------------- |
| Safe            | Original data cannot be modified accidentally |
| Simple          | No need to understand memory/pointers         |
| No side effects | Function doesn't alter caller's variables     |

### ❌ Cons

| Drawback                 | Explanation                                                    |
| ------------------------ | -------------------------------------------------------------- |
| Slower for large objects | Copies may be expensive (e.g., copying large vectors, strings) |
| More memory usage        | Requires creating additional copies                            |

---

# 🔹 **7. Real-World Use Cases**

✔ **Mathematical functions**
Where original data should remain unchanged.

✔ **Library functions**
To ensure safety from unwanted modification.

✔ **Functions taking small data types**
Like `int`, `char`, `double` — copying is cheap.

✔ **When immutability is required**
Useful for secure or predictable code.

---

# 🔹 **8. When NOT to Use Pass by Value**

When passing:

❌ large arrays
❌ large objects
❌ vectors
❌ complex classes

→ better to use **pass by reference (`&`)** or **pass by const reference (`const &`)**.

---

# ✔ Final Summary (Interview-Ready)

* Pass by value copies arguments to parameters
* Modifications inside the function do **not** affect original
* Safe but sometimes inefficient
* Best for small, simple types
* Worst for big memory objects

---

# ⭐ Difference Between **Function Parameter** and **Argument** in C++
---

# 📘 **Function Parameters vs Arguments in C++**

**Introduced:** **C++98** (fundamental concept since the beginning)

---

# 🔹 **1. Basic Definitions**

## ✔ **Parameter (Formal Parameter)**

* A variable declared in the **function definition**.
* Acts as a **placeholder** for the value that will be passed.
* Lives inside the **function scope**.

Example:

```cpp
void add(int x, int y)   // x and y are parameters
```

---

## ✔ **Argument (Actual Argument)**

* The **value** or **variable** passed to a function during a call.
* Exists in **main or caller function**.

Example:

```cpp
add(5, 10);   // 5 and 10 are arguments
```

---

# 🔹 **2. One-Line Difference**

| Parameter                       | Argument                                |
| ------------------------------- | --------------------------------------- |
| Variable in function definition | Actual data passed during function call |
| Placeholder                     | Real value                              |
| Exists inside function          | Exists at calling place                 |

---

# 🔹 **3. Block Diagram (Memory Concept)**

```
Function Definition:
--------------------
void add(int x, int y)
{
     // x, y are PARAMETERS
}

Function Call:
--------------
int a = 5;
int b = 10;
add(a, b);
  |    |
  |    ----> argument (10)
  |
  -------> argument (5)

Inside function:
x = copy of a
y = copy of b
```

---

# 🔹 **4. Example Program**

```cpp
#include <iostream>
using namespace std;

void greet(string name) {   // name → PARAMETER
    cout << "Hello, " << name << endl;
}

int main() {
    greet("Himanshu");      // "Himanshu" → ARGUMENT
    return 0;
}
```

---

# 🔹 **5. Pros & Cons**

## ✔ Parameters

| Pros                | Cons                           |
| ------------------- | ------------------------------ |
| Provide flexibility | Cannot exist without arguments |
| Provide abstraction | Limited to function scope      |

## ✔ Arguments

| Pros                | Cons                            |
| ------------------- | ------------------------------- |
| Provide real values | Must match parameter type/count |
| Allow reusability   | Wrong arguments cause errors    |

---

# 🔹 **6. Real-World Use Cases**

### Parameters

✔ When designing a function
✔ When creating reusable code
✔ When defining interfaces/APIs

### Arguments

✔ When using a function with different inputs
✔ When passing user input to processing functions
✔ When calling library functions

---

# 🔹 **7. Summary (Interview-Ready)**

```cpp
#include <iostream>

void say_age(int age){ // Parameter
    ++age;
    std::cout <<  "Hello , you are " << age << " years old! &age : " << &age <<  std::endl;
}

int main(){

    int age{23}; // Local
    std::cout << "age (before call) : " << age << "&age : " << &age << std::endl;
    say_age(age); // Argument
    std::cout << "age (after call) : " << age << "&age : " << &age <<  std::endl;

    return 0;
}

```

* **Parameters** → variables inside function definition.
* **Arguments** → actual values passed during function call.
* Parameters = placeholders; Arguments = real values.
* Without arguments, parameters cannot be used.

---
---

# 📘 Pass by **const Value** in C++

**Header:** `<iostream>`
**Introduced:** **C++98** (Concept of `const` and pass-by-value exists since early C++)
**Category:** Function Parameter Passing Technique

---

# 🧠 What is *Pass by Value*?

In **pass by value**, the function receives a **copy** of the argument.
Modifications inside the function **do not affect the original value**.

Example:

```cpp
void fun(int x) { x = 10; }
```

Here `x` is a **copy** of the caller's value.

---

# 🧠 What is *Pass by const Value* ?

When you pass a parameter **by value AND make it const**, you write:

```cpp
void fun(const int x)
```

This means:

* A **copy** of the value is still passed (normal pass-by-value).
* But inside the function, the parameter **cannot be modified**.
* So the function is *not allowed* to change its local copy.

---

# 🎯 Why Use `const` with Pass-by-Value?

Because it:

* Prevents accidental modification
* Makes function intent clearer
* Helps the compiler catch mistakes
* Helps maintain clean and safe code

But it **does not improve performance**, because a copy is already made.

---

# ✔ Syntax

```cpp
return_type function_name(const data_type parameter);
```

---

# 🌟 Simple Example (Easy to Understand)

```cpp
#include <iostream>
using namespace std;

void printDouble(const int x) {   // const value parameter
    // x++;     ❌ ERROR: cannot modify const parameter
    cout << "Double: " << (x * 2) << endl;  // safe to use
}

int main() {
    int num = 5;
    printDouble(num);   // pass by const value
    cout << "Original num: " << num << endl;
    return 0;
}
```

### ✔ Output

```
Double: 10
Original num: 5
```

### 📝 Explanation

* The function gets a **copy** of `num`.
* `const` ensures the copy cannot be modified.
* The original variable `num` remains unchanged.

---

# 📌 When Should You Use Pass-by-Const-Value?

Use it when:

✔ The parameter is **small** (like `int`, `double`, `char`, bool, enum)
✔ You want to **prevent accidental modification**
✔ You still want pass-by-value semantics (function receives a copy)

For **small types**, `const` is good for clarity.

---

# ❌ When NOT to Use It

Don't use it for:

* Large objects (e.g., `std::string`, `std::vector`, custom classes)
  → Use `const &` (pass-by-const-reference) instead

Because copying large objects is expensive.

Example:

```cpp
void fun(const vector<int>& v);  // better than const vector<int> v
```

---

# 🟩 Pros

| Advantage             | Description                      |
| --------------------- | -------------------------------- |
| Safety                | Function cannot modify the value |
| Clear intent          | Shows the value is read-only     |
| Compiler checks       | Errors if modification attempted |
| Ideal for small types | No overhead for copy             |

---

# 🟥 Cons

| Disadvantage                   | Description            |
| ------------------------------ | ---------------------- |
| Still creates a copy           | No performance benefit |
| Not suitable for large objects | Use `const &` instead  |

---

# 🌍 Real-World Use Cases

* Functions that only *read* small values (`int`, `double`, char).
* Utility functions: math operations, printing, comparisons.
* Code bases focused on safety and correctness.

Example:

```cpp
bool isPositive(const int x);
void showSquare(const int n);
double half(const double value);
```

---

# 📌 Summary (Interview-Ready)

* **Pass by value:** function gets a **copy**.
* **Pass by const value:** copy is **read-only** inside the function.
* Good for **small types**, but avoid for large objects.
* Offers **safety**, not **performance**.

---

# 📘 Pass by Pointer in C++

**Header:** `<iostream>`
**Introduced:** **C++98** (pointers exist since C, fully supported in C++)
**Concept:** Function receives the **memory address** of a variable.
This allows the function to **modify the original value**.

---

## ✅ Definition

In **pass by pointer**, you pass the **address** of a variable using `&`, and the function receives it using a pointer (`int*`).

---

## ✔ Syntax

```cpp
void func(int* ptr);
```

---

## ✔ Simple Example

```cpp
#include <iostream>
using namespace std;

void increment(int* p) {   // p stores the address of x
    (*p)++;                // modify original value
}

int main() {
    int x = 10;
    increment(&x);         // pass address
    cout << x;             // output: 11
}
```

---

## ⭐ Pros

* Function can **modify the caller’s variable**
* Useful for returning multiple values
* More efficient for large objects (avoids copying)

---

## ❗ Cons

* Pointer syntax error-prone
* Possible null-pointer issues
* Harder to read than references

---

## 🌍 Real-World Use

* Dynamic memory (`new`, `delete`)
* C-style APIs and system calls
* Functions that need to modify multiple values

---

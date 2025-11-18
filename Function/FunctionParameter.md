
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

# 📘 Pass by Pointer to Const in C++

**Header:** `<iostream>`
**Introduced in:** **C++98**
**Concept:** Passing a pointer that points to a value which **cannot be modified** inside the function.

---

## ✅ What It Means

When you pass a **const pointer parameter**, i.e.:

```cpp
void func(const int* p);
```

You are promising:

✔ The function **can read** the value using `*p`
✖ The function **cannot modify** the value using `*p = ...`
✔ The function **can change what p points to** (p is not const)

This is **safe** and **efficient**, especially when passing large data.

---

## ✔ Simple & Clean Example

```cpp
#include <iostream>
using namespace std;

void printValue(const int* ptr) {   // pass by pointer to const
    cout << "Value: " << *ptr << endl;

    // *ptr = 100;   // ❌ ERROR: cannot modify the pointed value
}

int main() {
    int x = 10;
    printValue(&x);   // passing address of x
}
```

---

## ⭐ Why Use Pass-by-Pointer-to-Const?

### Pros

* ✔ Prevents accidental modification
* ✔ Expresses **read-only intent** clearly
* ✔ Efficient for large data (avoids copying)
* ✔ Works well for arrays

### Cons

* ✖ Requires using `&` and pointer syntax
* ✖ Cannot modify the pointed value

---

## 🌍 Real-World Use Cases

* Read-only array access: `void process(const int* arr, size_t size);`
* Passing large structures/objects safely
* Library/API design where data must not be changed

---

## 📌 Summary (Very Short)

> **Pass by pointer to const** = function gets the **address**, can **read** data, but **cannot change** it.

---

---

# 📌 Pass by **const pointer to const** in C++

### **📄 Header File**

No special header needed.

### **🕒 Introduced**

Available since **C++98**

---

# ✅ What is “const pointer to const” ?

A **const pointer to const** means:

```
const int * const ptr
```

* The **data** pointed to → **cannot be modified**
* The **pointer address** → **cannot be changed**

So **both are const**.

---

# 📌 Function Parameter Syntax

```cpp
void fun(const int * const ptr);
```

Inside the function:

* You **cannot modify** `*ptr`
* You **cannot reassign** `ptr`

---

# ✔️ Why use it?

### **Pros**

* Guarantees **complete safety**:
  → neither the pointer nor the data can be changed accidentally.
* Useful when passing **sensitive read-only buffers**.
* Makes intent **clear** to other developers.

### **Cons**

* Slightly verbose.
* Rarely necessary—often `const int*` alone is enough.

---

# 🌍 Real-World Use Cases

* Passing **configuration values** that must not be modified.
* Functions that read from a **fixed memory-mapped register**.
* Reading from a **read-only buffer** without allowing reassignment.

---

# 🧪 Simple Example (Easy Language)

```cpp
#include <iostream>

void printValue(const int * const ptr) {  // const pointer to const int
    // *ptr = 50;   // ❌ Error: data can’t be modified
    // ptr = nullptr; // ❌ Error: pointer can’t change

    std::cout << "Value is: " << *ptr << std::endl; // ✔️ allowed: read only
}

int main() {
    int x = 10;
    const int * const p = &x;  // same type

    printValue(p);
}
```

---

# 🧠 Key Idea (1-Line Memory Trick)

> **Left const → data const**,
> **Right const → pointer const**
>
> `const int * const p;`
> **both sides const → nothing can change**

---
# Pass by Reference in C++

## 📌 Header File

No special header required.

## 🕒 Introduced In

**C++98**

---

# 📘 What is Pass by Reference?

Pass by reference means **passing the actual variable (not a copy)** to a function using a reference (`&`).

This allows the function to:

* Access the original variable directly
* Modify the original variable
* Avoid copying large objects (performance benefit)

Syntax:

```cpp
type functionName(type& parameter);
```

---

# ✔️ Why Use Pass by Reference?

### **Pros**

* No copy → **faster** for large structures
* Function can **modify the caller's variable**
* Useful for returning multiple outputs

### **Cons**

* Caller variable **can be changed unintentionally**
* Harder to understand if misused

---

# 🌍 Real-World Use Cases

* Modifying values inside functions (swap, update, etc.)
* Avoiding expensive copies (e.g., passing vectors, objects)
* Returning multiple outputs via reference parameters

---

# 🧪 Simple Example: Basic Pass by Reference

```cpp
#include <iostream>

void update(int& x) {  // x is a reference to the original variable
    x = x + 10;        // modifies the original 'num'
}

int main() {
    int num = 5;
    update(num);

    std::cout << "After update: " << num << std::endl;
}
```

**Output:**

```
After update: 15
```

The original variable `num` is modified.

---

# 🧪 Example: Swapping Two Numbers Using Reference

```cpp
void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

Reference is ideal for swaps because no copying is required.

---

# 📌 Pass by Reference with `const`

If you want to avoid modification but also avoid copy:

```cpp
void print(const int& x) {
    std::cout << x << std::endl;
}
```

* Uses reference → no copy
* Uses `const` → cannot modify

---

# 🧠 Memory Trick

> **Reference = Alias**
> Whatever you do to the reference happens to the original variable.

---

# ✔️ When to Use Pass by Reference

Use it when:

* Function must modify the caller variable
* Passing large objects (vector, string, class)
* Returning multiple outputs

Avoid when:

* You don’t want accidental modifications → use **`const &`** instead.

---

# Pass by **Const Reference** in C++

## 📌 Header File

No special header required.

## 🕒 Introduced In

**C++98**

---

# 📘 What is Pass by Const Reference?

Pass by **const reference** means:

* You pass a **reference** (`&`) → no copy is made
* You add **const** → function cannot modify the original variable

### Syntax

```cpp
type functionName(const type& parameter);
```

### Simple Meaning

> "Give me the original variable (no copy), but I promise I won’t change it."

---

# ✔️ Why Use Const Reference?

### **Pros**

* **No copying** → fast, especially for large objects (string, vector, class)
* **Read-only safety** → function cannot modify input
* Ideal for **large data structures** or **immutable inputs**

### **Cons**

* Slightly less clear for beginners
* Cannot modify the parameter even if you want to

---

# 🌍 Real-World Use Cases

* Passing **std::string**, **std::vector**, **objects** safely
* Passing data to functions that should **only read**
* Good for **performance-sensitive** code
* Example: Printing, searching, comparing, analyzing

---

# 🧪 Example 1: Basic Const Reference

```cpp
#include <iostream>

void printValue(const int& x) {  
    // x = 20;  // ❌ Error: cannot modify
    std::cout << "Value: " << x << std::endl;  // ✔️ Allowed (read-only)
}

int main() {
    int num = 10;
    printValue(num);
}
```

---

# 🧪 Example 2: Works With Large Objects (Zero Copy)

```cpp
#include <iostream>
#include <string>

void showMessage(const std::string& msg) {
    std::cout << msg << std::endl;  // fast, no copy, read-only
}

int main() {
    std::string text = "Hello C++";
    showMessage(text);
}
```

Without const reference, passing a `std::string` would create a **copy**, which is expensive.

---

# 🧪 Example 3: Passing Temporary (Rvalues)

Const reference can bind to **temporaries**:

```cpp
void display(const int& x) {
    std::cout << x << std::endl;
}

int main() {
    display(500);   // ✔️ valid: temporary binds to const reference
}
```

A normal non-const reference **cannot** bind to rvalue.

---

# 🧠 Important Concepts

## 1. **Const Reference Does NOT Make Original Variable Const**

```cpp
void func(const int& x) {
   // cannot modify x here
}

int main() {
    int a = 10;
    func(a);
    a = 20;   // ✔️ still allowed
}
```

Const applies **inside the function only**.

---

## 2. **Why Not Pass by Value?**

Pass by value **copies** the argument:

```cpp
void print(int x) {}  // copy happens
```

For small types (int, char), pass by value is fine.
For large objects (string, vector), **prefer const reference**.

---

## 3. Const Reference vs Reference

| Feature                  | Non-Const Reference (`int&`) | Const Reference (`const int&`) |
| ------------------------ | ---------------------------- | ------------------------------ |
| Can modify argument?     | ✔️ Yes                       | ❌ No                           |
| Allows temporary/rvalue? | ❌ No                         | ✔️ Yes                         |
| Copy occurs?             | No                           | No                             |
| Use case                 | Modify                       | Read-only                      |

---

# 🔍 When to Use Const Reference?

### Use When:

* Passing **large objects**
* Function **should not modify** the argument
* You want to **avoid copies**
* You want to accept **temporaries** safely

### Avoid When:

* You need a copy inside function → use pass by value
* Parameter is very small (int, char) → value is simpler

---

# 🔚 Summary (Quick Revision)

* **const reference = fast + safe**
* No copy
* Cannot modify
* Can bind to temporary
* Best for large, read-only inputs

---

---

# ✔️ Pass by Value

* Syntax feels **natural** and easy.
* Good for **fundamental types** like `int`, `double`, `char`, etc.
* Not recommended for **relatively large user-defined types** because:

  * It **creates copies**, which can **waste memory** and reduce performance.
* Safe because the function works on a **copy**, not the original variable.

---

# ✔️ Pass by Reference

* **Does not create copies**.
* Any changes made inside the function are **reflected in the original argument**.
* Saves memory because the function accesses the **actual variable**.
* Recommended for **large user-defined types**.
* Syntax feels a bit **less natural** than pass by value, but:

  * It is widely accepted and heavily used in C++ development.

---

# ✔️ Pass by Pointer

* The **pointer (address)** itself is passed **by value**.
* Using **dereferencing**, the function can modify the original variable.
* Avoids copies (a pointer is very cheap to copy).
* Syntax is considered **ugly** because you must:

  * Use pointer parameters (`int* p`)
  * Pass the address during the call (`func(&x)`)
  * Dereference in the function (`*p = ...`)
* Despite the syntax, it is still **widely used** in real-world C++ code.
* Recommended for **large user-defined types**, and when a parameter might be **nullable** (`nullptr`).

---

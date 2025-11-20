
---

# ✅ **Returning by Value in C++ (Modern Optimizations Explained)**

Even though returning large objects **by value** looks expensive (because it suggests copying), **modern C++ compilers optimize most of these copies away**.

This is achieved through:

### 🔹 **1. NRVO — Named Return Value Optimization**

### 🔹 **2. RVO — Return Value Optimization**

### 🔹 **3. Move Semantics (C++11+)**

---

# ⭐ **Key Idea**

> **When you return an object by value, the compiler usually constructs the object directly in the caller’s memory location — no copy and no move.**

This makes returned-by-value objects **as efficient as returning by reference**, and sometimes *even faster*, because references require an existing object.

---

# 🔥 **Simple Example (Looks Expensive but is Actually Optimized)**

```cpp
#include <string>

std::string make_name() {
    std::string name = "Himanshu";
    return name;   // NRVO applies → no copy, no move
}

int main() {
    std::string n = make_name();  // Object constructed directly here
}
```

### Without optimizations (WRONG mental model):

* create `name` inside function
* copy it into return value
* destroy temporary

### With modern compilers (REAL behavior):

✔ `name` is constructed **directly** into `n`
✔ no copy
✔ no move
✔ no overhead

This is **NRVO**.

---

# 🔥 **RVO Example (Always Guaranteed Since C++17)**

```cpp
std::string make_hello() {
    return std::string("Hello");   // temporary constructed directly in caller
}
```

Since C++17, this **is guaranteed** to have:

* **0 copies**
* **0 moves**

---

# 🔥 **Move Semantics Backup (C++11+)**

If NRVO cannot apply (rare cases), compiler uses **move constructor** instead of copy constructor.

Example:

```cpp
std::string choose(bool t) {
    if (t) return std::string("Yes");
    return std::string("No");
}
```

Here NRVO *may* not apply because two different objects may be returned → compiler falls back to:

✔ move constructor
❌ copy constructor

Moves are cheap (pointer steal).

---

# 🔥 **When Return-by-Value is NOT Optimized**

❌ Returning different local variables of the same function (NRVO disabled)

```cpp
MyObj test(int x) {
    MyObj a, b;
    if (x > 0) return a;
    else return b;        // NRVO cannot guarantee — falls back to move
}
```

But still:
✔ moves are cheap
✔ copies avoided
✔ performance still good

---

# 🧠 **Why It Looks Like “Compiler Returns by Reference Behind Your Back”**

Because the compiler constructs the return object **directly in the caller’s storage**, it behaves like **return by reference** from performance perspective:

* no intermediate object
* no copy
* no move

But **logically**, it is still *return by value*
(no aliasing, no reference lifetime issues).

---

# 🏁 **Summary**

### ✔ Returning by value is efficient

### ✔ NRVO/RVO eliminate almost all temporary copies

### ✔ Move semantics act as a backup

### ✔ Safe and idiomatic in modern C++

**So modern C++ encourages *return by value*.**

---

```cpp
#include <iostream>


int sum ( int a , int b){
    int result = a + b;
    std::cout << "In : &result(int) :  " << &result << std::endl;
 	return result;
}

std::string add_strings(std::string str1, std::string str2){
    std::string result =  str1 + str2;
    std::cout << "In : &result(std::string) :  " << &result << std::endl;
    return result;
}

int main(){

    
    /*
    int x{15};
    int y{9};
    int result = sum(x,y);
    std::cout << "Out : &result(int) :  " << &result << std::endl;
    std::cout << "result : " << result << std::endl;
    */
 

   
    std::string in_str1{"Hello"};
    std::string in_str2{" World!"};
    std::string result_str = add_strings(in_str1,in_str2);
    std::cout << "Out : &result_str(std::string) :  " << &result_str << std::endl;
    std::cout << "result_str : " << result_str << std::endl;
  

    return 0;
}
```
---

# ✅ **Q1: Why are addresses (IN & OUT) DIFFERENT for `int` return?**

### ✔ Function:

```cpp
int sum (int a, int b){
    int result = a + b;
    std::cout << "In : &result(int) :  " << &result << std::endl;
    return result;
}
```

### ✔ Reason:

`int result` is a **simple built-in type**, a small POD (Plain Old Data).
For small primitive types, the compiler **does NOT apply NRVO/RVO (copy-elision)** because copying an `int` is *extremely cheap*.

So:

* `result` is created **inside the function stack frame**
* copied into the caller's variable (`result` in main)
* therefore their addresses are **different**

### 🔍 **Memory Behavior**

```
Inside function:
   result (int) at address A

In main():
   result (int) at address B
```

A ≠ B → addresses differ.

**Copying a 4-byte int is trivial**, so compiler does not optimize this.

---

# ✅ **Q2: Why are addresses (IN & OUT) SAME for `std::string` return?**

### ✔ Function:

```cpp
std::string add_strings(std::string str1, std::string str2){
    std::string result =  str1 + str2;
    std::cout << "In : &result(std::string) :  " << &result << std::endl;
    return result;
}
```

### ✔ Reason:

`std::string` is a **heavy object** (dynamic allocation, size, capacity, pointer).
Copying is expensive.

So the compiler uses **RVO/NRVO (Return Value Optimization)**:

* It constructs `result` **directly in the caller’s memory**
* No temporary is created inside the function
* The address inside the function matches the address in `main()`

### 🔍 **Memory Behavior**

```
Compiler creates result_str in main()

Inside add_strings():  
   result is actually constructed at &result_str (same address)

Back in main():  
   result_str lives at that same location
```

So addresses are **identical**.

---

# ☑ **Why compiler optimizes strings but not ints?**

| Type          | Heavy? | Copy expensive? | RVO/NRVO applied? | Address same? |
| ------------- | ------ | --------------- | ----------------- | ------------- |
| `int`         | ❌ No   | ❌ No            | ❌ No              | ❌ Different   |
| `std::string` | ✔ Yes  | ✔ Yes           | ✔ Yes             | ✔ Same        |

---

# 🧠 Short Summary

### **Integers**

* Cheap to copy
* No copy-elision performed
* Function-local variable lives in **function stack**
* Returned value stored in **caller stack**
  ➡ **Addresses DIFFERENT**

### **std::string**

* Expensive to copy → compiler avoids copy
* NRVO places object **directly in caller's memory**
  ➡ **Addresses SAME**

---


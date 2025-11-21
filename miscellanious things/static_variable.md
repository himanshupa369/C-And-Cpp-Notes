```cpp
#include <iostream>

size_t dog_count{0};// Global scope


unsigned int add_student(){
     static unsigned int student_count{0}; // The scope of this var is in add_student,
							  // but it's life time goes beyond the function execution.
    student_count++;
    ++dog_count;
    return student_count;
}

void do_something(){
    //--student_count; // Compiler error
    ++dog_count;
}

int main(){

    /*
    std::cout << "student count : " << add_student()  << std::endl;//1
    std::cout << "student count : " << add_student()  << std::endl;//2
    std::cout << "student count : " << add_student()  << std::endl;//3
    */

   for(size_t i {} ; i < 20 ;++i){
       std::cout << "student count : " << add_student()  << std::endl;
   }
   
    return 0;
}
```

---

# 🚀 **Static Variables in C++ (Beginner → Industry Level)**

Static variables are one of the most frequently asked topics in **C++ interviews**—because they involve memory management, lifetime, scope, and linkage.

Let’s understand **everything clearly**.

---

# ✅ **1. What Is a Static Variable in C++?**

A **static variable** is a variable that:

### ✔ Has *static storage duration*

It is created **once**, lives **for the entire program**, and is destroyed at program exit.

### ✔ Is initialized only **once**

Even if the function is called 100 times, the static variable is initialized only the first time.

### ✔ Retains its value between function calls

It behaves like a small persistent memory.

---

# 🚩 **2. Types of static variables**

There are **three types**:

## **(A) Static Local Variables**

Inside a function/block.

```cpp
void counter() {
    static int count = 0;  // initialized once
    count++;
    std::cout << count << '\n';
}
```

Calling `counter()` 3 times prints:

```
1
2
3
```

### 🧠 Key points:

* Scope: **local to the function**
* Lifetime: **entire program**
* Default initialization: **0**

---

## **(B) Static Global Variables (internal linkage)**

Declared at global level:

```cpp
static int x = 10;
```

### ✔ Meaning:

* Visible **only in this file** (translation unit)
* Prevents conflicts with variables of the same name in other files
* Used in multi-file projects to enforce encapsulation

---

## **(C) Static Data Members in Classes**

```cpp
class Student {
public:
    static int count;
};

int Student::count = 0;   // definition outside class
```

### ✔ Meaning:

* Shared by **all objects** of the class
* Only **one copy** exists
* Must be **defined outside** the class

---

# 📌 **3. Static Variables Memory Location**

Static variables are stored in:

### 👉 **Data Segment (.data)**

If initialized.

### 👉 **BSS Segment (.bss)**

If default-initialized to zero.

They are **NOT** stored on stack or heap.

---

# 📌 **4. Why Do We Use Static Variables? (Industry Use Cases)**

### 👍 1. Persisting data between function calls

E.g., counting number of calls.

### 👍 2. Hiding global variables inside a file

Using `static` at global scope improves **encapsulation**.

### 👍 3. Class-level shared resources

E.g., number of active objects, logging system, configuration, counters.

### 👍 4. Implementing Singleton pattern

Static variable ensures only one instance exists.

---

# 📘 **5. Complete Example for All Types**

```cpp
#include <iostream>

static int g_count = 5;  // static global

void test() {
    static int x = 0;    // static local
    x++;
    std::cout << "x = " << x << "\n";
}

class A {
public:
    static int val;      // static class member
};

int A::val = 100;

int main() {
    test();
    test();

    std::cout << g_count << "\n"; 
    std::cout << A::val << "\n";
}
```

---

# ⚠️ **6. Common Mistakes**

### ❌ Mistake 1: Thinking static local behaves like global

No — it is *local in scope* but *global in lifetime*.

### ❌ Mistake 2: Forgetting to define static class members

Will give linker error.

### ❌ Mistake 3: Using static where not necessary

Can cause weird state bugs.

---

# 🧠 **7. Most Important Interview Questions (with answers)**

---

### **Q1: What is the difference between static and global variables?**

| Feature    | Global Variable       | Static Global Variable |
| ---------- | --------------------- | ---------------------- |
| Visibility | Across entire program | Only in the file       |
| Linkage    | External linkage      | Internal linkage       |
| Lifetime   | Entire program        | Entire program         |

---

### **Q2: How do static variables behave inside functions?**

They **retain their value** between calls and are **initialized one time only**.

---

### **Q3: Where are static variables stored in memory?**

* `.data` segment → initialized static variables
* `.bss` segment → uninitialized static variables

---

### **Q4: Can static variables be thread-safe?**

No — not by default.
Static variables are **shared** among all threads → cause **race conditions**.

Use mutex or `thread_local`.

---

### **Q5: Why must static class members be defined outside the class?**

Because they are **not object members**; memory must be allocated separately.

---

### **Q6: Can a static member function access non-static members?**

❌ No.

Because static functions do not have `this` pointer.

---

### **Q7: Can constructors be static?**

❌ No.
Only objects can be static, not constructors.

---

### **Q8: What is difference between static data member and static local variable?**

| Feature | Static Local    | Static Data Member    |
| ------- | --------------- | --------------------- |
| Scope   | Inside function | Class scope           |
| Shared? | No              | Shared by all objects |
| Access  | Function only   | `ClassName::member`   |

---

### **Q9: What is static function in a class?**

A function that:

* Belongs to the class, not objects
* Can be called without object
* Can access only static members

---

# 🔥 **8. Real Company Interview Examples**

### **Example 1 (Amazon)**

Implement a function that counts how many times it is called.

```cpp
int count_calls() {
    static int count = 0;
    return ++count;
}
```

### **Example 2 (Microsoft)**

Why does this return different values?

```cpp
int f() {
    static int x = 0;
    return ++x;
}
```

Answer: Because static retains state.

---

# 🎯 **Final Summary (Perfect for GitHub Notes)**

* `static` gives variables **program-long lifetime**
* Scope depends on where it is declared (local/global/class)
* Class static members → shared among objects
* Stored in **data/BSS segment**
* Used for **singletons, counters, controlling visibility, shared config**
* Common interview topic with linkage, lifetime, memory, OOP
* Both global and static variables have static storage duration. 
They live throughout the entire lifetime of the program.
* Static variables are scoped to the function in which they are 
declared and used. If you try to access them outside that 
function, you’ll get a compiler error
* Global variables are scoped to the global scope of the file 
where they are declared. They are accessible and usable 
through out the entire file

---



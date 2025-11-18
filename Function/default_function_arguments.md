
---

# 🔹 **Default Arguments in C++ (Industry-Level Quick Notes)**

### ✅ **What is a default argument?**

A **default argument** is a value automatically used by the function **when the caller does not provide that argument**.

```cpp
void func(int x, int y = 10);
```

If caller passes only `x`, then `y` becomes `10`.

---

# 🔹 **Syntax**

Default values are written **only in the function declaration**, not in the definition.

```cpp
void print(int a, int b = 5);  // OK (declaration)

void print(int a, int b) {     // definition → NO default here
    std::cout << a << ", " << b;
}
```

---

# 🔹 **Rules (Industry Important)**

### ✔ Rule 1 — Default args must be on the **right side**

You **cannot** have a non-default parameter after a default one.

```cpp
void f(int a = 5, int b); // ❌ invalid
```

Correct:

```cpp
void f(int a, int b = 5); // ✔️
```

---

### ✔ Rule 2 — Given only in declaration (header file)

Professional C++ always puts defaults in header files:

```cpp
// .h
void log(std::string msg, int level = 1);

// .cpp
void log(std::string msg, int level) { ... }
```

It avoids **multiple definition** issues.

---

### ✔ Rule 3 — Evaluated at compile time

The default value is substituted during **compile time**, not runtime.

---

### ✔ Rule 4 — Function overloading interacts with default args

Default arguments can cause ambiguity:

```cpp
void test(int a, int b = 10);
void test(int a);
```

Calling:

```cpp
test(5); // ❌ ambiguous (two matches)
```

---

### ✔ Rule 5 — Works with constructors too

```cpp
class A {
public:
    A(int x = 0, int y = 0) { }
};
```

---

# 🔹 **Why default arguments? (Industry Uses)**

### ✔ Reduce repeated overloads

Instead of:

```cpp
void log(string msg);
void log(string msg, int level);
```

Use:

```cpp
void log(string msg, int level = 1);
```

### ✔ Clean API design (header files)

### ✔ Very useful for constructors in big classes

---

# 🔹 **Simple Example**

```cpp
#include <iostream>
void greet(std::string name = "Guest") {
    std::cout << "Hello, " << name << "\n";
}

int main() {
    greet();          // Hello, Guest
    greet("Himanshu"); // Hello, Himanshu
}
```

---

# 📌 **One-Line Summary**

**Default arguments let the function fill missing values automatically, must appear on the right, and are defined only once in the declaration (usually header).**

---

```cpp
//example:-
#include <iostream>

void compute( int age = 27 , double weight = 72.4, double distance = 12.5);
void greet_teacher(std::string_view name_sv = "teacher" , int homeworks =12,
    int exams = 4, double pass_rate = 0.5, std::string_view first_dpmt = "Computer Sce");


int main(){

    //compute();

	//Call and use default arguments
    greet_teacher();
    greet_teacher("Mr Bean");
    greet_teacher("Mr Hamston",7);
    greet_teacher("Mr Walker",7,3);
    greet_teacher("Mr Paku",7,3,0.7);
    greet_teacher("Mr Kojo",7,3,0.7,"Applied Mathematics");

   
    return 0;
}

void compute( int age   , double weight , double distance  ){
	std::cout << "Doing computations on age : " << age 
		<< " weight : " << weight 
		<< " and distance : " << distance << std::endl;
}

void greet_teacher(std::string_view name_sv,int homeworks,
                    int exams, double pass_rate, std::string_view first_dpmt){
    std::cout << std::endl;
    std::cout << "Good morning " << name_sv << "!" << std::endl;
    std::cout << "In the past semester, we had " << homeworks << " homeworks, and "
                << exams << " exams. The pass rate was around : " << pass_rate << std::endl;
    std::cout << "The best performing department is : " << first_dpmt << std::endl;
}
```

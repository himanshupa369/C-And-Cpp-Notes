
---

# 📘 **Constructors in C++ — Notes**

---

## 🔹 What is a Constructor?

A **constructor** is a special function inside a class that is automatically executed when an object is created.

✔ Same name as the class
✔ No return type (not even `void`)
✔ Used to initialize member variables
✔ Called automatically by compiler during object creation

---

## 🔥 Why Constructors?

Without a constructor, object members may contain garbage values or rely on default initializers.
A constructor allows us to give objects a valid initial state.

---

## 🧩 Syntax

```cpp
class ClassName {
public:
    ClassName();              // Default constructor
    ClassName(params...);     // Parameterized constructor
};
```

---

## Types of Constructors

| Type                          | Meaning                              | Example                        |
| ----------------------------- | ------------------------------------ | ------------------------------ |
| **Default Constructor**       | Takes no arguments                   | `Cylinder()`                   |
| **Parameterized Constructor** | Takes arguments to initialize object | `Cylinder(double r, double h)` |

---

## 🌟 Example from Lecture

```cpp
#include <iostream>

const double PI {3.1415926535897932384626433832795};

class Cylinder {
public : 
    // Default Constructor (no parameters)
    Cylinder(){
        base_radius = 2.0;
        height = 2.0;
    }

    // Parameterized Constructor
    Cylinder(double rad_param, double height_param){
        base_radius = rad_param;
        height = height_param;
    }
   
    double volume(){
        return PI * base_radius * base_radius * height;
    }

private : 
    double base_radius{1};
    double height{1};
};
```

---

### 🔍 What Happens in `main()`?

```cpp
Cylinder cylinder1; // Calls default constructor → radius=2, height=2
// Cylinder cylinder1(10,4); // Would call parameterized constructor
```

✔ Compiler checks argument pattern and selects matching constructor
✔ Constructor initializes data inside object
✔ `volume()` then uses those initialized values

---

### 🧠 Important Learning Points

| Concept                                                                    | Meaning                                |
| -------------------------------------------------------------------------- | -------------------------------------- |
| Constructor has **no return type**                                         | Declaring return makes it invalid      |
| Name must match class                                                      | Otherwise it becomes a normal function |
| If **you don’t write one**, compiler generates a default empty constructor |                                        |
| Constructors usually stay **public**                                       | So objects can be created from outside |
| Parameterized constructors allow custom initialization                     | More flexible object creation          |

---

### ⚙ Compiler-Generated Default Constructor

If no constructor is defined, C++ automatically provides:

```cpp
Cylinder(){ }  // empty, does not initialize manually
```

Members will only get default values if **explicitly initialized**, otherwise garbage.

---

### 🧾 Summary

| Feature                 | Constructor                              |
| ----------------------- | ---------------------------------------- |
| Purpose                 | Initialize objects                       |
| Return Type             | **None**                                 |
| Name                    | Same as class                            |
| Auto-Call               | YES, on object creation                  |
| Overloading             | Supported                                |
| If You Don't Create One | Compiler generates a default constructor |

---

### Output Example

```
volume : 25.1327    // Using default constructor (r=2, h=2)
```

---
---

# 🔥 **Types of Constructors in C++ **

---

## 1️⃣ **Default Constructor**

A constructor that takes **no arguments**.

If you don’t write one, the compiler generates it automatically.

### Example:

```cpp
class A {
public:
    A() {            // Default constructor
        std::cout << "Default Constructor Called\n";
    }
};

int main() {
    A obj; // Calls default constructor
}
```

---

## 2️⃣ **Parameterized Constructor**

Constructor that **takes parameters** for custom initialization.

```cpp
class Student {
public:
    int age;
    std::string name;

    Student(int a, std::string n) : age(a), name(n) {} // parameterized
};

int main() {
    Student s1(21, "Raj"); // calls parameterized constructor
}
```

---

## 3️⃣ **Copy Constructor**

Creates a new object by copying data from an existing object.

**Signature:**

```cpp
ClassName(const ClassName& other);
```

### Example:

```cpp
class Number {
public:
    int value;
    
    Number(int v) : value(v) {}
    
    Number(const Number& obj) {  // Copy constructor
        value = obj.value;
        std::cout << "Copy Constructor Called\n";
    }
};

int main() {
    Number n1(10);
    Number n2 = n1;  // copy constructor
}
```

---

## 4️⃣ **Move Constructor (C++11 - C++20)**

Used for **transferring (moving) resources**, instead of copying.
Especially useful for objects holding heap memory, large vectors, strings etc.

**Signature:**

```cpp
ClassName(ClassName&& other) noexcept;
```

### Example:

```cpp
#include <iostream>
#include <vector>

class Demo {
public:
    std::vector<int> data;

    Demo(std::vector<int> d) : data(std::move(d)) {}

    Demo(Demo&& other) noexcept {        // Move constructor
        data = std::move(other.data);    // transfer ownership
        std::cout << "Move Constructor Called\n";
    }
};

int main() {
    Demo d1({1,2,3,4});
    Demo d2 = std::move(d1);   // move instead of copy
}
```

⚠ After move, `d1.data` becomes empty.

---

## 5️⃣ **Delegating Constructor (C++11 onwards)**

One constructor calls **another constructor** of the same class.

Used to avoid code repetition.

### Example:

```cpp
class Box {
public:
    int length, width, height;

    Box() : Box(1,1,1) {} // delegating to parameterized constructor

    Box(int l, int w, int h) : length(l), width(w), height(h) {}
};

int main(){
    Box b1;        // calls default → redirects to (1,1,1)
    Box b2(5,6,7); // normal parameterized constructor
}
```

---

## 6️⃣ **Explicit Constructor**

Used to **prevent implicit conversion**.

```cpp
class Meter {
public:
    int value;
    explicit Meter(int v) : value(v) {}
};

int main(){
    Meter m1(10);  // OK
    // Meter m2 = 10; // ❌ error (implicit conversion blocked)
}
```

---

## 7️⃣ **Conversion Constructor**

Allows conversion from **other types to class type**.

```cpp
class Time {
public:
    int seconds;
    Time(double sec) : seconds(sec) {} // double → Time conversion
};

int main(){
    Time t = 5.5; // allowed (implicit conversion)
}
```

---

## 8️⃣ **Copy + Move Constructor Combined Class Example**

```cpp
class Test {
public:
    int val;

    Test(int x) : val(x) {}                   // parameterized
    Test() : Test(0) {}                        // delegating + default
    Test(const Test& t) : val(t.val) {}        // copy
    Test(Test&& t) noexcept : val(t.val) {     // move
        t.val = 0;
    }
};
```

---

# 📌 Summary Table

| Constructor               | Purpose                           | Introduced |
| ------------------------- | --------------------------------- | ---------- |
| Default Constructor       | Creates object with no args       | C++98      |
| Parameterized Constructor | Initialize with parameters        | C++98      |
| Copy Constructor          | Create duplicate object           | C++98      |
| Move Constructor          | Move resources instead of copy    | C++11      |
| Delegating Constructor    | Call one constructor from another | C++11      |
| Explicit Constructor      | Prevent implicit conversion       | C++98      |
| Conversion Constructor    | Allows type conversion → Class    | C++98      |

---



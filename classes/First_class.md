
---

# 📘 **Classes in C++ – Notes**

### 🔹 What is a Class?

A **class** is a user-defined data type in C++ that allows you to model real-world entities.
It contains:

| Component                         | Meaning                                     |
| --------------------------------- | ------------------------------------------- |
| **Member Variables (Attributes)** | Data stored inside the class                |
| **Member Functions (Methods)**    | Behaviors/operations performed on that data |

Example analogy:

| Real-world Object           | Class                     |
| --------------------------- | ------------------------- |
| Person → name, age, address | Cylinder → radius, height |

---

### 🔹 Why Classes?

Before classes, we used built-in types:

```cpp
int age;
double height;
```

But when modeling something complex (Person, Car, Bank Account, Cylinder),
we need our **own custom type** → *Class*.

---

### 🔥 Syntax of a Class

```cpp
class ClassName {
public:
    //public members accessible from outside
private:
    //private members accessible only inside class
};
```

✔ Must end with **semicolon `;`**
✔ Members are **private by default**

---

### 🧩 Example Used in Lecture → Modeling a Cylinder

A **cylinder** is defined by:

* `base_radius`
* `height`

and we can compute:

* **Area = πr²**
* **Volume = Area × height**

---

### 📌 Program from Lecture

```cpp
#include <iostream>

const double PI {3.1415926535897932384626433832795};

class Cylinder {
public:
    double volume(){
        return PI * base_radius * base_radius * height;
    }

public:
    double base_radius{1};
    double height{1};
};

int main(){
    Cylinder cylinder1;
    std::cout << "volume : " << cylinder1.volume() << std::endl;

    cylinder1.base_radius = 10;
    cylinder1.height = 3;
    std::cout << "volume : " << cylinder1.volume() << std::endl;

    cylinder1.height = 8;
    std::cout << "volume : " << cylinder1.volume() << std::endl;

    return 0;
}
```

---

### 🔍 Key Observations and Learnings

| Concept                              | Explanation                             |
| ------------------------------------ | --------------------------------------- |
| Class created using `class Cylinder` | Defines a blueprint                     |
| `base_radius` & `height`             | Member variables (properties)           |
| `volume()`                           | Member function that computes volume    |
| `Cylinder cylinder1;`                | Creates an object of class Cylinder     |
| Access with `.` operator             | `cylinder1.volume()`                    |
| Members are public here              | So we can modify radius/height directly |
| If members were private              | External access would be restricted     |

---

### 🎯 Important Points

✔ A class groups **data + functions** together <br>
✔ Methods have access to private & public members <br>
✔ Objects store real values at runtime <br>
✔ Good practice → **keep data private, expose functions** <br>
• Class member variables can either be raw stack variables or 
pointers <br>
 • Members can’t be references <br>
 • Classes have functions (methods) that let them do things <br>
 • Class methods have access to the member variables, regardless 
of whether they are public or private <br>
 • Private members of classes ( variables and functions) aren’t 
accessible from the outside of the class definition
<br>


---

### 🚀 Summary

| Class                         | Object                               |
| ----------------------------- | ------------------------------------ |
| Blueprint/Template            | Instance of class                    |
| No memory allocated           | Memory allocated when object created |
| Defines variables + functions | Stores actual values                 |

C++ classes enable **data encapsulation**, **modularity**, and **object-oriented programming**.

---



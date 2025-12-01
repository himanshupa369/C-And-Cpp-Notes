
---

# 🔥 **Arrow Operator (`->`) in C++**

When we have **an object pointer**, we use the **arrow notation `->`** to access members (variables/functions) of that object.

### **Why arrow (`->`) instead of dot (`.`)?**

| Object Type       | Access Operator |
| ----------------- | --------------- |
| Normal Object     | `.` (Dot)       |
| Pointer to Object | `->` (Arrow)    |

Because pointer stores *address*, so to access members C++ automatically performs:

```
(*ptr).member   ≡   ptr->member     // both same
```

---

## ⭐ Example: Using `.` vs `->`

```cpp
class Student {
public:
    std::string name;
    int age;

    void introduce() {
        std::cout << "Name: " << name << ", Age: " << age << "\n";
    }
};

int main(){
    Student s1;         // normal object
    s1.name = "Rahul";
    s1.age = 21;
    s1.introduce();     // dot operator

    Student *ptr = &s1; // Managing stack object through pointer
    ptr->name = "Aman"; // arrow operator
    ptr->age = 22;
    ptr->introduce();

    return 0;
}
```

### Output:

```
Name: Rahul, Age: 21
Name: Aman, Age: 22
```

---

# 📍 Memory Visualization

```
s1 --->
       [ name="Rahul" | age=21 ]

ptr ----> &s1 (points here)

ptr->age = 22
means
(*ptr).age = 22
```

---

## 🏷 Creating Objects Dynamically using `new` + Arrow

```cpp
Student *ptr = new Student();  // allocated on heap
ptr->name = "Kunal";
ptr->age = 19;
ptr->introduce();

delete ptr; // must free memory
```

---

## 🔥 A More Practical Class Example

```cpp
#include <iostream>

class Cylinder {
private:
    double radius;
    double height;
public:
    Cylinder(double r, double h) : radius(r), height(h) {}

    double volume() {
        return 3.14159 * radius * radius * height;
    }

    void setRadius(double r){ radius = r; }
    void setHeight(double h){ height = h; }
};

int main() {

    Cylinder *c = new Cylinder(5.0, 10.0); // pointer object
    std::cout << "Volume = " << c->volume() << "\n";

    c->setRadius(7.0);   // modify using arrow
    c->setHeight(15.0);

    std::cout << "Updated Volume = " << c->volume() << "\n";

    delete c;
}
```

---

## 🧠 When do we use pointer + `->` in real projects?

| Use Case                                    | Why Pointer/Arrow is Needed                 |
| ------------------------------------------- | ------------------------------------------- |
| Dynamic memory allocation (`new`)           | Object size unknown at compile time         |
| Linked lists, trees, graphs                 | Nodes store addresses to next element       |
| Smart pointers (`unique_ptr`, `shared_ptr`) | Managed memory objects -> operator          |
| Polymorphism & runtime binding              | Access derived objects through base pointer |

Example (smart pointer):

```cpp
#include <memory>

std::unique_ptr<Student> p = std::make_unique<Student>();
p->name = "Virat";   // arrow used here
p->introduce();
```

---

# 📝 Final Notes

| Feature           | Dot (`.`)     | Arrow (`->`)           |
| ----------------- | ------------- | ---------------------- |
| Normal object     | ✔ allowed     | ❌ not needed           |
| Pointer to object | ❌ invalid     | ✔ used                 |
| Meaning           | direct access | access through pointer |
| Equivalent form   | obj.member    | (*ptr).member          |

---

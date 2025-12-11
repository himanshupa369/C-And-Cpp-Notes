
---

# **Static Members in C++ — Complete Notes**

## **1. Regular (Non-static) Member Variables**

* These are the normal data members we declare inside a class.
* **Each object gets its own separate copy** of every non-static data member.
* When you create multiple objects, each object maintains its **own independent state**.
* Memory for these variables is allocated **inside the object**.
* If six objects are created, then six separate copies of each member variable exist.

### **Example**

```cpp
class Point {
    double x;
    double y;
};
```

If you create:

```cpp
Point p1, p2, p3;
```

Then:

* `p1.x` is different from `p2.x`
* different memory locations
* no sharing happens between objects

---

## **2. Why Static Members?**

Sometimes you need a variable:

* that is **not tied to an object**, and
* should be shared by **all instances** of a class
* that belongs to the **class blueprint**, not to each object

Example problem:

* You want to keep track of how many `Point` objects have been created.
* A regular member variable cannot be used:

  * It lives inside an object.
  * It gets destroyed when the object is destroyed.
  * It would require multiple copies for multiple objects.

Hence, we need something that belongs to the **class itself**.

---

## **3. Static Member Variables**

* Declared using keyword **`static`** inside the class.
* Only **one copy** exists in the entire program.
* Shared by **all objects** of that class.
* Lifetime:
  Exists until program ends (similar to global variables).
* Scope:
  Accessible using class name.

### **Syntax**

```cpp
class Point {
public:
    static size_t point_count;   // Declaration inside class
};
```

### **Definition outside the class (compulsory)**

```cpp
size_t Point::point_count = 0;   // Allocation & initialization
```

---

## **4. How Static Members Work**

If you create objects like:

```cpp
Point p1;
Point p2;
```

You can increment the counter in the constructor:

```cpp
Point::point_count++;
```

### **Effect**

* After `p1`, count = 1
* After `p2`, count = 2
* Both objects share the same single variable.

---

## **5. Characteristics of Static Members**

| Property                         | Static Member               | Non-static Member  |
| -------------------------------- | --------------------------- | ------------------ |
| Belongs to                       | Class                       | Individual object  |
| Memory allocated                 | Once                        | Per object         |
| Accessed using                   | Class::member or obj.member | Requires an object |
| Lifetime                         | Entire program              | Lifetime of object |
| Shares value with other objects? | Yes                         | No                 |

---

## **6. When to Use Static Members**

Use static members when:

* You need a counter shared by all objects.
* You need configuration values common to all objects.
* You want to maintain global state but keep it **inside the class** (not as global variables).

---

## **7. Key Takeaways**

1. **Static members are tied to the class, not objects.**
2. **Only one instance exists**, shared among all objects.
3. Regular members are stored inside each object; static members are stored separately.
4. You must **define static variables outside** the class.
5. Common usage example: **object counters**.

---


---

# **Deleted Constructors in C++ — Complete Notes**

## **1. Introduction**

Deleted constructors are a C++ mechanism that allows a developer to **explicitly disable** specific constructors.
When a constructor is marked as deleted, the compiler **forbids** the program from using or invoking that constructor.
Any attempt to use that constructor results in a **compile-time error**.

This feature is part of C++11 and later.

---

## **2. Why Delete Constructors?**

You delete constructors when certain operations **must not be allowed**, such as:

* You don’t want objects to be created in certain ways (e.g., no default construction).
* You want to **prevent copying** or **moving** of objects (common in resource-managing classes).
* You want to enforce a **special construction pattern**.

Deleted constructors give precise control over object-creation semantics.

---

## **3. Syntax**

```cpp
ClassName() = delete;            // Delete default constructor
ClassName(const ClassName&) = delete;  // Delete copy constructor
ClassName(ClassName&&) = delete;       // Delete move constructor
```

---

## **4. Example**

### **Header (Point.h)**

```cpp
class Point {
public:
    Point() = delete;                     // Default constructor deleted
    Point(const Point&) = delete;         // Copy constructor deleted
    Point(Point&&) = delete;              // Move constructor deleted

    Point(double x, double y);            // Only allowed constructor

    void print() const;
};
```

### **Usage in main**

```cpp
int main() {
    Point p1(10.5, 20.9);   // OK: allowed constructor
    p1.print();

    Point p2;               // Error: default constructor deleted
    Point p3 = p1;          // Error: copy constructor deleted
    Point p4 = std::move(p1); // Error: move constructor deleted

    return 0;
}
```

---

## **5. What Happens When Deleted Constructors Are Called?**

If a deleted constructor is used, the compiler generates an error similar to:

```
error: use of deleted function ‘Point::Point()’
error: use of deleted function ‘Point::Point(const Point&)’
error: use of deleted function ‘Point::Point(Point&&)’
```

This ensures no invalid object creation occurs.

---

## **6. Real-World Use Cases**

### **(1) Preventing Default Construction**

Sometimes an object must always be constructed with specific parameters.

Example:
A “FileHandle” class must always receive a filename.

### **(2) Preventing Copying**

Copying resource-managing objects (mutexes, file handles, sockets) leads to undefined behavior.

Common in RAII classes:

```cpp
std::mutex m; // cannot be copied
```

### **(3) Preventing Moving**

If moving could break invariants, you delete the move constructor.

### **(4) Singleton Pattern Enforcement**

Deleting copy and move constructors enforces a Singleton's uniqueness.

---

## **7. Benefits (Pros)**

* **Compile-time safety**: Prevents dangerous or invalid object creation.
* **Clear intent**: Code explicitly communicates which constructors are allowed.
* **Prevents object slicing** in certain designs.
* **Protects invariants** inside classes by restricting unsupported build paths.
* **Essential for RAII classes** to prevent resource duplication.

---

## **8. Limitations (Cons)**

* Sometimes makes the class less flexible.
* Developers must now use the allowed constructor exactly as defined.
* If overused, can make classes difficult to work with and test.

---

## **9. C++ Version Information**

* **Introduced in C++11**.
* Supported in all later standards (C++14, C++17, C++20, C++23, C++26).

---

## **10. Summary**

Deleted constructors are used to **ban specific ways of creating or copying objects**.
By marking constructors as `= delete`, C++ gives developers fine-grained control over object construction and prevents errors at compile time. This technique is essential in writing robust C++ classes, especially those managing resources.

---


---

## 📘 **Basic Class Interview Questions**

---

### 1. **What is a class in C++?**

A class is a **user-defined data type** that binds data and functions. It's the foundation of **object-oriented programming**.

```cpp
class MyClass {
  int x;                // Data member
public:
  void setX(int val);   // Member function
};
```

---

### 2. **What is the difference between class and struct?**

| Feature        | `class`       | `struct`   |
| -------------- | ------------- | ---------- |
| Default access | `private`     | `public`   |
| OOP Features   | Yes           | Yes        |
| Use case       | Complex types | Plain data |

---

### 3. **What are access specifiers?**

* `public`: Accessible from anywhere
* `private`: Accessible only inside the class
* `protected`: Accessible inside class and derived classes

---

### 4. **How do you define a constructor and destructor?**

```cpp
class MyClass {
public:
  MyClass();     // Constructor
  ~MyClass();    // Destructor
};
```

---

## 🔄 **Intermediate / Practical Questions**

---

### 5. **What is the Rule of 3 / Rule of 5?**

If you define one of these, define all:

* Copy Constructor
* Copy Assignment Operator
* Destructor

C++11 adds:

* Move Constructor
* Move Assignment Operator

---

### 6. **What is the difference between shallow copy and deep copy?**

* **Shallow copy** copies pointer values → same memory.
* **Deep copy** duplicates memory contents → safe.

---

### 7. **Explain this pointer in class.**

`this` is a pointer to the current object.

```cpp
class MyClass {
  int x;
public:
  MyClass(int x) {
    this->x = x;   // Resolve ambiguity
  }
};
```

---

### 8. **What is a static member in a class?**

* Shared among all objects.
* Exists independently of any instance.

```cpp
class A {
public:
  static int count;
};
```

---

### 9. **Can a constructor be virtual?**

❌ No. Constructors can't be virtual, but destructors **should be virtual** if using polymorphism.

---

### 10. **What is friend function/class?**

* Can access private members of the class.
* Used for operator overloading or bridging access.

```cpp
class A {
  friend void show(A&);
};
```

---

## 🧠 **Advanced Conceptual Questions**

---

### 11. **What is data hiding and encapsulation?**

* **Data hiding**: Restricting direct access (private members).
* **Encapsulation**: Bundling data and methods.

---

### 12. **What is function overloading vs overriding?**

| Concept   | Overloading              | Overriding                       |
| --------- | ------------------------ | -------------------------------- |
| Scope     | Same class               | Base and Derived class           |
| Signature | Different parameter list | Same function signature          |
| Keyword   | No keyword               | Requires `virtual` in base class |

---

### 13. **What are inline member functions?**

Defined inside class body — compiler may inline them for performance.

---

### 14. **What is the use of `mutable` keyword in class?**

Allows a **member variable to be modified** even in a `const` function.

```cpp
class A {
  mutable int counter;
public:
  void increment() const { counter++; }
};
```

---

### 15. **How is memory allocated for class objects?**

* Data members: per object
* Static members: one copy for entire class

---

## 👨‍💼 Post-Internship Class-based Behavioral/Project Questions

---

### 16. **Can you explain a class you designed during your internship?**

* What were the data members and functions?
* Did you use encapsulation or inheritance?
* What problems did you face?

---

### 17. **Did you implement any design patterns using classes?**

* Singleton, Factory, Observer, etc.?

---

### 18. **How did you manage class dependencies?**

* Composition vs inheritance
* Use of interfaces (abstract classes)

---

### 19. **Did you use smart pointers in your class? Why?**

If yes, explain use of `std::unique_ptr`, `std::shared_ptr` for memory safety.

---

### 20. **Have you written a class with dynamic memory? How did you manage it?**

Talk about:

* Using `new`/`delete`
* Rule of 3/5
* Custom destructor or copy constructors

---

---

## 🔰 **Basic Object-Oriented Questions**

---

### 1. **What is an object in C++?**

An **object** is an **instance of a class**. It represents a real-world entity with **state** (data members) and **behavior** (member functions).

```cpp
class Car {
public:
    int speed;
    void drive() { /*...*/ }
};

Car myCar; // Object of class Car
```

---

### 2. **How is an object different from a class?**

| Aspect     | Class               | Object                      |
| ---------- | ------------------- | --------------------------- |
| Definition | Blueprint/template  | Instance created from class |
| Memory     | No memory allocated | Memory allocated            |

---

### 3. **How do you create objects in C++?**

* **Stack**: `MyClass obj;`
* **Heap**: `MyClass* ptr = new MyClass();`

---

### 4. **Can objects be passed to a function?**

Yes, in 3 ways:

```cpp
void func(MyClass obj);       // Pass by value
void func(MyClass& obj);      // Pass by reference
void func(const MyClass* obj); // Pass by pointer
```

---

### 5. **What happens when you copy an object?**

The **copy constructor** is invoked.

```cpp
MyClass a;
MyClass b = a; // invokes copy constructor
```

---

## 🔧 **Object Lifecycle & Memory Questions**

---

### 6. **What is object lifetime in C++?**

Depends on where and how it's created:

* Stack object: Lifetime ends at scope exit
* Heap object: Lifetime ends when `delete` is called

---

### 7. **What is a temporary object?**

An unnamed object created during expression evaluation.

Example:

```cpp
MyClass();       // temporary object
func(MyClass()); // passed to function as temporary
```

---

### 8. **What is the use of `this` pointer with objects?**

`this` points to the current object inside member functions.

```cpp
class A {
public:
  int x;
  void setX(int x) { this->x = x; }
};
```

---

### 9. **How are objects stored in memory?**

* Stack: Direct memory allocation
* Heap: Stores object via pointer
* Static members: Single memory allocation shared among all objects

---

### 10. **What happens if you use an object before initialization?**

* Stack object: Initializes default values (if default constructor exists)
* Heap object via `new`: Constructor is called
* Uninitialized pointers: ❌ **Undefined behavior**

---

## 🧠 **Advanced / Tricky Questions**

---

### 11. **How to create an array of objects?**

```cpp
MyClass arr[5];            // Stack
MyClass* arr = new MyClass[5]; // Heap
```

---

### 12. **What is Object Slicing?**

When a derived object is assigned to a base object **by value**, extra data from derived class is "sliced off".

```cpp
class Base { };
class Derived : public Base { };
Base b = Derived(); // Slicing occurs
```

---

### 13. **What is the difference between object and reference to object?**

```cpp
MyClass obj;       // Actual object
MyClass& ref = obj; // Reference (alias)
```

---

### 14. **What is the purpose of `const` objects?**

Ensures that no member function can modify the object.

```cpp
const MyClass obj;
obj.getValue(); // ok if getValue() is a const member function
```

---

### 15. **Can you make an object `const` and still call member functions?**

Yes, but only those marked as `const`:

```cpp
int getVal() const;
```

---

## 👨‍💻 Post-Internship / Project-Based Object Questions

---

### 16. **How did you manage object creation and destruction in your project?**

Mention:

* Constructors/destructors
* Resource management
* Smart pointers if used

---

### 17. **Did you use any design pattern involving objects?**

Examples:

* Factory (object creation)
* Singleton (single object)

---

### 18. **How did you handle large object copies?**

Answer:

* Used **move constructor**
* Passed by reference (`const &`)
* Avoided deep copy unless necessary

---

### 19. **Can you overload operators for an object?**

Yes:

```cpp
MyClass operator+(const MyClass&);
```

---

### 20. **What’s the difference between static object and normal object?**

* Static object retains value **between function calls**
* It’s destroyed only at program termination

```cpp
void func() {
  static MyClass obj;
}

class Demo {
    int x;
public:
    void setX(int val) { x = val; }
    int getX() const { return x; }
};

int main() {
    Demo a;             // Non-const
    a.setX(5);          // ✅ OK
    a.getX();           // ✅ OK

    const Demo b;       // Const object
    b.getX();           // ✅ OK (const method)
    b.setX(10);         // ❌ Error (non-const method)
}

```

---

---

## 📝 **Basic Questions**

---

### 1. **What are access specifiers in C++?**

Access specifiers control the visibility of class members (variables and functions) from outside the class. The three access specifiers in C++ are:

* **`public`**: Members are accessible from anywhere.
* **`private`**: Members are accessible only within the class.
* **`protected`**: Members are accessible within the class and derived classes.

---

### 2. **What is the default access specifier for members of a class and a struct?**

* **Class**: The default access specifier is **`private`**.
* **Struct**: The default access specifier is **`public`**.

```cpp
class MyClass {    // By default, members are private
    int x;
};

struct MyStruct {  // By default, members are public
    int x;
};
```

---

### 3. **Can you explain `public`, `private`, and `protected` in detail?**

* **`public`**: Members are accessible from any function or class.

  ```cpp
  class MyClass {
  public:
      int x;  // Accessible from anywhere
  };
  ```

* **`private`**: Members are **only accessible** within the class itself or through **friend functions**.

  ```cpp
  class MyClass {
  private:
      int x;  // Not accessible outside the class
  };
  ```

* **`protected`**: Members are accessible in the class and derived classes, but not from outside.

  ```cpp
  class Base {
  protected:
      int x;
  };

  class Derived : public Base {
  public:
      void setX(int val) {
          x = val;  // Protected members can be accessed in derived classes
      }
  };
  ```

---

## 🔧 **Intermediate Questions**

---

### 4. **What is the role of `friend` in access specifiers?**

A **friend function** or class can access the private and protected members of another class.

```cpp
class MyClass {
private:
    int x;
    friend void show(MyClass& obj);  // Friend function can access private members
};

void show(MyClass& obj) {
    cout << obj.x;  // Accessing private member
}
```

---

### 5. **Can `protected` members be accessed outside the class?**

No, `protected` members are **not accessible** directly outside the class, but they are accessible to **derived classes**.

```cpp
class Base {
protected:
    int x;
};

class Derived : public Base {
public:
    void setX(int val) {
        x = val;  // Protected members are accessible in derived classes
    }
};

int main() {
    Base obj;
    // obj.x = 10;   // ❌ Error: x is protected and not accessible outside
}
```

---

### 6. **Can a class have private constructors?**

Yes, a class can have **private constructors**. This is often used in the **Singleton** design pattern to prevent object creation outside the class.

```cpp
class Singleton {
private:
    Singleton() {}  // Private constructor
public:
    static Singleton* getInstance() {
        static Singleton instance;
        return &instance;
    }
};
```

---

### 7. **What happens when access specifiers are not mentioned explicitly?**

* In a **class**, the default access specifier is **`private`**.
* In a **struct**, the default access specifier is **`public`**.

```cpp
class MyClass {
    int x; // private by default
};

struct MyStruct {
    int x; // public by default
};
```

---

## 🔑 **Advanced Questions**

---

### 8. **Can a derived class access private members of its base class?**

No, a derived class **cannot access private members** of its base class directly. However, it can access **protected** members.

```cpp
class Base {
private:
    int x;
public:
    int getX() { return x; }  // Public getter
};

class Derived : public Base {
public:
    void access() {
        // x = 10;  // ❌ Error: private member cannot be accessed directly
        int val = getX();  // ✅ OK: Access through public method
    }
};
```

---

### 9. **What is the difference between private inheritance and protected inheritance?**

* **Private Inheritance**: The base class members (public and protected) become **private** in the derived class.

  ```cpp
  class Base { 
  public: 
      int x; 
  };

  class Derived : private Base { 
      // x is now private
  };
  ```

* **Protected Inheritance**: The base class members (public and protected) become **protected** in the derived class.

  ```cpp
  class Derived : protected Base { 
      // x is now protected
  };
  ```

---

### 10. **Can a member be both `private` and `protected` in a class?**

No, a member cannot have multiple access specifiers. However, a class can have **different** access specifiers for different members.

```cpp
class MyClass {
private:
    int x;
protected:
    int y;
public:
    int z;
};
```

---

### 11. **Can you change the access specifier of a base class member in a derived class?**

Yes, you can change the accessibility of base class members in a derived class, but it only works for **`protected`** and **`public`** members. This is called **access specifier change** or **"redefining"** access.

```cpp
class Base {
protected:
    int x;
};

class Derived : public Base {
public:
    void setX(int val) {
        x = val; // Allowed because x is protected in Base
    }
};
```

But **private members** cannot be accessed or modified by a derived class.

---

### 12. **What is the difference between `public` inheritance and `private` inheritance?**

* **Public inheritance**: Public and protected members of the base class are inherited as public and protected in the derived class respectively.

* **Private inheritance**: Public and protected members of the base class become private in the derived class.

```cpp
class Base {
public:
    int x;
};

class DerivedPublic : public Base { // Public inheritance
    void access() {
        x = 10;  // x is public in DerivedPublic
    }
};

class DerivedPrivate : private Base { // Private inheritance
    void access() {
        x = 10;  // x is private in DerivedPrivate
    }
};
```

---

---

## ✅ **Basic-Level Questions**

---

### 1. **What is a constructor in C++?**

> A constructor is a special member function that is **automatically called** when an object is created. It is used to **initialize** objects of a class.

---

### 2. **What are the characteristics of constructors?**

* Same name as the class.
* No return type (not even `void`).
* Can be overloaded.
* Called automatically when object is created.

---

### 3. **Types of constructors in C++?**

* **Default Constructor**
* **Parameterized Constructor**
* **Copy Constructor**
* **Move Constructor** (C++11)
* **Delegating Constructor** (C++11)
* **Explicit Constructor**
* **Conversion Constructor**

---

### 4. **What is a default constructor?**

> A constructor with **no parameters** or with **default values** for all parameters.

```cpp
class A {
public:
    A() {
        cout << "Default Constructor" << endl;
    }
};
```

---

### 5. **What is a parameterized constructor?**

> A constructor that takes one or more arguments to initialize an object.

```cpp
class A {
public:
    int x;
    A(int val) { x = val; }
};
```

---

### 6. **What is a copy constructor?**

> A constructor that initializes an object by copying another object of the same class.

```cpp
class A {
public:
    int x;
    A(int val) { x = val; }
    A(const A &obj) { x = obj.x; }
};
```

---

### 7. **What is the syntax of an initializer list in constructors?**

```cpp
class A {
    int x;
public:
    A(int val) : x(val) {}  // Initializes x directly
};
```

---

## 🔧 **Intermediate-Level Questions**

---

### 8. **Can constructors be overloaded?**

> Yes. You can define multiple constructors with different parameter lists (constructor overloading).

---

### 9. **Can we define a constructor as `virtual`?**

> ❌ No. Constructors **cannot be virtual** because the object is not fully constructed when the constructor is running.

---

### 10. **Can a constructor be private or protected?**

> ✅ Yes. Often used in:

* **Singleton pattern** (private constructor)
* **Factory methods**
* Preventing instantiation from outside

---

### 11. **What happens if you do not define any constructor in your class?**

> C++ provides a **default constructor** automatically only if **no other constructor** is defined.

---

### 12. **What is a conversion constructor?**

> A constructor that takes a **single argument** and allows **implicit conversion** from that type to the class type.

```cpp
class A {
public:
    A(int val) { ... }  // Can convert int to A
};
```

---

### 13. **What is an `explicit` constructor?**

> Used to **prevent implicit conversions** by constructors with a single parameter.

```cpp
class A {
public:
    explicit A(int val) { ... }
};
```

---

### 14. **What is a delegating constructor?** *(C++11)*

> One constructor calls another constructor of the same class.

```cpp
class A {
    int x;
public:
    A() : A(0) {}               // Delegates to parameterized constructor
    A(int val) : x(val) {}
};
```

---

### 15. **What is a move constructor?** *(C++11)*

> Optimizes performance by transferring resources from one object to another instead of copying.

```cpp
class A {
    int* ptr;
public:
    A(A&& other) {
        ptr = other.ptr;
        other.ptr = nullptr;
    }
};
```

---

## 🚀 **Advanced-Level Questions**

---

### 16. **What is constructor delegation and how is it different from inheritance?**

* Delegation = constructor calls another constructor **within the same class**
* Inheritance = derived class constructor **calls base class constructor**

---

### 17. **Can a constructor call another constructor of the same class?**

> ✅ Yes, using delegating constructor syntax (`: this(args)` in Java or `: ClassName(args)` in C++11)

---

### 18. **Can a constructor throw an exception?**

> ✅ Yes, but constructor must handle resource cleanup or use RAII.

---

### 19. **What is the order of constructor calls in inheritance?**

> **Base class constructor** is called **first**, then the **derived class constructor**.

---

### 20. **How is constructor invocation different in aggregation and inheritance?**

* **Inheritance**: Base constructor called implicitly or explicitly by derived.
* **Aggregation**: Member objects' constructors called before outer object’s constructor.

---

---

## ✅ **Basic-Level Questions**

---

### 1. \*\*What is a destructor in C++?

> A destructor is a special member function that is **automatically called** when an object goes out of scope or is deleted, to release resources.

---

### 2. **What is the syntax of a destructor?**

```cpp
class MyClass {
public:
    ~MyClass() {
        // Destructor body
    }
};
```

* It has the same name as the class, preceded by a `~` symbol.
* It **does not** take arguments and **cannot be overloaded**.

---

### 3. **What are the properties of a destructor?**

* No return type.
* No parameters.
* Cannot be overloaded.
* Automatically invoked when object is destroyed.
* Used to release resources like memory, file handles, etc.

---

### 4. **Does a class have a default destructor if none is defined?**

> ✅ Yes. If you don’t provide a destructor, the compiler provides a **default** one.

---

### 5. **When is a destructor called?**

* When a **local object** goes out of scope.
* When an object is **explicitly deleted** using `delete`.
* When the program exits and global/static objects are cleaned up.

---

## 🔧 **Intermediate-Level Questions**

---

### 6. **Can you overload a destructor in C++?**

> ❌ No. A class can have **only one destructor** and it cannot be overloaded.

---

### 7. **What happens if the destructor is not virtual in a base class?**

> If a base class has a non-virtual destructor and you delete a derived object via a base pointer, it leads to **undefined behavior**.

```cpp
class Base {
public:
    ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived Destructor\n"; }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // ❌ Only Base destructor called
}
```

✅ Fix:

```cpp
class Base {
public:
    virtual ~Base() { cout << "Base Destructor\n"; }
};
```

---

### 8. **What is a virtual destructor?**

> A destructor declared with the `virtual` keyword to ensure **proper cleanup** of derived objects when deleting through a base pointer.

---

### 9. **Why should you use virtual destructors in base classes?**

> To ensure the **entire object hierarchy** is destroyed correctly when deleting via a base pointer.

---

### 10. **What is the order of destructor calls in inheritance?**

> Destructors are called in **reverse order of construction**:

* Derived destructor is called first
* Then base class destructor is called

```cpp
class Base {
public:
    ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived Destructor\n"; }
};
```

Output:

```
Derived Destructor
Base Destructor
```

---

### 11. **Can a destructor be `const`, `static`, or `virtual`?**

| Modifier  | Valid? | Explanation                            |
| --------- | ------ | -------------------------------------- |
| `const`   | ❌ No   | Makes no sense semantically.           |
| `static`  | ❌ No   | Destructor is tied to object instance. |
| `virtual` | ✅ Yes  | Allows polymorphic cleanup.            |

---

### 12. **What if we throw an exception from a destructor?**

> **Bad practice**. If a destructor throws an exception during stack unwinding, it leads to `std::terminate()` being called.

Use `try-catch` inside destructors.

---

## 🚀 **Advanced-Level Questions**

---

### 13. **Can you manually call a destructor?**

> ✅ Yes, using placement new technique.

```cpp
MyClass* p = new MyClass();
p->~MyClass();   // Manually calling destructor
```

But this is **dangerous** and rarely needed unless you're using placement `new`.

---

### 14. **How is memory cleaned up in case of composition (member objects)?**

> Destructors of **member objects** are automatically called when the parent object is destroyed.

---

### 15. **What is RAII in C++?**

> **Resource Acquisition Is Initialization**: A design principle where resources are tied to object lifetime and cleaned in destructor.

Example: `std::lock_guard`, `std::fstream`, `std::unique_ptr`

---

### 16. **What is the difference between destructor and `delete`?**

| `~Destructor()`                    | `delete`                             |
| ---------------------------------- | ------------------------------------ |
| Cleans up object memory internally | Destroys object & deallocates memory |
| User-defined cleanup               | Keyword to release heap memory       |
| Called automatically or manually   | Used with dynamic allocation (`new`) |

---

### 17. **What is the difference between destructor and finalizer in other languages (like Java)?**

* C++: Deterministic destruction via scope or `delete`
* Java: Finalizers are non-deterministic (Garbage Collected)
* C++ gives **control**, Java relies on GC

---

## 🧪 Example for Virtual Destructor Use

```cpp
class Base {
public:
    virtual ~Base() { cout << "Base destroyed\n"; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived destroyed\n"; }
};

int main() {
    Base* ptr = new Derived;
    delete ptr;  // Calls both destructors due to virtual
}
```

---

## ✅ Summary Table

| Feature               | Destructor       |
| --------------------- | ---------------- |
| Overloadable?         | ❌ No             |
| Parameters allowed?   | ❌ No             |
| Virtual allowed?      | ✅ Yes            |
| Callable manually?    | ✅ Yes (but rare) |
| Automatically called? | ✅ Yes            |

---

---

## ✅ **1. Basic Concept**

| Feature                    | **Static Member Function**   | **Non-Static Member Function** |
| -------------------------- | ---------------------------- | ------------------------------ |
| Belongs to                 | Class itself                 | Object (instance of class)     |
| Access via                 | Class name or object         | Only via object                |
| Uses `this` pointer        | ❌ No                         | ✅ Yes                          |
| Access to instance members | ❌ No (unless using object)   | ✅ Yes                          |
| Memory allocation          | Allocated once for the class | Separate for each object       |

---

## ✅ **2. Syntax Example**

```cpp
class Demo {
    int x;
    static int count;

public:
    Demo(int val) : x(val) { count++; }

    static void showCount() {  // Static Function
        cout << "Count = " << count << endl;
    }

    void showX() const {       // Non-static Function
        cout << "X = " << x << endl;
    }
};
```

```cpp
Demo::showCount();  // ✅ Valid
Demo obj(10);
obj.showX();        // ✅ Valid
```

---

## ✅ **3. Interview-Oriented Differences**

| Aspect                       | **Static Function**                                | **Non-Static Function**  |
| ---------------------------- | -------------------------------------------------- | ------------------------ |
| `this` pointer               | ❌ Not available                                    | ✅ Implicitly passed      |
| Access to static members     | ✅ Yes                                              | ✅ Yes                    |
| Access to non-static members | ❌ No                                               | ✅ Yes                    |
| Called on                    | Class name or object                               | Object only              |
| Use-case                     | Class-level operations (e.g., counters, utilities) | Object-specific behavior |

---

## ✅ **4. Common Interview Questions**

### 🔹 Q1: Can a static function access non-static data members?

**No**, because it doesn’t have access to the `this` pointer or instance data.

### 🔹 Q2: Can static and non-static functions have the same name?

**Yes**, via overloading, but they must differ in signature.

### 🔹 Q3: Can a static function be `const`?

**No**, `const` applies to `this`, which static functions do not have.

### 🔹 Q4: Where is static function memory stored?

In the **code segment**, shared among all objects of the class.

---

## ✅ **5. Use-Cases**

| Use-Case                    | Static Function                 |
| --------------------------- | ------------------------------- |
| Counting objects            | ✔️ Use static counter           |
| Utility/helper inside class | ✔️ No need for object           |
| Factory design pattern      | ✔️ Often static factory methods |

| Use-Case                           | Non-Static Function    |
| ---------------------------------- | ---------------------- |
| Access object-specific data        | ✔️ Like `x`, `y`, etc. |
| Polymorphism via virtual functions | ✔️ Only non-static     |

---

## 🧠 Example Interview Snippet

**Q:** “What happens if you try to access non-static data from a static function?”

**A:** Compilation error. Static functions don’t have `this`, so they cannot refer to instance data.

---



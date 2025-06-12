
---

## 🔒 What is **Encapsulation**?

> **Encapsulation** is an **Object-Oriented Programming (OOP)** principle where **data (variables)** and **methods (functions)** that operate on the data are **bundled together** into a single unit — typically a **class** — and the **access to the internal details is restricted**.

---

## ✅ Key Points

| Feature      | Explanation                                                         |
| ------------ | ------------------------------------------------------------------- |
| Main goal    | Hide internal data from outside world                               |
| Achieved via | Access specifiers: `private`, `protected`, `public`                 |
| Access       | Only through **public methods (getters/setters)**                   |
| Benefit      | Improves **data security**, **modularity**, and **maintainability** |

---

## 💡 Real-life Analogy

Think of a **capsule (medicine)** — you can’t see what's inside, but you get the effect by taking it.

Similarly:

* **Class** = capsule
* **Private data** = hidden medicine
* **Public functions** = controlled way to "use" it

---

## 🧾 C++ Example of Encapsulation

```cpp
class BankAccount {
private:
    double balance;  // ✅ Encapsulated: only accessible through methods

public:
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account;
    account.deposit(1000);
    cout << "Balance: " << account.getBalance();  // ✅ Controlled access
}
```

---

## 🎯 Benefits of Encapsulation

* ✅ Data hiding: prevents accidental or unauthorized changes
* ✅ Security: internal state is not exposed
* ✅ Flexibility: implementation can change without affecting users
* ✅ Reusability: clear, modular code

---

## ❓ Common Interview Questions

### 🔹 Q1: How is encapsulation implemented in C++?

> Using **classes** and **access specifiers** (`private`, `public`, `protected`).

---

### 🔹 Q2: Difference between encapsulation and abstraction?

| Encapsulation                 | Abstraction                          |
| ----------------------------- | ------------------------------------ |
| Hides **how** things are done | Hides **what** is done               |
| Focus: implementation hiding  | Focus: essential features            |
| Done via classes              | Done via abstract classes/interfaces |

---

### 🔹 Q3: Can encapsulation be broken?

> Technically, yes (via friend functions or pointers), but it's discouraged and breaks design principles.

---

### 🔹 Q4: Is encapsulation possible without private data?

> No. If everything is public, there's **no data hiding** — hence, **no encapsulation**.

---

### 🔹 Q5: Give a real-life system that uses encapsulation?

> **ATM machine**:

* You interact via screen & buttons (interface).
* You don’t access cash storage or software logic (internal data hidden).

---

## 🔐 Summary Table

| Concept              | Encapsulation                     |
| -------------------- | --------------------------------- |
| Data hiding          | ✅ Yes                             |
| Achieved via         | Access specifiers in classes      |
| Allows               | Controlled access to data         |
| Helps in             | Security, maintenance, modularity |
| Related OOP concepts | Abstraction, Information hiding   |

---

---

## 🎭 What is **Abstraction**?

> **Abstraction** is an **OOP principle** that hides **complex implementation details** and exposes only the **essential features** to the user.

You focus on **what** an object does, not **how** it does it.

---

## ✅ Key Points

| Feature         | Description                                                           |
| --------------- | --------------------------------------------------------------------- |
| Purpose         | Hide complexity and show only essentials                              |
| Achieved in C++ | Through **abstract classes**, **interfaces** (pure virtual functions) |
| Access          | Implementation hidden, interface exposed                              |
| Benefit         | Helps in **scalability**, **maintenance**, and **security**           |

---

## 💡 Real-life Analogy

**Car**:

* You use steering, brakes, accelerator (**interface**)
* You don’t care how the engine works, fuel injects, or sensors operate (**implementation is abstracted**)

---

## 🔧 Abstraction in C++ – Example

### ✅ Using **Abstract Class (pure virtual functions)**

```cpp
class Animal {
public:
    virtual void sound() = 0;  // Pure virtual ⇒ abstract
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark!" << endl;
    }
};
```

* `Animal` is an **abstract class**
* `Dog` **implements** the abstract function

---

## 🔍 Key Concepts

| Concept                   | Explanation                                   |
| ------------------------- | --------------------------------------------- |
| **Abstract class**        | Class with at least one pure virtual function |
| **Pure virtual function** | `virtual void f() = 0;`                       |
| **Interface in C++**      | A class with **only pure virtual functions**  |

---

## 🔐 Access Modifiers in Abstraction

* Implementation logic is kept in **private/protected**
* Interface is provided via **public** methods

---

## 🚀 Benefits of Abstraction

* ✅ Hides unnecessary details
* ✅ Enhances modularity
* ✅ Makes large codebases maintainable
* ✅ Supports scalable system design (like plugin-based systems)

---

## ❓ Interview Questions on Abstraction

### 🔹 Q1: What is abstraction in C++?

> Abstraction is the process of hiding internal details and showing only functionality to the user.

---

### 🔹 Q2: How is abstraction achieved in C++?

> Using **abstract classes** and **pure virtual functions**.

---

### 🔹 Q3: What is the difference between encapsulation and abstraction?

| Encapsulation                  | Abstraction                              |
| ------------------------------ | ---------------------------------------- |
| Hides data (how it's stored)   | Hides implementation (how it works)      |
| Achieved via access specifiers | Achieved via abstract classes/interfaces |
| Data-oriented                  | Behavior-oriented                        |

---

### 🔹 Q4: Can we instantiate an abstract class?

> ❌ No. You must inherit and implement all pure virtual functions.

---

### 🔹 Q5: Is it possible to have a class with no data members and only pure virtual functions?

> ✅ Yes, that becomes an **interface**, similar to Java/C#.

---

## 📘 Quick Summary Table

| Feature      | Abstraction                                                   |
| ------------ | ------------------------------------------------------------- |
| Focus        | Hiding complexity                                             |
| Achieved via | Abstract classes, pure virtual functions                      |
| Enables      | Interfaces, scalable architecture                             |
| Example      | `Animal` base class with `sound()` as a pure virtual function |
| Keyword      | `virtual`, `= 0`                                              |

---

---

## 🧬 What is **Inheritance** in C++?

> **Inheritance** is an OOP principle where a class (**derived/child**) **inherits** the properties and behaviors of another class (**base/parent**).

It promotes **code reuse**, **extensibility**, and models **"is-a" relationships**.

---

## ✅ Key Terminology

| Term             | Meaning                                                   |
| ---------------- | --------------------------------------------------------- |
| Base class       | The class whose members are inherited                     |
| Derived class    | The class that inherits members                           |
| Access Specifier | Controls accessibility (`public`, `protected`, `private`) |

---

## 🔧 Basic Example

```cpp
class Animal {
public:
    void eat() {
        cout << "Eating...\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking...\n";
    }
};

int main() {
    Dog d;
    d.eat();   // Inherited
    d.bark();  // Own method
}
```

---

## 🏷️ Types of Inheritance in C++

| Type             | Example Syntax          | Description                                           |
| ---------------- | ----------------------- | ----------------------------------------------------- |
| **Single**       | `class B : public A`    | One base → one derived                                |
| **Multiple**     | `class C : public A, B` | Two or more base classes                              |
| **Multilevel**   | A → B → C               | Chain of inheritance                                  |
| **Hierarchical** | A → B, A → C            | One base, multiple derived                            |
| **Hybrid**       | Combination of above    | May need **virtual inheritance** to resolve ambiguity |

---

## 🎯 Access Specifier Impact

### Syntax:

```cpp
class Derived : [access] Base { ... };
```

| Inherited as  | Public in Base | Protected in Base | Private in Base |
| ------------- | -------------- | ----------------- | --------------- |
| **Public**    | public         | protected         | ❌ inaccessible  |
| **Protected** | protected      | protected         | ❌ inaccessible  |
| **Private**   | private        | private           | ❌ inaccessible  |

---

## 🔀 Virtual Inheritance (to prevent Diamond Problem)

```cpp
class A { public: void say() {} };
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};
```

* Without virtual: multiple copies of `A` in `D`.
* With virtual: one shared instance.

---

## ✅ Real-life Analogy

* **Base class:** `Vehicle`
* **Derived classes:** `Car`, `Truck`, `Bike`
* All vehicles **share common properties** (speed, fuel), but also have **unique behavior**.

---

## 🎯 Interview Questions on Inheritance

### 🔹 Q1: What is inheritance?

> Inheritance allows a class to acquire properties and behaviors of another class.

---

### 🔹 Q2: What is the difference between `public`, `protected`, and `private` inheritance?

| Inheritance Type | External Access                              | Derived Class Access  |
| ---------------- | -------------------------------------------- | --------------------- |
| Public           | ✅ (base's public stays public)               | ✅                     |
| Protected        | ❌ (base's public/protected become protected) | ✅                     |
| Private          | ❌ (everything becomes private)               | ✅ only within derived |

---

### 🔹 Q3: What is the Diamond Problem?

> Occurs in **multiple inheritance** when two base classes inherit from a common class, and a derived class inherits from both → leads to ambiguity.

✅ Resolved using **virtual inheritance**.

---

### 🔹 Q4: Can constructors be inherited?

> ❌ No, but **base class constructors can be called** using initializer list.

---

### 🔹 Q5: What’s the difference between composition and inheritance?

| Inheritance           | Composition          |
| --------------------- | -------------------- |
| "Is-a" relationship   | "Has-a" relationship |
| Extends functionality | Uses functionality   |
| Compile-time binding  | More flexible        |

---

## 📝 Summary Table

| Feature       | Inheritance                     |
| ------------- | ------------------------------- |
| Principle     | Code reuse via base classes     |
| Syntax        | `class Derived : public Base`   |
| Benefits      | Reusability, extensibility      |
| Drawback      | Diamond Problem, tight coupling |
| Resolved with | Virtual inheritance             |

---

---

## 💎 What is the **Diamond Problem** in C++?

> The **Diamond Problem** occurs in **multiple inheritance** when a class inherits from **two classes that both inherit from the same base class**, leading to **ambiguity** about which base class member to use.

---

## 🔁 Basic Structure (Diamond Shape)

```
      A
     / \
    B   C
     \ /
      D
```

* Class `B` and `C` inherit from `A`
* Class `D` inherits from both `B` and `C`
* So, `D` gets **two copies** of class `A` — **ambiguity** arises

---

## 🧨 Problem Example: Without Virtual Inheritance

```cpp
#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "From A\n";
    }
};

class B : public A {};
class C : public A {};
class D : public B, public C {};  // Diamond

int main() {
    D obj;
    // obj.show();  ❌ Error: Ambiguous
    obj.B::show();  // ✅ OK
    obj.C::show();  // ✅ OK
}
```

* ❌ `obj.show();` gives **error**: ambiguous — compiler can't decide which `A::show()` to call

---

## ✅ Solution: Use **Virtual Inheritance**

```cpp
class A {
public:
    void show() {
        cout << "From A\n";
    }
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    D obj;
    obj.show();  // ✅ No ambiguity now
}
```

* With **`virtual` inheritance**, only **one copy of A** exists in `D`
* Avoids duplication and resolves ambiguity

---

## 🧠 Internals: How Virtual Inheritance Works

* Compiler maintains a **shared instance** of class `A` in `D`
* Adds an **indirection (vbase pointer)** to access the shared base

---

## 🎯 Interview Questions on Diamond Problem

### 🔹 Q1: What is the Diamond Problem?

> Ambiguity that arises when a class inherits from two classes that inherit from a common base class, causing duplication of base class members.

---

### 🔹 Q2: How do you solve it?

> Using **virtual inheritance** in intermediate classes (`class B : virtual public A`)

---

### 🔹 Q3: Does virtual inheritance affect performance?

> Slightly. Introduces indirection via a **vbase pointer**, but **prevents bugs** and is worth the tradeoff in complex hierarchies.

---

### 🔹 Q4: Can we use virtual inheritance in single inheritance?

> Technically yes, but it has no effect — it's only meaningful in **multiple inheritance** scenarios.

---

### 🔹 Q5: What is the default inheritance type for classes?

> `private` for `class`, and `public` for `struct`.

---

## 📘 Summary Table

| Concept          | Details                                          |
| ---------------- | ------------------------------------------------ |
| Problem          | Ambiguous base class due to multiple inheritance |
| Caused by        | Two paths to same base                           |
| Solution         | Virtual inheritance                              |
| Syntax           | `class B : virtual public A`                     |
| Runtime overhead | Yes, minimal (due to indirection)                |
| In real projects | Avoid or carefully design hierarchy              |

---

---

## 🔁 What is **Function Overloading**?

> **Function Overloading** is a form of **compile-time polymorphism** where **multiple functions with the same name** are defined **with different parameter types or counts**.

The compiler decides **which function to call at compile time**, based on the **argument list**.

---

## ✅ Example: Function Overloading

```cpp
#include <iostream>
using namespace std;

class Print {
public:
    void show(int x) {
        cout << "Integer: " << x << endl;
    }

    void show(double d) {
        cout << "Double: " << d << endl;
    }

    void show(string s) {
        cout << "String: " << s << endl;
    }
};

int main() {
    Print obj;
    obj.show(10);          // Calls int version
    obj.show(3.14);        // Calls double version
    obj.show("Hello");     // Calls string version
}
```

---

## 🔍 Key Rules of Function Overloading

| Rule               | Description                                |
| ------------------ | ------------------------------------------ |
| ✅ Name             | Must be the same                           |
| ✅ Parameter list   | Must differ by **number, type, or order**  |
| ❌ Return type only | Return type alone **cannot** differentiate |
| ✅ Scope            | Can be inside class or globally            |

---

## ❌ Invalid Overload Example

```cpp
int add(int a, int b);
float add(int x, int y); // ❌ Error: same parameter types after promotion
```

* Ambiguity due to type promotion from `int → float`

---

## 🎯 Advantages

* ✅ Improves code readability and reuse
* ✅ Reduces naming complexity
* ✅ Supports polymorphism without changing function name

---

## 🚀 Real-Life Analogy

A function like `print()` can accept:

* `print("hello")`
* `print(42)`
* `print(3.14)`

You’re using **same name, different input types** — that’s **overloading**.

---

## 🧠 Related Terms

| Concept                   | Description                                        |
| ------------------------- | -------------------------------------------------- |
| Function Overloading      | Same name, different parameters                    |
| Operator Overloading      | Same operator behaves differently                  |
| Compile-time polymorphism | Decided by compiler (e.g., overloading, templates) |
| Runtime polymorphism      | Decided at runtime (via virtual functions)         |

---

## ❓ Interview Questions on Function Overloading

### 🔹 Q1: What is function overloading?

> It allows multiple functions with the same name but different parameter lists in the same scope.

---

### 🔹 Q2: What are the rules for function overloading?

> Functions must differ by **number**, **types**, or **order** of parameters — not just return type.

---

### 🔹 Q3: Is function overloading an example of polymorphism?

> ✅ Yes, it's a type of **compile-time polymorphism**.

---

### 🔹 Q4: Can constructors be overloaded?

> ✅ Yes, constructors can be overloaded to allow multiple ways to initialize an object.

---

### 🔹 Q5: What happens if two overloaded functions have same signature but different return types?

> ❌ It’s a compilation error. Return type is **not considered** for overloading resolution.

---

## 📝 Summary Table

| Feature     | Description                    |
| ----------- | ------------------------------ |
| Name        | Same function name             |
| Parameters  | Must differ                    |
| Return type | Ignored in overload resolution |
| Decided at  | Compile time                   |
| Benefits    | Readability, reusability       |

---

---

## 🔁 What is **Operator Overloading**?

> **Operator overloading** in C++ allows you to **redefine the way operators work** for **user-defined types (classes/structs)**.

It supports **compile-time polymorphism**, just like function overloading.

---

## 🔧 Example: Operator Overloading

```cpp
#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overload +
    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 2), c2(1, 7);
    Complex c3 = c1 + c2;  // Calls overloaded + operator
    c3.display();
}
```

---

## ✅ Why Operator Overloading?

* Makes **user-defined types** behave like **primitive types**
* Improves **code readability**
* Enables **natural syntax** (`a + b`, `a == b`, `a++`, etc.)

---

## 🛠️ Operators You Can Overload

| Category   | Operators                         |                           |         |
| ---------- | --------------------------------- | ------------------------- | ------- |
| Arithmetic | `+`, `-`, `*`, `/`, `%`           |                           |         |
| Relational | `==`, `!=`, `<`, `>`, `<=`, `>=`  |                           |         |
| Logical    | `&&`, \`                          |                           | `, `!\` |
| Assignment | `=`, `+=`, `-=`, etc.             |                           |         |
| Bitwise    | `&`, \`                           | `, `^`, `<<`, `>>`, `\~\` |         |
| Unary      | `++`, `--`, `-`, `*`, `&`         |                           |         |
| Others     | `[]`, `()`, `->`, `new`, `delete` |                           |         |

❌ **Cannot overload:** `::`, `.`, `.*`, `sizeof`, `typeid`, `?:`

---

## 🎯 Rules of Operator Overloading

| Rule                                                 | Description                      |
| ---------------------------------------------------- | -------------------------------- |
| Syntax                                               | `return_type operator op (args)` |
| At least one operand must be a **user-defined type** |                                  |
| Can't change operator **precedence or arity**        |                                  |
| **Member function**: Left operand is current object  |                                  |
| **Friend function**: Can access private members      |                                  |

---

## 🔁 Unary Operator Overloading

```cpp
class Sample {
    int x;
public:
    Sample(int val) : x(val) {}
    Sample operator - () {
        return Sample(-x);
    }
};
```

---

## 🧠 Operator Overloading via Friend Function

```cpp
class Distance {
    int meter;
public:
    Distance(int m) : meter(m) {}

    friend Distance operator + (Distance d1, Distance d2);
};

Distance operator + (Distance d1, Distance d2) {
    return Distance(d1.meter + d2.meter);
}
```

---

## ❓ Interview Questions on Operator Overloading

### 🔹 Q1: What is operator overloading?

> It's the process of redefining how an operator behaves for user-defined types.

---

### 🔹 Q2: Can you overload all operators?

> ❌ No. Operators like `::`, `.`, `.*`, `sizeof`, and `?:` cannot be overloaded.

---

### 🔹 Q3: What's the difference between member and friend overloading?

| Member function                      | Friend function                                  |
| ------------------------------------ | ------------------------------------------------ |
| Left operand must be object of class | Can work with different operand orders           |
| Has access to `this` pointer         | Has access to private data if declared as friend |

---

### 🔹 Q4: Is it possible to overload both `++` (prefix and postfix)?

> ✅ Yes. Use:

```cpp
// Prefix
Complex& operator++();
// Postfix
Complex operator++(int);
```

---

### 🔹 Q5: What are the advantages of operator overloading?

* More intuitive and natural usage of custom types
* Improved code clarity
* Custom behavior for built-in operators

---

## 📘 Summary Table

| Feature         | Value                                     |
| --------------- | ----------------------------------------- |
| Type            | Compile-time polymorphism                 |
| Syntax          | `return_type operator op (args)`          |
| Usable with     | Classes/structs (user-defined types)      |
| Required for    | Intuitive use of complex classes          |
| Cannot overload | `::`, `.`, `.*`, `?:`, `sizeof`, `typeid` |

---
---

## 🧿 1. **Global Operator Overloading**

### 🔹 What is it?

> Global operator overloading refers to defining an **operator function outside the class** as a **non-member** or a **friend function**, especially when the **left-hand operand** is not a class object.

---

### ✅ When do we use global overloading?

* When the **left-hand side** of the expression is **not a class object**.
* When we need **symmetric behavior** like `obj + 5` and `5 + obj`.

---

### 💡 Example: `operator+` as Global Overload

```cpp
#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v) : value(v) {}

    int getValue() const { return value; }

    // Friend function to allow access to private members
    friend Number operator+(const Number& n1, const Number& n2);
};

// Global overloaded operator+
Number operator+(const Number& n1, const Number& n2) {
    return Number(n1.value + n2.value);
}

int main() {
    Number a(10), b(20);
    Number c = a + b;
    cout << "Sum: " << c.getValue();  // Output: 30
}
```

---

## 🔁 2. **Overloading `new` and `delete` Operators**

### 🔹 Why overload `new` and `delete`?

> To **track memory usage**, **custom memory pools**, **debug memory leaks**, or **log allocations**.

---

### ✅ Syntax to overload `new` and `delete`

```cpp
class MyClass {
public:
    void* operator new(size_t size) {
        cout << "Custom new for size: " << size << endl;
        return malloc(size);  // Must use malloc or ::operator new
    }

    void operator delete(void* ptr) {
        cout << "Custom delete" << endl;
        free(ptr);  // Must match with malloc
    }
};
```

---

### 🧪 Example: Overload `new` and `delete`

```cpp
int main() {
    MyClass* obj = new MyClass();  // Calls overloaded new
    delete obj;                    // Calls overloaded delete
}
```

---

### 📝 Notes:

* Use `malloc`/`free` or `::operator new()` to avoid recursion.
* Overloaded `new/delete` must **match** in allocation-deallocation.

---

## 🧠 Interview Questions

### 🔹 Q1: What is the difference between member and global operator overloading?

> Member functions require the **left-hand operand to be the class object**. Global (or friend) functions don't — making them suitable for symmetric or external operations.

---

### 🔹 Q2: Can `new` and `delete` be overloaded?

> ✅ Yes. Overloading them allows **custom memory management**, logging, or pooling.

---

### 🔹 Q3: What are the parameters of overloaded `operator new`?

> It takes a single parameter: `size_t size` (the size of memory to allocate).

---

### 🔹 Q4: Can we overload `new[]` and `delete[]`?

> ✅ Yes. Their signatures differ:

```cpp
void* operator new[](size_t size);
void operator delete[](void* ptr);
```

---

### 🔹 Q5: What happens if we forget to free memory in overloaded delete?

> ❌ **Memory leak**. Even with overloading, proper deallocation is your responsibility.

---

## 📘 Summary Table

| Concept              | Notes                              |
| -------------------- | ---------------------------------- |
| Global overloading   | Useful when LHS isn't class object |
| `new` overloading    | Custom allocation logic            |
| `delete` overloading | Custom cleanup logic               |
| Matching rule        | `new ↔ delete`, `new[] ↔ delete[]` |
| Common use           | Logging, pooling, debugging        |

---

---

## 🔥 1. Runtime Polymorphism in C++

### 🔹 Definition:

> **Runtime polymorphism** in C++ is achieved using **virtual functions**, **function overriding**, and **base class pointers/references** to invoke derived class methods **at runtime**.

---

### ✅ Example of Runtime Polymorphism:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Base display\n";
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived display\n";
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->display();  // ✅ Output: Derived display (runtime resolution)
    delete ptr;
}
```

> 🔍 Because `display()` is **virtual**, the function call is **resolved at runtime** based on the actual object.

---

### 🔧 Key Components:

| Term                | Meaning                                   |
| ------------------- | ----------------------------------------- |
| `virtual` keyword   | Enables dynamic dispatch                  |
| Function overriding | Derived class redefines base class method |
| Base pointer/ref    | Accessing derived method via base         |

---

## 🧠 Interview Questions on Runtime Polymorphism

### 🔹 Q1: What enables runtime polymorphism in C++?

> The **virtual function mechanism** and **function overriding**.

### 🔹 Q2: Can constructors be virtual?

> ❌ No. But **destructors should be virtual** in base class for proper cleanup.

### 🔹 Q3: What’s the difference between override and overload?

> `override` → runtime polymorphism,
> `overload` → compile-time polymorphism.

---

## ⚠️ 2. Default Arguments in C++

### 🔹 Definition:

> **Default arguments** provide default values for parameters when none are passed.

```cpp
void greet(string name = "Guest") {
    cout << "Hello, " << name << "!\n";
}

int main() {
    greet();           // Hello, Guest!
    greet("Aditya");   // Hello, Aditya!
}
```

---

## 🔄 3. Can Virtual Functions Use Default Arguments?

> ✅ **Yes**, BUT **default arguments are bound at compile time**, NOT runtime.

---

### ❌ Dangerous Example:

```cpp
class Base {
public:
    virtual void show(int x = 10) {
        cout << "Base: " << x << endl;
    }
};

class Derived : public Base {
public:
    void show(int x = 20) override {
        cout << "Derived: " << x << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->show();  // Output: Derived: 10  ❌ NOT 20
}
```

> Even though `Derived::show()` is called, the **default value `x=10` from Base** is used.
> Because **default args are resolved at compile-time**, but **virtual function call is runtime**.

---

## ❓ Interview Q\&A: Default Arguments + Runtime Polymorphism

### 🔹 Q1: Are default arguments part of runtime polymorphism?

> ❌ No, they are **resolved at compile time**.

---

### 🔹 Q2: What happens if virtual function uses different default args in base and derived?

> The **base class value** is used when accessed via base pointer/reference.

---

### 🔹 Q3: How to avoid default argument confusion in virtual functions?

> ✔️ Avoid default arguments in overridden virtual functions.
> ✔️ Use overloaded functions if needed.

---

## ✅ Summary Table

| Concept          | Runtime Polymorphism | Default Arguments |
| ---------------- | -------------------- | ----------------- |
| Binding time     | Runtime              | Compile time      |
| Keyword          | `virtual`            | `=` in param list |
| Resolved via     | Vtable/vptr          | Compiler          |
| Safe to combine? | Not recommended      | Causes confusion  |

---




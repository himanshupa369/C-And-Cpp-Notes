<!DOCTYPE html>
<html>
<head>
    
</head>
<body>

<h2>Solid Principle Playlist</h2>

        "https://www.youtube.com/embed/HLFbeC78YlU?list=PL6n9fhu94yhXjG1w2blMXUzyDrZ_eyOme"

</body>
</html>

<head>
    
</head>
<body>

<h2>Solid Principle Examples</h2>

        "https://medium.com/backticks-tildes/the-s-o-l-i-d-principles-in-pictures-b34ce2f1e898"

</body>
</html>

<!DOCTYPE html>
<html>
<head>

</head>
<body>
  <h1>🧠 Common Design Principles</h1>
  <ul>
    <li><strong>SOLID</strong> principles</li>
    <li><strong>DRY</strong> – Don’t Repeat Yourself</li>
    <li><strong>KISS</strong> – Keep It Simple, Stupid</li>
    <li><strong>YAGNI</strong> – You Aren’t Gonna Need It</li>
    <li><strong>Separation of Concerns</strong></li>
  </ul>
</body>
</html>


<!DOCTYPE html>
<html>
<head>

</head>
<body>
  <h1>🔠 SOLID Principles</h1>

  <p>The SOLID principles are five key object-oriented design principles that help make software:</p>
  <ul>
    <li>Easier to maintain</li>
    <li>More scalable</li>
    <li>Less buggy</li>
    <li>Flexible for change</li>
  </ul>

  <p>They were popularized by <strong>Robert C. Martin (Uncle Bob)</strong> and are often used in C++, Java, Python, and other OOP languages.</p>

  <h2>SOLID stands for:</h2>
  <table border="1" cellpadding="5" cellspacing="0">
    <thead>
      <tr>
        <th>Letter</th>
        <th>Principle Name</th>
        <th>Short Description</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td><strong>S</strong></td>
        <td>Single Responsibility Principle</td>
        <td>One class → one job</td>
      </tr>
      <tr>
        <td><strong>O</strong></td>
        <td>Open/Closed Principle</td>
        <td>Open for extension, closed for modification</td>
      </tr>
      <tr>
        <td><strong>L</strong></td>
        <td>Liskov Substitution Principle</td>
        <td>Subtypes should work as their base types</td>
      </tr>
      <tr>
        <td><strong>I</strong></td>
        <td>Interface Segregation Principle</td>
        <td>Many small interfaces &gt; one big one</td>
      </tr>
      <tr>
        <td><strong>D</strong></td>
        <td>Dependency Inversion Principle</td>
        <td>Depend on abstractions, not concretions</td>
      </tr>
    </tbody>
  </table>
  </body>
</html>
---

## ✅ Core Design Principles in C++ (SOLID)

---

### **1. Single Responsibility Principle (SRP)**

> **A class should have only one reason to change.**

* 🛠️ Each class/function should handle a single part of the functionality.
* ❌ Don't mix unrelated logic (e.g., file I/O and business rules in one class).
* ✅ Keeps code **modular**, **testable**, and **easy to refactor**.

#🏠 Analogy:
A chef cooks food. A cashier handles billing. You wouldn't want a chef to handle payments too.
---

### **2. Open/Closed Principle (OCP)**

> **Software entities should be open for extension but closed for modification.**

* 📦 Add new functionality via **inheritance**, **virtual functions**, or **templates** — not by changing existing code.
* ✅ Encourages **extensible** design while protecting **existing code** from bugs.

#🏠 Analogy:
A USB port allows new devices to be added without changing the port itself.
---

### **3. Liskov Substitution Principle (LSP)**

> **Derived classes must be substitutable for their base classes.**

* 🧠 Any instance of a base class should be replaceable with a derived class without altering program behavior.
* ✅ Promotes **polymorphism** and avoids runtime surprises.
* ❌ Don't violate expected behavior in a subclass (e.g., override but ignore a method's expected outcome).

#🏠 Analogy:
You can use a credit card or debit card at the ATM – both follow the same interface.
---

### **4. Interface Segregation Principle (ISP)**

> **Clients should not be forced to depend on interfaces they do not use.**

* 🧩 Split **fat interfaces** into smaller, focused ones.
* ✅ Improves **modularity** and **testability**.
* ❌ Don’t make a class implement unrelated methods just because they exist in a large interface.

#🏠 Analogy:
A printer that only prints shouldn’t be forced to support scanning.
---

### **5. Dependency Inversion Principle (DIP)**

> **Depend on abstractions, not on concrete implementations.**

* 🎯 High-level modules shouldn't depend on low-level modules.
* ✅ Use **abstract classes** or **interfaces**, and inject them as dependencies (via constructor or setter).
* 🛠️ Enables **flexible architecture** (e.g., switch from file-based logging to database logging without changing business logic).

#🏠 Analogy:
A TV remote doesn't care whether you're using a Sony or LG TV, as long as both follow the "IR protocol."
---


**YAGNI**, **KISS**, and **DRY** — three of the most **widely followed coding principles** that promote clean, efficient, and maintainable code.

---

## 🔁 **Quick Summary Table**

| Principle | Stands For               | Key Idea                                              | Real-Life Analogy                                   |
| --------- | ------------------------ | ----------------------------------------------------- | --------------------------------------------------- |
| **YAGNI** | You Aren’t Gonna Need It | Don’t add functionality until it’s actually needed    | Don’t pack winter clothes for a beach trip          |
| **KISS**  | Keep It Simple, Stupid   | Prefer simple and readable solutions over clever ones | A simple calculator over a rocket to add numbers    |
| **DRY**   | Don’t Repeat Yourself    | Eliminate duplicate code by reusing logic             | One recipe card for all apple pies, not one per pie |

---

## ✅ 1. **YAGNI – You Aren’t Gonna Need It**

> Only implement what's necessary now — not what *might* be needed later.

### ❌ Bad Example:

```cpp
class User {
public:
    std::string name;
    std::string getCountry() const { return "India"; } // Unused, unnecessary
    void calculateLoyaltyPoints() {} // Premature logic
};
```

* These functions are **never used** and add maintenance burden.

### ✅ Good Example:

```cpp
class User {
public:
    std::string name;
};
```

* Add `getCountry()` or `calculateLoyaltyPoints()` **only if needed** in the future.

---

## ✅ 2. **KISS – Keep It Simple, Stupid**

> Simpler code is easier to read, debug, and maintain.

### ❌ Bad Example:

```cpp
bool isEven(int n) {
    return ((n ^ 1) == n + 1); // Bitwise trick – hard to read
}
```

### ✅ Good Example:

```cpp
bool isEven(int n) {
    return n % 2 == 0; // Clear and simple
}
```

* Avoid clever hacks unless performance **really** demands it.

---

## ✅ 3. **DRY – Don’t Repeat Yourself**

> Reuse code instead of copying it in multiple places.

### ❌ Bad Example:

```cpp
double calculateCircleArea(double r) {
    return 3.14 * r * r;
}

double calculateSphereSurfaceArea(double r) {
    return 4 * 3.14 * r * r;
}
```

### ✅ Good Example:

```cpp
constexpr double PI = 3.14;

double square(double x) {
    return x * x;
}

double calculateCircleArea(double r) {
    return PI * square(r);
}

double calculateSphereSurfaceArea(double r) {
    return 4 * PI * square(r);
}
```








---

# CUPID Principles (Software Design)

**CUPID** is a **set of modern design principles** focused on **readability, maintainability, and developer happiness**.
It complements traditional OOP principles rather than replacing them.

CUPID was popularized by **Dan North**.

---

## Meaning of CUPID

### **C – Composable**

* Software components should be **easy to combine**
* Small units that can be reused in different contexts
* Prefer **composition over inheritance**

**Example (C++ idea):**

```cpp
class Logger { };
class FileWriter { };

class Service {
    Logger logger;
    FileWriter writer;
};
```

**Key idea:** Build systems like LEGO blocks.

---

### **U – Understandable**

* Code should be **easy to read and reason about**
* Favor clarity over cleverness
* Minimize mental overhead

**Good signs:**

* Clear naming
* Short functions
* Predictable control flow

**Bad sign:**

```cpp
doStuff(x ? y++ : --z); // Hard to reason
```

---

### **P – Predictable**

* Code should behave **as expected**
* No hidden side effects
* Consistent APIs

**Rule of thumb:**

> “If I call this function twice, will it surprise me?”

---

### **I – Idiomatic**

* Use the **idioms of the language**
* Follow community conventions

**C++ example:**

* RAII for resource management
* `std::unique_ptr` instead of raw `new/delete`
* Range-based loops

```cpp
std::vector<int> v;
for (int x : v) { }
```

---

### **D – Domain-focused**

* Code should reflect **business/domain language**
* Avoid technical jargon in core logic

**Example:**

```cpp
class Order {
    Money totalPrice();
};
```

instead of:

```cpp
double calc();
```

---

## Summary of CUPID

| Principle      | Focus                     |
| -------------- | ------------------------- |
| Composable     | Reusability & flexibility |
| Understandable | Readability               |
| Predictable    | Reliability               |
| Idiomatic      | Language best practices   |
| Domain-focused | Business clarity          |

---

# SOLID Principles (Classic OOP)

SOLID focuses on **class-level design correctness**, mainly for **object-oriented systems**.

| Principle | Meaning               |
| --------- | --------------------- |
| **S**     | Single Responsibility |
| **O**     | Open/Closed           |
| **L**     | Liskov Substitution   |
| **I**     | Interface Segregation |
| **D**     | Dependency Inversion  |

**Goal:** Prevent rigid, fragile, tightly-coupled designs.

---

# CUPID vs SOLID (Core Differences)

| Aspect           | SOLID                       | CUPID                       |
| ---------------- | --------------------------- | --------------------------- |
| Origin           | Classical OOP               | Modern software design      |
| Level            | Class / Interface level     | System & codebase level     |
| Focus            | Correctness & extensibility | Readability & composability |
| Style            | Rule-driven                 | Heuristic-driven            |
| Language         | OOP-centric                 | Language-agnostic           |
| Modern relevance | Still important             | Very relevant today         |

---

## Key Insight (Important for Interviews)

> **SOLID prevents bad design.
> CUPID promotes good design.**

* SOLID tells you **what not to do**
* CUPID tells you **how good code should feel**

---

## Do They Replace Each Other?

❌ No
✅ They **complement** each other

**Best practice:**

* Use **SOLID** to structure classes and dependencies
* Use **CUPID** to shape readable, maintainable systems

---

## Interview-Ready One-Liner

> “SOLID focuses on object-oriented correctness, while CUPID focuses on composability, readability, and developer experience. In modern systems, I try to follow SOLID at the class level and CUPID at the system level.”

---


---

# ✅ Constructor Delegation in C++

## 🔹 Header

**Topic:** Constructor Delegation
**Language:** C++
**Feature Introduced In:** ✅ **C++11**

---

## 🔹 What Is Constructor Delegation?

**Constructor delegation** is a C++ feature that allows **one constructor to call another constructor of the same class** to perform object initialization.

### 🎯 Purpose

* Avoids **code duplication**
* Centralizes **initialization logic**
* Improves **maintainability and consistency**

Instead of repeating initialization code in multiple constructors, one constructor **delegates the construction work** to another.

---

## 🔹 Basic Syntax

```cpp
ClassName(arg1, arg2) : ClassName(otherArgs...) {
    // Additional logic (optional)
}
```

⚠️ This delegation **must be done using the initializer list**.

---

## 🔹 Example Without Delegation (Code Duplication)

```cpp
class Square {
    double m_side;
    std::string m_color;
    int m_shading;

public:
    Square(double side) {
        m_side = side;
        m_color = "black";
        m_shading = 5;
    }

    Square(double side, std::string color, int shading) {
        m_side = side;
        m_color = color;
        m_shading = shading;
    }
};
```

❌ **Problem:** Initialization logic is duplicated.

---

## ✅ Example With Constructor Delegation (Correct Design)

```cpp
class Square {
    double m_side;
    std::string m_color;
    int m_shading;

public:
    Square(double side)
        : Square(side, "black", 5) {     // ✅ Delegation
        std::cout << "1-parameter constructor called\n";
    }

    Square(double side, std::string color, int shading)
        : m_side(side), m_color(color), m_shading(shading) {
        std::cout << "3-parameter constructor called\n";
    }
};
```

---

## 🔹 Order of Execution (Very Important)

When you call:

```cpp
Square s(10);
```

### ✅ Execution Sequence:

1. **1-param constructor is called**
2. It **delegates to the 3-param constructor**
3. **3-param constructor initializes the object**
4. **3-param constructor body executes**
5. Control returns to **1-param constructor body**
6. Execution returns to `main()`

✅ Output:

```
3-parameter constructor called
1-parameter constructor called
```

---

## ❌ Calling Another Constructor Inside the Body Is NOT Delegation

```cpp
Square(double side) {
    Square(side, "black", 5);  // ❌ WRONG
}
```

### 🔴 What Actually Happens:

* This creates a **temporary local object**
* That object is **destroyed immediately**
* The current object remains **uninitialized**

✅ Proof: Destructor runs immediately for the temporary object.

---

## ❗ Important Rules & Limitations

### 1️⃣ Delegation Must Be in Initializer List

```cpp
Square(double s) : Square(s, "black", 5) {} ✅
```

```cpp
Square(double s) { Square(s, "black", 5); } ❌
```

---

### 2️⃣ No Other Member Initialization Allowed with Delegation

❌ This is illegal:

```cpp
Square(double s)
    : Square(s, "black", 5), m_position(10.0) {}  // ❌ Compiler Error
```

✅ Reason:
**If constructor delegation is used, it must be the ONLY entry in the initializer list.**

---

### 3️⃣ Further Initialization Is Allowed Inside Constructor Body

✅ This is legal:

```cpp
Square(double s) : Square(s, "black", 5) {
    m_position = 45.8;  // ✅ Allowed
}
```

---

## 🔹 Destructor Behavior in Delegation

✔️ With proper delegation:

* Only **one object is created**
* Only **one destructor is called**

❌ With incorrect constructor call inside body:

* **Temporary object is created and destroyed**
* Then the real object is destroyed later
  → This leads to **unexpected extra destructor calls**

---

## 🔹 Real-World Use Cases

* Game engines (shapes, UI elements)
* GUI widgets
* Financial models
* Physics simulation objects
* Any class with **multiple configuration levels**

---

## ✅ Advantages

| Benefit           | Explanation                        |
| ----------------- | ---------------------------------- |
| ✅ Code Reuse      | Prevents duplicate initialization  |
| ✅ Maintainability | One place to update logic          |
| ✅ Reliability     | Avoids inconsistent initialization |
| ✅ Cleaner Design  | Clear constructor hierarchy        |

---

## ❌ Disadvantages / Limitations

| Limitation                | Explanation                                     |
| ------------------------- | ----------------------------------------------- |
| ❌ C++11 Required          | Not available before C++11                      |
| ❌ No mixed initialization | Cannot initialize members along with delegation |
| ❌ Debugging chain         | Call stack becomes deeper                       |
| ❌ Poor design risk        | Over-delegation can reduce clarity              |

---

## ✅ Best Practices

* Use constructor delegation for:

  * Default values
  * Reduced duplication
* Always:

  * Delegate from **simpler → more complete constructor**
* Avoid:

  * Calling constructors inside constructor bodies
  * Mixing delegation with member initialization

---

## ✅ One-Line Definition (For Exams / Interviews)

> Constructor delegation is a C++11 feature that allows one constructor to reuse another constructor of the same class using the initializer list to avoid code duplication.

---

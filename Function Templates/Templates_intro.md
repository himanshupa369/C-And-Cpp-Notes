
---

# ✅ **Function Templates in C++ — Short Notes (C++98 → C++20)**

## **✔ What is a Function Template?**

* A **function template** is a **blueprint**, not real C++ code.
* The compiler creates **real functions** from this blueprint when you call the function with specific types.
* These generated real functions are called **template instances**.

---

## **✔ Why Function Templates?**

* Avoids writing many overloads:

  ```cpp
  int max(int,int)
  double max(double,double)
  std::string max(std::string,std::string)
  ```
* A single template replaces all repetitive copies.

---

## **✔ Basic Syntax**

### **Declaration**

```cpp
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}
```

### **Usage**

```cpp
maximum(10, 20);          // T = int
maximum(5.5, 7.9);        // T = double
maximum("A"s, "B"s);      // T = std::string
```

---

## **✔ How Template Instantiation Works**

* Compiler looks at the argument types.
* Replaces `T` with those types.
* Generates **one instance per unique type**.
* Already-generated instances are **reused** (no duplicates).

Example:

```cpp
maximum(5,7);    // generates maximum<int>
maximum(5.5,7.9) // generates maximum<double>
```

---

## **✔ Important Rules**

### **1. All T must be the same type**

This fails:

```cpp
maximum(5.5, 7);  // ERROR: double vs int
```

### **2. Template code must support operations used inside**

This fails:

```cpp
multiply<std::string>("A","B");   // ERROR: "A" * "B" invalid
```

### **3. Templates may compile but behave incorrectly**

Example: calling `maximum()` with **pointers**:

```cpp
int x = 5, y = 7;
int* px = &x;
int* py = &y;

maximum(px, py);   // compares memory addresses, NOT values!
```

---

## **✔ Debugging Templates**

* Debugger steps into **the generated instance**, not the template itself.
* Call stack shows instantiation like:

```
maximum<int>(int, int)
maximum<double>(double, double)
```

---

## **✔ Example Correct Usage**

```cpp
int x = 5, y = 7;
int* px = &x;
int* py = &y;

auto result = maximum(*px, *py);  // Correct: compare values
```

---

# 📌 **Key Takeaways**

* Function templates are only **blueprints**, not code.
* Compiler creates **template instances** when needed.
* Operations in template must be **valid for the chosen type**.
* Pointer comparisons compare **addresses**, not **values**.

---


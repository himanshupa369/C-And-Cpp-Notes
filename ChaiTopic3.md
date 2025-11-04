
---

# ⚙️ **Difference Between `assign()` and Assignment Operator (`=`) in C++**

| Feature           | **`assign()` Function**                                                    | **Assignment Operator (`=`)**                                       |
| ----------------- | -------------------------------------------------------------------------- | ------------------------------------------------------------------- |
| **Type**          | A **member function** (mainly used in STL containers and `std::string`)    | A **built-in operator** used for assigning values                   |
| **Usage**         | Used with **objects of classes** (like `std::string`, `std::vector`, etc.) | Used to assign **values or objects** in general                     |
| **Defined In**    | Defined as a **member function** in STL classes                            | Built-in part of the C++ language                                   |
| **Purpose**       | To copy or assign content from another object, substring, or range         | To assign one value or object to another                            |
| **Overloadable?** | Yes (for custom classes)                                                   | Yes (can be overloaded in user-defined classes)                     |
| **Chaining**      | Usually returns `void` (depends on implementation)                         | Returns the **assigned object** (allows chaining like `a = b = c;`) |

---

## 🔹 **1. Assignment Operator (`=`)**

* It’s the **basic assignment mechanism** in C++.
* Used to copy the value or object **from right-hand side to left-hand side**.

### Example:

```cpp
int a, b;
a = 10;       // assigns 10 to a
b = a;        // assigns value of a to b
```

### Example with `std::string`:

```cpp
string s1 = "Hello";
string s2;
s2 = s1;  // copies content of s1 into s2
cout << s2; // Output: Hello
```

---

## 🔹 **2. `assign()` Function**

* It is a **member function** in STL containers like `std::string`, `std::vector`, etc.
* Used for **more controlled assignment** — e.g., partial copying, assigning ranges, filling values.

### Example with `std::string`:

```cpp
string str1 = "Hello World";
string str2;

str2.assign(str1);          // copies entire string
cout << str2 << endl;       // Output: Hello World

str2.assign(str1, 6, 5);    // copies substring from index 6 of length 5
cout << str2 << endl;       // Output: World
```

### Example with `std::vector`:

```cpp
vector<int> v1 = {1, 2, 3, 4, 5};
vector<int> v2;

v2.assign(v1.begin() + 1, v1.end() - 1);  // assigns part of another vector
// v2 = {2, 3, 4}

v2.assign(3, 10); // assigns 3 copies of 10 → {10, 10, 10}
```

---

## 🔹 **Return Type Difference**

| Operator   | Return Type                       | Enables                              |
| ---------- | --------------------------------- | ------------------------------------ |
| `=`        | Returns a reference to LHS object | **Chained assignment** (`a = b = c`) |
| `assign()` | Usually returns `void`            | **No chaining possible**             |

📘 Example:

```cpp
string a, b, c = "Hi";
a = b = c;         // ✅ valid (returns reference)
a.assign(b.assign(c));  // ❌ invalid (assign() returns void)
```

---

## 🔹 **When to Use Which**

| Use Case                                     | Recommended          |
| -------------------------------------------- | -------------------- |
| Simple variable or object assignment         | `=` operator         |
| Partial string/vector copy, range assignment | `assign()` function  |
| Custom class copy control                    | Overload `operator=` |

---

## 🧠 **Example Comparison**

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // Using assignment operator
    string s1 = "Hello";
    string s2;
    s2 = s1;  // full copy
    cout << "Using '=': " << s2 << endl;

    // Using assign()
    string s3;
    s3.assign(s1, 0, 4);  // copy "Hell"
    cout << "Using assign(): " << s3 << endl;

    // Using assign() with vector
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2;
    v2.assign(v1.begin() + 2, v1.end()); // {3, 4, 5}
    cout << "v2 size: " << v2.size();
}
```

🧾 **Output:**

```
Using '=': Hello
Using assign(): Hell
v2 size: 3
```

---

## ✅ **Summary**

| Aspect           | `assign()`                             | Assignment Operator `=`  |
| ---------------- | -------------------------------------- | ------------------------ |
| Belongs To       | STL containers like `string`, `vector` | Built-in operator        |
| Usage            | Assigns content, range, or substring   | Copies full value/object |
| Return Type      | Usually `void`                         | LHS object reference     |
| Chain Assignment | ❌ No                                   | ✅ Yes                    |
| Customization    | Can be overloaded                      | Can be overloaded        |
| Preferred For    | Substrings, partial copy               | General assignments      |

---


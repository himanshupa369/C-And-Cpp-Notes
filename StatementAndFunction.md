
---

## ⚙️ Difference Between Function and Statement (C++)

### 🧩 **Function**

* A **function** is a block of code designed to perform a specific task.
* It has a **name**, optional **parameters**, and a **body**.
* Functions can be **called (invoked)** multiple times to reuse code.
* May return a value using the `return` statement.

**Example:**

```cpp
void greet() {
    cout << "Hello, world!" << endl;
}
```

---

### 💡 **Statement**

* A **statement** is the **basic unit of computation** in a C++ program.
* Every C++ program is a **collection of statements** organized to achieve some goal.
* **Each statement ends with a semicolon (`;`)** in C++.
* Statements are executed **in order from top to bottom** when the program runs.
* Execution continues until a statement **terminates the program** (e.g., `return 0;`)
  or **alters the flow** (e.g., loops, `if`, or `goto`).

**Example:**

```cpp
int x = 10;           // declaration statement
cout << x << endl;    // output statement
x = x + 5;            // assignment statement
greet();              // function call statement
return 0;             // termination statement
```

---

### 🔍 **Key Differences**

| Feature         | Function                                      | Statement                           |
| --------------- | --------------------------------------------- | ----------------------------------- |
| **Definition**  | A reusable block of code that performs a task | A single instruction in the program |
| **Ends With**   | No semicolon (except when called)             | Usually ends with a semicolon `;`   |
| **Reusability** | Can be called multiple times                  | Executed once in sequence           |
| **Example**     | `void greet() { ... }`                        | `greet();`, `int x = 10;`           |

---

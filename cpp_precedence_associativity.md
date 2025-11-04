
---

# ⚙️ **Operator Precedence and Associativity in C++**

---

## 🧩 **What is Operator Precedence?**

* **Operator precedence** determines the **order** in which different operators in an expression are evaluated.
* Operators with **higher precedence** are evaluated **before** operators with **lower precedence**.

📘 **Example:**

```cpp
int a = 10 + 5 * 2;  
// Multiplication (*) has higher precedence than addition (+)
// So: a = 10 + (5 * 2) = 20
```

---

## 🔁 **What is Operator Associativity?**

* **Associativity** determines the **order of evaluation** when **operators of the same precedence** appear in an expression.
* It can be:

  * **Left-to-right** → most common
  * **Right-to-left** → for assignment and unary operators

📘 **Example:**

```cpp
int a = 10, b = 20, c = 30;
int result = a + b + c; 
// '+' has left-to-right associativity
// So: ((a + b) + c)
```

📘 **Example (Right-to-left):**

```cpp
int x, y, z;
x = y = z = 5;  
// '=' has right-to-left associativity
// So: x = (y = (z = 5))
```

---

## ⚖️ **Operator Precedence Table (Simplified)**

| Precedence (High → Low) | Operator(s)                                               | Description                                                                   | Associativity |               |               |
| ----------------------- | --------------------------------------------------------- | ----------------------------------------------------------------------------- | ------------- | ------------- | ------------- |
| 1️⃣                     | `::`                                                      | Scope resolution                                                              | Left-to-right |               |               |
| 2️⃣                     | `++` `--` `()` `[]` `.` `->`                              | Postfix increment/decrement, function call, array subscripting, member access | Left-to-right |               |               |
| 3️⃣                     | `++` `--` `+` `-` `!` `~` `*` `&` `sizeof` `new` `delete` | Unary operators                                                               | Right-to-left |               |               |
| 4️⃣                     | `*` `/` `%`                                               | Multiplication, division, modulo                                              | Left-to-right |               |               |
| 5️⃣                     | `+` `-`                                                   | Addition, subtraction                                                         | Left-to-right |               |               |
| 6️⃣                     | `<<` `>>`                                                 | Bitwise shift                                                                 | Left-to-right |               |               |
| 7️⃣                     | `<` `<=` `>` `>=`                                         | Relational operators                                                          | Left-to-right |               |               |
| 8️⃣                     | `==` `!=`                                                 | Equality operators                                                            | Left-to-right |               |               |
| 9️⃣                     | `&`                                                       | Bitwise AND                                                                   | Left-to-right |               |               |
| 🔟                      | `^`                                                       | Bitwise XOR                                                                   | Left-to-right |               |               |
| 11️⃣                    | `                                                         | `                                                                             | Bitwise OR    | Left-to-right |               |
| 12️⃣                    | `&&`                                                      | Logical AND                                                                   | Left-to-right |               |               |
| 13️⃣                    | `                                                         |                                                                               | `             | Logical OR    | Left-to-right |
| 14️⃣                    | `?:`                                                      | Conditional (ternary)                                                         | Right-to-left |               |               |
| 15️⃣                    | `=` `+=` `-=` `*=` `/=` `%=` `<<=` `>>=` `&=` `^=` `      | =`                                                                            | Assignment    | Right-to-left |               |
| 16️⃣                    | `,`                                                       | Comma                                                                         | Left-to-right |               |               |

---

## 💡 **Key Notes**

* Parentheses `()` **override both precedence and associativity**.
* **Associativity** matters only when **operators have equal precedence**.
* **Postfix `++`/`--`** have **higher precedence** than **prefix `++`/`--`**.
* The **assignment operator `=`** has **lower precedence** than almost every other operator.

---

## 🧠 **Common Confusing Examples**

### 1. Precedence between `*` and `+`

```cpp
int x = 2 + 3 * 4;  
// Multiplication first → 2 + (3 * 4) = 14
```

### 2. Right-to-left Associativity (Assignment)

```cpp
int x, y, z;
x = y = z = 5;
// Evaluates as: x = (y = (z = 5))
```

### 3. Ternary Operator

```cpp
int a = 5, b = 10;
int result = (a > b) ? a : b;  
// result = 10
```

### 4. Combining Unary and Binary

```cpp
int x = 10;
int y = -x++;  
// Postfix ++ has higher precedence → y = -(x++), not (-x)++
```

### 5. Mixing Bitwise and Logical

```cpp
int a = 2, b = 3, c = 0;
if (a & b && c) cout << "Yes";  
// '&' evaluated before '&&'
```

---

## ✅ **Tips for Remembering**

1. **Parentheses > everything** → always use `()` for clarity.
2. **Unary > Multiplicative > Additive** → (++, --, *, +, -).
3. **Comparison before assignment**.
4. When unsure, **use parentheses explicitly**.

---

## 🧾 **Summary**

| Concept           | Defines                             | Typical Direction              |
| ----------------- | ----------------------------------- | ------------------------------ |
| **Precedence**    | Which operator is applied first     | Based on hierarchy             |
| **Associativity** | Order for same-precedence operators | Left-to-right or Right-to-left |
| **Parentheses**   | Override both                       | Always top priority            |

---


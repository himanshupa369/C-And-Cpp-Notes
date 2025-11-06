
---

### ✅ **Basic-Level Questions**

1. **Q:** What is a `switch` statement in C?

   **A:** It is a control statement used to execute one block of code among many based on the value of an expression.

---

2. **Q:** What types of values can be used in a `switch`?

   **A:** Only **integral or enumeration types** like `int`, `char`, or `enum`. `float`, `double`, and `string` are **not allowed**.

---

3. **Q:** What happens if there is no `break` in a `switch` case?

   **A:** **Fall-through** occurs. Execution continues into the next case even if it doesn't match.

   ```c
   int x = 2;
   switch(x) {
       case 1: printf("One ");
       case 2: printf("Two ");
       case 3: printf("Three");
   }
   // Output: Two Three
   ```

---

### ⚠️ **Tricky Questions**

4. **Q:** Can `default` be placed at the beginning or middle of a `switch`?

   **A:** Yes. The position doesn't matter, but it only executes if **no `case` matches**, unless fall-through leads to it.

---

5. **Q:** Can `case` values be repeated?

   **A:** **No.** Repeated `case` values will cause a **compilation error**.

---

6. **Q:** What is the scope of a variable declared inside a `case`?

   **A:** If you declare a variable inside a `case` without braces `{}`, it may cause an error:

   ```c
   switch(x) {
       case 1:
           int a = 5; // ❌ error without braces
           break;
   }
   ```

   ✅ Use braces to define scope:

   ```c
   case 1: {
       int a = 5;
       break;
   }
   ```

---

7. **Q:** Is `break` necessary in every case?

   **A:** Not mandatory, but without it, **fall-through behavior** occurs. Use it to prevent unwanted execution of other cases.

---

8. **Q:** Can `switch` work with strings in C?

   **A:** **No.** C doesn't support `switch` on strings, but C++ does with `std::string` (indirectly with `if-else`).

---

9. **Q:** Can we nest a `switch` inside another `switch`?

   **A:** Yes. It's called **nested switch**, and it works like nested `if-else`.

---

### 🔍 **Example Interview Problem**

**Q:** What will be the output?

```c
int a = 1;
switch(a) {
    case 1:
        printf("A ");
    case 2:
        printf("B ");
        break;
    default:
        printf("C");
}
```

**Answer:**
Output: `A B`
Explanation: `case 1` matches, but no `break`, so it falls into `case 2`.

---


---

## 🧩 **Grouping Multiple Cases**

You can **combine multiple cases** that should execute the same code.

### Example:

```cpp
switch (tool) {
    case rectangle:
    case circle:
    case ellipse:
        cout << "Drawing shape" << endl;
        break;

    default:
        cout << "Not a shape tool" << endl;
        break;
}
```

✅ **Output (if tool = circle):**

```
Drawing shape
```

🧠 *This is useful when multiple case values share the same behavior.*

---

## ⚠️ **Important Rules & Limitations**

| Rule                          | Explanation                                                                                                     |
| ----------------------------- | --------------------------------------------------------------------------------------------------------------- |
| **1. Expression Type**        | Must be an integral or enum type (`int`, `char`, `long`, etc.). Not allowed for `string`, `float`, or `double`. |
| **2. Unique Case Labels**     | Each `case` constant must be unique within the same switch block.                                               |
| **3. Compile-Time Constants** | Case labels must be compile-time constants (like `const int` or `enum`).                                        |
| **4. Scope**                  | Labels (`case`, `default`) are local to the switch statement.                                                   |
| **5. Fall-through**           | Occurs if `break` is omitted — all subsequent cases execute.                                                    |
| **6. Default Case**           | Optional but recommended for handling unexpected values.                                                        |

---


---

## 🔎 **Key Takeaways**

| Concept             | Summary                                              |
| ------------------- | ---------------------------------------------------- |
| **Purpose**         | Simplify multiple condition checks for one variable. |
| **Break Statement** | Prevents fall-through into next cases.               |
| **Default**         | Executes when no case matches (optional).            |
| **Expression Type** | Must be integral or enum (not string or float).      |
| **Grouping**        | Multiple cases can share one code block.             |
| **Fall-through**    | If break is missing, all following cases execute.    |

---


---




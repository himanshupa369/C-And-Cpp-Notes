
---

## 📝 C++ Comments

### 1. **Single-Line Comments**

Used for short explanations or disabling one line of code.
Syntax:

```cpp
// This prints a message
cout << "Hello, World!" << endl;

// cout << "This line is commented out";
```

---

### 2. **Multi-Line (Block) Comments**

Used for longer explanations or temporarily commenting multiple lines.
Syntax:

```cpp
/* This is a block comment.
   It can span multiple lines.
   Useful for describing functions or algorithms. */
cout << "C++ Comments Example" << endl;
```

⚠️ **Note:** Block comments **cannot be nested**

```cpp
/* Outer comment start
   /* Inner comment – ❌ not allowed */
   Outer comment end */
```

---

### 3. **Best Practices**

✅ Use comments to **explain why**, not **what** (code already shows what).
✅ Keep them **short and relevant**.
✅ Update comments when code changes.
✅ Prefer single-line comments for inline notes.

Example:

```cpp
int factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) return 1;

    // Recursive case
    return n * factorial(n - 1);
}
```

---

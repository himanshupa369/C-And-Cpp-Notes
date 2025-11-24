
---

# 🚀 Debugging C++ Programs in **Microsoft Visual Studio (IDE)**

### (Beginner → Industry-Ready Notes)

Microsoft Visual Studio IDE provides one of the **best C++ debugging environments** with a rich GUI, call stack navigation, variable visualization, and advanced breakpoints.

These notes cover how a fresher can confidently debug C++ programs in Visual Studio.

---

# --------------------------------------------

# ✅ 1. What You Need

### ✔ Microsoft Visual Studio IDE (NOT VS Code)

Install with workload:
**Desktop development with C++**

This includes:

* MSVC Compiler
* MSVC Debugger
* IntelliSense
* Project templates

---

# --------------------------------------------

# 🟩 2. Opening & Running a C++ Project

1. **Create New Project → C++ Console App**
2. Write code
3. Press **Ctrl + F5** → Run **without debugger**
4. Press **F5** → Run **with debugger**

---

# --------------------------------------------

# 🟥 3. Setting Breakpoints (Most Important Skill)

Breakpoints tell the debugger **where to pause** program execution.

### How to set:

* Click on the **left margin (gutter)** next to the line
* A **red dot** appears → this is your breakpoint

### Remove breakpoint:

* Click the red dot again

### Toggle all breakpoints:

`Debug → Windows → Breakpoints`

---

# --------------------------------------------

# 🟦 4. Starting the Debugger

Two main ways:

### ▶ **Start Debugging**

* Menu: **Debug → Start Debugging**
* Keyboard: **F5**

Program runs until:

* It hits a breakpoint
* Or it finishes execution

### ▶ **Step Debugging Controls**

Located at the toolbar:

| Button                   | Action                                    |
| ------------------------ | ----------------------------------------- |
| **Continue (F5)**        | Run until next breakpoint                 |
| **Step Over (F10)**      | Execute one line (skips inside functions) |
| **Step Into (F11)**      | Enters inside the called function         |
| **Step Out (Shift+F11)** | Jump out of current function              |
| **Restart**              | Restart debugging session                 |
| **Stop**                 | End debugging                             |

---

# --------------------------------------------

# 🟨 5. Debugger Windows You Must Know

Visual Studio shows multiple debugging windows.
The 4 MOST IMPORTANT ones:

---

## 5.1 **Locals Window**

Shows **local variables of the current function**.

✔ Helps see variable values
✔ Automatically updates when stepping through code

---

## 5.2 **Watch Window**

You can manually track **any variable or expression**.

Examples:

* `x`
* `result > 10`
* `ptr == nullptr`
* `vector.size()`

Add an expression:

* Debug → Windows → Watch → Watch 1
* Type expression and press Enter

---

## 5.3 **Call Stack Window**

Shows **which functions were called** and in what order.

Example stack:

```
adjust()  
sum()  
main()
```

The top item is the *current executing function*.

Useful to:

* track nested function calls
* identify crash locations
* understand recursion behavior

---

## 5.4 **Autos Window**

Shows variables used in the **current and next few lines**.

---

# --------------------------------------------

# 🟩 6. Example Debugging Session Step-By-Step

Suppose we have:

```cpp
int adjust(int& input) {
    int adjustment = 2;
    input += adjustment;
    return input;
}

int sum(int x, int y) {
    int result = x + y;
    adjust(result);
    return result;
}

int main() {
    int a = 10, b = 12;
    int summation = sum(a, b);
    std::cout << summation;
}
```

### Debug flow:

---

### ✔ 1. Set breakpoint at `summation = sum(a,b);`

Press **F5** → program pauses at the breakpoint.

---

### ✔ 2. Press **Step Into (F11)**

Execution enters:

```cpp
int sum(int x, int y)
```

Locals window now shows:

* `x = 10`
* `y = 12`
* `result = ??? (uninitialized)`

---

### ✔ 3. Step through `result = x + y;`

* Now `result = 22`

---

### ✔ 4. Step Into `adjust(result);`

Visual Studio jumps into:

```cpp
int adjust(int& input)
```

Locals:

* input = 22
* adjustment = 2

After stepping:

* input becomes **24**
* result in `sum()` also becomes **24** because **reference**

---

### ✔ 5. Step Out → returns to `sum()`

* sum returns 24
* summation in main becomes 24

---

### ✔ 6. Watch Window shows:

| Expression       | Value |
| ---------------- | ----- |
| `summation > 10` | true  |

---

# --------------------------------------------

# 🟧 7. Viewing Memory (Advanced but useful)

You can inspect raw memory:

**Debug → Windows → Memory → Memory 1**

Useful for:

* pointer debugging
* array debugging
* understanding memory layout

---

# --------------------------------------------

# 🟪 8. Debugging Common Bugs with Visual Studio

| Bug                       | How debugger helps                  |
| ------------------------- | ----------------------------------- |
| Null pointer              | Watch window shows `ptr == nullptr` |
| Out-of-range array access | Exception info + memory window      |
| Wrong return values       | Call stack + locals help you trace  |
| Reference bugs            | Step Into shows binding behavior    |
| Infinite loops            | Pause → see current line            |

---

# --------------------------------------------

# 🟩 9. Tips for Freshers

* ALWAYS compile Debug build (NOT Release)
* Use **Step Into** to learn how code executes
* Use **Watch Window** for conditions
* Use **Call Stack** to understand function flow
* Break program frequently to study state
* Never assume — always verify variable values

---

# --------------------------------------------

# 🟦 10. Summary Sheet (For Quick Revision)

### **To Debug:**

* F5 → Debug
* F10 → Step Over
* F11 → Step Into
* Shift+F11 → Step Out

### **Windows:**

* Locals
* Autos
* Watch
* Call Stack

### **Must Know:**

* How to add/remove breakpoints
* How to examine values at each step
* How references/pointers behave during debugging
* How call stack changes during function calls

---

---

# 🔴 How to **Add / Remove Breakpoints** in Visual Studio (C++)

Breakpoints tell the debugger *where to pause* program execution so you can inspect variables, memory, and flow.

---

# ✅ **1. How to Add a Breakpoint**

### **Method 1: Click on the Left Margin**

1. Move your mouse to the **left gray margin** beside a line of code
2. Click once
3. A **red dot** appears → this is your breakpoint

✔ Easiest and most commonly used

---

### **Method 2: Press F9**

1. Place your cursor on the line
2. Press **F9**

✔ Toggles a breakpoint on/off for that line

---

### **Method 3: Through Menu**

`Debug → Toggle Breakpoint`
(or right-click a line → **Breakpoint → Insert Breakpoint**)

---

# ❌ **2. How to Remove a Breakpoint**

Same methods as adding:

### **Method 1: Click the Red Dot**

Click the red dot again → disappears
✔ Removes the breakpoint

---

### **Method 2: Press F9**

Place cursor on the break-pointed line → press **F9**

---

### **Method 3: Breakpoint Window**

1. Open:
   `Debug → Windows → Breakpoints`
2. You will see a list of all breakpoints
3. You can:

   * Disable
   * Enable
   * Delete (right-click → Delete)

---

# ⚙️ **3. Disable vs Remove**

* **Disable** = breakpoint stays but is inactive (hollow red circle)
* **Remove** = breakpoint deleted completely

You can disable from the Breakpoint Window.

---

# 🧹 **4. Remove All Breakpoints**

`Debug → Windows → Breakpoints → Delete All`

or
**Ctrl + Shift + F9**

---

# 📌 Summary (Quick Notes for GitHub)

| Action                  | Shortcut / Method             |
| ----------------------- | ----------------------------- |
| Add breakpoint          | Click margin / F9             |
| Remove breakpoint       | Click red dot / F9            |
| Disable breakpoint      | Breakpoints Window            |
| Open Breakpoints Window | Debug → Windows → Breakpoints |
| Delete all breakpoints  | Ctrl + Shift + F9             |

---

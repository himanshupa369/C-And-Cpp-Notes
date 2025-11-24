
---

# ✅ **Debugging C++ in Visual Studio Code — Industry-Level Notes**

Debugging is one of the most essential skills for any C++ developer.
VS Code provides a lightweight but powerful debugging environment using **GDB**, **LLDB**, or **MSVC debugger**.

Below are structured, clean notes for GitHub or professional documentation.

---

# ------------------------------------

# 🟩 **1. Requirements (Industry Standard)**

### ✔ Compiler

Use any one:

* **GCC / MinGW-w64** (Linux/Windows)
* **Clang / LLDB** (Linux/macOS)
* **MSVC (cl.exe)** (Windows)

### ✔ VS Code Extensions

Install:

1. **C/C++ (Microsoft)**
2. **C/C++ Extension Pack** (recommended)
3. **CMake Tools** (if using CMake)

---

# ------------------------------------

# 🟦 **2. Required Configuration Files**

VS Code uses two JSON files:

| File            | Purpose                                |
| --------------- | -------------------------------------- |
| **tasks.json**  | Defines *how to build* the C++ program |
| **launch.json** | Defines *how to debug* the program     |

Both live inside:

```
.vscode/
   ├── tasks.json
   └── launch.json
```

---

# ------------------------------------

# 🟧 **3. tasks.json — Build Instructions**

### Example (GCC / MinGW)

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build-gcc",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "${fileDirname}/*.cpp",
                "-o",
                "${fileDirname}/app.exe"
            ],
            "group": "build",
            "problemMatcher": ["$gcc"]
        }
    ]
}
```

### Example (MSVC)

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build-msvc",
            "type": "shell",
            "command": "cl.exe",
            "args": [
                "/EHsc",
                "/Zi",
                "${file}",
                "/Fe:${fileDirname}\\app.exe"
            ],
            "problemMatcher": ["$msCompile"]
        }
    ]
}
```

---

# ------------------------------------

# 🟨 **4. launch.json — Debug Configurations**

You can add **multiple** debugger configurations.

---

## 🎯 **4.1 Debug Using GCC + GDB**

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug with GDB",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/app.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "externalConsole": true,
            "preLaunchTask": "build-gcc",
            "MIMode": "gdb",
            "miDebuggerPath": "gdb"
        }
    ]
}
```

---

## 🎯 **4.2 Debug Using MSVC Debugger**

```json
{
    "name": "Debug with MSVC",
    "type": "cppvsdbg",
    "request": "launch",
    "program": "${fileDirname}/app.exe",
    "args": [],
    "cwd": "${fileDirname}",
    "console": "externalTerminal",
    "preLaunchTask": "build-msvc"
}
```

---

# ------------------------------------

# 🟩 **5. Debugging Workflow (Step-By-Step)**

### ✔ 1. **Set breakpoints**

* Click left of line number → red dot appears.

### ✔ 2. **Start debugger**

* Press **F5**
* OR open **Run → Start Debugging**

### ✔ 3. **Debugger Windows (Industry Standard Usage)**

| Window                 | Purpose                                  |
| ---------------------- | ---------------------------------------- |
| **Variables / Locals** | Shows function-local variables           |
| **Watch**              | Track expression values (e.g., `x > 10`) |
| **Call Stack**         | Displays active functions in stack order |
| **Breakpoints**        | Enable/disable breakpoints               |
| **Terminal**           | Program output                           |

---

# ------------------------------------

# 🟦 **6. Debugger Controls (Professional Use)**

| Button      | Action                                    |
| ----------- | ----------------------------------------- |
| ▶ Start     | Run debugger                              |
| ⏸ Pause     | Pause execution                           |
| ↪ Step Over | Execute next line (skip inside functions) |
| ↩ Step Into | Go inside function                        |
| ↺ Step Out  | Return from function                      |
| 🔄 Restart  | Restart debugging                         |
| ⛔ Stop      | Stop debugger                             |

---

# ------------------------------------

# 🟧 **7. Example: Debugging Function Calls**

Consider:

```cpp
int sum(int a, int b) {
    int result = a + b;
    adjust(result);  // watch call stack change here
    return result;
}
```

When debugging:

1. Execution enters `sum()`
2. Local variables show `a`, `b`, `result`
3. Stepping into `adjust()`:

   * `sum()`'s activation record freezes
   * `adjust()` appears on top of **Call Stack**
4. Stepping out returns to `sum()`

This mirrors how real compilers manage stack frames.

---

# ------------------------------------

# 🟨 **8. Using the Watch Window (Very Important)**

Examples of useful watch expressions:

* `value > 10`
* `ptr == nullptr`
* `vector.size()`
* `myObj.field`

This helps catch:

* logical bugs
* pointer errors
* incorrect state transitions

---

# ------------------------------------

# 🟥 **9. Industry Tips & Best Practices**

### ✔ Always compile with debug symbols

GCC: `-g`
Clang: `-g`
MSVC: `/Zi`

### ✔ Use `externalConsole: true`

So program input/output behaves normally.

### ✔ Don’t debug optimized (`-O2`) builds

The compiler may:

* inline functions
* remove variables
* reorder code

Debugging becomes misleading.

### ✔ Use assertions

```cpp
assert(ptr != nullptr);
```

### ✔ Use logging (spdlog, glog) for production builds.

### ✔ Use sanitizers during development

* AddressSanitizer
* UBsan
* ThreadSanitizer

These catch:

* memory leaks
* invalid pointers
* undefined behavior

---

# ------------------------------------

# 🟦 **10. Debugging Summary Table**

| Feature                          | GDB                       | LLDB        | MSVC                   |
| -------------------------------- | ------------------------- | ----------- | ---------------------- |
| Platform                         | Win/Linux                 | macOS/Linux | Windows                |
| Best For                         | Linux dev, cross-platform | macOS dev   | Windows enterprise dev |
| Supports conditional breakpoints | ✔                         | ✔           | ✔                      |
| Pretty-print STL                 | Needs config              | Good        | Best                   |
| Performance                      | Good                      | Good        | Excellent              |

---

# ------------------------------------

# 🎯 **Final Summary**

Debugging in VS Code is reliable and powerful when configured properly.
To debug professionally in C++ you must understand:

* breakpoints
* call stack
* scopes & locals
* stepping inside/out/over
* GDB/MSVC configuration
* watch expressions
* debugger configuration files

These skills *are required* in real-world C++ development.

---



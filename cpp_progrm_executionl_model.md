# 🧠 C++ Program Execution Model

## 🔹 1. Source Code
You write the program in a text file using the `.cpp` extension.
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

---

## 🔹 2. Compilation
The **compiler** (e.g., `g++`, `clang++`, `MSVC`) converts your **source code** into **object code (.obj or .o)** — a machine-readable intermediate file.

**Steps performed:**
1. **Preprocessing** – Handles `#include`, `#define`, macros, comments removal.  
2. **Compilation** – Converts code into assembly, checks syntax & semantics.  
3. **Assembly** – Produces object file (machine code).  

---

## 🔹 3. Linking
The **linker** combines your object files with libraries (like the C++ Standard Library) into a single **executable file**.

- Resolves **function calls** (like `cout`, `main`, etc.)
- Merges multiple object files.
- Produces final executable:  
  - Windows → `.exe`  
  - Linux → no extension (binary)

---

## 🔹 4. Loading
When the program runs:
- The **loader** (part of the OS) loads the executable into memory.
- Memory segments are created:
  - **Code segment** – machine instructions.
  - **Data segment** – global/static variables.
  - **Stack** – local variables, function calls.
  - **Heap** – dynamically allocated memory (`new`, `malloc`).

---

## 🔹 5. Execution
The **CPU executes** the instructions starting from the `main()` function.
- Control flows **sequentially** unless redirected (loops, conditionals, function calls).
- Execution continues until:
  - Program ends (`return 0;` or `exit()`), or  
  - Error/exception occurs.

---

## 🔹 6. Termination
- Program releases allocated resources (files, memory).
- OS takes back control and receives an **exit code** from the program.

**Example:**
```cpp
return 0;   // Returns 0 → success
return 1;   // Non-zero → error or abnormal termination
```

---

## 🧩 C++ Execution Model Diagram

```
 Source Code (.cpp)
        ↓
   Preprocessing
        ↓
   Compilation
        ↓
   Assembler → Object Code (.o/.obj)
        ↓
      Linking
        ↓
   Executable File (.exe or binary)
        ↓
      Loading
        ↓
     Execution
        ↓
    Termination
```


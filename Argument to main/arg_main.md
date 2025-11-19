
---

# ✅ **1. Signature of `main` with arguments**

In C++, the recommended standard signature is:

```cpp
int main(int argc, char* argv[])
```

### ✔ `argc`

* **Argument Count**
* Number of arguments passed from the command line
* Always **≥ 1** (program name is argument 0)

### ✔ `argv`

* **Argument Vector**
* Array of C-style strings (`char*`)
* `argv[0]` → program name
* `argv[1]` → first argument
* `argv[n]` → nth argument

---

# ✅ **2. How command-line arguments are passed**

If you run:

```
./app hello 42 "sunny is funny"
```

Then:

```
argc = 4
argv[0] = "./app"
argv[1] = "hello"
argv[2] = "42"
argv[3] = "sunny is funny"
```

---

# ✅ **3. Minimal Working Example**

```cpp
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "argc = " << argc << "\n";

    for(int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "] = " << argv[i] << "\n";
    }

    return 0;
}
```

---

# ✅ **4. Converting Arguments to Numbers (Common Task)**

Because everything in `argv[]` is a **string**, you must convert:

```cpp
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if(argc < 3) {
        std::cout << "Usage: ./app <num1> <num2>\n";
        return 1;
    }

    int a = std::stoi(argv[1]);
    double b = std::stod(argv[2]);

    std::cout << "a + b = " << (a + b) << "\n";
    return 0;
}
```

---

# ✅ **5. `main` alternative signatures**

These are also valid:

```cpp
int main(); // no args
```

```cpp
int main(int argc, char** argv); // same as char* argv[]
```

---

# ✅ **6. Why industry uses `main(int argc, char* argv[])`**

✔ For **passing files**
✔ For **passing configuration values**
✔ For **CLI utilities (Linux tools)**
✔ For **parsing options (-help, --verbose)**
✔ For **scripting, build systems**

Example:

```
./compiler input.cpp -O3 -fno-exceptions
```

---

# ✅ **7. Typical Professional Pattern**

```cpp
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {

    std::vector<std::string> args(argv, argv + argc);

    for(const auto& arg : args) {
        std::cout << arg << "\n";
    }

    return 0;
}
```

This converts raw C-style strings into modern `std::string`.

---

# 🧠 **Key Takeaway**

**`argc` → number of arguments**
**`argv` → array of arguments (C-strings)**
Used for: **files, flags, configuration, scripting, automation, command-line tools**.

---

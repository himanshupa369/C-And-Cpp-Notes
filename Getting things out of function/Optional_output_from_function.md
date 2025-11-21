
# ✅ **What is “optional output” in a function?**

It means **a function may or may not return a meaningful value**, depending on conditions.

Before C++17, developers used:

* `nullptr` (for pointers)
* `bool + output reference`
* error codes
* exceptions

From **C++17**, the best tool is:

# ⭐ **`std::optional<T>` — Optional Output**

`std::optional<T>` represents a **value that may or may not exist**.

---

# ✅ **Why use optional output?**

### In production code:

* Avoid using **magic values** (like `-1` or `""` for error)
* Avoid returning **null pointers**
* Avoid **multiple outputs** just to indicate success
* Improve **safety** and **readability**

---

# ✅ **Basic Example**

```cpp
#include <optional>
#include <string>

std::optional<int> parse_integer(const std::string& s) {
    try {
        return std::stoi(s);   // success
    } catch(...) {
        return std::nullopt;   // no output
    }
}
```

Usage:

```cpp
auto result = parse_integer("123");

if (result.has_value()) {
    std::cout << "Value = " << *result;
} else {
    std::cout << "Invalid integer!";
}
```

---

# 🧠 **Key Idea**

`std::optional<T>` = **"maybe T"**

* **Contains T** → valid output
* **Empty** → function failed or no output

---

# 🔥 **Perfect industry example: find() operations**

```cpp
std::optional<int> find_index(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;   // found
    }
    return std::nullopt; // not found
}
```

---

# ⭐ **Advantages in real-world C++**

| Without optional       | With optional         |
| ---------------------- | --------------------- |
| return -1              | return nullopt        |
| return nullptr         | return optional<T>    |
| use output parameter   | safe, value-in-return |
| unclear API            | clear API             |
| requires documentation | self-documenting      |

---

# 🔍 **How to check optional output?**

### Method 1

```cpp
if (opt)
```

### Method 2

```cpp
if (opt.has_value())
```

### Method 3

```cpp
int value = opt.value_or(0);  // default
```

---

# ⚠️ Avoid mistakes

### Don't do:

```cpp
int x = opt.value(); // undefined if empty
```

Use `.value_or()` instead.

---

# 🔥 C++20 Enhancement

Optional can be used in `if` initializer:

```cpp
if (auto v = parse_integer(text); v.has_value()) {
    std::cout << "OK: " << *v;
} else {
    std::cout << "error";
}
```

---

# 🧩 Summary — Optional Output

### ✔ A function can return:

* `std::optional<T>` → when output is *not guaranteed*
* `std::nullopt` → no value
* `T` → valid result

---

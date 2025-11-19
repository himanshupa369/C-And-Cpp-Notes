
```cpp
//Explanation Code:-
#include <iostream>

//Declare an enum type
//The default type associated with enum classes with C++ is int
//unsigned char : 0 ~ 255
enum class Month :  char {
    Jan = -1, January = Jan, Feb, Mar, 
    Apr, May, Jun,
    Jul, Aug, Sep,
    Oct = 100, Nov, Dec
};


int main(){

    Month month {Month::Jan};
    std::cout << "month : " << static_cast<int>(month) << std::endl;
    std::cout << "sizeof(month) : " << sizeof(month) << std::endl;

    return 0;
}

```
---

# 📘 **Enum Class — Complete & Advanced Notes (C++11+)**

## ✅ 1. What is an Enum Class?

`enum class` is a **strongly-typed, scoped enumeration** introduced in **C++11**.

It lets you define a **custom type** that can take a fixed set of named values.

Example:

```cpp
enum class Month {
    Jan, Feb, Mar, Apr, May, Jun,
    Jul, Aug, Sep, Oct, Nov, Dec
};
```

It is used when your variable can only be one of a specific set of values (months, states, errors, modes, etc.).

---

# ✅ 2. Why Enum Class Instead of Traditional Enum?

| Feature               | Traditional `enum`         | `enum class`             |
| --------------------- | -------------------------- | ------------------------ |
| Scope                 | Pollutes global scope      | Scoped: `Month::Jan`     |
| Type conversion       | Implicitly converts to int | ❌ No implicit conversion |
| Type safety           | Weak                       | Strong                   |
| Name clashes          | Common                     | Impossible               |
| Prefer in modern code | ❌ No                       | ✔ YES                    |

Modern C++ **always prefers `enum class`**.

---

# ✅ 3. Basic Declaration and Use

```cpp
enum class Month {
    Jan, Feb, Mar
};

int main() {
    Month m = Month::Feb;
}
```

---

# ✅ 4. Enum Values Are Stored as Integers Internally

Default numbering:

```
Jan = 0  
Feb = 1  
Mar = 2  
...  
Dec = 11
```

Enums are backed by an **integer type** (default = `int`).

---

# ✅ 5. Printing an Enum Class Value (Must Cast)

`enum class` cannot be printed directly.

```cpp
Month m = Month::Jul;
std::cout << static_cast<int>(m);   // prints 6
```

---

# ✅ 6. Custom Starting Values

You can change the integer values:

```cpp
enum class Month {
    Jan = 1,
    Feb,   // 2
    Mar,   // 3
    ...
    Dec    // 12
};
```

Compiler auto-increments from the last specified value.

---

# ✅ 7. Custom Values in the Middle

```cpp
enum class Month {
    Jan = 1,
    Feb,
    Mar,
    Apr = 18,
    May,    // 19
    Jun,    // 20
};
```

---

# ✅ 8. Multiple Enumerators with the Same Value

```cpp
enum class Month {
    Jan = 1,
    January = Jan,
    Feb,
    Mar
};
```

Both `Jan` and `January` represent the same value.

---

# ✅ 9. Enum Values Defined Using Other Enum Values

```cpp
enum class Month {
    Jan = 1,
    January = Jan,
    Feb,
    Mar
};
```

Changing `Jan` updates `January` automatically.

---

# ✅ 10. Negative Values Are Allowed (if underlying type supports it)

```cpp
enum class Month : char {
    Jan = -1,
    Feb,   // 0
    Mar    // +1
};
```

---

# ✅ 11. Underlying Type (Advanced)

Default underlying type = `int`.

You can override it:

```cpp
enum class Month : unsigned char {
    Jan = 1,
    Feb,
    Mar
};
```

Why override?

* Reduce memory (embedded systems)
* Restrict valid range
* Interop with hardware/network protocols

---

# 📌 **Important Rule**

The assigned values must fit in the underlying type.

Example error:

```cpp
enum class Month : unsigned char {
    Oct = 300  // ❌ error (300 > 255)
};
```

---

# ✅ 12. sizeof(EnumType)

```cpp
std::cout << sizeof(Month);
```

If underlying type is:

* `int` → usually **4 bytes**
* `unsigned char` → **1 byte**
* `char` → **1 byte**
* `short` → **2 bytes**

---

# 🚀 **Complete Final Code From Lecture (Cleaned & Professional)**

```cpp
#include <iostream>

// Strongly typed enum with custom underlying type
// Using 'char' → range roughly from -128 to 127
enum class Month : char {
    Jan = -1,          // custom negative value
    January = Jan,     // alias → same value as Jan

    Feb,               // 0
    Mar,               // 1
    Apr,               // 2
    May,               // 3
    Jun,               // 4
    Jul,               // 5
    Aug,               // 6
    Sep,               // 7

    Oct = 100,         // custom jump
    Nov,               // 101
    Dec                // 102
};

int main() {

    Month month = Month::Jan;

    // Must cast enum class to int to print it
    std::cout << "month : " << static_cast<int>(month) << "\n";

    // Prints the size in bytes of the enum type
    std::cout << "sizeof(month) : " << sizeof(month) << "\n";

    return 0;
}
```

---

# 📘 Summary Notes (GitHub-Ready)

```
# Enum Class (C++11+) — Advance Notes

## Why enum class?
- Strongly typed
- Scoped (no name pollution)
- No implicit conversion to int
- Preferred in modern C++

## Basic syntax
enum class Month { Jan, Feb, Mar };

## Printing
std::cout << static_cast<int>(Month::Feb);

## Custom values
enum class Month { Jan = 1, Feb, Mar };

## Custom mid enum values
enum class Month { Jan = 1, Feb, Mar = 18, Apr };

## Multiple names for same value
Jan = 1,
January = Jan,

## Underlying type
enum class Month : unsigned char {};

## Size
sizeof(Month);

## Rules
- Values must fit in the underlying type
- Default underlying type = int
```

---

---

# ✅ **ENUM in C++ — Production Level Knowledge**

C++ has **two types of enums**:

1. **Traditional enums** (`enum`)
2. **Scoped enums** (`enum class`) — introduced in **C++11**

Both behave very differently and matter in real production code.

---

# 1️⃣ **Traditional Enum (Unscoped Enum)**

```cpp
enum Color {
    RED,
    GREEN,
    BLUE
};
```

### ✔ Characteristics

| Feature              | Behavior                                                         |
| -------------------- | ---------------------------------------------------------------- |
| Scope                | Injects names into outer scope (RED becomes a global identifier) |
| Implicit conversions | Converts to/from `int` automatically                             |
| Type safety          | ❌ Not type-safe                                                  |
| Memory size          | Usually `int` (but implementation defined)                       |
| Forward declaration  | Possible                                                         |

### Why NOT recommended in modern production?

* Pollutes namespace
* Accidental comparisons with integers
* Easy to misuse:

  ```cpp
  int x = RED;  // allowed
  Color c = 5;  // also allowed (!)
  ```

### But still used for:

* C-style APIs
* Bitmask enums (`enum Flags { ... }`)

---

# 2️⃣ **Scoped Enum (`enum class`) — Modern C++ (C++11)**

```cpp
enum class Color : uint8_t {
    Red,
    Green,
    Blue
};
```

### ✔ Advantages (production grade)

| Feature                | Behavior                                 |
| ---------------------- | ---------------------------------------- |
| Scope                  | Names are inside enum (Color::Red)       |
| Type safety            | ✔ Strongly typed; no implicit conversion |
| Underlying type        | Can be explicitly chosen                 |
| No namespace pollution | ✔ Correct                                |
| Better debugging       | Shows scoped names in debuggers          |

### Cannot implicitly convert:

```cpp
Color c = Color::Red;
// int x = c;      // ❌ error
// c = 1;          // ❌ error
```

### Why preferred in production?

* Prevents bugs
* Cleaner API
* Smaller storage possible (`uint8_t`, `uint16_t`)
* Perfect for switch statements

---

# 3️⃣ **Specifying Underlying Type (Very Important)**

```cpp
enum class ErrorCode : int {
    OK = 0,
    NotFound = 404,
    Internal = 500
};
```

**Why important?**

* ABI stability (API compatibility)
* Memory optimization (embedded systems)
* Interfacing with network or hardware protocols

---

# 4️⃣ **Forward Declaration (Production Requirement)**

### Unscoped enum:

```cpp
enum Color;   // allowed
```

### Scoped enum:

```cpp
enum class Color : uint8_t;  // underlying type is required
```

Why?

* Compiler must know its **size** for usage in headers.

---

# 5️⃣ **Enums in Switch (Production Tip)**

Using `enum class` with `switch`:

```cpp
switch(color) {
    case Color::Red:   break;
    case Color::Green: break;
    case Color::Blue:  break;
}
```

✔ Compiler warns if you miss enum values
✔ No silent fall-through errors

---

# 6️⃣ **Using Enum as Bitmask (Advanced Production)**

**Unscoped enum required before C++11**
But modern C++ prefers:

### C++11–20 way with `enum class` and overloaded operators:

```cpp
enum class Permission : uint8_t {
    Read    = 1 << 0,
    Write   = 1 << 1,
    Execute = 1 << 2
};

inline Permission operator|(Permission a, Permission b) {
    return Permission(uint8_t(a) | uint8_t(b));
}
```

---

# 7️⃣ **Why Enum Is Important in Real Projects**

* Represent states (state machines)
* Error codes
* Configuration flags
* Message types in network protocols
* IPC / shared memory structures
* Hardware register fields
* Performance-critical decision logic (switch is faster than if chains)

---

# 8️⃣ **Memory Layout (Real World)**

Default sizes depend on compiler/platform:

| Compiler           | Default Enum Size  |
| ------------------ | ------------------ |
| GCC/Clang (Linux)  | 4 bytes            |
| MSVC (Windows)     | 4 bytes            |
| Embedded compilers | could be 1–4 bytes |

To enforce size (highly recommended):

```cpp
enum class PacketType : uint16_t { ... };
```

---

# 9️⃣ **Best Practices (Production Guidelines)**

### ✔ Always use `enum class` (scoped enums)

### ✔ Always specify underlying type (for ABI stability)

### ✔ Use unscoped enums only when:

* Interacting with C code
* You need bitwise OR without overloads

### ✔ Never rely on default enum size

### ✔ Avoid converting enums to/from integers unless necessary

---

# 🔟 Real Production Example — API Response Type

```cpp
enum class Status : uint8_t {
    Success = 0,
    NetworkError = 1,
    Timeout = 2,
    InvalidData = 3
};

Status fetch_data() {
    ...
    return Status::Timeout;
}

int main() {
    switch (fetch_data()) {
        case Status::Success: ...
        case Status::NetworkError: ...
        case Status::Timeout: ...
        case Status::InvalidData: ...
    }
}
```

✔ Clear
✔ Type-safe
✔ Small
✔ Easy to debug

---



---



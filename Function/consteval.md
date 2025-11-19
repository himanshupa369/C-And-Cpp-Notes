
---

# ⭐ **`consteval` in C++ (C++20)**

**`consteval`** means:
👉 **The function MUST execute at compile time**
👉 It **cannot** run at runtime
👉 If the call is not a compile-time constant → **COMPILER ERROR**

It is stronger than `constexpr`.

---

# 🔥 **1. Basic Example**

```cpp
consteval int add(int a, int b) {
    return a + b;
}

int main() {
    constexpr int x = add(10, 20);    // ✅ OK (compile-time)
    int a = 5;
    int y = add(a, 3);                // ❌ ERROR (runtime variable passed)
}
```

✔ `consteval` FORCE compile-time
✔ If input is not constant → compilation fails

---

# 🎯 **2. Why do we need `consteval`?**

`constexpr` = *can run at compile time OR runtime*
`consteval` = *must run at compile time only*

```cpp
#include <iostream>

//Evaluate this function at compile time. If you can't 
//do that throw a compiler error
consteval int get_value(int multiplier){
    return 3 * multiplier;
}

int main(){

    int result = get_value(4);

    int some_var{5};
    result = get_value(some_var);
   
    return 0;
}

```
Use when:

* You want **absolute guarantee** the computation is compile-time (zero-cost code)
* Useful in **HFT**, **embedded**, **metaprogramming**, **compile-time strings**, **IDs**, **hashes**, etc.

---

# 🧠 **3. Difference Table: `constexpr` vs `consteval`**

| Feature                            | `constexpr` | `consteval` |
| ---------------------------------- | ----------- | ----------- |
| Must run at compile time?          | ❌ No        | ✅ Yes       |
| Can run at runtime?                | ✅ Yes       | ❌ No        |
| Can produce compile-time constant? | Yes         | Yes         |
| Error if not compile time?         | No          | Yes         |
| Introduced                         | C++11       | C++20       |

---

# 📌 **4. Example: Forcing compile-time validation**

```cpp
consteval int square(int x) {
    return x * x;
}

constexpr int good = square(4);  // OK

int n = 5;
int bad = square(n);             // ❌ ERROR
```

This prevents accidental runtime computation.

---

# ⚡ 5. **Useful Real Examples**

### ✔ Compile-time string length

```cpp
consteval std::size_t length(const char* str) {
    std::size_t count = 0;
    while (str[count] != '\0')
        count++;
    return count;
}

constexpr auto L = length("Himanshu"); // OK
char msg[ length("GPT") ];            // OK
```

---

# ✔ **6. `consteval` Constructor (Immediate Functions)**

You can force objects to be constructed at compile time:

```cpp
struct Point {
    int x, y;
    consteval Point(int a, int b) : x(a), y(b) {}
};

constexpr Point p(1, 2);  // OK
Point q(3, 4);            // ❌ ERROR (runtime call)
```

---

# 🎯 **7. `consteval` + `constexpr` Together**

```cpp
consteval int id() { return 100; }

constexpr int x = id();  // allowed
```

✔ A `consteval` function can be used in a `constexpr` context
✔ But not vice-versa

---

# 🚫 **8. Limitations of `consteval`**

`consteval` functions cannot contain:

* dynamic memory (`new`, `delete`)
* I/O (`cout`)
* runtime-dependent operations
* non-constant globals
* try/catch

---

# ⭐ Final Summary (industry-level, short)

* **`consteval` = immediate function** → *must run at compile time*
* Used to enforce high-performance compile-time computation
* Every call must have compile-time constant arguments
* Provides stronger guarantee than `constexpr`
* Very useful for **IDs**, **hash functions**, **lookup tables**, **static configuration**

---



# ⭐ Type Aliases in C++ (98 → C++20)

Type aliases let you create alternate names for types.
They improve readability, reduce verbosity, and are heavily used in modern API design.

---

# 📌 C++98 — `typedef`

### ✔ Available since C (very old)

### ✔ Only syntax before C++11

```cpp
typedef unsigned long long ull;
typedef int* int_ptr;

ull big_number = 100;
int_ptr p = nullptr;
```

### ❌ Limitations

* Cannot alias templates.
* Syntax is backward (type comes last).
* Harder to read for complex types.

Example (hard to read):

```cpp
typedef void (*callback)(int, double);
```

---

# ⭐ C++11 — `using` (Modern Type Alias)

### ✔ Clean and modern syntax

### ✔ Works with templates

### ✔ Replaces most `typedef` usage

```cpp
using ull = unsigned long long;
using int_ptr = int*;
using callback = void(*)(int, double);
```

### Why better?

* Read left-to-right.
* Supports type alias templates (major advantage):

```cpp
template<typename T>
using vec = std::vector<T>;

vec<int> numbers;   // same as std::vector<int>
```

---

# ⭐ C++14 — No change (still uses C++11 aliasing)

But **C++14 libraries** began using `using` aggressively
(e.g., std::enable_if_t, std::decay_t etc.)

Example from standard:

```cpp
template<bool B, class T = void>
using enable_if_t = typename std::enable_if<B,T>::type;
```

---

# ⭐ C++17 — Alias templates become core in metaprogramming

C++17 expands template metaprogramming features → **alias templates used everywhere**.

Example:

```cpp
template<typename T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;
```

Also used in:

* `std::optional`
* `std::variant`
* `std::invoke_result_t`
* `std::void_t` (C++17 feature)

Alias templates help write concise type traits.

---

# ⭐ C++20 — Concepts use type aliases deeply

C++20 introduces **concepts**, and alias templates integrate into constraints:

```cpp
template<typename T>
using Vec = std::vector<T>;

template<typename T>
concept Number = std::is_arithmetic_v<T>;

Number auto x = 10;
Vec<Number auto> v;   // using alias + concept (valid in C++20)
```

Another example:

```cpp
template<typename T>
using string_map = std::map<std::string, T>;
```

### C++20 Modules also encourage alias usage:

```cpp
export using id_t = unsigned long long;
```

---

# 🔥 Summary Table — Type Aliases Across C++ Versions

| C++ Version | Feature                              | Example                                            | Notes                               |
| ----------- | ------------------------------------ | -------------------------------------------------- | ----------------------------------- |
| **C++98**   | `typedef`                            | `typedef int* IP;`                                 | Old syntax, no templates            |
| **C++11**   | `using` alias                        | `using IP = int*;`                                 | Clean syntax, supports templates    |
| **C++14**   | Library alias helpers                | `enable_if_t`                                      | Boosted usage, no language change   |
| **C++17**   | Metaprogramming aliases              | `remove_cvref_t`                                   | Type traits rely on alias templates |
| **C++20**   | Concepts + modules integrate aliases | `template<typename T> using Vec = std::vector<T>;` | Modern design encourages aliasing   |

---

# ⭐ When to Use What?

| Use Case                      | Recommended                  |
| ----------------------------- | ---------------------------- |
| Simple alias                  | `using`                      |
| Alias templates               | `using` (only choice)        |
| Legacy C code                 | `typedef`                    |
| Modern C++ library code       | `using`                      |
| Metaprogramming / type traits | alias templates with `using` |

---

# 🔥 Final Takeaway

```
C++98 → typedef (old)
C++11+ → using (modern, powerful, readable)
C++14/17/20 → using becomes essential for templates, type traits, concepts, modules
```

---


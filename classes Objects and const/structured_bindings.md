
---

# ✅ Structured Bindings in C++

**C++ Version Introduced:** ✅ **C++17** <br>
**Lambda Capture with Structured Bindings:** ✅ **C++20** <br>

---

## ✅ What Are Structured Bindings?

Structured Bindings allow you to **unpack multiple values from an object into separate variables using a simple syntax**.

They work with:

* `struct`
* `class` (only with **public members**)
* `std::pair`
* `std::tuple`
* Arrays

---

## ✅ Basic Syntax

```cpp
auto [a, b] = object;
```

This means:

* `a` → gets first member
* `b` → gets second member
  ✅ **Order matters**

---

## ✅ Example with `struct`

```cpp
struct Point {
    double x;
    double y;
};

Point p{5, 6};

auto [a, b] = p;

std::cout << a << ", " << b;   // Output: 5, 6
```

✅ `a` gets `x`
✅ `b` gets `y`

---

## ✅ Important Rule: Members MUST Be Public

❌ This will FAIL:

```cpp
class Point {
    double x;
    double y;
};
auto [a, b] = p;  // ❌ ERROR: private members
```

✅ This will work:

```cpp
class Point {
public:
    double x;
    double y;
};
```

---

## ✅ Structured Bindings Create **COPIES**

```cpp
auto [a, b] = point1;

point1.x = 44.1;
point1.y = 55.2;

std::cout << a << ", " << b;   // Still prints OLD values
```

✅ `a` and `b` **do NOT change**
✅ They are **independent copies**

---

## ❌ Reference Structured Bindings with `&` (Not Allowed This Way)

```cpp
auto [&a, &b] = point1;   // ❌ INVALID SYNTAX
```

⛔ This syntax is **not allowed**
✅ Correct way (C++17):

```cpp
auto& [a, b] = point1;   // ✅ Proper reference binding
```

---

## ✅ Structured Bindings in Lambda (C++20)

You can **capture structured binding variables inside a lambda**.

```cpp
auto [a, b] = point1;

auto func = [=]() {
    std::cout << a << std::endl;
    std::cout << b << std::endl;
};

func();
```

✅ Works only from **C++20 onward**
❌ If you **don’t capture `a` and `b`**, compiler error occurs

---

## ✅ Why `auto` Is Mandatory

❌ This is INVALID:

```cpp
double [a, b] = point1;   // ❌ ERROR
```

✅ Only valid syntax:

```cpp
auto [a, b] = point1;
```

---

## ✅ Your Program’s Behavior Summary

| Step                 | Output Behavior    |
| -------------------- | ------------------ |
| Initial print        | `(5, 6)`           |
| Structured binding   | `a=5, b=6`         |
| Modify point         | `(44.1, 55.2)`     |
| Print `a`, `b` again | Still `5, 6`       |
| Lambda capture       | Prints same copies |

---

## ✅ Advantages

* ✅ Clean and readable code
* ✅ No `.x`, `.y`, `.first`, `.second`
* ✅ Works with tuples, maps, arrays
* ✅ Great for modern C++ style

---

## ❌ Limitations

* ❌ Only works with **public members**
* ❌ Always uses **auto**
* ❌ Creates **copies by default**
* ❌ Direct reference binding syntax with `&` inside brackets is tricky
* ❌ Lambda capture works properly only from **C++20**

---

## ✅ Real-World Use Cases

* Iterating `std::map`
* Tuple return values
* Clean struct access
* Lambda data processing
* Competitive programming

---

## ✅ Interview One-Line Answer

> Structured binding is a C++17 feature that allows unpacking object data into individual variables using `auto [a, b]`, and it creates copies unless bound by reference.

---

Just say **yes** 👍

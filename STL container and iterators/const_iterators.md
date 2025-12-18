# Constant Iterators in C++ (Personal Notes)

## 1. What is a Constant Iterator?

A **constant iterator** is an iterator that **does not allow modification of the element it points to**.

* You can **read** values using a const iterator
* You **cannot modify** values through it
* You **can move** the iterator itself (increment / decrement)

This helps enforce **const-correctness** and protects container data from accidental modification.

---

## 2. Non-const vs Const Iterators

### Non-const Iterator

* Returned by `begin()` and `end()` on **non-const containers**
* Allows both **reading and modifying** elements

```cpp
std::vector<int> numbers{1, 2, 3};
for(auto it = numbers.begin(); it != numbers.end(); ++it) {
    *it = 100;   // allowed
}
```

### Const Iterator

* Prevents modification of elements

```cpp
std::vector<int> numbers{1, 2, 3};
for(auto it = numbers.cbegin(); it != numbers.cend(); ++it) {
    //*it = 100; // ❌ compile-time error
}
```

---

## 3. How to Obtain Constant Iterators

### 3.1 Using `const_iterator` Explicitly

```cpp
std::vector<int>::const_iterator it = numbers.cbegin();
```

This clearly expresses intent and improves code readability.

---

### 3.2 Using `cbegin()` and `cend()` (Recommended)

```cpp
for(auto it = numbers.cbegin(); it != numbers.cend(); ++it) {
    std::cout << *it << " ";
}
```

* `c` stands for **const**
* Self-documenting and safe

---

### 3.3 Using `auto` with `cbegin()`

```cpp
auto it = numbers.cbegin();
```

* `auto` deduces `const_iterator`
* Still enforces read-only access

---

### 3.4 From a `const` Container

```cpp
const std::vector<int> nums{10, 20, 30};

auto it = nums.begin(); // returns const_iterator
```

* If the container itself is `const`, **all iterators are const**
* Modification is completely forbidden

---

## 4. Constant Reverse Iterators

### Obtained Using `crbegin()` and `crend()`

```cpp
for(auto it = numbers.crbegin(); it != numbers.crend(); ++it) {
    std::cout << *it << " ";
}
```

* Traverse container **backwards**
* Still **read-only**

---

## 5. What is Allowed vs Not Allowed

### ✅ Allowed

* Reading values
* Moving iterator (`++it`, `--it`)

```cpp
++it;   // allowed
std::cout << *it;
```

### ❌ Not Allowed

* Modifying the value pointed to

```cpp
*it = 50; // ❌ error: assignment of read-only location
```

---

## 6. Common Compiler Error

```text
error: assignment of read-only location
```

Reason:

* Trying to modify data through a **const iterator**

---

## 7. Why Constant Iterators Matter

* Enforce **data safety**
* Prevent accidental modification
* Improve **API design**
* Essential for **large codebases** and **library code**

---

## 8. Best Practices

* Prefer `cbegin()` / `cend()` for read-only loops
* Use const iterators in **print / validation / traversal-only logic**
* Use non-const iterators only when modification is intended

---

## 9. Quick Summary

| Feature       | Non-const Iterator | Const Iterator               |
| ------------- | ------------------ | ---------------------------- |
| Read values   | Yes                | Yes                          |
| Modify values | Yes                | No                           |
| Move iterator | Yes                | Yes                          |
| Obtained from | `begin()`          | `cbegin()` / const container |

---

## 10. Key Takeaway

> **Const iterators protect container elements, not the iterator itself.**

You can move the iterator, but you cannot change what it points to.

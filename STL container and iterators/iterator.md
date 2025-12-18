
---

# 📘 Iterators in C++

## What are Iterators?

Iterators are **pointer-like objects** that allow traversal of containers **without knowing how the container is implemented internally**.

* They abstract away memory layout
* Same syntax works for multiple container types
* Core idea: **unified traversal interface**

---

## Why Iterators Exist

Different containers store data differently:

### Contiguous Memory Containers

Examples:

* `std::array`
* `std::vector`

Characteristics:

* Elements are stored **next to each other in memory**
* Navigation possible using pointer arithmetic (`+1`, `-1`)

---

### Non-Contiguous Memory Containers

Examples:

* `std::list`
* `std::map`
* `std::set`

Characteristics:

* Elements may be **scattered across memory**
* No direct pointer arithmetic possible

📌 **Iterators hide these differences** and provide a common way to move through elements.

---

## Core Idea of Iterators

> As long as a container supports the iterator interface, we can traverse it using the same syntax — regardless of its internal structure.

This is the foundation of STL algorithms and generic programming.

---

## Iterator Basics

### Begin Iterator

* Obtained using `begin()`
* Points to the **first element** in the container

### End Iterator

* Obtained using `end()`
* Points **one position past the last element**
* **Does NOT point to valid data**
* Must **never be dereferenced**

📌 Very important distinction:

```
end() ≠ last element
end() = position after last element
```

---

## Declaring Iterators (Classic Syntax)

Example with `std::vector<int>`:

```cpp
std::vector<int>::iterator it_begin = vec.begin();
std::vector<int>::iterator it_end   = vec.end();
```

Key points:

* Iterators are **bound to the container type**
* An iterator for `vector<int>` **cannot** be used for:

  * `vector<double>`
  * `array<int>`
  * any other container

---

## Iterator Behavior (Pointer-Like)

Iterators are designed to **mimic pointer behavior**:

### Dereferencing

```cpp
*it_begin   // accesses element
```

### Increment (Move Forward)

```cpp
++it_begin;
```

Moves iterator to the next element.

### Comparison

```cpp
it_begin != it_end
```

Used to check whether traversal should continue.

---

## Traversing a Container Using Iterators

General traversal pattern:

```cpp
auto it = container.begin();
auto end = container.end();

while (it != end) {
    std::cout << *it << " ";
    ++it;
}
```

This works for:

* `std::vector`
* `std::array`
* `std::list`
* Any STL container with iterators

---

## Step-by-Step Iterator Movement Example

Given container:

```cpp
{11, 22, 33, 44}
```

| Iterator Position | Dereferenced Value | `it != end()` |
| ----------------- | ------------------ | ------------- |
| begin()           | 11                 | true          |
| ++it              | 22                 | true          |
| ++it              | 33                 | true          |
| ++it              | 44                 | true          |
| ++it              | ❌ invalid          | false         |

📌 When iterator equals `end()`:

* Loop must stop
* Dereferencing causes **undefined behavior**

---

## ⚠️ Dereferencing `end()` Iterator

* Results in **undefined behavior**
* May print garbage
* May crash the program
* Must only be used for **comparison**, never for access

---

## Generic Printing Using Iterators (Template Function)

A single function can print **any container** supporting iterators:

```cpp
template<typename Collection>
void print_collection(const Collection& c) {
    auto it = c.begin();
    auto end = c.end();

    std::cout << "[ ";
    while (it != end) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "]";
}
```

---

## Power of Iterators

Using the same function:

```cpp
std::vector<int> v{11, 22, 33, 44};
std::array<int, 4> a{100, 200, 300, 400};

print_collection(v);
print_collection(a);
```

✔ Works seamlessly
✔ No knowledge of container internals required

---

## Why This Is Powerful

* Enables **generic programming**
* STL algorithms (`sort`, `find`, `count`) rely on iterators
* Custom containers can integrate with STL by providing iterators
* Other developers can use your container without documentation

---

## Key Rules to Remember

* `begin()` → first element
* `end()` → one past last element
* Never dereference `end()`
* Iterators behave like pointers
* Same traversal logic works for all STL containers

---

## Big Picture Summary

> Iterators provide a unified, safe, and flexible way to traverse containers, making STL containers and algorithms work together seamlessly.

---

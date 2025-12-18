
---

# 📘 Traversing Subranges Using Iterators (Offsets)

## Core Idea

Iterators can be **offset** to control **which part (subrange)** of a container is processed.

Instead of always working from:

* `begin()` → first element
* `end()` → past the last element

we can **shift these iterators** to define a custom range.

---

## Default Iterator Range

For any container:

```cpp
auto begin_it = container.begin();
auto end_it   = container.end();
```

* `begin_it` → first element
* `end_it` → one past the last element

This range processes **the entire container**.

---

## Adjusting the Iterator Range

We can **add offsets** to `begin()` and **subtract offsets** from `end()`:

```cpp
auto new_begin = container.begin() + begin_offset;
auto new_end   = container.end()   - end_offset;
```

This creates a **subrange** inside the container.

---

## Visual Understanding

Original container:

```
[ 11, 22, 33, 44, 55, 66, 77 ]
```

Example offsets:

* `begin_offset = 2`
* `end_offset = 2`

Resulting range:

```
[ 33, 44, 55 ]
```

Explanation:

* `begin() + 2` → points to `33`
* `end() - 2` → points to `66`
* Loop stops **before** `66`

---

## Modified Print Function with Offsets

```cpp
template<typename Collection>
void print_collection(
    const Collection& c,
    std::size_t begin_offset,
    std::size_t end_offset
) {
    auto it = c.begin() + begin_offset;
    auto end = c.end() - end_offset;

    std::cout << "[ ";
    while (it != end) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "]";
}
```

---

## Key Loop Logic

* Start at **adjusted begin iterator**
* Stop at **adjusted end iterator**
* Dereference only valid iterators
* Stop before hitting the adjusted end

---

## Example: `std::vector<int>`

```cpp
std::vector<int> v{11, 22, 33, 44, 55, 66, 77};

print_collection(v, 2, 2);
```

Output:

```
[ 33 44 55 ]
```

---

## Changing Offsets Dynamically

### Change Begin Offset

```cpp
print_collection(v, 1, 2);
```

Output:

```
[ 22 33 44 55 ]
```

---

### Change End Offset

```cpp
print_collection(v, 1, 3);
```

Output:

```
[ 22 33 44 ]
```

The **end iterator moves closer**, shrinking the range.

---

## Works with Any Iterator-Supported Container

Same logic works for:

* `std::vector`
* `std::array`

Example:

```cpp
std::array<int, 6> a{100, 200, 300, 400, 500, 600};

print_collection(a, 1, 1);
```

Output:

```
[ 200 300 400 500 ]
```

---

## Why This Is Useful

* Process **partial ranges** of data
* Avoid copying subarrays
* Enable flexible algorithms
* Foundation for STL algorithms (`std::copy`, `std::sort`, ranges)

---

## Important Constraints ⚠️

* Offset arithmetic (`+` / `-`) requires **random-access iterators**

  * Works with: `vector`, `array`, `deque`
  * Does NOT work with: `list`, `forward_list`
* Offsets must remain **within valid bounds**
* Dereferencing invalid iterators leads to **undefined behavior**

---

## Conceptual Summary

> By shifting `begin()` and `end()` iterators using offsets, we can precisely control which subset of a container is traversed.

---

## One-Line Definition

**Iterator subranges** are controlled views of container data created by offsetting the begin and end iterators.

---

---

# 📘 Reverse Iterators in C++

## What Are Reverse Iterators?

**Reverse iterators** allow you to traverse a container **backwards**, from the last element to the first.

They provide the same iterator interface but with **reversed traversal direction**.

---

## Key Concept

If a normal iterator moves **forward** when incremented (`++it`),
a **reverse iterator moves backward** when incremented.

---

## Reverse Iterator Boundaries

| Function   | Meaning                                |
| ---------- | -------------------------------------- |
| `rbegin()` | Points to the **last element**         |
| `rend()`   | Points to **before the first element** |

⚠️ `rend()` does **not** point to valid data and must **never be dereferenced**.

---

## Important Difference from Forward Iterators

* `end()` → past **last** element
* `rend()` → past **first** element (in reverse direction)

---

## Traversal Direction

```cpp
++reverse_iterator
```

Moves **backward** in the container.

Example sequence:

```
10 → 9 → 8 → ... → 1
```

---

## Creating Reverse Iterators

### 1️⃣ Using Type Deduction (`auto`)

```cpp
auto rit = numbers.rbegin();
auto rend = numbers.rend();
```

Compiler deduces:

```cpp
std::vector<int>::reverse_iterator
```

---

### 2️⃣ Explicit Type Declaration

```cpp
std::vector<int>::reverse_iterator rit = numbers.rbegin();
std::vector<int>::reverse_iterator rend = numbers.rend();
```

Both approaches are valid.

---

## Example: Reverse Traversal

```cpp
std::vector<int> numbers{1,2,3,4,5,6,7,8,9,10};

auto rit = numbers.rbegin();
auto rend = numbers.rend();

std::cout << "[ ";
while (rit != rend) {
    std::cout << *rit << " ";
    ++rit;
}
std::cout << "]";
```

### Output

```
[ 10 9 8 7 6 5 4 3 2 1 ]
```

---

## How the Loop Works

1. `rbegin()` → last element
2. `rend()` → before first element
3. Loop continues while iterators differ
4. `*rit` accesses valid elements
5. `++rit` moves backward
6. Loop stops when `rit == rend()`

---

## ⚠️ Iterator Type Safety

### ❌ Invalid Comparison

```cpp
auto rit = numbers.rbegin();
auto it  = numbers.end();

if (rit != it) { } // ❌ Compiler error
```

### Why?

* Reverse iterators and forward iterators are **different types**
* Compiler cannot compare them
* Results in **template substitution errors**

✔️ Only compare:

* reverse ↔ reverse
* forward ↔ forward

---

## Modifying Data with Reverse Iterators

Reverse iterators are **non-const by default**.

```cpp
auto rit = numbers.rbegin();
*rit = 34;
```

This modifies the **last element**.

---

## Example Modification

Original:

```
[ 10 9 8 7 6 ]
```

After:

```cpp
*numbers.rbegin() = 34;
```

Result:

```
[ 34 9 8 7 6 ]
```

---

## Key Takeaways

* Reverse iterators traverse containers **backwards**
* `rbegin()` → last element
* `rend()` → before first element
* `++reverse_iterator` moves backward
* Never dereference `rend()`
* Do not compare reverse and forward iterators
* Reverse iterators can **modify data** unless declared `const`

---

## One-Line Definition

A **reverse iterator** is an iterator that moves through a container from the last element to the first.

---


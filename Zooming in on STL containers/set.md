<img width="1017" height="653" alt="Screenshot 2025-12-22 151749" src="https://github.com/user-attachments/assets/c2183209-0bf2-4230-9a41-02b91e7fa31a" />
<br>

---

# `std::set` in C++

## Header

```cpp
#include <set>
```

## Introduced In

* **C++98**
* Comparator flexibility enhanced with **C++11+** (lambdas, functors, `std::function`)

---

## What is `std::set`?

`std::set` is an **associative container** that stores **unique elements** in a **sorted order**.

* Elements are **automatically ordered**
* **Duplicate values are not allowed**
* Ordering is maintained internally (typically via a balanced tree)

---

## Key Properties of `std::set`

* Elements are **always sorted**
* Sorting is done using a **comparison function**
* **Insertion order does not matter**
* **Fast lookup** (logarithmic time complexity)
* **No duplicates allowed**

---

## Ordering Requirement

To store elements in a `std::set`, the type must be **orderable**.

### Default Ordering

* Uses `operator<` internally
* Orders elements from **smallest to greatest**

### Duplicate Detection Logic

Two elements `x` and `y` are considered equal if:

```cpp
!(x < y) && !(y < x)
```

---

## Basic Declaration

```cpp
std::set<int> numbers{11, 6, 2, 15, 16, 9, 12};
```

✔ Stored in sorted order automatically

---

## Iterators in `std::set`

### Forward Iterators

```cpp
set.begin();
set.end();
```

### Reverse Iterators

```cpp
set.rbegin();
set.rend();
```

Used to traverse elements in **reverse order**

---

## Capacity Methods

| Method       | Description               |
| ------------ | ------------------------- |
| `size()`     | Number of elements        |
| `empty()`    | Checks if set is empty    |
| `max_size()` | Maximum possible elements |

---

## Modifiers

### 1. `insert()`

```cpp
auto result = numbers.insert(14);
```

#### Return Type

```cpp
std::pair<iterator, bool>
```

* `first` → iterator to element
* `second` → `true` if insertion succeeded, `false` if duplicate

#### Example

```cpp
if(result.second) {
    std::cout << "Inserted: " << *result.first;
} else {
    std::cout << "Duplicate element";
}
```

---

### 2. `emplace()`

Constructs element **in-place**

```cpp
numbers.emplace(42);
```

* Faster than `insert` for complex objects
* Same return type as `insert`

---

### 3. `erase()`

```cpp
auto it = numbers.find(13);
if(it != numbers.end()) {
    numbers.erase(it);
}
```

Removes element by iterator or value

---

### 4. `clear()`

```cpp
numbers.clear();
```

Removes all elements

---

### 5. `swap()`

```cpp
numbers.swap(otherNumbers);
```

Exchanges contents of two sets

---

## Searching Elements

```cpp
auto it = numbers.find(15);
```

* Returns iterator if found
* Returns `end()` if not found

---

## Storing Custom Types in `std::set`

### Example Class

```cpp
class Book {
public:
    int year;
    std::string title;

    bool operator<(const Book& other) const {
        return year < other.year;
    }
};
```

✔ `operator<` is **mandatory** for ordering

---

## Custom Comparators in `std::set`

### 1. Default Comparator

```cpp
std::set<int> s; // uses std::less<int>
```

---

### 2. Built-in Functors

#### Ascending Order

```cpp
std::set<int, std::less<int>> s;
```

#### Descending Order

```cpp
std::set<int, std::greater<int>> s;
```

---

### 3. Custom Functor

```cpp
struct IntComparator {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

std::set<int, IntComparator> s;
```

---

### 4. Function Pointer Comparator

```cpp
bool compare(int a, int b) {
    return a < b;
}

std::set<int, bool(*)(int,int)> s(compare);
```

⚠️ Cannot use brace initialization

---

### 5. Lambda Comparator

```cpp
#include <functional>

std::set<int, std::function<bool(int,int)>> s(
    [](int a, int b) {
        return a < b;
    }
);
```

✔ Most flexible
❌ Syntax is verbose

---

## Time Complexity

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(log n)   |
| Find      | O(log n)   |
| Erase     | O(log n)   |

---

## Pros

* Automatically sorted
* No duplicates
* Fast search
* Highly customizable ordering
* Ideal for ordered unique data

---

## Cons

* Slower than `std::unordered_set`
* No random access
* Comparator complexity can affect performance

---

## Common Use Cases

* Maintaining sorted unique values
* Implementing dictionaries, indexes
* Eliminating duplicates while keeping order
* Intermediate structure for algorithms

---

## Summary

* `std::set` stores **unique, sorted elements**
* Ordering is done using a **comparator**
* Duplicate insertions are ignored
* Insert returns an `std::pair`
* Supports custom types and custom ordering
* Widely used in associative container design

---


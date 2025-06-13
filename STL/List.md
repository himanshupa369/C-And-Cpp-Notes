
---

## 🔹 **1. Basic Concept Questions**

### Q1: What is `std::list` in C++?

* A **doubly-linked list** from STL.
* Allows **fast insertion/deletion** from anywhere (O(1) if iterator is known).
* Slower random access (O(n)) compared to `vector`.

### Q2: Difference between `std::list` and `std::vector`?

| Feature        | `vector`   | `list`          |
| -------------- | ---------- | --------------- |
| Access         | O(1)       | O(n)            |
| Insertion/Del. | Slow (mid) | Fast (anywhere) |
| Memory         | Contiguous | Non-contiguous  |

---

## 🔹 **2. Functions & Usage**

### Q3: How to insert elements in `std::list`?

```cpp
std::list<int> l = {1, 2, 3};
l.push_front(0);
l.push_back(4);
l.insert(l.begin(), 10); // Insert before first element
```

### Q4: How to delete elements?

```cpp
l.pop_back();      // Removes last
l.pop_front();     // Removes first
l.erase(it);       // Removes element at iterator
l.clear();         // Removes all
```

---

## 🔹 **3. STL List-Specific Functions**

| Function       | Description                                |
| -------------- | ------------------------------------------ |
| `push_back()`  | Add to end                                 |
| `push_front()` | Add to front                               |
| `insert()`     | Insert at position (iterator)              |
| `erase()`      | Remove at position                         |
| `remove(val)`  | Remove all matching values                 |
| `unique()`     | Remove consecutive duplicates only         |
| `sort()`       | Sort the list (default: `<`)               |
| `merge()`      | Merge two sorted lists                     |
| `reverse()`    | Reverse the list                           |
| `splice()`     | Transfer elements from one list to another |
| `clear()`      | Delete all elements                        |

---

## 🔹 **4. Conceptual & Tricky Questions**

### Q5: What is the time complexity of `push_back` and `push_front` in `std::list`?

✅ O(1) — constant time

---

### Q6: Can we do binary search in `std::list`?

❌ No. It doesn’t support random access iterators (needed by `std::binary_search`).

---

### Q7: Is `std::list` thread-safe?

❌ No. STL containers are **not thread-safe** by default.

---

### Q8: What is the use of `splice()`?

✅ Transfers elements from one list to another without copying or reallocating.

```cpp
std::list<int> l1 = {1, 2, 3};
std::list<int> l2 = {4, 5};
auto it = l1.begin();
l1.splice(it, l2);  // l1 = {4, 5, 1, 2, 3}, l2 = {}
```

---

## 🔹 **5. Code-Based Interview Question Example**

### Q9: Write code to remove duplicates from a sorted `std::list`:

```cpp
std::list<int> l = {1, 1, 2, 2, 3, 3, 3, 4};
l.unique(); // Removes only **consecutive** duplicates
```

---

## 🔹 **6. Real-world scenario question**

### Q10: When would you prefer `std::list` over `std::vector`?

✅ When you need frequent insertions and deletions **in the middle of the container**, and **random access is not required**.

---

## 🔹 Bonus: Iterating over a `list`

```cpp
for (auto& val : l) {
    std::cout << val << " ";
}
```

---

---

## 🔹 1. **What is `std::forward_list` in C++?**

* `std::forward_list` is a **singly-linked list** (introduced in **C++11**).
* It uses **less memory** than `std::list` (no backward pointer).
* Optimized for **sequential traversal and insertion/removal at the front**.

---

## 🔹 2. **Key Differences: `forward_list` vs `list`**

| Feature           | `std::list` (doubly-linked) | `std::forward_list` (singly-linked) |
| ----------------- | --------------------------- | ----------------------------------- |
| Pointers per node | 2 (next, prev)              | 1 (next)                            |
| Memory usage      | Higher                      | Lower                               |
| Traversal         | Bidirectional               | Forward only                        |
| Insert at end     | Efficient                   | Slower (must traverse)              |
| Sorting           | Supported                   | Supported                           |
| Introduced in     | C++98                       | C++11                               |

---

## 🔹 3. **Basic Usage**

```cpp
#include <forward_list>
#include <iostream>
using namespace std;

int main() {
    forward_list<int> fl = {10, 20, 30};
    fl.push_front(5);
    fl.insert_after(fl.begin(), 15); // Insert after head
    for (int val : fl) cout << val << " ";
}
```

---

## 🔹 4. **Commonly Used Functions**

| Function                 | Purpose                               |
| ------------------------ | ------------------------------------- |
| `push_front(val)`        | Add element at front                  |
| `pop_front()`            | Remove front element                  |
| `insert_after(pos, val)` | Insert after a given iterator         |
| `erase_after(pos)`       | Erase element after position          |
| `before_begin()`         | Iterator to position **before** begin |
| `sort()`                 | Sort the list                         |
| `remove(val)`            | Remove all matching values            |
| `unique()`               | Remove **consecutive** duplicates     |
| `merge()`                | Merge two sorted forward\_lists       |
| `reverse()`              | Reverse the list                      |
| `clear()`                | Clear all elements                    |

---

## 🔹 5. **Tricky Interview Questions**

### Q1: Why is `insert()` not available in `forward_list`?

* ❌ Because it's a singly-linked list — you can't insert *before* an iterator.
* ✅ Use `insert_after()` with `before_begin()` to insert at start.

---

### Q2: How to insert at the beginning of a `forward_list`?

```cpp
fl.insert_after(fl.before_begin(), 100);
```

---

### Q3: Is random access allowed in `forward_list`?

❌ No. It only supports **forward iterators**, not random access.

---

### Q4: Can we use `reverse()` in `forward_list`?

✅ Yes, since C++11:

```cpp
fl.reverse();
```

---

### Q5: Is `forward_list` memory-efficient?

✅ Yes, it uses less memory than `list` due to having only one pointer (`next`).

---

### Q6: When should you use `forward_list` instead of `vector` or `list`?

✅ When:

* You need frequent insertions/deletions at the **front**
* You want **low memory usage**
* You don’t need bidirectional traversal or random access

---

## 🔹 6. **Code Question: Remove all even numbers from a forward\_list**

```cpp
forward_list<int> fl = {1, 2, 3, 4, 5, 6};
fl.remove_if([](int x) { return x % 2 == 0; });
```

---

## 🔹 7. **Does `forward_list` support `emplace_front()`?**

✅ Yes. Like `push_front()`, but constructs in-place:

```cpp
fl.emplace_front(10);
```

---

## 🔹 8. **Can we sort a `forward_list` of custom objects?**

✅ Yes, using a custom comparator:

```cpp
fl.sort([](const MyType &a, const MyType &b) {
    return a.id < b.id;
});
```

---

## 🧠 Bonus: Iterate with `.before_begin()` and `.insert_after()`

```cpp
auto it = fl.before_begin();
while (next(it) != fl.end()) {
    if (*next(it) == 5) {
        fl.insert_after(it, 99); // Insert before 5
        break;
    }
    ++it;
}
```

---



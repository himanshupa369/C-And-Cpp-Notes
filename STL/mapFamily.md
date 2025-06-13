

---

## 🔧 `emplace()` vs `try_emplace()`

| Feature               | `emplace()`                                             | `try_emplace()`                                                                    |
| --------------------- | ------------------------------------------------------- | ---------------------------------------------------------------------------------- |
| Introduced in         | C++11                                                   | C++17                                                                              |
| Inserts               | Only if key doesn't exist                               | Only if key doesn't exist                                                          |
| Key existence check   | ✅ Yes                                                   | ✅ Yes                                                                              |
| Construction of value | Always attempts to construct value (even if key exists) | ✅ Only constructs value **if key doesn't exist**                                   |
| Performance           | May be slightly slower (due to construction)            | More efficient when value construction is expensive                                |
| Use case              | When you want to insert a new element                   | When you want to insert only if key not present and avoid unnecessary construction |

---

## ✅ Code Example: `emplace()`

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    m.emplace(1, "Apple");              // inserts
    m.emplace(1, "Banana");             // does NOT insert (duplicate key), but still constructs "Banana"

    cout << m[1] << endl;               // Output: Apple

    return 0;
}
```

👉 Even though key `1` already exists, `"Banana"` was still **constructed**, then discarded.

---

## ✅ Code Example: `try_emplace()`

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    m.try_emplace(1, "Apple");         // inserts
    m.try_emplace(1, "Banana");        // does NOT insert and does NOT construct "Banana"

    cout << m[1] << endl;              // Output: Apple

    return 0;
}
```

🟢 Advantage: `"Banana"` was **never constructed**, saving resources.

---

## 💡 When to Use What?

| Scenario                                          | Use             |
| ------------------------------------------------- | --------------- |
| Inserting key-value pair with expensive value     | `try_emplace()` |
| Inserting into containers other than `map`        | `emplace()`     |
| You're using C++11                                | `emplace()`     |
| You want to avoid constructing unnecessary values | `try_emplace()` |

---

Here are **frequently asked interview questions** on `std::map`, `std::multimap`, and `std::unordered_map` in C++, along with key differences and examples—ideal for post-internship and fresher interviews.

---

## ✅ 1. What are the key differences between `map`, `multimap`, and `unordered_map`?

| Feature         | `std::map`           | `std::multimap` | `std::unordered_map` |
| --------------- | -------------------- | --------------- | -------------------- |
| Duplicates Keys | ❌ Not Allowed        | ✅ Allowed       | ❌ Not Allowed        |
| Key Order       | ✅ Sorted (by key)    | ✅ Sorted        | ❌ Unordered (hashed) |
| Underlying DS   | Red-Black Tree (BST) | Red-Black Tree  | Hash Table           |
| Insertion Time  | O(log n)             | O(log n)        | O(1) avg, O(n) worst |
| Header          | `<map>`              | `<map>`         | `<unordered_map>`    |

---

## ✅ 2. Can a map store duplicate keys?

* `std::map` and `unordered_map` → ❌ No duplicate keys
* `std::multimap` → ✅ Yes, allows multiple entries with the same key

---

## ✅ 3. How do you insert elements in a `map`?

```cpp
std::map<int, std::string> m;
m[1] = "Apple";
m.insert({2, "Banana"});
m.emplace(3, "Cherry");
```

---

## ✅ 4. How to iterate over a `map` or `unordered_map`?

```cpp
for (auto& [key, val] : m)
    std::cout << key << ": " << val << std::endl;
```

---

## ✅ 5. What happens if you access a non-existent key using `[]`?

* It inserts the key with a **default value** (dangerous in `unordered_map` or `map`).

```cpp
std::map<int, string> m;
std::cout << m[100]; // Creates m[100] = ""
```

---

## ✅ 6. How to avoid unwanted insertion on access?

Use `.at()`:

```cpp
std::cout << m.at(1);  // throws std::out_of_range if key not found
```

---

## ✅ 7. Can you store custom objects in a `map`?

Yes, but:

* `map`: Must define `operator<` for the key
* `unordered_map`: Must define `hash` and `operator==` for the key

---

## ✅ 8. What is the difference between `emplace()` and `insert()`?

* `insert()` copies/moves the value
* `emplace()` constructs in-place, **more efficient**
* `try_emplace()` (C++17) → avoids constructing the value if the key exists

---

## ✅ 9. What is `equal_range()` in `multimap`?

Returns a pair of iterators covering the range of elements with the same key.

```cpp
multimap<int, string> mm = {{1, "A"}, {1, "B"}};
auto range = mm.equal_range(1);

for (auto it = range.first; it != range.second; ++it)
    cout << it->second << " ";
```

Output: `A B`

---

## ✅ 10. What are common use-cases of `unordered_map`?

* Fast lookups (e.g., frequency counts, hash tables)
* Caching
* Graph adjacency lists
* Competitive programming

---

## ✅ 11. When would you prefer `multimap` over `map`?

* When **duplicate keys** are needed.
* For example: grouping student scores, log timestamps, etc.

---

## ✅ 12. Does `unordered_map` maintain order?

❌ No. Elements are hashed into buckets, so the iteration order is **non-deterministic**.

---

## ✅ 13. What are the major drawbacks of `unordered_map`?

* No key order
* Poor hash functions → performance degrades to O(n)
* No `lower_bound`, `upper_bound`, `equal_range` (not supported)

---

## ✅ 14. How to delete a key in map/unordered\_map?

```cpp
m.erase(2); // Deletes key 2
```

For `multimap`, deletes all entries with that key.

---

## ✅ 15. How to erase a specific key-value pair in `multimap`?

```cpp
auto it = mm.find(1);
if (it != mm.end())
    mm.erase(it);  // Only deletes one occurrence
```

---

## ✅ 16. Can you use `std::map` as a min-heap?

Yes. Since `map` is ordered by key, `begin()` always gives the minimum key.

---

## ✅ 17. Can `map` keys be pointers?

Yes, but you must define how to compare pointers or use a custom comparator.

---

## ✅ 18. What's the difference between `find()` and `count()`?

```cpp
auto it = m.find(5);   // returns iterator or m.end()
int n = m.count(5);    // returns 0 or 1 for map, 0+ for multimap
```

---

## ✅ 19. Can we compare two maps?

```cpp
std::map<int, string> m1, m2;
if (m1 == m2) cout << "Equal";
```

Yes, `==`, `!=`, `<`, etc. are supported.

---

## ✅ 20. What is `load_factor` and `rehash()` in `unordered_map`?

* `load_factor`: ratio of elements to buckets
* `rehash(n)`: sets minimum number of buckets

Used for optimizing performance in hashing.

---

## 🧠 Summary Decision Guide

| Use Case              | STL Container        |
| --------------------- | -------------------- |
| Unique sorted keys    | `std::map`           |
| Duplicate sorted keys | `std::multimap`      |
| Fast lookup, no order | `std::unordered_map` |

---





---

## 🔹1. What is the difference between `set`, `multiset`, and `unordered_set`?

| Feature         | `set`                | `multiset`           | `unordered_set`          |
| --------------- | -------------------- | -------------------- | ------------------------ |
| Duplicates      | ❌ No                 | ✅ Yes                | ❌ No                     |
| Ordering        | ✅ Sorted (ascending) | ✅ Sorted (ascending) | ❌ Unordered (hash table) |
| Time complexity | O(log n) (RB Tree)   | O(log n)             | O(1) average, O(n) worst |
| Underlying Data | Red-Black Tree       | Red-Black Tree       | Hash Table               |
| Header File     | `<set>`              | `<set>`              | `<unordered_set>`        |

---

## 🔹2. When should you prefer `multiset` over `set`?

> When **duplicate elements** are allowed and **you still want sorted order**.

Example:

```cpp
multiset<int> ms = {1, 2, 2, 3};
```

---

## 🔹3. What happens if you insert a duplicate into a `set`?

> The `set` ignores the insertion. No error, no crash.

---

## 🔹4. Can you iterate over a `set` or `unordered_set`?

✅ Yes. Both provide iterators:

* `set` → ordered iteration (`begin() to end()`)
* `unordered_set` → unordered iteration (depends on hash buckets)

---

## 🔹5. How do you delete only **one instance** of a value in `multiset`?

```cpp
multiset<int> ms = {1, 2, 2, 3};
auto it = ms.find(2); // Only one
if (it != ms.end()) ms.erase(it);
```

---

## 🔹6. What is the time complexity of insert/find in `set` vs `unordered_set`?

| Operation  | `set` (RB Tree) | `unordered_set` (Hash Table) |
| ---------- | --------------- | ---------------------------- |
| `insert()` | O(log n)        | O(1) avg, O(n) worst         |
| `find()`   | O(log n)        | O(1) avg, O(n) worst         |
| `erase()`  | O(log n)        | O(1) avg, O(n) worst         |

---

## 🔹7. What is `emplace()` in `set` or `unordered_set`?

> It constructs the element **in-place**, avoiding copies.

```cpp
set<int> s;
s.emplace(10);  // Similar to insert(10)
```

---

## 🔹8. How to count how many times a value exists?

```cpp
multiset<int> ms = {1, 2, 2, 3};
int count_2 = ms.count(2);  // returns 2
```

In `set` and `unordered_set`, `count(x)` is either 0 or 1.

---

## 🔹9. What is `equal_range()` in multiset?

Returns a pair of iterators to the range of elements equal to a given value:

```cpp
auto [start, end] = ms.equal_range(2);
for (auto it = start; it != end; ++it)
    cout << *it << " ";
```

---

## 🔹10. Can you store user-defined types in `set` or `unordered_set`?

✅ Yes, but:

* For `set`: must define **`operator<`**.
* For `unordered_set`: must define **`hash function`** and **`==` operator**.

---

## 🔹11. What are possible issues with `unordered_set`?

* Poor hash function → collisions → O(n) performance.
* No ordering → can't use binary search.
* Iterator invalidation on rehash.

---

## 🔹12. Can we use `lower_bound` and `upper_bound` with all three?

| Function        | `set`/`multiset` | `unordered_set` |
| --------------- | ---------------- | --------------- |
| `lower_bound()` | ✅ Yes            | ❌ Not available |
| `upper_bound()` | ✅ Yes            | ❌ Not available |

---

## 🔹13. How to delete a range of values in `set` or `multiset`?

```cpp
auto it1 = s.lower_bound(10);
auto it2 = s.upper_bound(20);
s.erase(it1, it2);
```

---

## 🔹14. When does `unordered_set` perform worse than `set`?

> When:

* Hash function causes **too many collisions**
* Worst-case time becomes **O(n)**

---

## 🔹15. Which set type is better for lookup-heavy tasks?

| Situation                  | Prefer             |
| -------------------------- | ------------------ |
| Need fast average lookup   | `unordered_set`    |
| Need order / range queries | `set` / `multiset` |
| Need duplicates + order    | `multiset`         |

---

## ✅ Summary

| Container       | Ordered | Duplicates | Time Complexity (insert/find) | Best for                     |
| --------------- | ------- | ---------- | ----------------------------- | ---------------------------- |
| `set`           | ✅ Yes   | ❌ No       | O(log n)                      | Sorted unique elements       |
| `multiset`      | ✅ Yes   | ✅ Yes      | O(log n)                      | Sorted duplicates            |
| `unordered_set` | ❌ No    | ❌ No       | O(1) avg, O(n) worst          | Fast lookup, no order needed |

---


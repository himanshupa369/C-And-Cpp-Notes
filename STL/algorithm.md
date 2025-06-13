
---

### 🔹 1. `std::for_each`

**Header:** `<algorithm>`
**Use Case:** Apply a function to each element in a range.

```cpp
std::vector<int> v = {1, 2, 3};
std::for_each(v.begin(), v.end(), [](int x){ std::cout << x << " "; });
```

---

### 🔹 2. `std::stable_sort`

**Header:** `<algorithm>`
**Use Case:** Sorts with **stable order preservation** for equal elements.

```cpp
std::vector<std::pair<int, int>> v = {{3,1}, {1,2}, {3,2}};
std::stable_sort(v.begin(), v.end());
```

---

### 🔹 3. `std::replace`

**Header:** `<algorithm>`
**Use Case:** Replaces all occurrences of a value with another.

```cpp
std::vector<int> v = {1, 2, 3, 2};
std::replace(v.begin(), v.end(), 2, 9);  // v: {1, 9, 3, 9}
```

---

### 🔹 4. `std::count`

**Header:** `<algorithm>`
**Use Case:** Counts how many times a value appears.

```cpp
int n = std::count(v.begin(), v.end(), 9);  // n = 2
```

---

### 🔹 5. `std::binary_search`

**Header:** `<algorithm>`
**Use Case:** Checks if a value exists in a **sorted** range.

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
bool found = std::binary_search(v.begin(), v.end(), 3);  // true
```

---

### 🔹 6. `std::minmax_element`

**Header:** `<algorithm>`
**Use Case:** Returns **pair of iterators** to smallest and largest element.

```cpp
auto [minIt, maxIt] = std::minmax_element(v.begin(), v.end());
```

---

### 🔹 7. `std::merge`

**Header:** `<algorithm>`
**Use Case:** Merges two **sorted** ranges into a third one.

```cpp
std::vector<int> a = {1,3,5}, b = {2,4,6}, res(6);
std::merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());
```

---

### 🔹 8. `std::next_permutation`

**Header:** `<algorithm>`
**Use Case:** Rearranges to the **next lexicographical permutation**.

```cpp
std::vector<int> v = {1, 2, 3};
std::next_permutation(v.begin(), v.end());  // v: {1, 3, 2}
```

---

### 🔹 9. `std::prev_permutation`

**Header:** `<algorithm>`
**Use Case:** Rearranges to the **previous lexicographical permutation**.

```cpp
std::prev_permutation(v.begin(), v.end());  // v: {1, 2, 3}
```

---

### 🔹 10. `std::accumulate`

**Header:** `<numeric>`
**Use Case:** Computes the sum (or any binary operation) over a range.

```cpp
#include <numeric>
int sum = std::accumulate(v.begin(), v.end(), 0);  // sum = 6
```

---

### 🔹 11. `std::inner_product`

**Header:** `<numeric>`
**Use Case:** Computes the dot product of two ranges.

```cpp
std::vector<int> a = {1, 2}, b = {3, 4};
int dot = std::inner_product(a.begin(), a.end(), b.begin(), 0);  // 1*3 + 2*4 = 11
```

---

### 🔹 12. `std::remove`

**Header:** `<algorithm>`
**Use Case:** Removes **logical occurrences** of a value (needs erase).

```cpp
auto it = std::remove(v.begin(), v.end(), 3);  // moves non-3s forward
v.erase(it, v.end());  // physically remove
```

---

## 📘 Summary Table

| Algorithm          | Header        | Purpose                            |
| ------------------ | ------------- | ---------------------------------- |
| `for_each`         | `<algorithm>` | Apply function to each element     |
| `stable_sort`      | `<algorithm>` | Stable sorting                     |
| `replace`          | `<algorithm>` | Replace value                      |
| `count`            | `<algorithm>` | Count occurrences                  |
| `binary_search`    | `<algorithm>` | Search in sorted range             |
| `minmax_element`   | `<algorithm>` | Get min and max element            |
| `merge`            | `<algorithm>` | Merge two sorted ranges            |
| `next_permutation` | `<algorithm>` | Lexicographic next permutation     |
| `prev_permutation` | `<algorithm>` | Lexicographic previous permutation |
| `accumulate`       | `<numeric>`   | Sum (or operation) of elements     |
| `inner_product`    | `<numeric>`   | Dot product of two ranges          |
| `remove`           | `<algorithm>` | Logical removal of value           |

---

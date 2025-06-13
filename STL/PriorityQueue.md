

---

## 🔹 1. **What is `std::priority_queue` in C++?**

* A container adapter that provides **constant time access to the largest (or smallest) element**.
* Internally implemented as a **binary max-heap** (by default) using a **vector + heap functions**.

---

## 🔹 2. **Basic Syntax**

```cpp
#include <queue>
priority_queue<int> pq;     // Max heap
pq.push(10);
pq.push(5);
cout << pq.top();           // 10
pq.pop();                   // removes 10
```

---

## 🔹 3. **Min Heap using `priority_queue`**

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

---

## 🔹 4. **Important Interview Questions**

### Q1: **What is the time complexity of push/pop operations?**

* Both `push()` and `pop()` take **O(log n)** time due to heap restructuring.

---

### Q2: **How is a `priority_queue` implemented internally?**

* ✅ Uses `std::vector` + `make_heap`, `push_heap`, `pop_heap`.
* ✅ Default comparator: `std::less<T>` → max-heap

---

### Q3: **Can we iterate through a `priority_queue`?**

❌ No. It doesn't expose iterators.

✅ But you can copy to a temporary:

```cpp
priority_queue<int> temp = pq;
while (!temp.empty()) {
    cout << temp.top() << " ";
    temp.pop();
}
```

---

### Q4: **How to store pairs in a `priority_queue`?**

```cpp
priority_queue<pair<int, int>> pq;
pq.push({3, 10});
pq.push({5, 20});
cout << pq.top().first;  // 5
```

✅ Lexicographical ordering applies: first element compared, then second.

---

### Q5: **How to customize comparator for user-defined class?**

```cpp
struct Node {
    int val;
    int priority;
};

struct Compare {
    bool operator()(Node const &a, Node const &b) {
        return a.priority < b.priority; // max heap
    }
};

priority_queue<Node, vector<Node>, Compare> pq;
```

---

### Q6: **Difference between `priority_queue` and `set`?**

| Feature    | `priority_queue` | `set`               |
| ---------- | ---------------- | ------------------- |
| Order      | Heap order       | Sorted order        |
| Access     | Only top         | Any element         |
| Duplicates | Allowed          | Not allowed (`set`) |
| Iterators  | ❌ Not available  | ✅ Yes               |

---

## 🔹 5. **Tricky Questions**

### Q7: What happens if you modify elements inside a `priority_queue`?

❌ You should not mutate elements, as it breaks heap invariants.

---

### Q8: Can we make a min heap of pairs?

✅ Yes:

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
```

---

### Q9: Can we use `emplace()` in `priority_queue`?

✅ Yes, since C++11:

```cpp
pq.emplace(100);
```

---

### Q10: When should you use `priority_queue`?

✅ When:

* You need **efficient access to the highest/lowest priority item**.
* You're implementing greedy algorithms (e.g., Dijkstra, Huffman Coding).

---

## 🔹 6. Bonus Tip: Custom comparator with lambda (C++14+)

```cpp
auto cmp = [](int left, int right) { return left > right; };
priority_queue<int, vector<int>, decltype(cmp)> minHeap(cmp);
```

---

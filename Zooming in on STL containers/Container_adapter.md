
---

# Container Adapters in C++

## Overview

* **Container adapters** are special STL components that **do not store data directly**.
* They **wrap existing sequence containers** and **restrict/customize their interface** to serve a specific purpose.
* Common underlying containers:

  * `std::vector`
  * `std::list`
  * `std::deque`

## Purpose of Container Adapters

* To provide **specific data-access semantics** such as:

  * Last-In-First-Out (LIFO)
  * First-In-First-Out (FIFO)
  * Priority-based access
* Improve **clarity, safety, and intent** in program design by limiting available operations.

---

## Types of Container Adapters

### 1. `std::stack`

**Concept:**

* **LIFO (Last In, First Out)**
* The last element inserted is the first one removed.

**Behavior Example:**

* Push order: `1 → 2 → 3 → 4`
* Pop order: `4 → 3 → 2 → 1`

**Real-world Use Case:**

* Function call management (call stack)
* Undo/redo operations
* Expression evaluation

**Key Operations:**

* `top()` – Access top element
* `push()` / `emplace()` – Add element
* `pop()` – Remove top element
* `swap()` – Swap contents

**Underlying Containers Allowed:**

* `std::vector`
* `std::list`
* `std::deque`

**Required Container Support:**

* `back()`
* `push_back()`
* `pop_back()`

---

### 2. `std::queue`

**Concept:**

* **FIFO (First In, First Out)**
* The first element inserted is the first one removed.

**Behavior Example:**

* Insert: `1 → 2 → 3 → 4`
* Remove: `1 → 2 → 3 → 4`

**Real-world Use Case:**

* Task scheduling
* Message queues
* Producer–consumer problems

**Key Operations:**

* `front()` – Access first element
* `back()` – Access last element
* `push()` / `emplace()` – Insert at back
* `pop()` – Remove from front

**Underlying Containers Allowed:**

* `std::list`
* `std::deque`

**Why `std::vector` is NOT allowed:**

* `std::vector` does **not support `pop_front()`**

---

### 3. `std::priority_queue`

**Concept:**

* Similar to a queue, but elements are **ordered by priority**
* The **highest-priority element** is removed first (by default)

**Behavior:**

* Elements are internally arranged using a **heap**
* Ordering is **not FIFO**

**Real-world Use Case:**

* Resource allocation
* CPU scheduling
* Event simulation

**Key Operations:**

* `top()` – Access highest-priority element
* `push()` / `emplace()` – Insert element
* `pop()` – Remove highest-priority element

**Underlying Containers Allowed:**

* `std::vector`
* `std::deque`

**Why `std::list` is NOT allowed:**

* `std::priority_queue` requires **random access iterators**
* `std::list` does not support random access

---

## Key Design Principles

* Container adapters:

  * **Restrict access intentionally**
  * **Expose only relevant operations**
* Choice of underlying container depends on:

  * Required operations
  * Iterator capabilities
  * Performance considerations

---

## Important Notes

* Container adapters are **not full containers**
* They **reuse sequence containers internally**
* Always consult **STL documentation** to understand:

  * Requirements
  * Allowed base containers
  * Iterator constraints

---

## Summary Table

| Adapter          | Access Order   | Base Containers     | Key Requirement  |
| ---------------- | -------------- | ------------------- | ---------------- |
| `stack`          | LIFO           | vector, list, deque | push/pop at back |
| `queue`          | FIFO           | list, deque         | pop at front     |
| `priority_queue` | Priority-based | vector, deque       | random access    |

---

## Conclusion

Container adapters simplify program design by providing **purpose-driven interfaces** over existing STL containers. They improve readability, correctness, and align data structures with real-world problem semantics.

---


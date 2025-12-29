<img width="1166" height="658" alt="Screenshot 2025-12-29 120403" src="https://github.com/user-attachments/assets/0c769825-fc2b-4600-82f0-8f4ae7894625" />

---

# **Unordered Sets and Unordered Maps (C++)**

---

## **Overview**

* `std::unordered_set` and `std::unordered_map` are **associative containers**
* Unlike `std::set` and `std::map`, they **do NOT maintain any sorted order**
* Designed primarily for **better performance**

---

## **Key Concept: Hash Tables**

* Internally implemented using **hash tables**
* Elements are placed based on **hash values**, not comparisons
* Ordering is **not predictable** and **not user-controllable**

---

## **Main Motivation**

* Faster average-case performance compared to ordered containers
* Particularly effective when:

  * Ordering is **not required**
  * Fast lookup is critical

---

## **Time Complexity (Average Case)**

| Operation | Ordered (`set/map`) | Unordered (`unordered_set/map`) |
| --------- | ------------------- | ------------------------------- |
| Insert    | O(log n)            | O(1)                            |
| Search    | O(log n)            | O(1)                            |
| Erase     | O(log n)            | O(1)                            |

> Note: Worst-case for unordered containers can degrade to **O(n)** depending on hash quality.

---

## **Containers Covered**

### **Unordered Versions**

* `std::unordered_set`
* `std::unordered_map`
* `std::unordered_multiset`
* `std::unordered_multimap`

---

## **Headers Required**

```cpp
#include <unordered_set>
#include <unordered_map>
```

---

## **Key Differences from Ordered Containers**

| Feature            | Ordered (`set/map`) | Unordered                 |
| ------------------ | ------------------- | ------------------------- |
| Ordering           | Sorted by key       | No ordering               |
| Internal structure | Tree (RB-tree)      | Hash table                |
| Custom comparator  | Supported           | Not used                  |
| Custom hash        | Not required        | Required for custom types |
| Iteration order    | Predictable         | Unpredictable             |

---

## **Duplicates**

* `unordered_set` → **No duplicates**
* `unordered_map` → **No duplicate keys**
* `unordered_multiset` → Duplicates allowed
* `unordered_multimap` → Duplicate keys allowed

---

## **Element Access**

* `unordered_map` supports:

```cpp
m[key];
```

* Lookup is fast but **ordering is undefined**

---

## **Custom Hash Functions**

* Required when using **user-defined types** as keys
* Allows control over how elements are distributed
* Mentioned in lecture but **out of scope**

---

## **Important Design Advice (From Lecture)**

* Performance depends on:

  * Data distribution
  * Quality of hash function
* Always test with **real application data**
* Blindly switching to unordered containers can hurt performance

---

## **Instructor’s Preference**

* Prefers `std::set` and `std::map` due to:

  * Deterministic ordering
  * Easier debugging
  * Explicit control using comparators

> Choice depends on **use case**, not theory alone.

---

## **When to Use Unordered Containers**

* Ordering does not matter
* Need fast average lookup
* Examples:

  * Caches
  * Frequency counting
  * Lookup tables
  * Hash-based indexing

---

## **When to Avoid Them**

* When sorted output is required
* When iteration order matters
* When hash collisions are frequent

---

## **One-Line Interview Summary**

> Unordered associative containers use hash tables to provide faster average-case performance but sacrifice predictable ordering.

---

## **Next Topic**

➡ **Container Adapters**

* `std::stack`
* `std::queue`
* `std::priority_queue`

---

```cpp
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

template<typename T>
void show_collection( const T& collection){
    
    std::cout << " [" ;
    for(const auto& elt : collection){
        std::cout << " " << elt ;
    }
    std::cout << "]" << std::endl;
    
}

template <typename T>
void show_map_collection( const T& collection){
    
    std::cout << " [" ;
    for(const auto& [key,value ]: collection){
        std::cout << " (" << key << "," << value << ")" ;
    }
    std::cout << "]" << std::endl;
    
}

int main(){

    //std::set<int> collection1 {11,16,2,912,15,6,15,2};
    std::unordered_set<int> collection1 {11,16,2,912,15,6,15,2};

    //std::map<int,int> collection2 {{1,11},{0,12},{4,13},{2,14},{3,15}};
    std::unordered_map<int,int> collection2 {{1,11},{0,12},{4,13},{2,14},{3,15}};
    
    
    std::cout << "collection1 : " ;
    show_collection(collection1);
    
    std::cout << "collection2 : ";
    show_map_collection(collection2);
    
    //The operations are mostly similar to std::set and std::map . The details
    //can be checked in your favorite C++ standard library reference manual
    
    
    return 0;
}
```


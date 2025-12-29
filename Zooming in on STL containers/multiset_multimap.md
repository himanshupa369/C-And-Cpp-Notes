<img width="1749" height="665" alt="Screenshot 2025-12-29 112443" src="https://github.com/user-attachments/assets/d5244ffd-dd7b-4d26-8436-a5d33b5350fd" />

---

# **C++ STL: `std::multiset` and `std::multimap`**

## **Header Files**

```cpp
#include <set>   // multiset
#include <map>   // multimap
```

---

## **C++ Version**

* Introduced in **C++98**
* Continuously supported and enhanced in later standards

---

## **Definition**

### **`std::multiset`**

* An **associative container** that stores **keys only**
* **Allows duplicate keys**
* Elements are **automatically ordered**

### **`std::multimap`**

* An **associative container** that stores **key–value pairs**
* **Allows duplicate keys**
* Elements are **automatically ordered by key**

---

## **Why `multiset` and `multimap`?**

* `std::set` and `std::map` **do not allow duplicates**
* When an application requires:

  * Multiple identical keys
  * Ordered storage
* `std::multiset` and `std::multimap` are the correct choice

---

## **Key Characteristics (Common)**

1. **Duplicates are allowed**
2. Elements are **always ordered**
3. Default ordering uses:

   ```cpp
   std::less<Key>
   ```

   (ascending order)
4. Ordering is based on:

   * Key itself (`multiset`)
   * Key part of the key–value pair (`multimap`)
5. Internally implemented as **balanced binary search trees**

---

## **Ordering Behavior**

* Insertion order does **not** matter
* Data is **automatically sorted**
* Duplicate elements appear **next to each other**

---

## **`std::multiset` Details**

### **Template Parameters**

```cpp
std::multiset<Key, Comparator>
```

### **Key Properties**

* Stores **only keys**
* Allows **multiple identical keys**
* Requires:

  * `operator<` for custom types
  * Or a custom comparator

### **Example**

```cpp
std::multiset<int> numbers = {1, 1, 2, 2, 3, 3};
```

Stored internally as:

```
1 1 2 2 3 3
```

---

## **Custom Types in `multiset`**

* Custom objects must define:

```cpp
bool operator<(const T& other) const;
```

* Equality is deduced using ordering logic

---

## **`std::multimap` Details**

### **Template Parameters**

```cpp
std::multimap<Key, Value, Comparator>
```

### **Key Properties**

* Stores **key–value pairs**
* Allows **duplicate keys**
* Ordering is done **only on keys**

### **Example**

```cpp
std::multimap<int, std::string> offices = {
    {101, "HR"},
    {101, "Finance"},
    {102, "IT"}
};
```

Stored internally as:

```
101 → HR
101 → Finance
102 → IT
```

---

## **Comparison with `map` and `set`**

| Container       | Stores Duplicates | Stores Values |
| --------------- | ----------------- | ------------- |
| `std::set`      | No                | No            |
| `std::map`      | No                | Yes           |
| `std::multiset` | Yes               | No            |
| `std::multimap` | Yes               | Yes           |

---

## **Iterators**

Both containers support:

* `begin()`, `end()`
* `cbegin()`, `cend()`
* `rbegin()`, `rend()`

Traversal:

* Forward iteration
* Reverse iteration

---

## **Printing Elements**

### **Multiset**

```cpp
for (auto it = ms.begin(); it != ms.end(); ++it) {
    std::cout << *it << " ";
}
```

### **Multimap**

```cpp
for (auto it = mm.begin(); it != mm.end(); ++it) {
    std::cout << it->first << " " << it->second;
}
```

---

## **Insertion Behavior**

* All insertions succeed (unless memory failure)
* Duplicate keys are **always accepted**
* No boolean success flag like `std::set` / `std::map`

---

## **Performance**

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(log n)   |
| Search    | O(log n)   |
| Erase     | O(log n)   |

---

## **Pros**

* Supports duplicate keys
* Automatically ordered
* Fast search and traversal
* Ideal for grouped or repeated data

---

## **Cons**

* Higher memory usage
* Slower than unordered containers
* No random access
* Slightly more complex logic when handling duplicates

---

## **Real-World Use Cases**

### **`std::multiset`**

* Sorted collections with repetitions
* Frequency-based datasets
* Event logs
* Statistical distributions

### **`std::multimap`**

* One-to-many relationships
* Indexing systems
* Database-like mappings
* Grouping values under the same key

---

## **Important Notes**

* Ordering is **always maintained**
* Duplicates are stored **adjacent**
* Keys determine equality
* Custom comparators are fully supported
* Same headers as `set` and `map`

---

## **Summary**

* `std::multiset` and `std::multimap` are **duplicate-friendly versions** of `std::set` and `std::map`
* Data is **ordered by key**
* Ideal when **duplicates + ordering** are required
* APIs and behavior are very similar to `set` and `map`

---

```cpp
#include <iostream>
#include <set> // multiset
#include <map> //multimap


class Book{
    friend std::ostream& operator<< (std::ostream& out, const Book& operand);
public : 
    Book() = default;
    Book(int year, std::string title) 
        : m_year(year),m_title(title)
        {
        }
        
    bool operator< (const Book & right_operand)const{
        return this->m_year < right_operand.m_year;
    }
    
private : 
    int m_year;
    std::string m_title;
};

std::ostream& operator<< (std::ostream& out, const Book& operand){
    out << "Book [" << operand.m_year << ", " << operand.m_title << "]";
    return out;
}


template <typename T>
 void print_multiset(const std::multiset<T> & m_set){
    
    auto it = m_set.begin();
    
    std::cout << "multiset of elements : [" ;
    while(it != m_set.end()){
        
        std::cout << " " << *it ;
        ++it;
    }
    std::cout << "]" << std::endl;
}


template <typename T,typename K>
 void print_multimap(const std::multimap<T,K> & m_map){
    
    auto it = m_map.begin();
    
    std::cout << "multimap of elements : [" ;
    while(it != m_map.end()){
        
        std::cout << " [" << it->first << "," << it->second << "]" ;
        ++it;
    }
    std::cout << "]" << std::endl;
}

int main(){

    std::multiset<int> numbers = {1,2,1,6,2,8,3,9,4,24,6,2};
    
    std::multiset<Book> books = {Book(1734,"Cooking Food"),
                    Book(1930,"Building Computers"),Book(1734,"Farming for Beginners")};
                    
           
    std::cout << "numbers : ";
    print_multiset(numbers);
    
    std::cout << "books : " ;
    print_multiset(books);
    
    std::cout << std::endl;
    std::cout << "multimap : " << std::endl;
    
    
    std::multimap<int,std::string> office_numbers = {std::make_pair(101,"Daniel Gray"),
                        std::make_pair(102,"John Snow"),
                        std::make_pair(103,"Jamie Lanister"),
                        std::make_pair(102,"Van Gomir"),
                        std::make_pair(101,"Kay Moris"),
                        std::make_pair(102,"Zuba Loy"),
                        };
                    
    std::cout << "office_numbers : " ;
    print_multimap(office_numbers);
    
    
    std::multimap<int,Book> other_books = {
                std::make_pair(0,Book(1734,"Cooking Food")),
                std::make_pair(1,Book(1930,"Building Computers")),
                std::make_pair(1,Book(1995,"Farming for Beginners"))
        };
        
    std::cout << "other_books : ";
    print_multimap(other_books);
    
    
    //The rest of the cool stuff you can do with this can be browsed through
    //the documentation.Many methods are similar to the std::set and std::map
    //counterparts.
  
    return 0;
}
```


---

## **`set` / `map` vs `multiset` / `multimap` (Interview Explanation)**

### **Core Difference**

The fundamental difference is **duplicate key support**.

* **`std::set` and `std::map`**
  ➝ **Do NOT allow duplicate keys**

* **`std::multiset` and `std::multimap`**
  ➝ **Allow duplicate keys**

---

## **Container-wise Explanation**

### **1. `std::set` vs `std::multiset`**

| Feature         | `std::set`        | `std::multiset`    |
| --------------- | ----------------- | ------------------ |
| Duplicate keys  | Not allowed       | Allowed            |
| Stored data     | Keys only         | Keys only          |
| Ordering        | Sorted            | Sorted             |
| Insert behavior | Duplicate ignored | Duplicate accepted |
| Typical use     | Unique values     | Repeated values    |

**Interview Line:**

> Use `std::set` when uniqueness is required, and `std::multiset` when multiple identical keys must be stored in sorted order.

---

### **2. `std::map` vs `std::multimap`**

| Feature           | `std::map`             | `std::multimap`        |
| ----------------- | ---------------------- | ---------------------- |
| Duplicate keys    | Not allowed            | Allowed                |
| Stored data       | Key–value pairs        | Key–value pairs        |
| Ordering          | By key                 | By key                 |
| Insert behavior   | Duplicate key rejected | Duplicate key accepted |
| Key-value mapping | One-to-one             | One-to-many            |

**Interview Line:**

> `std::map` enforces unique keys, whereas `std::multimap` supports one-to-many relationships.

---

## **Ordering Behavior (Common to All)**

* Automatically ordered by key
* Default comparator:

```cpp
std::less<Key>
```

* Implemented using **balanced binary search trees**
* Time complexity: **O(log n)** for insert, search, erase

---

## **Important Behavioral Differences**

### **Insertion Result**

* `set` / `map`:
  Return a `pair<iterator, bool>` indicating success or failure
* `multiset` / `multimap`:
  Always insert → **no failure due to duplicates**

---

### **Element Access**

* `map`:

```cpp
m[key];   // allowed
```

* `multimap`:

```cpp
m[key];   // NOT allowed (ambiguous)
```

Must use:

```cpp
equal_range()
find()
```

**Interview Tip:**

> `operator[]` is intentionally disabled in `multimap` because multiple values may exist for the same key.

---

## **When to Use What (Very Important)**

### **Use `set` / `map` when**

* Keys must be **unique**
* Data integrity requires one-to-one mapping
* Examples:

  * User IDs
  * Configuration settings
  * Lookup tables

### **Use `multiset` / `multimap` when**

* Duplicate keys are **expected**
* One-to-many relationships exist
* Examples:

  * Employee → Departments
  * Course → Students
  * Logs, statistics, frequency counts

---

## **One-Line Interview Summary**

> `set` and `map` enforce uniqueness, while `multiset` and `multimap` allow duplicates, all maintaining sorted order with logarithmic complexity.

---


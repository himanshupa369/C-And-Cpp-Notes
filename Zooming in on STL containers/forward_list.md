<img width="1436" height="794" alt="Screenshot 2025-12-22 120928" src="https://github.com/user-attachments/assets/66027be5-db54-41c5-b863-e1155229d2cb" />
<br>
<img width="1731" height="700" alt="Screenshot 2025-12-22 120951" src="https://github.com/user-attachments/assets/02876eda-dde2-4226-98ae-1cf32b39338b" />

---

# **C++ STL: `std::forward_list`**

## **Header**

```cpp
#include <forward_list>
```

---

## **C++ Version**

* Introduced in **C++11**

---

## **What is `std::forward_list`?**

`std::forward_list` is a **singly linked list container** in the C++ Standard Library designed for **very fast insertions and deletions anywhere in the container**, including the middle.

---

## **Internal Data Structure**

* Implemented as a **singly linked list**
* Each node contains:

  * The **data**
  * A **pointer to the next node**
* **No pointer to the previous node**

### Memory Layout

* Elements are stored **non-contiguously** in memory
* Each node may reside at a completely different memory address
* Traversal happens by **following internal pointers**, not by pointer arithmetic

---

## **Traversal Behavior**

* Traversal is done by moving from one node to the next using pointers
* Example flow:

  ```
  10 → 20 → 30 → 40 → 50 → 60
  ```
* No memory locality is required for traversal

---

## **Iterator Support**

| Feature                 | Supported |
| ----------------------- | --------- |
| Forward iterators       | Yes       |
| Reverse iterators       | No        |
| Random access iterators | No        |

### Reason:

* Only **forward pointers** exist
* No backward links → reverse traversal is impossible

---

## **Consequences of Design**

1. **No random access**

   * Cannot jump directly to an element
   * Must traverse sequentially (linear time)
2. **Poor cache locality**

   * Slower traversal compared to `std::vector`
3. **Extremely fast insertions and deletions**

   * Only pointer rewiring is required

---

## **Element Access**

* `front()` → Access first element
* ❌ No `operator[]`
* ❌ No `at()`

---

## **Key Iterators**

| Iterator         | Purpose                           |
| ---------------- | --------------------------------- |
| `begin()`        | First element                     |
| `end()`          | Past-the-end                      |
| `before_begin()` | Position **before** first element |

> `before_begin()` is critical for inserting at the front.

---

## **Insertion Operations**

```cpp
insert_after(iterator, value);
emplace_after(iterator, value);
```

### Insert at Front

```cpp
fl.insert_after(fl.before_begin(), value);
```

---

## **Deletion Operations**

```cpp
erase_after(iterator);
pop_front();
clear();
```

---

## **Searching**

* Uses `std::find`

```cpp
auto it = std::find(fl.begin(), fl.end(), value);
```

* If found → iterator to element
* If not found → `end()`

---

## **Resize Behavior**

```cpp
resize(n);
```

* Resize down → elements lost permanently
* Resize up → new elements **value-initialized**
* Lost elements are **not restored**

---

## **Swap**

```cpp
fl1.swap(fl2);
```

* Exchanges contents efficiently

---

## **Merge**

```cpp
fl1.merge(fl2);
```

* Transfers elements from `fl2` into `fl1`
* **Source list becomes empty**

---

## **Splice Operations**

```cpp
splice_after(pos, source);
splice_after(pos, source, first, last);
```

### Behavior:

* Moves elements from one list to another
* **No copying**
* Source list loses ownership of moved elements

---

## **Removal Operations**

### Remove by Value

```cpp
remove(value);
```

* Removes matching elements

### Remove with Predicate

```cpp
remove_if(predicate);
```

* Predicate returns `true` → element removed

---

## **Reverse**

```cpp
reverse();
```

* Reverses the order of elements

---

## **Unique**

```cpp
unique();
```

* Removes **only contiguous duplicates**
* Non-adjacent duplicates remain

---

## **Sort**

```cpp
sort();
```

* Sorts elements in ascending order
* Commonly followed by `unique()` to remove all duplicates

---

## **Performance Characteristics**

| Operation     | Complexity          |
| ------------- | ------------------- |
| Insert/Delete | O(1)                |
| Search        | O(n)                |
| Access        | O(1) for front only |

---

## **Pros**

* Extremely fast insertions and deletions
* No element shifting
* Efficient memory usage for frequent modifications

---

## **Cons**

* No random access
* Poor cache performance
* Forward traversal only
* Complex iterator logic

---

## **Real-World Usage**

* Rarely used in production
* Suitable for:

  * Embedded systems
  * Low-level data structures
  * Custom memory-critical applications

---

## **Recommendation**

* Prefer **`std::vector`** in most real-world scenarios
* `std::vector` offers:

  * Random access
  * Better cache locality
  * Comparable performance in many insertion cases

---

## **Key Takeaway**

`std::forward_list` trades **access flexibility** for **insertion efficiency** and should be used only when its specific strengths align with the problem requirements.

---

```cpp
#include <iostream>
#include <forward_list>

template <typename T>
void print_collection(const T& collection){
    
    auto it = collection.begin();
    
    std::cout << " Collection [";
    while(it != collection.end()){
        std::cout << " " << *it ;
        ++it;
    }
    std::cout << "]" << std::endl;
}



int main(){

    std::forward_list<int> numbers = {100,2,3,4,5};
    print_collection(numbers);
    
    //Code1 : Element access
    std::cout << " front element : " << numbers.front() << std::endl;


    //Modifiers
    
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "modifiers : " << std::endl;
    
    //Clear
    std::cout << std::endl;
    std::cout << "clear :" << std::endl;
    print_collection(numbers);
    
    numbers.clear();
    
    print_collection(numbers);
    std::cout << std::boolalpha;


    //Insert after
    std::cout << std::endl;
    std::cout << "insert_after : " << std::endl;
    numbers = {11,12,13,14,15}; 
    
    print_collection(numbers);
    auto it_insert = numbers.before_begin();
    
    numbers.insert_after(it_insert,333);
    
    print_collection(numbers);


    //Emplace after : create in place after an iterator
    std::cout << std::endl;
    std::cout << "emplace_after : " << std::endl;
    
    print_collection(numbers);
    
    it_insert = numbers.before_begin();
    
    numbers.emplace_after(it_insert,444);
    
    print_collection(numbers);


    //Erase_after
    std::cout << std::endl;
    std::cout << "erase_after : " << std::endl;
    
    print_collection(numbers);
    
    auto it_erase = std::find(numbers.begin(),numbers.end(),13);
    
    if(it_erase!= numbers.end()){
        std::cout << " Found 13 !" << std::endl;
    }else{
        std::cout << " Couldn't find 13 !" << std::endl;
    }

    //Erase the 14
    numbers.erase_after(it_erase);
    
    print_collection(numbers);


    //pop_front
    std::cout << std::endl;
    std::cout << "pop_front : " << std::endl;
    
    print_collection(numbers);
    
    numbers.pop_front();
    
    print_collection(numbers);


    //resize : up or down
    std::cout << std::endl;
    std::cout << "resize : " << std::endl;
    
    print_collection(numbers);
    
    numbers.resize(10);
    
    print_collection(numbers);
    
    numbers.resize(3); // When you resize down, the elements are lost for good.
                        // if you resize up again,you won't get them back.
    
    print_collection(numbers);
    
    numbers.resize(10);
    
    print_collection(numbers);


   
    //swap
    std::cout << std::endl;
    std::cout << "swap : " << std::endl;
    
    std::forward_list<int> other_numbers {200,400,600};
    
    std::cout << " numbers : ";
    print_collection(numbers);
    
    std::cout << " other_numbers :";
    print_collection(other_numbers);
    
    
    numbers.swap(other_numbers);
    
    std::cout << " numbers : ";
    print_collection(numbers);
    
    std::cout << " other_numbers :";
    print_collection(other_numbers);

    //Other operations
    std::cout << std::endl;
    std::cout << "merge : " << std::endl;
    
    std::forward_list<int> numbers1 {1,5,6};
    std::forward_list<int> numbers2 {9,2,4};
    
    std::cout << " numbers1 : " ;
    print_collection(numbers1);
    
    std::cout << " numbers2 : ";
    print_collection(numbers2);

    //merge
    numbers1.merge(numbers2);
    
    std::cout << " numbers1 : " ;
    print_collection(numbers1);
    
    std::cout << " numbers2 : ";
    print_collection(numbers2);


    //splice_after : moving a range of elements from one container to another
    std::cout << std::endl;
    std::cout << "splice_after : " << std::endl;
    
    numbers1 = {1,5,6,8,3};
    numbers2 = {9,2,4,7,13,11,17};
    
    std::cout << " numbers1 : " ;
    print_collection(numbers1);
    
    std::cout << " numbers2 : ";
    print_collection(numbers2);

    numbers1.splice_after(numbers1.before_begin(),numbers2,numbers2.before_begin(),numbers2.cend());
    
    std::cout << " numbers1 : " ;
    print_collection(numbers1);
    
    std::cout << " numbers2 : ";
    print_collection(numbers2);

    //Remove
    std::cout << std::endl;
    std::cout << "remove : " << std::endl;
    
    numbers = { 1,100,2,3,10,1,11,-1,12 };
    
    print_collection(numbers);
 
    numbers.remove(1); // remove both elements equal to 1
    
    print_collection(numbers);

    //Remove predicate
    numbers.remove_if([](int n){ return n > 10; });
    
    print_collection(numbers);


    //reverse
    std::cout << std::endl;
    std::cout << "reverse : " << std::endl;
    
    numbers = { 1,100,2,3,10,1,11,-1,12 };
    
    print_collection(numbers);
    
    numbers.reverse();
    
    print_collection(numbers);


    //Unique : Removes contiguous duplicates
    //Removes duplicated 100 and 11, but doesn't remove 1
    std::cout << std::endl;
    std::cout << "unique : " << std::endl;
    
    numbers = { 1,100,100,2,3,10,1,11,11,-1,12,10,1 };
    
    print_collection(numbers);
    
    numbers.unique();
    
    print_collection(numbers);


    //Sort
    std::cout << std::endl;
    std::cout << "sort : " << std::endl;
    
    print_collection(numbers);
    
    numbers.sort();
    
    print_collection(numbers);

    //If we want to remove all duplicates, we can first sort and then
    //remove duplicates.
    
    numbers.unique();
    
    print_collection(numbers);
   
    return 0;
}
```

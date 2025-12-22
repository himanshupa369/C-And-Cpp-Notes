
---

# **C++ STL: `std::vector` (Revisited with Iterators)**

## **Header**

```cpp
#include <vector>
```

---

## **C++ Version**

* Available since **C++98**

---

## **What is `std::vector`?**

`std::vector` is a **sequence container** that stores elements **contiguously in memory**, providing **fast random access** and efficient insertion at the back.

It is commonly used as the **default container** in C++ programs and works well in approximately **70% of real-world use cases**.

---

## **Key Characteristics**

* Elements stored **contiguously**
* Supports **random access iterators**
* Fast element access using **array index operator**
* Automatically grows when capacity is exceeded
* Uses a **dynamic array internally**

---

## **Memory Layout**

```
[ e0 ][ e1 ][ e2 ][ e3 ][ e4 ]
```

* Contiguous memory
* Supports pointer arithmetic
* Excellent cache locality

---

## **Iterator Support**

| Iterator Type          | Supported |
| ---------------------- | --------- |
| Forward iterator       | Yes       |
| Reverse iterator       | Yes       |
| Random access iterator | Yes       |

### Iterator Behavior

* `++it` → move forward
* `--it` → move backward
* `it + n` → jump n positions
* Enables array-like operations

---

## **Element Access Methods**

```cpp
operator[]   // No bounds checking
at()         // Bounds checking, throws exception
front()      // First element
back()       // Last element
data()       // Pointer to underlying array
```

### Important Notes

* `operator[]` → **undefined behavior** if out of range
* `at()` → throws `std::out_of_range` exception
* `data()` allows pointer arithmetic (not recommended in production)

---

## **Capacity Operations**

```cpp
size()
capacity()
max_size()
empty()
```

---

## **Capacity Management**

### Automatic Growth

* Capacity increases automatically when exceeded
* Growth often happens by doubling (implementation-defined)

### Reserve

```cpp
reserve(n)
```

* Allocates capacity without changing size
* Prevents frequent reallocations

### Shrink

```cpp
shrink_to_fit()
```

* Reduces unused capacity
* Helps save memory

---

## **Modifiers**

### Add Elements

```cpp
push_back(value)
emplace_back(args...)
```

### Remove Elements

```cpp
pop_back()
clear()
```

---

## **Insertion**

```cpp
insert(iterator, value)
emplace(iterator, args...)
```

### Important Behavior

* Inserted **before** iterator position
* Insertions in middle/front are **expensive (O(n))**
* Existing elements are shifted
* **Iterators may become invalidated**

---

## **Iterator Invalidation Warning**

* Iterators **do not automatically update**
* After insertion:

  * Iterator continues pointing to the same memory location
  * But data at that location may have changed
* Must reassign iterator manually if needed

---

## **Emplace**

```cpp
emplace(iterator, args...)
```

* Constructs element **in place**
* Avoids temporary objects
* Supports inserting multiple arguments
* More efficient for custom objects

---

## **Erase**

### Single Element

```cpp
erase(iterator)
```

### Range Erase

```cpp
erase(begin, end)
```

### Range Rules

* Start iterator: **inclusive**
* End iterator: **exclusive**

---

## **Resize**

```cpp
resize(n)
```

* Shrink → elements permanently removed
* Expand → default-constructed elements added
* Default constructor is invoked

---

## **Swap**

```cpp
swap(other_vector)
```

* Exchanges contents efficiently
* No element copying
* Constant time complexity

---

## **Traversal**

### Forward Traversal

```cpp
for(auto it = v.begin(); it != v.end(); ++it)
```

### Reverse Traversal

```cpp
for(auto it = v.rbegin(); it != v.rend(); ++it)
```

---

## **Performance Characteristics**

| Operation             | Complexity |
| --------------------- | ---------- |
| Random access         | O(1)       |
| Push back (amortized) | O(1)       |
| Insert/erase middle   | O(n)       |
| Traversal             | O(n)       |

---

## **Pros**

* Fast random access
* Excellent cache performance
* Simple and intuitive API
* Works well with STL algorithms
* Default container for most use cases

---

## **Cons**

* Expensive insertions/removals in middle/front
* Iterator invalidation during reallocation
* Requires contiguous memory

---

## **Real-World Recommendation**

* Use `std::vector` as the **default container**
* Switch to other containers only if:

  * Frequent middle insertions (`std::list`)
  * Fixed-size array needed (`std::array`)
  * Very large sparse data

---

## **Key Takeaway**

`std::vector` combines **array-like speed** with **dynamic sizing**, making it the most commonly used and versatile container in modern C++.

---
```cpp
#include <iostream>
#include <vector>


class Item{
public : 
    Item() :m_var(0){
        std::cout << "Item default constructor called" << std::endl;
    }
    Item(int var) : m_var(var){
       // std::cout << "Item constructor called for: " << m_var << std::endl;
    }
    Item(int var1, int var2) : m_var( var1 * var2)
    {
        
    }
    
    Item(const Item& source) : m_var{source.m_var}{
        //std::cout << "Item copy constructor called for :" << m_var << std::endl;
    }
    
    int get() const{
        return m_var;
    }
private : 
    int m_var{0};
};

std::ostream& operator << (std::ostream& out, const Item & item){
    out << "Item [ value : " << item.get() << "]";
    return out;
}


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

    //Code1 :Collection creation and element access
    std::cout << std::endl;
    std::cout << "Creating std::vector's : " << std::endl;
    std::vector<int> numbers {1,2,3,4,5}; // Default initialized vector.
    std::vector<Item> items{Item(6),Item(7),Item(8),Item(9),Item(10)};
    
    std::cout << " numbers  : ";
    print_collection(numbers);
    std::cout << " items : ";
    print_collection(items);
    
    //Accessing elements
    std::cout << std::endl;
    std::cout << "Element access : " << std::endl;
    std::cout << " numbers[3] : " << numbers[3] << std::endl; // No bound check
    std::cout << " numbers.at(3) : " << numbers.at(3) << std::endl; // Bound check
    
    std::cout << " numbers[30] (Undefined behavior):" <<  numbers[30] << std::endl;// No bounds check, undefined behavior, junk value or even crash.
    //std::cout << " numbers.at(30) (throws expception): " << numbers.at(30) << std::endl;
    
    std::cout << " numbers.front() : " << numbers.front() << std::endl;
    std::cout << " numbers.back() :" << numbers.back() << std::endl;
    
    //Data method
    std::cout << " numbers[3] (with underlying data array) : " << (*(numbers.data()+3)) << std::endl;
  
  
    //Code2 : Iterators
    std::cout << "-----------------------" << std::endl;
    
    std::cout << std::endl;
    std::cout << "Iterators : " << std::endl;
    
    //begin() and end()
    auto it = numbers.begin();
    
    std::cout << " Vector(With iterators) : [ ";
    while(it!=numbers.end()){
        std::cout << " " << *it ;
        ++it;
    }
    std::cout << " ]" << std::endl;
    
    //Reverse traversal with rbebin and rend
    auto it_reverse = numbers.rbegin(); // non const iterator
    
    std::cout << " Vector(Reverse traversal with iterators) : [ ";
    while(it_reverse!=numbers.rend()){
        std::cout << " " << *it_reverse ;
        ++it_reverse; // Increments towards the first element of the array.
    }
    std::cout << " ]" << std::endl;    
    
    std::cout << "-----------------------" << std::endl;
    
    
   
    //Code3 : Capacity
    
    std::cout << std::endl;
    
    std::cout << "capacity : " << std::endl;
    std::cout << " numbers : ";
    print_collection(numbers);
    
    std::cout << " numbers size : " << numbers.size() << std::endl;
    std::cout << " numbers max_size : " << numbers.max_size() << std::endl;
    std::cout << std::boolalpha; // Force output of bool as true or false instead of 1 or 0
    std::cout << " numbers is empty : " << numbers.empty() << std::endl;
    std::cout << " numbers capacity : " << numbers.capacity() << std::endl;

    numbers.push_back(20);
    std::cout << " numbers (after push_back) : ";
    print_collection(numbers);
    std::cout << " numbers capacity : " << numbers.capacity() << std::endl;
    
    numbers.shrink_to_fit();
    std::cout << " numbers (after shrink_to_fit) : ";
    print_collection(numbers);
    std::cout << " numbers capacity : " << numbers.capacity() << std::endl;
    
    numbers.reserve(20);
    std::cout << " numbers(after reserve) : ";
    print_collection(numbers);
    std::cout << " numbers size : " << numbers.size() << std::endl;
    std::cout << " numbers capacity : " << numbers.capacity() << std::endl;
    
    std::cout << "-----------------------" << std::endl;
    
    
    
    //Code4 : Modifier methods
    
    std::cout << std::endl;
    std::cout << "clear : " << std::endl;
    print_collection(numbers);
    
    //Clear
    numbers.clear();
    
    print_collection(numbers);
    std::cout << " numbers size : " << numbers.size() << std::endl;
    std::cout << " numbers capacity : " << numbers.capacity() << std::endl;
    
    numbers ={10,20,30,40,50,60};
    
    print_collection(numbers);
    
    
    
    
    //Insert
    //The element you provide as insert()’s second argument is
    //inserted right before the position referred to
    //by the iterator you provide as its first argument
    
    std::cout << std::endl;
    std::cout << "insert : "  << std::endl;
    
    std::cout << " numbers(before insert) : " ;
    print_collection(numbers);
    
    auto it_pos = numbers.begin() + 2;
    
    std::cout << "*it_pos : " << *it_pos << std::endl;
    
    numbers.insert(it_pos,300);
    numbers.insert(it_pos,400); // As we insert new items, it_pos changes the elements it's
                                // pointing to :it is  invalidated. Originaly it was pointing
                                // to 30. It keeps pointing at position 2 but the content at
                                //that position has changed.
    std::cout << " numbers (after insert 300,400) : ";
    print_collection(numbers);
    std::cout << "*it_pos : " << *it_pos << std::endl;
    
    
    
    
    //Emplace 
    std::cout << std::endl;
    std::cout << "emplace : " << std::endl;
    print_collection(items);
    
    auto it_item_pos = items.begin() + 2;
    items.emplace(it_item_pos,45,10); // The parameters following the iterator
                                        // are passed to a constructor of the type stored in 
                                        // the vector.
    print_collection(items);
    
    
    
    //Erase
    std::cout << std::endl;
    std::cout << "erase : " << std::endl;
    print_collection(items);
    
    items.erase(items.begin() + 4);
    
    print_collection(items);
    
    //Range : visualize
    items.erase(items.begin() + 1, items.begin()+4);
    
    print_collection(items);
    
    
    
    
    //Emplace_back
    std::cout << std::endl;
    std::cout << "emplace_back : " << std::endl;
    print_collection(items);
    
    items.emplace_back(10,10); // equivalent to items.emplace(items.end() , 10,10);
    items.emplace_back(10,11);
    items.emplace_back(10,12);
    
    /*
    //The above is equivalent to the code below.
    items.emplace(items.end() , 10,10);
    items.emplace(items.end() , 10,11);
    items.emplace(items.end() , 10,12);
    */
    
    print_collection(items);
    
    
    
    
    //Pop back
    std::cout << std::endl;
    std::cout << "pop_back : " << std::endl;
    print_collection(items);
    
    items.pop_back();
    
    print_collection(items);
    
    //Resize
    std::cout << std::endl;
    std::cout << "resize (Before) : " << std::endl;
    print_collection(items);
    std::cout << "items size : " << items.size() << std::endl;
    std::cout << "items capacity : " << items.capacity() << std::endl;
    
    items.resize(11);// Pay attention on the default constructors being called
    
    print_collection(items);
    std::cout << "after resize : " << std::endl;
    std::cout << "items size : " << items.size() << std::endl;
    std::cout << "items capacity : " << items.capacity() << std::endl; 
    
    
    
    //Swap
    std::cout << std::endl;
    std::cout << "swap : " << std::endl;
    
    
    std::vector<Item> other_items = {Item(22),Item(33),Item(44)};
    
    std::cout << "items : " ;
    print_collection(items);
    
    std::cout << "other_items : " ;
    print_collection(other_items);
    
    //items.swap(other_items);
    other_items.swap(items);
    
    std::cout << "after swap : " << std::endl;
    
    std::cout << "items : " ;
    print_collection(items);
    
    std::cout << "other_items : " ;
    print_collection(other_items);

    
    return 0;
}
```

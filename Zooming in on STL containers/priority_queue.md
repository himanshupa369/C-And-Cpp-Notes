<img width="1153" height="703" alt="Screenshot 2025-12-29 130014" src="https://github.com/user-attachments/assets/9ec2b129-bd91-41f0-8fbb-2424798b2f09" />

---

# **`std::priority_queue` (C++ STL Container Adapter)**

---

## **Header**

```cpp
#include <queue>
```

---

## **C++ Version**

* Introduced in **C++98**
* Comparator, custom container, and lambda usage improved in **C++11+**

---

## **Overview**

* `std::priority_queue` is a **container adapter**
* Provides a **priority-based FIFO-like interface**
* The element with the **highest priority is always accessed first**
* Priority is determined by:

  * `operator<` of stored type (default)
  * OR a **custom comparator**

---

## **Core Concept: Priority Queue**

* Unlike `std::queue` (FIFO), order of insertion **does not matter**
* Removal depends on **priority**, not insertion time
* Internally implemented using a **heap**

---

## **Default Behavior**

* **Highest element** comes out first
* Uses:

  * **`std::vector`** as the underlying container
  * **`std::less<T>`** as the comparator (max-heap)

---

## **Priority Rule**

> The element considered “largest” by the comparator has the **highest priority**.

---

## **Template Definition**

```cpp
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```

---

## **Supported Underlying Containers**

✔ `std::vector` (default)
✔ `std::deque`

❌ `std::list`

* Reason: **No random access iterators**, required for heap operations

---

## **Key Member Functions**

### **Capacity**

* `empty()`
* `size()`

### **Element Access**

* `top()`

  * Returns **const reference**
  * Cannot modify the element

```cpp
int x = pq.top();   // OK
pq.top() = 10;      // ❌ Compilation error
```

---

### **Modifiers**

* `push(value)`
* `emplace(args...)`
* `pop()` → removes **highest priority element**
* `swap(other)`

---

## **Important Design Constraint**

* No iterators
* No random access
* Only **top element** is visible

---

## **Clearing a Priority Queue**

* No `clear()` function
* Must repeatedly call `pop()`

```cpp
while (!pq.empty()) {
    pq.pop();
}
```

---

## **Printing a Priority Queue**

* Pass **by value**
* Pop elements from the copy

```cpp
template<typename T>
void printPQ(std::priority_queue<T> pq) {
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}
```

---

## **Using Custom Types**

### Example

```cpp
std::priority_queue<Book> books;
```

* Priority decided by `Book::operator<`
* Common strategies:

  * Year
  * Title
  * Author
  * Rating

---

### Example `operator<`

```cpp
bool operator<(const Book& other) const {
    return year < other.year; // newer book = higher priority
}
```

---

## **Changing Priority Order**

### 1. Using `std::greater` (Min-Heap)

```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
```

* Smallest element has highest priority

---

### 2. Changing Underlying Container

```cpp
std::priority_queue<int, std::deque<int>, std::greater<int>> pq;
```

---

### 3. Using Custom Functor

```cpp
struct Compare {
    bool operator()(int a, int b) {
        return a < b;
    }
};
std::priority_queue<int, std::vector<int>, Compare> pq;
```

---

### 4. Using Lambda Comparator (Advanced / Ugly Syntax)

```cpp
auto cmp = [](int a, int b) { return a < b; };
std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
```

> Not recommended for production unless necessary.

---

## **Template Function Pitfall**

### ❌ Problem

```cpp
template<typename T>
void printPQ(std::priority_queue<T> pq);
```

Fails when comparator/container is customized.

---

### ✅ Correct

```cpp
template<typename T, typename Container, typename Compare>
void printPQ(std::priority_queue<T, Container, Compare> pq);
```

Same applies to helper functions like `clearPQ`.

---

## **Behavior Summary**

| Comparator            | Top Element  |
| --------------------- | ------------ |
| `std::less` (default) | Largest      |
| `std::greater`        | Smallest     |
| Custom                | User-defined |

---

## **Time Complexity**

| Operation | Complexity |
| --------- | ---------- |
| push      | O(log n)   |
| pop       | O(log n)   |
| top       | O(1)       |

---

## **Pros**

* Fast access to highest-priority element
* Automatic ordering
* Ideal for scheduling problems
* Highly customizable

---

## **Cons**

* No iteration
* Cannot modify elements directly
* Complex template syntax for customization
* Harder debugging due to heap behavior

---

## **Real-World Use Cases**

* Task scheduling
* CPU job queues
* Event handling systems
* Dijkstra’s algorithm
* A* search
* Top-K problems
* HFT / real-time decision queues

---

## **One-Line Interview Summary**

> `std::priority_queue` is a container adapter that always provides access to the highest-priority element based on a comparator, typically implemented using a heap.

---

```cpp
#include <iostream>
#include <queue>



class Book{
    friend std::ostream& operator<< (std::ostream& out, const Book& operand);
public : 
    Book() = default;
    Book(int year, std::string title) 
        : m_year(year),m_title(title)
        {
        }
        
    bool operator< (const Book & right_operand)const{
        return this->m_year < right_operand.m_year; // original prioriy: bigger year comes to the top.
        //return this->m_year > right_operand.m_year; // reverses original priorities : smaller year comes to the top. 
        //return this->m_title < right_operand.m_title; //Orders by titles in reverse order ( D,C,B,A,...).
    }
    
private : 
    int m_year;
    std::string m_title;
};

std::ostream& operator<< (std::ostream& out, const Book& operand){
    out << "Book [" << operand.m_year << ", " << operand.m_title << "]";
    return out;
}



//template <typename T>
//void print_priority_queue(std::priority_queue<T> p_queue){

template<typename T,
                    typename Container = std::vector<T>,
                    typename Compare = std::less<typename Container::value_type>>  
void print_priority_queue(std::priority_queue<T,Container,Compare> p_queue){ 
    
    std::cout << "priority queue of elements : [";
    while(!p_queue.empty()){
        std::cout << " " << p_queue.top() ;
        p_queue.pop();
    }
    std::cout << "]" << std::endl;
    
}


//template <typename T>
//void clear_queue(std::priority_queue<T>& p_queue){

template<typename T,
                    typename Container = std::vector<T>,
                    typename Compare = std::less<typename Container::value_type>>  
void clear_queue(std::priority_queue<T,Container,Compare>& p_queue){ 
    
    std::cout << "Clearing priority queue of size : " << p_queue.size() << std::endl;
    while(!p_queue.empty()){
        p_queue.pop();
    }
    
}



int main(){

    //Code1 : Creating  pushing and accessing
    std::priority_queue<int> numbers1; // The greatest has higher priority
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);
    
    numbers1.push(10);
    numbers1.push(8);
    numbers1.push(12);
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);
    
    numbers1.push(11);
    numbers1.push(3);
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);
    
    //Acess
    std::cout << " numbers1.top() :  " << numbers1.top() << std::endl;


    //Code2 : Can't through top to modify top element : this is
    //because top() returns  a CONST reference.
    std::cout << std::endl;
    std::cout << "modify top element through top():" << std::endl;
    
    std::cout << " numbers1 (before modification) : ";
    print_priority_queue(numbers1);
    
    //numbers1.top() = 500; // Compiler error

    std::cout << " numbers1 (after modification) : ";
    print_priority_queue(numbers1);


    //Code3 : poping : Pops the highest priority element
    std::cout << std::endl;
    std::cout << "poping data : " << std::endl;
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);
    
    numbers1.pop();
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);
    
    numbers1.pop();
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);

    //Code4 : Clearing a priority queue
    std::cout << std::endl;
    std::cout << "clearing a priority queue : " << std::endl;
    
    std::cout << " priority queue initial size : " << numbers1.size() << std::endl;
    std::cout << " numbers1 (before) : ";
    print_priority_queue(numbers1);
    
    clear_queue(numbers1);
    
    std::cout << " priority_queue final size : " << numbers1.size() << std::endl;
    std::cout << " numbers1(after) : ";
    print_priority_queue(numbers1);


    //Code5 : priority_queue of user defined types
    std::cout << std::endl;
    std::cout << "priority queue of user defined type :" << std::endl;
    
    std::priority_queue<Book> books;
    
    //ATTETION : Notice the effects of changing operator< to do a different comparison
    //mechanism and how that affects the priorities perceived by the priority queue
    //this can  be seen in the order the elements are printed in by print_priority_queue : 
    //it starts from the top.
    
    books.push(Book(1921,"Art of War"));
    books.push(Book(2020,"Building Social Media Marketing Strategies"));
    books.push(Book(1990,"Converging Lines of Modern Economy"));
    books.push(Book(1998,"Driving Current Triggered Transistors"));
    
    std::cout << "books : ";
    print_priority_queue(books);
    std::cout << "books size : " << books.size() << std::endl;
    std::cout << "top book : " << books.top() << std::endl;


   //Code6 : specify a custom comparator and/or underlying container
    std::cout << std::endl;
    std::cout << "changing the comparator and underlying container : " << std::endl;
    
    //std::priority_queue<int, std::vector<int>, std::less<int> > numbers2; // Default. 
                                       // Works with single template parameter functions
    //std::priority_queue<int, std::vector<int>, std::greater<int> > numbers2; // Non default,
                //compiler doesn't generate correct template instances,
                //we need to be explicit in our print and clear functions
    //std::priority_queue<int, std::deque<int>, std::greater<int> > numbers2;
    
    //Using your own functor
   
    auto cmp = [](int left, int right) { return left < right; };
    //This uses a different constructor. Let's be honest, this syntax is weird.
    std::priority_queue<int, std::vector<int>, decltype(cmp)> numbers2(cmp);
  
   
    numbers2.push(10);
    numbers2.push(8);
    numbers2.push(12);
    
    std::cout << " numbers2 : ";
    print_priority_queue(numbers2);
    
   
    return 0;
}
```

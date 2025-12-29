
---

# `std::queue` Container Adapter (C++ STL)

## Overview

* `std::queue` is **not a container**, but a **container adapter**.
* It adapts existing **sequence containers** to provide a **queue (FIFO) interface**.
* Elements are:

  * **Inserted at one end (back)**
  * **Removed from the other end (front)**

---

## Core Concept: Queue (FIFO)

* **First In, First Out (FIFO)**
* The first element inserted is the first one removed.

### Example

Insertion order:

```
push(10) → push(20) → push(30)
```

Removal order:

```
10 → 20 → 30
```

---

## Key Characteristics of `std::queue`

* Interface is **restricted**
* No iterators
* No random access
* Elements accessed only through:

  * **front**
  * **back**

---

## Required Interface Methods

To support a queue interface, the underlying container must provide:

* `front()`
* `back()`
* `push_back()`
* `pop_front()`

---

## Underlying Sequence Containers

### Supported Containers

* `std::deque` (default)
* `std::list`

### Unsupported Container

* `std::vector`

  * Reason: **No `pop_front()` method**

---

## Queue Template Definition

```cpp
template<
    class T,
    class Container = std::deque<T>
> class queue;
```

---

## Common Queue Operations

### Capacity

* `empty()` – checks if queue is empty
* `size()` – number of elements

### Element Access

* `front()` – returns reference to the first element
* `back()` – returns reference to the last element

> Both `front()` and `back()` return **references**, allowing modification.

### Modifiers

* `push(value)` – insert at back
* `emplace(args...)` – construct in place
* `pop()` – remove element from front
* `swap(other)` – swap contents

---

## Printing a Queue (Standard Pattern)

### Key Idea

* Queues **do not provide iteration**
* To print all elements:

  * Pass the queue **by value**
  * Repeatedly:

    * Access `front()`
    * Print it
    * Call `pop()`

### Why Pass by Value?

* Original queue remains unchanged
* Only the copy is modified

---

## Clearing a Queue

### No Built-in `clear()` Method

* Must remove elements manually

### Correct Approach

* Pass queue **by reference**
* Loop until `empty()`
* Call `pop()` repeatedly

---

## Modifying Queue Elements

* Since `front()` and `back()` return references:

```cpp
queue.front() = 500;
queue.back()  = 600;
```

* Modification affects the actual elements in the queue

---

## Queue with User-Defined Types

* `std::queue` supports **custom types**

```cpp
std::queue<Book> books;
```

* FIFO behavior remains unchanged
* First inserted object is removed first

---

## Custom Underlying Container

### Syntax

```cpp
std::queue<int, std::list<int>> q1;
std::queue<int, std::deque<int>> q2; // default
```

### Why Customize?

* Performance tuning
* Memory behavior
* Application-specific requirements

---

## Template Function Compatibility Issue

### Problem

* `std::queue` has **two template parameters**
* Helper functions may accept only one
* Causes compiler errors when non-default container is used

### Incorrect

```cpp
template<typename T>
void printQueue(std::queue<T> q);
```

### Correct

```cpp
template<typename T, typename Container>
void printQueue(std::queue<T, Container> q);
```

### Same Applies To

* `clearQueue`
* Any function accepting `std::queue`

---

## Summary Table

| Feature           | Details           |
| ----------------- | ----------------- |
| Type              | Container Adapter |
| Ordering          | FIFO              |
| Access Points     | front, back       |
| Default Container | `std::deque`      |
| Other Supported   | `std::list`       |
| Unsupported       | `std::vector`     |
| Iterators         | Not available     |

---

## Real-World Use Cases

* Task scheduling
* Message queues
* Producer–consumer systems
* Event handling systems

---

## Key Takeaway

`std::queue` enforces **FIFO behavior** by adapting sequence containers and limiting element access to the front and back. It ensures correctness and clarity when sequential processing is required.

---

```cpp
#include <iostream>
#include <queue>
#include <list>
#include <deque>


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

template<typename T, typename Container = std::deque<T>>
void print_queue(std::queue<T,Container> queue){
    
    std::cout << " queue of items : [";
    while(!queue.empty()){
        T item = queue.front();
        std::cout << " " << item ;
        queue.pop();
    }
    std::cout << "]" << std::endl;
    
}

template<typename T, typename Container = std::deque<T>>
void clear_queue(std::queue<T,Container>& queue){
    std::cout << " Clearing queue of size : " << queue.size() << std::endl;

    while(!queue.empty()){
        queue.pop();
    }
    
}


int main(){

     //Code1 : Creating  pushing and accessing
    std::cout << "Creating pushing and accessing : " << std::endl;
    std::queue<int> numbers1;
    
    std::cout << " numbers1 : ";
    print_queue(numbers1);
    
    numbers1.push(10);
    numbers1.push(20);
    numbers1.push(30);
    
    std::cout << " numbers1 : ";
    print_queue(numbers1);
    
    numbers1.push(40);
    numbers1.push(50);
    
    std::cout << " numbers1 : ";
    print_queue(numbers1);

    //Acess
    std::cout << " numbers1.front() :  " << numbers1.front() << std::endl;
    std::cout << " numbers1.back() : " << numbers1.back() << std::endl;

    //Code2 : Modify through top : this is because front and back return  a reference
    std::cout << std::endl;
    std::cout << "modify top element through front and back :" << std::endl;
    
    std::cout << " numbers1 (before modification) : ";
    print_queue(numbers1);
    
    numbers1.front() = 500;
    numbers1.back() = 600;
    
    std::cout << " numbers1 (after modification) : ";
    print_queue(numbers1);

    //Code3 : poping
    std::cout << std::endl;
    std::cout << "poping data : " << std::endl;
    
    std::cout << " numbers1 : ";
    print_queue(numbers1);
    
    numbers1.pop();
    
    std::cout << " numbers1 : ";
    print_queue(numbers1);
    
    numbers1.pop();
    
    std::cout << " numbers1 : ";
    print_queue(numbers1);


    //Code4 : Clearing a queue
    std::cout << std::endl;
    std::cout << "clearing a queue : " << std::endl;
    
    std::cout << " queue initial size : " << numbers1.size() << std::endl;
    
    std::cout << " numbers1 (before) : ";
    print_queue(numbers1);
    
    clear_queue(numbers1);
    
    std::cout << " queue final size : " << numbers1.size() << std::endl;
    std::cout << " numbers1(after) : ";
    print_queue(numbers1);


    //Code5 : Queue of user defined types
    std::cout << std::endl;
    std::cout << "queue of user defined type :" << std::endl;
    
    std::queue<Book> books;
    
    books.push(Book(1921,"The Art of War"));
    books.push(Book(2000,"Social Media Marketing"));
    books.push(Book(2020,"How the Pandemic Changed the World"));
    
    std::cout << " books : ";
    print_queue(books);
    std::cout << " books size : " << books.size() << std::endl;
    std::cout << " front book : " << books.front() << std::endl;
    std::cout << " back book : " << books.back() << std::endl;


    //Code6 Specify underlying container
    std::cout << std::endl;
    std::cout << "custom underlying sequence container : " << std::endl;
        
    std::queue<int,std::list<int>> numbers3;
    std::queue<int,std::deque<int>> numbers4;

    numbers3.push(3);
    numbers3.push(4);
    
    numbers4.push(5);
    numbers4.push(6);
    
    std::cout << " numbers3 : ";
    print_queue(numbers3);

    std::cout << " numbers4 : ";
    print_queue(numbers4);
    
   
    return 0;
}
```

<img width="1414" height="736" alt="Screenshot 2025-12-29 122755" src="https://github.com/user-attachments/assets/7026806e-b24a-4d7c-a134-760be56c15a0" />

---

# `std::stack` Container Adapter (C++ STL)

## Overview

* `std::stack` is **not a container**; it is a **container adapter**.
* It **adapts sequence containers** to provide a **stack (LIFO) interface**.
* It restricts access so elements can be accessed **only from the top**.

---

## Core Concept: Stack (LIFO)

* **Last In, First Out (LIFO)**
* The last element inserted is the first element removed.

### Example

Insertion order:

```
push(10) → push(20) → push(30)
```

Removal order:

```
30 → 20 → 10
```

---

## Key Characteristics of `std::stack`

* Not a standalone container
* Built on top of sequence containers
* Access restricted to:

  * **Top element only**
* No iterators provided
* No random access

---

## Underlying Sequence Containers

### Supported Containers

* `std::deque` (default)
* `std::vector`
* `std::list`

### Required Operations

The underlying container **must support**:

* `back()`
* `push_back()`
* `pop_back()`

---

## Stack Template Definition

```cpp
template<
    class T,
    class Container = std::deque<T>
> class stack;
```

* `T` → type of stored elements
* `Container` → underlying sequence container (optional)

---

## Common Stack Operations

### Capacity

* `empty()` – checks if stack is empty
* `size()` – number of elements

### Element Access

* `top()` – returns **reference** to top element

  * Does **not remove** the element
  * Can be used to modify the top element

### Modifiers

* `push(value)` – inserts element on top
* `emplace(args...)` – constructs element in place
* `pop()` – removes top element (no return value)
* `swap(other)` – swaps contents

---

## Important Behavior of `top()`

* Returns a **reference**, not a copy
* Allows modification:

```cpp
stack.top() = newValue;
```

* Does **not** remove the element

---

## Printing a Stack (Important Pattern)

### Key Idea

* Stack does **not allow iteration**
* To print all elements:

  * Pass stack **by value**
  * Repeatedly:

    * Access `top()`
    * Print it
    * Call `pop()`

### Reason for Passing by Value

* Original stack remains unchanged
* Copy is destroyed during printing

---

## Clearing a Stack

### No Built-in `clear()` Method

* Must manually pop elements

### Correct Approach

* Pass stack **by reference**
* Loop until `empty()` is true
* Call `pop()` repeatedly

---

## Stack with User-Defined Types

* `std::stack` fully supports **custom classes**
* Example:

```cpp
std::stack<Book> books;
```

* Behavior remains LIFO
* Last inserted object is removed first

---

## Custom Underlying Container

### Syntax

```cpp
std::stack<int, std::vector<int>> s1;
std::stack<int, std::list<int>> s2;
std::stack<int, std::deque<int>> s3; // default
```

### Why Customize?

* Performance tuning
* Memory behavior
* Cache locality (`vector`)

---

## Template Pitfall: Function Compatibility

### Problem

* Stack can have **two template parameters**
* Helper functions (e.g., `printStack`) may accept only one
* Causes **compiler errors** when using non-default container

### Example Issue

```cpp
template<typename T>
void printStack(std::stack<T> s); // fails for vector/list
```

### Correct Fix

Include underlying container in template:

```cpp
template<typename T, typename Container>
void printStack(std::stack<T, Container> s);
```

### Same Fix Applies To

* `clearStack`
* Any helper function accepting `std::stack`

---

## Why Default (`std::deque`) Sometimes Works

* Compiler assumes default container if not specified
* Works only when underlying container is `std::deque`
* Fails when explicitly using `vector` or `list`

---

## Summary Table

| Feature           | Details                   |
| ----------------- | ------------------------- |
| Type              | Container Adapter         |
| Access            | Top only                  |
| Ordering          | LIFO                      |
| Default Container | `std::deque`              |
| Custom Containers | `vector`, `list`, `deque` |
| Iterators         | Not supported             |
| Clear Method      | Not provided              |

---

## Real-World Use Cases

* Function call stack
* Undo / redo systems
* Backtracking algorithms
* Expression evaluation
* Syntax parsing

---

## Key Takeaway

`std::stack` enforces **strict LIFO behavior** by adapting sequence containers and limiting access to the top element only. It improves correctness and clarity when stack semantics are required.

---

```cpp
#include <iostream>
#include <stack>
#include <vector>
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
void print_stack(std::stack<T,Container> stack){

//template <typename T>
//void print_stack(std::stack<T> stack){


    //Notice that we're working on a copy here. IMPORTANT
    std::cout << "stack of elements : [";
    while(!stack.empty()){
        T item = stack.top();
        std::cout << " " << item ;
        stack.pop(); // Poping from a copy doesn't affect the original. We're good here.
    }
    std::cout << "]" << std::endl;
}

template <typename T, typename Container = std::deque<T>>
void clear_stack(std::stack<T,Container>& stack){
//template <typename T>
//void clear_stack(std::stack<T>& stack){

    std::cout << "Clearing stack of size : " << stack.size() << std::endl;
    while(!stack.empty()){
        stack.pop();
    }
}


int main(){
    //Code1 : Creating std::stacks and storing data in
    std::stack<int> numbers1;
    
    std::cout << " numbers1 : ";
    print_stack(numbers1); // empty
    
    numbers1.push(10);
    numbers1.push(20);
    numbers1.push(30);
    
    std::cout << "numbers1 : ";
    print_stack(numbers1); // 30 20 10 : FILO

    numbers1.push(40);
    numbers1.push(50);
    
    std::cout << "numbers1 : ";
    print_stack(numbers1); // 50 40 30 20 10  : FILO

    std::cout << "-----" << std::endl;

    //Accessing elements
    std::cout << "top : " << numbers1.top() << std::endl;
    //Pop off the top
    print_stack(numbers1);
    numbers1.pop();
    print_stack(numbers1);
    std::cout << "top : " << numbers1.top() << std::endl;
    
    //We can organize these calls to top and pop into a function 
    // that can nicely show the contents of a stack. That's what print_stack does

    std::cout << "-----" << std::endl;

    //Code2 : Modifying the top element through the reference returned by top()
    //top() returns a reference. We can use that to modify the underlying 
    //element in the stack
    std::cout << "numbers1 : ";
    print_stack(numbers1); 
    
    numbers1.top() = 55;
    
    std::cout << "numbers1 : ";
    print_stack(numbers1); 


    //Code3 : Clearing a stack
    std::cout << std::endl;
    std::cout << "clearing a stack : " << std::endl;
    
    std::cout << "stack initial size : " << numbers1.size() << std::endl;
    std::cout << "numbers1 (before) : ";
    print_stack(numbers1);
    
    clear_stack(numbers1);
    
    std::cout << "stack final size : " << numbers1.size() << std::endl;
    std::cout << "numbers1(after) : ";
    print_stack(numbers1);


    //Code4 : Stack of user defined types
    std::stack<Book> books;
    books.push(Book(1921,"The Art of War"));
    books.push(Book(2000,"Social Media Marketing"));
    books.push(Book(2020,"How the Pandemic Changed the World"));
    
    std::cout << "books : ";
    print_stack(books);
    std::cout << "books size : " << books.size() << std::endl;


    //Custom underlying sequence container
    
    std::stack<int,std::vector<int>> numbers2;
    std::stack<int,std::list<int>> numbers3;
    std::stack<int,std::deque<int>> numbers4;
    
    numbers2.push(5); // underlying container : std::vector
    numbers2.push(6);
    
    numbers3.push(7);   // underlying container : std::list
    numbers3.push(8);
    
    numbers4.push(9);   //  underlying container : std::deque
    numbers4.push(10);


    std::cout << " numbers4 : ";
    print_stack(numbers4); // OK 

    std::cout << " numbers3 : ";
    print_stack(numbers3); // Compiler error

    std::cout << " numbers2 : ";
    print_stack(numbers2); // Compiler error

    return 0;
}
```

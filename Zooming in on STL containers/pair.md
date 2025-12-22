

# `std::pair` in C++

## Header

`<utility>`

## Introduced In

* **C++98**
* Enhanced usability with **C++17** (Structured Bindings, CTAD)

---

## What is `std::pair`?

`std::pair` is a **standard library utility type** used to group **two related values** into a single object.
It is commonly used to represent **key–value pairs**.

---

## Syntax

```cpp
std::pair<T1, T2> p;
```

* `T1` → type of the first element (key)
* `T2` → type of the second element (value)

---

## Data Members

`std::pair` exposes **two public data members**:

```cpp
p.first   // first element (key)
p.second  // second element (value)
```

⚠️ These are **data members**, **not functions** (no parentheses).

---

## Creating a `std::pair`

### 1. Direct Initialization

```cpp
std::pair<int, std::string> p{1, "Alice"};
```

### 2. Using `std::make_pair`

```cpp
auto p = std::make_pair(2, "Bob");
```

* Types are **automatically deduced**
* Older but still commonly seen

### 3. Class Template Argument Deduction (CTAD)

```cpp
std::pair p{3, std::string("Charlie")};
```

✅ Compiler deduces template arguments
📌 Available since **C++17**

---

## Accessing Elements

```cpp
std::cout << p.first << " " << p.second;
```

❌ This will NOT work:

```cpp
std::cout << p; // No operator<< overload
```

---

## Structured Bindings (C++17)

Allows unpacking a pair into named variables.

```cpp
auto [key, value] = p;
```

* `key` receives `first`
* `value` receives `second`
* Improves readability
* Very common in modern C++

---

## `std::pair` in Containers

### Example: Vector of Pairs

```cpp
std::vector<std::pair<int, std::string>> students{
    {1, "Alice"},
    {2, "Bob"},
    {3, "Charlie"}
};
```

---

## Iterating Over a Container of Pairs

### 1. Using `first` and `second`

```cpp
for (const auto& p : students) {
    std::cout << p.first << " " << p.second << '\n';
}
```

### 2. Using Structured Bindings (Recommended)

```cpp
for (const auto& [id, name] : students) {
    std::cout << id << " " << name << '\n';
}
```

✅ Cleaner
✅ Less error-prone
✅ Modern C++ style

---

## Common Use Cases

* Associative containers (`std::map`, `std::unordered_map`)
* Returning two values from a function
* Temporary grouping of related data
* Algorithm results (e.g., value + index)

---

## Pros

* Lightweight and efficient
* Simple key–value abstraction
* Works seamlessly with STL containers
* Supported across all C++ standards

---

## Cons

* Limited to **exactly two elements**
* No semantic meaning for `first` and `second`
* Poor readability without structured bindings

---

## Best Practices

* Prefer **structured bindings** in C++17+
* Use meaningful variable names when unpacking
* Avoid deeply nested pairs (use `struct` instead)
* Use `std::pair` only when two values logically belong together

---

## Summary

* `std::pair` groups two values into one object
* Access via `.first` and `.second`
* Cannot be printed directly
* Widely used in STL containers
* Structured bindings make it far more readable in modern C++

---
```cpp
#include <iostream>
#include <vector>
#include <utility>


int main(){

    //Code1 : Create pair
    std::cout << "creating pairs:" << std::endl;
    std::pair<int,std::string> pair1{0,"Book shelf"};
    
    auto pair2 = std::make_pair(1,"Table"); // Deduces the template arguments

    //std::cout << "pair1 : " << pair1 << std::endl;

    std::cout << " pair1 : (" << pair1.first << "," << pair1.second << ")" << std::endl;
    std::cout << " pair2 : (" << pair2.first << "," << pair2.second << ")" << std::endl;

    //Code2 : auto[] syntax - collect components of a pair into variables.
    std::cout << std::endl;
    std::cout << "auto[] syntax - collect components of a pair into variables : " << std::endl;
    auto [int_var, string_var] = pair1;
    std::cout << "pair1 (auto[] syntax) : (" << int_var << "," << string_var << ")" << std::endl;
    
    

    //Code3 : template argument deduction (C++17)
    std::cout << std::endl;
    std::cout << "template argument deduction : " << std::endl;
    
    std::pair student(33165, std::string("John Snow"));// Deducing the template arguments
    
    std::cout << "student ID : " << student.first << std::endl;
    std::cout << "Student name : " << student.second << std::endl;


    //Code4 : collection of pairs
    std::cout << std::endl;
    std::cout << "collection of pairs : " << std::endl;
    
    std::vector<std::pair<int,std::string>> collection {{10,"Earth"},{20,"Spins"},
                                                        {30,"From"},{40,"Left"},
                                                        {50,"To"},{60,"Right"}};
    //Traverse : syntax1
    std::cout << std::endl;
    std::cout << "syntax1 : " << std::endl;
    std::cout << "collection : [";
    for(const auto& elt : collection){
        std::cout << " (" << elt.first << "," << elt.second << ")";
    }
    std::cout << "]" << std::endl;


    //Traverse : syntax2
    std::cout << std::endl;
    std::cout << "syntax2 : " << std::endl;
    std::cout << "collection : [";
    for( auto[key,value] : collection){
        std::cout << " (" << key << "," << value << ")";
    }
    std::cout << "]" << std::endl;
   
    return 0;
}

```

```cpp
#include <iostream>
#include <vector>

template <typename T>
void print_vec( const std::vector<T>& vec){
    for(size_t i{}; i < vec.size();++i){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;    
}

template <typename T>
void print_raw_array(const T* p, std::size_t size)
{
    std::cout << "data = ";
    for (std::size_t i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
}


int main(){

    //Constructing vectors
    std::vector<std::string> vec_str {"The","sky","is","blue","my","friend"};
    std::cout << "vec1[1]  : " << vec_str[1] << std::endl;
    print_vec(vec_str);

    std::cout << "------" << std::endl;

    std::vector<int> ints1;
    std::cout << "ints1 : ";
    print_vec(ints1); // Won't print anything, the vector has no content

    std::vector<int> ints2 = { 1,2,3,4 };
    std::vector<int> ints3{ 11,22,33,44 };
    
    std::cout << "ints2 : ";
    print_vec(ints2);

    std::cout << "ints3 : ";
    print_vec(ints3);


    std::vector<int> ints4(20, 55); // A vector with 20 items, all initialized to 55
    std::cout << "ints4 : ";
    print_vec(ints4);
    
    //Be careful about uniform initialization
    std::vector<int> ints5{20, 55}; // A vector with 2 items : 20 and 55
    std::cout << "ints5 : ";
    print_vec(ints5);


    //Accessing elements
    std::cout << std::endl;
    std::cout << "Accessing elements in a vector: " << std::endl;
    std::cout << "vec_str[2] : " << vec_str[2] << std::endl;
    std::cout << "vec_str.at(3) : " << vec_str.at(3) << std::endl;
    std::cout << "vec_str.front() : " << vec_str.front() << std::endl;
    std::cout << "vec_str.back() : " << vec_str.back() << std::endl;

    //Using the data method
    std::cout << "using raw array : " << std::endl;
    print_raw_array(vec_str.data(),vec_str.size());


    //Adding and removing stuff
    std::cout << std::endl;
    std::cout << "Adding and removing stuff : " << std::endl;
    
    std::cout << "ints1 : " ;
    print_vec(ints1);
    
    
    //Pushing back
    ints1.push_back(100);
    ints1.push_back(200);
    ints1.push_back(300);
    ints1.push_back(500);
    std::cout << "ints1 : " ;
    print_vec(ints1);
    
    //Poping back
    ints1.pop_back();
    std::cout << "ints1 : " ;
    print_vec(ints1);

   
    return 0;
}
```
---

# 📘 `std::vector` — Dynamic Contiguous Container (Personal Notes)

## What is `std::vector`?

`std::vector` is a **sequence container** used to store a collection of elements **contiguously in memory**.

* Internally wraps a **dynamic array**
* Size can grow or shrink at runtime
* Provides **fast random access**
* Excellent choice when **memory locality** matters

---

## Header Requirement

```cpp
#include <vector>
```

---

## Key Characteristics

* Stores elements **next to each other in memory**
* Supports **dynamic resizing**
* Similar behavior to arrays, but much more powerful
* Template-based → works with **any data type**

Example:

```cpp
std::vector<int> numbers;
std::vector<std::string> words;
```

---

## Creating a `std::vector`

### 1️⃣ Brace Initialization (Recommended)

```cpp
std::vector<int> v{1, 2, 3, 4};
```

### 2️⃣ Assignment Initialization

```cpp
std::vector<int> v = {1, 2, 3, 4};
```

### 3️⃣ Empty Vector

```cpp
std::vector<int> v;
```

---

## ⚠️ Important Constructor Difference (Very Important)

### Parentheses `()`

```cpp
std::vector<int> v(20, 55);
```

✔ Creates **20 elements**, each initialized to **55**

### Braces `{}`

```cpp
std::vector<int> v{20, 55};
```

✔ Creates **2 elements** → `20` and `55`

📌 This distinction is a **common beginner pitfall**.

---

## Accessing Elements

### 1️⃣ Using Index Operator `[]`

```cpp
v[0];
v[1];
```

* Fast
* No bounds checking

### 2️⃣ Using `at()`

```cpp
v.at(2);
```

* Performs bounds checking
* Returns a **reference**
* Safer than `[]`

### 3️⃣ `front()` and `back()`

```cpp
v.front(); // first element
v.back();  // last element
```

* Return copies of elements

---

## Looping Through a Vector

### Using Indexing

```cpp
for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << " ";
}
```

### `size()` Method

* Returns number of elements currently stored
* Used for safe looping

---

## Adding and Removing Elements

### Adding Elements

```cpp
v.push_back(100);
```

* Adds element at the **end**
* May reallocate memory

### Removing Elements

```cpp
v.pop_back();
```

* Removes last element only

📌 `std::vector` is optimized for **back insertion/removal**

---

## Getting Raw Array Access

### `data()` Method

```cpp
int* ptr = v.data();
```

* Returns pointer to underlying dynamic array
* Useful when interacting with:

  * Legacy APIs
  * Functions expecting raw arrays

Example:

```cpp
print_array(v.data(), v.size());
```

---

## Printing a Vector Using Templates

```cpp
template<typename T>
void print_vector(const std::vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
}
```

* Works for **any type**
* Demonstrates `std::vector` as a **generic container**

---

## Summary of Common Methods

| Method        | Purpose              |
| ------------- | -------------------- |
| `size()`      | Number of elements   |
| `push_back()` | Add element at end   |
| `pop_back()`  | Remove last element  |
| `front()`     | First element        |
| `back()`      | Last element         |
| `at()`        | Safe indexed access  |
| `data()`      | Pointer to raw array |

---

## When to Use `std::vector`

✅ When:

* Fast access by index is required
* Data must be contiguous
* Size changes dynamically
* Cache efficiency matters

❌ Avoid when:

* Frequent insertions/removals in the middle are needed

---

## Final Takeaway

* `std::vector` is the **most commonly used STL container**
* Combines **array-like performance** with **dynamic resizing**
* Understanding constructors and access methods is critical

---

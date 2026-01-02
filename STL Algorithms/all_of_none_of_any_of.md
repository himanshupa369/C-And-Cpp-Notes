
---

# STL Predicate Algorithms

## `std::all_of`, `std::any_of`, `std::none_of`

---

## 1. Big Idea

Sometimes I need to check **a condition across an entire collection**, such as:

* Are **all** elements even?
* Is **any** element divisible by 7?
* Are **none** of the elements odd?

Instead of manually looping through containers, C++ provides **ready-made STL algorithms** that do this efficiently and uniformly using **iterators**.

These algorithms work with:

* `std::vector`
* `std::set`
* `std::array`
* raw arrays
  (as long as `begin()` and `end()` are available)

---

## 2. Required Header

```cpp
#include <algorithm>
```

This header provides:

* `std::all_of`
* `std::any_of`
* `std::none_of`

---

## 3. Common Function Signature

All three algorithms follow the same structure:

```cpp
algorithm_name(begin_iterator, end_iterator, predicate);
```

Where:

* **begin_iterator** → start of range
* **end_iterator** → one past the last element
* **predicate** → function, lambda, or functor returning `bool`

---

## 4. `std::all_of`

### Purpose

Checks whether **ALL elements** in a range satisfy a condition.

### Returns

* `true` → condition holds for every element
* `false` → even one failure breaks it

### Example: Check if all numbers are even

```cpp
std::all_of(begin, end, [](int x) {
    return x % 2 == 0;
});
```

### Key Observations

* One odd number → result becomes `false`
* Short-circuits on first failure
* Works identically for vector, set, array

---

## 5. Why Not Manual Loops?

Yes, I *can* write a loop, but:

* Different containers have different internals
* Algorithms provide a **unified**, **tested**, and **readable** solution
* STL algorithms are optimized and expressive

**Best practice:**
Always check `<algorithm>` before writing custom loops.

---

## 6. `std::any_of`

### Purpose

Checks whether **AT LEAST ONE element** satisfies a condition.

### Returns

* `true` → at least one match found
* `false` → no element satisfies condition

---

### Example Using a Functor (Divisibility Check)

```cpp
struct IsDivisible {
    int divisor;
    bool operator()(int x) const {
        return x % divisor == 0;
    }
};
```

Usage:

```cpp
std::any_of(begin, end, IsDivisible{7});
```

### Key Observations

* Stops at first successful match
* Useful for validation checks
* Predicate can be:

  * Lambda
  * Functor
  * Function pointer

---

## 7. `std::none_of`

### Purpose

Checks whether **NO elements** satisfy a condition.

### Returns

* `true` → none satisfy the predicate
* `false` → at least one element does

---

### Example: Check if none of the numbers are odd

```cpp
bool isOdd(int x) {
    return x % 2 != 0;
}

std::none_of(begin, end, isOdd);
```

### Interpretation

* `true` → all numbers are even
* `false` → at least one odd number exists

---

## 8. Container Independence (Very Important)

These algorithms:

* Do **not care** how the container is implemented
* Only require iterator support

This works **without changing algorithm code**:

```cpp
std::vector<int>
std::set<int>
std::array<int, N>
int raw_array[N]
```

This is the **core power of STL algorithms + iterators**.

---

## 9. Predicate Types Summary

You can pass predicates as:

| Type     | Example                           |
| -------- | --------------------------------- |
| Lambda   | `[](int x){ return x % 2 == 0; }` |
| Functor  | `IsDivisible{7}`                  |
| Function | `bool isOdd(int)`                 |

All are valid.

---

## 10. Iterator-Pair Limitation

These algorithms require:

```cpp
(begin, end)
```

Even when operating on the **entire container**.

This can feel verbose, but:

* This is intentional design
* Enables working on **subranges**

> This limitation is addressed later using **range-based algorithms (C++20)**.

---

## 11. When to Use Which?

| Algorithm | Use Case                      |
| --------- | ----------------------------- |
| `all_of`  | Validate entire dataset       |
| `any_of`  | Detect existence of condition |
| `none_of` | Ensure absence of condition   |

---

## 12. Interview Notes

* These are **short-circuiting algorithms**
* Prefer STL algorithms over manual loops
* Work with **any iterator-compatible container**
* Show understanding of **predicate design**

---

## 13. Personal Takeaway

Whenever I want to:

* Validate a rule across a collection
* Avoid manual iteration
* Write expressive, maintainable code

👉 **Check `<algorithm>` first**

These functions reduce bugs and improve clarity.

---
```cpp
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>


bool is_odd(int n){
   return n % 2 != 0; 
}


int main(){

    std::vector<int> collection{2,6,8,49,64,71};
    //std::set<int> collection{2,6,8,40,64,70};
    //int collection[] {2,6,8,40,64,70};

    //std::all_of , lambda function predicate
    if (std::all_of(std::begin(collection), std::end(collection), [](int i){ return i % 2 == 0; })) {
        std::cout << "(std::all_of) :  All numbers in collection are even" << std::endl;
    }else{
        std::cout << "(std::all_of) : Not all numbers in collection are even" << std::endl;
    }

    std::cout << "------" << std::endl;

    //std::any_of ,functor as predicate 
    class DivisibleBy
    {
        private : 
            const int d;
        public : 
            DivisibleBy(int n) : d(n) {}
            bool operator()(int n) const { return n % d == 0; }
    };
 
    if (std::any_of(std::begin(collection),std::end(collection), DivisibleBy(7))) {
        std::cout << "(std::any_of) : At least one number is divisible by 7" << std::endl;
    }else{
        std::cout << "(std::any_of) : None of the numbers is divisible by 7" << std::endl;
    }

    std::cout << "-------" << std::endl;

    //std::none_of , function pointer as predicate
    if (std::none_of(std::begin(collection), std::end(collection), is_odd)) {
        std::cout << "(std::none_of) :  None of the numbers is odd" << std::endl;
    }else{
        std::cout << "(std::none_of) : At least one number is odd" << std::endl;
    }

   
    return 0;
}

```

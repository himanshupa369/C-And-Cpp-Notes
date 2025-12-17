
---

# `std::weak_ptr` in C++ — Personal Notes

---

## 1. What is `std::weak_ptr`?

* `std::weak_ptr` is a **non-owning smart pointer**
* It **observes** an object managed by `std::shared_ptr`
* It **does NOT control lifetime**
* When a `weak_ptr` goes out of scope:

  * Memory is **NOT released**
  * Reference count is **NOT decremented**

---

## 2. Key Properties of `weak_ptr`

| Property                   | Behavior |
| -------------------------- | -------- |
| Ownership                  | ❌ No     |
| Affects ref count          | ❌ No     |
| Deletes memory             | ❌ No     |
| Can access object directly | ❌ No     |

---

## 3. Why `weak_ptr` Cannot Be Used Like Other Pointers

`std::weak_ptr` **does not provide**:

* `operator*`
* `operator->`
* `get()`

### Invalid Usage (Compile-time Error)

```cpp
std::weak_ptr<Dog> wdog;
wdog->name;   // ❌ Error
(*wdog).name; // ❌ Error
```

Reason:

> `weak_ptr` is **not meant to manipulate data directly**

---

## 4. Creating a `weak_ptr`

A `weak_ptr` is always created **from a `shared_ptr`**

```cpp
std::shared_ptr<Dog> dog = std::make_shared<Dog>("Dog1");
std::weak_ptr<Dog> weakDog = dog;
```

* Both point to the **same object**
* Only `shared_ptr` owns it

---

## 5. Accessing Data via `weak_ptr` → `lock()`

To use a `weak_ptr`, you **must convert it back** to `shared_ptr`

```cpp
if (auto sp = weakDog.lock()) {
    std::cout << sp->name << std::endl;
}
```

### What `lock()` Does

* Returns `std::shared_ptr<T>`
* If object is already destroyed → returns `nullptr`
* Temporarily increases reference count

---

## 6. Reference Count Behavior

```cpp
std::shared_ptr<Dog> dog = std::make_shared<Dog>("Dog1");
std::weak_ptr<Dog> wdog = dog;

auto sp = wdog.lock();
```

| Pointer | Ref Count      |
| ------- | -------------- |
| `dog`   | 1              |
| `wdog`  | 0 (weak)       |
| `sp`    | +1 (temporary) |

---

## 7. Why `weak_ptr` Exists (Main Purpose)

### Problem: **Cyclic Dependency**

Occurs when objects **own each other** using `shared_ptr`

---

## 8. Cyclic Dependency Example (Problem Case)

```cpp
class Person {
public:
    std::string name;
    std::shared_ptr<Person> friendPtr;
};
```

```cpp
auto a = std::make_shared<Person>("Alison");
auto b = std::make_shared<Person>("Beth");

a->friendPtr = b;
b->friendPtr = a;
```

### What Goes Wrong?

* `Alison` owns `Beth`
* `Beth` owns `Alison`
* Reference count never becomes `0`
* Destructors are **never called**
* **Memory leak**

---

## 9. Why Memory Is Leaked

* Local `shared_ptr` variables go out of scope
* But objects still point to each other
* Heap objects remain alive forever

---

## 10. Solution: Replace One `shared_ptr` with `weak_ptr`

### Correct Design

```cpp
class Person {
public:
    std::string name;
    std::weak_ptr<Person> friendPtr; // 🔑 fix
};
```

### Why This Works

* `weak_ptr` does NOT increase reference count
* Ownership cycle is broken
* Objects are destroyed correctly
* Destructors are called

---

## 11. Accessing `friendPtr` After Fix

```cpp
if (auto friendShared = friendPtr.lock()) {
    std::cout << friendShared->name << std::endl;
}
```

---

## 12. Destructor Behavior (After Fix)

* Reference count reaches `0`
* Objects are deleted
* No memory leak
* Clean program termination

---

## 13. When Should You Use `weak_ptr`?

Use `weak_ptr` **only when**:

* There is **shared ownership**
* And a **possible ownership cycle**

### Common Scenarios

* Bidirectional relationships
* Parent ↔ Child
* Friends / Neighbors
* Observer pattern
* Graphs with back-references

---

## 14. When You Do NOT Need `weak_ptr`

* No cyclic dependency
* One clear owner
* `unique_ptr` is sufficient
* Raw pointers are lifetime-safe

---

## 15. Smart Pointer Usage Philosophy

* Prefer `unique_ptr`
* Use `shared_ptr` only when ownership is shared
* Use `weak_ptr` **only to break cycles**
* Smart pointers are tools — not rules

---

## 16. Summary Table

| Pointer      | Owns | Ref Count | Deletes |
| ------------ | ---- | --------- | ------- |
| `unique_ptr` | Yes  | No        | Yes     |
| `shared_ptr` | Yes  | Yes       | Yes     |
| `weak_ptr`   | No   | No        | No      |

---

## 17. One-Line Takeaway

> `std::weak_ptr` exists to safely observe shared objects and break cyclic dependencies without affecting ownership.

---


```cpp

#include <iostream>
#include <memory>
#include "dog.h"
#include "person.h"

int main(){

	//Playing with basic use of weak_ptr
    /*
    std::shared_ptr<Dog> shared_ptr_dog_1 = std::make_shared<Dog>("Dog1");
    std::shared_ptr<int> shared_ptr_int_1 = std::make_shared<int>(200);
    
    std::weak_ptr<Dog>  weak_ptr_dog_1 (shared_ptr_dog_1);
    std::weak_ptr<int>  weak_ptr_int_1 (shared_ptr_int_1);
    */

    // No * , or -> operators you would expect from regular pointers
    //std::cout << "weak_ptr_dog_1 use count : " << weak_ptr_dog_1.use_count() << std::endl;
    /*
    std::cout << "Dog name : " << weak_ptr_dog_1->get_name() << std::endl; // Compiler error : No -> operator
    std::cout << "Pointed to value : " << *weak_ptr_int_1 << std::endl; // Compiler error : No * operator
    std::cout << "Pointed to address : " << weak_ptr_dog_1.get() << std::endl; // No get method
    */


	// To use a weak ptr you have to turn it into a shared_ptr with the lock method
    /*
	std::cout << std::endl;
    std::shared_ptr<Dog> weak_turned_shared = weak_ptr_dog_1.lock();
    std::cout << "weak_turned_shared use count : " << weak_turned_shared.use_count() << std::endl;
    std::cout << "Dog name : " << weak_turned_shared->get_name() << std::endl;
	std::cout << "Dog name : " << shared_ptr_dog_1->get_name() << std::endl;
    */


    //Cycling dependency problem
	//Circular dependencies
	std::shared_ptr<Person> person_a = std::make_shared<Person>("Alison");
    std::shared_ptr<Person> person_b = std::make_shared<Person>("Beth");
    
    person_a->set_friend(person_b);
    person_b->set_friend(person_a);
	
    
    return 0;
}

```

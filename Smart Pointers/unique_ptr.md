
---

# `std::unique_ptr` in C++

## Topic

**Unique Pointers (Smart Pointers)**

---

## Why `std::unique_ptr` Exists

Managing heap memory manually using `new` and `delete` is:

* Error-prone
* Easy to forget `delete`
* Causes memory leaks
* Hard to track ownership across files

`std::unique_ptr` solves this by:

1. **Ensuring single ownership** of heap memory
2. **Automatically releasing memory** when it goes out of scope (RAII)

---

## Header Required

```cpp
#include <memory>
```

---

## Memory Management Approaches (Quick Recap)

### 1. Stack Allocation

```cpp
Dog d("Tommy");
```

* Automatic lifetime
* Destructor called when scope ends
* No manual memory management

### 2. Raw Pointer (Heap Allocation)

```cpp
Dog* d = new Dog("Tommy");
delete d;
```

Problems:

* Must remember `delete`
* Easy to leak memory
* Destructor not called if `delete` is forgotten

---

## What is `std::unique_ptr`?

* A **smart pointer** that owns a dynamically allocated object
* Only **one unique_ptr** can own a resource at a time
* Ownership **cannot be copied**
* Ownership **can be moved**
* Automatically deletes memory when destroyed

---

## Basic Syntax

```cpp
std::unique_ptr<Type> ptr;
```

---

## Managing Existing Heap Memory

```cpp
Dog* rawDog = new Dog("Buddy");

std::unique_ptr<Dog> upDog(rawDog);
rawDog = nullptr; // best practice
```

⚠ After assigning to `unique_ptr`, **do not use the raw pointer**

---

## Creating `unique_ptr` Using `new`

```cpp
std::unique_ptr<Dog> upDog{ new Dog("Max") };
```

Works, but **not recommended** in modern C++

---

## Recommended Way: `std::make_unique`

```cpp
auto upDog = std::make_unique<Dog>("Rocky");
```

Advantages:

* Cleaner syntax
* Exception safe
* Avoids direct use of `new`

---

## `unique_ptr` with Fundamental Types

```cpp
auto upInt = std::make_unique<int>(42);
*upInt = 100;
```

---

## Accessing Managed Object

### Arrow Operator

```cpp
upDog->printInfo();
```

### Dereference Operator

```cpp
(*upDog).printInfo();
```

### Get Raw Pointer (No Ownership Transfer)

```cpp
Dog* raw = upDog.get();
```

⚠ Never delete the pointer returned by `get()`

---

## Automatic Destruction (RAII)

When a `unique_ptr`:

* Goes out of scope
* Is reset
* Is overwritten

➡ Destructor of the managed object is called automatically

---

## Scope-Based Destruction Example

```cpp
{
    auto upDog = std::make_unique<Dog>("Oscar");
}
// Destructor called here
```

---

## Copying is NOT Allowed

```cpp
auto p1 = std::make_unique<Dog>("A");
auto p2 = p1;        // ❌ ERROR
auto p3(p1);        // ❌ ERROR
```

Reason:

* Unique ownership must be preserved
* Copy constructor is deleted

---

## Moving Ownership (`std::move`)

```cpp
auto p1 = std::make_unique<Dog>("Charlie");
auto p2 = std::move(p1);
```

After move:

* `p2` owns the memory
* `p1` becomes `nullptr`

---

## Checking After Move

```cpp
if(!p1){
    std::cout << "p1 is null\n";
}
```

---

## Resetting a `unique_ptr`

```cpp
auto upDog = std::make_unique<Dog>("Leo");
upDog.reset();
```

Effects:

* Destructor called immediately
* Pointer becomes `nullptr`

---

## Assigning New Memory After Reset

```cpp
upDog = std::make_unique<Dog>("Milo");
```

---

## Summary of Important Member Functions

| Function      | Purpose                        |
| ------------- | ------------------------------ |
| `get()`       | Returns raw pointer            |
| `reset()`     | Deletes managed object         |
| `release()`   | Releases ownership (no delete) |
| `operator->`  | Access members                 |
| `operator*`   | Dereference                    |
| `std::move()` | Transfer ownership             |

---

## C++ Version Support

| Feature            | Version |
| ------------------ | ------- |
| `std::unique_ptr`  | C++11   |
| `std::make_unique` | C++14   |

---

## Best Practices

* Prefer `std::make_unique` over `new`
* Never copy a `unique_ptr`
* Use `std::move` for ownership transfer
* Avoid raw pointers unless interfacing with legacy APIs
* Let RAII manage lifetime

---

## One-Line Summary

> `std::unique_ptr` enforces single ownership of heap memory and automatically releases resources when it goes out of scope, making C++ memory management safer and cleaner.

---

```cpp
//before use below code u need  to implement dog.cpp and dog.h.

#include <iostream>
#include <memory>
#include "dog.h"

int main(){


    //Stack variables
    /*
    {
        Dog dog1("Dog1");
        // Calling functions on stack objects
        dog1.print_dog();

    }
    std::cout << "Hitting outside scope" << std::endl;
    std::cout << "Done!" << std::endl;
    */


   //----------------------------------------------------------------------------------
    //Using raw pointers : Remember to manually release memory, 
    //						if you don't relase , you leak memory
    /*
        Dog* p_dog2 = new Dog("Dog2");
        int * p_int1 = new int(100);
        
        p_dog2->print_dog();
        std::cout << "Integer is : " << *p_int1 << std::endl;
        std::cout << "Integer lives at address : " << p_int1 << std::endl;
        
        //If you go out of scope withoug releasing (deleting) p_dog2 and
        // p_int1 you'll have leaked memory
        delete p_dog2; // Calls the destructor
        delete p_int1;
        */


    //----------------------------------------------------------------------------------
    //Using unique_ptr : managed memory is owned by a single pointer at any moment.
    /*
    {
        Dog * p_dog_3 = new Dog("Dog3");
        std::unique_ptr<Dog> up_dog_4{p_dog_3}; // Can also manage a previously allocated 
                                                // space managed by a raw pointer. You shouldn't
                                                // try to use the raw pointer from this point on
        std::unique_ptr<Dog> up_dog_5 {new Dog("Dog5")};
        std::unique_ptr<int> up_int2{new int(200)};
        std::unique_ptr<Dog> up_dog_6{nullptr};// Can also initialize with nullptr
                        // and give it memory to manage later, we'll see how to 
                        // do that with std::move later in the lecture. Just know
                        // that you can initialize a unique ptr with nullptr for now.
        
        //Can use unique pointer just like we use a raw pointer.
        up_dog_5->print_dog(); // Calling function with -> operator
        //Assign to fundamental type
        * up_int2 = 500;
        std::cout << "Integer is : " << *up_int2 << std::endl; // dereferencing
        std::cout << "Integer lives at address : " << up_int2.get() << std::endl;

    }
    std::cout << "Hitting the outside scope" << std::endl; 
    */


//----------------------------------------------------------------------------------
    /*
    //using make_unique syntax. Much cleaner (C++14 ) 
	//Calls new internally for us, we don't have to do it ourselves
    std::unique_ptr<Dog> up_dog_7 = std::make_unique<Dog>("Dog7");
    up_dog_7->print_dog();
     
    std::unique_ptr<int> p_int3 = std::make_unique<int>(30);
    *p_int3 =67;
    std::cout << "Value pointed to by p_int3 is :"  << *p_int3 << std::endl;
    std::cout << "p_int pointing at address :" << p_int3.get() << std::endl;
    */

//----------------------------------------------------------------------------------
    /*
    //Copies not allowed
    std::unique_ptr<Dog> up_dog_8 = std::make_unique<Dog>("Dog8");
    up_dog_8->print_dog();
    //Can get the wrapped pointer address : useful for older raw pointer APIs
    std::cout << "Dog8 memory address: " << up_dog_8.get() << std::endl;

    // Copies and Assignments are not allowed with unique ptr
    //std::unique_ptr<Dog> up_dog_9 = up_dog_8; // Error.This also does some kind of copy
                        // More on this when we've learnt about operator overloading
    //std::unique_ptr<Dog> up_dog_10{up_dog_8}; // Error :  Copy constructor deleted
    */

//----------------------------------------------------------------------------------

    //Can however move the pointer. 
    /*
    std::unique_ptr<Dog> up_dog_11 = std::make_unique<Dog>("Dog11");
    {
        std::unique_ptr<Dog> up_dog_12 = std::move(up_dog_11); // Now up_dog_12 manages Dog11
                                                    // and up_dog_11 points to nothing(nullptr)
        up_dog_12->print_dog();
        std::cout << "Dog12 memory address : " << up_dog_12.get() << std::endl;
    
        std::cout << "up_dog_11 is now nullptr : " << up_dog_11.get() << std::endl;	
        if(up_dog_11){
            std::cout << "Pointer11 pointing to something valid" << std::endl;
        }else{
            std::cout << "Pointer11 point to nullpter" << std::endl;
        }	
    
    }
    std::cout << "Hitting the outside scope" << std::endl;
    */

//----------------------------------------------------------------------------------
    //Can reset unique_ptr : releases memory and sets the pointer to nullptr
    //If you comment out the reset line, the destructor is called after the doing
    //something print out, if it's not commented out, we reset the pointer and the
    //destructor is called before the line : std::cout << "Doing something" << std::endl; SHOW THIS.
    
	
    std::unique_ptr<Dog> up_dog_13 = std::make_unique<Dog>("Dog13");
    up_dog_13.reset(); // releases memory and sets pointer to nullptr
    
    //Can use unique pointer in if statement to see if it points somewhere valid
    if(up_dog_13){
        std::cout << "up_dog_13 points somewhere valid : " << up_dog_13.get() << std::endl;
    }else{
        std::cout << "up_dog_13 points is null : " << up_dog_13.get() << std::endl;
    }

 

    
 
   
    return 0;
}
```

---

# Common Built-in Functions of `std::unique_ptr`

## Topic

**Operations and Utilities Provided by `std::unique_ptr`**

---

## `get()`

### Purpose

* Returns the **raw pointer** managed by the `unique_ptr`
* **Does NOT transfer ownership**
* `unique_ptr` remains responsible for deletion

### Syntax

```cpp
T* get() const noexcept;
```

### Example

```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(42);
int* raw = ptr.get();   // raw does not own memory
```

### Notes

* Use mainly for **interfacing with legacy APIs**
* Never call `delete` on the returned pointer
* Lifetime depends entirely on the `unique_ptr`

---

## `release()`

### Purpose

* Releases ownership of the managed object
* Returns the raw pointer
* `unique_ptr` becomes `nullptr`

### Syntax

```cpp
T* release() noexcept;
```

### Example

```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(10);
int* raw = ptr.release();   // ownership transferred
delete raw;                // manual deletion required
```

### Notes

* Dangerous if not handled carefully
* Must manually `delete` the returned pointer
* Prefer `reset()` or move semantics unless absolutely necessary

---

## `reset()`

### Purpose

* Deletes the currently owned object
* Optionally takes ownership of a new pointer

### Syntax

```cpp
void reset(T* ptr = nullptr) noexcept;
```

### Example

```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(5);

ptr.reset(new int(20));  // deletes 5, now owns 20
ptr.reset();             // deletes 20, ptr becomes null
```

### Notes

* Destructor of the owned object is called immediately
* Safe way to replace or clear ownership
* Prefer `std::make_unique` when assigning new memory

---

## `swap()`

### Purpose

* Exchanges ownership between two `unique_ptr` objects

### Syntax

```cpp
void swap(unique_ptr& other) noexcept;
```

### Example

```cpp
std::unique_ptr<int> a = std::make_unique<int>(100);
std::unique_ptr<int> b = std::make_unique<int>(200);

a.swap(b);   // a → 200, b → 100
```

### Notes

* No allocation or deletion occurs
* Constant-time operation
* Useful in exception-safe code and algorithms

---

## `operator*` and `operator->`

### Purpose

* Provides access to the managed object

### Example

```cpp
std::unique_ptr<std::string> str =
    std::make_unique<std::string>("Hello");

std::cout << *str << "\n";        // Dereference
std::cout << str->length() << "\n"; // Member access
```

### Notes

* Behaves like a raw pointer
* Undefined behavior if pointer is null
* Always ensure the pointer owns an object before access

---

## `operator bool()`

### Purpose

* Checks whether the `unique_ptr` owns an object

### Example

```cpp
std::unique_ptr<int> ptr;

if (!ptr) {
    std::cout << "Pointer is null\n";
}
```

### Notes

* Enables safe condition checks
* Preferred over `get() == nullptr`
* Improves readability and intent

---

## Quick Comparison Summary

| Function          | Ownership Change | Deletes Object | Typical Use Case           |
| ----------------- | ---------------- | -------------- | -------------------------- |
| `get()`           | ❌ No             | ❌ No           | Legacy API access          |
| `release()`       | ✅ Yes            | ❌ No           | Manual lifetime control    |
| `reset()`         | ❌ / ✅            | ✅ Yes          | Replace or clear ownership |
| `swap()`          | ✅ Yes            | ❌ No           | Ownership exchange         |
| `*` / `->`        | ❌ No             | ❌ No           | Object access              |
| `operator bool()` | ❌ No             | ❌ No           | Null check                 |

---

## Key Takeaway

> `std::unique_ptr` provides precise, explicit control over ownership while preventing accidental memory leaks through enforced single ownership and RAII-based destruction.

---


---

# Shared Pointers in C++ (`std::shared_ptr`)

---

## 1. What problem shared pointers solve

* Allow **multiple smart pointers** to own the **same memory**
* Memory is released **only when the last owner goes away**
* Ownership is tracked using a **reference count (use count)**

---

## 2. Core concept: Reference counting

* Each shared pointer pointing to the same object increments the count
* When a shared pointer:

  * Goes out of scope
  * Is reset
* → reference count decrements
* **Memory is destroyed only when reference count becomes zero**

Example flow:

```
1 pointer  → count = 1
2 pointers → count = 2
3 pointers → count = 3
...
Last pointer destroyed → count = 0 → memory released
```

---

## 3. Declaring a shared pointer

### Fundamental type

```cpp
#include <memory>

std::shared_ptr<int> ptr1(new int(20));
```

* Allocates memory on heap
* Reference count starts at **1**

---

## 4. Using a shared pointer

```cpp
*ptr1 = 40;                 // modify value
std::cout << *ptr1;         // access value
std::cout << ptr1.use_count(); // reference count
```

---

## 5. Copying shared pointers (allowed)

```cpp
std::shared_ptr<int> ptr2 = ptr1;
```

* Both `ptr1` and `ptr2` point to **same memory**
* Reference count increases

Key rule:

> Copying a shared pointer does NOT copy the data — it shares ownership

---

## 6. Modifying data through any shared pointer

```cpp
*ptr2 = 70;
```

* Change is visible through **all shared pointers**
* Because they all point to the same memory

---

## 7. Different ways to initialize shared pointers

```cpp
std::shared_ptr<int> p3;              // null
std::shared_ptr<int> p4(nullptr);     // explicitly null
std::shared_ptr<int> p5 = ptr1;       // copy
```

All copies:

* Increase reference count
* Share the same memory

---

## 8. `use_count()` behavior

```cpp
ptr1.use_count(); // same value from all shared pointers
```

* All shared pointers report the **same count**
* Count represents total owners of the memory

---

## 9. Resetting a shared pointer

```cpp
ptr5.reset();
```

Effects:

* `ptr5` becomes `nullptr`
* Its reference count becomes **0**
* Other shared pointers remain valid
* Global reference count decreases by 1

---

## 10. `get()` – accessing raw pointer

```cpp
int* raw = ptr1.get();
```

* Returns raw pointer
* **Does not affect ownership**
* Must not manually delete this pointer

---

## 11. Shared pointer and `bool` conversion

```cpp
if (ptr1) {
    // ptr1 is not null
}

if (!ptr5) {
    // ptr5 is null
}
```

* Internally checks if pointer is valid or null

---

## 12. Managing existing raw memory (important)

```cpp
int* raw = new int(33);
std::shared_ptr<int> ptr6(raw);
raw = nullptr; // VERY IMPORTANT
```

Key rules:

* Once shared pointer takes ownership:

  * Raw pointer should be **immediately nulled**
* Otherwise:

  * Risk of **double delete**

---

## 13. Shared pointers with custom objects

### Example with `Dog` class

```cpp
std::shared_ptr<Dog> dog1(new Dog("Bruno"));
```

* Constructor called once
* Destructor called **only when reference count reaches zero**

---

## 14. Copying shared pointers with objects

```cpp
std::shared_ptr<Dog> dog2 = dog1;
```

* Both point to the same `Dog`
* Reference count increments
* Destructor runs **after last pointer is destroyed**

---

## 15. Using `std::make_shared` (recommended)

```cpp
auto ptr = std::make_shared<int>(55);
auto dog = std::make_shared<Dog>("Rocky");
```

Advantages:

* No direct use of `new`
* Exception safe
* Single allocation for:

  * Control block
  * Object

---

## 16. Reset with `make_shared`

```cpp
ptr.reset();
```

* Pointer becomes null
* Reference count decreases
* If count reaches zero → memory freed

---

## 17. Shared pointer lifecycle summary

* Constructor → when first shared pointer is created
* Reference count increases → on copy
* Reference count decreases → on reset / scope exit
* Destructor → when count reaches zero

---

## 18. Key rules to remember (interview-ready)

* `shared_ptr` allows **shared ownership**
* Memory freed only when **last owner disappears**
* `use_count()` helps debugging, not logic
* Avoid mixing raw pointers and shared pointers
* Prefer `make_shared` over `new`

---

## 19. One-line mental model

> A shared pointer keeps an object alive as long as at least one owner exists.

---

```cpp
#include <iostream>
#include <memory>
#include "dog.h"



int main(){

    //shared pointers to fundamental types
    /*
    {

        std::shared_ptr<int> int_ptr_1 {new int{20}};
        
        std::cout << "The pointed to value is : " << *int_ptr_1 << std::endl;
        *int_ptr_1 = 40; // Use the pointer to assign
        std::cout << "The pointed to value is : " << *int_ptr_1 << std::endl;
        std::cout << "Use count : " << int_ptr_1.use_count() << std::endl; //1

        std::cout << "----" << std::endl;

        //Copying

        std::shared_ptr<int> int_ptr_2 = int_ptr_1; // Use count : 2
        
        std::cout << "The pointed to value is (through int_ptr2)  : " << *int_ptr_2 << std::endl;
        *int_ptr_2 = 70;
        std::cout << "The pointed to value is (through int_ptr2) : " << *int_ptr_2 << std::endl;
        
        std::cout << "Use count for int_ptr_1 : " << int_ptr_1.use_count() << std::endl;
        std::cout << "Use count for int_ptr_2 : " << int_ptr_2.use_count() << std::endl;


        //Other ways to initialize shared pointers
        std::cout << "-----" << std::endl;
        std::shared_ptr<int> int_ptr_3; // nullptr
        int_ptr_3 = int_ptr_1; // Use count : 3

        std::shared_ptr<int> int_ptr_4{nullptr};
        int_ptr_4 = int_ptr_1; // Use count : 4
        
        std::shared_ptr<int> int_ptr_5{int_ptr_1}; // Use count : 5
        
         std::cout << "The pointed to value is (through int_ptr5)  : " << *int_ptr_5 << std::endl;
        *int_ptr_5 = 100;
        std::cout << "The pointed to value is (through int_ptr5) : " << *int_ptr_5 << std::endl;
        
        std::cout << "Use count for int_ptr_1 : " << int_ptr_1.use_count() << std::endl;
        std::cout << "Use count for int_ptr_2 : " << int_ptr_2.use_count() << std::endl;
        std::cout << "Use count for int_ptr_3 : " << int_ptr_3.use_count() << std::endl;
        std::cout << "Use count for int_ptr_4 : " << int_ptr_4.use_count() << std::endl;
        std::cout << "Use count for int_ptr_5 : " << int_ptr_5.use_count() << std::endl;


        //Use a shared pointer to manage an already existing piece of memory
        std::cout << "-----" << std::endl;
        std::cout << "Use a shared pointer to manage an already existing piece of memory :" << std::endl;
        int * int_ptr_raw = new int(33);
        
        std::shared_ptr<int> int_ptr_6 {int_ptr_raw};
        int_ptr_raw = nullptr;
        std::cout << "The value pointed to by int_ptr_raw is (through int_ptr_6) : " << *int_ptr_6 << std::endl;
        std::cout << "Use count for int_ptr_6 is : " << int_ptr_6.use_count() << std::endl;
        std::cout << "raw pointer : " << int_ptr_raw << std::endl;
        std::cout << "int_ptr_6.get() : " << int_ptr_6.get() << std::endl;


        //Reset : decrements the use count and sets the pointer to nullptr
        std::cout << std::endl;
        std::cout << "Reset..." << std::endl;
        int_ptr_5.reset(); // decrements reference count and sets int_ptr5 to nullptr
                        // after this if you show use count, for int_ptr5,you'll get 0
        std::cout << "Use count for int_ptr_1 : " << int_ptr_1.use_count() << std::endl;
        std::cout << "Use count for int_ptr_2 : " << int_ptr_2.use_count() << std::endl;
        std::cout << "Use count for int_ptr_3 : " << int_ptr_3.use_count() << std::endl;
        std::cout << "Use count for int_ptr_4 : " << int_ptr_4.use_count() << std::endl;
        std::cout << "Use count for int_ptr_5 : " << int_ptr_5.use_count() << std::endl;
        std::cout << "int_ptr_5.get() : " << int_ptr_5.get() << std::endl;


         //Can get the raw pointer address and use the ptr in if statements (castable to bool)
		std::cout << std::endl;
		std::cout << "Casting to bool and using in if statements..." << std::endl;
        std::cout << "int_ptr_4 : " << int_ptr_4 << std::endl;
        std::cout << "int_ptr_4.get() : " << int_ptr_4.get() << std::endl;
		std::cout << std::boolalpha;
        std::cout << "int_ptr_4->bool : " << static_cast<bool>(int_ptr_4) << std::endl;
        std::cout << "int_ptr_5->bool : " << static_cast<bool>(int_ptr_5) << std::endl;
        
        if(int_ptr_4){
            std::cout << "int_ptr_4 pointing to something valid" << std::endl;
        }else{
            std::cout << "int_ptr_4 pointing to nullptr" << std::endl;
        }


        std::cout << "Resetting the pointers... " << std::endl;
        int_ptr_4.reset();
        int_ptr_3.reset();
        int_ptr_2.reset();
        int_ptr_1.reset();
        std::cout << "Use count for int_ptr_1 : " << int_ptr_1.use_count() << std::endl;
        std::cout << "Use count for int_ptr_2 : " << int_ptr_2.use_count() << std::endl;
        std::cout << "Use count for int_ptr_3 : " << int_ptr_3.use_count() << std::endl;
        std::cout << "Use count for int_ptr_4 : " << int_ptr_4.use_count() << std::endl;
        std::cout << "Use count for int_ptr_5 : " << int_ptr_5.use_count() << std::endl;
		
    }
    */


   //Shared pointers with custom types
   /*
   {
		std::shared_ptr<Dog> dog_ptr_1{ new Dog("Dog1")};
        dog_ptr_1->print_info();
        
        std::cout << "Use count : " << dog_ptr_1.use_count() << std::endl;
        
        std::shared_ptr<Dog> dog_ptr_2 = dog_ptr_1; // Use count : 2
        
        std::cout << "Use count for dog_ptr_1 : " << dog_ptr_1.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_2 : " << dog_ptr_2.use_count() << std::endl;

		//Initializing
        std::cout << std::endl;
		std::cout << "Initializing..." << std::endl;
        std::shared_ptr<Dog> dog_ptr_3;
        dog_ptr_3 = dog_ptr_1; // Use count : 3

        std::shared_ptr<Dog> dog_ptr_4{nullptr};
        dog_ptr_4 = dog_ptr_1; // Use count : 4
        
        std::shared_ptr<Dog> dog_ptr_5{dog_ptr_1}; // Use count : 5
          
        std::cout << std::endl;
        std::cout << "Use count for dog_ptr_1 : " << dog_ptr_1.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_2 : " << dog_ptr_2.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_3 : " << dog_ptr_3.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_4 : " << dog_ptr_4.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_5 : " << dog_ptr_5.use_count() << std::endl;
        



        //Can also initialize from an already existing raw pointer
        
        std::cout << std::endl;
		std::cout << "Initializing from already existing raw pointer" << std::endl;
        
        Dog * dog_ptr_raw = new Dog("Ralso");
        std::shared_ptr<Dog> dog_ptr_6 {dog_ptr_raw};
        dog_ptr_raw = nullptr;

        dog_ptr_6->print_info();
        std::cout << "Use count for dog_ptr_6 is : " << dog_ptr_6.use_count() << std::endl;
        std::cout << "dog_ptr_raw : " << dog_ptr_raw << std::endl;


       //Reset : decrements the use count and sets the pointer to nullptr
        std::cout << std::endl;
        std::cout << "Resetting" << std::endl;
        dog_ptr_5.reset(); // decrements reference count and sets int_ptr5 to nullptr
                        // after this if you show use count, for int_ptr5,you'll get 0
        std::cout << "Use count for dog_ptr_1 : " << dog_ptr_1.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_2 : " << dog_ptr_2.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_3 : " << dog_ptr_3.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_4 : " << dog_ptr_4.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_5 : " << dog_ptr_5.use_count() << std::endl;
		
		
        //Can get the raw pointer address and use the ptr in if statements
		std::cout << std::endl;
		std::cout << "Casting to bool and using in if statements..." << std::endl;
        std::cout << "dog_ptr_4 : " << dog_ptr_4 << std::endl;
        std::cout << "dog_ptr_4.get() : " << dog_ptr_4.get() << std::endl;
        std::cout << "dog_ptr_4->bool : " << static_cast<bool>(dog_ptr_4) << std::endl;
        std::cout << "dog_ptr_5->bool : " << static_cast<bool>(dog_ptr_5) << std::endl;
        
        if(dog_ptr_5){
            std::cout << "dog_ptr_5 pointing to something valid" << std::endl;
        }else{
            std::cout << "dog_ptr_5 pointing to nullptr" << std::endl;
        }
   }
   */


   //make_shared
   {
		std::shared_ptr<int> int_ptr_6 = std::make_shared<int>(55);
        std::cout << "The value pointed to by int_ptr_6 is : " << *int_ptr_6 << std::endl;
        
        std::shared_ptr<Dog> dog_ptr_6 = std::make_shared<Dog>("Salz");
        dog_ptr_6->print_info();
        
        std::cout << "int_ptr_6 use count : " << int_ptr_6.use_count() << std::endl;//1
        std::cout << "dog_ptr_6 use count : " << dog_ptr_6.use_count() << std::endl;//1


		//Share the object(data) with other shared_ptr's
        std::cout << std::endl;
        std::cout << "Share the object(data) with other shared_ptr's" << std::endl;
        std::shared_ptr<int> int_ptr_7 {nullptr};
        int_ptr_7 = int_ptr_6;
        
        std::shared_ptr<Dog> dog_ptr_7 {nullptr};
        dog_ptr_7 = dog_ptr_6;
        
        std::cout << "int_ptr6 use count : " << int_ptr_6.use_count() << std::endl;
        std::cout << "dog_ptr6 use count : " << dog_ptr_6.use_count() << std::endl;


        std::cout << std::endl;
        std::cout << "Reset ptr6's" << std::endl;
        int_ptr_6.reset(); // decrement reference count, and set int_ptr6 to nullptr
                            // if reference count is zero, release the managed memory
        dog_ptr_6.reset();
        std::cout << "int_ptr_6 use count : " << int_ptr_6.use_count() << std::endl;
        std::cout << "dog_ptr_6 use count : " << dog_ptr_6.use_count() << std::endl;
		std::cout << "int_ptr_7 use count : " << int_ptr_7.use_count() << std::endl;
        std::cout << "dog_ptr_7 use count : " << dog_ptr_7.use_count() << std::endl;
        

   }

    return 0;
}
```

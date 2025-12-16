
---

# `std::unique_ptr` as Function Parameters and Return Values

## Core Principle

`std::unique_ptr` enforces **exclusive ownership** of dynamically allocated memory.

* ❌ **Copying is not allowed**
* ✅ **Moving ownership is allowed**
* Memory is released automatically when the owning `unique_ptr` goes out of scope (RAII)

---

## 1. Passing `std::unique_ptr` to Functions by Value

### Function Signature

```cpp
void do_something_with_dog_v1(std::unique_ptr<Dog> d);
```

### Behavior

* Passing by value **requires a copy**
* Copy constructor of `std::unique_ptr` is **deleted**
* Results in a **compiler error**

### Invalid Code

```cpp
std::unique_ptr<Dog> p_dog = std::make_unique<Dog>("Dog1");
do_something_with_dog_v1(p_dog); // ❌ compiler error
```

### Compiler Reason

* `std::unique_ptr` explicitly deletes its copy constructor
* Error usually mentions *deleted function*

---

### Explicit Move (Allowed)

```cpp
do_something_with_dog_v1(std::move(p_dog));
```

### What Happens

* Ownership transfers to the function parameter
* `p_dog` becomes `nullptr`
* Managed object is destroyed **when the function exits**

### After the Call

```cpp
p_dog.get() == nullptr  // true
```

### Important Warning

> Passing `unique_ptr` by value **transfers ownership**.
> Use this only when the function is supposed to *consume* the object.

---

## 2. Passing `std::unique_ptr` to Member Functions by Value

### Example

```cpp
person1.adopt_dog(std::move(p_dog));
```

### Behavior

* Same rules as free functions
* Ownership moves into the member function
* Object is destroyed when the function ends
* Original pointer becomes `nullptr`

### Key Rule

> Member functions do not change ownership semantics.
> `unique_ptr` by value always implies ownership transfer.

---

## 3. Implicit Move with Temporary `std::unique_ptr`

### Example

```cpp
do_something_with_dog_v1(std::make_unique<Dog>("Temporary Dog"));
```

### Why This Works

* The argument is a **temporary**
* Compiler performs an **implicit move**
* No copy is attempted

### Lifetime

* Temporary `unique_ptr` is destroyed at function exit
* Managed object is deleted automatically

### Use Case

* One-off object usage
* Clean, concise ownership transfer

---

## 4. Passing `std::unique_ptr` by Reference (Recommended for Read/Modify)

### Function Signature

```cpp
void do_something_with_dog_v2(const std::unique_ptr<Dog>& d);
```

### Why Use This

* No ownership transfer
* No copy
* Caller retains ownership

### Allowed Operations

```cpp
d->set_dog_name("Rior");
d->print_info();
```

### Not Allowed

```cpp
d.reset();  // ❌ compiler error
```

### Reason

* `const std::unique_ptr&` protects the pointer itself
* You cannot:

  * reset
  * release
  * swap
  * move

### Important Distinction

| Can Modify              | Can’t Modify        |
| ----------------------- | ------------------- |
| Object being pointed to | `unique_ptr` itself |

---

## 5. Returning `std::unique_ptr` from Functions

### Function

```cpp
std::unique_ptr<Dog> get_unique_ptr() {
    std::unique_ptr<Dog> p_dog = std::make_unique<Dog>("Function Local");
    return p_dog;
}
```

### Why This Works

* No copy occurs
* Compiler applies:

  * **Move semantics**
  * or **Return Value Optimization (RVO / NRVO)**

### Key Insight

> Returning a `std::unique_ptr` by value is **safe and idiomatic**

### Proof from Code

* Address inside function matches address outside
* Confirms no copy is made

---

## 6. Using Returned `std::unique_ptr` Immediately

### Example

```cpp
get_unique_ptr()->print_info();
```

### Behavior

1. `unique_ptr` is created inside the function
2. Returned as a temporary
3. Member function is called
4. Temporary `unique_ptr` is destroyed
5. Managed object is deleted immediately

### Output Order

* Constructor
* Print info
* Destructor
* `"function done"`

### Key Takeaway

> Temporary `unique_ptr`s are destroyed at the **end of the full expression**

---

## 7. Summary Table

| Scenario                         | Allowed          | Ownership Effect              |
| -------------------------------- | ---------------- | ----------------------------- |
| Pass by value                    | ❌ (without move) | N/A                           |
| Pass by value + `std::move`      | ✅                | Ownership transferred         |
| Pass temporary                   | ✅                | Ownership transferred         |
| Pass by `const&`                 | ✅                | No ownership change           |
| Modify pointed object            | ✅                | Safe                          |
| Modify `unique_ptr` via `const&` | ❌                | Compile-time error            |
| Return by value                  | ✅                | Ownership transferred         |
| Immediate use of return value    | ✅                | Temporary destroyed after use |

---

## Final Best Practices

* Use **pass-by-reference (`const std::unique_ptr<T>&`)** when:

  * You only need access, not ownership
* Use **pass-by-value + `std::move`** only when:

  * The function must take ownership
* Returning `std::unique_ptr` by value is:

  * Safe
  * Modern
  * Recommended
* Avoid unnecessary ownership transfers

---

```cpp
#include <iostream>
#include <memory>
#include "dog.h"
#include "person.h"


void do_something_with_dog_v1( std::unique_ptr<Dog> d){
    d->print_info() ;
}


void do_something_with_dog_v2( const std::unique_ptr<Dog>& d){
    d->set_dog_name("Rior");
    d->print_info();
   // d.reset(); // Compiler error
}


std::unique_ptr<Dog> get_unique_ptr(){
    std::unique_ptr<Dog> p_dog = std::make_unique<Dog>("Function Local");
	std::cout << "unique_ptr address(in) : " << &p_dog << std::endl;
    return p_dog;  // The compiler does some optimizations and doesn't return a copy here
					// it's returning something like a reference to the local object.
					// We can prove this by looking at the address of objects in memory.
					// This is not standard behavior, some compilers may actually return 
					// by value by making a copy. The compilers have some freedom to choose
					// their own way to do things.
}

int main(){

    /*
	//Passing unique ptr to functions by value
	std::unique_ptr<Dog> p_dog_1 = std::make_unique<Dog>("Dog1");
    
	//Can't pass unique_ptr by value to a function : copies not allowed
    //do_something_with_dog_v1(p_dog_1);   // copy detected,


	//do_something_with_dog_v1(std::move(p_dog_1)); // Ownership will move to the body
												// of the function and memory will be
												// released when function returns.
												// Not what you typically want.

    std::cout << "p_dog_1 : " << p_dog_1.get() << std::endl; 
    std::cout << "Hitting back the main function" << std::endl;

    */

    std::cout << "------" << std::endl;

    //std::unique_ptr<Dog> p_dog_1 = std::make_unique<Dog>("Dog1");

    /*
    Person person1("John");
    person1.adopt_dog(std::move(p_dog_1)); // The same behavior when function is part of the class
    std::cout << "Doing something , p_dog_1 points to :  " <<p_dog_1.get() <<  std::endl;
    */

	//An implicit move is done when object is created in place as a temporary
	//do_something_with_dog_v1(std::make_unique<Dog>("Temporary Dog"));

//---------------------------------------------------------------------------
    /*
	//Can pass the std::unique_ptr parameter by reference.
	std::unique_ptr p_dog_2 = std::make_unique<Dog>("Dog2");
	p_dog_2->print_info();
	do_something_with_dog_v2(p_dog_2);
	std::cout << "-----" << std::endl;
	p_dog_2->print_info();
    */


//---------------------------------------------------------------------------
	//Returning unique ptr from function by value
/*
	std::unique_ptr<Dog> p_dog_3 = get_unique_ptr();
	std::cout << "delimiter" << std::endl;
	std::cout << "unique_ptr address(out) : " << &p_dog_3 << std::endl;

	 p_dog_3->print_info();
*/

    get_unique_ptr()->print_info();

    std::cout << "function done" << std::endl;
    
	
	
	
	
	


   
    return 0;
}

```

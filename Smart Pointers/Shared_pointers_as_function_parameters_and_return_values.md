
---

# `std::shared_ptr` as Function Parameters and Return Values

---

## 1. Passing `std::shared_ptr` to Functions

### 1.1 Pass by Value

```cpp
void useDog(std::shared_ptr<Dog> dog);
```

#### Behavior

* A **copy** of the `shared_ptr` is created
* **Reference count increments** when entering the function
* Reference count **decrements** when function exits

#### Reference Count Flow

| Stage                  | `use_count()` |
| ---------------------- | ------------- |
| Before function call   | 1             |
| Inside function        | 2             |
| After function returns | 1             |

#### Key Points

* Safe and common
* Slight overhead due to reference counting
* Object lifetime is correctly managed

---

### 1.2 Pass by Non-Const Reference

```cpp
void useDog(std::shared_ptr<Dog>& dog);
```

#### Behavior

* **No copy** is made
* Reference count **does NOT change**
* The shared pointer itself **can be modified**

#### What You Can Do

* Call `reset()`
* Reassign to another object
* Modify ownership

```cpp
dog.reset(); // Valid
```

#### Key Points

* No reference count change
* Dangerous if ownership is altered unintentionally
* Use only when ownership modification is intended

---

### 1.3 Pass by Const Reference (Recommended)

```cpp
void useDog(const std::shared_ptr<Dog>& dog);
```

#### Behavior

* **No copy**
* Reference count **unchanged**
* Shared pointer **cannot be modified**

#### What You Can Do

```cpp
dog->setName("Buddy"); // Allowed
```

#### What You Cannot Do

```cpp
dog.reset(); // ❌ Compile-time error
```

#### Key Points

* Best performance
* Safe
* Most commonly recommended approach

---

## 2. Returning `std::shared_ptr` from Functions

---

### 2.1 Return by Value (Correct Way)

```cpp
std::shared_ptr<Dog> getDog() {
    return std::make_shared<Dog>("Max");
}
```

#### Behavior

* No extra copy due to **Return Value Optimization (RVO)**
* Final reference count is **1**
* Same as calling `make_shared` directly

#### Key Points

* Safe and efficient
* Preferred way to return shared ownership
* No reference count surprises

---

### 2.2 Return by Reference (❌ Never Do This)

```cpp
std::shared_ptr<Dog>& getDog(); // ❌
```

#### Why This Is Dangerous

* Returns reference to a **local variable**
* Local shared pointer is destroyed when function exits
* Reference count becomes **invalid (0)**
* Leads to **undefined behavior / crashes**

#### Compiler Warning

```
warning: returning reference to local variable
```

#### Runtime Result

* Program crash
* Premature destructor call
* Dangling reference

#### Rule

> **Never return `std::shared_ptr` by reference**

---

## 3. Summary Table

| Use Case                    | Recommended? | Reference Count    |
| --------------------------- | ------------ | ------------------ |
| Pass by value               | ✅ Yes        | Increments         |
| Pass by const reference     | ✅ Best       | No change          |
| Pass by non-const reference | ⚠️ Careful   | No change          |
| Return by value             | ✅ Yes        | Safe               |
| Return by reference         | ❌ Never      | Undefined behavior |

---

## 4. Best Practices

* ✅ Pass `shared_ptr` by **const reference** unless ownership is needed
* ✅ Return `shared_ptr` **by value**
* ❌ Never return `shared_ptr` by reference
* ❌ Avoid unnecessary copies
* ⚠️ Be careful when modifying ownership inside functions

---

## 5. Interview-Ready One-Liners

* “Passing `shared_ptr` by value increments the reference count.”
* “Passing by const reference avoids reference count overhead.”
* “Returning `shared_ptr` by value is safe due to RVO.”
* “Returning `shared_ptr` by reference causes undefined behavior.”
* “Never return a reference to a local smart pointer.”

---

## 6. One-Line Conclusion

> `std::shared_ptr` should be passed carefully and returned only by value to ensure correct reference counting and avoid undefined behavior.

---

```cpp

#include <iostream>
#include <memory>
#include "dog.h"

//Passing by value
void use_dog_v1( std::shared_ptr<Dog> dog){
    std::cout << "shared_ptr passed by value , dog_name : " << dog->get_name() << std::endl;
    std::cout << "use count in use_dog_v1 : " << dog.use_count() << std::endl; // 2
}



//Passing by non const reference
void use_dog_v2( std::shared_ptr<Dog> & dog){
    //Since no copy is made, we won't see the reference count increment here
    dog->set_dog_name("Riol");
	//dog.reset(new Dog()); // Passed by non const ref
    std::cout << "shared_ptr passed by non const reference (dog name changed in function) , dog_name : " << dog->get_name() << std::endl;
    std::cout << "use count in use_dog_v2 : " << dog.use_count() << std::endl;
}


void use_dog_v3( const std::shared_ptr<Dog> & dog){
     //Since no copy is made, we won't see the reference count increment here
    dog->set_dog_name("Simy"); // We can change the dog object even though
                            // shared_ptr is passed by ref. The const protects the shared_ptr
                            //  object itself, not the pointed to object.
    //dog.reset(new Dog()); // Passed by const ref
    std::cout << "shared_ptr passed by const reference (dog name changed in function) , dog_name : " << dog->get_name() << std::endl;
    std::cout << "use count in use_dog_v3 : " << dog.use_count() << std::endl;
}


//Returning by value
//     Returning a shared_ptr by value goes through return value optimization and at the
//                end no copy is made, we have a single shared ptr with a reference count of 1,
//                just like when we create a shared directly with make_shared.
std::shared_ptr<Dog> get_shared_ptr_v1(){
    std::shared_ptr<Dog> dog_ptr = std::make_shared<Dog>("Internal Dog_v1");
	std::cout << "Managed dog address(in) : " << dog_ptr.get() << std::endl;
    return dog_ptr;
}


//RETURNING SHARED_PTR BY REF( CONST OR NON CONST) IS A RECIPE
//FOR DISASTER. DON'T DO IT.
//returning std::shared_ptr by reference doesn't properly increment the reference count,
// which opens up the risk of deleting something at the wrong time. We'll get a crash
 std::shared_ptr<Dog>& get_shared_ptr_v2(){
    std::shared_ptr<Dog> dog_ptr = std::make_shared<Dog>("Internal Dog_v2");
    return dog_ptr;
}



int main(){

	//Passing by value : A copy will be made, increment the ref count in function body
    /*
	std::cout << std::endl;
	std::cout << "Passing shared_ptr by value : " << std::endl;
	
	std::shared_ptr<Dog> shared_ptr_dog_1 = std::make_shared<Dog>("Filld");
	std::cout << "shared_ptr_dog_1 use count(before) : "
								<< shared_ptr_dog_1.use_count() << std::endl; //1
	use_dog_v1(shared_ptr_dog_1);
	
	std::cout << "shared_ptr_dog_1 use count(after) : "
								<< shared_ptr_dog_1.use_count() << std::endl; //1
    */


	// Passing by non const reference
	//		No copy is made, reference count doesn't increment in function body
	/*
	std::cout << std::endl;
	std::cout << "Passing by non const reference : " << std::endl;
	std::shared_ptr<Dog> shared_ptr_dog_2 = std::make_shared<Dog>("Flizy");
	
	std::cout << "shared_ptr_dog_2 use count(before) : "
								<< shared_ptr_dog_2.use_count() << std::endl;
	use_dog_v2(shared_ptr_dog_2);
	
	std::cout << "shared_ptr_dog_2 use count(after) : "
								<< shared_ptr_dog_2.use_count() << std::endl;
    */

	//Passing by const reference
	//The const just protects the shared pointer object itself, it doesn't 
	//protect the pointed to value from changes.
    /*
	std::cout << std::endl;
	std::cout << "Passing by const reference : " << std::endl;
	
	std::shared_ptr<Dog> shared_ptr_dog_3 = std::make_shared<Dog>("Kitzo");
	
	std::cout << "shared_ptr_dog_3 use count(before) : "
								<< shared_ptr_dog_3.use_count() << std::endl;//1
	use_dog_v3(shared_ptr_dog_3);
	
	std::cout << "shared_ptr_dog_3 use count(after) : "
								<< shared_ptr_dog_3.use_count() << std::endl; //1

    */

	//Returning by value
	//     Returning a shared_ptr by value goes through return value optimization and at the
    //                end no copy is made, we have a single shared ptr with a reference count of 1, just
    //                like when we create a shared directly with make_shared.
	/*
	 std::shared_ptr<Dog> shared_ptr_dog_4 = get_shared_ptr_v1();
	 std::cout << "Managed dog address (out) : " << shared_ptr_dog_4.get() << std::endl;
	 std::cout << "shared_ptr_dog_4 use count : " << shared_ptr_dog_4.use_count() << std::endl;
     */

    //Returning by reference : not recommended.
	std::shared_ptr<Dog>& shared_ptr_dog_5 = get_shared_ptr_v2();
    std::cout << "ref count : " << shared_ptr_dog_5.use_count() << std::endl;






	
   
    return 0;
}

```

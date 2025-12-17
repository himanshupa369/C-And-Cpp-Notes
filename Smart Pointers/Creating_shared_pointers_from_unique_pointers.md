<img width="1792" height="629" alt="Screenshot 2025-12-17 113016" src="https://github.com/user-attachments/assets/e6a26bca-07b2-4eb3-8cbc-431dfee18f83" />

```cpp
#include <iostream>
#include <memory>
#include "dog.h"


std::unique_ptr<Dog> get_unique_ptr(){
     std::unique_ptr<Dog> dog_ptr_internal = std::make_unique<Dog>("Phil");
     return dog_ptr_internal;
}



int main(){

	//Create shared pointers from unique_ptrs
	std::unique_ptr<int> unique_ptr_int_1 = std::make_unique<int>(22);//Heap object
	std::unique_ptr<Dog> unique_ptr_dog_1 = std::make_unique<Dog>("Halz"); //Heap object
        
	//Create shared pointers from unique_ptrs
	//Ownership moves from unique_ptrs to shared_ptrs from now on
	std::shared_ptr<int> shared_ptr_int_1 = std::move(unique_ptr_int_1);
	std::shared_ptr<Dog> shared_ptr_dog_1 = std::move(unique_ptr_dog_1);
	//std::shared_ptr<Dog> shared_ptr_dog_2 = unique_ptr_dog_1; // Direct assignment
                                                        // Doesn't work, you have to do
														// an explicit std::move to move ownership
														
														
	std::cout << "shared_ptr_int_1 use count : " << shared_ptr_int_1.use_count() << std::endl;
	std::cout << "shared_ptr_dog_1 use count : " << shared_ptr_dog_1.use_count() << std::endl;
	std::cout << std::boolalpha;
	std::cout << "unique_ptr_int_1 : " << static_cast<bool> (unique_ptr_int_1) << std::endl;
	std::cout << "unique_ptr_dog_1 : " << static_cast<bool> (unique_ptr_dog_1) << std::endl;

    std::cout << "unique_ptr_int_1 : " << unique_ptr_int_1 << std::endl;
    std::cout << "unique_ptr_dog_1 : " << unique_ptr_dog_1 << std::endl;


	//Can create copies because now we hold a shared ptr
	std::cout << std::endl;
	std::cout << "Making copies..." << std::endl;
	std::shared_ptr<int> shared_ptr_int_3 {shared_ptr_int_1};
	std::shared_ptr<Dog> shared_ptr_dog_3 {shared_ptr_dog_1};
	
	std::cout << "shared_ptr_int_1 use count : " << shared_ptr_int_1.use_count() << std::endl;
	std::cout << "shared_ptr_dog_1 use count : " << shared_ptr_dog_1.use_count() << std::endl;
	std::cout << "shared_ptr_int_3 use count : " << shared_ptr_int_3.use_count() << std::endl;
	std::cout << "shared_ptr_dog_3 use count : " << shared_ptr_dog_3.use_count() << std::endl;



	//Can't transform from std::shared_ptr to std::unique_ptr
		//The reason this transformation is disabled isn't hard to think of.
        //          At any given moment, there may be any number of shared pointers 
        //          spread through your entire application working on the same object, 
        //          If you were to instantly make one of those a unique ptr, what do 
        //          you do with the remaining copies?? Unique ptr can't have copies 
        //          anyway. So the compiler prevents you from doing this.
	//std::unique_ptr<int> unique_ptr_illegal_1 {shared_ptr_int_3}; // Compiler error
	//std::unique_ptr<int> unique_ptr_illegal_2 =shared_ptr_int_3; // Compiler error
	//std::unique_ptr<int> unique_ptr_illegal_3 =std::move(shared_ptr_int_3); // Compiler error
	
	

	//Returning unique_ptr to unique_ptr
	std::cout << std::endl;
	std::cout << "Returning unique_ptr from function to unique ptr" << std::endl;
	std::unique_ptr<Dog> unique_ptr_dog_2 = get_unique_ptr(); // This implicitly moves
													// ownership to dog_ptr9_unique
	if(unique_ptr_dog_2)
		std::cout << "unique_ptr_dog_2 dog name : " << unique_ptr_dog_2->get_name() << std::endl;
		
	

	//Returning unique_ptr to shared_ptr
	std::cout << std::endl;
	std::cout << "Returning unique_ptr from function to shared ptr" << std::endl;
	std::shared_ptr<Dog> shared_ptr_dog_4= get_unique_ptr(); // This implicitly moves
						// ownership to shared_ptr_dog_4. Implicitly does something
						//like this : 
						// std::shared_ptr<Dog> shared_ptr_dog_4 = std::move(dog_ptr_internal);
						//moving ownership to a shared pointer whose reference count becomes 1.
	if(shared_ptr_dog_4){
		std::cout << "shared_ptr_dog_4 name 	 : " << shared_ptr_dog_4->get_name() << std::endl;
		std::cout << "shared_ptr_dog_4 use count : " << shared_ptr_dog_4.use_count() << std::endl;
 
	}
   
    return 0;
}

```

---

# Smart Pointer Transformations: `unique_ptr` ↔ `shared_ptr`

---

## 1. Problem Context

* `std::unique_ptr` enforces **exclusive ownership**
* Because of this, it **cannot be copied**
* Sometimes the program needs **multiple pointers** to the same heap object
* Solution: **transform `unique_ptr` into `shared_ptr`**

---

## 2. Transforming `unique_ptr` → `shared_ptr`

### Key Rule

Ownership must be **moved**, not copied.

### Correct Syntax

```cpp
std::shared_ptr<int> sp = std::move(up);
```

* Ownership transfers from `unique_ptr` → `shared_ptr`
* `unique_ptr` becomes `nullptr`
* `shared_ptr` starts with **use_count = 1**

---

## 3. Why `std::move` Is Mandatory

❌ This is NOT allowed:

```cpp
std::shared_ptr<int> sp = up;   // compiler error
```

Reason:

* Copying violates the **uniqueness guarantee**
* Compiler prevents accidental double ownership

✅ Correct:

```cpp
std::shared_ptr<int> sp = std::move(up);
```

---

## 4. State After the Move

* `unique_ptr` → reset to `nullptr`
* `shared_ptr` → sole owner
* Memory is now managed by the **shared control block**

Example check:

```cpp
std::cout << up.get(); // prints 0 (null)
```

---

## 5. Reference Count Behavior

Immediately after move:

```cpp
sp.use_count(); // 1
```

After copying shared pointer:

```cpp
auto sp2 = sp;
sp.use_count(); // 2
```

* Shared ownership is allowed
* Memory released only when count reaches zero

---

## 6. Working with Custom Types (e.g., `Dog`)

```cpp
std::unique_ptr<Dog> uDog = std::make_unique<Dog>("Hulk");
std::shared_ptr<Dog> sDog = std::move(uDog);
```

* Heap object remains the same
* Destructor runs only after **last shared owner is destroyed**

---

## 7. What You CANNOT Do

### ❌ shared_ptr → unique_ptr (Not Allowed)

```cpp
std::unique_ptr<Dog> u = sDog;        // ❌
std::unique_ptr<Dog> u = std::move(sDog); // ❌
```

Reasons:

* `shared_ptr` may have **multiple owners**
* `unique_ptr` requires **exactly one owner**
* Compiler blocks this to prevent unsafe behavior

---

## 8. Why shared_ptr → unique_ptr Is Conceptually Invalid

* Other shared pointers may still exist
* Which one should give up ownership?
* Violates the fundamental rule of `unique_ptr`
* Hence:

  * ❌ brace initialization
  * ❌ assignment
  * ❌ `std::move`
    all fail with compiler errors

---

## 9. Returning `unique_ptr` from Functions (Very Important)

### Valid and Safe

```cpp
std::unique_ptr<Dog> getDog() {
    return std::make_unique<Dog>("Phil");
}
```

Why this works:

* Compiler performs **move semantics**
* No copying occurs
* Ownership safely transferred

---

## 10. Assigning Returned `unique_ptr`

### To another `unique_ptr`

```cpp
std::unique_ptr<Dog> uDog = getDog();
```

* Ownership moves from function-local pointer
* Single owner preserved

---

### To a `shared_ptr`

```cpp
std::shared_ptr<Dog> sDog = getDog();
```

* **Implicit move** occurs
* Ownership transfers to `shared_ptr`
* `use_count = 1`

This behaves the same as:

```cpp
std::shared_ptr<Dog> sDog = std::move(uDog);
```

---

## 11. Why Returning `unique_ptr` Is Best Practice

| Return Type  | Flexibility                    |
| ------------ | ------------------------------ |
| `unique_ptr` | Can convert to `shared_ptr`    |
| `shared_ptr` | Cannot convert to `unique_ptr` |

**Design Guideline:**

> Prefer returning `unique_ptr` from functions for maximum flexibility.

---

## 12. Common Mistake (Very Dangerous)

```cpp
std::shared_ptr<int> sp(up.get()); // ❌
```

Why wrong:

* Two smart pointers think they own the same memory
* Leads to **double deletion**
* Undefined behavior

---

## 13. Summary Takeaways

* `unique_ptr` → `shared_ptr` ✔️ (via `std::move`)
* `shared_ptr` → `unique_ptr` ❌ (never allowed)
* Returning `unique_ptr` from functions is preferred
* Shared pointers allow copying and reference counting
* Compiler errors here are **intentional safety mechanisms**

---

## 14. One-Line Conceptual Insight

> `unique_ptr` represents **ownership**, `shared_ptr` represents **collaboration** — ownership can be shared, but collaboration cannot be undone safely.

---


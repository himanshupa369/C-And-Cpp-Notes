<img width="1821" height="696" alt="Screenshot 2025-12-17 120315" src="https://github.com/user-attachments/assets/8ff6fc56-86ae-4849-949a-36e4c549eea6" />

```cpp
#include <iostream>
#include <memory>
#include "dog.h"



int main(){

	//C++17 only : Recommended
	std::shared_ptr<int[]> shared_ptr_int_arr_1( new int[10]{1,2,3,4,5,6,7,8});
	std::shared_ptr<Dog[]> shared_ptr_dog_arr_1( new Dog[10]{Dog("Dog1"),Dog("Dog2")});


	//Setting elements
	shared_ptr_int_arr_1[3] = 28;
	shared_ptr_dog_arr_1[1] = Dog("Fluzzy");

	//Read int array
	std::cout << std::endl;
	std::cout << "Reading data from arrays" << std::endl;
	std::cout << "Reading shared_ptr_int_arr_1: " << std::endl;
	for(size_t i{0}; i < 10 ; ++i){
		std::cout << "shared_ptr_int_arr_1[" << i << "] : " << shared_ptr_int_arr_1[i] << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "Reading shared_ptr_dog_arr_1: " << std::endl;
	for(size_t i{0}; i < 10 ; ++i){
		std::cout << "shared_ptr_dog_arr_1[" << i << "] : " << shared_ptr_dog_arr_1[i].get_name() << std::endl;
	}
   
    return 0;
}
```
---

# `std::shared_ptr` with Arrays in C++

---

## 1. Overview

* `std::shared_ptr` can manage **dynamically allocated arrays**
* This feature was **introduced in C++17**
* Memory is allocated on the **heap**
* Automatic cleanup occurs when the **last shared owner is destroyed**

---

## 2. Syntax for Shared Pointer Arrays

### General Form

```cpp
std::shared_ptr<T[]> ptr(new T[size]{ initializer_list });
```

### Example: Integer Array

```cpp
std::shared_ptr<int[]> arr(new int[10]{1,2,3,4,5,6,7,8});
```

### Example: Object Array

```cpp
std::shared_ptr<Dog[]> dogs(new Dog[10]{
    Dog("Dog1"),
    Dog("Dog2")
});
```

---

## 3. Default Initialization Behavior

### Fundamental Types (e.g., `int`)

* Uninitialized elements are **zero-initialized**

Example:

```cpp
new int[10]{1,2,3}; 
// Remaining elements → 0
```

### User-Defined Types (e.g., `Dog`)

* Uninitialized elements invoke the **default constructor**

Example:

```cpp
new Dog[10]{ Dog("A"), Dog("B") };
// Remaining dogs → default constructed
```

---

## 4. Accessing Array Elements

* Use **subscript operator (`[]`)**
* Same syntax as raw arrays

```cpp
std::cout << arr[3];
std::cout << dogs[1].get_name();
```

---

## 5. Modifying Array Elements

### Modify Fundamental Type

```cpp
arr[3] = 28;
```

### Modify Object

```cpp
dogs[1] = Dog("Flossie");
```

Changes are reflected immediately since the array lives on the heap.

---

## 6. Looping Through Shared Pointer Arrays

```cpp
for (int i = 0; i < 10; ++i) {
    std::cout << arr[i] << "\n";
}
```

```cpp
for (int i = 0; i < 10; ++i) {
    std::cout << dogs[i].get_name() << "\n";
}
```

---

## 7. Destruction and Memory Cleanup

* When the **last `shared_ptr` goes out of scope**:

  * The array memory is released
  * Destructors are called for **each element**

Example:

* `Dog[10]` → 10 destructor calls
* Happens automatically, no `delete[]` needed

---

## 8. `make_shared` and Arrays (Important Limitation)

❌ **`std::make_shared` does NOT support arrays**

```cpp
std::make_shared<int[]>(10); // ❌ Compiler error
```

Reasons:

* No standardized support
* Some compilers provide partial extensions
* Not portable or reliable

✔ Correct approach:

```cpp
std::shared_ptr<int[]> arr(new int[10]);
```

---

## 9. C++ Version Requirement

| Feature                | C++ Version |
| ---------------------- | ----------- |
| `std::shared_ptr<T[]>` | **C++17**   |

* Using this in **C++14 or earlier** → compiler error

---

## 10. Practical Considerations

* Raw arrays with smart pointers are **rare in real-world C++**
* Modern C++ prefers:

  * `std::vector`
  * `std::array`
  * Other STL containers

Smart pointer arrays exist mainly for:

* Legacy code
* Low-level memory control
* Educational purposes

---

## 11. Key Takeaways

* `std::shared_ptr` can manage arrays (C++17+)
* Must use `new[]`, not `make_shared`
* Default initialization applies to missing elements
* Safe, automatic cleanup when last owner is destroyed
* Array elements accessed with `[]`
* Prefer STL containers in production code

---

## 12. One-Line Summary

> `std::shared_ptr<T[]>` provides shared ownership of heap-allocated arrays with automatic lifetime management, but should be used sparingly in modern C++.

---

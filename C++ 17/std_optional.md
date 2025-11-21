```cpp
#include <iostream>
#include <optional>



int main(){

	//Declare and initialize
    std::optional<int> items{3}; 
    std::optional<std::string> name{"Daniel Gakwaya"};
    std::optional<double> weight {77.2};
    std::optional<char> character{'s'};
	
	
	//Declare and empty initialize
    std::optional<std::string> dog_name {}; // Initializes to std::nullopt
    std::optional<int> age {std::nullopt}; // std::nullopt is the null or zero equivalent
											// for std::optional
	std::optional<char> letter = std::nullopt; 	// Triggers unused warning
	std::optional<double> height = {};		  	//Initializes to std::nullopt
												// Triggers unused warning.


    //Read from an std::optional variable
	std::cout << "items : " << items.value() << std::endl;
	std::cout << "items : " << *items << std::endl; // Personaly find this confusing as
													// it's not a pointer, so this the 
													// first and last time I use it in the
													// course
    //std::cout << "items : " << items << std::endl;
	std::cout << "name : " << name.value() << std::endl;
	std::cout << "weight : " << weight.value() << std::endl;
	std::cout << "character : " << character.value() << std::endl;


    //Write stuff
	dog_name = "Fluffy";
	age = 26;
	
    std::cout << std::endl;
    std::cout << "Writting data in ..." << std::endl;
	std::cout << "dog_name : " << dog_name.value() << std::endl;
	std::cout << "age : " << age.value() << std::endl;


    //Reading bad data
	//std::cout << letter.value() << std::endl; // Throws exception and crashes program
	//std::cout << height.value() << std::endl; // Trhows exception and crashes program


    //has_value()
    std::cout << std::boolalpha;
    std::cout << "letter.has_value() : " << letter.has_value() << std::endl;
    std::cout << "height.has_value() : " << height.has_value() << std::endl;
    std::cout << "dog_name.has_value() : " << dog_name.has_value() << std::endl;


    //Do your checks before you read data

    std::cout << std::endl;
    std::cout << "Conditional reading" << std::endl;
	if(letter.has_value()){
		std::cout << "letter contains a useful value" << std::endl;
	}else{
		std::cout << "letter contains std::nullopt" << std::endl;
	}
	
	//Checking against std::nullopt
	if(letter != std::nullopt){
		std::cout << "letter contains a useful value" << std::endl;
	}else{
		std::cout << "letter contains std::nullopt" << std::endl;
	}


    //Checking against std::nullopt
	if(dog_name != std::nullopt){
		std::cout << "dog_name contains a useful value : " << dog_name.value() << std::endl;
	}else{
		std::cout << "dog_name contains std::nullopt" << std::endl;
	}

    
    
    return 0;
}
```

---

# 📌 **`std::optional` — Modern C++ Optional Value (C++17)**

`std::optional<T>` represents **a value that may or may not exist**.

* If it **contains a value**, you can access it.
* If it **doesn’t**, it holds `std::nullopt`.

Essentially:
👉 *“Maybe T”*
Instead of using error codes, sentinel values (`-1`), or nullable pointers.

---

# ✅ **1. Why `std::optional`?**

Modern C++ uses `optional` to:

* Avoid **null pointers**
* Avoid **magic values** (`-1`, empty strings)
* Make APIs **self-documenting**
* Represent *optional output* from functions
* Prevent returning pointers/references to invalid memory
* Reduce bugs in parsing, searching, configuration logic, etc.

---

# ✅ **2. Basic Declaration**

```cpp
std::optional<int> a{3};            // contains value 3
std::optional<double> weight{77.2}; // contains value
std::optional<char> ch{'A'};        // contains 'A'
std::optional<std::string> name{"Alex"};
```

**Empty optionals**

```cpp
std::optional<int> x{};             // empty
std::optional<int> y = std::nullopt;// empty
std::optional<double> z = {};       // empty
```

---

# ✅ **3. Setting a Value**

Just assign a normal `T`:

```cpp
std::optional<std::string> dog;
dog = "Fluffy";     // now contains value
```

---

# ✅ **4. Reading a Value**

### ✔ Recommended

```cpp
x.value()
```

### ✔ Alternative (pointer-like syntax — allowed but discouraged)

```cpp
*x
```

### ❌ NOT allowed

```cpp
std::cout << x;    // ERROR: optional cannot be streamed directly
```

---

# ⚠️ **5. Important Warning**

Calling `.value()` on an empty optional → **throws exception (`std::bad_optional_access`)**

```cpp
std::optional<int> a{};
a.value();          // ❌ crashes!
```

---

# ✅ **6. Safe way to check before read**

### Method 1: `.has_value()`

```cpp
if(a.has_value()) {
    std::cout << a.value();
}
```

### Method 2: truthiness check

```cpp
if(a) { /* contains value */ }
```

### Method 3: compare with `std::nullopt`

```cpp
if(a != std::nullopt) { ... }
```

### Method 4: `.value_or(default)`

```cpp
int n = a.value_or(-1);   // returns -1 if empty
```

---

# ✅ **7. Optional in Functions — Most Common Use Case**

### Example: parsing

```cpp
std::optional<int> parse(const std::string& s) {
    try {
        return std::stoi(s);
    } catch (...) {
        return std::nullopt;
    }
}
```

### Usage:

```cpp
if (auto value = parse("123"); value.has_value()) {
    std::cout << *value;
} else {
    std::cout << "invalid input";
}
```

---

# ✅ **8. Why Optional Is Better Than Returning Reference or Pointer**

| Problem                                                 | Why `optional` solves it                 |
| ------------------------------------------------------- | ---------------------------------------- |
| Returning pointer → may return `nullptr`                | optional is explicit, safer              |
| Returning reference → must always refer to valid object | optional allows “no result”              |
| Returning magic values (like -1)                        | optional removes ambiguity               |
| Using output parameters                                 | optional keeps **output in return type** |

---

# ✅ **9. Optional Supports Any Type**

Works with:

* basic types
* structures
* classes
* move-only types
* large objects (cheap move due to small-object optimization)

---

# ⭐ **10. Summary (Short + Industry Level)**

* `std::optional<T>` = value or **empty**
* Introduced in **C++17**
* Best for **optional output**, **search results**, **parsing**, **configuration**, **validation**
* Use `.value()` or `*obj` to read
  (but **check first** using `.has_value()`)
* Use `value_or(default)` for safe access
* `optional` cannot be printed directly
* The safe modern replacement for:

  * `nullptr` returns
  * magic return values (`-1`)
  * `bool + output parameter` design

---

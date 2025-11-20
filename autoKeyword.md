

---

### ✅ **1. What is `auto` in C++?**

**Answer:**
The `auto` keyword allows the compiler to **automatically deduce** the type of a variable from its initializer.
It was **repurposed in C++11** for type inference.

---

### ✅ **2. Can you declare a variable using `auto` without initialization?**

**Answer:**
No, it's a **compile-time error**.
`auto` requires an **initializer** to deduce the type.

```cpp
auto x; // ❌ Error: 'auto' requires an initializer
```

---

### ✅ **3. What type is deduced here?**

```cpp
auto x = 10;
auto y = 3.14;
auto z = 'A';
```

**Answer:**

* `x`: `int`
* `y`: `double`
* `z`: `char`

---

### ✅ **4. Does `auto` preserve `const`?**

```cpp
const int x = 5;
auto y = x;
```

**Answer:**
No, `y` is deduced as `int`, not `const int`.
To preserve const, use:

```cpp
const auto y = x;
```

---

### ✅ **5. What is the difference between `auto`, `auto&`, and `const auto&` in loops?**

**Answer:**

```cpp
std::vector<int> v = {1, 2, 3};
for (auto x : v)      // copy
for (auto& x : v)     // reference
for (const auto& x : v) // const reference
```

---

### ✅ **6. Can `auto` deduce function parameter types?**

**Answer:**
Not before C++14. In C++14 and later, you can write:

```cpp
auto func(auto x) { return x + 1; } // Valid in C++20
```

---

### ✅ **7. Does `auto` work with pointers and references?**

**Answer:**
Yes.

```cpp
int x = 5;
auto* p = &x;    // int*
auto& r = x;     // int&
const auto& cr = x; // const int&
```

---

### ✅ **8. What is the difference between `auto` and `decltype(auto)`?**

**Answer:**

* `auto` drops references and const-qualifiers unless specified.
* `decltype(auto)` deduces the **exact type**, including references and qualifiers.

Example:

```cpp
int x = 10;
int& rx = x;

auto a = rx;         // int (reference dropped)
decltype(auto) b = rx; // int& (reference preserved)
```

---

### ✅ **9. Can `auto` be used with lambda expressions?**

**Answer:**
Yes.

```cpp
auto f = [](int x) { return x * x; };
```

Here, `f` is a lambda object with an overloaded `operator()`.

---

### ✅ **10. What happens in this code?**

```cpp
auto x = {1, 2, 3};
```

**Answer:**
Deduces `x` as `std::initializer_list<int>`

---

### ✅ **11. Can we use `auto` as a function return type?**

**Answer:**

* **C++11:** Use **trailing return type**.

```cpp
auto func() -> int { return 10; }
```

* **C++14+:** Use deduced return type.

```cpp
auto func() { return 10; }
```

---

### ✅ **12. What are the benefits of using `auto`?**

**Answer:**

* Reduces code verbosity
* Improves maintainability
* Helps with complex types (e.g., iterators, lambdas)

---

### ✅ **13. What are the drawbacks of using `auto`?**

**Answer:**

* Can reduce code readability
* Might deduce unintended types if not careful
* Not allowed without initialization

---

### ✅ **14. Predict the output:**

```cpp
int x = 42;
int& rx = x;

auto a = rx;   // ?
auto& b = rx;  // ?
```

**Answer:**

* `a` is `int`
* `b` is `int&`

---

### ✅ **15. Can `auto` be used in class member declarations?**

**Answer:**
**C++14 onwards:** Yes, with immediate initialization:

```cpp
class Test {
    auto x = 10;  // OK in C++14+
};
```

---
```cpp
#include <iostream>


int main(){

    //Type deduction with auto : Just a copy
    /*
	double some_var{55.5};
	
	auto x = some_var;
	
	std::cout << "sizeof(some_var) : " << sizeof(some_var) << std::endl;
	std::cout << "sizeof(x) : " << sizeof(x) << std::endl;
	std::cout << "&some_var : " << &some_var << std::endl;
	std::cout << "&x : " << &x << std::endl;
    std::cout << " some_var : " << some_var << std::endl;
    std::cout << " x : " << x << std::endl;
    */



   /*
	double some_var = 55.5; //double
	
	double& some_var_ref {some_var};
	
	auto y = some_var_ref; // y is not deduced as a reference to double
						   // it's just a double that contains the value 
						   // in some_var_ref
	++y;
					
	std::cout << "sizeof(some_var) : " << sizeof(some_var) << std::endl; // 8
	std::cout << "sizeof(some_var_ref) : " << sizeof(some_var_ref) << std::endl; // 8
	std::cout << "sizeof(y) : " << sizeof(y) << std::endl; // 8
	std::cout << "&some_var : " << &some_var << std::endl; // 0xabc123
	std::cout << "&some_var_ref : " << &some_var_ref << std::endl ;// 0xabc123
	std::cout << "&y : " << &y << std::endl;  // 0xaab543
	std::cout << "some_var : " << some_var << std::endl; //55.5
	std::cout << "some_var_ref : " << some_var_ref << std::endl; // 55.5
	std::cout << "y : " << y << std::endl; // 56.5
    */


   // True reference deduction
   /*
   	double some_var = 55.5; //double
    double& some_var_ref {some_var};

	
	auto& z = some_var_ref; // z is deduced as a double reference
	++z;
	
	std::cout << "sizeof(some_var) : " << sizeof(some_var) << std::endl; // 8
	std::cout << "sizeof(some_var_ref) : " << sizeof(some_var_ref) << std::endl; // 8
	std::cout << "sizeof(z) : " << sizeof(z) << std::endl; // 8
	std::cout << "&some_var : " << &some_var << std::endl;// 0xabc123
	std::cout << "&some_var_ref : " << &some_var_ref << std::endl;// 0xabc123
	std::cout << "&z : " << &z << std::endl;// 0xabc123
	std::cout << "some_var : " << some_var << std::endl; // 56.5
	std::cout << "some_var_ref : " << some_var_ref << std::endl; //56.5
	std::cout << "z : " << z << std::endl; // 56.5
    */


	//Constness is preserved with properly deduced references var with auto.💡💡💡💡💡💡
    /*
	const double some_other_var {44.3};
	
	const double& const_ref {some_other_var};
	
	auto& p = const_ref; //constness is preserved.
	
	std::cout << "some_other_var : " << some_other_var << std::endl;
	std::cout << "const_ref : " << const_ref << std::endl;
	std::cout <<  "p : " << p << std::endl;
	
	//++p; // Compiler error
	
	std::cout << "some_other_var : " << some_other_var << std::endl;
	std::cout << "const_ref : " << const_ref << std::endl;
	std::cout <<  "p : " << p << std::endl;
    */

	//Constness doesn't matter with non reference deduction 💡💡💡💡💡💡
	const double i_am_const {71.2};
    const double& my_ref {i_am_const};

	auto q = my_ref; // q is a separate variable, initialized with the
							// value in i_am_const. but constness is not preserved.
	++q;// Can modify q without a problem. It's a copy.
	




	
   
    return 0;
}
```


---

# ⭐ Type vs Non-Type Template Parameters in C++

C++ templates allow you to parametrize **types**, **values**, and even **other templates**.
The two most common categories are:

# 🧩 1. Type Template Parameters

These are the **most common**.
They allow you to pass a **type** as a template argument.

### ✔ Meaning

Template parameters whose value is a **type** (e.g., `int`, `double`, `std::string`).

### ✔ Syntax

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

Here, `T` is a **type parameter**.

### ✔ Example Usage

```cpp
max<int>(3, 5);          // T = int
max<double>(3.1, 5.7);   // T = double
```

### ✔ When to use?

* When behavior depends on **data type**
* For generic containers/functions (`vector<T>`, `sort<T>`)

---

# 🧩 2. Non-Type Template Parameters (NTTP)

These are template parameters whose value is **not a type**, but a **constant value** known at compile-time.

### ✔ Allowed types (C++20)

* `int`, `char`, `bool`
* `size_t`
* `enum`
* Pointers
* References
* Floating point (C++20)
* Structural types (C++20)

### ✔ Syntax

```cpp
template <int SIZE>
int sum(int (&arr)[SIZE]) {
    int s = 0;
    for(int i = 0; i < SIZE; ++i) s += arr[i];
    return s;
}
```

Here, `SIZE` is a **non-type parameter**.

### ✔ Example Usage

```cpp
int data[5] = {1, 2, 3, 4, 5};
sum<5>(data);       // SIZE = 5 (value)
```

### ✔ When to use?

* Fixed-size arrays
* Compile-time constants
* Optimizing performance (loop unrolling, buffer sizes)
* Template-based metaprogramming

---

# 🆚 **Difference Between Type and Non-Type Template Parameters**

| Feature         | Type Template Parameter          | Non-Type Template Parameter             |
| --------------- | -------------------------------- | --------------------------------------- |
| What is passed? | A **type** (int, double, class…) | A **value** (int, char, pointer, bool…) |
| Deduction       | Often deduced from function args | Must be a **compile-time constant**     |
| Used for        | Generic functions/classes        | Compile-time configuration              |
| Example         | `template <typename T>`          | `template <int N>`                      |

---

# 📘 Example: Type + Non-Type Together

```cpp
template <typename T, int N>
class Array {
public:
    T data[N];
};
```

Usage:

```cpp
Array<int, 10> arr;   // T = int, N = 10
```

---

# 🧨 Why Use Non-Type Template Parameters?

### ✔ Zero runtime overhead

### ✔ Allows compile-time computation

### ✔ Makes generic constant values possible

### ✔ Works with constexpr programming

Example showing compile-time size:

```cpp
template <size_t N>
void printSize() {
    std::cout << "Size: " << N << '\n';
}

printSize<20>(); // prints: Size: 20
```

---

# 📌 Summary (For GitHub Notes)

### **Type Template Parameters**

* Accept **types**
* Example: `template<typename T>`
* Used for STL containers & generic algorithms.

### **Non-Type Template Parameters**

* Accept **compile-time values**
* Example: `template<int N>`
* Used for fixed-size arrays, compile-time configs, metaprogramming.

---
<img width="1617" height="778" alt="Screenshot 2025-11-25 174601" src="https://github.com/user-attachments/assets/3c4af5d4-b4b5-4095-83ea-00abf739b256" />

```cpp
#include <iostream>

/*
template <int threshold,typename T>
bool is_valid(T collection[] ,size_t size)
{
    T sum{};//0
    for(size_t i{ 0 }; i < size; ++i) {
        sum += collection[i];
    }
    return (sum > threshold) ? true : false;
}
*/


//Version making a little more sense for the task
template <typename T>
bool is_valid(T collection[], int threshold,size_t size)
{
	T sum{};
	for(size_t i{ 0 }; i < size; ++i) {
		sum += collection[i];
	}
	return (sum > threshold) ? true : false;
}


//Support for C++20 NTTP is still not fully supported
//Function below doesn't compile on gcc10 but does on gcc11 with wandbox
//Wandbox : https://wandbox.org/permlink/FqJzUV00c5MC2ie2
/*
template <typename T, double coeff>
T process (T a, T b){
    return a*b-coeff;
}
*/

int main(){

	double temperatures[] {10.0,20.0,30.0,40.0,50.0,100.0};

    auto result = is_valid<double>(temperatures,200,std::size(temperatures));
    std::cout << std::boolalpha;
    std::cout << "result : " << result << std::endl;
   
    return 0;
}
```

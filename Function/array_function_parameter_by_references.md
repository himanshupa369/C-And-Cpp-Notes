
---

# ✅ **Passing an Array by Reference — Edge Cases**

A function like this:

```cpp
void func(int (&arr)[5]);
```

passes the array **by reference**, not as a pointer.

Here are the **core edge cases**:

---

## **1. Size becomes part of the type**

The size **must match exactly**.

```cpp
int a[5];
func(a);    // OK

int b[4];
func(b);    // ❌ compile error (type mismatch)
```

👉 This is **good for safety**, but **reduces flexibility**.

---

## **2. Cannot pass dynamic arrays**

```cpp
int n;
cin >> n;
int* arr = new int[n];
func(arr);   // ❌ cannot bind dynamic array to int(&)[5]
```

Even if the sizes match at runtime, **compile-time sizes do not**.

---

## **3. Cannot pass `std::vector` or pointer arrays**

```cpp
std::vector<int> v(5);
func(v);          // ❌ no matching function

int* p = new int[5];
func(p);          // ❌ wrong type
```

Because the type is still **not** `int[5]`.

---

## **4. Cannot pass array decay**

Normally arrays decay to pointers, but **not here**:

```cpp
void foo(int arr[]);   // arr → int*
void bar(int (&arr)[5]); // arr is an array reference

int a[5];
foo(a);   // OK
bar(a);   // OK

int* p = a;
bar(p);   // ❌ array reference cannot bind to pointer
```

Reference-to-array prevents decay → cleaner type safety → less flexibility.

---

## **5. Function receives the real array**

No copying; the function can modify the caller’s array:

```cpp
void func(int (&arr)[5]) {
    arr[0] = 100;
}
```

This can lead to:

### **Edge Case: Accidental mutation**

Very common bug in industry code.

Solution: use `const int (&arr)[5]`.

---

## **6. Lifetime issues**

If you bind to an array whose lifetime ends, reference becomes invalid:

```cpp
int* make() {
    int arr[5];   // local array
    return arr;   // ❌ returning pointer to dead array
}

void f() {
    int (&ref)[5] = *make();  // ❌ dangling reference
}
```

---

## **7. Overload confusion**

These two are different functions:

```cpp
void foo(int arr[5]);
void foo(int (&arr)[5]);
```

* First one is actually `void foo(int*)` (decays)
* Second is real array reference

May cause ambiguous/broken API design.

---

## **8. Not commonly used in APIs**

Because the syntax is awkward:

```cpp
void func(int (&)[5]);
```

Industry prefers:

✔️ `std::span<int>` (C++20)
✔️ `std::array<int, 5>&`
✔️ `T* + size` parameter

---

# 📌 **Short Summary**

| Edge Case                       | Explanation                         |
| ------------------------------- | ----------------------------------- |
| Array size becomes part of type | Must match exactly                  |
| No decay allowed                | Can't pass pointer or dynamic array |
| Can't pass vector               | Type mismatch                       |
| Real array is modified          | Hidden side effects                 |
| Lifetime issues                 | Dangling reference possible         |
| Overload complexity             | Hard to maintain                    |
| Rare in real APIs               | Too rigid                           |

---
```cpp
#include <iostream>

//Declaration
double sum( const double (&scores) [10]);


int main(){

    double student_scores[] {10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0,1}; 
    
    double sum_result = sum(student_scores);
	
    std::cout << "result is : " << sum_result << std::endl;
   
    return 0;
}

//Definition
double sum( const double (&scores) [10]){
    double sum{};
    for(size_t i{}; i < std::size(scores) ; ++i){
        sum  += scores[i];
    }
    return sum;
}
```

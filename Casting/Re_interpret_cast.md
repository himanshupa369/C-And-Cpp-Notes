
```cpp
//...re-interpret cast...

//reinterpret_cast is a type of cast in C++ that is used for converting one pointer type to another, or an integral type to / from a pointer type.
//It is the most dangerous and low - level cast in C++ because it performs a bitwise conversion without any safety checks.

//Key Properties :-

//No Type Safety : It does not check if the conversion is valid.
//Used for Low - Level Operations : Like type punning, working with hardware registers, etc.
//Can Lead to Undefined Behavior : If misused, it may lead to crashes or corruption.

//When to Use reinterpret_cast ?
//✅ Interfacing with hardware or low - level memory operations.
//✅ Converting between pointer types(only when absolutely necessary).
//✅ Working with raw memory buffers.

//When to Avoid reinterpret_cast ?
//❌ When safer casts like static_cast or dynamic_cast can be used.
//❌ When converting unrelated types(e.g., int to std::string*).
//❌ When you don’t fully understand the consequences(it can cause undefined behavior).

#include <iostream>
using namespace std;

struct A {
    int x;
};

int main() {
    // 1 Use
    //A obj;
    //int* ptr = reinterpret_cast<int*>(&obj);  // Convert struct pointer to int pointer
    //cout << *ptr << endl; // May give unintended output

    // 2 Use
    int num = 65;
    void* ptr1 = reinterpret_cast<void*>(num); // Convert integer to void pointer
    cout << ptr1 << endl;
    //Note:- ⚠ Warning: This is dangerous! The integer might not be a valid memory address.

    // 3 use
    int a = 10;
    int* ptr = &a;

    uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);  // Convert pointer to integer
    cout << "Pointer as integer: " << addr << endl;

    int* new_ptr = reinterpret_cast<int*>(addr); // Convert back to pointer
    cout << "Value at new pointer: " << *new_ptr << endl;

    const int x=1;
    int* p1=(int*)(&x); // c style cast allowed 
    int* p11=reinterpret_cast<int*>(&x); //but it does not discard qualifier.

    return 0;
}
```

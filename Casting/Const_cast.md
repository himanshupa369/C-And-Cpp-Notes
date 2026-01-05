
```cpp
//...const_cast in C++...

//const_cast is a C++ casting operator used to remove or add const (or volatile) qualifiers from a variable.

// Key Features of const_cast:

//✔ Removes const or volatile qualifiers from a variable.
//✔ Used for modifying "const" data in specific scenarios(though modifying truly constant data leads to undefined behavior).
//✔ Does NOT perform type conversion—it only changes the const / volatile qualifiers.
//✔ Primarily used when working with legacy APIs that do not accept const parameters but do not actually modify the data.


// When to Use const_cast ?

//✅ When you must remove const for API compatibility.
//✅ When calling a non - const function inside a const function.
//✅ When working with legacy C functions that don’t accept const parameters.

// ❌ Do NOT use const_cast if :
//    🚫 You need to modify an actual constant(undefined behavior).
//    🚫 You can redesign your code to avoid casting.

//Const Correctness in C++...

//Const correctness is a programming practice in C++ that ensures read - only variables, parameters, and member functions do not modify data unless explicitly intended.

//🔹 Why Use Const Correctness ?
//✔ Prevents accidental modification of data.
//✔ Improves code safety and readability.
//✔ Enables compiler optimizations.
//✔ Helps avoid bugs caused by unintended changes.

// how we can read a const pointers.
//int a = 10, b = 20;
//const int* p1 = &a;   // Pointer to a constant int (Cannot modify *p1)
//int* const p2 = &a;   // Constant pointer to int (Cannot change p2)
//const int* const p3 = &a;  // Constant pointer to constant int
//* p1 = 20;  // ❌ Error: Read-only value
//p1 = &b;   // ✅ Allowed (changing pointer itself)
//*p2 = 20;  // ✅ Allowed (changing value)
//p2 = &b;   // ❌ Error: Cannot change pointer address

/* void printValue(const int value) { // Cannot modify value inside the function
    // value = 20; ❌ Error: Cannot modify a const parameter
    cout << "Value: " << value << endl;
}*/

//🔹 When Is It Safe to Convert a const Object to Non - const ?
//✅ Safe when :
//✔ The original object was not declared as const but was passed as a const reference.
//✔ The class is designed to allow modifications internally(e.g., using mutable variables).
//   `mutable` allows modification in `const` functions

//🔹 When NOT to Convert a const Object to Non - const ?
//🚫 If the object was truly declared as const at creation
        //const Test obj(10);  // ❌ Converting this can cause undefined behavior!
//🚫 If the object is stored in read - only memory(e.g., global const variables)
//🚫 If the class was designed to be immutable(e.g., for thread safety)


#include <iostream>
using namespace std;

void modifyValue(const int* ptr) {
   int* modifiablePtr = const_cast<int*>(ptr); // Remove const
   *modifiablePtr = 20; // Modify value
}

class Test {
public:
   void show() const {
       cout << "Inside const function" << endl;
       const_cast<Test*>(this)->nonConstFunction();
   }

   void nonConstFunction() {
       cout << "Modified inside non-const function" << endl;
   }
};

void printMessage(char* str) {
   cout << "Message: " << str << endl;
}

int main() {
   //Removing const for Modification
   //✅ const_cast is used to remove const and modify the value.
   int x = 10;
   modifyValue(&x);
   cout << "Modified value: " << x << endl; // Output: 20

   // Using const_cast for Function Overloading
   //✅ const_cast is used to call a non-const function from a const function.
   Test obj;
   obj.show();


   //const_cast with Pointers
   //✅ Useful when working with legacy C functions that don't accept const parameters.
   const char* message = "Hello, World!";
   printMessage(const_cast<char*>(message)); // Removes const to match function signature

   //If the original data is truly constant (e.g., stored in read-only memory), modifying it leads to undefined behavior.
   // ❌ Never modify data that was originally declared as const.
   
   //const int x = 100;
   //int* ptr = const_cast<int*>(&x);
   //*ptr = 200; // 🚨 Undefined behavior! x is declared as const.
   //cout << "Value: " << x << endl;  // Output is unpredictable!


 


   return 0;
}
```

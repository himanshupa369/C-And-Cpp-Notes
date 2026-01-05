
```cpp
//dynamic_cast in C++...

//dynamic_cast is a type of casting operator in C++ that is used for safe runtime type conversion between polymorphic(i.e., classes with virtual functions) objects.

// Key Features of dynamic_cast....

//✔ Used for safe downcasting(from base class to derived class).
//✔ Requires at least one virtual function in the base class to work.
//✔ Performs a runtime check to ensure the cast is valid.
//✔ If the cast is invalid :
               //Returns nullptr when used with pointers.
               //Throws std::bad_cast exception when used with references.


//When to Use dynamic_cast ?
//✅ When working with polymorphic classes(must have a virtual function).
//✅ When you need safe downcasting(checking if an object is actually of the derived type).
//✅ When runtime safety is required(unlike static_cast, which doesn’t check).

//❌ Do NOT use dynamic_cast if :
//    🚫 You don’t have virtual functions(use static_cast).
//    🚫 Performance is critical(dynamic casting is slower due to runtime checks).

//Feature	                                 dynamic_cast	                                 static_cast
//Type Checking	                             Runtime check	                                 Compile - time check
//Works on Pointers ?                       ✅ Yes	                                         ✅ Yes
//Works on References ?                     ✅ Yes(throws bad_cast if failed)	             ✅ Yes(unsafe)
//Requires Virtual Functions ?              ✅ Yes	                                         ❌ No
//Safe for Downcasting ?                    ✅ Yes(checks at runtime)	                     ❌ No(unsafe)
//Performance	                              Slower(runtime overhead)	                     Faster(compile - time)


#include <iostream>
using namespace std;

class Base {
public:
   virtual void show() { cout << "Base class" << endl; } // Virtual function required!
   ~Base() {
       cout << "Base destructor invoked:" << endl;
   }
};

class Derived : public Base {
public:
   void show() override { cout << "Derived class" << endl; }
   ~Derived(){
       cout << "derived destructor invoked:" << endl;
   }
};

int main() {
   Base* basePtr = new Derived();  // Base class pointer pointing to Derived object
   Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Safe downcasting


   //Invalid Downcasting Example -> 
   /* Base* basePtr = new Base();
   Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Invalid cast! */

   if (derivedPtr) {
       derivedPtr->show(); // Output: "Derived class"
   }
   else {
       cout << "Cast failed!" << endl;
   }

    // why base is deleted but not derived;
   //delete derivedPtr;
   //delete basePtr;
   
   
   return 0;
}
```

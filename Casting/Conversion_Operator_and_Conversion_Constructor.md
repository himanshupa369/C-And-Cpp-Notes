
```cpp
//Conversion Operator vs Conversion Constructor in C++


/*Feature	                      Conversion Constructor	              Conversion Operator
Converts	                      Other types → Class type	              Class type → Other types
Syntax	                          ClassName(Type t) {}	                  operator Type() {}
Implicit ?                        Yes(unless explicit)	                  Yes(unless explicit)
Example	                          Distance d = 10;	                      int meters = d;  */             
//In C++, type conversion allows objects to be implicitly or explicitly converted between types.This can be done using:
//Conversion Constructors → Convert from another type to a class type.
//Conversion Operators → Convert from a class type to another type.

//🔹 1)Conversion Constructor
//✔ A constructor that takes a "single parameter only" of a different type and converts it into a class object.
//✔ Implicitly called unless marked explicit.

//#include <iostream>
//using namespace std;
//
//class Distance {
//    int meters;
//    char chr;
//
//public:
//    // Conversion Constructor (converts int to Distance object)
//    Distance(int m) : meters(m) {
//        cout << "Integer Conversion Constructor called\n";
//    }
//    Distance(char ch): chr(ch){
//        cout<<"Char Conversion Constructor called\n";
//    }
//    void show() { 
//    cout << "Distance: " << meters << " meters" << endl; 
//    }
//    void display(){
//    cout<<"Distance: "<<chr<<" character"<<endl;     
//    }
//};
//
//int main() {
//    Distance d1 = 10;  // Implicit conversion from int → Distance
//    d1.show();
//
//    Distance d3 = 'A';
//    d3.display();
//
//    Distance d2(20);   // Explicit constructor call
//    d2.show();
//    return 0;
//}

//Note:- ✔ 10 and 20 are implicitly converted into Distance objects.


//🔹 2️) Conversion Operator(operator TYPE())
//✔ A member function that converts a class object into another type.
//✔ Uses the syntax :
//                   operator primitiveTYPE() { return typecast(...); }

#include<iostream>
#include<string>
using namespace std;

class Distance {
   int meters;

public:
   Distance(int m) : meters(m) {}

   // Conversion Operator (converts Distance to int)
   operator int() {
       return meters;
   }
   operator char() {
       return char(meters);
   }
   operator float() {
       return float(meters);
   }
   operator string() {
       return to_string(meters);
   }
};

int main() {
   Distance d(65);
   int meters = d;  // Implicit conversion from Distance → int
   cout << "Meters: " << meters << endl;  // ✅ Output: Meters: 65
   char ch = d;
   cout << "Character: " << ch << endl;
   float fl = d;
   cout << "Float: " << fl << endl;
   string str = d;
   cout << "string: " << str << endl;
   return 0;
}
```

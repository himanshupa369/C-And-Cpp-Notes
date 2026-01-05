
```cpp
#include<iostream>
using namespace std;

// Polymorphism: A function with the same name but different parameter types or the number of parameters (not return type) is called polymorphism.
// In this example, we demonstrate static (compile-time) polymorphism using function overloading and operator overloading.

//friend function:- Friend Function is  a function which is not a member function of class and it has previlege to access private 
// and protected member  of the class
class calculator {
private:
    int p;
    int q;
public:
    int x;

    // Constructor to initialize x,p,q with a value
    calculator(int lv,int pv,int qv) : x(lv),p(pv),q(qv) {}
    
    //friend function
    friend int mul(const calculator &ob1);
    
    // Function overloading 
    
    //based on parameter types
    int add(int a, int b) {
        return a + b;
    }

    
    double add(double x, double y) {
        return x + y;
    }

    // based on number of parameters
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Print method to display the value of x
    void print(){  
        cout << "x is: " << x << endl;
    }

    // Operator overloading
    void operator ++() {
        x = x + 2;
    }

    // Overload the assignment operator
    calculator& operator=(const calculator& obj) {
        if (this != &obj) { // Avoid self-assignment
            x = obj.x;  // Copy the value from the other object
        }
        return *this; // Return the current object
    }
};
int mul(const calculator& ob1) {
    return (ob1.p) * (ob1.q);
}

int main() {
    calculator cal(5,4,3);   
    calculator cal1(10,5,6); 
    cout<<"friend function is called: "<<mul(cal)<<endl;

    cal.print(); 

    // Assignment operator
    cal = cal1;  
    cal.print(); 

    // Function Overloading based on parameter types and count:
    cout << "add(4, 5): " << cal.add(4, 5) << endl;        // Calls int add(int, int)
    cout << "add(4.5, 5.5): " << cal.add(4.5, 5.5) << endl; // Calls double add(double, double)
    cout << "add(4, 5, 6): " << cal.add(4, 5, 6) << endl;   // Calls int add(int, int, int)

    // Operator Overloading:
    ++cal; 
    cal.print();  
    return 0;
}
```

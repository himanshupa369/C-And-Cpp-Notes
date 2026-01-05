
```cpp
//Runtime Polymorphism is also called Dynamic Polymorphism and achieved this topic includes concepts of override,dynamic casting,diamond Problem
//Abstract class,abstraction,virtual and pure virtual function,v-pointer and virtual table,virtual destructor

#include <iostream>
using namespace std;

//Virtual Constructor we can't create;
// Virtual table :- When a class contains at least one virtual function, the compiler generates a vtable at compile time for that class.
// below Shape class is Abstract Class which have atleast one  pure virtual fn. and can't instantiate their objects.
// Constructors cannot be virtual.
// virtual destructor is used to destruct the object according to virtual table sequence without memory leak it deallocate memory properly //
class Shape {
public:
    /*A pure virtual function is a virtual function in a base class that has no implementation.It is meant to be overridden by derived classes.*/
   /*The presence of a pure virtual function in a class makes that class abstract, meaning you cannot instantiate objects of that class directly.*/
    //Pure Virtual Function
    virtual void draw() = 0;
    virtual ~Shape() {
        cout << "Called Shape Destructor" << endl;
    }
};
class Square :virtual public Shape {
public:
    //overwrite of pure virtual function
    void draw() override{
        cout << "Draw a Square" << endl;
    }
    virtual ~Square() {
        cout << "Called Square Destructor" << endl;
    }

};
class Circle : virtual public Shape {
public:
    void draw() override{
        cout << "Draw a Circle" << endl;
    }
    virtual ~Circle() {
        cout << "Called Circle Destructor" << endl;
    }
};
//diamond problem
class Diamond :public Square,public Circle {
    void draw() override {
        cout << "Draw a diamond " << endl;
    }
    virtual ~Diamond() {
        cout << "Called Diamond Destructor" << endl;
    }
};

//Note:- In above diamond example without virtual inheritance Diamond has two copy of Class Shape but with virtual inheritance diamond has only one copy of shape.

class Base {
public:
   /* A virtual function in object - oriented programming(OOP) is a function that is declared within a base class and is meant to be overridden in a derived class.
    When a function is marked as virtual, it allows for polymorphism, meaning that the function call is resolved at runtime, rather than at compile time.*/
    virtual void display() {
        cout << "this is base class" << endl;
    }
      ~Base() {
        cout << "Called Base Destructor" << endl;
    }
};
class Derive:virtual public Base {
public:
  /*  The override keyword in C++ is used to indicate that a member function in a derived class is intended to override a virtual function in the base class.
    It is part of C++11 and later standards, and its main purpose is to ensure type safety and improve code clarity when dealing with polymorphism.*/
    // void display(int a) { } kind of function is not override kind of method.
    void display() override {
        cout << "this is derived class " << endl;
    }
    ~Derive() {
        cout << "Called Derive Destructor" << endl;
    }

};
int main()
{
    cout << "Base Object: "<<endl;
    Base* bs = new Base;
    bs->display();
    cout << "Derive Object: "<<endl;
    Derive* dr = new Derive;
    dr->display();
    cout << "Due to Virtual Pointer derive class method is called: " << endl;
    bs = new Derive;
    bs->display();
    //Shape* sp = new Shape; it cannot instantiate bcuz it is abstract class
    Shape* sp = new Square;
    sp->draw();
    sp = new Circle;
    sp->draw();
    // we can not point diamond with shape because there is no direct connection with Shape->diamond it shows error//
    Circle* sp1 = new Diamond;
    sp1->draw();

    return 0;
}

```

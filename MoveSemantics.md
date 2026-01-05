

---

## ✅ C++ Move Constructor & Move Assignment – Interview Questions with Answers

---

### 🔹 1. **What is a move constructor in C++?**

**Answer:**
A **move constructor** transfers ownership of resources from a **temporary (rvalue)** object to a new object to avoid deep copy overhead.

```cpp
ClassName(ClassName&& other);  // move constructor
```

---

### 🔹 2. **What is the syntax of a move assignment operator?**

```cpp
ClassName& operator=(ClassName&& other); // move assignment
```

---

### 🔹 3. **Why do we need move semantics?**

**Answer:**
To:

* **Avoid deep copies**
* **Improve performance**
* **Enable efficient return-by-value**
* Handle **temporary (rvalue) objects** efficiently

---

### 🔹 4. **What is the difference between copy and move constructors?**

| Feature           | Copy Constructor                 | Move Constructor                  |
| ----------------- | -------------------------------- | --------------------------------- |
| Signature         | `ClassName(const ClassName&)`    | `ClassName(ClassName&&)`          |
| Used for          | Copying lvalue                   | Moving from rvalue                |
| Resource handling | Deep copy                        | Transfer ownership (shallow move) |
| Cost              | Higher (may allocate new memory) | Lower (no allocations if moved)   |

---

### 🔹 5. **Write a move constructor example.**

```cpp
class MyClass {
    int* data;
public:
    MyClass(int val) { data = new int(val); }

    // Move constructor
    MyClass(MyClass&& other) noexcept {
        data = other.data;
        other.data = nullptr;  // Release ownership
    }

    ~MyClass() { delete data; }
};
```

---

### 🔹 6. **What happens if you don’t define a move constructor?**

**Answer:**

* The compiler generates a default one **only if**:

  * No custom copy constructor/assignment/destructor is defined
* Otherwise, move operations fall back to **copy** (which may be inefficient or unsafe)

---

### 🔹 7. **What is Rule of 5 in C++11?**

**Answer:**

If your class needs any one of these, you usually need all five:

1. Copy constructor
2. Copy assignment
3. Move constructor
4. Move assignment
5. Destructor

---

### 🔹 8. **How does `std::move` work with move constructor?**

**Answer:**

`std::move` **casts an lvalue to an rvalue**, enabling move constructor/assignment.

```cpp
MyClass a(5);
MyClass b = std::move(a);  // Move constructor called
```

---

### 🔹 9. **How to implement a move assignment operator?**

```cpp
MyClass& operator=(MyClass&& other) noexcept {
    if (this != &other) {
        delete data;  // clean up
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}
```

---

### 🔹 10. **What is the danger of not nullifying the source in move?**

**Answer:**

* **Double deletion** when both objects try to free the same resource.
* **Dangling pointer** errors.

---

## 🧠 Bonus Tips:

| Mistake                                | Fix                                |
| -------------------------------------- | ---------------------------------- |
| Not checking for self-assignment       | `if (this != &other)`              |
| Not setting `other.data = nullptr`     | Prevents double delete             |
| Using `const ClassName&&` in move ctor | ❌ Invalid – can't move from const  |
| Forgetting `noexcept`                  | May disable move in STL containers |

---

## ✅ Interview Traps:

* What if you pass an rvalue by reference instead of rvalue-reference?
* Can you move a `const` object? (❌ No – move constructor requires non-const)
* What is the return type of move assignment? (`ClassName&`)
* Why `noexcept` is important in move semantics? (Ensures safety in STL containers)

---

```cpp
// Why Move Semantics?
/* 
=> Eliminate unnecessary copying in c++ to boost speed and efficiency.
=> Improve Performance especially when handling large and complex objects by enabling the transfer of resources rather than costly duplication.

=>this all achieved through Lvalue ,Rvalue ,Rvalue Reference and the utility function std::move.


//Introduction...

//In C++, move semantics is a feature introduced in C++11 that allows resources to be efficiently transferred from one object to another, instead of copying them.
//This is particularly useful for expensive operations like managing dynamic memory, file handles, or other system resources.
//Allow us to avoid unnecessary copy of objects when working with temporary object.

//Why Move Semantics?

//When an object is copied, a deep copy is typically performed, which means duplicating all resources.However,
//in some cases(like returning objects from functions), creating a copy is wasteful.Move semantics allows transferring ownership of resources instead of duplicating them.

//When are Move Semantics Used ?

//Returning objects from functions(avoid unnecessary copies).
//When passing temporary objects.
//Optimizing large data structures like vectors, strings, etc.


Copy & Move Semantics : -

*Copy is implemented through copy constructor
* Copy of the object state is created
* Wasteful in case copy is created from a temporary
* Instead, the state can be moved from the source object
* Implemented through move semantics

Resource Management :-
   * Some classes own a resource
   * This resource may be a pointer, file handle, socket, etc.
   * Such resources may be acquired in the constructor
   * Subsequently, you have to decide the action in case objects of such classes are copied, moved or destroyed
   * E.g. on destruction, the resource must be released to avoid leaks
   * Similarly, on copy or move the resource must be handled accordingly
*/

//Move Constructor and Move Copy Assignment...

//#include <iostream>
//using namespace std;
//
//class A {
//private:
//    int* ptrArr;
//public:
//    A() : ptrArr(new int[5]) {
//        for (int i = 0; i < 5; ++i) {
//            ptrArr[i] = i + 1;
//        }
//        cout << "default constructor called" << endl;
//    }
//
//    // Copy Constructor (Deep Copy)
//    A(const A& other) : ptrArr(new int[5]) {
//        cout << "copy constructor called" << endl;
//        for (int i = 0; i < 5; ++i) {
//            this->ptrArr[i] = other.ptrArr[i];
//        }
//    }
//
//    // Move Copy Constructor
//    A(A&& other) noexcept : ptrArr(other.ptrArr) {
//        cout << "move constructor called" << endl;
//        other.ptrArr = nullptr; // Transfer ownership
//    }
//
//    // Copy Assignment Operator
//    A& operator=(const A& other) {
//        cout << "Copy Assignment Overload" << endl;
//        if (this != &other) {
//            delete[] ptrArr;
//            this->ptrArr = new int[5];
//            for (int i = 0; i < 5; ++i) {
//                ptrArr[i] = other.ptrArr[i];
//            }
//        }
//        return *this;
//    }
//
//    // Move Assignment Operator
//    //noexcept defines that function can't throw error
//    A& operator=(A&& other) noexcept {
//        cout << "Move Assignment Overload" << endl;
//        if (this != &other) {
//            delete[] ptrArr;
//            this->ptrArr = other.ptrArr;
//            other.ptrArr = nullptr;
//        }
//        return *this;
//    }
//
//    void display() {
//        cout << "print call" << endl;
//        for (int i = 0; i < 5; ++i) {
//            cout << ptrArr[i] << " ";
//        }
//        cout << endl;
//        cout << endl;
//    }
//
//    virtual ~A() {
//        delete[] ptrArr;
//        cout << "destructor is called" << endl;
//    }
//};
//
//int main() {
//    A a;
//    a.display();
//
//    // Copy constructor
//    A b = a;
//    b.display();
//
//    // Move constructor
//    A c = std::move(b);
//    c.display();
//    //b.display();
//
//    A d;
//    //Copy Assignment
//    d = a;
//    d.display();
//
//    A e;
//    // Move copy assignment
//    e = std::move(a);
//    e.display();
//}



//move constructor with vector reallocation or resizing. 

//#include <iostream>
//#include <vector>
//
//class MyClass {
//public:
//    int* data;
//
//    MyClass(int val) {
//        data = new int(val);
//        std::cout << "Constructor: " << *data << std::endl;
//    }
//
//    // Copy constructor
//    MyClass(const MyClass& other) {
//        if(other.data!=nullptr) //********************
//        data = new int(*other.data); 
//        std::cout << "Copy Constructor: " << *data << std::endl;
//    }
//
//    // Move constructor
//    MyClass(MyClass&& other) noexcept {
//        data = other.data;
//        other.data = nullptr;
//        std::cout << "Move Constructor\n";
//    }
//
//    ~MyClass() {
//        if (data) {
//            std::cout << "Destructor: " << *data << std::endl;
//            delete data;
//        }
//    }
//};
//
//int main() {
//    std::vector<MyClass> vec;
//
//    vec.reserve(2);  // Avoid reallocation for first 2
//    vec.push_back(MyClass(1));
//    vec.push_back(MyClass(2));
//
//    std::cout << "--- Triggering Reallocation ---\n";
//    vec.push_back(MyClass(3)); // Causes reallocation, moves/copies objects
//
//    return 0;
//}
//// If we did not use noexcept in our move constructor then we can see that order of destructors are not deallocating in reverse order of object creation due to vector implementation and it varies compiler to compiler.


```

```cpp
/*

🔄 What is std::move() ?

=> std::move() is a standard library function defined in the <utility> header that casts an object to an r - value reference.
=> It does not actually move anything.It simply enables move semantics by converting an l - value into an r - value, so that the move constructor or move assignment operator can be used.
=> It's mainly used to avoid expensive deep copies (e.g., for containers, strings, or user-defined types with dynamic memory).
=> reinitialization is must after move a Lvalue.
=> It is also used for non copy operation where function only provides move operation.
*/

//#include <iostream>
//#include <string>
//#include <utility>
//#include<vector>
//
//void PrintArr(std::vector<int>&& v){
//    int n = v.size();
//    for (auto& i : v) {
//        std::cout << i << " ";
//    }
//}
//int main() {
//    std::string a = "Hyderabad";
//    std::string b = std::move(a); // move constructor is used
//    std::cout << "a: " << a << std::endl; // a is now in a valid but unspecified state
//    std::cout << "b: " << b << std::endl; // "Hyderabad"
//
//
//    std::vector<std::string> v;
//    v.emplace_back("C++ session"); //construct string directly in vector,avoiding temporaries.
//    v.push_back("CopyCreation"); // it create copy then move copy into container.
//
//    std::vector<int> arr = { 1,2,3,4,5 };
//    PrintArr(std::move(arr));
//    std::cout << std::endl;
//    //Print of array elements give us error because after move ,reinitialization is must to access those variables.
//    std::vector<int> arr2 = std::move(arr);
//    for (int i = 0; i < arr.size(); i++) {
//        std::cout << arr[i] << " ";
//    }
//
//
//}

```

```cpp
// std::move()...

// It is a function from C++ standard library  for casting to a rvalue reference.

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& v) {
	cout << "size: (" << v.size() <<") " << " Array elements:" << endl;
	for (auto i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}


template<typename T>
void Swap(T& a, T& b) {
	T temp = move(a);
	a = move(b);
	b = move(temp);
}

int main() {
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 5; ++i) {
		v1.push_back(i + 1);
	}
	for (int i = 10; i < 15; ++i) {
		v2.push_back(i + 1);
	}
	printVector(v1);
	printVector(v2);

	//Normal Copy Assignment
	//v2 = v1;
	//Move Copy Assignment
	//v2 = move(v1);
	::Swap(v1, v2);

	printVector(v1);
	printVector(v2);
}
```

```cpp
//Move Constructor and Move Copy Assignment...

#include <iostream>
using namespace std;

class A {
private:
   int* ptrArr;
public:
   A() : ptrArr(new int[5]) {
       for (int i = 0; i < 5; ++i) {
           ptrArr[i] = i + 1;  
       }
       cout << "default constructor called" << endl;
   }

   // Copy Constructor (Deep Copy)
   A(const A& other) : ptrArr(new int[5]) {
       cout << "copy constructor called" << endl;
       for (int i = 0; i < 5; ++i) {
           this->ptrArr[i] = other.ptrArr[i];
       }
   }

   // Move Constructor
   A(A&& other) noexcept : ptrArr(other.ptrArr) {
       cout << "move constructor called" << endl;
       other.ptrArr = nullptr; // Transfer ownership
   }

   // Copy Assignment Operator
   A& operator=(const A& other) {
       cout << "Copy Assignment Overload" << endl;
       if (this != &other) {
           delete[] ptrArr;
           this->ptrArr = new int[5];
           for (int i = 0; i < 5; ++i) {
               ptrArr[i] = other.ptrArr[i];
           }
       }
       return *this;
   }

   // Move Assignment Operator
   //noexcept defines that function can't throw error
   A& operator=(A&& other) noexcept{
       cout << "Move Assignment Overload" << endl;
       if (this != &other) {
           delete[] ptrArr;
           this->ptrArr = other.ptrArr;
           other.ptrArr = nullptr;
       }
       return *this;
   }

   void display() {
       cout << "print call" << endl;
       for (int i = 0; i < 5; ++i) {
           cout << ptrArr[i] << " ";
       }
       cout << endl;
       cout << endl;
   }

   virtual ~A() {
       delete[] ptrArr; 
       cout << "destructor is called" << endl;
   }
};

int main() {
   A a; 
   a.display();

  // Copy constructor
   A b = a; 
   b.display();

  // Move constructor
   A c = move(b); 
   c.display();
   //b.display();

   A d;
   //Copy Assignment
   d = a;
   d.display();

   A e;
   // Move copy assignment
   e = move(a);
   e.display();
}

```

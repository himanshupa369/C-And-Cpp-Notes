 **copy constructor** that supports:

1. ✅ **Shallow copy**
2. ✅ **Deep copy**
3. ✅ **Ownership transfer (move semantics)**

---

## 🔧 Class Setup

We'll use a class with a dynamically allocated integer to demonstrate the three types of copying:

```cpp
#include <iostream>
using namespace std;

class MyClass {
private:
    int* data;
public:
    // Constructor
    MyClass(int val) {
        data = new int(val);
        cout << "Constructor: " << *data << endl;
    }

    // 1️⃣ Shallow Copy Constructor
    MyClass(const MyClass& other, bool shallow) {
        if (shallow) {
            data = other.data;  // Share pointer (BAD)
            cout << "Shallow Copy Constructor\n";
        }
    }

    // 2️⃣ Deep Copy Constructor
    MyClass(const MyClass& other) {
        data = new int(*other.data);  // Copy value
        cout << "Deep Copy Constructor\n";
    }

    // 3️⃣ Move Constructor (Ownership Transfer)
    MyClass(MyClass&& other) noexcept {
        data = other.data;       // Steal pointer
        other.data = nullptr;    // Nullify source
        cout << "Move Constructor\n";
    }

    // Display
    void show() const {
        if (data) cout << "Data: " << *data << endl;
        else cout << "Data: nullptr" << endl;
    }

    // Destructor
    ~MyClass() {
        cout << "Destructor called\n";
        delete data;
    }
};
```

---

## 🧪 Usage in `main()`

```cpp
int main() {
    MyClass original(100);

    // 1. Deep Copy
    MyClass deepCopy(original); // uses regular deep copy constructor
    deepCopy.show();

    // 2. Shallow Copy (unsafe, manual)
    MyClass shallowCopy(original, true); // uses custom shallow copy
    shallowCopy.show();

    // 3. Move (Ownership Transfer)
    MyClass movedObj(std::move(original));
    movedObj.show();
    original.show();  // Should be nullptr

    return 0;
}
```

---

## ⚠️ Notes

| Type            | Safe? | Pros                       | Cons                                |
| --------------- | ----- | -------------------------- | ----------------------------------- |
| Shallow Copy    | ❌ No  | Fast (just copies pointer) | Double free, shared ownership issue |
| Deep Copy       | ✅ Yes | Independent copy           | Slower, needs memory allocation     |
| Move (Transfer) | ✅ Yes | Fast, no copy              | Source becomes null                 |

---



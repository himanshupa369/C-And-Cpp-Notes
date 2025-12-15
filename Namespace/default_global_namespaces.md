
---

# Notes: Default Global Namespace in C++

## 1. What the Global Namespace Is

* Any function, variable, or class **not declared inside a namespace** belongs to the **default global namespace**
* The global namespace does **not have a name**
* It is implicitly present in every C++ program

Example from code:

```cpp
double add(double a, double b){
    return a + b;
}
```

This `add` function lives in the **global namespace**.

---

## 2. User-Defined Namespace

* A namespace groups related code and prevents name conflicts
* Functions inside a namespace can have the **same name and signature** as global functions

Example:

```cpp
namespace My_Thing{
    double add(double a, double b){
        return a + b - 1;
    }
}
```

Here:

* `My_Thing::add` is **different** from global `add`
* Both coexist without conflict

---

## 3. Same Function Name in Global and Namespace Scope

This code contains **two `add` functions**:

| Location             | Function                                    |
| -------------------- | ------------------------------------------- |
| Global namespace     | `add(double, double)` → returns `a + b`     |
| `My_Thing` namespace | `add(double, double)` → returns `a + b - 1` |

The compiler decides **which one to call based on scope resolution**.

---

## 4. Scope Resolution Operator `::`

The `::` operator tells the compiler **where to look** for a name.

### Meaning of `::`

* `::add()` → call `add` from **global namespace**
* `My_Thing::add()` → call `add` from `My_Thing` namespace

---

## 5. Accessing the Global Namespace from Inside a Namespace

Inside `My_Thing::do_something()`:

```cpp
void do_something(){
    double result = ::add(5,6);
    std::cout << "result : " << result << std::endl;
}
```

### What Happens Here

* `::add(5,6)` explicitly tells the compiler:

  > “Use the `add` function from the **global namespace**, not the local one.”

* Result:

```text
5 + 6 = 11
```

---

## 6. What If `::` Is Removed?

If this line is changed to:

```cpp
double result = add(5,6);
```

### Compiler Behavior

* The compiler first looks **inside the current namespace**
* Finds `My_Thing::add`
* Calls it instead of the global one

Result:

```text
5 + 6 - 1 = 10
```

This is called **name hiding**.

---

## 7. Access Priority Rule (Very Important)

When a name is used **without qualification**, C++ searches in this order:

1. Current scope (local / namespace)
2. Enclosing scopes
3. Global namespace (only if `::` is used)

So inside `My_Thing`:

* `add()` → `My_Thing::add`
* `::add()` → global `add`

---

## 8. Accessing Namespace Functions from `main()`

```cpp
int main(){
    My_Thing::do_something();
    return 0;
}
```

Explanation:

* `do_something` is **not in global scope**
* Must be accessed using:

```cpp
My_Thing::do_something();
```

---

## 9. Summary Table

| Call                          | Function Used      |
| ----------------------------- | ------------------ |
| `add(5,6)` (inside namespace) | `My_Thing::add`    |
| `::add(5,6)`                  | Global `add`       |
| `My_Thing::add(5,6)`          | Namespace `add`    |
| `My_Thing::do_something()`    | Namespace function |

---

## 10. Key Takeaways

* Anything outside a namespace lives in the **global namespace**
* `::` with no name explicitly refers to the **global namespace**
* Local namespace names hide global names
* Use `::` to avoid ambiguity and make intent clear
* This behavior is heavily tested in **interviews and exams**

---
```cpp
#include <iostream>

//Global namespace
double add(double a, double b){
    return a + b;
}

namespace My_Thing{
    double add(double a, double b){
        return a + b - 1;
    }
    
    void do_something(){
        //double result = ::add(5,6); // access global namespace 
        double result = add(5,6); //access local namespace
        std::cout << "result : " << result << std::endl;
    }
    
}


int main(){
    My_Thing::do_something();
    return 0;
}
```

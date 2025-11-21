```cpp

#include <iostream>

//function declaration 
//auto max(int& a, int& b);
// this showing error because return type of function is responsible for type deduction but there is no return type.
//just like auto always need to be initialized.
// for this problem trailing return type comes under picture.
auto max(int& a, int& b)->int;

int main(){

    int x{5};
    int y{9};
    int int_val = max(x,y);
    std::cout<<"max value="<<int_val<<std::endl;
    return 0;
}
//Definition without trailing.
auto max(int& a, int& b){
    if(a>b){
        return a;
    }else{
        return b; // Will return a copy.
    }
}
//Definition
auto max(int& a, int& b)->int{
    if(a>b){
        return a;
    }else{
        return b; // Will return a copy.
    }
}

```

---

# ❌ Why Your Code Fails

You wrote:

```cpp
//function declaration 
auto max(int& a, int& b);
```

This is **illegal in C++14/17/20** because:

### 🔥 **Rule:**

You **cannot declare** a function with deduced return type (`auto`) *unless the compiler already knows its definition*.

Return type deduction happens **after seeing the return statements**, but in a **declaration**, the compiler sees NO return statements.

So it errors.

---

# ✔ Solutions

## ✅ **Solution 1: Put function definition before main()**

```cpp
#include <iostream>

auto max(int& a, int& b) {
    if(a > b)
        return a;   // returns int (copy)
    else
        return b;   // returns int (copy)
}

int main() {
    int x{5};
    int y{9};

    int int_val = max(x,y);
}
```

This works because the compiler sees the function body for deduction.

---

## ✅ **Solution 2: Use trailing return type**

If you want a separate declaration, you must specify return type:

```cpp
auto max(int& a, int& b) -> int;
```

Then:

```cpp
auto max(int& a, int& b) -> int {
    if(a > b)
        return a;
    return b;
}
```

---

## ❗BONUS: Why it returns a **copy**?

Because `auto` always deduces **by value**, unless specified as:

* `auto&`
* `const auto&`
* `decltype(auto)`

Your function:

```cpp
auto max(int& a, int& b)
```

→ deduced return type = `int`

So it returns a **copy**, even though the parameters are references.

---

# ✔ Final Summary

| Issue                       | Reason                                           |
| --------------------------- | ------------------------------------------------ |
| `auto max(int&, int&);`     | ❌ Cannot use auto in a declaration-only function |
| Definition after main       | ❌ Compiler cannot deduce return type             |
| Use trailing return type    | ✔ Fix                                            |
| Move definition before main | ✔ Fix                                            |

---


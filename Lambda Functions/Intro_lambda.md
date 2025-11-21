
---

# 📘 **Lambda Functions in C++ — Clean Notes with Examples**

Lambda functions (introduced in **C++11**) are **anonymous inline functions** used for short operations, callbacks, STL algorithms, and functional-style code.

---

# ⭐ **1. Lambda Function Syntax**

A lambda function in C++ has the following structure:

```cpp
[capture_list](parameters) -> return_type {
    // body
};
```

### ✔ Components:

1. **Capture List**

   * Written inside `[ ]`
   * Controls how variables from surrounding scope are captured
   * We cover it later; here we use empty `[]`.

2. **Parameter List**

   * Like function parameters `(int a, double b)`

3. **Return Type (optional)**

   * Compiler auto-deduces return type
   * You can force it using `-> type`

4. **Body**

   * Code executed when lambda is called

5. **Semicolon**

   * Because a lambda is an expression (like creating a variable)

---

# ⭐ **2. Declaring a Lambda Function (No Parameters)**

```cpp
#include <iostream>

int main() {

    auto func = []() {
        std::cout << "Hello World\n";
    };

    func();     // calling lambda
    func();     // can call multiple times

    return 0;
}
```

### 📌 Notes:

* `auto` deduces the lambda's type.
* Lambda is called exactly like a normal function.

---

# ⭐ **3. Calling a Lambda *Without* Giving It a Name**

```cpp
[](){
    std::cout << "Hello from direct call!\n";
}();   // parentheses = calling the lambda
```

This is used when the lambda is needed only once.

---

# ⭐ **4. Lambda Function with Parameters**

```cpp
[] (double a, double b) {
    std::cout << "Sum: " << (a + b) << "\n";
}(10.5, 5.5);
```

Or with a name:

```cpp
auto add = [](double a, double b) {
    return a + b;
};

std::cout << add(10, 20) << "\n";   // 30
```

---

# ⭐ **5. Lambda Returning a Value**

### ✔ Direct call returning value:

```cpp
auto result = [](int a, int b) {
    return a + b;
}(23, 7);

std::cout << result << "\n";    // 30
```

---

# ⭐ **6. Lambda Inside `std::cout`**

```cpp
std::cout << [](int a, int b){
    return a + b;
}(5, 2) << "\n";     // prints 7
```

---

# ⭐ **7. Explicit Return Type in Lambda**

Sometimes the return is ambiguous; then we specify type:

```cpp
auto func = [](double a, double b) -> int {
    return a + b;    // sum (double) converted to int
};
```

Example demonstration:

```cpp
double a = 6.9;
double b = 3.5;

auto func_int = [](double x, double y) -> int {
    return x + y;    // returns int
};

auto func_double = [](double x, double y) {
    return x + y;    // deduced as double
};

int result1 = func_int(a, b);
double result2 = func_double(a, b);

std::cout << result1 << "\n";      // 10 (converted)
std::cout << result2 << "\n";      // 10.4 (precise)
```

---

# ⭐ **8. Summary (Perfect for GitHub README)**

| Concept              | Explanation             | Example           |
| -------------------- | ----------------------- | ----------------- |
| Basic lambda         | Inline unnamed function | `[](){}`          |
| With parameters      | Like normal function    | `[](int x){}`     |
| With name            | Use `auto`              | `auto f = [](){}` |
| Direct call          | No name needed          | `[](){ }();`      |
| Returning values     | Allowed, auto deduced   | `return a+b;`     |
| Explicit return type | Using `-> type`         | `-> int`          |
| Multiple calls       | Give it a name          | `func(); func();` |

---

# ⭐ **9. Minimal Quick Reference Code**

```cpp
auto f1 = [](){ std::cout << "Hello\n"; };

auto f2 = [](int x){ return x * 2; };

auto f3 = [](double x, double y) -> int { return x + y; };

[](){ std::cout << "Direct call\n"; }();

std::cout << f2(10);
```

---


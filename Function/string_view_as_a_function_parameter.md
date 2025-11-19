```cpp
#include <iostream>
#include<string>
#include<string_view>
void print_string(std::string& str){
	std::cout << "string  : " << str << std::endl;
}
void print_string_view(std::string_view str){
	std::cout << "string  : " << str << std::endl;
}
void print_string_const(const std::string& str){
	std::cout << "string  : " << str << std::endl;
}
int main(){
    std::string s{"sunny was funny"};
    //print_string(s); // work fine
    //print_string("sunny was funny"); //temp data not bind with non const references
    //print_string_view("sunny was funny"); // work fine
    //print_string_view(s); //work fine
    //print_string_view(std::string_view("sunny was funny")); //work fine
    //print_string(std::string_view("sunny was funny")); //error
    //print_string_const(s); // work fine
    
    
   
    return 0;
}
```
---

# ✅ **Explanation of Each Function Call (Why it Works or Fails)**

Your functions:

```cpp
void print_string(std::string& str);             // NON-const lvalue reference
void print_string_view(std::string_view str);    // string_view value parameter
void print_string_const(const std::string& str); // CONST lvalue reference
```

---

# ✔ 1. `print_string(s);`

```cpp
print_string(s); // works fine
```

**Reason:**

* `s` is a `std::string` (lvalue).
* Function needs `std::string&` (non-const lvalue reference).
* Perfect match.

---

# ❌ 2. `print_string("sunny was funny");`

```cpp
print_string("sunny was funny");
```

**Fails**
Because:

* `"sunny was funny"` is a **string literal** → type: `const char[ ]`
* Compiler must convert it into a **temporary `std::string`**
* You cannot bind a **temporary** to a **non-const** reference (`std::string&`)

✔ Temporary can bind to:

* `const std::string&` (allowed)

❌ Temporary cannot bind to:

* `std::string&` (your parameter) → **compile error**

---

# ✔ 3. `print_string_view("sunny was funny");`

```cpp
print_string_view("sunny was funny"); // works fine
```

**Reason:**

* `"literal"` → directly becomes a `string_view` (no allocation, no copy).
* `string_view` is designed to bind to string literals.

---

# ✔ 4. `print_string_view(s);`

```cpp
print_string_view(s); // works fine
```

**Reason:**

* `std::string` has an **implicit conversion** to `std::string_view`.
* So this call is valid.

---

# ✔ 5. `print_string_view(std::string_view("sunny was funny"));`

```cpp
print_string_view(std::string_view("sunny was funny")); // works fine
```

**Reason:**

* You directly pass a `std::string_view`.
* The function accepts a `string_view` directly.
* Always valid.

---

# ❌ 6. `print_string(std::string_view("sunny was funny"));`

```cpp
print_string(std::string_view("sunny was funny")); // error
```

### **Why error?**

* Parameter type = `std::string&`
* Argument type = `std::string_view`

Compiler tries to convert:

```
string_view → string
```

But **this conversion exists ONLY as an explicit constructor:**

```cpp
explicit std::string(std::string_view);
```

❌ Explicit constructors are not used for implicit conversions.
❌ So compiler cannot convert string_view → string → bind to string&.

Hence, the call fails.

---

# ✔ 7. `print_string_const(s);`

```cpp
print_string_const(s); // works fine
```

**Reason:**

* `s` is a `std::string`
* Parameter is `const std::string&`
* Perfect match

---

# 📌 **Final Summary Table**

| Call                                  | Works? | Reason                                 |
| ------------------------------------- | ------ | -------------------------------------- |
| `print_string(s)`                     | ✔      | exact match (`string&`)                |
| `print_string("literal")`             | ❌      | temporary cannot bind to non-const ref |
| `print_string_view("literal")`        | ✔      | literal → `string_view`                |
| `print_string_view(s)`                | ✔      | `string` → `string_view` conversion    |
| `print_string_view(string_view(...))` | ✔      | direct type match                      |
| `print_string(string_view(...))`      | ❌      | no implicit conversion to `string`     |
| `print_string_const(s)`               | ✔      | exact match (`const string&`)          |

---

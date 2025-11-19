```cpp
#include<iostream>
#include<string_view>

enum class Month{
Jan,Feb,Mar,Apr,May,Jun,July,Aug,Sep,Oct,Nov,Dec
};

std::string_view enum_month(Month mnth){
    switch(mnth){
        // case Month::Jan : return "January";
        // case Month::Feb : return "February";
        // case Month::Mar : return "March";
        // case Month::Apr : return "April";
        // case Month::May : return "May";
        // case Month::Jun : return "June";
        // case Month::July: return "July";
        // case Month::Aug : return "August";
        // case Month::Sep : return "September";
        // case Month::Oct : return "October";
        // case Month::Nov : return "November"; 
        // case Month::Dec : return "December";
        // default: return "NULL";
        using enum Month;
        case Jan : return "January";
        case Feb : return "February";
        case Mar : return "March";
        case Apr : return "April";
        case May : return "May";
        case Jun : return "June";
        case July: return "July";
        case Aug : return "August";
        case Sep : return "September";
        case Oct : return "October";
        case Nov : return "November"; 
        case Dec : return "December";
        default: return "NULL";
    }
}
int main(){
    Month mnth{Month::July};
    // using enum Month;
    // Month mnth{July};
    std::cout<<"Month is "<<enum_month(mnth)<<std::endl;
}

```


---

# ✅ **What is `using enum` in C++20?**

`using enum` is a **C++20 feature** that allows you to *import* all enumerators of an enum into the current scope **without qualifying them**.

Before C++20, to use an enum class, you had to write:

```cpp
Color c = Color::Red;
```

But with `using enum Color;`, you can write:

```cpp
Color c = Red;
```

This keeps `enum class` safety but removes the verbosity.

---

# ✅ **Why do we need it?**

* `enum class` is strongly typed → requires scope prefix (`Color::Red`)
* Sometimes code becomes long and repetitive
* `using enum` improves readability while keeping type safety

---

# ✅ **Basic Example**

### Without `using enum`:

```cpp
enum class Color { Red, Green, Blue };

void paint(Color c) {}

int main() {
    paint(Color::Red);
    paint(Color::Green);
}
```

### With `using enum` (C++20):

```cpp
enum class Color { Red, Green, Blue };

void paint(Color c) {}

int main() {
    using enum Color;  // Import enumerators into scope

    paint(Red);
    paint(Green);
}
```

✔ Much cleaner
✔ Still strongly typed
✔ Still scoped properly

---

# ✅ **Works Only for enum class?**

No — it works for both:

### ✔ enum class

### ✔ traditional enum

But the main benefit is for **enum class** since they require scoped access.

---

# ✅ **Where can you use `using enum`?**

### 1️⃣ **Inside a function**

```cpp
void f() {
    using enum Color;
    auto c = Green;
}
```

### 2️⃣ **Inside a class**

```cpp
class A {
    using enum Color;
};
```

### 3️⃣ **Inside namespaces**

### 4️⃣ **In switch statements**

This is extremely useful.

---

# 🚀 **Best Use-Case: switch() with enum class**

Before:

```cpp
switch(color) {
    case Color::Red: break;
    case Color::Green: break;
    case Color::Blue: break;
}
```

After using enum (C++20):

```cpp
switch(color) {
    using enum Color;
    case Red: break;
    case Green: break;
    case Blue: break;
}
```

✔ Cleaner
✔ No loss of type safety
✔ Compiler still checks all cases

---

# ⚠️ **Restrictions / Rules**

### 1️⃣ Must refer to an enum **type**, not a namespace

Correct:

```cpp
using enum Color;
```

Incorrect:

```cpp
using enum someNamespace; // ❌
```

---

### 2️⃣ You still cannot implicitly convert to int

```cpp
using enum Color;
int x = Red; // ❌ Still not allowed
```

`enum class` rules still apply.

---

# ✔ Full Example Demonstrating Everything

```cpp
#include <iostream>

enum class Status {
    Ok,
    Warning,
    Error
};

void handle(Status s) {
    using enum Status;  // Import enum values

    switch(s) {
        case Ok: 
            std::cout << "Everything fine\n"; 
            break;
        case Warning: 
            std::cout << "Something seems off\n"; 
            break;
        case Error: 
            std::cout << "System failure!\n"; 
            break;
    }
}

int main() {
    handle(Status::Ok);
    handle(Status::Warning);
}
```

---

# 📌 Summary (GitHub-Ready)

```
# using enum (C++20)

- Introduced in C++20
- Allows importing all enumerators of an enum into current scope
- Works for both enum and enum class
- Makes code cleaner, especially switch statements
- Keeps strong typing of enum class

### Example
enum class Color { Red, Green, Blue };

using enum Color;

Color c = Red;   // OK
```

---

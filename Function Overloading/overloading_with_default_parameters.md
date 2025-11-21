```cpp

#include <iostream>

//Declarations
void print_age(int age = 33);

void print_age(long int age = 44);

int main(){


    print_age();
    
    
    return 0;
}

//Definitions
void print_age(int age ){
    std::cout << "Your age is( int version)  : " << age << std::endl;
}

void print_age(long int age){
    std::cout << "Your age is (long int version) : " << age << std::endl;
}
```


---

# ⭐ Function Overloading with Default Parameters in C++

Function overloading becomes **dangerous** when combined with **default parameters**.
This is because the compiler may **not know which overload to choose** when no argument is provided.

---

# ❗ Why is this a Problem?

Consider these two overloads:

```cpp
void print_age(int age = 33);
void print_age(long int age = 44);
```

These overloads are **valid**, because `int` and `long int` are different types.

But when you call:

```cpp
print_age();
```

You did **not** provide an argument, so the compiler tries to use the default one.

Now the problem:

* Both overloads can be called with **zero arguments**.
* Both have valid default values.
* The compiler cannot decide whether to use `int` or `long int`.

➡️ **Result: Compilation Error − Ambiguous Function Call**

---

# 💡 Fixing the Ambiguity

You must pass an argument so that the compiler knows which overload to call:

```cpp
int h = 67;
print_age(h);      // calls int version

long int lh = 67;
print_age(lh);     // calls long version
```

---

# ✔ Corrected & Formatted Code

```cpp
#include <iostream>

// Declarations
void print_age(int age = 33);
void print_age(long int age = 44);

int main() {

    // ❌ Ambiguous — both overloads have default arguments
    // print_age();  

    int h = 67;
    print_age(h);       // ✔ Calls int version

    long int lh = 67;
    print_age(lh);      // ✔ Calls long int version

    return 0;
}

// Definitions
void print_age(int age) {
    std::cout << "Your age is (int version)       : " << age << std::endl;
}

void print_age(long int age) {
    std::cout << "Your age is (long int version) : " << age << std::endl;
}
```

---

# 📌 Key Takeaways (Perfect for GitHub README)

* Overloading + default parameters can easily confuse the compiler.
* If two overloads can be called **without arguments**, the call becomes **ambiguous**.
* You must **avoid default parameters** in overload sets **OR** make your calls explicit.
* The compiler resolves overloads based on the **argument you actually pass**, not the default one.

---

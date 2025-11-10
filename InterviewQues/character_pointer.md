
---

## 🧩 **1️⃣ Basic Example**

```cpp
#include <iostream>

int main() {
    char ch = 'A';      // a normal character variable
    char* ptr = &ch;    // store address of ch in a pointer

    std::cout << "ch : " << ch << std::endl;
    std::cout << "Address of ch : " << static_cast<void*>(ptr) << std::endl;
    std::cout << "Value via pointer : " << *ptr << std::endl;
}
/*
Example :-
#include <iostream>
int main() {
     const char* msg = "Hello World!";
     int a=5;
     int* ptr=&a;
    std::cout << msg << std::endl; // prints "Hello World!"
    std::cout<< ptr<< std::endl; // prints address of int.

    // if you want to print address of character use static_cast
    std::cout<< static_cast<const void*>(msg)<<std::endl;
    return 0;
}

*/
```

---

### 🧠 **Explanation**

| Variable | Type    | Value           | Meaning                |
| -------- | ------- | --------------- | ---------------------- |
| `ch`     | `char`  | `'A'`           | A character variable   |
| `ptr`    | `char*` | Address of `ch` | Pointer to a character |

✅ `ptr = &ch` stores the **memory address** of `ch`.

✅ `*ptr` dereferences the pointer — gives `'A'`.

---

### ⚠️ **Important:** Printing Addresses of `char*`

If you print a `char*` directly using `std::cout`, C++ assumes it’s a **C-string** and will try to print all characters until it finds a null terminator `'\0'`.

So this:

```cpp
std::cout << ptr;   // ❌ Dangerous
```

will **not print the address**, but instead may print:

```
A or random garbage
```

✅ Correct way to print the address:

```cpp
std::cout << static_cast<void*>(ptr);
```

---

## 🧩 **2️⃣ Character Array Example**

You can also take the address of elements in a character array:

```cpp
#include <iostream>

int main() {
    char name[] = "John";

    char* p1 = &name[0];   // Address of first character
    char* p2 = name;       // Same as above (array decays to pointer)

    std::cout << "First character: " << *p1 << std::endl;
    std::cout << "Whole string: " << p2 << std::endl;
}
```

🟢 Output:

```
First character: J
Whole string: John
```

✅ `p1` points to `'J'`
✅ `p2` points to start of the string `"John"`

---

## 🧩 **3️⃣ Why Printing `char*` Prints a String**

Because `std::cout` treats `char*` as a **C-string** pointer, meaning it will print from that address until it finds `'\0'`.

For example:

```cpp
char ch = 'A';
char* ptr = &ch;

std::cout << ptr; // ❌ Undefined behavior (no '\0')
```

👉 It will keep printing random memory contents until it finds a `'\0'`.

That’s why you should always use:

```cpp
std::cout << static_cast<void*>(ptr);  // ✅ prints address safely
```

---

## 🧩 **4️⃣ Storing Address of `const char` (String Literal)**

String literals like `"Hello"` are **constant character arrays**.
You can store their address using a `const char*`.

```cpp
#include <iostream>

int main() {
    const char* msg = "Hello World!";
    std::cout << msg << std::endl; // prints "Hello World!"
}
```

🧠 `msg` points to the **first character** (`'H'`) of a constant string stored in memory.

---

## 🧩 **5️⃣ Summary Table**

| Declaration                         | Meaning                           | Can Modify Data? | Prints as                   |
| ----------------------------------- | --------------------------------- | ---------------- | --------------------------- |
| `char ch = 'A'; char* p = &ch;`     | Pointer to char variable          | ✅ Yes            | Garbage if printed directly |
| `char arr[] = "Hi"; char* p = arr;` | Pointer to first element of array | ✅ Yes            | String (“Hi”)               |
| `const char* p = "Hello";`          | Pointer to string literal         | ❌ No             | String (“Hello”)            |
| `void* p = &ch;`                    | Generic pointer                   | ✅ N/A            | Address only                |

---

## 🧩 **6️⃣ Pro Tip: Using `std::string`**

In modern C++, instead of working with raw character pointers, prefer using `std::string`:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string word = "ChatGPT";
    const char* ptr = word.c_str(); // get address of internal C-string

    std::cout << "word: " << word << std::endl;
    std::cout << "Address: " << static_cast<const void*>(ptr) << std::endl;
}
```

✅ Safe
✅ Readable
✅ Modern C++ style

---

## 🧩 **Summary**

| Concept                               | Example                    | Output / Behavior                                 |
| ------------------------------------- | -------------------------- | ------------------------------------------------- |
| Store address of single char          | `char* p = &ch;`           | Must use `static_cast<void*>(p)` to print address |
| Store address of first char in string | `char* p = name;`          | Safe to print string                              |
| Store address of string literal       | `const char* p = "Hello";` | Safe to print                                     |
| Dereference pointer                   | `*p`                       | Gives the character itself                        |
| Print address safely                  | `static_cast<void*>(p)`    | Avoids string interpretation                      |

---

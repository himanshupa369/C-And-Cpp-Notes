
---

# ✅ **`"\n"` vs `std::endl` in C++**

## ⭐ **1. `"\n"` — Newline Character**

* It **only inserts a newline**.
* It **does NOT flush** (empty) the output buffer.
* Faster than `std::endl`.

### ✔ Example:

```cpp
std::cout << "Hello\n";
```

This just moves to the next line — nothing else.

---

## ⭐ **2. `std::endl` — Newline + Flush**

* Inserts a newline **AND**
* **flushes the output buffer** (forces immediate output).

### ✔ Example:

```cpp
std::cout << "Hello" << std::endl;
```

This:

1. Writes a newline.
2. Flushes the stream → slower.

---

# ⭐ When does flushing matter?

### ✔ Critical cases:

* Logging real-time output.
* Debugging: ensuring output appears before a crash.
* Interactive console programs (e.g., waiting for user input).

### ❌ Not needed in:

* Normal printing (loops, large output, etc.)

---

# ⚡ Performance Difference

Using `std::endl` too often (especially inside loops) is slower because flushing forces I/O to happen immediately.

### Example (slow):

```cpp
for(int i = 0; i < 1000000; i++)
    std::cout << i << std::endl;   // each iteration flushes output
```

### Faster:

```cpp
for(int i = 0; i < 1000000; i++)
    std::cout << i << "\n";        // no flushing
```

---

# 🎯 **Final Summary**

| Feature        | `"\n"`            | `std::endl`                                      |
| -------------- | ----------------- | ------------------------------------------------ |
| Adds newline   | ✔ Yes             | ✔ Yes                                            |
| Flushes buffer | ❌ No              | ✔ Yes                                            |
| Performance    | Fast              | Slower                                           |
| When to use    | For normal prints | For critical output that must appear immediately |

---

In C++, the backslash `\` before a double quote `"` is used as an **escape character**.
It tells the compiler:

> “This character is not a delimiter — treat it as part of the string.”

---

# ✅ **Why do we need `\"`?**

A string in C++ is written inside double quotes:

```cpp
"Hello"
```

If you want to include **another double quote** *inside* the string, it would break the string:

❌ Invalid:

```cpp
std::cout << "He said "Hello"";   // ERROR
```

The compiler gets confused.

---

# ⭐ Solution: Use the escape sequence `\"`

✔ Correct:

```cpp
std::cout << "He said \"Hello\""; 
```

Output:

```
He said "Hello"
```

The backslash tells C++:

* `\"` is not the end of the string
* It is a literal **"** character

---

# 📌 Complete List of Common Escape Sequences in C++

| Escape | Meaning                |
| ------ | ---------------------- |
| `\"`   | Double quote character |
| `\'`   | Single quote           |
| `\\`   | Backslash              |
| `\n`   | New line               |
| `\t`   | Tab                    |
| `\r`   | Carriage return        |
| `\b`   | Backspace              |
| `\0`   | Null character         |

---

# ✔ Example using multiple escaped quotes

```cpp
std::string text = "\"C++\" is fun!";
std::cout << text;
```

Output:

```
"C++" is fun!
```

---

# 🎯 Summary

* `\` is an **escape character**.
* `\"` lets you print `" "` inside strings.
* Required because strings are enclosed in double quotes.

---

---

# ✅ **Escape Sequences in C++**

Escape sequences start with a **backslash `\`** and represent characters that cannot be typed directly or have special meaning.

| Escape Sequence | Meaning         | ASCII Code (Hex) | Description                                                        |
| --------------- | --------------- | ---------------- | ------------------------------------------------------------------ |
| **'**           | Single quote    | `0x27`           | Used to print a single quote inside a character or string literal. |
| **"**           | Double quote    | `0x22`           | Used to print a double quote inside a string literal.              |
| **?**           | Question mark   | `0x3F`           | Avoids trigraph issues (rarely needed today).                      |
| **\**           | Backslash       | `0x5C`           | Prints a single backslash.                                         |
| **\a**          | Audible bell    | `0x07`           | Triggers a beep sound (if terminal supports it).                   |
| **\b**          | Backspace       | `0x08`           | Moves cursor one position back.                                    |
| **\f**          | Form feed       | `0x0C`           | Moves to next page (used in old printers).                         |
| **\n**          | New line        | `0x0A`           | Moves cursor to next line (line feed).                             |
| **\r**          | Carriage return | `0x0D`           | Moves cursor to beginning of the current line.                     |
| **\t**          | Horizontal tab  | `0x09`           | Prints a tab space (same as pressing Tab).                         |
| **\v**          | Vertical tab    | `0x0B`           | Moves cursor vertically down (rarely used).                        |

---

# 🔍 **Short Explanations with Examples**

### **1. ' (Single Quote)**

Used inside character or string.

```cpp
cout << '\'';   // prints '
```

### **2. " (Double Quote)**

Required to print quotes inside a string.

```cpp
cout << "He said \"Hello\"";
```

### **3. ? (Question Mark)**

Used to avoid trigraph confusion (obsolete today).

### **4. \ (Backslash)**

Prints a single backslash.

```cpp
cout << "C:\\Users\\Himanshu";
```

---

# 🔔 Control Characters

### **5. \a — Audible Bell**

```cpp
cout << "\a";   // beep sound (if supported)
```

### **6. \b — Backspace**

```cpp
cout << "Hello\b";  // prints "Hell"
```

### **7. \f — Form Feed**

Used by old printers — rarely used now.

### **8. \n — New Line**

Moves to the next line.

```cpp
cout << "Hello\nWorld";
```

### **9. \r — Carriage Return**

Returns cursor to the beginning of the line.

```cpp
cout << "Hello\rHi"; // prints "Hi"
```

### **10. \t — Horizontal Tab**

```cpp
cout << "Hello\tWorld";  // Hello   World
```

### **11. \v — Vertical Tab**

Very rarely used.

```cpp
cout << "Hello\vWorld";
```

---

# ✔ Summary

Escape sequences help you:

* Print special characters (`\'`, `\"`, `\\`)
* Control terminal behavior (`\n`, `\r`, `\t`)
* Represent non-printable ASCII characters (`\a`, `\b`, `\v`, etc.)

---

# 📘 **Notes: Copied Strings in C++ & Their Problems**

## 🔶 1. What is a Copied String?

When you write:

```cpp
std::string message = "Hello World";
std::string message_copy = message;
```

You are creating:

* **Two completely separate `std::string` objects**
* Each holds **its own copy** of the characters
* Both live at **different locations in memory**

---

# ❗ Problem 1: **Memory Waste**

### ➤ Each string stores its own buffer

If `message` stores 10,000 characters, then copying it means:

* `message` → 10,000 bytes
* `message_copy` → 10,000 bytes
* Total = **20,000 bytes**

This is wasteful when you only want to **read** the same string.

### Example:

```cpp
std::string big = "...10,000 chars...";
std::string copy = big;  // Expensive!
```

If your program copies large strings many times, RAM usage increases drastically.

---

# ❗ Problem 2: **Extra CPU Time During Copying**

Copying a string requires:

* allocating new memory
* copying each character

This is **O(n)** every time a copy happens.

---

# ❗ Problem 3: **Separate Memory Locations**

Even though `message` and `message_copy` contain the **same text**, they are physically different.

You can prove this using `.data()`:

```cpp
char* p1 = message.data();
char* p2 = message_copy.data();
```

Both pointers will show **different addresses** when printed.

---

# ✔ Solution: Use **References** Instead of Copies

```cpp
std::string message = "Hello";
std::string& message_copy = message;
```

A reference:

* **Does not create a new string**
* Just provides another name for the same object
* Both variables refer to **one single memory location**

---

# 🧠 How to Print the Address?

Problem:
`std::cout << p1;` prints the **string itself**, not the pointer address, because it's a `char*`.

Solution:

Cast to `void*`:

```cpp
std::cout << "(void*)p1";
```

This prevents `std::cout` from treating it as a C-string.

---

# ✅ Your Code Explained

### Code:

```cpp
std::string message {...};
std::string& message_copy {message};

char * p1 = message.data();
char * p2 = message_copy.data();

std::cout << "&message[0] : " << (void*)p1 << std::endl;
std::cout << "&message_copy[0] : " << (void*) p2 << std::endl;
```

### What this shows:

* `message_copy` is a **reference**
* No new string was created
* **Both addresses will be identical**

**Output example:**

```
&message[0]      : 0x7ffd526e7030
&message_copy[0] : 0x7ffd526e7030
```

They point to the **same memory** → No memory waste.

---

# 📝 Summary Table

| Concept                       | Behavior                           | Memory Use | CPU Cost  |
| ----------------------------- | ---------------------------------- | ---------- | --------- |
| `std::string copy = original` | Deep copy                          | ❌ High     | ❌ High    |
| `std::string& ref = original` | Reference                          | ✔ Minimal  | ✔ Minimal |
| `.data()`                     | Shows character buffer             | —          | —         |
| Casting to `(void*)`          | Prints address instead of C-string | —          | —         |

---

# ⭐ Key Takeaways

1. Copying large strings wastes memory and CPU.
2. `std::string` always deep-copies its buffer.
3. Use **references** when you only need another name for the same string.
4. `.data()` returns pointer to underlying buffer.
5. Cast to `(void*)` to print addresses.
6. For string literals, even references still copy data — use `std::string_view` (next topic).

---


---

# ✅ What is `std::string_view`?

`std::string_view` is a **lightweight, non-owning view** into an existing string (literal, `std::string`, C-string, char array).

* It **does not allocate memory**.
* It **does not copy** characters.
* It stores **only two things** internally:
* Header  #include<string_view> is used.

  * A `const char*` pointer
  * A `size_t` length

So it is generally **16 bytes** on 64-bit systems.

---

# ✅ Why `string_view` Exists

When you do:

```cpp
std::string s = "Hello";   // copy happens
std::string s1 = s;        // copy
std::string s2 = s;        // copy
```

You get *three separate strings* in memory — wasteful, especially for large strings.

With `std::string_view`:

```cpp
std::string_view sv = "Hello";
std::string_view sv1 = sv;
std::string_view sv2 = sv;
```

All of them just **point to the same memory** → no copies.

---

# ✅ Key Properties

### ✔ No allocation

### ✔ No ownership

### ✔ Very small object

### ✔ Efficient for passing read-only strings

### ❌ Cannot modify the data

### ❌ Dangerous if original string is destroyed

---

# ⚠ Important Rule:

## **A string_view must not outlive the data it points to**

Example (dangerous):

```cpp
std::string_view sv;
{
    std::string temp = "Hello";
    sv = temp;      // OK (for now)
}                   // temp is destroyed
std::cout << sv;    // ❌ Undefined behaviour
```

The `string` died, but the view remains.

---

# 🔍 Viewing Different Sources

You can construct a `string_view` from:

### ✔ String literal (always safe)

```cpp
std::string_view sv = "Hello";
```

### ✔ std::string (safe only while string lives)

```cpp
std::string s = "Hi";
std::string_view sv = s;
```

### ✔ C-string

```cpp
const char* c = "Hello";
std::string_view sv = c;
```

### ✔ char array

```cpp
char arr[] = "Hello";
std::string_view sv = arr;
```

### ✔ Non-null-terminated array (must specify size!)

```cpp
char arr[] = {'H','i','!'};
std::string_view sv(arr, 3);
```

---

# 🔎 Changes to Original String Are Visible

```cpp
char word[] = "Dog";
std::string_view sv = word;

word[2] = 't';
std::cout << sv;    // "Dot"
```

Because a view is **not a copy**.

---

# 🔧 Shrinking the View: `remove_prefix` / `remove_suffix`

```cpp
std::string_view sv = "The animals have left the region";
sv.remove_prefix(4);  // removes "The "
sv.remove_suffix(10); // removes " the region"
```

`string_view` now shows:

```
animals have left
```

Original string is untouched.

---

# ⚠ `data()` Can Be Dangerous After Modifying the View

Example:

```cpp
std::string_view sv = "Ticket";
sv.remove_prefix(2); // "cket"
sv.remove_suffix(2); // "ck"

std::cout << sv;             // "ck"
std::cout << strlen(sv.data()); // ❌ may print garbage length
```

Because `data()` still points inside the original literal `"Ticket"`,
so `strlen()` keeps reading until it finds a null terminator.

---

# ❌ Do NOT Use `string_view` on Non-null-terminated Arrays Without Size

This is wrong:

```cpp
char arr[] = {'H','e','l','l','o'};
std::string_view sv = arr;    // ❌ undefined behaviour
```

Because `strlen(arr)` will keep reading past bounds.

Correct:

```cpp
std::string_view sv(arr, 5);  // ✔ safe
```

---

# ⭐ Final Summary Cheat Sheet

### Use `string_view` when:

* You want efficient read-only string access
* You don’t want copies
* You are passing strings into functions

### Do NOT use `string_view` when:

* The source string will be destroyed soon
* You need to store the string long-term
* You need to modify the string
* The underlying data is not null terminated (unless length is provided)
* You rely on `data()` after modifying the view

```cpp
#include <iostream>
#include <string_view>
#include <cstring>


int main(){

    //Showing the problem
    /*
    std::string string {"Hello"};
    std::string string1 {string}; // Copy
    std::string string2 {string}; // Copy
    
    std::cout  << "address of string : " <<  &string << std::endl;
    std::cout  << "address of string1 : " <<  &string1 << std::endl;
    std::cout  << "address of string2 : " <<  &string2 << std::endl;
    */


   //Using string_view
   /*
    std::string_view sv {"Hellooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"};
    std::string_view sv1 {sv}; // View viewing the hello literal
    std::string_view sv2 {sv1}; // Another view viewing hello 
    
    std::cout << "Size of string_view : " << sizeof(std::string_view) << std::endl;
    std::cout << "size of sv1 : " << sizeof(sv1) << std::endl;
    
    std::cout << "sv : " << sv << std::endl;
    std::cout << "sv1 : " << sv1 << std::endl;
    std::cout << "sv2 : " << sv2 << std::endl;
    */


   //Constructing string_view's
   /*
    std::string string3 {"Regular std::string"};
    const char * c_string {"Regular C-String"};
    const char char_array[]{"Char array"}; // Null terminated
    char char_array2[]{'H','u','g','e'}; // Non null terminated char array

    std::string_view sv3{"String litteral"};
    std::string_view sv4{string3};
    std::string_view sv5{c_string};
    std::string_view sv6{char_array};
    std::string_view sv7{sv3}; 
    std::string_view sv8{char_array2,std::size(char_array2)};//Non null terminated char array
                                                             //Need to pass in size info
    std::cout << "sv3 : " << sv3 << std::endl;
    std::cout << "sv4 : " << sv4 << std::endl;
    std::cout << "sv5 : " << sv5 << std::endl;
    std::cout << "sv6 : " << sv6 << std::endl;
	std::cout << "sv7 (constructed from other string_view) : " << sv7 << std::endl;
    std::cout << "Non null terminated string with std::string_view : " << sv8 << std::endl;
    */

   //Changes to the original string are reflected in the string_view
   /*
    char word [] {"Dog"};
    std::string_view sv9{word};
    
    std::cout << "word : " << sv9 << std::endl;
    
	std::cout << "Changing data... " << std::endl;
    //Change the data
    word[2] = 't';
    
    std::cout << "word : " << sv9 << std::endl;
    */

   //Changing the view window : SHRINKING
   /*
    const char * c_string1 { "The animals have left the region" };
    std::string_view sv10{c_string1};
    
    std::cout << "sv10 : " << sv10 << std::endl;
    
    sv10.remove_prefix(4); // Removes "The"
    
	//Prints : animals have left the region
    std::cout << "View with removed prefix(4) : " << sv10 << std::endl;
    
    sv10.remove_suffix(10); // Removes "the region"
    
	//Prints : animals have left
    std::cout << "View with removed suffix(10) : " << sv10 << std::endl;
    
    //Changing the view doesn't change the viewed string : 
    std::cout << "Original sv10 viewed string : " << c_string1 << std::endl;
    */


   //String_view shouldn't outlive whatever it is viewing
   /*
    std::string_view sv11;
    
    {
        std::string string4{"Hello there"};
        sv11 = string4;
        std::cout << "INSIDE --- sv11 is viewing : " << sv11 << std::endl;
        
        
        //string4 goes out of scope here.
    }
    std::cout << "OUTSIDE --- sv1 is viewing : " << sv11 << std::endl;
    */


   //data
   /*
    std::string_view sv13 {"Ticket"};
    std::cout << "sv13 : " << sv13 << std::endl;
    std::cout << "std::strlen(sv13.data()) : " << std::strlen(sv13.data()) << std::endl;
    */


   //Don't use data() on a modified view (through remove_prefix or remove_suffix)
   /*
	std::string_view sv14 {"Ticket"};
    sv14.remove_prefix(2);
    sv14.remove_suffix(2);
    
    //Length info is lost when you modify the view
    std::cout << sv14 << " has " << std::strlen(sv14.data()) << " characters(s)" << std::endl;
    std::cout << "sv14.data() is " << sv14.data() << std::endl;
    std::cout << "sv14 is " << sv14 << std::endl;
    */


   //Don't view non null terminated strings
   /*
    char char_array3[] {'H','e','l','l','o'};
    std::string_view sv15 {char_array3,std::size(char_array3)};
    
    std::cout << sv15 << " has " << std::strlen(sv15.data()) << " characters(s)" << std::endl;
    std::cout <<"sv15.data is  : " <<  sv15.data() << std::endl;
    std::cout << "sv15 is : " << sv15 << std::endl;
    */


   //std::string behaviors
	std::string_view sv16{"There is a huge forest in that area"};
    
    std::cout << "sv16 is " << sv16.length() << " characters long" << std::endl;
    std::cout << "The front character is : " << sv16.front() << std::endl;
    std::cout << "The back character is : " << sv16.back() << std::endl;
    std::cout << "Substring : " << sv16.substr(0,22) << std::endl;


    return 0;
}

```
---


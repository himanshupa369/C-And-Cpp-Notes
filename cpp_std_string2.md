
---

# ✅ 1. All Ways to Access Characters in `std::string`

## **1. Array‐index operator `[]`**

```cpp
str[i]
```

* Fastest way
* **No bounds checking**
* Accessing out-of-range index = **undefined behavior**

Example:

```cpp
std::cout << str[0];
```

---

## **2. `.at(index)` method**

```cpp
str.at(i)
```

* Same as indexing but with **bounds checking**
* Throws `std::out_of_range` if index is invalid

Example:

```cpp
std::cout << str.at(1);
```

---

## **3. Range-based for loop**

```cpp
for(char c : str)
    std::cout << c;
```

* Easiest way
* Automatic iteration through entire string

---

## **4. `.front()` and `.back()`**

* Access first and last characters

```cpp
str.front()   // first character
str.back()    // last character
```

Both return **references**, so modifying them changes the string.

---

## **5. `.c_str()`**

```cpp
const char* p = str.c_str();
```

* Gives **read-only** C-string (null-terminated)
* **Cannot modify** it

---

## **6. `.data()`**

Two versions:

* C++11–C++17 → returns **const char***
* C++17 and later → returns **char*** (modifiable)

Used to access internal memory.

Example:

```cpp
char* p = str.data();  // modifiable in C++17+
p[0] = 'B';            // modifies original string
```

---

---

# ✅ 2. Now let’s explain YOUR FINAL CODE line by line

### Code:

```cpp
#include <iostream>
#include <string>

int main(){

    std::string str2 { "Hello World"};
    
    char * data = str2.data();
    std::cout << "Wrapped c string : " << data << std::endl;
    
    data[0] = 'B';// This also changes std::string.
    
    std::cout << "Wrapped c string (after modification) : " << data << std::endl;
    std::cout << "Original string (after modification ) :" << str2 << std::endl;

    return 0;
}
```

---

# 🔍 **Line-by-Line Explanation**

### **Line 1–2**

```cpp
#include <iostream>
#include <string>
```

* Includes input/output and string library.

---

### **Line 5**

```cpp
std::string str2 { "Hello World"};
```

* Creates a `std::string` with the content:

```
Hello World
```

Memory layout inside string:

```
H e l l o _ W o r l d \0
```

---

### **Line 7**

```cpp
char * data = str2.data();
```

* `str2.data()` returns a **pointer to internal memory of the string**.
* Since C++17, this memory is **modifiable**.
* `data` now points to:

```
H e l l o _ W o r l d \0
↑
data points here
```

---

### **Line 8**

```cpp
std::cout << "Wrapped c string : " << data << std::endl;
```

* Since `data` is a `char*`, `cout` prints it as a **null-terminated string**.

### **Output:**

```
Wrapped c string : Hello World
```

---

### **Line 10**

```cpp
data[0] = 'B';
```

* Modifies the first character via the pointer.
* Now internal string becomes:

```
B e l l o _ W o r l d \0
```

So the original `str2` is also modified.

---

### **Line 12**

```cpp
std::cout << "Wrapped c string (after modification) : " << data << std::endl;
```

* Prints updated string using pointer.

### **Output:**

```
Wrapped c string (after modification) : Bello World
```

---

### **Line 13**

```cpp
std::cout << "Original string (after modification ) :" << str2 << std::endl;
```

* Prints the actual `std::string`, also modified.

### **Output:**

```
Original string (after modification ) :Bello World
```

---

# 🎯 Final Program Output (Full)

```
Wrapped c string : Hello World
Wrapped c string (after modification) : Bello World
Original string (after modification ) :Bello World
```

---

# 🚀 Summary (Easy to remember)

| Method            | Modifies string | Safe?             | Purpose                 |
| ----------------- | --------------- | ----------------- | ----------------------- |
| `str[i]`          | ✔               | ❌ No bounds check | Fast indexing           |
| `str.at(i)`       | ✔               | ✔ Checked         | Safe indexing           |
| `front(), back()` | ✔               | ✔                 | Access ends             |
| Range-for         | ❌ (unless ref)  | ✔                 | Read each char          |
| `c_str()`         | ❌               | ✔                 | Get read-only C-string  |
| `data()`          | ✔ (C++17+)      | ⚠️ careful        | Direct access to memory |

---

---

# 🚀 **1. size(), length(), empty()**

## ✔ `size()`

Returns **how many characters are currently in the string**.

```cpp
std::string s = "Hello";
std::cout << s.size(); // 5

//example :- code
#include <iostream>
#include <string>


int main(){

    /*
    std::string str1 {"Hello World"};
    std::string str2;
    std::string str3{};
    
    //Empty
    std::cout << std::endl;
    std::cout << "std::string::empty() : " << std::endl;
    std::cout << "str1 is empty : " << std::boolalpha << str1.empty() << std::endl;
    std::cout << "str2 is empty : " << std::boolalpha << str2.empty() << std::endl;
    std::cout << "str3 is empty : " << std::boolalpha << str3.empty() << std::endl;

    //Size
    std::cout << std::endl;
    std::cout << "std::string::size() : " << std::endl;
    std::cout << "str1 contains " << str1.size() << " characters" << std::endl; //11
    std::cout << "str2 contains " << str2.size() << " characters" << std::endl; // 0
    std::cout << "str3 contains " << str3.size() << " characters" << std::endl; // 0

   //Length
    std::cout << std::endl;
    std::cout << "std::string::length() : " << std::endl;
    std::cout << "str1 contains " << str1.length() << " characters" << std::endl; //11
    std::cout << "str2 contains " << str2.length() << " characters" << std::endl; // 0
    std::cout << "str3 contains " << str3.length() << " characters" << std::endl; // 0
    */

    //max_size : max number of characters a string can have on the system
    /*
	//Prints : 2147483647 on my system
    std::string str1 {"Hello World"};
    std::cout << "std::string can hold " << str1.max_size() << " characters" << std::endl;
    */


    //Capacity
    /*
    std::string str1 {"Hello World"};
    std::string str2;
    std::cout << "str1 capacity : " << str1.capacity() << std::endl;
	std::cout << "str2 capacity : " << str2.capacity() << std::endl;
	
	str1 = "The sky is so blue, the grass is green. Kids are running all over the place";
	
    std::cout << "str1 size : " << str1.size() << std::endl;
	std::cout << "str1 capacity : " << str1.capacity() << std::endl;
    */

    //Reserve : Update the capacity
    /*
    std::string str1 {"Hello World"};
	std::cout << "str1 capacity : " << str1.capacity() << std::endl; // 15
	std::cout << "str1 size : " << str1.size() << std::endl;

    str1.reserve(100);
    
    std::cout << "str1 after reserve : " << str1 << std::endl; 
	std::cout << "str1 capacity : " << str1.capacity() << std::endl; // 100
	std::cout << "str1 size : " << str1.size() << std::endl;
    */


    //shrink_to_fit
    std::string str1 {"Hello World"}; // 11
    str1.reserve(100);

	std::cout << "str1 capacity : " << str1.capacity() << std::endl; //100
	std::cout << "str1 size : " << str1.size() << std::endl; // 11

	str1.shrink_to_fit();
 
	std::cout << "str1 capacity : " << str1.capacity() << std::endl; //11
	std::cout << "str1 size : " << str1.size() << std::endl;//11

    return 0;
}
```

## ✔ `length()`

Same as `size()`.
It exists ONLY for naming convenience.

```cpp
s.length() == s.size()   // true
```

Both return **number of characters**, NOT counting the null terminator.

---

## ✔ `empty()`

Checks whether the string contains zero characters.

```cpp
std::string a = "";
std::string b = "Hello";

a.empty(); // true
b.empty(); // false
```

---

# 🔥 **Summary (size vs length vs empty)**

| Function   | Meaning                 | Returns    |
| ---------- | ----------------------- | ---------- |
| `size()`   | current character count | number     |
| `length()` | same as size()          | number     |
| `empty()`  | is string empty?        | true/false |

---

# 🚀 **2. max_size()**

`max_size()` returns the **maximum number of characters your system's string implementation can hold**.

Example:

```cpp
std::string s;
std::cout << s.max_size();
```

Typical outputs:

| System / Library | Possible max_size()  |
| ---------------- | -------------------- |
| 64-bit GCC       | 2^63 - 1 (≈ 9.22e18) |
| MSVC             | ≈ 4GB                |

⚠️ This does NOT mean you can actually allocate that much memory. It’s just the theoretical upper limit.

---

# 🚀 **3. capacity()**

`capacity()` tells you **how much memory is currently allocated**, which is usually **more than size()**.

### Why capacity exists?

To avoid frequent memory allocations when growing the string.

Example:

```cpp
std::string s{"Hello"}; // size: 5
std::cout << s.capacity(); // maybe 15
```

---

### ✔ String grows exponentially

When string grows beyond capacity, it reallocates:

* Old capacity: 15
* Insert more characters → overflow
* New capacity becomes bigger, typically multiplied (implementation dependent)

---

# 🚀 **4. reserve(n)**

`reserve(n)` requests **at least n capacity**, but does NOT change the size.

Example:

```cpp
std::string s{"Hello"};
s.reserve(100);

s.size();     // 5
s.capacity(); // >= 100
```

👍 Useful to avoid multiple reallocations when building a long string in loops.

---

# 🚀 **5. shrink_to_fit()**

Requests the string to **release unused memory** and shrink capacity to match size.

Example from your code:

```cpp
std::string str1{"Hello World"}; // size = 11, capacity maybe 15
str1.reserve(100);               // capacity = 100
str1.shrink_to_fit();            // capacity = 11
```

### Output:

```
str1 capacity : 100
str1 size : 11
str1 capacity : 11
str1 size : 11
```

⚠️ Note: `shrink_to_fit()` is **non-binding**. Compiler *may* shrink, but usually does.

---

# 🧠 **Memory Model Explained**

Let’s understand it visually.

---

## Before reserve(100):

```
"Hello World"
size = 11
capacity = 15 (for example)
```

---

## After reserve(100):

```
"Hello World" + (89 unused characters)
size = 11
capacity = 100
```

---

## After shrink_to_fit():

```
"Hello World"
size = 11
capacity = 11
```

Unused memory is freed.

---

# 🧩 **6. Why size and capacity are different?**

Because:

* `size` = number of characters in the string.
* `capacity` = allocated memory (may be larger to support growth).

This avoids expensive reallocations during string modification.

---

# ✔ Comparison Table

| Feature           | Meaning           | Changes size?  | Changes capacity?  |
| ----------------- | ----------------- | -------------- | ------------------ |
| `size()`          | characters stored | ✔ returns size | ❌                  |
| `length()`        | same as size      | ✔ returns size | ❌                  |
| `empty()`         | size == 0         | ✔              | ❌                  |
| `capacity()`      | allocated memory  | ❌              | ✔ returns capacity |
| `reserve(n)`      | grow capacity     | ❌              | ✔                  |
| `shrink_to_fit()` | shrink capacity   | ❌              | ✔ tries to reduce  |
| `max_size()`      | theoretical limit | ❌              | ❌                  |

---

# 🏁 Final Summary (easy to memorize)

```
size = current number of characters
length = alias of size
capacity = allocated memory (for growth)
reserve = increase capacity
shrink_to_fit = reduce capacity
empty = check if size == 0
max_size = maximum possible size on this system
```

---

---

# 📘 **C++ String Modifying Functions — Complete Notes**

---

# ✅ **1. `clear()`**

### **Purpose:**

Removes all characters from the string. Size becomes **0**, but **capacity remains unchanged**.

### **Syntax**

```cpp
str.clear();
```

### **Example**

```cpp
std::string str1{"The Lion Dad"};

std::cout << str1 << std::endl;      // Output: The Lion Dad
std::cout << str1.size() << std::endl;      // 12
std::cout << str1.capacity() << std::endl;  // capacity (implementation dependent)

str1.clear();

std::cout << str1 << std::endl;      // Output: (empty)
std::cout << str1.size() << std::endl;      // 0
std::cout << str1.capacity() << std::endl;  // same as before
```

### **Explanation**

* `clear()` deletes characters but does **not** free memory.
* Useful when reusing the string to avoid reallocation.

---

# ✅ **2. `insert()` — Multiple Overloads**

---

## **2.1 Insert count copies of a character**

### **Syntax**

```cpp
str.insert(index, count, ch);
```

### **Example**

```cpp
std::string str2 {"122"};
str2.insert(1, 4, '3');   // Insert 4 '3's at index 1
std::cout << str2;        // 132222
```

### **Explanation**

* Index **1** means insertion after the first character.
* It inserts `"3333"` producing `1 3333 22`.

---

## **2.2 Insert a C-string**

### **Syntax**

```cpp
str.insert(index, c_string);
```

### **Example**

```cpp
std::string str3{"Hello!"};
const char* txt = " World";

str3.insert(5, txt);
std::cout << str3;   // Hello World!
```

### **Explanation**

* Inserts `" World"` starting at index 5 (after "Hello").

---

## **2.3 Insert first `count` chars of C-string**

### **Syntax**

```cpp
str.insert(index, c_string, count);
```

### **Example**

```cpp
std::string str4{"Hello!"};
const char* txt4 = " World Health Organization";

str4.insert(5, txt4, 6);   // inserts " World"
std::cout << str4;         // Hello World!
```

### **Explanation**

* Takes **only 6 characters**: `" World"`.

---

## **2.4 Insert another string**

### **Syntax**

```cpp
str.insert(index, str2);
```

### **Example**

```cpp
std::string str6{"Hello!"};
std::string str5{" World"};

str6.insert(5, str5);
std::cout << str6;     // Hello World!
```

---

## **2.5 Insert substring of another string**

### **Syntax**

```cpp
str.insert(index, other_str, start_pos, count);
```

### **Example**

```cpp
std::string str7{"Hello!"};
std::string str8{"Statistical Analysis of the World Population."};

str7.insert(5, str8, 27, 6);  
std::cout << str7;     // Hello World!
```

### **Explanation**

* Starting at index 27 in str8 → substring `"World "`.
* Insert first 6 chars → `"World"`.

---

# ✅ **3. `erase()`**

### **Purpose:**

Remove `count` characters starting from `index`.

### **Syntax**

```cpp
str.erase(index, count);
```

### **Example**

```cpp
std::string str9{
"Hello World is a message used to start off things when learning programming!"
};

str9.erase(11, str9.size() - 12);

std::cout << str9;
// Output: Hello World!
```

### **Explanation**

* Starting at index **11**, delete all characters except first 11.
* This keeps `"Hello World"`.

---

# ✅ **4. `push_back()`**

### **Purpose:**

Adds a single character at the end.

### **Syntax**

```cpp
str.push_back(ch);
```

### **Example**

```cpp
std::string str10{"Hello World"};
str10.push_back('!');

std::cout << str10;   // Hello World!
```

---

# ✅ **5. `pop_back()`**

### **Purpose:**

Removes last character.

### **Syntax**

```cpp
str.pop_back();
```

### **Example**

```cpp
std::string str11{"Hello World!!"};
str11.pop_back();

std::cout << str11;   // Hello World!
```

---

# 🎯 Summary Table

| Operation               | Function                         | What It Does                |
| ----------------------- | -------------------------------- | --------------------------- |
| Clear                   | `clear()`                        | Removes all chars           |
| Insert char(s)          | `insert(pos, count, ch)`         | Inserts repeated characters |
| Insert C-string         | `insert(pos, cstr)`              | Inserts entire C-string     |
| Insert partial C-string | `insert(pos, cstr, count)`       | Inserts first `count` chars |
| Insert string           | `insert(pos, str)`               | Inserts another std::string |
| Insert substring        | `insert(pos, str, start, count)` | Inserts substring           |
| Erase                   | `erase(pos, count)`              | Deletes characters          |
| Push back               | `push_back(ch)`                  | Appends a char              |
| Pop back                | `pop_back()`                     | Removes last char           |

---

---

# 📘 **Comparing `std::string` in C++ — Complete Notes with Explanation**

---

## ⭐ **1. Comparison Operators for `std::string`**

C++ allows direct comparison of `std::string` objects using:

| Operator | Meaning                   |
| -------- | ------------------------- |
| `==`     | Equal                     |
| `!=`     | Not equal                 |
| `<`      | Lexicographically less    |
| `>`      | Lexicographically greater |
| `<=`     | Less or equal             |
| `>=`     | Greater or equal          |

Lexicographical comparison = **dictionary order** (compared character by character using ASCII values).

---

# ✅ **Example 1: Comparing Two std::strings**

```cpp
std::string hello_str{"Hello"};
std::string bello_str{"Bello"};

std::cout << std::boolalpha;
std::cout << hello_str << "==" << bello_str << " : " 
          << (hello_str == bello_str) << std::endl;    // false

std::cout << hello_str << "!=" << bello_str << " : "
          << (hello_str != bello_str) << std::endl;    // true

std::cout << hello_str << ">" << bello_str << " : "
          << (hello_str > bello_str) << std::endl;     // true

std::cout << hello_str << ">=" << bello_str << " : "
          << (hello_str >= bello_str) << std::endl;    // true

std::cout << hello_str << "<" << bello_str << " : "
          << (hello_str < bello_str) << std::endl;     // false

std::cout << hello_str << "<=" << bello_str << " : "
          << (hello_str <= bello_str) << std::endl;    // false
```

### ✔ **Line-by-line Explanation**

* `"Hello"` vs `"Bello"`
* ASCII of `'H'` (72) is **greater** than `'B'` (66)
  → `"Hello" > "Bello"` is **true**
  → `"Hello" < "Bello"` is **false**
* All comparisons are done character-by-character.

---

# ⭐ **2. Comparing `std::string` with C-Strings (`const char*`)**

You can directly compare:

```cpp
std::string == const char*
```

C++ automatically treats the `char*` as a C-string and compares contents until `'\0'`.

---

# ✅ **Example 2: std::string vs C-string**

```cpp
const char* c_string1{"Bello"};
hello_str = "Hello";

std::cout << hello_str << "==" << c_string1 << " : "
          << (hello_str == c_string1) << std::endl;     // false

std::cout << c_string1 << ">=" << hello_str << " : "
          << (c_string1 >= hello_str) << std::endl;     // false

std::cout << c_string1 << "<" << hello_str << " : "
          << (c_string1 < hello_str) << std::endl;      // true
```

### ✔ **Explanation**

* `"Hello"` vs `"Bello"` again → `"Hello"` is lexicographically greater.
* Note:
  `c_string1 == hello_str` compares contents
  **NOT** pointer addresses.

---

# ⭐ **3. WARNING: Comparing Strings Without Null Terminator**

C-string functions (`strlen`, comparisons, printing) depend on `'\0'` to detect end.

Without `'\0'`, C++ will read **garbage memory**.

---

# ❌ **Wrong (no null terminator)**

```cpp
const char hello_char_array[] {'h','e','l','l','o'};  // ❌ No '\0'
```

This array is **not** a proper C-string because it lacks the null character.

Comparing it to a std::string causes undefined behavior because the program reads beyond 5 characters until it accidentally finds a `'\0'`.

---

# ✅ **Correct (with null terminator)**

```cpp
const char hello_char_array[] {'h','e','l','l','o','\0'};   // ✔ Proper C-string

std::string hello_str = "hello";

std::cout << hello_str << " == hello_char_array : "
          << (hello_str == hello_char_array) << std::endl;  // true
```

### ✔ Why it works

* `'\0'` tells the program: **string ends here**
* So comparison works exactly as expected.

---

# 📌 Summary Notes (Quick Revision)

### ✅ `std::string` supports:

* `==` equal
* `!=` not equal
* `>` `<` lexicographical comparison
* Works on **ASCII values** of characters
* Comparison happens **character-by-character**

### ✅ You *can* compare:

* `std::string` ↔ `std::string`
* `std::string` ↔ `"C-string literal"`
* `std::string` ↔ `const char*`

### ⚠ You *must ensure*:

* C-strings must contain `'\0'`
* Otherwise comparisons give undefined results.

---



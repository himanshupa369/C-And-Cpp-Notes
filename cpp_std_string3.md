
---

# Understanding `std::string::compare()` in C++


```
#include <iostream>
#include <string>


int main(){


	//Compare (1)
    //int compare( const basic_string& str ) const noexcept;(1)
	//Compares this string to str.
    /*
	std::string str1{"Hello"};
    std::string str2{"World"};
	
    std::cout << "str1 : " << str1 << std::endl;
	std::cout << "str2 : " << str2 << std::endl;
    std::cout << "str1.compare(str2) : " << str1.compare(str2) << std::endl; // negative
    std::cout << "str2.compare(str1) : " << str2.compare(str1) << std::endl; // positive
    */

	//Compare (2)
    //int compare( size_type pos1, size_type count1,const basic_string& str ) const; (2)
	//Compares a  substring  of this string(from pos1, going count1 positions) to str
    /*
	std::string str1 = "Hello";
    std::string str3{"Hello World"};
    std::cout << "Comparing 'World' to 'Hello' : " << str3.compare(6,5,str1) << std::endl;//1
    */

	//Compare (3)
    //int compare( const CharT* s ) const;(4)
	//Compares this string to the null-terminated character sequence beginning 
    //at the character pointed to by s.
    std::string str5{"Hello"};
    const char* message {"World"};
    std::cout << "Comparing Hello to World : " << str5.compare(message) << std::endl;//-1
    std::cout << "Comparing Hello to World : " << str5.compare("World") << std::endl; //-1


    return 0;
}
```


---

# ✅ **1. String Replacing**

---

## **Replace (1)**

```cpp
#include <iostream>
#include <string>


int main(){


	//Compare (1)
    //int compare( const basic_string& str ) const noexcept;(1)
	//Compares this string to str.
    /*
	std::string str1{"Hello"};
    std::string str2{"World"};
	
    std::cout << "str1 : " << str1 << std::endl;
	std::cout << "str2 : " << str2 << std::endl;
    std::cout << "str1.compare(str2) : " << str1.compare(str2) << std::endl; // negative
    std::cout << "str2.compare(str1) : " << str2.compare(str1) << std::endl; // positive
    */

	//Compare (2)
    //int compare( size_type pos1, size_type count1,const basic_string& str ) const; (2)
	//Compares a  substring  of this string(from pos1, going count1 positions) to str
    /*
	std::string str1 = "Hello";
    std::string str3{"Hello World"};
    std::cout << "Comparing 'World' to 'Hello' : " << str3.compare(6,5,str1) << std::endl;//1
    */

	//Compare (3)
    //int compare( const CharT* s ) const;(4)
	//Compares this string to the null-terminated character sequence beginning 
    //at the character pointed to by s.
    std::string str5{"Hello"};
    const char* message {"World"};
    std::cout << "Comparing Hello to World : " << str5.compare(message) << std::endl;//-1
    std::cout << "Comparing Hello to World : " << str5.compare("World") << std::endl; //-1


    return 0;
}
```

```cpp
// basic_string& replace(size_type pos, size_type count, const basic_string& str)
```

**Meaning:**
Replace the characters in the current string from index `pos` to `pos + count` with the entire `str`.

Example from the code:

```cpp
std::string str1 {"Finding Nemo"}; 
std::string str1_2 {"Searching For"};       // (typo in your code 'Searcing')

str1.replace(0, 7, str1_2);
```

### ✔ Explanation

* Original: `"Finding Nemo"`
* Replace from **position 0**, **7 characters**: `"Finding"`
* Replace `"Finding"` with `"Searching For"`

**Result:**

```
Searching For Nemo
```

---

## **Replace (2)**

```cpp
// replace(pos1, count1, str2, pos2, count2)
```

**Meaning:**
Replace a portion of the current string with a **substring** of another string.

Example:

```cpp
std::string str2 {"Finding Nemo"};
std::string str3 {"The Horse was Found in the Fields Searching For Food"};

str2.replace(0, 7, str3, 34, 13);
```

### ✔ Explanation

* Replace `"Finding"` (0 to 7) in `str2`
* With **substring from str3**:

  * Start at index **34**
  * Take **13 characters**

Substring starting at 34 in str3 = `"Searching For"`

✔ Final:

```
Searching For Nemo
```

---

# ✅ **2. String Copying**

---

```cpp
size_type copy(CharT* dest, size_type count, size_type pos = 0)
```

### ✔ Meaning

Copy a part of the string starting at `pos` into a **pre-allocated char array** `dest`.

**Important:**

* The copied data is **NOT null-terminated automatically**.
* If you want to safely print it, the array must already contain `'\0'`.

### Code:

```cpp
std::string str4{"Climbing Kirimanjaro"};
char txt4[15] {};       // initialized to all '\0'

str4.copy(txt4, 11, 9);
```

### ✔ Explanation

* Starting at index **9** of `"Climbing Kirimanjaro"`
* Copy **11 characters** into `txt4`

Index 9 letter:

```
C l i m b i n g _ K i r i m a n j a r o
0 1 2 3 4 5 6 7 8 9 ...
```

Index 9 = `'K'`.

11 characters = `"Kirimanjaro"`

The array already contains null characters, so printing works safely.

Output:

```
Kirimanjaro
```

---

# ✅ **3. String Resizing**

---

### **Resize (increase size)**

```cpp
str5.resize(8);
```

### ✔ Explanation

Original string:

```
"Hello"
```

New size = **8**, so 3 extra characters are added.

By default, added characters are:

```
'\0' (null character)
```

### ❗ Null characters do not show when printed.

---

### **Checking the null characters**

The loop prints each character, including `'\0'`:

```
0:H  
1:e  
2:l  
3:l  
4:o  
5:  
6:  
7:  
```

Indexes 5–7 are empty-looking because they contain `'\0'`.

---

### **Resize with a fill character**

```cpp
str5.resize(10, '*');
```

New positions get `'*'`:

Output:

```
Hello\0\0\0**
```

When printed normally:

```
Hello**    (nulls are invisible)
```

---

### **Resize down**

```cpp
str5.resize(5);
```

String becomes:

```
Hello
```

Capacity stays the same; only size changes.

---

# ✅ **4. String Swapping**

---

### Code:

```cpp
std::string str_a{"This is a string stored in A"};
std::string str_b{"This is a string stored in B and it's really great to be able to do that."};

str_a.swap(str_b);
```

### ✔ What swap() does:

Swaps **contents**, **size**, and **capacity** between strings.

It does **NOT** copy characters—it swaps internal pointers.

---

### Before swap:

```
str_a: short string (smaller capacity)
str_b: long string (large capacity)
```

### After swap:

```
str_a now contains the long string (capacity increases)
str_b now contains the short string (capacity decreases)
```

This is very efficient (constant time).

---

# 🎯 Final Summary Table

| Feature               | Function                                   | What It Does                                  |
| --------------------- | ------------------------------------------ | --------------------------------------------- |
| **Replace**           | `replace(pos, count, str)`                 | Replace part of string with another string    |
| **Replace substring** | `replace(pos1, count1, str, pos2, count2)` | Replace part with substring of another string |
| **Copy**              | `copy(dest, count, pos)`                   | Copies characters to a char array             |
| **Resize**            | `resize(n)`                                | Increase or decrease string size              |
| **Resize with fill**  | `resize(n, ch)`                            | New characters filled with `ch`               |
| **Swap**              | `swap(str)`                                | Exchange entire contents + capacity           |

---

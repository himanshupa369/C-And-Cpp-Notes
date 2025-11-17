In C++, **raw string literals** are a special type of string literal that allow you to include characters **without needing to escape them**.

It is introduced in C++11.
They are extremely useful when your string contains:

* backslashes `\`
* quotes `" `
* regular expressions
* file paths
* multi-line strings
* JSON/XML/HTML text

---

# ✅ **Syntax of Raw String Literal**

```
R"( your string here )"
```

Everything inside **`R"(...)"`** is taken **exactly as it is**, with *no escape sequences*.

---

# 📌 Example 1: Without Raw String

You must escape backslashes and quotes:

```cpp
std::string path = "C:\\Users\\Himanshu\\Desktop\\project";
```

---

# 📌 Example 2: With Raw String

No need to escape anything:

```cpp
std::string path = R"(C:\Users\Himanshu\Desktop\project)";
```

✔ Much cleaner.

---

# 📌 Example 3: Multi-line Raw String

```cpp
std::string text = R"(
Hello,
This is a multi-line string.
No need to use \n.
)";
```

---

# 📌 Example 4: Raw String with Quotes Inside

```cpp
std::string quote = R"(He said "Hello" to me.)";
```

If you use normal string, you must write:

```cpp
std::string quote = "He said \"Hello\" to me.";
```

---

# 🔥 **Delimiter Customization (Advanced)**

If your string contains `)"`, you can use your own delimiter.

Syntax:

```
R"delimiter( your string )delimiter"
```

Example:

```cpp
std::string s = R"abc( Inside this )abc" string )abc";
```

---

# 🧠 Summary Table

| Feature                   | Normal String | Raw String |
| ------------------------- | ------------- | ---------- |
| Backslash has meaning     | Yes           | No         |
| Escape sequences work     | Yes           | No         |
| Multi-line allowed        | No            | Yes        |
| Good for regex/file paths | Hard          | Easy       |

---

# ✔ Final Summary

**Raw string literal** = A string where backslashes, quotes, and escape sequences are treated literally, without needing `\\`, `\"`, `\n`, etc.

---

---

# 📘 **Notes on Raw String Literals in C++**

## ✅ What is a Raw String Literal?

A **raw string literal** is a string where C++ does **not** process escape sequences such as:

* `\n`
* `\t`
* `\\`
* `\"`
* etc.

Whatever you write inside a raw string literal is taken literally.

---

# ✅ Syntax

Basic:

```cpp
R"( your text here )"
```

Custom delimiter:

```cpp
R"DELIM( your text here )DELIM"
```

---

# 🎯 Why use Raw Strings?

They make your code simpler when your string contains:

* File paths
* Many backslashes
* Quotes
* Multi-line text
* Regular expressions

---

# 🧩 Your Code Explained (Section by Section)

---

## 🔹 **1. The "Bad Way" — Using Escaped Characters**

```cpp
std::string todo_list {"\tClean the house\n\tWalk the dog\n\tDo laundry\n\tpick groceries"};
std::string windows_path {"D:\\sandbox\\testProject\\hello.txt"};
std::string linux_path {"/home/username/files/hello.txt"};
std::string hint {" \"\\\\\" escapes a backslash character like \\."};
```

Problems:

* `\t`, `\n` must be escaped.
* Backslashes `\` must be doubled: `\\`.
* Quotes `"` must be escaped: `\"`.

This becomes hard to read and error-prone.

---

## 🔹 **2. Same Strings Using Raw String Literals**

```cpp
std::string to_do_list {R"(  Clean the house
   Walk the dog
   Do laundry
   Pick groceries)"};
```

✔ No need for `\n`
✔ No escaping
✔ Readable multi-line text

---

## 🔹 **3. Raw String Literal Assigned Normally**

```cpp
std::string to_do_list = R"(
	Clean the house
	Walk the dog
	Do Laundry
	Pick groceries
)";
```

Same as above, but using assignment instead of brace initialization.

---

## 🔹 **4. Raw String Literal Stored in const char***

```cpp
const char* c_string {R"(
	Clean the house
	Walk the dog
	Do Laundry
	Pick groceries
)"};
```

✔ Raw strings also work for C-style strings (`const char*`).

---

## 🔹 **5. Raw Strings for Paths and Quotes**

```cpp
std::string windows_path1 {R"(D:\sandbox\testProject\hello.txt)"};
std::string linux_path1 {R"(/home/username/files/hello.txt)"};
std::string hint1 {R"("\\" escapes a backslash character like \.)"};
```

✔ No more double backslashes
✔ No escaping `"`
✔ As clean as it gets

---

## 🔹 **6. Complex Case — Raw String with Quotes Inside**

```cpp
std::string sentence {R"--(The message was "(Stay out of this!)")--"};
```

Why use `--` here?

Because the string contains:

```
"( ... )"
```

If we used:

```cpp
R"( ... )"
```

C++ might confuse the inner `")"` with the closing delimiter of the raw string.

So we add a custom delimiter:

```
R"--(   ...   )--"
```

Anything between `( ... )` inside the matching delimiters is taken literally.

✔ It prevents conflicts
✔ Allows nested parentheses and quotes inside the string

---

# 🧠 **Summary of Raw String Literal Rules**

### ✔ Raw strings do *not* process escape sequences

`\n` stays `\n`, not newline.

### ✔ They allow multi-line text

No need to manually add `\n`.

### ✔ You can include quotes, backslashes, and symbols without escaping.

### ✔ If the content clashes with `)"`, use a custom delimiter.

---

# 📝 **Final Output of the Last Statement**

Your last part:

```cpp
std::string sentence {R"--(The message was "(Stay out of this!)")--"};
std::cout << sentence << std::endl;
```

**Output:**

```
The message was "(Stay out of this!)"
```

---

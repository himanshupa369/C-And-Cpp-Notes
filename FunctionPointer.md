---

## 🔍 **Basic Understanding**

### 1. **What is a function pointer?**

> A function pointer is a pointer that stores the address of a function and can be used to call that function.

---

### 2. **How do you declare and use a function pointer?**

```cpp
void greet() {
    cout << "Hello\n";
}

int main() {
    void (*ptr)() = greet;
    ptr(); // calls greet()
}
```

---

### 3. **Can you pass a function pointer to another function?**

> Yes. This is useful in callbacks or custom behavior.

```cpp
void action(void (*fptr)()) {
    fptr();
}
```

---

## 🧠 **Conceptual Questions**

### 4. **What is the syntax to declare a pointer to a function that takes two `int`s and returns an `int`?**

```cpp
int (*ptr)(int, int);
```

---

### 5. **What are some real-life use cases of function pointers?**

* Callbacks
* Menu-driven programs
* Event-driven systems
* Replacing `switch-case`
* Plugin architecture

---

### 6. **Difference between function pointer and pointer to function?**

> They are the same — the term "pointer to function" is the correct description, "function pointer" is just shorthand.

---

## ⚒️ **Code-Based Questions**

### 7. **What will be the output?**

```cpp
int add(int a, int b) { return a + b; }

int main() {
    int (*fptr)(int, int) = add;
    cout << fptr(2, 3);
}
```

✅ **Answer:** 5

---

### 8. **Write a program to choose between add, subtract, multiply using function pointers.**

```cpp
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main() {
    int (*op[])(int, int) = {add, sub};
    int a = 10, b = 5;
    cout << op[0](a, b) << endl;  // 15
    cout << op[1](a, b) << endl;  // 5
}
```

---

### 9. **Can we have a pointer to a member function?**

> Yes, but the syntax is different for member functions:

```cpp
class A {
public:
    void display() { cout << "Hi\n"; }
};

int main() {
    void (A::*fptr)() = &A::display;
    A obj;
    (obj.*fptr)(); // calls display()
}
```

---

## ❓ **Tricky Questions**

### 10. **What happens if you call a function using an uninitialized function pointer?**

> **Undefined Behavior** — may crash or call garbage code.

---

### 11. **What is the size of a function pointer?**

> It is implementation-dependent, but usually **same as a regular pointer** (e.g., 8 bytes on 64-bit systems).

---

### 12. **Can a function pointer point to `main()`?**

> Yes, technically it can. But it serves no practical purpose and is rarely used.

---

### 13. **Can you use function pointers in a class?**

> Yes, both **non-member** and **member** function pointers can be used in classes, but member function pointers have special syntax.

---
### 24. ✅ What is a function pointer with extern "C" used for?
To link with C libraries in C++:

---cpp
Copy
Edit
extern "C" void myFunc();
---

### 25. ✅ Can a function pointer point to a static member function?
Yes! Because static member functions don't require this pointer.

---cpp
Copy
Edit
class A {
public:
    static void display() {
        cout << "Static Function\n";
    }
};

int main() {
    void (*ptr)() = A::display;
    ptr();
}
---

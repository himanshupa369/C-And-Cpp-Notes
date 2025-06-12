
---

### 🔹 **Basic Questions**

1. **What are `cin` and `cout` in C++?**

   * `cin` is used for input (from keyboard), and `cout` is used for output (to console).
   * Both are part of the `<iostream>` header.

   ```cpp
   int x;
   cin >> x;      // input
   cout << x;     // output
   ```

2. **Which header file is required to use `cin` and `cout`?**

   * `<iostream>`

3. **What does `std::cin` and `std::cout` mean?**

   * `cin` and `cout` are in the `std` namespace. Without `using namespace std;`, you must write `std::cin` and `std::cout`.

   ```cpp
   std::cout << "Hello";
   ```

4. **What operator is used with `cin` and `cout`?**

   * `cin` uses `>>` (extraction operator).
   * `cout` uses `<<` (insertion operator).

---

### 🔹 **Intermediate Questions**

5. **Can `cin` and `cout` be overloaded?**

   * Yes, you can overload the `<<` and `>>` operators for user-defined types (classes).

   ```cpp
   class Point {
   public:
       int x, y;
       friend istream& operator>>(istream& in, Point& p) {
           in >> p.x >> p.y;
           return in;
       }
       friend ostream& operator<<(ostream& out, const Point& p) {
           out << "(" << p.x << "," << p.y << ")";
           return out;
       }
   };
   ```

6. **What is the difference between `endl` and `"\n"` in `cout`?**

   * `endl` flushes the output buffer after printing newline.
   * `"\n"` just inserts a newline without flushing.

   ```cpp
   cout << "Line 1\n";       // faster
   cout << "Line 2" << endl; // slower due to flush
   ```

7. **How to take input with spaces using `cin`?**

   * Use `getline()` to read an entire line (including spaces).

   ```cpp
   string name;
   getline(cin, name);
   ```

---

### 🔹 **Advanced Questions**

8. **What happens when you mix `cin` and `getline()`?**

   * `cin` leaves a newline (`\n`) in the buffer, which `getline()` reads immediately.
   * Solution: use `cin.ignore()` before `getline()`.

   ```cpp
   int age;
   string name;
   cin >> age;
   cin.ignore();          // clear the newline
   getline(cin, name);
   ```

9. **Can you redirect `cin` and `cout` to files?**

   * Yes, using file streams or by redirecting standard input/output.

   ```cpp
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   ```

10. **What is the type of `cin` and `cout`?**

    * `cin` is an object of type `istream`.
    * `cout` is an object of type `ostream`.

---

### ❓ Code-Based Interview Example

**Q:** Predict the output:

```cpp
int x;
cout << "Enter a number: ";
cin >> x;
cout << "You entered: " << x << endl;
```

**A:** If user inputs `42`, output will be:

```
Enter a number: You entered: 42
```

---


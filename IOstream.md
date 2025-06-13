

---

## ✅ **Basic I/O Stream Interview Questions**

### 1. **What are I/O streams in C++?**

**Answer:**
I/O streams in C++ are **objects** used to perform input and output operations using `iostream` classes like:

* `cin` (standard input)
* `cout` (standard output)
* `cerr` (standard error)
* `clog` (standard log)

---

### 2. **What is the difference between `cin`, `cerr`, `clog`, and `cout`?**

| Stream | Use             | Buffered | Example               |
| ------ | --------------- | -------- | --------------------- |
| `cin`  | Standard input  | Yes      | `cin >> a;`           |
| `cout` | Standard output | Yes      | `cout << "Hi";`       |
| `cerr` | Error output    | **No**   | `cerr << "Error";`    |
| `clog` | Logging output  | Yes      | `clog << "Log info";` |

---

### 3. **What is `std::endl` vs `'\n'`?**

* `std::endl`: newline + flushes the output buffer (slower)
* `'\n'`: just a newline character (faster)

---

## ✅ **Intermediate Level Questions**

### 4. **What are input/output manipulators?**

**Answer:** They are functions used to format output, e.g.:

* `std::setw(n)`, `std::setprecision(n)`, `std::hex`, `std::oct`, `std::fixed`

```cpp
#include <iomanip>
cout << std::setw(10) << std::setprecision(3) << 3.14159;
```

---

### 5. **Difference between `>>` and `getline()` with `cin`?**

```cpp
string s;
cin >> s;         // Reads until space
getline(cin, s);  // Reads entire line
```

---

### 6. **What is stream extraction (`>>`) and insertion (`<<`) operator overloading?**

Used to define **custom input/output** for user-defined types.

```cpp
class Person {
    string name;
public:
    friend ostream& operator<<(ostream&, const Person&);
};
```

---

### 7. **What is stream buffering?**

* Streams are buffered for performance.
* `cout` stores output in a buffer until flushed.

---

### 8. **What is `std::ios` base class?**

All stream classes (`ifstream`, `ofstream`, `iostream`) derive from `std::ios`.
It provides flags like:

* `ios::app`, `ios::ate`, `ios::binary`, `ios::in`, `ios::out`, `ios::trunc`

---

## ✅ **Advanced Questions**

### 9. **What are `ifstream`, `ofstream`, and `fstream`?**

| Class      | Used For        |
| ---------- | --------------- |
| `ifstream` | Reading files   |
| `ofstream` | Writing files   |
| `fstream`  | Both read/write |

---

### 10. **How do you check stream state or errors?**

```cpp
if (cin.fail()) {
    cerr << "Input failed";
}
```

Common functions:

* `fail()`, `eof()`, `good()`, `clear()`

---

### 11. **What is the difference between text mode and binary mode?**

```cpp
ofstream fout("data.bin", ios::binary);  // No newline translation
```

* **Text mode:** platform-specific newline conversion
* **Binary mode:** no conversion, used for binary files

---

### 12. **What is `std::istream_iterator` / `std::ostream_iterator`?**

Used for **input/output from/to streams like containers**.

```cpp
istream_iterator<int> it(cin), end;
vector<int> v(it, end);
```

---

## ✅ Trick Questions

### 13. **What happens if `cin` fails?**

* The stream enters a **fail state**
* All further I/O operations will be ignored until `cin.clear()` is called

---

### 14. **Can you redirect `cin`/`cout`?**

Yes, using `freopen()` or `rdbuf()`:

```cpp
freopen("input.txt", "r", stdin);  // Redirect cin
```

---

### 15. **How do you flush `cout`?**

* `cout.flush()`
* `std::endl` (flushes automatically)

---

## ✅ Bonus: Real-life Use-Cases

* Logging: `clog`, `cerr`
* Competitive programming: use `'\n'` instead of `endl`
* Reading files using `ifstream` for config/CSV parsing

---


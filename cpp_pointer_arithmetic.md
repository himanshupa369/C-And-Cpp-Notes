
---

# 🧩 Pointer Arithmetic in C++

---

## 💡 What is Pointer Arithmetic?

**Pointer arithmetic** means performing **mathematical operations** (like `+`, `-`, `++`, `--`) on pointers to move them through memory — usually within arrays.

It allows you to **navigate memory addresses** based on the size of the data type the pointer points to.

---

### 🧠 Key Idea:

When you add or subtract from a pointer,
it **moves by multiples of the data type’s size**, not by 1 byte.

---

### Example:

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* ptr = arr; // points to arr[0]

std::cout << *ptr << std::endl;   // 10
ptr++;                            // moves to arr[1]
std::cout << *ptr << std::endl;   // 20
```

If `int` = 4 bytes, then:

* `ptr` initially points to address `1000`
* after `ptr++`, it points to `1004`

📦 It moved by **4 bytes**, not by 1 byte.

---

## 🧮 Arithmetic Operations Allowed on Pointers

| Operation     | Description                                   | Example                   |
| ------------- | --------------------------------------------- | ------------------------- |
| `++`          | Move pointer to next element                  | `ptr++`                   |
| `--`          | Move pointer to previous element              | `ptr--`                   |
| `+`           | Move forward `n` elements                     | `ptr + 2`                 |
| `-`           | Move backward `n` elements                    | `ptr - 3`                 |
| `ptr2 - ptr1` | Gives number of elements between two pointers | `int diff = ptr2 - ptr1;` |

---

### ✅ Example: Pointer Addition and Subtraction

```cpp
#include <iostream>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* p1 = arr;        // points to arr[0]
    int* p2 = arr + 3;    // points to arr[3] (40)

    std::cout << *p1 << std::endl;   // 10
    std::cout << *p2 << std::endl;   // 40

    int diff = p2 - p1;
    std::cout << "Distance: " << diff << std::endl;  // 3

    p1 = p1 + 2; // move 2 steps ahead → arr[2]
    std::cout << *p1 << std::endl;  // 30
}

/*
//Comparison of pointers :-
#include <iostream>


int main(){
    
    int scores[10] {11,12,13,14,15,16,17,18,19,20};
    
    int * pointer1 {&scores[0]};
    int * pointer2 {&scores[8]};
	
    //Can also compare pointers
    
    //The further you go in the array, the bigger the address
    
    std::cout << "Comparing pointers : " <<std::boolalpha <<  std::endl;
	
    std::cout << "pointer1 > pointer2 : " <<  (pointer1 > pointer2) << std::endl;
    std::cout << "pointer1 < pointer2 : " << (pointer1 < pointer2) << std::endl;
    std::cout << "pointer1 >= pointer2 : " <<  (pointer1 >= pointer2) << std::endl;
    std::cout << "pointer1 <= pointer2: " << (pointer1 <= pointer2) << std::endl;
    std::cout << "pointer1 == pointer2 : " <<  (pointer1 == pointer2) << std::endl;
    std::cout << "pointer1 != pointer2 : " << (pointer1 != pointer2) << std::endl;
    
    return 0;
}

*/
```

📌 `p2 - p1` = number of elements (not bytes) between them → `3`

---

## 🚫 Invalid Pointer Arithmetic

Not all arithmetic is allowed — these are **undefined behaviors** in C++:

| Operation                                 | Description                       | Validity |
| ----------------------------------------- | --------------------------------- | -------- |
| `ptr + 1` (within array)                  | ✅ Valid                           |          |
| `ptr - 1` (within array)                  | ✅ Valid                           |          |
| `ptr + n` (where `n` moves outside array) | ❌ Undefined behavior              |          |
| Arithmetic on non-array pointers          | ⚠️ Dangerous, usually meaningless |          |

---

### ⚠️ Example (Undefined Behavior)

```cpp
int x = 10;
int* p = &x;
p++; // ❌ undefined behavior — not part of any array
```

The compiler won’t stop you, but the result is unpredictable.

---

## 🧠 Pointer Comparison (Related Concept)

You can compare pointers that point **into the same array**.

```cpp
int arr[] = {1, 2, 3, 4};
int* p1 = &arr[0];
int* p2 = &arr[3];

if (p1 < p2) std::cout << "p1 is before p2";
```

✅ Allowed: comparisons like `<`, `>`, `==`, `!=` within the same array
❌ Not allowed: comparing unrelated pointers.

---

## 🧩 Pointer Arithmetic with Different Data Types

Let’s see how much each pointer moves:

| Type      | Size    | `ptr++` moves by | Example Address |
| --------- | ------- | ---------------- | --------------- |
| `char*`   | 1 byte  | +1 byte          | 1000 → 1001     |
| `int*`    | 4 bytes | +4 bytes         | 1000 → 1004     |
| `double*` | 8 bytes | +8 bytes         | 1000 → 1008     |

---

### Example:

```cpp
char c = 'A';
int i = 10;
double d = 20.5;

char* pc = &c;
int* pi = &i;
double* pd = &d;

std::cout << "pc+1: " << (void*)(pc + 1) << std::endl;
std::cout << "pi+1: " << (void*)(pi + 1) << std::endl;
std::cout << "pd+1: " << (void*)(pd + 1) << std::endl;
```

Output (addresses):

```
pc+1: 0x1001
pi+1: 0x1004
pd+1: 0x1008
```

---

## 🔍 Real-Life Use Cases

| Use Case                            | Description                         |
| ----------------------------------- | ----------------------------------- |
| Iterating arrays using pointers     | Faster, low-level access            |
| Working with dynamic memory         | Traversing `new[]` allocated arrays |
| Implementing custom data structures | Linked lists, stacks, buffers       |
| File or memory manipulation         | Handling raw bytes via `char*`      |

---

## 🧾 Summary Table

| Operation | Meaning                    | Example            |
| --------- | -------------------------- | ------------------ |
| `ptr++`   | Move to next element       | `++ptr;`           |
| `ptr--`   | Move to previous element   | `--ptr;`           |
| `ptr + n` | Move ahead `n` elements    | `ptr = ptr + 3;`   |
| `ptr - n` | Move backward `n` elements | `ptr = ptr - 2;`   |
| `p2 - p1` | Distance (in elements)     | `int n = p2 - p1;` |

---

## 🧩 Visual Diagram

```
int arr[5] = {10, 20, 30, 40, 50};

Address → 1000   1004   1008   1012   1016
            ↓      ↓      ↓      ↓      ↓
           [10]   [20]   [30]   [40]   [50]
            ↑
           ptr (points to arr[0])

ptr++ → points to 1004 → arr[1]
```

---

## 🟢 TL;DR (Quick Revision)

| Rule                                     | Explanation               |
| ---------------------------------------- | ------------------------- |
| Pointer arithmetic moves by size of type | Not by bytes              |
| Only valid within same array             | Going beyond = undefined  |
| `p2 - p1` gives count of elements        | Not bytes                 |
| Works with all data types                | Step size depends on type |

---

---

# 🧠 **Pointer Arithmetic in C++ (Explained with Examples)**

---

## 🔹 What is Pointer Arithmetic?

Pointer arithmetic means performing **mathematical operations on pointers** to move them through memory.
This allows you to **navigate arrays**, **modify elements**, or **access data efficiently** using pointers.

---

## 🔹 Basic Rules of Pointer Arithmetic

1. You can only do arithmetic on pointers that point to **elements of the same array**.
2. When you increment or decrement a pointer, it moves by the **size of the data type**, not by 1 byte.
3. You can:

   * Increment (`++`)
   * Decrement (`--`)
   * Add/subtract integers (`ptr + n`, `ptr - n`)
   * Subtract one pointer from another (`ptr2 - ptr1`) — gives the **number of elements** between them.

---

## 🧩 Example Code Walkthrough

```cpp
#include <iostream>

int main() {

    int scores[10] {11,12,13,14,15,16,17,18,19,20};
    int* p_score { scores };   // points to first element: &scores[0]
```

---

### 🔸 1. Incrementing Pointers

```cpp
std::cout << "Values using pointer increment:\n";
for (size_t i = 0; i < std::size(scores); ++i) {
    std::cout << "Address: " << p_score << " Value: " << *p_score << std::endl;
    ++p_score;
}
```

➡️ Each `++p_score` moves forward by `sizeof(int)` bytes (typically 4 bytes).

| Step | Address | Value | Explanation |
| ---- | ------- | ----- | ----------- |
| 1    | 1000    | 11    | start       |
| 2    | 1004    | 12    | +4 bytes    |
| 3    | 1008    | 13    | +4 bytes    |

---

### 🔸 2. Using `ptr + n` to Jump Ahead

```cpp
p_score = scores; // reset
std::cout << "\nExplicit addition:\n";
std::cout << "scores[4] : " << *(p_score + 4) << std::endl;
```

➡️ `*(p_score + 4)` → moves 4 elements ahead → accesses `scores[4]`.

📘 Equivalent to `scores[4]`.

---

### 🔸 3. Traversing Using a Loop

```cpp
p_score = scores;

std::cout << "\nTraversing array using pointer arithmetic:\n";
for (size_t i = 0; i < std::size(scores); ++i) {
    std::cout << "Value : " << *(p_score + i) << std::endl;
}
```

📌 This behaves exactly like:

```cpp
for (size_t i = 0; i < std::size(scores); ++i)
    std::cout << "Value : " << scores[i] << std::endl;
```

✅ Both are identical in result — the pointer version just uses memory arithmetic.

---

### 🔸 4. Pointer Arithmetic on the Array Name

```cpp
std::cout << "\nPointer arithmetic directly on array name:\n";
for (size_t i = 0; i < std::size(scores); ++i) {
    std::cout << "Value : " << *(scores + i) << std::endl;
}
```

➡️ `scores` itself **acts like a constant pointer** to its first element (`&scores[0]`).

You **cannot modify** `scores` (e.g., `scores++` ❌),
but you can do arithmetic using `*(scores + i)`.

---

### 🔸 5. Printing in Reverse Order

#### (a) Using Index

```cpp
std::cout << "\nReverse order using array index:\n";
for (size_t i = std::size(scores); i > 0; --i)
    std::cout << "Value : " << scores[i - 1] << std::endl;
```

#### (b) Using Pointer Arithmetic

```cpp
std::cout << "\nReverse order using pointer decrement:\n";
p_score = scores + std::size(scores) - 1; // point to last element
for (size_t i = std::size(scores); i > 0; --i)
    std::cout << "Value : " << *(p_score--) << std::endl;
```

📘 `p_score--` moves backward in memory by `sizeof(int)` bytes each time.

---

### 🔸 6. Modifying Values Using Pointers

```cpp
p_score = scores;
scores[0] = 31;           // normal indexing
*(scores + 1) = 32;       // pointer arithmetic on array name
*(p_score + 2) = 33;      // pointer arithmetic on pointer

std::cout << "\nAfter modification:\n";
for (size_t i = 0; i < std::size(scores); ++i)
    std::cout << "Value : " << scores[i] << std::endl;
```

💡 All three ways modify the same array memory!

---

## 🧠 Memory Visualization

```
Array : int scores[5] = {11, 12, 13, 14, 15};

Memory layout:

Address → 1000   1004   1008   1012   1016
             ↓      ↓      ↓      ↓      ↓
           [11]   [12]   [13]   [14]   [15]
             ↑
           p_score (int*)

p_score + 1 → points to 1004 → element 12
p_score + 4 → points to 1016 → element 15
```

---

## ⚙️ Additional Logical Insights

| Concept                | Meaning                                  | Example                            |
| ---------------------- | ---------------------------------------- | ---------------------------------- |
| **Array name**         | Acts like a pointer to the first element | `scores == &scores[0]`             |
| **Increment pointer**  | Moves by data type size                  | `++p_score` moves by 4 bytes (int) |
| **Dereferencing**      | Access value at that memory              | `*p_score`                         |
| **Pointer difference** | Gives count of elements between them     | `p2 - p1`                          |
| **Invalid operations** | Crossing array bounds                    | `p_score + 10` (outside memory) ❌  |

---

## ⚠️ Common Mistakes

❌ `scores++` → Error (array name is not a modifiable lvalue)
❌ Pointer arithmetic on unrelated pointers → Undefined behavior
❌ Forgetting to reset pointer before reuse
❌ Accessing out of bounds (e.g., `*(scores + 10)`)

---

## ✅ Summary Table

| Operation | Description              | Example               |
| --------- | ------------------------ | --------------------- |
| `ptr++`   | Move to next element     | `++p_score`           |
| `ptr--`   | Move to previous element | `--p_score`           |
| `ptr + n` | Jump forward n elements  | `*(p_score + 3)`      |
| `ptr - n` | Jump backward n elements | `*(p_score - 2)`      |
| `p2 - p1` | Get element distance     | `int diff = p2 - p1;` |

---

## 🧾 Real-World Uses

| Use Case                  | Description                              |
| ------------------------- | ---------------------------------------- |
| Traversing arrays quickly | Low-level control of iteration           |
| Dynamic memory traversal  | Working with `new[]` allocations         |
| String manipulation       | Moving through `char*` buffers           |
| Low-level algorithms      | Implementing sorting, searching manually |
| System-level programming  | Memory-mapped files, buffers, drivers    |

---

## 🧩 Key Takeaways

1. Pointer arithmetic operates in **units of element size**, not bytes.
2. Valid only **within the same array or memory block**.
3. Array names behave like **constant pointers**.
4. Great for **high-performance** or **low-level** applications.
5. Use with **care** — easy to cause undefined behavior.

---


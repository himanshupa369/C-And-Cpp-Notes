
---

## 🧠 **Code Explanation — Random Number Generation using `rand()`**

---

### 🧩 1. Seeding the Random Generator

```cpp
std::srand(std::time(0)); // Seed
```

✅ This line **initializes (seeds)** the pseudo-random number generator using the **current time**.

Without this, your random numbers would **be the same each time you run the program**.

---

### 🧩 2. Generating a Raw Random Number

```cpp
int random_num = std::rand();
std::cout << random_num;
```

* `std::rand()` returns an integer between `0` and `RAND_MAX`.
* `RAND_MAX` is a constant defined in `<cstdlib>`, often `32767` on many systems.

So the range of raw random values is:

```
0 <= random_num <= RAND_MAX
```

---

### 🧩 3. Generating Multiple Random Numbers

You can use a loop to generate many random numbers:

```cpp
for (size_t i{0}; i < 20; ++i) {
    int random_num = std::rand();
    std::cout << "random_num " << i << " : " << random_num << std::endl;
}
```

Each call to `rand()` updates its internal state and produces a new number.

---

### 🧩 4. Restricting to a Range — `%` Operator

If you only want numbers in a **specific range**, use the **modulus operator `%`**.

#### Example 1: Range [0, 10]

```cpp
int random_num = std::rand() % 11;  // gives 0–10
```

#### Example 2: Range [1, 10]

```cpp
int random_num = std::rand() % 10 + 1; // gives 1–10
```

🧮 **General formula for random number in [min, max]:**

```cpp
int random_num = std::rand() % (max - min + 1) + min;
```

✅ Example: random number between 5 and 15
`std::rand() % (15 - 5 + 1) + 5` → gives `[5,15]`

---

### 🧩 5. Full Example (Your Code)

```cpp
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(0)); // Seed with current time

    for (size_t i{0}; i < 20; ++i) {
        int random_num = std::rand() % 10 + 1; // [1,10]
        std::cout << "random_num " << i << " : " << random_num << std::endl;
    }

    return 0;
}
```

**🟢 Output (will vary each run):**

```
random_num 0 : 7
random_num 1 : 3
random_num 2 : 10
random_num 3 : 5
...
```

---

### ⚠️ **Important Notes**

| Point                | Explanation                                                                                                                          |
| -------------------- | ------------------------------------------------------------------------------------------------------------------------------------ |
| 🔸 `rand()`          | Generates pseudo-random integers                                                                                                     |
| 🔸 `srand(seed)`     | Seeds the random number generator                                                                                                    |
| 🔸 Default seed      | If you **don’t** call `srand()`, the generator always starts from the same seed (usually 1), producing the *same sequence* every run |
| 🔸 `%` bias          | Using `%` can slightly bias results if `(RAND_MAX + 1)` is not divisible by your range size                                          |
| ✅ Modern alternative | Use `<random>` from C++11 (e.g., `std::uniform_int_distribution`) for true uniform distribution                                      |

---

### 🧩 6. Example — Random Number in Any Range

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int min = 50;
    int max = 100;

    for (int i = 0; i < 10; ++i) {
        int random_num = std::rand() % (max - min + 1) + min;
        std::cout << random_num << " ";
    }
}
```

**Output Example:**

```
91 74 56 83 59 64 96 85 55 73
```

---

## 🧩 7. Comparison: `rand()` vs `<random>`

| Feature        | `rand()`        | `<random>` (Modern C++)             |
| -------------- | --------------- | ----------------------------------- |
| Range control  | via `%`         | via `std::uniform_int_distribution` |
| Bias           | Possible        | None                                |
| Thread safety  | ❌ No            | ✅ Yes                               |
| Quality        | Low             | High                                |
| Seeding        | `srand()`       | `std::random_device`                |
| Recommendation | For quick demos | For production                      |

---

## 🧩 8. Practice Challenge 💪

Try generating an array of 10 integers where each number is:

* Between 1 and 100
* Randomly generated
* Printed in one line, separated by spaces

Hint:

```cpp
for (int& x : arr)
    x = std::rand() % 100 + 1;
```

---

---

## 🧠 **Generating Random Numbers in an Array (C++)**

---

### 🧩 1. The Basic Idea

We want to:

1. Create an array (or vector).
2. Fill it with random numbers.
3. Print them out to check.

---

## 🧩 **Method 1 — Using `rand()` (C-style)**

> ⚠️ Simple, but not ideal for serious programs — use for learning or small projects.

```cpp
#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    // Seed random number generator with current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Fill array with random numbers (0–99)
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = std::rand() % 100;
    }

    // Print array
    std::cout << "Random numbers:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
}
```

**🟢 Output Example:**

```
Random numbers:
23 87 12 56 78 5 91 42 63 10
```

---

### 🔍 **Explanation**

* `srand()` seeds the random generator — if you don’t seed it, you’ll get the *same numbers* every time.
* `rand() % 100` gives numbers in `[0, 99]`.
* Use `%` operator to limit range.

---

## 🧩 **Method 2 — Using `<random>` (Modern C++11 and beyond)** ✅

This is the **recommended** and **safer** way.

```cpp
#include <iostream>
#include <random>
#include <array>

int main() {
    const int SIZE = 10;
    std::array<int, SIZE> arr;

    // Create random device and engine
    std::random_device rd;  // seed
    std::mt19937 gen(rd()); // Mersenne Twister engine

    // Define range of numbers
    std::uniform_int_distribution<> dist(1, 100); // [1, 100]

    // Fill array
    for (int& x : arr) {
        x = dist(gen);
    }

    // Print array
    std::cout << "Random numbers:\n";
    for (int x : arr) {
        std::cout << x << " ";
    }
}
```

**🟢 Output Example:**

```
Random numbers:
73 6 94 33 27 48 57 19 89 1
```

---

### 🔍 **Explanation**

| Component                         | Purpose                            |
| --------------------------------- | ---------------------------------- |
| `std::random_device`              | Generates a random seed            |
| `std::mt19937`                    | Modern pseudo-random number engine |
| `std::uniform_int_distribution<>` | Controls range (e.g., 1–100)       |
| `dist(gen)`                       | Produces one random number         |

✅ **Advantages over `rand()`:**

* Truly independent random numbers
* Better quality randomness
* Customizable ranges and distributions

---

## 🧩 **Method 3 — Using `std::vector` Instead of Raw Arrays**

```cpp
#include <iostream>
#include <vector>
#include <random>

int main() {
    int n = 10;
    std::vector<int> arr(n);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 50); // numbers between 0–50

    for (int& x : arr)
        x = dist(gen);

    std::cout << "Random vector:\n";
    for (int x : arr)
        std::cout << x << " ";
}
```

---

## 🧩 **Method 4 — Random Floating Point Numbers**

```cpp
#include <iostream>
#include <random>

int main() {
    const int SIZE = 5;
    double arr[SIZE];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0); // between 0 and 1

    for (double& x : arr)
        x = dist(gen);

    for (double x : arr)
        std::cout << x << " ";
}
```

**Output Example:**

```
0.14322 0.95861 0.23487 0.71192 0.50431
```

---

## ⚙️ **Summary Table**

| Method         | Header      | Random Range                | Recommended? |
| -------------- | ----------- | --------------------------- | ------------ |
| `rand()`       | `<cstdlib>` | `%` operator                | ❌ Legacy     |
| `<random>`     | `<random>`  | `uniform_int_distribution`  | ✅ Modern C++ |
| Floating point | `<random>`  | `uniform_real_distribution` | ✅ Modern C++ |

---

## 🧩 **Bonus — Fill Array Using STL Algorithm**

```cpp
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int main() {
    std::vector<int> arr(10);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(10, 99);

    std::generate(arr.begin(), arr.end(), [&]() { return dist(gen); });

    for (int x : arr)
        std::cout << x << " ";
}
```

---

## 🧭 **Key Takeaways**

* ✅ Prefer `<random>` over `rand()`.
* ✅ Always seed your random generator.
* ✅ Use `uniform_int_distribution` or `uniform_real_distribution` for controlled ranges.
* ✅ Use `std::generate` for concise code.
* 🚫 Don’t rely on `rand()` for serious randomness.

---


---

# 📘 C++20 Concepts — Complete Notes

### 🏷 Feature Introduced In → **C++20**

Concepts help us **constrain template parameters**, making templates safer, more readable and with clear compiler errors.
They allow specifying the **requirements that a type must satisfy**, before template instantiation.

---

## 🔹 Why Concepts?

| Without Concepts                  | With Concepts                         |
| --------------------------------- | ------------------------------------- |
| Hard-to-read template errors      | Clear constraint-based compile errors |
| Templates accept invalid types    | Rejects invalid types early           |
| No direct way to enforce behavior | Enforce operators, types, expressions |

---

## ✨ Declaring a Concept

```cpp
template<typename T>
concept ConceptName = requires (T x) {
    // requirements
};
```

Then use it in a function:

```cpp
ConceptName auto func(ConceptName auto a) { }
```

or

```cpp
template<ConceptName T>
T func(T a);
```

---

## 🔥 4 Types of Requirements Inside `requires`

| Requirement Type      | Purpose                                     | Example                              |
| --------------------- | ------------------------------------------- | ------------------------------------ |
| **Simple**            | Checks only syntax validity                 | `a + b;`                             |
| **Nested**            | Checks if condition evaluates to `true`     | `requires sizeof(T) < 4;`            |
| **Compound**          | Validate return type, noexcept, conversions | `{a+b} -> std::convertible_to<int>;` |
| **Type Requirements** | `typename T::value_type` (advanced)         | **Not in course scope**              |

---

---

## 1️⃣ Simple Requirement

### ✔ Syntax is checked

❌ But value is NOT evaluated

```cpp
template<typename T>
concept TinyType = requires(T t) {
    sizeof(T) <= 4;   // Valid syntax → passes even if false
};
```

⛔ This will still accept `double` (8 bytes) — because syntax is valid.

---

## 2️⃣ Nested Requirement

### Ensures expression is **true**

```cpp
template<typename T>
concept TinyType = requires (T t) {
    sizeof(T) <= 4;          // syntax check
    requires sizeof(T) <= 4; // boolean evaluated
};
```

✔ `char, short, bool` allowed
❌ `int, double, long` rejected

---

## ▶ Example: Using Concept with Function

```cpp
TinyType auto addTiny(TinyType auto a, TinyType auto b) {
    return a + b;
}
```

---

## 3️⃣ Compound Requirement

Checks expression + return type + (optional) noexcept

```cpp
template<typename T>
concept Addable = requires (T a, T b) {
    { a + b } -> std::convertible_to<int>;    // + must work + convert to int
};
```

✔ Valid → `int`, `char`, `double` (all convertible to int)
❌ Invalid → `std::string`, `A+B` is string not int

---

### Example

```cpp
Addable auto add(Addable auto a, Addable auto b){
    return a + b;
}

int main(){
    double x=10 , y=20;
    std::cout << add(x,y);  // ✔ works
}
```

---

## 🧠 Summary Table

| Concept Feature        | Meaning                                   |
| ---------------------- | ----------------------------------------- |
| `requires`             | starts concept constraints                |
| `Simple requirement`   | syntax must be valid                      |
| `Nested requirement`   | condition must evaluate to true           |
| `Compound requirement` | check result type/convertibility/noexcept |
| `convertible_to<T>`    | result must convert to type T             |

---

## 👍 Advantages (Pros)

| Benefit                      | Description                        |
| ---------------------------- | ---------------------------------- |
| Better compile-time errors   | readable template diagnostics      |
| More readable templates      | acts like type interface/contracts |
| Enables template overloading | cleaner SFINAE alternative         |
| Improves code safety         | rejects invalid types early        |

---

## 👎 Limitations (Cons)

| Drawback                                     |
| -------------------------------------------- |
| Adds some complexity for beginners           |
| Can be misused if constraints are too strict |
| Requires C++20 compliant compiler            |

---

## 📌 Real-World Use Cases

✔ Building strong template APIs
✔ Constraining math functions (integral only, floating only)
✔ STL algorithms use Concepts now
✔ Safer overload resolution in generic code

---


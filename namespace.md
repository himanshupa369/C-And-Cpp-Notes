

---

### ✅ **Basic Interview Questions**

1. **What is a namespace in C++? Why is it used?**
   **Answer:**
   A `namespace` is a declarative region that provides a scope to identifiers (such as variables, functions, classes). It's used to **avoid name conflicts** especially when working with large projects or multiple libraries.

---

2. **What is the syntax of defining and using a namespace?**

   ```cpp
   namespace MySpace {
       void display() {
           std::cout << "Inside MySpace\n";
       }
   }

   int main() {
       MySpace::display();  // Qualified name
       return 0;
   }
   ```

---

3. **What is the `using` directive?**

   ```cpp
   using namespace std;
   ```

   This allows direct access to all identifiers in a namespace without qualification.
   ✅ Convenient
   ❌ May cause name conflicts in large codebases (bad in headers)

---

### ✅ **Intermediate Questions**

4. **What is the difference between `using namespace` and `using` declaration?**

   ```cpp
   using namespace std;        // imports all names
   using std::cout;            // imports only cout
   ```

   Prefer `using std::cout` in headers or shared code to avoid pollution.

---

5. **Can namespaces be nested?**
   **Answer:** Yes.

   ```cpp
   namespace A {
       namespace B {
           void fun();
       }
   }

   A::B::fun();
   ```

---

6. **Can we define anonymous namespaces? What are they for?**
   **Answer:** Yes. An **anonymous namespace** is used to give internal linkage to functions/objects.

   ```cpp
   namespace {
       void secretFunc() {}  // Only visible in this translation unit
   }
   ```

---

7. **Can two namespaces have the same name in different files?**
   **Answer:** Yes. They are extended.

---

### ✅ **Advanced/Tricky Interview Questions**

8. **What happens if two namespaces define a function with the same name and both are used via `using namespace`?**

   ```cpp
   namespace A { void show(); }
   namespace B { void show(); }

   using namespace A;
   using namespace B;

   show();  // ❌ Ambiguous
   ```

   **Answer:** Compiler error due to ambiguity. Use explicit qualification.

---

9. **Can you use classes/functions inside a namespace without `using` or `::`?**
   **Answer:** Only if you bring them into scope via:

   * `using` declaration
   * Friend declarations
   * Inheritance

---

10. **What are inline namespaces (C++11)? Why are they useful?**
    **Answer:** Used for versioning.

```cpp
namespace Library {
    inline namespace v2 {
        void print();  // default version
    }

    namespace v1 {
        void print();  // older version
    }
}

Library::print();          // resolves to v2::print()
Library::v1::print();      // explicitly access v1
```

---

### 🧠 Use-Cases to Mention in Interview

* Avoiding `std::cout`/`std::endl` in every line.
* Avoiding name collision in libraries.
* Providing modularity in large codebases.
* Creating versioned APIs via `inline namespace`.

---


Use these references : <br>
https://www.cplusplus.com/reference/iterator/
https://en.cppreference.com/w/cpp/iterator
https://en.cppreference.com/w/cpp/iterator/contiguous_iterator

<img width="1183" height="714" alt="Screenshot 2025-12-18 163441" src="https://github.com/user-attachments/assets/8003f206-84bb-4312-b833-6b01e2e524d7" />
<br>
<img width="1287" height="721" alt="Screenshot 2025-12-18 163457" src="https://github.com/user-attachments/assets/2081f4e9-cac6-4337-88c1-c72bddb0d60c" />
<br>
<img width="1457" height="752" alt="Screenshot 2025-12-18 163512" src="https://github.com/user-attachments/assets/bf7b782c-22e9-4ce7-a920-0eb614477d50" />
<br>
<img width="1180" height="734" alt="Screenshot 2025-12-18 163526" src="https://github.com/user-attachments/assets/3f39a31f-680a-49a1-85e0-1b9cb5ecd499" />
<br>
<img width="1488" height="722" alt="Screenshot 2025-12-18 163542" src="https://github.com/user-attachments/assets/855c3235-965c-4510-a38a-e4e0c3ff475d" />
<br>
<img width="1506" height="702" alt="Screenshot 2025-12-18 163555" src="https://github.com/user-attachments/assets/75e61dcc-c261-4bb7-b22c-5f82355f2897" />


---

# C++ Iterators – Categories and Features

## 1. **Definition of an Iterator**

* An **iterator** is an object that points to an element in a range of elements and allows traversal through the range.
* Iterators behave like **pointers**:

  * `++` operator to move forward
  * `--` operator for reverse movement (if supported)
  * `*` dereference operator to access elements

**Note:** Not all iterators support the same operations; their capabilities depend on their **category**.

---

## 2. **Iterator Categories**

### **A. Input Iterator**

* Used to **read data** from a container.
* Dereferencing gives a **copy** of the value, **no connection** to the original data.
* Supports:

  * `==` and `!=` comparison
  * Dereference `*` operator (read-only, R-value)
* **Limitations:** Cannot use arithmetic like `++` (some implementations may allow `++` for forward movement).

---

### **B. Output Iterator**

* Used to **write data** to a container.
* Dereferencing gives a **reference** to the element, allowing modification.
* Can assign values via dereferencing:

  ```cpp
  *it = value;
  ```
* **Limitations:** Cannot reliably read original container data; limited arithmetic support.

---

### **C. Forward Iterator**

* Can be **input or output** depending on `const`.
* Can move **forward** using `++`.
* Combines features of input and output iterators.
* Suitable for traversing a collection **once or multiple times** in forward direction.

---

### **D. Bidirectional Iterator**

* Extends **forward iterator** capabilities.
* Can move **forward (`++`)** and **backward (`--`)**.
* Used in containers like `std::list`, `std::set`.

---

### **E. Random Access Iterator**

* Extends **bidirectional iterator** capabilities.
* Supports:

  * `++` and `--` operators
  * Arithmetic with offsets (`it + n`, `it - n`)
  * Array-style indexing (`it[n]`)
  * Comparison (`<`, `>`, `<=`, `>=`)
* Provides **direct access** to any element in constant time.
* Examples: `std::vector`, `std::deque`, `std::array`.

---

### **F. Contiguous Iterator** (C++20)

* Extends **random access iterator**.
* Guarantees that **data is stored contiguously in memory**.
* Useful for memory-locality sensitive algorithms.
* Examples: `std::vector`, `std::array`.

---

## 3. **Hierarchy of Iterator Features**

* Iterators inherit features in the following manner:

  ```
  Input/Output → Forward → Bidirectional → Random Access → Contiguous
  ```
* A higher category iterator can be used wherever a lower category is required:

  * e.g., Random Access Iterator can be used as a Forward Iterator.

---

## 4. **Key Notes**

* **Input iterators:** read-only, return R-value.
* **Output iterators:** write-only, return reference.
* **Forward iterators:** can traverse forward, combining input/output features.
* **Bidirectional iterators:** forward + backward movement.
* **Random access iterators:** fast access via indexing and offsets.
* **Contiguous iterators:** guarantee contiguous memory storage, ideal for performance-sensitive operations.
* Always **use the operators appropriate** for the iterator type you are working with.

---

These notes cover the **iterator categories, features, hierarchy, and practical considerations** for C++ programming.

---



---

# Breaking Circular Dependencies in C++ (`std::shared_ptr` & `std::weak_ptr`)

---

## 1. What Is a Circular Dependency?

A **circular dependency** occurs when two (or more) objects **own each other using `std::shared_ptr`**.

### Example Problem

```cpp
struct Dog;
struct Owner;

struct Dog {
    std::shared_ptr<Owner> owner;
};

struct Owner {
    std::shared_ptr<Dog> dog;
};
```

### What Happens?

* `Dog` owns `Owner`
* `Owner` owns `Dog`
* Reference count never becomes **0**
* **Destructors are never called**
* **Memory leak occurs**

---

## 2. Why `std::shared_ptr` Fails Here

| Object | Ref Count       |
| ------ | --------------- |
| Dog    | 1 (Owner → Dog) |
| Owner  | 1 (Dog → Owner) |

Even after exiting scope:

* Both still point to each other
* No object releases ownership
* Heap memory is leaked

---

## 3. Solution: `std::weak_ptr`

### What Is `std::weak_ptr`?

* **Non-owning reference**
* Does **not increase reference count**
* Used to **observe** a `shared_ptr`
* Breaks ownership cycles

---

## 4. Correct Design Using `std::weak_ptr`

### Rule of Thumb

> One side **owns**, the other side **observes**

---

### Fixed Example

```cpp
struct Dog;
struct Owner;

struct Dog {
    std::weak_ptr<Owner> owner; // Non-owning
};

struct Owner {
    std::shared_ptr<Dog> dog;   // Owning
};
```

### Result

* `Owner` owns `Dog`
* `Dog` only observes `Owner`
* Reference count can reach **0**
* Destructors are called correctly

---

## 5. Accessing a `weak_ptr`

### `weak_ptr` Cannot Be Dereferenced Directly

```cpp
owner->name; // ❌ Compile-time error
```

---

### Correct Way: `lock()`

```cpp
if (auto ownerShared = owner.lock()) {
    std::cout << ownerShared->name << std::endl;
}
```

### Why?

* `lock()` returns a `shared_ptr`
* Returns `nullptr` if object is destroyed
* Prevents dangling pointer access

---

## 6. Detecting Expired Objects

```cpp
if (owner.expired()) {
    std::cout << "Owner no longer exists\n";
}
```

---

## 7. Reference Count Behavior

```cpp
std::shared_ptr<Dog> dog = std::make_shared<Dog>();
std::weak_ptr<Dog> weakDog = dog;
```

| Pointer   | Ref Count                       |
| --------- | ------------------------------- |
| `dog`     | 1                               |
| `weakDog` | 1 weak reference (no ownership) |

> `weak_ptr` does **not** affect object lifetime

---

## 8. Real-World Use Cases

| Scenario             | Owner (`shared_ptr`) | Observer (`weak_ptr`) |
| -------------------- | -------------------- | --------------------- |
| Parent → Child       | Parent               | Child                 |
| UI Controller → View | Controller           | View                  |
| Graph Nodes          | Graph                | Adjacent nodes        |
| Cache systems        | Cache                | Clients               |
| Observer pattern     | Subject              | Observer              |

---

## 9. Common Interview Questions

### Q1. Why not use raw pointers?

* Risk of dangling pointers
* No lifetime tracking

### Q2. When should `weak_ptr` be used?

* To **break ownership cycles**
* When you need access **without owning**

### Q3. Does `weak_ptr` delete objects?

* ❌ No
* It only observes

---

## 10. Best Practices

* Never form cycles using only `shared_ptr`
* Always convert one side to `weak_ptr`
* Use `lock()` before accessing
* Prefer `expired()` checks when needed

---

## 11. Summary Table

| Pointer Type | Owns Object | Affects Lifetime |
| ------------ | ----------- | ---------------- |
| `shared_ptr` | Yes         | Yes              |
| `weak_ptr`   | No          | No               |

---

## 12. One-Line Conclusion

> **Circular dependencies occur when shared ownership forms a cycle; `std::weak_ptr` breaks the cycle by providing non-owning access.**

---


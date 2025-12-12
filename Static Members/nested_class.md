<img width="1769" height="705" alt="Screenshot 2025-12-12 121457" src="https://github.com/user-attachments/assets/bdac1241-b2d0-4612-9208-ccc75d44d74c" />


---

# My notes — Nested classes 

**What a nested class is (short):**
A nested class is a class declared *inside* another class (outer). It’s a normal type, but its declaration and access rules are governed by where it appears (public / private / protected) inside the outer.

---

## Quick summary of the important rules

* A nested class type name is looked up as `Outer::Inner`.
* **If `Inner` is `private` in `Outer`, code outside `Outer` cannot name `Outer::Inner` or create `Inner` objects.**
* `Outer` **does not** automatically get access to `Inner`’s private members.
* `Inner` **does** have access to `Outer`’s private members **if it has an `Outer` object to operate on** (i.e., via a pointer/reference to that `Outer`).
* Nested class methods may access `Outer`’s **static** members directly (no object needed).
* Definitions of `Inner`’s member functions (outside the header) must use the qualified name: `Outer::Inner::...`.

---

## Case 1 — `Inner` declared in `private` section of `Outer` (common pattern)

### What this implies

* `Inner` is an implementation detail: users of `Outer` cannot name `Outer::Inner` or make `Inner` objects.
* Only `Outer`’s members (and friends) can create `Inner` objects or refer to the type.
* This is a good way to *hide* helper types.

### Typical uses

* Container internals, helper types, visitors, state machine states that must remain hidden.

### Example (minimal)

```cpp
class Outer {
private:
    class Inner {
    private:
        double d;
    public:
        Inner(double v) : d(v) {}
        double get() const { return d; }
    };

    int m;              // outer's private data
    static int s_count; // static member accessible to Inner

public:
    Outer(int v) : m(v) {}

    // Outer creates and uses Inner internally
    void do_something() {
        Inner i(3.14);            // allowed: Outer can create Inner
        double v = i.get();       // allowed: Outer can call public Inner members
        (void)v;
    }

    // give outside world some controlled behaviour that uses Inner
    int compute() {
        Inner i(m * 1.0);
        return static_cast<int>(i.get());
    }
};
```

### Notes & pitfalls

* Attempting `Outer::Inner x(1.0);` from `main()` will fail because `Inner` is private.
* `Outer` **cannot** directly access `Inner`’s `private` members; it can only use `Inner`’s public/protected API.
* `Inner` can access `Outer`’s static members directly. To access non-static members of a specific `Outer` instance, `Inner` needs a pointer/reference to that `Outer`.

---

## Case 2 — `Inner` declared in `public` section of `Outer`

### What this implies

* `Inner` becomes part of the outer’s public interface: users can write `Outer::Inner` and create instances.
* This is effectively the same type-scoping as putting `Inner` in the global namespace but namespaced under `Outer`.

### Typical uses

* When `Inner` is a public helper type meant for users of `Outer` (e.g., iterators, proxy types).

### Example (public inner)

```cpp
class Outer {
public:
    class Inner {
    private:
        double d;
    public:
        Inner(double v) : d(v) {}
        double get() const { return d; }
    };

    // Outer can still create Inner
    Inner make_inner(double v) { return Inner(v); }
};

int main() {
    Outer::Inner x(4.2);        // OK - Inner is public
    Outer o;
    auto y = o.make_inner(1.1); // also OK
}
```

### Notes & pitfalls

* Public nested types are often used for scoping: `Outer::Iterator` instead of `Iterator`.
* Even if `Inner` is public, it still follows normal C++ access rules: `Outer` does not get privileged access to `Inner`’s private members (only `Inner` member functions and friends can access them).

---

## Access relationships — detailed (examples + explanations)

### 1) Can **outside** code construct `Inner`?

* **Private `Inner`**: No → `Outer::Inner` is inaccessible from outside.
* **Public `Inner`**: Yes.

### 2) Can `Outer` access `Inner`’s private members?

* No. `Outer` is not automatically a friend of `Inner`. Use `friend` if you want that.

```cpp
class Outer {
private:
    class Inner {
    private:
        int a;
        friend class Outer;  // only then Outer can access Inner::a
    public:
        Inner(int v) : a(v) {}
    };
    void f() {
        Inner i(1);
        int x = i.a; // OK only if friend declared
    }
};
```

### 3) Can `Inner` access `Outer`’s private members?

* **Yes**, but only if it is given an `Outer` object (pointer/reference) or the member is `static`.
* `Inner` may be implemented to take `Outer*` and access private fields.

```cpp
class Outer {
private:
    int secret = 42;
public:
    class Inner {
    public:
        void reveal(Outer* o) {
            // can access private members of *o
            std::cout << o->secret << '\n';
        }
    };
};
```

### 4) Can `Inner` access `Outer`’s static members without an object?

* **Yes** — static members belong to the class, so `Inner` can name `Outer::s` (or just `s` if in scope).

---

## How to define `Inner` methods outside the header

When implementing `Inner` methods in the .cpp file you must fully qualify the name:

```cpp
// in outer.h
class Outer {
public:
    class Inner {
    public:
        Inner(double);
        double get() const;
    private:
        double d;
    };
};

// in outer.cpp
Outer::Inner::Inner(double v) : d(v) {}
double Outer::Inner::get() const { return d; }
```

If you forget the qualification the compiler won’t be able to find the function definition.

---

## Practical tips / best practices

1. Use a **private** nested class when the type is an implementation detail — keeps public API small.
2. Use a **public** nested class for types that logically belong to `Outer` (iterators, policy types).
3. Do **not** rely on implicit access between `Outer` and `Inner`: add `friend` declarations explicitly when needed.
4. Prefer passing `Outer*` or `Outer&` into `Inner` methods when `Inner` must access `Outer` instance data — be explicit.
5. Keep nested classes small and focused. Over-nesting can make code harder to read.

---

## Short checklist when you get compiler errors

* `inner was not declared in this scope` → you tried to name `Inner` from outside but it’s private. Use `Outer::Inner` and/or change access.
* `Outer::Inner is private within this context` → `Inner` is in `private:` and you’re trying to use it externally.
* `incomplete type` errors when declaring `Inner` members in `Outer` → you tried to put a non-pointer instance of `Outer` inside itself (not allowed).
* Missing `Outer::Inner::foo` definition → you forgot the qualification when implementing `Inner`’s methods in .cpp.

---

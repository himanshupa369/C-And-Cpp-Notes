
---

# Objects in Arrays and Range-Based For Loops Create Copies in C++

## Header

**Topic:** Copy behavior when storing objects in arrays and using range-based for loops
**Language Standard:** C++11 (range-based for loop), general rule valid since C++98
**Related Concepts:** Copy Constructor, Object Lifetime, References, Arrays, Range-based for loops

---

# 1. Why Objects in Arrays Are Copied

When you write:

```cpp
Person students[] {p1, p2, p3};
```

C++ **copies each object** (`p1`, `p2`, `p3`) into the array.

### Reason

Arrays store **actual objects**, not references or pointers.

During initialization:

* `students[0]` becomes a **copy** of `p1`
* `students[1]` becomes a **copy** of `p2`
* `students[2]` becomes a **copy** of `p3`

If a **copy constructor is defined**, it is called for each element.

### Evidence

The copy constructor prints:

```
Copy constructor for Snow
Copy constructor for Gray
Copy constructor for Drill
```

---

# 2. Objects in Arrays Have Different Memory Addresses

Example:

```
p1 address  = 0x7ffd...A90
students[0] = 0x7ffd...A50
```

These are **different objects** living at different addresses.

### Key Point

Array elements are **independent copies**, not aliases of the original objects.

---

# 3. Copy Constructor Helps You See These Copies

A minimal copy constructor:

```cpp
Person::Person(const Person& other)
    : Person(other.first_name, other.last_name, *other.age)
{
    std::cout << "Copy constructor for " << last_name << '\n';
}
```

This prints every time copying occurs (array creation, pass-by-value, etc.).

---

# 4. Range-Based For Loop Also Creates Copies (By Default)

### Example:

```cpp
for (Person p : students) {
    p.print_info();
}
```

Here **p is a copy** of each array element.

→ Copy constructor is called for every iteration.

### Behavior:

* A temporary `Person` object is created for each element
* Used inside the loop
* Destroyed at the end of the iteration
* New copy created in next iteration

This results in 3 additional calls to the copy constructor.

---

# 5. Avoid Copies by Using References in Range-Based For Loops

### Correct way to avoid copying:

```cpp
for (Person& p : students) {
    p.print_info();
}
```

Benefits:

* No copy constructor calls
* Loop variable `p` refers to the actual array element
* Faster and memory-safe

---

# 6. Regular For Loop Does NOT Create Copies

Example:

```cpp
for (size_t i = 0; i < std::size(students); ++i) {
    students[i].print_info();
}
```

Here, the loop accesses:

* `students[i]` directly
* No temporary objects
* No copy constructor calls

---

# 7. Summary Table

| Operation                                     | Creates Copies? | Why                                    |
| --------------------------------------------- | --------------- | -------------------------------------- |
| Initializing array with objects               | Yes             | Array stores actual objects            |
| Range-based loop with value (`Person p`)      | Yes             | Loop creates local copy each iteration |
| Range-based loop with reference (`Person& p`) | No              | Uses original element                  |
| Traditional for loop                          | No              | Accesses elements directly             |

---

# 8. Key Takeaways

* Arrays always store copies, not references.
* Copy constructor will be triggered when populating arrays.
* Range-based for loops **copy elements by default**.
* Use `&` (reference) in the loop to avoid unnecessary copies.
* Traditional index-based loops do not create copies.
* Copy overhead becomes significant for heavy objects.

---

# Sample Code Used in the Lecture

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string last_name{};
    std::string first_name{};
    int* age{}; // Dynamically allocated

public:
    // Destructor
    ~Person() {
        delete age;      // Prevent memory leak
    }

    // Delegating constructors
    Person(const std::string& last_name)
        : Person(last_name, "") {}

    Person(const std::string& last_name_param,
           const std::string& first_name_param)
        : Person(last_name_param, first_name_param, 0) {}

    Person(const std::string& last_name_param,
           const std::string& first_name_param,
           int age_param)
        : last_name(last_name_param),
          first_name(first_name_param),
          age(new int(age_param)) {}

    // Copy Constructor (deep copy)
    Person(const Person& source_p)
        : Person(source_p.get_last_name(),
                 source_p.get_first_name(),
                 *(source_p.get_age())) 
    {
        std::cout << "Copy constructor called for "
                  << last_name << std::endl;
    }

    // Setters
    void set_first_name(const std::string& first_name) {
        this->first_name = first_name;
    }

    void set_last_name(const std::string& last_name) {
        this->last_name = last_name;
    }

    void set_age(int age) { 
        *(this->age) = age;
    }

    // Getters
    const std::string& get_first_name() const {
        return first_name;
    }

    const std::string& get_last_name() const {
        return last_name;
    }

    int* get_age() const {
        return age;
    }

    // Utility
    void print_info() {
        std::cout << "Person object at : " << this
                  << " [ Last_name : " << last_name
                  << ", First_name : " << first_name
                  << " , age : " << *age
                  << " , age address : " << age
                  << " ]" << std::endl;
    }
};

int main() {
    Person p1("John", "Snow", 25);
    Person p2("Sam", "Gray", 45);
    Person p3("Johny", "Drill", 5);

    // Before array creation
    p1.print_info();
    p2.print_info();
    p3.print_info();

    std::cout << "----" << std::endl;

    // Array creation — copies are made here
    Person students[] { p1, p2, p3 };

    // Regular for loop — no extra copies
    for (size_t i{}; i < std::size(students); ++i) {
        students[i].print_info();
    }

    std::cout << "----" << std::endl;

    // Range-based for loop with reference — prevents copies
    for (Person& p : students) {
        p.print_info();
    }

    return 0;
}

```

---




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

```cpp
     |
weak ptr :--
  In C++, the syntax int num{}; is uniform (brace) initialization, introduced in C++11, and it means:
int num{};  // Initializes num to 0
This is equivalent to:
int num = 0;
int num;  // Not initialized, contains garbage value


// Weak Ownership :-
#include <iostream>
#include<memory>
class Printer {
    std::shared_ptr<int> m_pValue{};
public:
    void SetValue(std::shared_ptr<int> p) {
        m_pValue = p;
    }

    void Print() {
        std::cout << "Ref count: " << m_pValue.use_count() << std::endl;
        std::cout << "Value is: " << *m_pValue << std::endl;
    }
};

int main() {
    Printer prn;
    int num{};
    std::cin >> num;
    std::shared_ptr<int> p (new int{ num });
    prn.SetValue(p);

    if (*p > 10) {
        p = nullptr;
    }

    prn.Print();
}

//weak ptr internal 

#include <iostream>
#include<memory>
class Printer {
    std::weak_ptr<int> m_pValue{};
public:
    void SetValue(std::weak_ptr<int> p) {
        m_pValue = p;
    }

    void Print() {
        if (m_pValue.expired())
        {
            std::cout << "Resource is no longer available " << std::endl;
            return;
        }
        // lock() always return a shared ptr.
        auto sp = m_pValue.lock();
        std::cout << "Reference is: " << sp.use_count() << std::endl;
        std::cout << "Value is: " << *sp << std::endl;
    }
};

int main() {
    Printer prn;
    int num{};
    std::cin >> num;
    std::shared_ptr<int> p(new int{ num });
    prn.SetValue(p);

    if (*p > 10) {
        p = nullptr;
    }

    prn.Print();
}

// Circular reference
circular ownership:-

  
emp (shared_ptr<Employee>)               prj (shared_ptr<Project>)
┌────────────────────┐                    ┌────────────────────┐
│ Employee object     │◄──────────────┐  │ Project object      │◄──────────────┐
│ ref_count = 2       │               │  │ ref_count = 2       │               │
│ m_prj ──────────────┼─────────────► │  │ m_emp ──────────────┼─────────────► │
└────────────────────┘                │  └────────────────────┘                │
         ▲                            │             ▲                          │
         └────────────────────────────┘             └──────────────────────────┘
     emp (shared_ptr<Employee>)              prj (shared_ptr<Project>)

// In below code destructors not called and it causes memory leak.
#include<iostream>
#include<memory>
class Employee;
class Project {
public:
	std::shared_ptr<Employee> m_emp;
	Project() {
		std::cout << "Project()" << std::endl;
	}
	~Project() {
		std::cout << "~Project()" << std::endl;
	}
};
class Employee {
public:
	std::shared_ptr<Project> m_prj;
	Employee() {
		std::cout << "Employee()" << std::endl;
	}
	~Employee() {
		std::cout << "~Employee()" << std::endl;
	}
};

int main() {
	std::shared_ptr<Employee> emp { new Employee{} };
	std::shared_ptr<Project> prj { new Project{} };
	emp->m_prj = prj;
	prj->m_emp = emp;
}
  
no circular ownership:-
  
  emp (shared_ptr<Employee>)               prj (shared_ptr<Project>)
┌────────────────────┐                  ┌────────────────────┐
│ Employee object     │◄──────────────┐  │ Project object      │◄──────────────┐
│ ref_count = 1       │               │  │ ref_count = 1       │               │
│ m_prj ──────────────┼─────────────► │  │ m_emp ─weak_ptr─────┼──────┐        │
└────────────────────┘                │  └────────────────────┘       ▼        │
         ▲                            │        (no ownership)                  │
         └────────────────────────────┘                                        │
     emp (shared_ptr<Employee>)                                  prj (shared_ptr<Project>)

#include<iostream>
#include<memory>
class Employee;
class Project {
public:
	std::weak_ptr<Employee> m_emp;
	Project() {
		std::cout << "Project()" << std::endl;
	}
	~Project() {
		std::cout << "~Project()" << std::endl;
	}
};
class Employee {
public:
	std::shared_ptr<Project> m_prj;
	Employee() {
		std::cout << "Employee()" << std::endl;
	}
	~Employee() {
		std::cout << "~Employee()" << std::endl;
	}
};

int main() {
	std::shared_ptr<Employee> emp { new Employee{} };
	std::shared_ptr<Project> prj { new Project{} };
	emp->m_prj = prj;
	prj->m_emp = emp;
}

// Deleter :-
Smart pointer does not invoke delete they always invoke deleter call back.

#include<iostream>
#include<memory>
#include<cstdlib>

struct Free {
	void operator ()(int *p) {
		free(p);
		std::cout << "pointer Freed\n";
	}
};
void MallocDeleter(int* p) {
	free(p);
	std::cout << "MallocDeleter called/ Pointer Freed" << std::endl;
}
void UniquePtrDeleters() {
	// In case of UniquePtrDeleters we need to use of Custom deleter name inside declaration.

	//syntax :-std::unique_ptr<int, Deleter_name > p{ (int*)malloc(4),deleter Object/Temporary Object };
	std::unique_ptr<int, Free> p{ (int*)malloc(4),Free{} };
	//using function pointer
	//std::unique_ptr<int, void (*)(int*)> p{ (int*)malloc(4),MallocDeleter };
	*p = 100;
	std::cout << *p << '\n';
}
void SharedPtrDeleters() {
	//But not in case of SharedPtr.

	//syntax :-std::unique_ptr<int, Deleter_name > p{ (int*)malloc(4),deleter Object/Temporary Object };
	//std::shared_ptr<int> p{ (int*)malloc(4),Free};
	//using function pointer
	std::shared_ptr<int> p{(int*)malloc(4),MallocDeleter};
	*p = 100;
	std::cout << *p << '\n';
}
int main() {
	SharedPtrDeleters();
	UniquePtrDeleters();
}

//Dynamic Array using smart pointers
#include<cstdlib>
#include<iostream>

int main() {
	std::unique_ptr<int> arr{ new int[5]{1,2,3,4,5}};
	//arr[0] = 10;
	arr.get()[0] = 10;
	//but in below case you can use arr[0]=10;
	//std::unique_ptr<int[]> arr{ new int[5]{1,2,3,4,5}};
	//in case of smart ptr we can use direct subscript in C++ 17 version and later version
	//std::smart_ptr<int[]> arr{ new int[5] {1,2,3,4,5} }; => arr[0]=10;

}
  
make_unique /make_shared  is a variadic template function which uses factory methods. 
eliminate use of new in smart pointer to allocate something on heap
make_shared store some extra infrmation So when we use it, it will allocate the memory for the control block and the underlying resource using
one new call. And during destruction, there'll be only one delete call to delete both underlined resource and the control block.


Now, there is one disadvantage when you use make() functions, there is no way to specify a custom deleter while using make() functions.
So if you want to use a custom deleter with your smart pointer, you cannot use make() function, instead
you have to construct the smart pointer and allocate the memory for your resource yourself.
```


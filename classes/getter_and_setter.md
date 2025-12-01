
---

# 📘 **Setter & Getter in C++ **

---

## 🔹 Why Do We Need Setters & Getters?

In a well-designed C++ class, member variables are generally **private**, meaning they **cannot be accessed directly from outside** the class.
To interact (read/write) with those private values, we use:

| Purpose                             | Function Type |
| ----------------------------------- | ------------- |
| To **read** / access private data   | 👉 **Getter** |
| To **modify** / update private data | 👉 **Setter** |

This protects the variables and maintains **encapsulation → a key OOP concept.**

---

## 🧾 Basic Syntax

### ✔ Getter (Read only)

```cpp
double get_height(){
    return height;   // returns copy of private variable
}
```

### ✔ Setter (Modify value)

```cpp
void set_height(double h){
    height = h;     // modifies private variable
}
```

---

# 📌 Code Explained (From Lecture)

```cpp
class Cylinder {
public:
    Cylinder() = default;
    Cylinder(double rad_param,double height_param){
        base_radius = rad_param;
        height = height_param;
    }

    double volume(){
        return PI * base_radius * base_radius * height;
    }

    // Getters
    double get_base_radius(){ return base_radius; }
    double get_height(){ return height; }

    // Setters
    void set_base_radius(double rad_param){ base_radius = rad_param; }
    void set_height(double height_param){ height = height_param; }

private:
    double base_radius{1};
    double height{1};
};
```

### `private:`

Base radius & height **cannot be accessed directly outside class.**

### `public:` getters & setters

Allow safe controlled access.

---

# 🔥 Difference Between Getter & Setter

| Feature            | Getter               | Setter                              |
| ------------------ | -------------------- | ----------------------------------- |
| Purpose            | Read/access value    | Modify/update value                 |
| Return Type        | Returns variable     | Usually `void`                      |
| Risk Level         | ✓ Safe (Read only)   | ⚠ Can break logic if misused        |
| Can validate data? | ❌ No                 | ✔ Yes (check input before updating) |
| Used when          | Need to access value | Need to change value                |

---

# ⭐ Why Not Make Variables Public?

```cpp
cylinder1.base_radius = -10; // INVALID value but allowed if public ❌
```

This could break volume calculation.

Setters allow **validation**:

```cpp
void set_base_radius(double r){
    if(r > 0) base_radius = r;
}
```

✔ Prevents negative values
✔ Protects internal data.

---

# 🏭 Where They Are Used in Real Industry Projects?

| Real-world scenario                 | Why Getters/Setters?                                          |
| ----------------------------------- | ------------------------------------------------------------- |
| Banking system (Account balance)    | Getter to read balance, Setter updates only after validations |
| Game engines (Player health, speed) | Prevent illegal values like HP < 0 or > max limit             |
| UI input forms                      | Setter validates user input before storing                    |
| Database model classes              | Getters used for output, Setters sanitize/verify data         |
| Vehicle/IoT/Robotics systems        | Prevent unsafe configurations e.g., speed > max range         |
| E-commerce product price, stock     | Get → show to user, Set → admin updates with rules            |

### 💡 They enforce *Encapsulation + Security + Data control*

---

# 📍 Summary

| Topic       | Meaning                                            |
| ----------- | -------------------------------------------------- |
| Getter      | Returns private data (read only)                   |
| Setter      | Updates private data (write access)                |
| Why needed? | Protect internal state → Encapsulation             |
| Return Type | Getter → returns value, Setter → usually void      |
| Real-life?  | Banking, games, IoT, API models, inventory systems |

---

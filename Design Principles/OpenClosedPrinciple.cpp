/*
🔸 O — Open/Closed Principle (OCP)

🧠 Definition:
Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.
(Definition: In object-oriented programming, the open/closed principle states that "software entities such as classes, modules, functions, etc. 
should be open for extension, but closed for modification")

1. Which means, any new functionality should be implemented by adding new classes, attributes and methods, instead of changing the current ones or existing ones.
2. Bertrand Meyer is generally credited for having originated the term open/closed principle and This Principle is considered by Bob Martin as “the most important principle of object-oriented design”.

Implementation guidelines
1. The simplest way to apply OCP is to implement the new functionality on new derived (sub) classes that inherit the original class implementation.
2. Another way is to allow client  to access the original class with an abstract interface, 
3. So, at any given point of time when there is a requirement change instead of touching the existing functionality it’s always suggested to create new classes and leave the original implementation untouched.

Pit falls of Not following OCP : What if I do not follow Open closed principle during a requirement enhancement in the development process. In that case, we end up with the following disadvantages
1) If a class or a function always allows the addition of new logic, as a developer we end up testing the entire functionality along with the requirement.
(End up testing the entire functionality)

2) Also, as a developer we need to ensure to communicate the scope of the changes to the Quality Assurance team in advance so that they can gear up for enhanced regression testing along with the feature testing. 
(QA team need to test entire flow.)

3) Step 2 above is a costly process to adapt for any organization
(Costly process for organization.)

4) Not following the Open Closed Principle breaks the SRP since the class or function might end up doing multiple tasks.
(Breaks the single responsibility as well)

5) Also, if the changes are implemented on the same class, Maintenance of the class becomes difficult since the code of the class increases by thousands of unorganised lines. 
(maintenance overheads increases on the classes.)

That means:
- You should be able to add new functionality
- Without changing the existing code

💥 Why It Matters:
- Encourages scalability
- Reduces the risk of introducing bugs
- Makes your code easier to maintain and extend

🧪 Real-World Analogy:
You can add apps to your phone (extend) without rewriting its operating system (modifying).

📌 Summary:

✅ Good Practice                     ❌ Bad Practice
-----------------------------       -----------------------------
Extend behavior via new classes     Modify existing code for each new feature
Use interfaces or abstract classes  Hardcoded logic everywhere
Safe and stable extension path      High risk of bugs on changes
*/


// 🛒 Mini Project: Invoice System with Discount Strategies

#include <iostream>
#include <vector>
#include <memory>

// Item structure remains same
struct Item {
    std::string name;
    double price;
};

// 🎯 Abstract base class for discount strategy
class DiscountStrategy {
public:
    virtual double apply(double total) const = 0;
    virtual ~DiscountStrategy() = default;
};

// 🎁 No discount
class NoDiscount : public DiscountStrategy {
public:
    double apply(double total) const override {
        return total;
    }
};

// 🎁 Fixed percentage discount
class PercentageDiscount : public DiscountStrategy {
    double percent; // e.g., 10 for 10%
public:
    PercentageDiscount(double p) : percent(p) {}
    double apply(double total) const override {
        return total - (total * percent / 100.0);
    }
};

// 🎁 Fixed amount discount
class FlatDiscount : public DiscountStrategy {
    double amount;
public:
    FlatDiscount(double amt) : amount(amt) {}
    double apply(double total) const override {
        return (total > amount) ? total - amount : 0;
    }
};

// 🧮 Invoice class - now takes a discount strategy (Open for extension)
class Invoice {
    std::vector<Item> items;
    std::shared_ptr<DiscountStrategy> discountStrategy;
public:
    Invoice(std::shared_ptr<DiscountStrategy> strategy)
        : discountStrategy(strategy) {}

    void addItem(const Item& item) {
        items.push_back(item);
    }

    double getTotalBeforeDiscount() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.price;
        }
        return total;
    }

    double getTotalAfterDiscount() const {
        return discountStrategy->apply(getTotalBeforeDiscount());
    }

    const std::vector<Item>& getItems() const {
        return items;
    }
};

// 🖨️ Presentation logic
class InvoicePrinter {
public:
    void print(const Invoice& invoice) {
        std::cout << "Invoice:\n";
        for (const auto& item : invoice.getItems()) {
            std::cout << "- " << item.name << ": $" << item.price << "\n";
        }
        std::cout << "Total before discount: $" << invoice.getTotalBeforeDiscount() << "\n";
        std::cout << "Total after discount:  $" << invoice.getTotalAfterDiscount() << "\n";
    }
};

int main() {
    // Choose a discount strategy (can easily add new ones without touching Invoice)
    std::shared_ptr<DiscountStrategy> strategy = std::make_shared<PercentageDiscount>(10); // 10% off

    Invoice invoice(strategy);
    invoice.addItem({"Notebook", 12.99});
    invoice.addItem({"Pen", 1.99});
    invoice.addItem({"Mouse", 25.49});

    InvoicePrinter printer;
    printer.print(invoice);

    return 0;
}

/*
✅ OCP Applied:

We extended functionality (discount types) without modifying existing Invoice class.

Component            | Responsibility
---------------------|-------------------------------
DiscountStrategy     | Abstract base for discount types
NoDiscount           | No discount logic
PercentageDiscount   | Applies percentage-based discount
FlatDiscount         | Applies fixed-amount discount
Invoice              | Applies strategy without changing logic
InvoicePrinter       | Presents invoice data

We can now add new discount types just by creating new classes.
No need to touch or risk breaking existing code.
*/

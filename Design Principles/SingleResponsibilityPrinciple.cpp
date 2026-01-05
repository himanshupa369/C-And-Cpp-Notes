/*
🔹 S — Single Responsibility Principle (SRP).

🧠 Definition:
A class should have only one reason to change.

That means:
One class → One job → One responsibility

Every module or class should have responsibility over a single part of the functionality provided by the software, 
and that responsibility should be entirely encapsulated by the class.

=> There can be many members in the class as long as they related to the single responsibility.
=> With SRP,Classes becomes smaller and cleaner.
=> Code is less fragile.

Motivation...
=> Maintainability,
=> Testability (for large scale systen),
=> Flexibility and extensibility,
=> Parallel Development,
=> Loose Coupling 

💥 Why It Matters:
- Reduces complexity
- Easier to debug and test
- Makes your code modular and reusable
- Prevents unintended side-effects when modifying code

🧪 Real-World Analogy:
A Chef cooks.
A Waiter serves food.
A Cashier handles payment.
Would you make one person do all three?
Probably not — same with your classes!

📌 Summary:

✅ Good Practice             ❌ Bad Practice
---------------------       ------------------------
1 class = 1 responsibility   1 class = many jobs
Clear separation of concerns Tight coupling of logic
Easier to test and extend    Hard to maintain/debug
*/


//🛒 Mini Project: Billing System for a Shop

#include <iostream>
#include <vector>
#include <fstream>

struct Item {
    std::string name;
    double price;
};

// 🧮 1. Business logic class (Single responsibility: handle invoice data)
class Invoice {
    std::vector<Item> items;
public:
    void addItem(const Item& item) {
        items.push_back(item);
    }

    double getTotal() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.price;
        }
        return total;
    }

    const std::vector<Item>& getItems() const {
        return items;
    }
};

// 🖨️ 2. Presentation logic class (SRP: only prints)
class InvoicePrinter {
public:
    void print(const Invoice& invoice) {
        std::cout << "Invoice:\n";
        for (const auto& item : invoice.getItems()) {
            std::cout << "- " << item.name << ": $" << item.price << "\n";
        }
        std::cout << "Total: $" << invoice.getTotal() << "\n";
    }
};

// 💾 3. Persistence logic class (SRP: only saves to file)
class InvoiceSaver {
public:
    void saveToFile(const Invoice& invoice, const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file\n";
            return;
        }

        file << "Invoice:\n";
        for (const auto& item : invoice.getItems()) {
            file << "- " << item.name << ": $" << item.price << "\n";
        }
        file << "Total: $" << invoice.getTotal() << "\n";
        file.close();
    }
};

int main() {
    Invoice invoice;
    invoice.addItem({"Notebook", 12.99});
    invoice.addItem({"Pen", 1.99});
    invoice.addItem({"Mouse", 25.49});

    InvoicePrinter printer;
    printer.print(invoice);

    InvoiceSaver saver;
    saver.saveToFile(invoice, "invoice.txt");

    return 0;
}

/*
✅ SRP Applied:

Each class has a single concern:

- Invoice        → Business logic
- InvoicePrinter → Output logic
- InvoiceSaver   → Persistence logic

Class            | Responsibility
-----------------|-------------------------------
Invoice          | Handles data and calculation
InvoicePrinter   | Deals with presentation
InvoiceSaver     | Handles file persistence
*/

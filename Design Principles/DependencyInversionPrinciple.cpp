/*
🔹 D — Dependency Inversion Principle (DIP)

🧠 Definition:
=> High-level modules should not depend on low-level modules. Both should depend on abstractions.
=> Abstractions should not depend on details. Details should depend on abstractions.
=> The interaction between high level and low level modules should be thought of as an abstract interaction between them.
=> Introduced by Robert C Martin.

That means:
- Decouple high-level logic from low-level implementations
- Use interfaces (or abstract classes) to avoid direct dependencies

💥 Why It Matters:
- Increases flexibility (swap out low-level modules without touching high-level code)
- Promotes cleaner, modular architecture
- Avoids tight coupling between components

🧪 Real-World Analogy:
A client should be able to choose the payment method (e.g., PayPal, Credit Card) without the store's checkout process being tightly coupled to the specific method.

📌 Summary:

✅ Good Practice                       ❌ Bad Practice
-------------------------------       -------------------------------
Depend on abstractions              High-level module directly depends on low-level module
Flexible, easy to extend             Hard to change or extend without touching high-level code
No tight coupling                   Risk of breaking the system with new changes
*/


// 💳 Mini Project: Payment System

#include <iostream>
#include <memory>

// 🎯 Abstract Payment interface
class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() = default;
};

// 💳 PayPal payment method
class PayPal : public PaymentMethod {
public:
    void processPayment(double amount) override {
        std::cout << "Processing PayPal payment of $" << amount << "\n";
    }
};

// 💳 Credit Card payment method
class CreditCard : public PaymentMethod {
public:
    void processPayment(double amount) override {
        std::cout << "Processing Credit Card payment of $" << amount << "\n";
    }
};

// 🛒 High-level OrderProcessor that uses PaymentMethod abstraction (DIP)
class OrderProcessor {
    std::shared_ptr<PaymentMethod> paymentMethod;
public:
    // Constructor takes a PaymentMethod object (dependency injection)
    OrderProcessor(std::shared_ptr<PaymentMethod> payment)
        : paymentMethod(payment) {}

    void processOrder(double amount) {
        paymentMethod->processPayment(amount);  // Using the abstraction
    }
};

int main() {
    // High-level code (OrderProcessor) depends on abstraction, not on concrete payment methods
    std::shared_ptr<PaymentMethod> payment = std::make_shared<PayPal>(); // PayPal as payment method
    OrderProcessor orderProcessor(payment);

    orderProcessor.processOrder(100.00);  // PayPal payment

    // Now, we can easily change to a different payment method without touching OrderProcessor
    payment = std::make_shared<CreditCard>();  // Change to CreditCard
    orderProcessor = OrderProcessor(payment);

    orderProcessor.processOrder(200.00);  // Credit Card payment

    return 0;
}

/*
✅ DIP Applied:

OrderProcessor doesn't depend directly on specific payment methods.
It depends on the abstraction (PaymentMethod) instead.

Component            | Responsibility
---------------------|--------------------------------------
PaymentMethod        | Abstract base class for payment methods
PayPal               | Concrete implementation of PayPal payment
CreditCard           | Concrete implementation of Credit Card payment
OrderProcessor       | Processes orders using PaymentMethod abstraction

OrderProcessor is independent of how payments are processed — flexible to change!
*/

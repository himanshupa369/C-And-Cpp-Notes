/*
🔹 Interface Segregation Principle (ISP)

🧠 Definition:
Clients should not be forced to depend on interfaces they do not use.

That means:
- Break big interfaces into smaller, role-specific ones
- Each class should only implement what it actually needs
(one fat interface need to be split to many smaller and relevant interfaces 
so that clients can know about the interfaces that are relevant to them)

CASE Study.......

Problem......
• As we all know Xerox Corporation manufactures printer systems. In their development process of new systems Xerox 
had created a new printer system that could perform a variety of tasks such as stapling and faxing along with the regular printing task. 
• The software for this system was created from the ground up. 
• As the software grew for Xerox, making modifications became more and more difficult so that even the smallest change would take a redeployment cycle of an hour,
which made development nearly impossible.
• The design problem was that a single Job class was used by almost all of the tasks. Whenever a print job or a stapling job needed to be performed, 
a call was made to the Job class. 
• This resulted in a 'fat' class with multitudes of methods specific to a variety of different clients. 
Because of this design, a staple job would know about all the methods of the print job, even though there was no use for them.
 
Solution....

• To overcome this problem Robert C Martin suggested a solution which is called the Interface Segregation Principle. 
• Which means, Instead of one fat interface many small interfaces are preferred based on groups of methods with each one serving one submodule.
(one large job class is segregated to multiple interfaces depending on the requirement).



💥 Why It Matters:
- Reduces unnecessary code
- Avoids "empty method" implementations
- Makes code cleaner and easier to evolve

🧪 Real-World Analogy:
A Software Engineer codes.
A QA Tester tests.
A Manager manages.
You wouldn't ask the Manager to write unit tests or code, right?

📌 Summary:

✅ Good Practice                       ❌ Bad Practice
-------------------------------       -------------------------------
Small, focused interfaces             One fat interface for all roles
Only implement what you need          Forced to implement unused methods
More modular, role-based design       Tight coupling and bloated classes
*/


// 🛠️ Mini Project: Role-specific Interfaces

#include <iostream>

// 🎯 Small, focused interfaces
class ICode {
public:
    virtual void writeCode() = 0;
    virtual ~ICode() = default;
};

class ITest {
public:
    virtual void runTests() = 0;
    virtual ~ITest() = default;
};

class IManage {
public:
    virtual void manageTeam() = 0;
    virtual ~IManage() = default;
};

// 👨‍💻 Developer only codes
class Developer : public ICode {
public:
    void writeCode() override {
        std::cout << "Developer writing C++ code.\n";
    }
};

// 🧪 Tester only tests
class Tester : public ITest {
public:
    void runTests() override {
        std::cout << "Tester running test cases.\n";
    }
};

// 🧑‍💼 Manager only manages
class Manager : public IManage {
public:
    void manageTeam() override {
        std::cout << "Manager assigning tasks and planning sprints.\n";
    }
};

int main() {
    Developer dev;
    Tester tester;
    Manager mgr;

    dev.writeCode();
    tester.runTests();
    mgr.manageTeam();

    return 0;
}

/*
✅ ISP Applied:

Each class only implements what it needs.

Component | Responsibility
----------|-------------------------------
ICode     | Interface for coding
ITest     | Interface for testing
IManage   | Interface for managing
Developer | Only writes code
Tester    | Only runs tests
Manager   | Only manages team

No unnecessary method implementations.
No bloated interfaces. Clean and modular.
*/

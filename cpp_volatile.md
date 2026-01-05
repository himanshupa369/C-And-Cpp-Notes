
```cpp
//🔹 2️⃣ volatile Keyword
/* The volatile keyword tells the compiler not to optimize a variable, because its value might change unexpectedly due to external factors like:
✔ Hardware changes (e.g., memory-mapped I/O)
✔ Multithreading (e.g., shared variables)
✔ Interrupt handlers */

// 🔹 When to Use volatile?
// ✅ Use volatile when:
// ✔ Working with hardware registers (I/O ports, memory-mapped variables).
// ✔ Handling interrupt service routines (ISRs).
// ✔ Preventing unexpected compiler optimizations.

// 🚫 Avoid volatile for:
// ✔ Multithreading synchronization (Use std::atomic instead).
// ✔ General-purpose variables (It degrades performance).

#include <iostream>
using namespace std;

volatile int sensorValue;  // Value may change unexpectedly

void readSensor() {
    sensorValue = 42;  // Simulate hardware change
}

int main() {
    readSensor();
    cout << "Sensor Value: " << sensorValue << endl;  // Compiler won't optimize this access
// Note:- ✅ Why?
// ✔ Without volatile, the compiler may optimize away the second read because it assumes sensorValue hasn't changed.
// ✔ With volatile, the compiler always fetches the latest value from memory.
    return 0;
}
```

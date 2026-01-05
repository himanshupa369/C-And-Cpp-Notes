
```cpp
#include <stdio.h>
#include<iostream>
using namespace std;
int main() {
    int x = 10;
    float y = 5.5;
    char c = 'A';
    char str[] = "Hello, World!";

    // Printing variables with format specifiers
    printf("Integer: %d\n", x);     // %d for integers
    printf("Float: %.2f\n", y);     // %.2f for float with 2 decimal places
    printf("Character: %c\n", c);   // %c for characters
    printf("String: %s\n", str);    // %s for strings
    
    int age = 25;
    double salary = 45000.5020f;
    // .2f describes how many place values show on console after decimal //
    printf("Age: %d, \n Salary: %.2f\n", age, salary);

    float pi = 3.14159;

    // Printing with width and precision
    printf("Pi to 2 decimal places: %.2f\n", pi);  // 3.14
    printf("Pi with width 10: |%10.2f|\n", pi);     // Formatted with width left to ryt with spaces

    int num = 123;

    // Using %-15d
    printf("Using %% -15d: |%-15d|\n", num);  
    //  '-' flag ensures that the number is left-aligned (by default number is right aligned) and 15 defind atleast 15 character taken by variable//
    //if the number is shorter than 15 characters, will be padded with spaces on the right.

    /*we can write Hindi or any other language in the printf() function in C or C++, but there are a few important considerations :
    1)UTF-8 or Unicode Support,
    2)Console must have capability of encoding and decoding
    */
    // Hindi text in UTF-8 encoding
    //printf("नमस्ते दुनिया!\n");

    //Format Specifier AND Conversion Characters //

    printf("%d\n", 10); //prints 10 for integer and decimal values
    printf("%u\n", 10); //prints 10 for unsigned Integers
    printf("%f\n", 3.14); //prints 3.140000 for float and double (fixed-point notation)
    printf("%e\n", 3.14); //prints 3.140000e+00 for Float or double(scientific notation)
    printf("%E\n", 3.14); //prints 3.140000E+00 for Float or double (scientific notation, uppercase E)
    printf("%g\n", 3.14); // prints 3.14 for Float or double (use the shorter of %f or %e)
    printf("%G\n", 3.14); // prints 3.14 for Float or double (use the shorter of %f or %E, uppercase E)
    printf("%c\n", 'A'); // prints A for character
    printf("%s\n", "Hello"); // prints Hello for String of characters
    printf("%p\n", &num); //prints memory address of num
    printf("%x\n", 255); // prints ff for Unsigned integer (hexadecimal, lowercase letters)
    printf("%X\n", 255); // prints FF for Unsigned integer (hexadecimal, uppercase letters)
    printf("%o\n", 8); //prints 10 for Unsigned integer (octal)
    printf("%ld\n", 123456789L); //prints 123456789 for Long integer (decimal)
    printf("%lu\n", 123456789UL); //prints 123456789 for Unsigned long integer
    printf("%lf\n", 3.14); //prints 3.140000 for Double precision floating-point number we can use %Lf also.
    printf("%%"); // prints% for literal characters
    size_t sz = sizeof(num);
    printf("The size of num : %zu", &sz); //%zu is used in C to print size_t values.

    // Escape Sequence Character //
    printf("\a \n"); //Bell: Produces an alert sound(beep) on the terminal.
    printf("Hello\b World\n"); // prints Hell World(removes o)  Backspace: Moves the cursor one position backward.
    printf("Hello\fWorld\n\n"); 
    // moves to the next page(depending on the output device) Form feed: Moves the cursor to the beginning of the next page (not often used).
    // \n Newline: Moves the cursor to the beginning of the next line.
    printf("Hello\rWorld\n"); // overwrites Hello with World ,Carriage return: Moves the cursor to the beginning of the current line.

    printf("Hello\tWorld\n"); //prints Hello followed by a tab space and World ,Horizontal tab: Moves the cursor to the next tab stop.
    printf("Hello\vWorld\n"); //moves the cursor vertically ,Vertical tab: Moves the cursor down to the next vertical tab stop.
    printf("\0 \n"); //(end of string marker in C) ,Null character: Represents the null character, marking the end of a string.

    printf("\x41\n"); //prints A (\xhh) Hexadecimal: Represents a character with a hexadecimal value (e.g., \x41 for A).
    printf("\101\n"); // prints A(octal value for A is 101),(\oddd) Octal value: Represents a character with an octal value, where ddd is the octal value.
    printf("\u0041\n"); //prints A(Unicode for A) ,(\uXXXX) Unicode: Represents a character using 4 hexadecimal digits (for Unicode characters).
    printf("\U0001F600\n"); //prints 😀(Unicode for the 😀 emoji),(\UXXXXXXXX) Unicode (long): Represents a character using 8 hexadecimal digits (for Unicode characters).
    return 0;
}
```

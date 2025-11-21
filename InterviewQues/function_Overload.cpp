#include <iostream>
#include <string>

//Ambiguous calls 
// are below functions overloaded or not ??
void say_my_name(const std::string& name){
    std::cout << "Your name is (const ref) : " << name << std::endl;
}

void say_my_name(std::string& name){
    std::cout << "Your name is (non-const ref) : " << name << std::endl;
}

void say_my_name(std::string name){
    std::cout << "Your name is (by value) : " << name << std::endl;
}

int main(){

    std::string s1{"Himanshu"};
    const std::string s2{"Pathak"};

    // 1️⃣ Calls the non-const reference overload
    say_my_name(s1);

    // 2️⃣ Calls the const reference overload
    say_my_name(s2);

    // 3️⃣ Calls the pass-by-value overload
    say_my_name(std::string{"Sunny"});

    // Alternative ways to call pass-by-value:
    // say_my_name("Sunny"); // literal → temporary → matches by value
    // say_my_name(std::move(s1)); // moves into by-value overload

    return 0;
}

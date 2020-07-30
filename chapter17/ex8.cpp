/* 
Programming: Principles and Practice Using C++
Chapter 17 Exercise 8:
    Do exercise 7 again, but this time read into a std::string rather than to memory you put on the free store.
    (string know how to use free store for you).
*/
#include <iostream>

int main() {
    std::string test;
    for (char ch = '0'; std::cin.get(ch) && ch != '!';) {
        test += ch;
    }
    std::cout << test << '\n';
}

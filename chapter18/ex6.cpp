/* 
Programming: Principles and Practice Using C++
Chapter 18 Exercise 6:
    Modify cat_dot() from previous exercise to take a string to be used as the separator(rather than dot) as its third argument.
*/
#include <iostream>

std::string cat_dot(const std::string& s1, const std::string& s2, const std::string& separator) {
    return s1 + separator + s2;
}

int main() {
    std::cout << cat_dot("Niels", "Bohr", "=") << '\n';
}

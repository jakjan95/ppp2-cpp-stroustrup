/* 
Programming: Principles and Practice Using C++
Chapter 18 Exercise 5:
    Write a function, string cat_dot(const string& s1, const string& s2), 
    that concatenates two strings with a dot in between. For example, cat_dot("Niels", "Bohr") will return a string containing Niels.Bohr.
*/
#include <iostream>

std::string cat_dot(const std::string& s1, const std::string& s2) {
    return s1 + '.' + s2;
}

int main() {
    std::cout << cat_dot("Niels", "Bohr") << '\n';
}

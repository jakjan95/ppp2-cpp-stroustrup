/* 
Programming: Principles and Practice Using C++
Chapter 17 Exercise 3:
    Write a function, void to_lower(char* s), that replaces all uppercase characters in the C-style string s with their lowercase equivalents.
    For example, Hello,World! becomes hello, world!. Do not use any standard library functions. 
    A C-style string is a zero-terminated array of cahracters, so if you find a char with value 0 you are at the end.
*/
#include <iostream>
//ASCII:
//A-Z 65-90
//a-z 97-122

void to_lower(char* s) {
    for (int i = 0; s[i]; ++i) {
        if (s[i] >= 65 && s[i] <= 90) {
            s[i] += 32;
        }
    }
}

int main() {
    char word[] = "Hello, World!";
    to_lower(word);
    std::cout << word << '\n';

    return 0;
}

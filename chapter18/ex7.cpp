/* 
Programming: Principles and Practice Using C++
Chapter 18 Exercise 7:
    Write version of the cat_dot()s from the previous exercises to take C-style strings 
    as arguments and return a free-store-allocated C-style string as the result. 
    Do not use standard library functions or types in the implementation. Test these functions with several strings. 
    Be sure to free(using delete) all the memory you allocated from free store(using new). Cinoare tge effort involved 
    in this exercise with the effort involved for exercises 5 and 6.

Conclusion:
    Using C-style need more effort than using a library version of string which deals free memory on it own. 
    By using C-style string we must deal with memory allocation and stuff like that.
*/
#include <iostream>

int strLen(const char* str) {
    int result = 0;
    while (*str++) {
        result++;
    }
    return result;
}

char* cat_dot(const char* s1, const char* s2, const char* sep) {
    int s1Len = strLen(s1);
    int s2Len = strLen(s2);
    int sepLen = strLen(sep);

    char* result = new char[s1Len + s2Len + sepLen];

    char* resultPtr = result;
    while (*s1) {
        *resultPtr++ = *s1++;
    }

    while (*sep) {
        *resultPtr++ = *sep++;
    }

    while (*s2) {
        *resultPtr++ = *s2++;
    }

    return result;
}

int main() {
    std::cout << cat_dot("Niels", "Bohr", "=") << '\n';
    std::cout << cat_dot("Name", "Surname", ".") << '\n';
    std::cout << cat_dot("F", "16", "-") << '\n';
    std::cout << cat_dot("banana", "banana", "==") << '\n';

    return 0;
}

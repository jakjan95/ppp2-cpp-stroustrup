/* 
Programming: Principles and Practice Using C++
Chapter 18 Exercise 2:
    Write a function, char* findx(const char* s, const char* x), that finds the first occurence of the C-style string x in s. 
    Do not use standard library functions. Do not use subscripting; use the dereference operator * instead
*/
#include <iostream>

const char* findx(const char* s, const char* x) {
    const char* sPtr = s;
    const char* xPtr = x;

    while (*sPtr++) {
        if (*sPtr == *xPtr) {
            while (*xPtr++ == *sPtr++) {
                if (!*xPtr) {
                    return x;
                }
            }
        }
    }
    return s;
}

int main() {
    char word1[] = "Crazy word with surprise inside!";
    char word2[] = "word";
    char word3[] = "ins";

    std::cout << findx(word1, word2) << '\n';
    std::cout << findx(word1, word3) << '\n';

    return 0;
}

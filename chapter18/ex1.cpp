/* 
Programming: Principles and Practice Using C++
Chapter 18 Exercise 1:
    Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store. 
    Do not use standard library functions. Do not use subscripting; use the dereference operator * instead
*/
#include <iostream>

int strLen(const char* w) {
    int length = 0;
    while (*w++) {
        length++;
    }
    return length;
}

char* strdup(const char* w) {
    int wordLength = strLen(w);
    char* wordCopy = new char[wordLength];

    char* ptr = wordCopy;
    while (*w) {
        *ptr++ = *w++;
    }
    return wordCopy;
}

int main() {
    char* word = strdup("Long sentence here!");
    std::cout << word << '\n';
    delete word;

    return 0;
}

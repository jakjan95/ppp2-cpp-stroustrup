/* 
Programming: Principles and Practice Using C++
Chapter 18 Exercise 3:
    Write a function, int strcmp(const char* s1, const char* s2), that compares C-style strings. 
    Let it run a negative number if s1 is lexicographically before s2, zero if s1 equals s2, and positive number if s1 is lexicographically after s2. 
    Do not use standard library functions. Do not use subscripting; use the dereference operator * instead
*/
#include <iostream>

int strcmp(const char* s1, const char* s2) {
    int result = 0;
    while (*s1++ && *s2++) {
        if (*s1 > *s2) {
            result--;
        } else if (*s1 < *s2) {
            result++;
        }
    }

    return result;
}

int main() {

    std::cout<<strcmp("abcd", "abcd")<<'\n';
    std::cout<<strcmp("abcd", "bacd")<<'\n';
    std::cout<<strcmp("bacd", "abcd")<<'\n';

    return 0;
}

/* 
Programming: Principles and Practice Using C++
Chapter 17 Exercise 5:
    Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in s.
*/
#include <iostream>

//returning s when we don't find anything
//returning x wen we find x in s
const char* findx(const char* s, const char* x) {
    for (int i = 0; s[i]; ++i) {
        if (s[i] == x[0]) {
            for (int j = 1; x[j]; j++) {
                if (s[i + j] != x[j]) {
                    break;
                }
                if (x[j + 1] == 0) {
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
    char word3[] = "ith";

    std::cout << findx(word1, word2) << '\n';
    std::cout << findx(word1, word3) << '\n';

    return 0;
}

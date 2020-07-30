/* 
Programming: Principles and Practice Using C++
Chapter 17 Exercise 4:
    Write a function, char* strdup(const char*), that copies C-Style string into memory it allocates on the free store.
    Do not use any standard library functions.
*/
#include <iostream>

int getWordLength(const char* word) {
    int wordLength = 0;
    while (*word++) {
        wordLength++;
    }

    return wordLength + 1;
}

char* strdup(const char* word) {
    int wordLength = getWordLength(word);
    char* wordCopy = new char[wordLength];

    char* ptr = wordCopy;
    while (*word) {
        *ptr++ = *word++;
    }

    //Other way:
    // for (int i = 0; i < wordLength; ++i) {
    //     wordCopy[i] = word[i];
    // }

    return wordCopy;
}

int main() {
    char* word = strdup("Long sentence here!");
    std::cout << word << '\n';
    delete word;

    return 0;
}

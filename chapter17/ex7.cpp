/* 
Programming: Principles and Practice Using C++
Chapter 17 Exercise 7:
    Write a program that reads characters from cin into an array that you allcoate on the free store.
    Read inidivdual cahracters until an exclamination mark(!) is entered. Do not use a std::string.
*/
#include <iostream>

int getWordLength(const char* word) {
    int wordLength = 0;
    while (*word++) {
        wordLength++;
    }

    return wordLength;
}

char* addCharacter(char* word, char ch) {
    int length = getWordLength(word);
    char* extendedWord = new char[length + 1];

    for (int i = 0; i < length; ++i) {
        extendedWord[i] = word[i];
    }

    extendedWord[length] = ch;

    delete[] word;
    return extendedWord;
}

int main() {
    char* test = new char;
    for (char ch = '0'; std::cin.get(ch) && ch != '!';) {
        test = addCharacter(test, ch);
    }

    std::cout << test << '\n';
    delete test;
}

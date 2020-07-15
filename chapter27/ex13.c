/* 
Programming: Principles and Practice Using C++
Chapter 27 Exercise 14:
    Write a program that does the equivalent of string s; cin>>s; in C; 
    that is, define an input operation that reads an arbitrarily long 
    sequence of whitespace-terminated characters into a zero-terminated array of chars.
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char* get_word() {
    int max = 5;
    int count = 0;
    int c;
    char* word = (char*)malloc(max);
    while ((c = getchar()) != EOF && !isspace(c)) {
        if (count == max - 1) {
            max += max;
            word = (char*)realloc(word, max);
            if (word == 0) {
                break;
            }
        }
        word[count++] = c;
    }
    return word;
}

int main() {
    char* word = get_word();
    printf("%s \n", word);

    return 0;
}
/* 
Programming: Principles and Practice Using C++
Chapter 27 Exercise 1:
    Implement your own version of strlen(), strcmp() and strcpy().
*/

#include <stdio.h>

size_t my_strlen(const char* s) {
    size_t counter = 0;
    while (*s++) {
        counter++;
    }
    return counter;
}

int my_strcmp(const char* s1, const char* s2) {
    int result = 0;
    while (*s1++ && *s2++) {
        if (*s1 > *s2) {
            result++;
        }
        if (*s1 < *s2) {
            result--;
        }
    }
    return result;
}

//s1 must be char s1[];
char* my_strcpy(char* s1, const char* s2) {
    while (*s1++ = *s2++)
        ;
    return s1;
}

int main() {
    const char* str = "word";
    printf("length of %s is %ld \n", str, my_strlen(str));
    printf("%d \n", my_strcmp("ABCDEF", "ABCDEF"));
    char str1[] = "aaaa";
    const char* str2 = "baba";
    my_strcpy(str1, str2);
    printf("str1 after copying=%s\n", str1);
    return 0;
}
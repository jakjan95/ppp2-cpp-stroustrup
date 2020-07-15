/* 
Programming: Principles and Practice Using C++
Chapter 27 Exercise 9:
    Using only C facilities, including the C standard library, 
    read a sequence of words from stdin and write them to stdout in lexicographical order. 
    Hint: The C sort function is called qsort(); look it up somewhere. 
    Alternatively, insert the words int oan order list as you read them. There is no C standard library list.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 10
#define MAX_WORD_LENGTH 10

char* get_word() {
    char* word = (char*)malloc(MAX_WORD_LENGTH);
    int i;
    int x;
    for (i = 0; (x = getchar()) && x != '\n' && i < MAX_WORD_LENGTH; ++i) {
        word[i] = x;
    }
    word[++i] = '\0';
    return word;
}

//Alternative and easier version for loading words
// char* get_word(){
//     char* word = (char*)malloc(MAX_WORD_LENGTH);
//     scanf("%s", word);
//     return word;
// }

void print_table(char* table[], int sz) {
    int i;
    for (i = 0; i < sz; i++) {
        printf("tab[%d] = %s \n", i, table[i]);
    }
}

int strings_comparing(const void* a, const void* b) {
    char* _a = *(char**)a;
    char* _b = *(char**)b;
    return strcmp(_a, _b);
}

int main() {
    char* words[ARRAY_SIZE];

    printf("Enter %d words : \n", ARRAY_SIZE);
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("Still %d left:  ", ARRAY_SIZE - i);
        words[i] = get_word();
    }

    print_table(words, sizeof(words) / sizeof(*words));
    qsort(words, ARRAY_SIZE, sizeof(char*), strings_comparing);
    printf("Table after sorting: \n");
    print_table(words, sizeof(words) / sizeof(*words));
    return 0;
}
/* 
Programming: Principles and Practice Using C++
Chapter 27 Exercise 12:
    Implement a (C-style string, int) lookup table with operations such as:
    find(struct table*, const char*), insert(struct table*, const char*, int), and remove(struct table*, const char*).
    The representation of the table could be an array of a struct pair or a pair of arrays(const char*[] and int*); you choose.
    Also choose return types for your functions. Document your design decisions.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pair {
    const char* string;
    int value;
};

struct Pair* make_pair(const char* str, int val) {
    struct Pair* p = (struct Pair*)malloc(sizeof(struct Pair));
    p->string = str;
    p->value = val;
    return p;
}

struct table {
    struct Pair* array;  //first element of an array
    int size;
    int capacity;
};

struct table* create_table() {
    struct table* tab = (struct table*)malloc(sizeof(struct table));  //memory allocation for table
    tab->size = 0;
    tab->capacity = 0;
    tab->array = NULL;
    return tab;
}

void table_resize(struct table* tab) {
    const int base_array_size = 10;

    if (tab->capacity == 0) {
        tab->array = (struct Pair*)malloc(sizeof(struct Pair) * base_array_size);
        tab->capacity = base_array_size;
        return;
    } else if (tab->size == tab->capacity) {
        tab->array = (struct Pair*)realloc(tab->array, sizeof(struct Pair) * tab->capacity * 2);
        tab->capacity *= 2;
        return;
    }
}

void insert(struct table* tab, const char* str, int val) {
    table_resize(tab);
    tab->array[tab->size] = *make_pair(str, val);
    (tab->size)++;
}

//Function returns index of element when it finds it, otherwise it returns -1;
int find(struct table* tab, const char* str) {
    int i;
    for (i = 0; i < tab->size; i++) {
        if (strcmp(tab->array[i].string, str) == 0) {
            return i;
        }
    }
    return -1;
}

void print_table(struct table* tab) {
    int i;
    for (i = 0; i < tab->size; i++) {
        printf("%s : %d\n", tab->array[i].string, tab->array[i].value);
    }
}

void remove_element(struct table* tab, const char* str) {
    int to_remove = find(tab, str);
    if (to_remove == -1) {
        return;
    }

    int i = to_remove;
    for (i; i < tab->size - 1; i++) {
        tab->array[i] = tab->array[i + 1];
    }

    (tab->size)--;
}

int main() {
    struct table* numbers = create_table();

    insert(numbers, "zero", 0);
    insert(numbers, "one", 1);
    insert(numbers, "two", 2);
    insert(numbers, "three", 3);
    insert(numbers, "four", 4);
    insert(numbers, "five", 5);
    insert(numbers, "six", 6);
    insert(numbers, "seven", 7);
    print_table(numbers);

    int findFive = find(numbers, "five");
    if (findFive != -1) {
        printf("Number five found at index %d. It's value: %s-%d \n",
               findFive, numbers->array[findFive].string, numbers->array[findFive].value);
    }

    //Element removing from lookup table
    printf("Removing of number: four\n");
    remove_element(numbers, "four");
    print_table(numbers);

    //Inserting after removing
    printf("Inserting eight\n");
    insert(numbers, "eight", 8);
    print_table(numbers);

    return 0;
}
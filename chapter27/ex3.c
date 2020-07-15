/* 
Programming: Principles and Practice Using C++
Chapter 27 Exercise 3:
    "Pretty up" the intrusive List example in 27.9 as best you can to make it convienient to use. 
    Do catch/handle as many errors as you can. 
    It is fair game to change the details of the struct definitions, to use macros, whatever.

For this exercise I added simple conditions checking.
Instead of assert() we can returning error code which is -1 or 0 if function was successful,
this error code we can use later to error handling.
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct List {
    struct Link* first;
    struct Link* last;
};

struct Link {
    struct Link* pre;
    struct Link* succ;
};

//Initialization of list
void init(struct List* lst) {
    assert(lst);
    lst->first = lst->last = 0;
}

//it creates list in free memory
struct List* create() {
    struct List* lst = (struct List*)malloc(sizeof(struct List));
    init(lst);
    return lst;
}

//freeing memory for Links
void clear(struct List* lst) {
    assert(lst);
    {
        struct Link* curr = lst->first;
        while (curr) {
            struct Link* next = curr->succ;
            free(curr);
            curr = next;
        }
        lst->first = lst->last = 0;
    }
}

void destroy(struct List* lst) {
    assert(lst);
    clear(lst);
    free(lst);
}

//adding p at the back
void push_back(struct List* lst, struct Link* p) {
    assert(lst);
    if (p) {
        struct Link* last = lst->last;
        if (last) {
            last->succ = p;
            p->pre = last;
        } else {
            lst->first = p;
            p->pre = 0;
        }
        lst->last = p;
        p->succ = 0;
    }
}
//add p at front of lst
void push_front(struct List* lst, struct Link* p) {
    assert(lst);
    if (p) {
        struct Link* first = lst->first;
        if (first) {
            first->pre = p;
            p->succ = first;
        } else {
            lst->last = p;
            p->succ = 0;
        }

        lst->first = p;
        p->pre = 0;
    }
}

//insert q before p
void insert(struct List* lst, struct Link* p, struct Link* q) {
    assert(lst);
    if (p) {
        if (p == lst->first) {
            q->pre = 0;
            lst->first = q;
        } else {
            q->pre = p->pre;
            p->pre->succ = q;
        }
        p->pre = q;
        q->succ = p;
    }
}

//erasing p from list, returning pointer to a link after p
struct Link* erase(struct List* lst, struct Link* p) {
    assert(lst);
    if (!p) {
        return NULL;
    }

    if (p == lst->first) {
        if (p->succ) {
            lst->first = p->succ;
            p->succ->pre = 0;
            return p->succ;
        } else {
            lst->first = lst->last = 0;
            return 0;
        }
    } else if (p == lst->last) {
        if (p->pre) {
            lst->last = p->pre;
            p->pre->succ = 0;
        } else {
            lst->first = lst->last = 0;
            return 0;
        }
    } else {
        p->succ->pre = p->pre;
        p->pre->succ = p->succ;
        return p->succ;
    }
}

//Return link n "hops" before or after p
struct Link* advance(struct Link* p, int n) {
    if (!n) {
        return p;
    }

    if (n > 0) {
        while (n--) {
            if (!p->succ) {
                return p;
            }
            p = p->succ;
        }
    } else {
        while (n++) {
            if (!p->pre) {
                return p;
            }
            p = p->pre;
        }
    }
    return p;
}

struct Name {
    struct Link lnk;
    char* p;
};

struct Name* make_name(char* n) {
    struct Name* ptr = (struct Name*)malloc(sizeof(struct Name));
    ptr->p = n;
    return ptr;
}

void print_list(struct List* lst) {
}
/*------------------------------------------------------------------------*/

int main() {
    struct List names;
    struct Link* curr;
    init(&names);

    //make few names and add them to a list:
    push_back(&names, (struct Link*)make_name("Norah"));
    push_back(&names, (struct Link*)make_name("Annemarie"));
    push_back(&names, (struct Link*)make_name("Kris"));
    push_back(&names, (struct Link*)NULL);
    push_front(&names, (struct Link*)make_name("Katie"));

    //Delete the second name(index 1):
    erase(&names, advance(names.first, 1));

    //Insert before first element:
    insert(&names, names.first, (struct Link*)make_name("test1"));
    //Insert in middle(before 3rd element):
    insert(&names, advance(names.first, 2), (struct Link*)make_name("test2"));
    erase(&names, (struct Link*)NULL);
    
    int count = 0;
    curr = names.first;
    for (; curr != 0; curr = curr->succ) {
        count++;
        printf("element %d: %s\n", count, ((struct Name*)curr)->p);
    }

    return 0;
}
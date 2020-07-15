/* 
Programming: Principles and Practice Using C++
Chapter 27 Exercise 2:
    Complete the itursive List example in 27.9 and test it using every function.

Missing functions:
void push_front(struct List* lst, struct Link* p);
void insert(struct List* lst, struct Link* p, struct Link* q);
struct Link* advance(struct Link* p, int n);
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
    {
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
    {
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
    {
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
    if (p == 0) {
        return 0;
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
    if (n == 0) {
        return p;
    }

    if (n > 0) {
        while (n--) {
            p = p->succ;
        }
    } else if (n < 0) {
        while (n++) {
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
    struct Name* p = (struct Name*)malloc(sizeof(struct Name));
    p->p = n;
    return p;
}
/*------------------------------------------------------------------------*/

int main() {
    int count = 0;
    struct List names;
    struct Link* curr;
    init(&names);

    //make few names and add them to a list:
    push_back(&names, (struct Link*)make_name("Norah"));
    push_back(&names, (struct Link*)make_name("Annemarie"));
    push_back(&names, (struct Link*)make_name("Kris"));
    push_front(&names, (struct Link*)make_name("Katie"));

    //Delete the second name(index 1):
    erase(&names, advance(names.first, 1));
    
    //Insert before first element:
    insert(&names,names.first,(struct Link*)make_name("test1"));
    //Insert in middle(before 3rd element):
    insert(&names,advance(names.first, 2),(struct Link*)make_name("test2"));
    
    curr = names.first;
    for (; curr != 0; curr = curr->succ) {
        count++;
        printf("element %d: %s\n", count, ((struct Name*)curr)->p);
    }

    return 0;
}
/* 
Programming: Principles and Practice Using C++
Chapter 17 Exercise 14:
    Could the "list of gods" example from 17.10.1 have been written using a singly-linked list;
    that is, could we have left the prev member out of Link? Why might we want to do that? 
    For what kind of examples would it make sense to use sigly-linked list?
    Re-implement that example using only a singly-linked list.
*/

#include <iostream>
#include "SingleLink.hpp"

void print_all(SingleLink* p) {
    std::cout << "{ ";
    while (p) {
        std::cout << p->value;
        if (p = p->next()) {
            std::cout << ", ";
        }
    }
    std::cout << " }\n";
}

int main() {
    SingleLink* norse_gods = new SingleLink{"Thor"};
    norse_gods = norse_gods->insert(new SingleLink{"Odyn"});
    norse_gods = norse_gods->insert(new SingleLink{"Zeus"});
    norse_gods = norse_gods->insert(new SingleLink{"Freia"});

    SingleLink* greek_gods = new SingleLink{"Hera"};
    greek_gods = greek_gods->insert(new SingleLink{"Atena"});
    greek_gods = greek_gods->insert(new SingleLink{"Mars"});
    greek_gods = greek_gods->insert(new SingleLink{"Poseidon"});

    SingleLink* p = greek_gods->find("Mars");
    if (p) {
        p->value = "Ares";
    }

    SingleLink* p2 = norse_gods->find("Zeus");
    if (p2) {
        if (p2 == norse_gods) {
            norse_gods = p2->next();
        }
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }
    print_all(norse_gods);
    print_all(greek_gods);

    // Link* p3 = greek_gods->find("Poseidon");
    // std::cout << "p3 before advance: " << p3->value << '\n';
    // p3 = p3->advance(1);
    // std::cout << "p3 after advance(1): " << p3->value << '\n';
    std::cout<< greek_gods->value<<'\n';
    return 0;
}

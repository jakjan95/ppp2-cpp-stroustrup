/* 
Programming: Principles and Practice Using C++
Chapter 17 Exercise 10:
    Complete the "list of gods" example from 17.1.1 and run it.

Functions to write:
    Link* add(Link* n);
    Link* erase();
    Link* find(const std::string& s);

    Link* advance(int n) const;
*/
#include <iostream>
#include "Link.hpp"

void print_all(Link* p) {
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
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odyn"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Atena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    Link* p = greek_gods->find("Mars");
    if (p) {
        p->value = "Ares";
    }

    Link* p2 = norse_gods->find("Zeus");
    if (p2) {
        if (p2 == norse_gods) {
            norse_gods = p2->next();
        }
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }
    print_all(norse_gods);
    print_all(greek_gods);

    Link* p3 = greek_gods->find("Poseidon");
    std::cout << "p3 before advance: " << p3->value << '\n';
    p3 = p3->advance(1);
    std::cout << "p3 after advance(1): " << p3->value << '\n';

    return 0;
}

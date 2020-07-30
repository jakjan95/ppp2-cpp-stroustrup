/* 
Programming: Principles and Practice Using C++
Chapter 17 Exercise 9:
    Which way does the stack grow: up(toward higher addresses) or down(toward lower addresses)?
    Which way does the free store(heap) initially grow(that is, before you use delete)?
    Write a program to determine the answers.
*/
#include <iostream>

//growth towards lower addresses
void stackGrowth() {
    std::cout << "Stack: \n";
    int first = 15;
    bool second = true;
    double third = 2.5;
    std::cout << "&first == " << &first << '\t'
              << "&second == " << &second << '\t'
              << "&third == " << &third << '\n';
}


//grow towards higher addreses
void heapGrowth() {
    std::cout << "Free memory - heap: \n";
    int* first = new int{1};
    bool* second = new bool{true};
    double* third = new double{2.5};
    std::cout << "first == " << first << '\t'
              << "second == " << second << '\t'
              << "third == " << third << '\n';
}

int main() {
    stackGrowth();
    heapGrowth();

    return 0;
}

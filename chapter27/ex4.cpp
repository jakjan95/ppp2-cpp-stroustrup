/* 
Programming: Principles and Practice Using C++
Chapter 27 Exercise 4:
    Write C++ version of intrusive List and test is using every function.

In this exercise I can't deal with getting name_ form Name class,
basically it is derived class and as we use Link in our List, 
Link doesn't know anything about extra stuff added in derived class Name.

I made this homework easier by putting std::string name_ inside Link structure to make this exercise doable, 
other implementation like function for List remain the same regardless of implementation.

Type in this in command to run example: g++ ex4.cpp ex4List.cpp -o ex4
*/
#include <iostream>

#include "ex4List.hpp"

int main() {

    List test_list;
    test_list.push_back(new Link("First"));
    test_list.push_back(new Link("Second"));
    test_list.push_front(new Link("Zero"));
    test_list.push_back(new Link("Third"));
    test_list.push_back(new Link("Fourth"));
    test_list.push_back(new Link("Fifth"));
    test_list.push_front(new Link("Below zero"));

    print(test_list);

    //Advance test:
    auto second_element = advance(test_list.begin(), 3);
    std::cout << second_element->name_ << '\n';

    //Insert test
    test_list.insert(second_element, new Link("Before Second :)"));
    test_list.insert(test_list.begin(), new Link("Before Begin :)"));
    test_list.insert(test_list.end(), new Link("Before End :)"));

    print(test_list);

    //Erase test:
    std::cout << "Erase test:\n";
    test_list.erase(test_list.begin());
    test_list.erase(test_list.end());
    test_list.erase(advance(test_list.begin(), 3));
    print(test_list);

    return 0;
}
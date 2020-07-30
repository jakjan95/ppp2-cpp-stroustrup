/* 
Programming: Principles and Practice Using C++
Chapter 17 Exercise 2:
    How many bytes are there in an int? In a double? In a bool? Do not use sizeof except to verify your answer.
*/
#include <iostream>

int main() {

    /*
        int - 4 bytes
        double - 8 bytes
        bool - 1 byte
    */
    std::cout<<"sizeof(int) == "<<sizeof(int)<<'\n';
    std::cout<<"sizeof(double) == "<<sizeof(double)<<'\n';
    std::cout<<"sizeof(bool) == "<<sizeof(bool)<<'\n';

    return 0;
}


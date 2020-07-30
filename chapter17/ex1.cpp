/* 
Programming: Principles and Practice Using C++
Chapter 17 Exercise 1:
    What is the output format of pointer values on your implementation?
*/
#include <iostream>


int main() {
    int a = 5;
    int* ptr = &a;
    std::cout << ptr << '\n';
    
    //0x7ffe58fbd24c
    //Output of pointer value is hexadecimal
    return 0;
}

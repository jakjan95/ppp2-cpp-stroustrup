/* 
Programming: Principles and Practice Using C++
Chapter 27 Exercise 8:
    What is the lexicographical order on your machine? 
    Write ouy every character on your keyboard together with its integer value; 
    then, write the caracters out in order determined by their integer value.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void print_table(std::vector<char> vec) {
    for (auto el : vec) {
        std::cout << el << ':' << static_cast<int>(el) << '\t';
    }
    std::cout << '\n';
}

int main() {
    std::vector<char> keyboard_characters = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+',
                                             '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
                                             'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', 'A', 'S', 'D', 'F',
                                             'G', 'H', 'J', 'K', 'L', ':', '"', '|', '|',
                                             'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 'q', 'w', 'e', 'r', 't', 'y',
                                             'u', 'i', 'o', 'p', '[', ']', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
                                             '\'', '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
    std::cout << "Before sorting:\n ";
    print_table(keyboard_characters);
    std::sort(keyboard_characters.begin(), keyboard_characters.end());
    std::cout << "After sorting by their int value:\n ";
    print_table(keyboard_characters);
    return 0;
}
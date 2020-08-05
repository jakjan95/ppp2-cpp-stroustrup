/* 
Programming: Principles and Practice Using C++
Chapter 19 Exercise 3:
    Write a template function that takes a vector<T> vt and a vector<U> vu as arguments and returns the sum of all vt[i]*vu[i]s
*/

#include <iostream>
#include <vector>
template <typename T, typename U>
class Pair {
public:
    Pair(T first, U second)
        : first_{first}, second_{second} {}

    T getFirst() const {
        return first_;
    }

    U getSecond() const {
        return second_;
    }

private:
    T first_;
    U second_;
};

int main() {
    std::vector<Pair<std::string, int>> vectorOfPairs{Pair<std::string, int>("pi", 3.14), Pair<std::string, int>("e", 2.7)};
    vectorOfPairs.emplace_back(Pair<std::string, int>("zero", 0));
    for (auto el : vectorOfPairs) {
        std::cout << "KEY:" << el.getFirst() << "\tVALUE:" << el.getSecond() << '\n';
    }
    return 0;
}

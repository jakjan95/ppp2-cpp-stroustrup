/* 
Programming: Principles and Practice Using C++
Chapter 19 Exercise 2:
    Write a template function that takes a vector<T> vt and a vector<U> vu as arguments and returns the sum of all vt[i]*vu[i]s
*/
#include <iostream>
#include <vector>

template <typename T, typename U>
T elementsSum(const std::vector<T>& vec1, const std::vector<U>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::runtime_error("vectors in different size\n");
    }

    T val = T();

    for (size_t i = 0; i < vec1.size(); ++i) {
        val += vec1[i] * vec2[i];
    }
    return val;
}

int main() {
    std::vector<int> v2{1, 2, 3, 4};
    std::vector<double> v1{1.1, 2.1, 3.1, 4.1};
    std::cout << elementsSum(v1, v2) << '\n';
    return 0;
}

/* 
Programming: Principles and Practice Using C++
Chapter 19 Exercise 1:
    Write a template function f() that adds the elements of one vector<T> to the elements of another;
    for example, f(v1, v2) should do v1[i] += v2[i] for each element of v1.
*/
#include <iostream>
#include <vector>

template <typename T>
void f(std::vector<T>& v1, const std::vector<T>& v2) {
    if (v2.size() < v1.size()) {
        throw std::out_of_range("not enougn elements in second vector");
    }

    for (size_t i = 0; i < v1.size(); i++) {
        v1[i] += v2[i];
    }
}

template <typename T>
void printVec(const std::vector<T> vec) {
    for (auto el : vec) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    try {
        std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7};
        std::vector<int> vec2(vec1.size(), 3);

        printVec(vec1);
        printVec(vec2);

        f(vec1, vec2);
        printVec(vec1);

        //std::out_of_range:
        // std::vector<int> vv1{1, 2, 3};
        // std::vector<int> vv2{1, 1};
        // f(vv1, vv2);
        // printVec(vv1);

        std::vector<std::string> strVec1{"word1", "word2", "word3"};
        std::vector<std::string> strVec2{"@1", "@2", "@3"};
        f(strVec1, strVec2);
        printVec(strVec1);

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown error!\n";
    }

    return 0;
}

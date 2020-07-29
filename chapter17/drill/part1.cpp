#include <iostream>
#include <vector>

//ex4:
std::ostream& print_array10(std::ostream& os, int* a) {
    for (size_t i = 0; i < 10; i++) {
        os << a[i] << ' ';
    }
    os << '\n';
    return os;
}

//ex7
std::ostream& print_array(std::ostream& os, int* a, int n) {
    for (size_t i = 0; i < n; i++) {
        os << a[i] << ' ';
    }
    os << '\n';
    return os;
}

std::ostream& print_vector(std::ostream& os, const std::vector<int>& v) {
    for (auto el : v) {
        os << el << ' ';
    }
    os << '\n';
    return os;
}

int main() {
    //Part 1:
    //ex1:
    int* arr = new int[10];

    //ex2:
    for (size_t i = 0; i < 10; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    //ex3:
    delete[] arr;

    //ex5:
    int* arr2 = new int[10]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    print_array10(std::cout, arr2);
    delete[] arr2;

    //ex6:
    int* arr3 = new int[11]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    print_array(std::cout, arr3, 11);
    delete[] arr3;

    //ex8:
    size_t arraySize = 20;
    int* arr4 = new int[arraySize];
    for (size_t i = 0; i < arraySize; ++i) {
        arr4[i] = 100 + i;
    }
    print_array(std::cout, arr4, arraySize);
    delete[] arr4;
    //ex9: delete all arrays after allocations

    //ex10:
    std::cout<<"Vectors:\n";
    std::vector<int> v1{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    print_vector(std::cout, v1);

    std::vector<int> v2{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    print_vector(std::cout, v2);

    std::vector<int> v3(20);
    for (size_t i = 0; i < v3.size(); ++i) {
        v3[i] = 100 + i;
    }
    print_vector(std::cout, v3);
    return 0;
}

#include <iostream>
#include <vector>

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
    //ex1:
    int num = 7;
    int* p1 = &num;

    //ex2:
    std::cout << "p1 == " << p1 << "\t*p1 == " << *p1 << '\n';

    //ex3:
    int* p2 = new int[7]{1, 2, 4, 8, 16, 32, 64};

    //ex4:
    std::cout << "p2 == " << p2 << '\n';
    print_array(std::cout, p2, 7);

    //ex5
    int* p3 = p2;

    //ex6
    p1 = p2;

    //ex7
    p3 = p2;

    //ex8
    std::cout << "p1 == " << p1 << "\t*p1 == " << *p1 << '\n';
    std::cout << "p2 == " << p2 << "\t*p2 == " << *p2 << '\n';

    //ex9
    delete[] p3;

    //ex10
    p1 = new int[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

    //ex11
    p2 = new int[10];
    for (int i = 0; i < 10; i++) {
        p2[i] = p1[i];
    }

    print_array(std::cout, p1, 10);
    print_array(std::cout, p2, 10);

    delete[] p2;
    delete[] p1;

    //ex13
    std::vector<int> v1{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    std::vector<int> v2(10);
    v2 = v1;
    print_vector(std::cout, v1);
    print_vector(std::cout, v2);
    return 0;
}

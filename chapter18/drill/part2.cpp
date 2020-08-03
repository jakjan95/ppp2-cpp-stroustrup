#include <iostream>
#include <vector>

//ex1
std::vector<int> gv{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void printVector(const std::vector<int>& v) {
    for (const auto& el : v) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

//ex2
void f(const std::vector<int>& v) {
    //ex3:
    std::vector<int> lv(v.size());
    lv = gv;
    printVector(lv);
    std::vector<int> lv2(v);
    printVector(lv2);
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    f(gv);

    std::vector<int> vv(10);
    for (int i = 0; i < vv.size(); i++) {
        vv[i] = factorial(i + 1);
    }
    f(vv);
    return 0;
}

#include <iostream>

//ex1
int ga[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void printTable(int tab[], int sz) {
    for (size_t i = 0; i < sz; ++i) {
        std::cout << tab[i] << ' ';
    }
    std::cout << '\n';
}

//ex2
void f(int tab[], int sz) {
    //ex3:
    int la[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::copy(tab, tab + sz, la);
    printTable(la, sz);
    int* p = new int[sz];
    std::copy(tab, tab + sz, p);
    printTable(p, sz);
    delete[] p;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    //ex4:
    f(ga, 10);

    int aa[10] = {0};
    for (int i = 0; i < 9; i++) {
        aa[i] = factorial(i + 1);
    }
    printTable(aa, 10);
    f(aa, 10);
    return 0;
}

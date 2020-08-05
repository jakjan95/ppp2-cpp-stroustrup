/* 
Programming: Principles and Practice Using C++
Chapter 19 Exercise 5:
    Define a class Int having a single member of class int. 
    Define constructors, assignment, and operators +, 0, *, / for it. 
    Test it, and improve its design as needed(e.g. define operators << and >> for convenient I/O)
*/
#include <iostream>

class Int {
public:
    Int()
        : val_{0} {}
    Int(int val)
        : val_{val} {}

    Int(const Int& v)
        : val_{v.val_} {}

    Int& operator=(const Int& v) {
        val_ = v.val_;
        return *this;
    }

    int getValue() const {
        return val_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Int& i) {
        os << i.val_;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Int& i) {
        is >> i.val_;
        return is;
    }

    Int operator+(const Int& val2) {
        Int temp(getValue() + val2.getValue());
        return temp;
    }

    Int operator-(const Int& val2) {
        Int temp(getValue() - val2.getValue());
        return temp;
    }

    Int operator*(const Int& val2) {
        Int temp(getValue() * val2.getValue());
        return temp;
    }

    Int operator/(const Int& val2) {
        Int temp(getValue() / val2.getValue());
        return temp;
    }

private:
    int val_;
};

Int returnInt() {
    Int zz(15);
    std::cout << zz << " - " << &zz << '\n';
    return zz;
}

int main() {
    Int a(10);
    Int b = a;
    Int c(2);
    std::cout << a << '\t' << b << '\t' << c << '\n';
    std::cout << a + c << '\n';
    Int d = a / c;
    std::cout << d << '\n';
    std::cin >> d;
    std::cout << d << '\n';

    Int z = returnInt();
    std::cout << z << " - " << &z << '\n';

    return 0;
}

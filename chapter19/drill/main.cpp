#include <iostream>
#include <vector>

//ex1
template <typename T>
struct S {
    //ex2
    S(T v)
        : val{v} {}

    //ex5
    T& get();
    const T& get() const;

    //ex9
    // void set(T v){
    //     val = v;
    // }

    S& operator=(const T& v);

    friend std::ostream& operator<<(std::ostream& os, const S<T>& s) {
        os << s.get();
        return os;
    }

    friend std::istream& operator>>(std::istream& io, S<T>& s) {
        io >> s.val;
        return io;
    }

private:
    T val;
};

//ex6
template <typename T>
T& S<T>::get() {
    return val;
}

//ex10
template <typename T>
const T& S<T>::get() const {
    return val;
}

//ex9
template <typename T>
S<T>& S<T>::operator=(const T& v) {
    val = v;
    return *this;
}

template <typename T>
void read_val(T& v) {
    std::cin >> v;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "{";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    char ch;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T v; is >> v;) {
        vec.push_back(v);
        is >> ch;
        if (ch != ',' || ch == '}') {
            break;
        }
    }
    return is;
}

int main() {
    //ex3:
    S<int> s1{1};
    S<char> s2{'a'};
    S<double> s3{1.1};
    S<std::string> s4{"word"};
    std::vector<int> v1{1, 2, 3, 4};
    S<std::vector<int>> s5{v1};

    //ex4:
    // std::cout << "S<int> s1{1} == " << s1.val << '\n'
    //           << "S<char> s2{'a'} == " << s2.val << '\n'
    //           << "S<double> s3{1.1} == " << s3.val << '\n'
    //           << "S<std::string> s4{\"word\"} == " << s4.val << '\n';

    // std::cout << "S<std::vector<int>> s5{v1}; == { ";
    // for (auto el : s5.val) {
    //     std::cout << el << ' ';
    // }
    // std::cout << " }\n";

    //ex8:
    s1 = 5;
    std::cout << "S<int> s1{1} == " << s1.get() << '\n'
              << "S<char> s2{'a'} == " << s2.get() << '\n'
              << "S<double> s3{1.1} == " << s3.get() << '\n'
              << "S<std::string> s4{\"word\"} == " << s4.get() << '\n';

    std::cout << "S<std::vector<int>> s5{v1}; == { ";
    for (auto el : s5.get()) {
        std::cout << el << ' ';
    }
    std::cout << " }\n";

    //ex13
    std::cout << "S<int> s1 = \n";
    read_val(s1);
    std::cout << "S<char> s2{'a'}= \n";
    read_val(s2);
    std::cout << "S<double> s3{1.1}= \n";
    read_val(s3);
    std::cout << "S<std::string> s4{\"word\"}= \n";
    read_val(s4);

    std::cout << "S<int> s1{1} == " << s1 << '\n'
              << "S<char> s2{'a'} == " << s2 << '\n'
              << "S<double> s3{1.1} == " << s3 << '\n'
              << "S<std::string> s4{\"word\"} == " << s4 << '\n';

    //ex14:
    std::cout << " S<std::vector<int>> s5{v1}= \n";
    read_val(s5);
    std::cout << "S<std::vector<int>> s5{v1} = " << s5 << '\n';

    return 0;
}

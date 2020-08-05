/* 
Programming: Principles and Practice Using C++
Chapter 19 Exercise 10:
    Implement a simple unique_ptr supporting only a constructor, destructor, ->, *, and release().
    In particular, don't try to impelement an assignment or a copy constructor.
Conclusion:
    Tested by valgrind -> no leaks :) 
*/
#include <iostream>

template <typename T>
class UniquePtr {
public:
    UniquePtr(T* ptr)
        : p{ptr} {}

    ~UniquePtr() {
        delete p;
    }

    T* release() {
        T* q = p;
        p = nullptr;
        return q;
    }

    T operator*() const {
        return *p;
    }

    T* operator->() const {
        return p;
    }

private:
    T* p;
};

UniquePtr<int> fun(int n) {
    UniquePtr<int> ptr{new int{n}};
    return ptr;
}

UniquePtr<int> fun2(int n) {
    UniquePtr<int> ptr{new int{n}};
    return ptr.release();
}

int* fun3(int n) {
    UniquePtr<int> ptr{new int{n}};
    return ptr.release();
}

int main() {
    UniquePtr<int> p{new int{10}};
    std::cout << *p << '\n';

    UniquePtr<int> b = fun(5);
    std::cout << *b << '\n';

    UniquePtr<int> c = fun2(51);
    std::cout << *c << '\n';

    int* ptr = fun3(12);
    std::cout << *ptr << '\n';
    delete ptr;
    return 0;
}

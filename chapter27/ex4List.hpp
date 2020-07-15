#pragma once

#include <string>

struct Link {
    Link();
    Link(std::string name);

    Link* prev_;
    Link* suc_;
    std::string name_;
};

Link* advance(Link* element, int value);

//Unworking
// class Name : public Link {
// public:
//     Name()
//         : Link(), name_{""} {}

//     Name(std::string name)
//         : Link(), name_{name} {}

//     std::string getName() const {
//         return name_;
//     }
// private:
//     std::string name_;
// };

class List {
public:
    List();

    ~List() = default;

    Link* begin() const {
        return first_;
    }

    Link* end() const {
        return last_;
    }

    void push_back(Link* element);
    void push_front(Link* element);
    void insert(Link* actual, Link* to_insert);
    void erase(Link* element);

private:
    Link* first_;
    Link* last_;
};

void print(const List& lst);
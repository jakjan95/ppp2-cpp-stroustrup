#include "ex4List.hpp"

#include <iostream>

Link::Link()
    : prev_{nullptr}, suc_{nullptr}, name_{""} {}

Link::Link(std::string name)
    : prev_{nullptr}, suc_{nullptr}, name_{name} {}

Link* advance(Link* element, int value) {
    if (value == 0) {
        return element;
    }
    if (!element) {
        return nullptr;
    }

    if (value > 0) {
        while (value--) {
            element = element->suc_;
        }
    } else {
        while (value++) {
            element = element->prev_;
        }
    }
    return element;
}

List::List()
    : first_{nullptr}, last_{nullptr} {}

void List::push_back(Link* element) {
    if (!element) {
        return;
    }
    if (last_) {
        last_->suc_ = element;
        element->prev_ = last_;
    } else {
        first_ = element;
        element->prev_ = nullptr;
    }
    element->suc_ = nullptr;
    last_ = element;
}

void List::push_front(Link* element) {
    if (!element) {
        return;
    }
    if (first_) {
        element->suc_ = first_;
        first_->prev_ = element;
    } else {
        last_ = element;
        element->suc_ = nullptr;
    }

    first_ = element;
    element->prev_ = nullptr;
}

//inserting element before actual
void List::insert(Link* actual, Link* to_insert) {
    if (!to_insert && !actual) {
        return;
    }
    if (actual && actual == first_) {
        to_insert->prev_ = nullptr;
        first_ = to_insert;
    } else {
        to_insert->prev_ = actual->prev_;
        actual->prev_->suc_ = to_insert;
    }

    actual->prev_ = to_insert;
    to_insert->suc_ = actual;
}

void List::erase(Link* element) {
    if (!element) {
        return;
    }
    if (element == first_) {
        if (element->suc_) {
            first_ = element->suc_;
            element->suc_->prev_ = nullptr;
        } else {
            first_ = nullptr;
            last_ = nullptr;
        }
    } else if (element == last_) {
        if (element->prev_) {
            last_ = element->prev_;
            element->prev_->suc_ = nullptr;
        } else {
            first_ = nullptr;
            last_ = nullptr;
        }
    } else {
        element->prev_->suc_ = element->suc_;
        element->suc_->prev_ = element->prev_;
    }
}

void print(const List& lst) {
    for (auto p = lst.begin(); p != lst.end()->suc_; p = p->suc_) {
        std::cout << "List element: " << p->name_ << '\n';
    }
}
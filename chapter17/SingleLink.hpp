#pragma once
#include <string>

class SingleLink {
public:
    std::string value;
    SingleLink(const std::string& v, SingleLink* s = nullptr)
        : value{v}, succ{s} {}

    //Insert n before current
    SingleLink* insert(SingleLink* n);
    //Insert n after current
    SingleLink* add(SingleLink* n);
    //Erase current
    SingleLink* erase();
    //Find s in list
    SingleLink* find(const std::string& s);
    //Find s in const list
    const SingleLink* find(const std::string& s) const;

    //Move current by n-hops
    SingleLink* advance(int n) const;

    SingleLink* next() const { return succ; }

private:
    SingleLink* succ;
};

//----------------------------------------------
SingleLink* SingleLink::insert(SingleLink* n) {
    if (!n) {
        return this;
    }
    if (!this) {
        return n;
    }
    n->succ = this;
    return n;
}
//----------------------------------------------
//Insert n after current
SingleLink* SingleLink::add(SingleLink* n) {
    if (!n) {
        return this;
    }
    if (!this) {
        return n;
    }
    //n->succ = succ;
    succ = n;
    return n;
}

//----------------------------------------------
SingleLink* SingleLink::find(const std::string& s) {
    SingleLink* ptr = this;
    while (ptr) {
        if (ptr->value == s) {
            return ptr;
        }
        ptr = ptr->succ;
    }
    return nullptr;
}

//Exercise 12:
//We define this in order to have possibility finding items in const list
const SingleLink* SingleLink::find(const std::string& s) const {
    if (value == s) {
        return this;
    } else if (succ) {
        return succ->find(s);
    }
    return nullptr;
}

//----------------------------------------------
SingleLink* SingleLink::erase() {
    if (succ) {
        succ = nullptr;
    }

    return succ;
}
//----------------------------------------------
//Move current by n-hops
SingleLink* SingleLink::advance(int n) const {
    if (n > 0) {
        if(!succ){
            return nullptr;
        }
        return succ->advance(--n);
    }
    return const_cast<SingleLink*>(this);
}

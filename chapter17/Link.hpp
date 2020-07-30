#pragma once
#include <string>

class Link {
public:
    std::string value;
    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
        : value{v} {}

    //Insert n before current
    Link* insert(Link* n);
    //Insert n after current
    Link* add(Link* n);
    //Erase current
    Link* erase();
    //Find s in list
    Link* find(const std::string& s);
    //Find s in const list
    const Link* find(const std::string& s) const;

    //Move current by n-hops
    Link* advance(int n) const;

    Link* next() const { return succ; }
    Link* previous() const { return prev; }

private:
    Link* prev;
    Link* succ;
};

//----------------------------------------------
Link* Link::insert(Link* n) {
    if (!n) {
        return this;
    }
    if (!this) {
        return n;
    }
    n->succ = this;

    if (prev) {
        prev->succ = n;
    }

    n->prev = prev;
    prev = n;

    return n;
}
//----------------------------------------------
//Insert n after current
Link* Link::add(Link* n) {
    if (!n) {
        return this;
    }
    if (!this) {
        return n;
    }
    n->prev = this;

    if (succ) {
        succ->prev = n;
    }

    n->succ = succ;
    succ = n;
    return n;
}

//----------------------------------------------
Link* Link::find(const std::string& s) {
    Link* ptr = this;
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
const Link* Link::find(const std::string& s) const {
    if (value == s) {
        return this;
    } else if (succ) {
        return succ->find(s);
    }
    return nullptr;
}

//----------------------------------------------
Link* Link::erase() {
    if (succ) {
        succ->prev = prev;
    }
    if (prev) {
        prev->succ = succ;
    }
    return succ;
}
//----------------------------------------------
//Move current by n-hops
Link* Link::advance(int n) const {
    if (n > 0) {
        if(!succ){
            return nullptr;
        }
        return succ->advance(--n);
    } else if (n < 0) {
        if(!prev){
            return nullptr;
        }
        return succ->advance(++n);
    }

    return const_cast<Link*>(this);
}

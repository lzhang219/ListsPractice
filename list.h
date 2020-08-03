//
// Created by l05zh on 8/3/2020.
//

#ifndef LISTSPRACTICE_LIST_H
#define LISTSPRACTICE_LIST_H


template<class T>
struct ListNode {
public:
    T key;
    ListNode *next;

    ListNode() {
        next = nullptr;
    }

    explicit ListNode(T key) : key(key) {next=nullptr;}

    ListNode(T key, ListNode *next) : key(key), next(next) {}

    virtual ~ListNode() {
        if (next != nullptr) {
            delete next;
        }
    }
};

template<class T>
struct List {
    ListNode<T> *first, *last;

    List() {
        first = new ListNode<T>;
        last = first;
    }

    List(T t, int length) {
        first = new ListNode<T>(t);
        auto current = first;
        --length;
        while (length--) {
            current->next = new ListNode<T>(t);
            current = current->next;
        }
        last = current;
    }

    ~List() {
        delete first;
    }

    void InsElementFront(T t) {
        auto current = new ListNode<T>(t);
        current->next = first;
        first = current;
    }

    void InsElementEnd(T t) {
        last = last->next = new ListNode<T>(t);
    }
    void InsElement(T t, size_t i)
    {
        auto current = first;
        for (size_t j = 0; j < i; ++j) {
            current = current->next;
        }
        auto originalnext = current->next;
        current->next=new ListNode<T>(t);
        current->next->next=originalnext;
    }

    void modElement(T t, size_t i) {
        if (!i) {
            first->key = t;
            return;
        }
        auto current = first;
        while (i--) {
            current = current->next;
        }
        current->key = t;
    }
    void removeElement(size_t i){
        if(!i)
        {
            auto p = first;
            first=first->next;
            p->next = nullptr;
            delete p;
        }
        --i;
        auto p = first;
        for (int j = 0; j < i; ++j) {
            p=p->next;
        }
        ListNode<T> *o;
        o = p->next;
        p->next=p->next->next;
        o->next=nullptr;
        delete o;
    }
};

#endif //LISTSPRACTICE_LIST_H

//
// Created by l05zh on 8/3/2020.
//

#ifndef LISTSPRACTICE_LIST_H
#define LISTSPRACTICE_LIST_H

template<class T>
struct SLListNode {
public:
    T key;
    SLListNode *next;

    SLListNode() {
        next = nullptr;
    }

    explicit SLListNode(T key) : key(key) {next=nullptr;}

    SLListNode(T key, SLListNode *next) : key(key), next(next) {}

    virtual ~SLListNode() {
        if (next != nullptr) {
            delete next;
        }
    }
};

template<class T>
struct SLList {
    SLListNode<T> *first, *last;

    SLList() {
        first = nullptr;
        last = nullptr;
    }

    SLList(T t, int length) {
        first = new SLListNode<T>(t);
        auto current = first;
        --length;
        while (length--) {
            current->next = new SLListNode<T>(t);
            current = current->next;
        }
        last = current;
    }

    ~SLList() {
        delete first;
    }
    T getElement(unsigned int i)
    {
        auto p=first;
        for (int j = 0; j < i; ++j) {
            p=p->next;
        }
        return p->key;
    }
    void InsElementFront(T t) {
        auto current = new SLListNode<T>(t);
        if(first==nullptr)
        {
            last=current;
        }
        current->next = first;
        first = current;
    }

    void InsElementEnd(T t) {
        last = last->next = new SLListNode<T>(t);
    }
    void InsElement(T t, unsigned int i)
    {
        if(i==0)
        {
            InsElementFront(t);
            return;
        }
        --i;
        auto current = first;
        for (unsigned int j = 0; j < i; ++j) {
            current = current->next;
        }
        auto originalnext = current->next;
        current->next=new SLListNode<T>(t);
        current->next->next=originalnext;
    }
    unsigned int size(){
        unsigned int size=0;
        auto p = first;
        while(p!=nullptr)
        {
            p=p->next;
            ++size;
        }
        return size;
    }
    void modElement(T t, unsigned int i) {
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
    void removeElement(unsigned int i){
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
        SLListNode<T> *o;
        o = p->next;
        p->next=p->next->next;
        o->next=nullptr;
        delete o;
    }
};

#endif //LISTSPRACTICE_SLLIST_H

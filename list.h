//
// Created by l05zh on 8/3/2020.
//

#ifndef LISTSPRACTICE_LIST_H
#define LISTSPRACTICE_LIST_H

template<class T>
struct ListNode
{
public:
    T key;
    ListNode * next;
    ListNode();
    explicit ListNode(T key);
    ListNode(T key, ListNode *next);

    virtual ~ListNode();
};
template <class T>
struct List{
    ListNode<T> *first, *last;
    List();
    List(int length, T t);
    void InsElementFront(T t);
    void InsElementEnd(T t);
    void modElement(int i, T t);
};
#endif //LISTSPRACTICE_LIST_H

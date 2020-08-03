#include "list.h"
template<class T>
ListNode{
public:
    ListNode(){
        next=nullptr;
    }
    explicit ListNode(T key) : key(key){}
    ListNode(T key, ListNode *next) : key(key), next(next) {}

    virtual ~ListNode() {
        if(next!=nullptr)
        {
            delete next;
        }
    }
};
template <class T>
List{
    List(){
        first=new ListNode<T>;
        last=first;
    }
    List(int length, T t){
        first=new ListNode<T>(t);
        ListNode<T> * current=first;
        --length;
        while(length--)
        {
            current->next=new ListNode<T>(t);
            current=current->next;
        }
        last=current;
    }
    void InsElementFront(T t)
    {
        auto * current = new ListNode<T>(t);
        current->next=first;
        first=current;
    }
    void InsElementEnd(T t)
    {
        last=last->next=new ListNode<T>(t);
    }
    void modElement(int i, T t)
    {
        if(!i)
        {
            first->key=t;
            return;
        }
        auto * current = first;
        while(i--)
        {
            current = current->next;
        }
        current->key=t;
    }
};
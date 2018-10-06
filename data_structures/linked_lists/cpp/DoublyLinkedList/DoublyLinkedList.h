//
// Created by MohabMohamed on 03/10/18.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

template <class T>
class Node
{
public:
T data;
Node<T>* next;
Node<T>* prev;

    Node();
    Node(T data);
    ~Node();
};

template <class T>
class DoublyLinkedList
{
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int Length();
    void PushFront(T data);
    void PushBack(T data);
    T At(int pos);
    void InsertAt(int pos, T data);
    T DeleteAt(int pos);
    void Clear();



};


#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

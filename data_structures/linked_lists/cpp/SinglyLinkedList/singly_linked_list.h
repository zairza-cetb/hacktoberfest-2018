#include<iostream>

using namespace std;

template <class T>
class Node
{
public:
   T data;
   Node<T>* next;
    Node()
    {
        next = NULL;
    }
   Node(T n)
   {
       data = n;
       next = NULL;
   }


};


template<class T>
class Singlylinkedlist
{
    public:
    Node<T>* Head;
    Node<T>* Tail;
    int Size_;
    Singlylinkedlist()
    {
        Head = NULL;
        Tail = NULL;
        Size_ = 0;
    }
   void Push_front(T val);
   void Pop_front();
   void Push_back(T n);
   void Pop_back();
   void Display();
   void Clear();
   void Insert_at(T val,int position);
   void Delete_at (int location);
   void Delete_node(Node<T>* node);
   void Add_before(T val, int position);
   void Add_after(T val , int position);


   ~Singlylinkedlist()
   {
     cout<<"destructor is called"<<'\n';
     Clear();
   }

};





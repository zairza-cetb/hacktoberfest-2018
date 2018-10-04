#include "singly_linked_list.h"


//add a node to the end of the linked list o(1)
template<class T>
void Singlylinkedlist<T> :: Push_back(T n)
{
    Node<T>* new_node = new Node<T>(n);

    //check if it's the first element
    if(Size_ == 0)
      {
          Head = new_node;
          Tail = new_node;

      }
    else
    {
        Tail->next = new_node;
        Tail = new_node;

    }
    Size_++;
}

template <class T>
void Singlylinkedlist<T> :: Pop_back()
{

     if(Size_ == 0)
     {
       cout<<"Can't pop back. LinkedList is empty"<<'\n';
       return;
     }

//     if(Head ==  Tail)
//     {
//        delete Tail;
//        Tail = NULL;
//        Head = NULL;
//
//     }
//     else
//     {
//    //get the node before the last node
//    node<T>* tmp = Head;
//
//    while(tmp->next->next != NULL)
//    {
//       tmp = tmp->next;
//    }
//
//    delete Tail;
//    Tail = tmp;
//    Tail->next = NULL;
//    }
//Size_--;

Delete_node(Tail);


}



template<class T>
void Singlylinkedlist<T> :: Push_front(T val)
{
     Node<T>* new_node = new Node<T>(val);

     new_node->next = Head;
     Head = new_node;

     if(Tail == NULL)
     {
         Tail = new_node;

     }


Size_++;
}

template<class T>
void Singlylinkedlist<T>:: Pop_front()
{


     if(Size_ == 0)
     {
       cout<<"Can't pop back. LinkedList is empty"<<'\n';
       return;
     }

//     node<T>* tmp = Head->next;
//     delete Head;
//     Head = tmp;
//
//     if(Head == NULL )
//     {
//       Tail = NULL;
//     }
//
//Size_--;

        Delete_node(Head);

}


template <class T>
void Singlylinkedlist<T> :: Display() //O(N)
{
    if(Size_ == 0 )
    {
         cout<<" linked list is empty"<<'\n';
    }
    else
    {
    for( Node<T>* ptr = Head ; ptr != NULL ; ptr = ptr->next )
    {
        cout<<ptr->data<<" ";
    }
    cout<<'\n';
    }
}

template<class T>
void Singlylinkedlist<T> :: Clear() //O(N)
{
    if(Size_ == 0 )
    {
         cout<<" all cleared linked list is empty"<<'\n';
    }
    else
    {
        Node<T>* tmp = Head;
         while(Head != NULL)
         {
             Head = Head->next;
             //free the memory of the node to delete it
             delete tmp;
             tmp=Head;
         }
         // after the loop we make Tail point to NULL because it points
         //to a deleted location in the memory (dangling pointer)

         Tail = NULL;
        Size_ = 0;
    }
}

template<class T>
void Singlylinkedlist<T> :: Add_before(T val, int position)
{

  if (position == 1)
  {
    Push_front(val);

  }
  else
  {
       Node<T>* new_node = new Node<T>(val);
       Node<T>* tmp = Head;
       int n;
        //this loop will stop when n = position -1
       for( n=1 ; n < position-1 ; tmp = tmp->next,n++ );
       new_node->next = tmp->next;
       tmp->next = new_node;
       Size_++;

  }

}



template<class T>
void Singlylinkedlist<T> :: Add_after(T val,int position)
{

  if(position == Size_)
  {
    Push_back();
  }
  else
  {
      Node<T>* new_node = new Node<T>(val);

      Node<T>* chosen_node = Head;

      for(int i = 1; i<position;i++,chosen_node = chosen_node->next);

      new_node->next = chosen_node->next;
      chosen_node->next = new_node;

    Size_++;

  }

}
template<class T>
void Singlylinkedlist<T> :: Insert_at(T val,int position) //O(N) //add before
{

    if(Size_ == 0)
    {
        cout<<"no existing nodes.Linked list is empty. ";
        return;
    }

    if(position >Size_ || position < 0)
    {
       cout<<"invalid position choose a position between 1 and size "<<'\n';
       cout<<"size is: "<<Size_<<'\n';
       return;

    }

    // pre-pend
    Add_before(val,position);

}

template<class T>
void Singlylinkedlist<T> :: Delete_node(Node<T>* node)
{

    if(node != Head)
    {
        Node<T>* tmp = Head;
        while(tmp->next != node)
        {
           tmp = tmp->next;

        }

        tmp->next = node->next;
        if(Tail == node)
        {
           Tail = tmp;
        }

    }
    else
    {

          Head = node->next;
          if(Head == NULL)
          {
             Tail = NULL;
          }


    }
  delete node;
  Size_--;

}


template<class T>
 void Singlylinkedlist<T> :: Delete_at (int position)
 {


  if(Size_ == 0)
  {
      cout<<"Can't delete SLS is empty "<<'\n';
      return;
  }


  if(position>Size_ || position < 0)
    {
      cout<<"invalid location choose a position between 1 and size "<<'\n';
      cout<<"size is: "<<Size_<<'\n';
      return;

    }

            Node<T>* tmp = Head;
            for(int i = 1 ; i< position ; i++,tmp = tmp->next);
//            node<T>* to_be_deleted  = tmp->next;
//            tmp->next =  to_be_deleted->next;
//            delete to_be_deleted;
//            Size_--;
            Delete_node(tmp);


 }

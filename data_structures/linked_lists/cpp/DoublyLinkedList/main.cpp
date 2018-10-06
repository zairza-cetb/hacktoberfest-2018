#include <iostream>
#include "DoublyLinkedList.cpp"

void printDLL(DoublyLinkedList<int>& l)
{
    if(l.Length()==0)
        std::cout<<"Empty Dll\n";

    for(int i=0;i<l.Length();i++)
    {
        std::cout<<l.At(i)<<"   " ;
    }
    std::cout<<std::endl;

}



int main() {
    DoublyLinkedList<int> l;

    l.PushBack(5);
    l.PushBack(6);
    l.PushFront(2);
    l.PushFront(1);
    std::cout<<"After insertion : \n";
    printDLL(l);

    l.DeleteAt(2);
    std::cout<<"After deleting index 2 : \n";
    printDLL(l);

    l.DeleteAt(0);
    std::cout<<"After deleting index 0 : \n";
    printDLL(l);

    std::cout<<"current size : \n";
    std::cout<<l.Length()<<std::endl;

    l.InsertAt(1,8);
    std::cout<<"After inserting 8 at index 1 : \n";
    printDLL(l);

    l.Clear();
    printDLL(l);

    return 0;
}
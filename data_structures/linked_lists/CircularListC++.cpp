#include <iostream>

using namespace std;

template<class T>
class CNode
{
	public:
		
		CNode<T> *next;
		T info;
		
		CNode(const T& el, CNode *n=0)
		{
			info=el;
			next=n;
		}
};

template<class T>
class CList
{
	public:
		
		CNode<T> *tail;
		
		CList()
		{
			tail=0;
		}
		
		~CList();
		
		void addToTail(T);
		
		T deleteFromTail();
		
		void deleteNode(T);
		bool isInList(T);
		
		CList<T>* operator +(CList<T>*);
	  
	    void reverse();
	    bool search(T el);
       
	    void display(); 
	   
	    void addToPosition(CList<T>*, T, int);
	    void deleteFromPosition(CList<T>* ,int);
};

template<class T>
CList<T> :: ~CList()
{
  for(CNode<T> *p; !(tail!=0); )
  {
  	p=tail->next;
  	delete tail;
  	tail=p;
  }
  
}

template<class T>
void CList<T> :: addToTail(T el)
{
	if(tail==0)
	{
		tail=new CNode<T>(el);
		tail->next=tail;
	}
	else
	{
		tail->next=new CNode<T>(el, tail->next);
		tail=tail->next;
	}
}
	
template<class T>
T CList<T> :: deleteFromTail()
{
	CNode<T> *c=tail->next;
	T h=tail->info;
	if(tail==tail->next)
	{
		//T e=tail->info;
		delete tail;
		tail=0;
		return h;
	}
	while(c->next!=tail)
	{
		c=c->next;
	}
	c->next=tail->next;
	delete tail;
	tail=c;
	return h;
}

template<class T>
void CList<T> :: deleteNode(T el)
{
	CNode<T> *tmp=tail, *pred;
	if(el == tmp->info)
	{
		deleteFromTail();
		return ;
	}
	while(tmp->next != tail && el != tmp->info)
	{
		pred=tmp;
		tmp=tmp->next;
	}
	pred->next=tmp->next;
	delete tmp;
}

template<class T>
bool CList<T> :: search(T el)
{
	CNode<T> *tmp;
	for(tmp=tail; tmp->next!=tail && !(tmp->info==el); tmp=tmp->next);
        return tmp!=0;
  
}

template<class T>
void CList<T> :: reverse()
{
	CNode<T> *prev=tail, *current=tail->next, *nexty=current->next, *temp, *temp2, *temp3;
	while(current!=tail)
	{
		temp=current;
		temp2=nexty;
		temp3=nexty->next;
		nexty->next=current;
		current->next=prev;
		prev=temp;
		current=temp2;
		nexty=temp3;
	}
}

template<class T>
void CList<T> :: display()
{
	if(tail==0)
	{
		cout<<"\nList is empty ";
		return;
	}
	CNode<T> *c=tail->next;
	cout<<"\n";
	do
	{
		cout<<c->info<<" ";
		c=c->next;
	}while(c!=tail->next);
}

int main()
{
	CList<int> *C=new CList<int>();
	int c;
	char ch='y';
	do
	{
		cout<<"\nMenu is : 1.addToTail   2.deleteFromTail   3.deleteNode    4.search    5.reverse : ";
		cin>>c;
		switch(c)
		{
			case 1:{  int i;
					  cout<<"\nEnter the info value to be added to tail : ";
					  cin>>i;
					  C->addToTail(i);
					  C->display();
					  break;
				   }
				   
		    case 2:{  cout<<(C->deleteFromTail())<<" is the deleted element ";
		    		  C->display();
				      break;
			       }
			       
			case 3:{  int i;
					  cout<<"\nEnter element to be deleted : ";
					  cin>>i;
					  C->deleteNode(i);
					  C->display();
				      break;
			       }
			       
			case 4:{
					  int i;
					  cout<<"\nEnter element to be searched : ";
					  cin>>i;
					  int r= C->search(i);
					  if(r==0)	cout<<"\nElement not found !!!";
					  else 		cout<<"\nElement found !!!";
				      break;
				   }
				   
			case 5:{
				 	  cout<<"\nThe reverse List is : ";
					  C->reverse();
					  C->display();  
					  break;
				   }
		}
		
		cout<<"\nDo you want to do more (y/n) ???  ";
		cin>>ch;
		
	}while(ch=='y' || ch=='Y');
	
	return 0;
}

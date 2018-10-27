//Swapping adjacent nodes in single linked list

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>

//malloc fdunction is generic
//append insert at end awa first node

struct node{
int data;
struct node* link;
};

struct node* root=NULL;

int totalNodes();

void swap()
{
if(totalNodes()<2)
{
printf("Nodes are less , Invalid Operation");
}
else
{
int loc,i=1;
struct node* fptr,*sptr,*tptr;
printf("\nEnter location to be swapped:");
scanf("%d",&loc);
fptr=root;
while(i<loc-1)
{
fptr=fptr->link;
i++;
}
sptr=fptr->link;
tptr=sptr->link;
//swapping the nodes via pointers only
sptr->link=tptr->link;
tptr->link=sptr;
fptr->link=tptr;
}

}


void append()
{
struct node* temp;
temp = (struct node*)malloc(sizeof(node));
printf("\nEnter data of new node:");
scanf("%d",&temp->data);
temp->link=NULL;

if(root==NULL)
{
root=temp;
}
else
{
struct node* ptr;
ptr=root;
while(ptr->link!=NULL)
{
ptr=ptr->link;
}
ptr->link=temp;
}
}
//we can pass here root as an argument if required
//make it return so that we can put check on the size before deletion
int totalNodes()
{
struct node* ptr;
ptr=root;
int count=0;
if(ptr==NULL)
{
return 0;
}
else
while(ptr!=NULL)
{
ptr=ptr->link;
count++;
}
return count;
}

void addBeg()
{
struct node* temp;
temp = (struct node*)malloc(sizeof(struct node));
printf("\nEnter node data:");
scanf("%d",&temp->data);
temp->link=NULL;
//check root value is not null else add it as a first node
if(root==NULL)
{
root=temp;
}
else
{
temp->link=root;
root=temp;
}

}

void display()
{
struct node* ptr;
ptr = root;
if(ptr==NULL)
{
printf("\nThe list is empty");
}
else
while(ptr!=NULL)
{
printf("%d ",ptr->data);
if(ptr->link!=NULL)
printf("-> ");
ptr=ptr->link;
}

}

void deleteNode()
{
 struct node* temp;
 int loc;
 temp=root;
 if(temp==NULL)
 printf("\nList is already empty");
 else
 {
  printf("\nEnter node loc to delete:");
  scanf("%d",&loc);
  if(loc>totalNodes())
  printf("Invalid location[exceeding list size]");
  else if(loc==1)
  {
  temp=root;
  root=temp->link;
  temp->link=NULL;//to release the memory occupied as it was still
  ///pointing to next node
  free(temp);//to free up node or simply dismantle it
  }
  else
  {
   struct node* ptr=root,*q;
   int i=1;
   while(i<loc-1)
   {
   ptr=ptr->link;
   i++;
   }
   q=ptr->link;
   ptr->link=q->link;
   q->link=NULL;
   free(q);
  }
 }
}

void addAfter()
{
struct node* temp,*ptr;
int i=1,loc;
printf("\nEnter location after which you need to insert node:");
scanf("%d",&loc);
if(loc>totalNodes())
{
printf("\nInvalid operation!");
printf("\nTheir are %d nodes only",totalNodes());
}
else
{
ptr=root;
temp=(struct node*)malloc(sizeof(struct node*));
printf("\nEnter data for node:");
scanf("%d",&temp->data);
temp->link=NULL;
while(i<loc)
{
ptr=ptr->link;
i++;
}
temp->link=ptr->link; //right side connection
ptr->link=temp; //left side connection
}

}

void main()
{

clrscr();
int ch;

while(1)
{
printf("\n1.Append \n2.Number Of Nodes");
printf("\n3.Add at beg\n4.Display\n5.Delete\n6.Add after\n7.Swap\n8.Exit");
printf("\nEnter your choice:");
scanf("%d",&ch);
clrscr();
switch(ch)
{
case 1:append();
       printf("\n");
       break;
case 2:printf("Number Of Nodes:%d",totalNodes());
       printf("\n");
       break;
case 3:addBeg();
       printf("\n");
       break;
case 4:display();
       printf("\n");
       break;
case 5:deleteNode();
       printf("\n");
       break;
case 6:addAfter();
       printf("\n");
       break;
case 7:swap();
       printf("\n");
       break;
case 8:exit(1);
       break;
default:printf("\nWrong choice!");
	break;
}

}

}
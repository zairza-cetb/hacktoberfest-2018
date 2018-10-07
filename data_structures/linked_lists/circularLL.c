#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void push(struct node **head_ref,int data);
void printList(struct node *head);


void push(struct node **head_ref,int data){
  struct node *ptr1 = (struct node*)malloc(sizeof(struct node));
  struct node *temp = *head_ref;
  ptr1->data = data;
  ptr1->next = *head_ref;

  if(*head_ref!=NULL){
    while(temp->next!= *head_ref)
      temp=temp->next;
    temp->next=ptr1;
  }
  else
    ptr1->next=ptr1;

  *head_ref=ptr1;
}

void printList(struct node *head){
    struct node *temp = head;
    if (head != NULL){
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}

int main(){
  struct node* head=NULL;

  int ch,val;
  printf("OPERATIONs\n");
  printf("1.Insert\n");
  printf("2.Print Linked List\n");
  printf("3.Exit\n");

  do{
    printf("\nEnter choice = ");
    scanf("%d",&ch);

    switch (ch){
      case 1: printf("Enter new data = ");
              scanf("%d",&val);
              push(&head,val);
              break;
      case 2: printf("The linked List is: ");
              printList(head);
              break;
      case 3: exit(0);
    }
  }while(ch!=0);
return 0;
}

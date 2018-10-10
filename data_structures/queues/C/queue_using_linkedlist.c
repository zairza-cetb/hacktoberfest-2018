#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node* front = NULL, *rear = NULL;

void enqueue()
{
	struct node* temp = (struct node* )malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &temp->data);
	temp->next = NULL;

	if (front == NULL)
	{
		front = rear = temp;
		return;
	}

	rear->next = temp;
	rear = temp;
}

void dequeue()
{
	if (front == NULL)
	{
		printf("Empty!\n");
		return;
	}
	struct node* temp = front;
	printf("data: %d\n", front->data);
	if (front == rear)
		front = rear = NULL;
	else 
		front = front->next;
	free(temp);
}

void atFront()
{
	if (front == NULL)
	{
		printf("Empty!\n");
		return;
	}
	printf("At the top: %d\n", front->data);
}

int main()
{
	int choice;
	
	while(1)
	{
		printf("1. Enqueue\n2. Dequeue\n3. At front\n4. Exit\n\nEnter Choice: ");
	scanf("%d", &choice);
		switch(choice)
		{
			case 1: 
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				atFront();
				break;
			default:
				exit(0);
		}
	}

}
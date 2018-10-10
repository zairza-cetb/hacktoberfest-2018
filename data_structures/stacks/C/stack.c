#include<stdio.h>

int size=10;
int stack[10];
int top = -1;
int empty()
{
  if(top==-1)
  return 1;
  else
  return 0;
}
int full()
{
  if(top==10)
  return 1;
  else
  return 0;
}
void push(int data)
{
  top++;
  stack[top]=data;
}
void pop()
{
  top--;
}
void display()
{
  for(int i=0;i<=top;i++)
  printf("%d\n",stack[i]);
}
void main()
{
  int ch,val;
  do
  {
  printf("1.push\n");
  printf("2.pop\n");
  printf("3.display\n");
  printf("4.exit\n");
  printf("enter choice");
  scanf("%d",&ch);
  switch (ch) {
    case 1:
    if(full()==1)
    printf("OOPS!..stack is full already\n");
    else
    {
      printf("enter data");
      scanf("%d",&val);
      push(val);
    }
    break;
    case 2:
    if(empty()==1)
    printf("OOPS!..stack is empty\n");
    else
    pop();
    break;
    case 3:
    display();
    break;
    case 4:
    break;
    default :
    printf("enter correct option");
  }}
  while(ch!=4);
}

#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>
#include<ctype.h>
char stack[20];
int top=-1;

void push(char x)
{
if(top==19)
printf("overflow");
else
{
top++;
stack[top]=x;
}
}

char pop()
{
if(top==-1)
{
cout<<"\nUnderflow";
return -1;
}
else
{
int h=top;
top--;
return stack[h];
}

}

int priority(char x)
{

if(x=='(')
return 0;

if(x=='+'||x=='-')
return 1;

if(x=='*'||x=='/')
return 2;

return -1;
}

void main()
{
char exp[20],*e,x;
e=exp;
printf("\nEnter Expression:");
scanf("%s",&exp);

while(*e!='\0')
{
if(isalnum(*e))
printf("%c",*e);
else if(*e=='(')
push(*e);
else if(*e==')')
{

while((x=pop())!='(')
{
printf("%c",x);
}

}
else
{
while(priority(stack[top])>=priority(*e))
{
printf("%c",pop());
}
push(*e);
}

e++;//iterating the whole while

}

while(top!=-1)   //Printing anything if remains
{
printf("%c",pop());
}

getch();
}
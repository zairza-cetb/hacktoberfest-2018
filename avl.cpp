#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include"avl.h"
using namespace std;
 
int main(int argc,char* argv[])
{
  node *root = NULL;
  node *temp = NULL;
  tree t;
  int year,tcount,mcount,fcount;
  string  name="",previous="",popular,space;
  char ch;
  FILE *fp1;
  fp1=fopen("input.txt","r");
  int maxmul=0,mul=0;
while(!feof(fp1))
 {
   fscanf(fp1,"%d %d %d %d ",&year,&tcount,&mcount,&fcount);
	ch=fgetc(fp1);
   while(ch!='\n'&&ch!=EOF)
   {
   		name=name+ch;
      	ch=fgetc(fp1);	
   }
	
  	if(name!=previous)
  	{
 	root=t.insert(root,name);
 	mul=tcount;
 	previous=name;
  	}
    else
    {
 	mul=mul+tcount;
    }
  
    temp=t.locate(root,name);
    temp->mul=mul;
 }
 int option = atoi(argv[1]);
 node *temp1 = NULL;
 node *temp2 = NULL;
 string s1,s2;
 switch(option)
 {
 	case 1:s1 = atoi(argv[2]);
 			temp1=t.locate(root,name);
 			if(s1==temp1->key)
 			{
 				cout<<"key found"<<" "<<temp1->mul<<endl;
 			}
 			else
 			{
 				cout<<"key not found";
 			}
 			break;
 	case 2:cout<<t.height(root)<<endl;
 			break;
 	
 	case 3: s1 = string(argv[2]);
 			temp2 =t.depth(root,s1,0);
 			cout<<temp2->d;
 			break;	
    case 4:	s1 = string(argv[2]);
    		t.deleteNode(root,s1);
    		break;
    case 5: s1 = string(argv[2]);
    		s2 = string(argv[3]);
    		t.range(root,s1,s2);
    		break;    		
    case 6: string popular=root->key;
    		int p = root->mul;
    		t.most_popular(root,popular,p);
    		break;
    			
 }
 
 
  cout<<"inorder traversal of the constructed AVL tree is \n";
  t.inOrder(root);
 
  return 0;
}

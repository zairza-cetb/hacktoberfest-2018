#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;

struct node
{
    string key;
    node *left;
    node *right;
    int mul=0;
    int d;
    int height;
};
class tree
{
private:

public:
	int height(node *N);
	node* newnode(string key);
	node *rightRotate(node *y);
	node *leftRotate(node *x);
	int getBalance(node *N);
	node* insert(node* temp, string key);
	void inOrder(node *root);
	node* deleteNode(node* root, string key);
	node* minValueNode(node* temp);
	node* locate(node* root,string key);
	node* depth(node* temp,string key,int depth);
	void most_popular(node *temp,string &popular,int &p);
	void range(node *temp,string s1,string s2);
};

int max(int a, int b);
void tree :: range(node *temp,string s1,string s2)
{
	    range(temp->left,s1,s2);
        if(temp->key>s1&&temp->key<s2)
        cout<<temp->key;
        range(temp->right,s1,s2);
}

void tree :: most_popular(node *temp,string &popular,int &p)
{
    if(temp != NULL)
    {
        inOrder(temp->left);
        if(temp->mul>p)
        {
        	temp->key=popular;
        	temp->mul=p;
        }
        inOrder(temp->right);
    }
}

node* tree :: depth(node* temp,string key,int d)
{
	if(key == temp->key)
	{
		 temp->d=d;
        return temp;
    }
        		
    else if ( key < temp->key )
    {
    	d++;
        return depth(temp->left, key,d);
    }    
 
    else if ( key > temp->key )
    {
    	d++;
        return depth(temp->right, key,d);
    }
        
}
node* tree :: locate(node* temp, string key)
{
    if(key == temp->key) 
        return temp;
        		
    else if ( key < temp->key )
        return locate(temp->left, key);
 
    else if ( key > temp->key )
        return locate(temp->right, key);
      
}
node* tree :: minValueNode(node* temp)
{
    node* current = temp;
 
    
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 

node* tree :: deleteNode(node* root, string key)
{
 
    if (root == NULL)
        return root;
 
    if ( key < root->key )
        root->left = deleteNode(root->left, key);
 
    else if( key > root->key )
        root->right = deleteNode(root->right, key);
 
    else
    {
        
        if( (root->left == NULL) || (root->right == NULL) )
        {
            node *temp = root->left ? root->left :
                                             root->right;
 
           
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
             *root = *temp;
                           
            free(temp);
        }
        else
        {
            node* temp = minValueNode(root->right);
 
           
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL)
      return root;
   
    root->height = 1 + max(height(root->left),
                           height(root->right));
 
    int balance = getBalance(root);
 
   
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
   
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
   
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
 
int tree :: height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int max(int a, int b)
{
    return (a > b)? a : b;
}
 

node* tree :: newnode(string key)
{
     node* temp = new node;
    temp->key   = key;
    temp->left   = NULL;
    temp->right  = NULL;
    temp->height = 1;  
    return(temp);
}
 
node* tree :: rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
 
   
    x->right = y;
    y->left = T2;
 
   
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
   
    return x;
}
 

node* tree :: leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
 
   
    y->left = x;
    x->right = T2;
 
  
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
   
    return y;
}
 

int tree :: getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 

node* tree :: insert(node* temp, string key)
{
   
    if (temp == NULL)
        return(newnode(key));
 
    if (key < temp->key)
        temp->left  = insert(temp->left, key);
    else if (key > temp->key)
        temp->right = insert(temp->right, key);
    else 
        return temp;
 
   
    temp->height = 1 + max(height(temp->left),
                           height(temp->right));
 
    int balance = getBalance(temp);
 
   
    if (balance > 1 && key < temp->left->key)
        return rightRotate(temp);
 
   
    if (balance < -1 && key > temp->right->key)
        return leftRotate(temp);
 
    
    if (balance > 1 && key > temp->left->key)
    {
        temp->left =  leftRotate(temp->left);
        return rightRotate(temp);
    }
 
   
    if (balance < -1 && key < temp->right->key)
    {
        temp->right = rightRotate(temp->right);
        return leftRotate(temp);
    }
 
  
    return temp;
}
 

void tree :: inOrder(node *temp)
{
    if(temp != NULL)
    {
        inOrder(temp->left);
        
        cout<< temp->key;
        inOrder(temp->right);
    }
}

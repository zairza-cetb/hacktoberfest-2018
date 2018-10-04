#include <iostream>
#include<string>
#include<fstream>
using namespace std;

typedef struct node
{
	string name;
	int name_count;
	int male_count,female_count;
	int tot_count;
	struct node *left,*right;

}* nodePtr;
class bst
{
	public:
		nodePtr root,curr,temp;
		int count;
		nodePtr most_popular;

		bst()
		{
			root = curr = temp = most_popular = NULL;
			count = 0;
		}
		void add(int male_c , int female_c,int tot_count, string name);
		void inprint1();
		void inprint(nodePtr n);
		void search(string name);
		int height();
		int height1(nodePtr n);
		nodePtr find(string n);
		nodePtr left_most(nodePtr n);
		nodePtr parent(nodePtr n);
		string delete_(string n);
		void most_popular_print();
		void mostpopular(nodePtr n);
		void depth(string n);
		int depth1(string n,nodePtr n12);
		void between(string n1,string n2);
		void inorderP(string n1,string n2,nodePtr n3);

		void printleftmost();
};

void bst::depth(string n)
{
	cout<<depth1(n,root);
}

int bst::depth1(string n,nodePtr root)
{
	if(root==NULL) return 0;
	else if(n == root->name)
	{
		return 0;
	}
	else if(n<root->name)
	{
		return 1+depth1(n,root->left);
	}
	else if(n>root->name)
	{
		return 1+depth1(n,root->right);
	}
	return 0;
}


void bst :: inorderP(string n1,string n2,nodePtr n3)
{
	if(n3 == NULL) return;
	else if(n3->name < n1)
	{
		inorderP(n1,n2,n3->right);
	}
	else if(n3->name > n2)
	{
		inorderP(n1,n2,n3->left);
	}
	else
	{
		inorderP(n1,n2,n3->left);
		cout << n3->name<<endl;
		inorderP(n1,n2,n3->right);
	}
}

void bst :: between(string n1,string n2)
{	
	inorderP(n1,n2,root);
}

void bst :: mostpopular(nodePtr n)
{

	if(n!=NULL)
	{
		mostpopular(n->left);
		if(n->tot_count > most_popular->tot_count)
		{
			most_popular = n;
		}
		mostpopular(n->right);
	}
}

void bst :: most_popular_print()
{
	mostpopular(root);
	cout << most_popular->name<<" "<<most_popular->tot_count;
}

void bst :: printleftmost()
{

	nodePtr n = left_most(root->right);
	if(n!=NULL) cout<< n->name;
	else cout<<"no left_most";
}

void bst :: add(int male_c , int female_c, int tot_c , string name)
{
	nodePtr n = new node;
	n -> name = name;
	n -> male_count = male_c;
	n -> female_count = female_c;
	n -> name_count = 1;
	n-> tot_count = tot_c;
	n->left = n -> right = NULL;
	if(root == NULL)
	{
		root = n;
		count++;
		most_popular = root;
	}
	else
	{
		nodePtr parent = root;
		temp = root;
		while(temp!=NULL)
		{
			if(name < temp->name)
			{
				parent = temp;
				temp = temp->left;
			}
			else if(name > temp->name)
			{
				parent = temp;
				temp = temp->right;
			}
			else
			{
				temp->male_count += male_c;
				temp->female_count += female_c;
				temp->tot_count += tot_c;
				temp->name_count+=1;
				count++;
				return;
			}
		}
		if(name < parent->name) parent->left = n;
		else parent->right = n;
		count++;
	}
}

void bst :: inprint1()
{
	inprint(root);
}

void bst :: inprint(nodePtr n)
{
	if(n != NULL)
	{
		inprint(n->left);
		cout << n->name<< " "<<n->male_count << " "<< n->female_count<< " "<<n->name_count<<endl;
		inprint(n->right);
	}
}

void bst :: search(string name)    //prints elem and its entries if it is present else none
{
	temp = root;
	while(temp!=NULL)
	{
		if(temp->name > name) temp = temp->left;
		else if(temp->name < name) temp = temp->right;
		else 
		{
			cout <<temp->tot_count<< " \n";
			return;
		}
	}
	cout<<"0\n";

}

int bst :: height()
{
	return height1(root)-1;
}
int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
int bst :: height1(nodePtr n)
{
	if(n==NULL) return 0;
	else return 1+max(height1(n->left),height1(n->right));
}

nodePtr bst :: find(string name)
{
	temp = root;
	while(temp!=NULL)
	{
		if(temp->name > name) temp = temp->left;
		else if(temp->name < name) temp = temp->right;
		else 
		{
			return temp;
		}
	}
	return NULL;
}
nodePtr bst :: left_most(nodePtr n)
{
	temp = n;
	while(temp->left!=NULL)
	{
		temp = temp->left;
	}
	return temp;
}
nodePtr bst :: parent(nodePtr n)
{
	temp = root;
	nodePtr parent = NULL;
	while(temp!=NULL)
	{
		if(temp->name > n->name) 
		{
			parent = temp;
			temp = temp->left;
		}
		else if(temp->name < n->name) 
		{
			parent = temp;
			temp = temp->right;
		}
		else 
		{
			return parent;
		}
	}
	return parent;
}
string bst :: delete_(string name)
{
	curr = find(name);
	if(curr!=NULL)
	{
		if(curr->left!=NULL && curr->right!=NULL)
		{
			temp = left_most(curr->right);
			string str1 = temp->name,dummy;
			int mc = temp ->male_count;
			int fc = temp->female_count;
			int nc = temp->name_count;
			nodePtr m = parent(temp);
			if((m->left)->name == temp->name)
			{
				if(temp->left == NULL) m->left = temp->right;
				dummy = temp->name;
				delete(temp);
			}
			else
			{
				if(temp->left == NULL) m->right = temp->right;
				dummy = temp->name;
				delete(temp);
			}
			curr->name = str1;
			curr->male_count = mc;
			curr->female_count = fc;
			curr->name_count = nc;
			return dummy;
		}
		else if(curr->left == NULL && curr->right ==NULL)
		{
			nodePtr m = parent(curr);
			if(m->left == curr) m->left = NULL;
			else m->right = NULL;
			string dummy = curr ->name;
			delete(curr);
			return dummy;
		}
		else
		{
			nodePtr m = parent(curr);
			if((m->left)->name == name)
			{
				if(curr->left == NULL) m->left = curr->right;
				else m->left = curr->left;
			}
			else
			{
				if(curr->left == NULL) m->right = curr->right;
				else m->right = curr->left;
			}
			string dummy = curr->name;
			delete(curr);
			return dummy;
		}
	}
	cout<<"none\n";
	return "none";
}



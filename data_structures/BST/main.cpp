#include<iostream>
#include<fstream>
#include "bst1.h"
#include<cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
	if(argc>1)							   //the statements inside if generates the tree from the values given in the tree.
		{
			bst t;
			ifstream f;
			f.open("Dataset_random");             //filename
			int i,j,k;
			string data;
			int cnt=0;
			while(f>>i)
			{
				f>>k;
				f>>i;
				f>>j;
				f>>data;
				//cout<<data<<endl;
				t.add(i,j,k,data);				  //adds data to bst
				cnt++;
			}
			int opt = atoi(argv[1]);
			switch(opt)
			{
				case 1:
					t.search(argv[2]);            //searches a given string
					cout<<endl;
					break;
				case 2:
					cout << t.height()<<endl;           //outputs height of tree
					break;
				case 3:
					t.depth(argv[2]);             //outputs depth of node
					cout<<endl;
					break;
				case 4:
					t.delete_(argv[2]);           //deletes string
					cout << "deleted" << argv[2]<<endl;
					break;
				case 5:
					t.between(argv[2],argv[3]);   
					cout<<endl;
					break;
				case 6:
					t.most_popular_print();
					cout<<endl;
					break;
			}
		}
	else
	{
		cout<<"no of args are incorrect";
	}
}
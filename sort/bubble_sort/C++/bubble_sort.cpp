#include<iostream>
using namespace std;
int main()
{
	long long n,a[100000],temp;
	cin>>n;
	for(int i=0;i<n;i++)
	  cin>>a[i];
	for(int i=n-1;i>0;i--)
	{
		 for(int j=0;j<i;j++)
		 if(a[j]>a[j+1])
		 {
			 temp=a[j];
			 a[j]=a[j+1];
			 a[j+1]=temp;
		 }
	}
	for(int i=0;i<n;i++)
	   cout<<a[i]<<' ';
return 0;
}
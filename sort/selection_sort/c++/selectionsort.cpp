#include<iostream>
using namespace std;

int main()
{
    int n,i,j,index;
    long long a[100000],small;
    cin>>n;

    for(i=0;i<n;i++)
      cin>>a[i];
    
    

    for(i=0;i<n;i++)
    {   small=a[i];
        for(j=i+1;j<n;j++)
        {
            if(a[j]<=small)
            {
                small=a[j];
                index=j;
            }
        }
        a[index]=a[i];
        a[i]=small;

    }


    for(i=0;i<n;i++)
     cout<<a[i]<<' ';

     return 0;
    
}


#include<iostream>
using namespace std;
int main()
{
    int a[20],i,j;
    int m,c,n;
    cout<<"enter how many nos to be given";
    cin>>n;
    cout<<"enter the nos.";
    for(i=0;i<n;i++)
    {
        cin>>a[i];

    }
    int small;
    for(i=0;i<n;i++)
    {
        small=a[i];
        for(j=i;j<n;j++)
        {
            if(a[j]<small)
            {
                small=a[j];
                m=j;
            }
        }    
            c=a[i];
            a[i]=small;
            a[m]=c;
        
    }
    cout<<"sorted array is:"<<"\n";
    for(i=0;i<n;i++)
    {
        
        cout<<a[i]<<" ";
    }
    return 0; 
}

// C++ implementation of Bogo Sort 
#include<bits/stdc++.h> 
using namespace std; 
static bool IsSorted(int* data, int count)
{
	while (--count >= 1)
		if (data[count] < data[count - 1]) return false;

	return true;
}

static void Shuffle(int* data, int count)
{
	int temp, rnd;

	for (int i = 0; i < count; ++i)
	{
		rnd = rand() % count;
		temp = data[i];
		data[i] = data[rnd];
		data[rnd] = temp;
	}
}

static void BogoSort(int* data, int count)
{
	while (!IsSorted(data, count))
		Shuffle(data, count);
}
  
// prints the array 
void printArray(int a[], int n) 
{ 
    for (int i=0; i<n; i++) 
        printf("%d ", a[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
	int n;
	cout<<"enter size of array"<<endl;
	cin>>n;
    int* a = new int[n]; 
    cout<<"elements of array"<<endl;
    for(int i=0;i<n;i++)cin>>a[i];
    BogoSort(a, n); 
    printf("Sorted array :\n"); 
    printArray(a,n); 
    return 0; 
} 

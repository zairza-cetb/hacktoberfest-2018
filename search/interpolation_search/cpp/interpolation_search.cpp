#include <bits/stdc++.h>
using namespace std;
bool interpolation_search(int arr[],int size,int element){
	int low=0;
	int high=size-1;
	int pos=0;
	while(low <= high and element >= arr[low] and element <= arr[high]){
		//pos = l + [ (x-arr[l])*(h-l) / (arr[h]-arr[L]) ]
		pos=low+((element-arr[low])*(high-low))/(arr[high]-arr[low]);
		if(arr[pos] == element ){
			return true;
		} 
		if(arr[pos]>element)high=pos-1;
		else low=pos+1;
	}
	return false;
}
int main(){
	int element=10;
	int arr[]={1,5,6,13,29,30,39,42};
	int n=sizeof(arr)/sizeof(arr[0]);
	bool found=interpolation_search(arr,n,element);
	if(found){
		cout<<element<<" is present in array :)\n";
	}
	else cout<<element<<" is not present in array :(\n";
	element=29;
	found=interpolation_search(arr,n,element);
	if(found){
		cout<<element<<" is present in array :)\n";
	}
	else cout<<element<<" is not present in array :(\n";
}
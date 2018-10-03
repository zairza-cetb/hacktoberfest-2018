/* ternary_search.cpp
 * Implemented using Devide and Conquer Strategy
 * This Search require a array of element in 
 * sorted order.
 * Like Binary Search Devide a sorted array into two
 * part Ternary Search Devide it into three part.
 * It try to find one part while ignoring other two.
 */
#include<iostream>

//This function will return the array index which contain value in varibale x
//other wise it retunrn -1.
//@array is a int array 
//@left first index of array which is always 0
//@right number of element of array -1
//@x element to be searched 
int ternary_search(int* array, int left, int right, int x)
{

//Calculate two mid point which will devide array into three part.
if (right >= left){
int mid1 = left + (right - left) / 3;
int mid2 = mid1 + (right - left) / 3;

if(array[mid1] == x)
	return mid1;

if(array[mid2] == x)
	return mid2;

if(array[mid1] > x)
	return ternary_search(array, left, mid1 - 1, x);

else if(array[mid2] > x)
	return ternary_search(array, mid1 + 1, mid2 - 1, x);

else
	return ternary_search(array, mid2 + 1, right, x);
}
return -1;
}

//driver program to test the above function
int main(){

int arr[]={1,2,3,4,4,5,6,7,8,9,10,11};
std::cout<<ternary_search(arr,0,11,15)<<std::endl;
std::cout<<ternary_search(arr,0,11,4)<<std::endl;
return 0;
}

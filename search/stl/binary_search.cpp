#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n = 10;
    int a[] = {45, 34, 56, 23, 12, 56, 23, 989, 34, 10};
    // sorting the arrray
    sort(a, a+n);
    // using binary search to find the element
    int index = binary_search(a, a+n, 12);
    if (index)
        printf("Element found\n");
    else   
        printf("Element not found!\n");

}
#include <bits/stdc++.h>

using namespace std;

void display(int *a, int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
}
int main(void) {
    int n = 9;
    int a[] = {1, 45, 56, 23, 2, 34, 15, 45, 1};
    printf ("Array without sorting\n");
    display(a, n);
    // sorting using stl;
    sort(a, a+n);
    printf("Array after sorting\n");
    display(a, n);
    return 0;
}
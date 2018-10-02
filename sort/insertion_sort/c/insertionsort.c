#include <stdio.h>

void insertionsort(int arr[], int n)
{
  int i, j, temp;

  for(i = 1; i < n; i++){
    temp = arr[i];
    for(j = i; j > 0 && arr[j-1] > temp; j--){
      arr[j] = arr[j-1];
    }
    arr[j] = temp;
  }
}

int main()
{
  int i;
  int num[] = { 3, 2, 5, 8, 1, 6, 7, 4 }; 
  const int n = 8;

  for(i = 0; i < n; i++){
    printf("%d ", num[i]);
  }
  printf("\n");

  insertionsort(num, n);

  for(i = 0; i < n; i++){
    printf("%d ", num[i]);
  }
  printf("\n");

  return 0;
}

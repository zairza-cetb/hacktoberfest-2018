#include <iostream>
using namespace std;
int partition(int *unsortedArray, int low, int high)
{
    int left = low;
    int pivot = low;
    int right = high;
    while (left < right)
    {

        if (unsortedArray[left] <= unsortedArray[pivot])
        {

            left++;
        }
        if (unsortedArray[right] >= unsortedArray[pivot])
        {

            right--;
        }
        if (unsortedArray[left] > unsortedArray[right])
        {

            int c = unsortedArray[left] + unsortedArray[right];
            unsortedArray[right] = c - unsortedArray[right];
            unsortedArray[left] = c - unsortedArray[left];
        }
    }
    int c = unsortedArray[right] + unsortedArray[pivot];
    unsortedArray[right] = c - unsortedArray[right];
    unsortedArray[pivot] = c - unsortedArray[pivot];

    return right;
}
int *quickSort(int *unsortedArray, int low, int high)
{

    if (low < high)
    {
        int partitionValue = partition(unsortedArray, low, high);
        quickSort(unsortedArray, low, partitionValue - 1);
        quickSort(unsortedArray, partitionValue + 1, high);
    }
    return unsortedArray;
}
int main()
{
    int n;
    cout << "enter number of elements" << endl;
    cin >> n;
    int unsortedArray[n];
    for (int i = 0; i < n; i++)
    {
        cin >> unsortedArray[i];
    }
    int *sortedArray = quickSort(unsortedArray, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << sortedArray[i] << endl;
    }
}

#include <iostream>
using namespace std;
int *insertionSort(int unsortedArray[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int j = i;
        int value = unsortedArray[i];
        while (j >= 0 && (value < unsortedArray[j - 1]))
        {
            unsortedArray[j] = unsortedArray[j - 1];
            j--;
        }
        unsortedArray[j] = value;
    }
    return unsortedArray;
}
int main()
{
    int length;
    cout << "enter the number of elements want to sort" << endl;
    cin >> length;
    int unsortedArray[length];
    for (int i = 0; i < length; i++)
    {
        cin >> unsortedArray[i];
    }
    int *sortedArray = insertionSort(unsortedArray, length);
    for (int i = 0; i < length; i++)
    {
        cout << sortedArray[i] << endl;
    }
}
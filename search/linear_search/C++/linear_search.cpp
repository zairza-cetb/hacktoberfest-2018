#include <iostream>

int search(int arr[], int x);

int main()
{
    int sample_input[] = {12, 51, 9, 4, 102, 53, 64};
    int search_for = 4;

    int result = search(sample_input, search_for);

    if (result != 1)
        std::cout << search_for << " found at index: " << result << std::endl;
    else
        std::cout << search_for << " not found." << std::endl;
}

int search(int arr[], int x)
{
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
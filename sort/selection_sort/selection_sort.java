import java.util.*;
public class selection_sort
{
    void sort(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
        {
            int min_idx = i;
            for (int j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
    void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }

    public static void main(String args[])
    {
        selection_sort ob = new selection_sort();
        int arr[]=new int[5];
        Scanner s = new Scanner(System.in);
        System.out.println("enter array elements");
        for(int i=0;i<5;i++)
        arr[i]=s.nextInt();

        ob.sort(arr);
        System.out.println("Sorted array:");
        ob.printArray(arr);
    }
}

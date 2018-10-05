import java.util.*;
public class HeapSort
{
	public void sort(int arr[])
	{
		int n = arr.length;
		for (int i = n / 2 - 1; i >= 0; i--)
			heap(arr, n, i);
		for (int i=n-1; i>=0; i--)
		{
			int temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;
			heap(arr, i, 0);
		}
	}
	void heap(int arr[], int n, int i)
	{
		int largest = i;
		int l = 2*i + 1;
		int r = 2*i + 2;
		if (l < n && arr[l] > arr[largest])
			largest = l;
		if (r < n && arr[r] > arr[largest])
			largest = r;
		if (largest != i)
		{
			int swap = arr[i];
			arr[i] = arr[largest];
			arr[largest] = swap;
			heap(arr, n, largest);
		}
	}
	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i=0; i<n; ++i)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
	public static void main(String args[])
	{
		Scanner s=new Scanner(System.in);
		int arr[] = new int[5];
		int n = arr.length;
		System.out.println("enter array elements");
		for(int i=0;i<5;i++)
		arr[i]=s.nextInt();
		HeapSort ob = new HeapSort();
		ob.sort(arr);

		System.out.println("Sorted array is");
		printArray(arr);
	}
}

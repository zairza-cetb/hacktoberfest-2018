import java.util.Arrays;

public class InsertionSort {
    public static void main(String[] args) {
        int[] arr = {5,10,20,30,1,2,3,19,18,17,16};
        System.out.println("Array before sorting" + Arrays.toString(arr));
        insertionSort(arr);
        System.out.println("Array after sorting" + Arrays.toString(arr));
    }
    private static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int valueToSort = arr[i];
            int j = i;
            while (j > 0 && arr[j - 1] > valueToSort) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = valueToSort;
        }
    }

}

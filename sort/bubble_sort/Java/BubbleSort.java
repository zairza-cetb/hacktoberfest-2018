import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int arr[] = {10, 8, 7, 6, 5, 2, 2};
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));


    }

    public static void bubbleSort(int[] numArray) {

        int n = numArray.length;
        int temp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < (n - i); j++) {

                if (numArray[j - 1] > numArray[j]) {
                    temp = numArray[j - 1];
                    numArray[j - 1] = numArray[j];
                    numArray[j] = temp;
                }

            }
        }
    }
}

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class QuickSort {
    public <T extends Comparable<T>> void quickSort(List<T> input) {
        qSort(input, 0, input.size() - 1);
    }

    private <T extends Comparable<T>> void qSort(List<T> input, int lo, int high) {
        if(lo < high) {
            int pivotIndex = partition(input, lo, high);

            qSort(input, lo, pivotIndex - 1);
            qSort(input, pivotIndex + 1, high);
        }
    }

    private <T extends Comparable<T>> int partition(List<T> input, int lo, int high) {
        // Taking pivot as last element
        T pivot = input.get(high);

        // Elements to the left of wall are all <= than pivot
        // Elements to the right of wall are all >= than pivot
        int wall = lo - 1, cursor = lo;
        for(cursor = lo; cursor < high; cursor++) {
            if(input.get(cursor).compareTo(pivot) < 0) {
                // move the wall to the right to include the element at cursor location.
                wall++;
                // swap element at wall position with cursor position
                T temp = input.get(wall);
                input.set(wall, input.get(cursor));
                input.set(cursor, temp);
            }
        }

        // set index wall+1 as pivot
        T temp = input.get(wall+1);
        input.set(wall+1, pivot);
        input.set(high, temp);
        return wall + 1;
    }

    public static void main(String []args) {
        QuickSort qs = new QuickSort();
        List<Integer> numbers = new ArrayList<Integer>();
        numbers.addAll(Arrays.asList(4, 7, 2, 99, -3, 0));
   
        System.out.println("Before sorting: " + numbers);
        qs.quickSort(numbers);
        System.out.println("After sorting: " + numbers);
    }
}
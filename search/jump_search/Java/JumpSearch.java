import java.util.Arrays;

public class JumpSearch {

    private static final int NOT_FOUND = -1;

    /**
     * Performs the Jump Search (also called Block Search)
     *
     * @param array
     *          The input array of ints
     * @param key
     *          The int to look for
     * @return The index of the key ({@link #NOT_FOUND} if the key was not found).
     */
    static int search(int[] array, int key) {

        // Determine the block size
        int blockSize = (int) Math.sqrt(array.length);

        // Left and Right indexes for the current block
        int left = 0;
        int right = blockSize;

        // Iterate over the array until we find the right block
        while (array[right] < blockSize && right < array.length) {
            left = right;
            right += blockSize;
            if (right > array.length - 1) {
                right = array.length;
            }
        }

        // Search the block for the key
        for (int i = left; i < right; i++) {
            if (array[i] == key) {
                return i;
            }
        }

        // Return NOT_FOUND if the key was not found
        return NOT_FOUND;
    }

    public static void main(String[] args) {
        int[] test = { 1, 2, 3, 20, 60, 66, 77, 78, 100, 120, 123 };
        int key = 77;
        int indexOfKey = search(test, key);
        System.out.println("The Sample Array: " + Arrays.toString(test));
        System.out.println("The Test Key: " + key);
        System.out.println("The Index Of The Key: " + indexOfKey);
    }
}
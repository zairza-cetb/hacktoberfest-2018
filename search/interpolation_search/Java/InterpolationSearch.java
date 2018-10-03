import java.util.Arrays;

public class InterpolationSearch {
    
    private static final int NOT_FOUND = -1;
    
    static int interpolationSearch(int[] arr, int x) {
        
        // Keep track of the two indexes 
        int lo = 0;
        int hi = (arr.length - 1);
        
        while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
            
            // Calculate the position to check
            int pos = lo + (((hi-lo) /
                    (arr[hi]-arr[lo]))*(x - arr[lo]));

            // The key was found! 
            if (arr[pos] == x){
                return pos; 
            }

            // If x is larger, x is in upper part 
            if (arr[pos] < x) {
                lo = pos + 1;
            }

            // If x is smaller, x is in the lower part 
            else {
                hi = pos - 1;
            }
        }
        
        // The key was not found!
        return NOT_FOUND;
    }

    // Driver method  
    public static void main(String[] args)
    {
        int key = 18;
        int[] test = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
        int index = interpolationSearch(test, key);
        System.out.println("The Sample Array: " + Arrays.toString(test));
        System.out.println("The Test Key: " + key);
        System.out.println("The Index Of The Key: " + index);
    }
}
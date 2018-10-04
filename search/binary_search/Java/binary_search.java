  // Class binay search in java

  import java.util.ArrayList;
  import java.util.Arrays;
  import java.util.List;
  public class JavaBinaryTest {

   public JavaBinaryTest ()
   {
        javaBinarySearchTest();
   }
    public void javaBinarySearchTest() {
        List<Character> arr = new ArrayList(Arrays.asList('1', '5', '6', 'S', '7', '0', 'B', '2'));
        Character toFind = 'S';

              //  System.out.println(" --> " + javaBinarySearch(arr, toFind));
        assertTrue(javaBinarySearch(arr, toFind));

        toFind = 20;
              //  System.out.println(" --> " + javaBinarySearch(arr, toFind));
        assertFalse(javaBinarySearch(arr, toFind));

        toFind = 'T';
              //  System.out.println(" --> " + javaBinarySearch(arr, toFind));
        assertFalse(javaBinarySearch(arr, toFind));


    }

    private boolean javaBinarySearch(List<Character> arr, char toFind) {
        boolean tracesOn = false;
        Double medio = Math.floor(arr.size() / 2);
        if(tracesOn)
            System.out.println(medio);
        if(arr.size() > 1) {
            return javaBinarySearch(arr.subList(0, medio.intValue()), toFind) || javaBinarySearch(arr.subList(medio.intValue(), arr.size()), toFind);
        } else {
            if(tracesOn)
                System.out.println(" Result " + arr.get(0) + " = " + toFind + " -> " + (arr.get(0) == toFind));
            return arr.get(0) == toFind;
        }

    }
    }
    import java.util.Scanner;


    public class interpolation

    {


        public static int interpolationSearch(int[] sortedArray, int toFind)

        {

            int low = 0;

            int high = sortedArray.length - 1;

            int mid;

            while (sortedArray[low] <= toFind && sortedArray[high] >= toFind) 

            {

                if (sortedArray[high] - sortedArray[low] == 0)

                    return (low + high)/2;

                

                 mid = low + ((toFind - sortedArray[low]) * (high - low)) / (sortedArray[high] - sortedArray[low]);  

     

                 if (sortedArray[mid] < toFind)

                     low = mid + 1;

                 else if (sortedArray[mid] > toFind)

                     high = mid - 1;

                 else

                     return mid;

            }

            if (sortedArray[low] == toFind)

                return low;

               

            else

                return -1; 

        }    

        

        public static void main(String[] args) 

        {

            Scanner scan = new Scanner( System.in );        

            System.out.println("Interpolation Search Test\n");

            int n, i;

            System.out.println("Enter number of integer elements");

            n = scan.nextInt();

            

            int arr[] = new int[ n ];

            

            System.out.println("\nEnter "+ n +" sorted integer elements");

            for (i = 0; i < n; i++)

                arr[i] = scan.nextInt();

            System.out.println("\nEnter element to search for : ");

            int key = scan.nextInt();

     

            int result = interpolationSearch(arr, key);

     

            if (result == -1)

                System.out.println("\n"+ key +" element not found");

            else

                System.out.println("\n"+ key +" elemnt found at position "+ result);

     

        }    

    }


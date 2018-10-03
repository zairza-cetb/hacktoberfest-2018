public class insertion_sort 
{ 
    void sort(int arr[]) 
    { 
        int n = arr.length; 
        for (int i=1; i<n; ++i) 
        { 
            int item = arr[i]; 
            int j = i-1; 
            while (j>=0 && arr[j] > item) 
            { 
                arr[j+1] = arr[j]; 
                j = j-1; 
            } 
            arr[j+1] = item; 
        } 
    } 

    static void print(int arr[]) 
    { 
        int n = arr.length; 
        for (int i=0; i<n; ++i) 
            System.out.print(arr[i] + " "); 
  
        System.out.println(); 
    } 
    public static void main(String args[]) 
    {         
        int arr[] = {17, 14, 10, 9, 6, 1, 3, 7, 8}; 
  
        insertion_sort object = new insertion_sort();         
        object.sort(arr); 
          
        print(arr); 
    } 
}
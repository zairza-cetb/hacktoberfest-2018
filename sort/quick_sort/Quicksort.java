import java.util.*;

public class Quicksort{

    public static void main (String[] arg){
        System.out.println("insert a array disorder example: 2,4,8,3");
        Scanner sc = new Scanner(System.in);
        Quicksort.data(sc.next());
    }
    public static void data(String input){
        String[] arrayString = input.split(",");
        int i=0;
       int[] numbers=new int[arrayString.length];
        for(String vl : arrayString){
                numbers[i]=Integer.parseInt(vl);
                i++;
        }
        Quicksort.quickSort(numbers,0,numbers.length-1);
        for (int n : numbers) {
            System.out.print(n + " ");
        }
        System.out.println("");
    }

    public static void quickSort(int []numbersArrayList,int left,int right ){
        int pivot =numbersArrayList[left];
        int postLeft=left;
        int postRight=right;
        int aux;
        while(postLeft<postRight){
            postLeft=Quicksort.left(numbersArrayList,pivot,postLeft,postRight);
            postRight=Quicksort.right(numbersArrayList,pivot,postRight);
            if (postLeft < postRight) {
                aux = numbersArrayList[postLeft];
                numbersArrayList[postLeft] = numbersArrayList[postRight]; 
                numbersArrayList[postRight] = aux;
            }
        }
        numbersArrayList[left] = numbersArrayList[postRight];
        numbersArrayList[postRight] = pivot;
        if (left < postRight - 1) {
            quickSort(numbersArrayList, left, postRight - 1);
        }
        if (postRight + 1 < right) {
            quickSort(numbersArrayList, postRight + 1, right);
        }

    }

    static int left(int []numList,int pivot, int postLeft, int postRight){
        while(numList[postLeft] <= pivot && postLeft<postRight){
            postLeft++;
        }
        return postLeft;
    }

    static int right(int []numbersList,int pivot,int postRight){
        while(numbersList[postRight] > pivot){
            postRight--;
        }
        return postRight;
    }


}
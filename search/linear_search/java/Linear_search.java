
/*
Created By ram2408
*/
class Linear_search{
    public static void main(String[] args) {
        int input[]={10,64,23,41,39,100};
        int search_element=23;
        boolean found=linear_search(input,search_element);
        if(found){
            System.out.println(search_element+" is found in the array");
        }
        else System.out.println(search_element+" is not found in the array");
        search_element=12;
        found=linear_search(input,search_element);
        if(found){
            System.out.println(search_element+" is found in the array");
        }
        else System.out.println(search_element+" is not found in the array");
    }
    public static boolean linear_search(int array[],int search_element){
       int l=array.length; //size of the array
       for(int i=0;i<l;i++){
           if(array[i]==search_element){ //element is found ,return true;
               return true;
           }
       }
       return false;
    }
}
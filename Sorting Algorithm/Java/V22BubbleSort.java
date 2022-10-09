package File3_FunctionsAnd1dArray;

public class V22BubbleSort {
    public static void main(String[] args) {
        int[] myarr = {12,234,34,2,34,5,566,45};

        BubbleSort(myarr);

        //Displaying values
        for(int val:myarr){
            System.out.printf("%d,",val);
        }
    }

    // This function wil not return anything because the changes made in the array will be present in heap
    public static void BubbleSort(int[] arr){

        for(int counter=0 ; counter<arr.length-1; counter++){  // for 5 elements, we need 4 phases (run the loop 4 times (0,1,2,3))
            for(int j=0; j<arr.length-1-counter;j++){ // in each phase this loop

                if(arr[j]>arr[j+1]){
                    // Swapping
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }   
        }
    }
}

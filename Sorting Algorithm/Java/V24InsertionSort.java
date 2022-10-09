package File3_FunctionsAnd1dArray;

public class V24InsertionSort {
    public static void main(String[] args) {
        int[] myarr = {12,234,34,2,34,5,566,45};

        insertionSort(myarr);

        //Displaying values
        for(int val:myarr){
            System.out.printf("%d,",val);
        }
    }

    public static void insertionSort(int[] arr){

        for(int counter =1 ; counter<=arr.length-1 ; counter++){

            int val = arr[counter];  // 88,11,44,99,33

            // reverse loop
            int j;
            for(j=counter-1 ; j>=0 ; j--){
                
                if(val<arr[j]){
                    arr[j+1] = arr[j];
                }else{
                    arr[j+1] = val;
                    break;
                }
            }

            if(j==-1){
                arr[j+1] = val;
            }
        }
    }
}

package File3_FunctionsAnd1dArray;

public class V23SelectionSort {
    public static void main(String[] args) {
        int[] myarr = {12,234,34,2,34,5,566,45};

        selectioSort(myarr);

        //Displaying values
        for(int val:myarr){
            System.out.printf("%d,",val);
        }
    }

    public static void selectioSort(int[] arr){

        // run 4 times for an array of 5 elems  (counter = 0,1,2,3)
        for(int counter=0 ; counter < arr.length-1 ; counter++){ // for array of 5 elems, we need to set 4 elems. it should run 4 times

            int min = counter;
            
            for(int j=counter+1 ; j<=arr.length-1 ; j++){ // starting form counter+1 because we are comparing the value at index=counter with all other values. So, there is no need to compare it with itself
                if(arr[j]<arr[min]){
                    min = j;
                }
            }

            // End Of Iteration
            // Swapping
            int temp = arr[counter]; 
            arr[counter] = arr[min]; // setting the minimum value at index = 0 for iteration 1 and this goes o till index = 3
            arr[min] = temp;
        }
    }

}

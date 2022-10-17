import java.util.*;


public class Reverse_Array {
    public static void main(String[] args) {
        int size;
        Scanner ob1 = new Scanner(System.in);
        
        System.out.println("Enter the size of the array : ");
        size = ob1.nextInt();
        int arr[] = new int[size];
        
        System.out.println("Enter the elements of the array : ");
        for (int i=0; i<size ; i++) {
            arr[i] = ob1.nextInt();
        }
        System.out.println("Now the array is : ");
        for (int i=0; i<size ; i++) {
            System.out.print(arr[i]+" ");
        }
        
        
        int revArr[] = new int[size];
        System.out.println("\nNow the reverse array is : ");
        for (int i =size-1; i >=0 ; i--) {
            System.out.print(arr[i]+" ");
            revArr[i] = arr[i];
        }
        System.out.println();
    }
    
    
    
}

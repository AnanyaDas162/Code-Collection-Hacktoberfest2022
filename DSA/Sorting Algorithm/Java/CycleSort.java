import java.util.Arrays;

public class CycleSort {
    
    static void sort(int[] nums) {
        int i = 0;
        while (i<nums.length){
            int correctIndex = nums[i]-1;
            if (nums[i] != nums[correctIndex]){
                swap(nums, i, correctIndex);
            }
            else{
                i++;
            }
        }
    }

    static void swap(int[] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {1,3,5,4,2};
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }
}

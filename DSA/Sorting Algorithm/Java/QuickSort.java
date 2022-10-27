//T(n): O(n*n)
//S(n): O(1)
public class Main
{
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static int partition(int[] arr, int low, int high) {
        int pivot = high;
        int i = low - 1;
        //if any value is less than pivot, area 1 should occupy lesser elements
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < arr[pivot]) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, pivot);
        return i + 1;
    }
    public static void QuickSort(int[] arr, int low, int high) {
        if (low < high) {
            int p = partition(arr, low, high);
            QuickSort(arr, low, p - 1);
            QuickSort(arr, p + 1, high);
        }
    }
	public static void main(String[] args) {
	    int[] arr = {9, 8, 7, 5, 2, 1};
	    QuickSort(arr, 0, 5);
	    for (int i: arr) {
	    System.out.print(i +" ");
	    }
	}
}
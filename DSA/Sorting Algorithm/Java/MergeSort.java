//Sort an array using Merge Sort technique

import java.util.Arrays;
public class MergeSort {

			public static void main(String[] args) {
				int arr[] = {46,21,99,-12,11,34,85,64};
				System.out.println("Array before Sorting: " + Arrays.toString(arr));
				int n = arr.length;
				divide(arr, 0, n - 1);
				System.out.println("Array after Sorting: " + Arrays.toString(arr));
			}
			
			  public static void divide(int[] arr, int si, int ei) { 
		            if(si >= ei) {
		                return;
		            }
		            int mid = si + (ei - si)/2; 
		            divide(arr, si, mid);
		            divide(arr, mid+1, ei);
		    
		            conquer(arr, si, mid, ei);
		        }
		    
		        public static void conquer(int[] arr, int si, int mid, int ei) {
		            int[] temp = new int[ei-si+1];
		            int i = si; //for 1st sorted part
		            int j = mid+1; //for 2nd sorted part
		            
		            int k = 0;
		    
		            while(i <= mid && j <= ei) {
		                if(arr[i] < arr[j]) {
		                    temp[k] = arr[i];
		                    i++;
		                } else {
		                    temp[k] = arr[j];
		                    j++;
		                }
		                k++;
		            }
		    
		            //leftover elements of 1st sorted part
		            while(i <= mid) {
		                temp[k++] = arr[i++];
		            }
		    
		            //leftover elements of 2nd sorted part
		            while(j <= ei) {
		                temp[k++] = arr[j++];
		            }
		    
		            //copy temp to original array
		            for(k=0, i=si; k<temp.length; k++, i++) {
		                arr[i] = temp[k];
		            }
		        }
}

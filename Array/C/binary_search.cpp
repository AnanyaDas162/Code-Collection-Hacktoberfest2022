// By Kshitij Verma @kshitijv256

// Binary search implementation in C
// both using recursion and iteration methods

#include <stdio.h>

int rec_binary(int arr[], int left, int right, int x)
{
	if (right >= left) {
		int mid = left + (right - left) / 2;
		
		//When element is in the middle
		if (arr[mid] == x)
			return mid;

		//When element is in the left subarray
		if (arr[mid] > x)
			return rec_binary(arr, left, mid - 1, x);	//calling the function for only left subarray
			
		//Otherwise Element is in right subarray
		return rec_binary(arr, mid + 1, right, x);	//calling the function for only right subarray
	}

	// Element is not present
	return -1;
}

int iter_binary(int arr[], int left, int right, int x)
{
    while (left <= right) {  // It will iterate till only a single element is present else returned 
        int mid = left + (right - left) / 2;

		//checks arr[mid] value everytime value of mid changes
        if (arr[mid] == x)
            return mid;
            
        //when element is in right subarray
        if (arr[mid] < x)
            left = mid + 1;
            
        //when element is in right subarray
        else
            right = mid - 1;
    }
    
    // Element is not present
    return -1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 10, 40, 42, 53, 77 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x ;
	
	for(int i = 0; i < n; i++)
		printf("%d\t",arr[i]);
	printf("\n");
	printf("\nEnter the search value:\n\t");
	scanf("%d",&x);
	
	//Calling for recursive function
	int result = rec_binary(arr, 0, n - 1, x);
	if(result == -1){
		printf("Element is not present in array");
    }else{
		printf("\nElement is present at index(using recursion): %d", result);
    }
    
	//Calling for iterative function
	result = iter_binary(arr, 0, n - 1, x);
	if(result == -1)
		printf("Element is not present in array");
    else
		printf("\nElement is present at index(using iteration): %d", result);
	return 0;
}

// C++ implementation of Shell Sort
#include <iostream>
using namespace std;

/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n/2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct
			// location for a[i] is found
			int j;			
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			
			// put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
	return 0;
}

void printArray(int arr[], int n)
{
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = {12, 34, 54, 2, 3}, i;
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Array before sorting: \n";
	printArray(arr, n);

	shellSort(arr, n);

	cout << "\nArray after sorting: \n";
	printArray(arr, n);

	return 0;
}

/*
Time Complexity: Time complexity of the above implementation of Shell sort is O(n2). In the above implementation, the gap is reduced by half in every iteration. There are many other ways to reduce gaps which leads to better time complexity

Worst Case Complexity
The worst-case complexity for shell sort is  O(n2)

Best Case Complexity
When the given array list is already sorted the total count of comparisons of each interval is equal to the size of the given array.
So best case complexity is Ω(n log(n))
Average Case Complexity

The shell sort Average Case Complexity depends on the interval selected by the programmer. 
θ(n log(n)2).

THE Average Case Complexity: O(n*log n)
Space Complexity
The space complexity of the shell sort is O(1).
*/

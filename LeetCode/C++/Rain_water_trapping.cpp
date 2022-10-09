// C++ implementation of the approach

#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum
// water that can be stored
int maxWater(int arr[], int n)
{
	// To store the maximum water
	// that can be stored
	int res = 0;

	// For every element of the array
	for (int i = 1; i < n - 1; i++) {

		// Find the maximum element on its left
		int left = arr[i];
		for (int j = 0; j < i; j++)
			left = max(left, arr[j]);

		// Find the maximum element on its right
		int right = arr[i];
		for (int j = i + 1; j < n; j++)
			right = max(right, arr[j]);

		// Update the maximum water
		res = res + (min(left, right) - arr[i]);
	}

	return res;
}

// Driver code
int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << maxWater(arr, n);

	return 0;
}

// above code runs in O(n^2) time complexity.

// better appraoch
// creating two arrays storing max amount water from left and right

// C++ program to find maximum amount of water that can
// be trapped within given set of bars.
#include <bits/stdc++.h>
using namespace std;

int findWater(int arr[], int n)
{
	// left[i] contains height of tallest bar to the
	// left of i'th bar including itself
	int left[n];

	// Right [i] contains height of tallest bar to
	// the right of ith bar including itself
	int right[n];

	// Initialize result
	int water = 0;

	// Fill left array
	left[0] = arr[0];
	for (int i = 1; i < n; i++)
		left[i] = max(left[i - 1], arr[i]);

	// Fill right array
	right[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		right[i] = max(right[i + 1], arr[i]);

	// Calculate the accumulated water element by element
	// consider the amount of water on i'th bar, the
	// amount of water accumulated on this particular
	// bar will be equal to min(left[i], right[i]) - arr[i]
	// .
	for (int i = 1; i < n - 1; i++) {
		int var = min(left[i - 1], right[i + 1]);
		if (var > arr[i]) {
			water += var - arr[i];
		}
	}

	return water;
}

// Driver program
int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findWater(arr, n);
	return 0;
}

// above code runs in O(n) time and takes O(n) space


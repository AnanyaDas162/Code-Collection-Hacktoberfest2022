// First approach

// C++ implementation to find k numbers with most
// occurrences in the given array
#include <bits/stdc++.h>
using namespace std;

// Comparison function to sort the 'freq_arr[]'
bool compare(pair<int, int> p1, pair<int, int> p2)
{
	// If frequencies of two elements are same
	// then the larger number should come first
	if (p1.second == p2.second)
		return p1.first > p2.first;

	// Sort on the basis of decreasing order
	// of frequencies
	return p1.second > p2.second;
}

// Function to print the k numbers with most occurrences
void print_N_mostFrequentNumber(int arr[], int N, int K)
{
	// unordered_map 'mp' implemented as frequency hash
	// table
	unordered_map<int, int> mp;
	for (int i = 0; i < N; i++)
		mp[arr[i]]++;

	// store the elements of 'mp' in the vector 'freq_arr'
	vector<pair<int, int> > freq_arr(mp.begin(), mp.end());

	// Sort the vector 'freq_arr' on the basis of the
	// 'compare' function
	sort(freq_arr.begin(), freq_arr.end(), compare);

	// display the top k numbers
	cout << K << " numbers with most occurrences are:\n";
	for (int i = 0; i < K; i++)
		cout << freq_arr[i].first << " ";
}

// Driver's code
int main()
{
	int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 2;

	// Function call
	print_N_mostFrequentNumber(arr, N, K);

	return 0;
}

// above code runs in O(dlogd) time where d = count of disticnt elements in the array.
// space complexity O(d) d = count of disticnt elements in the array.

// best approach for the problem

// C++ program to find k numbers with most
// occurrences in the given array

#include <bits/stdc++.h>
using namespace std;

// Function to print the k numbers with most occurrences
void print_N_mostFrequentNumber(int arr[], int N, int K)
{
	// HashMap to store count of the elements
	unordered_map<int, int> elementCount;
	for (int i = 0; i < N; i++) {
		elementCount[arr[i]]++;
	}

	// Array to store the elements according
	// to their frequency
	vector<vector<int> > frequency(N + 1);

	// Inserting elements in the frequency array
	for (auto element : elementCount) {
		frequency[element.second].push_back(element.first);
	}

	int count = 0;
	cout << K << " numbers with most occurrences are:\n";

	for (int i = frequency.size() - 1; i >= 0; i--) {

		for (auto element : frequency[i]) {
			count++;
			cout << element << " ";
		}

		// if K elements have been printed
		if (count == K)
			return;
	}

	return;
}

// Driver's code
int main()
{
	int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 2;

	// Function call
	print_N_mostFrequentNumber(arr, N, K);

	return 0;
}
// this is the best appraoch and runs in O(n) time
// this takes O(n) space

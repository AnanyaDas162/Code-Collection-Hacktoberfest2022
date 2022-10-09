#include <bits/stdc++.h>
using namespace std;


// Function to calculate max sum of subarray
int maxsum(int arr[], int n, int k)
{
    int maximum_sum = INT_MIN;
    for (int i = 0; i <= n - k; i++) // simple brute force approach
    {
        int sum = 0;
        for (int j = i; j < k + i; j++)
        {
            sum += arr[j];
        }
        maximum_sum = max(maximum_sum, sum);
    }
    return maximum_sum;
}


// Function to calculate min sum of subarray
int minsum(int arr[], int n, int k)
{
    int minimum_sum = INT_MAX;
    for (int i = 0; i <= n - k; i++) // simple brute force approach
    {
        int sum = 0;
        for (int j = i; j < k + i; j++)
        {
            sum += arr[j];
        }
        minimum_sum = min(minimum_sum, sum);
    }
    return minimum_sum;
}


int main()
{
    int arr[] = {7, 2, 5, 1, 6, 4, 3}; // array
    int k = 3;                         // given size of subarray
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxsum(arr, n, k) << "\n"; // function call
    cout << minsum(arr, n, k) << "\n"; // function call
    return 0;
}

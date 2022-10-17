// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    
    long long mergeSort(long long arr[], long long low, long long mid, long long high){
        long long tempArr[low + high + 1], count = 0, i = low, j = mid, k = low;
        while(i <= mid - 1 && j <= high){
            if(arr[i] <= arr[j]) tempArr[k++] = arr[i++];
            else{
                tempArr[k++] = arr[j++];
                count = count + mid - i;
            }
        }
        while(i <= mid - 1) tempArr[k++] = arr[i++];
        while(j <= high) tempArr[k++] = arr[j++];
        for(int i = low; i < high + 1; i++) arr[i] = tempArr[i];
        return count;
    }
    
    long long solve(long long arr[], long long low, long long high){
        long long mid, count = 0;
        if(low < high){
            mid = (low + high) / 2;
            count += solve(arr, low, mid);
            count += solve(arr, mid + 1, high);
            count += mergeSort(arr, low, mid + 1, high);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return solve(arr, 0, N - 1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
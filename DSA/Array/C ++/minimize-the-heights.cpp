// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);
        int minE = arr[0];
        int maxE = arr[ n - 1];
        int result = arr[n - 1] - arr[0];
        
        for(int i = 0; i < n; i++){
            if(arr[i] >= k && arr[n - 1] >= k){
                maxE = max(arr[i - 1] + k, arr[n - 1] - k);
                minE = min(arr[0] + k, arr[i] - k);
                result = min(result, maxE - minE);
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
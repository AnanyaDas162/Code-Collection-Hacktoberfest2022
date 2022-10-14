//https://practice.geeksforgeeks.org/problems/ball-coloring3450/0

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    unsigned long long int noOfWays(unsigned long long int n){
        // code here
        
        return n*(n-1) + 2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long int n;
        cin >> n;
        Solution ob;
        cout<<ob.noOfWays(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
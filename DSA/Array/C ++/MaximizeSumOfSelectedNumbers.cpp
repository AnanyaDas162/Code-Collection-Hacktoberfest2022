// GFG Problem:POTD
// https://practice.geeksforgeeks.org/problems/maximize-the-sum-of-selected-numbers-from-an-array-to-make-it-empty0836/1


/*Given a array of N numbers, we need to maximize the sum of selected numbers. At each step, you need to select a number Ai, delete
one occurrence of Ai-1 (if exists), and Ai each from the array. Repeat these steps until the array gets empty. 
The problem is to maximize the sum of the selected numbers.*/


//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
         int ans=0;

        unordered_map<int,int> ump;

        for(int i=0;i<n;i++) ump[a[i]]++;

        

        // sort(a,a+n); array was already sorted but not mentioned

 

        

        for(int i=n;i>=0;i--)

        {

            if(ump[a[i]]>0)

            {

                ans+=a[i];

                ump[a[i]]--;

                if(ump[a[i]-1]>0) ump[a[i]-1]--;

            }

        }

        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends

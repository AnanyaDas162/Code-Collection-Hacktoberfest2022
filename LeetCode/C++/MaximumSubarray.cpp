#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
#include<cstring>
#include<map>
#include<cmath>
#include<conio.h>
#include<set>
typedef long long ll;
using namespace std;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size(), res = -100001;
        for (int l = 0; l < col; ++l) {
            vector<int> sums(row, 0);
            for (int r = l; r < col; ++r) {
                for (int i = 0; i < row; ++i) {
                    sums[i] += matrix[i][r];
                }

                // Find the max subarray no more than K 
                set<int> accuSet;
                accuSet.insert(0);
                int curSum = 0, curMax = -100001;
                for (int sum : sums) {
                    curSum += sum;
                    set<int>::iterator it = accuSet.lower_bound(curSum - k);
                    if (it != accuSet.end()) curMax = max(curMax, curSum - *it);
                    accuSet.insert(curSum);
                }
                res = max(res, curMax);
            }
        }
        return res;
    }
};
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = nums[0];
    int n = nums.size();
    vector<int> dp(n+1);
    dp[0]=nums[0];
    for(int i = 1;i<n;i++)
    {
        dp[i] = max(nums[i]+dp[i-1],nums[i]);
        ans = max(ans,dp[i]);
    }
    cout<<ans;
	getch();
}
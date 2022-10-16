#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
#include<cstring>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
#include<conio.h>
#include<queue>
#include <utility>
typedef long long ll;
using namespace std;
int main()
{
	getch();
}
class Solution {
public:
    int dp[301][11];
    int solve(vector<int>& mat, int n, int idx, int d) {
        if(d == 1)
            return *max_element(begin(mat)+idx, end(mat));
        
        if(dp[idx][d] != -1)
            return dp[idx][d];
    
        
        int Max = INT_MIN;
        int result = INT_MAX;
        
        for(int i = idx; i<=n-d; i++) {
            Max = max(Max, mat[i]);
            result = min(result, Max + solve(mat, n, i+1, d-1));
        }
        return dp[idx][d] = result;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        if(n < d)
            return -1;
        memset(dp, -1, sizeof(dp));
        return solve(jobDifficulty, n, 0, d);
    }
};
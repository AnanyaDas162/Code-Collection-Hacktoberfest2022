class Solution {
public:
    
   
    
    
    int solveRec(int i, string s, vector<int>&dp)
    {
        if(i>=s.size())
        {
            return 1;
        }
        if(s[i]=='0')
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        int pickOne = solveRec(i+1, s, dp);
        int pickSec = 0;
        if(i<s.size()-1 && (s[i]=='1' || s[i]=='2' && s[i+1]<='6'))
            pickSec = solveRec(i+2, s, dp);
        
        return dp[i] = pickSec+pickOne;
    }
    
    int numDecodings(string s) {
        
        int n =s.size();
        vector<int>dp(n+1, -1);
        return solveRec(0, s, dp);
        
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize DP array with INT_MAX and dp[0]=0
        int dp[amount+1];
        dp[0]=0;
        for(int i=1;i<=amount;++i)
            dp[i] = INT_MAX;

        int len = coins.size();

        // Fill DP array from amount=1 to amount's actual value
        for (int i = 1; i <= amount; ++i)
        {
            // Try to include all the coins one by one
            for (int j = 0; j < len; ++j)
            {
                // If this coin is usable(value less than current amount)
                if(coins[j] <= i){
                    // What is the cost for rest of the amount
                    // If I use this coin
                    // eg. if amount=8 and coins[j]=5 then rest is min cost
                    // for 8-5 = 3
                    int rest = dp[i-coins[j]];
                    // If including this coin gives lesser value 
                    // than current min value then include it
                    if(rest != INT_MAX && rest+1<dp[i]){
                        // update min value for amount=i
                        dp[i] = rest+1;
                    }
                }
            }
        }
        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};

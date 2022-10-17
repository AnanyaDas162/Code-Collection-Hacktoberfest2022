class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = -1, profit = 0;
        
        for(int i = prices.size() - 1; i >=0; i--){
            profit = max(profit, sell - prices[i]);
            sell = max(sell, prices[i]);
        }
        
        return profit;
    }
};
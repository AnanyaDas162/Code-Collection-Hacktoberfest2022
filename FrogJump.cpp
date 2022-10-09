class Solution {
public:
   map<int, bool> stone;
   int lastPos;
   map<pair<int, int>, bool> dp;
   bool solve(int pos, int k) {
      if (pos == lastPos)
         return true;
      if (k <= 0 || pos > lastPos)
         return false;
      if (dp.find({pos, k}) != dp.end())
         return dp[{pos, k}];
      if (stone[pos] == 1)
         return dp[{pos, k}] = solve(pos + k, k) || 
                               solve(pos + k - 1, k - 1) ||
                               solve(pos + k + 1, k + 1);
      return dp[{pos, k}] = false;
   }
   bool canCross(vector<int>& stones) {
      lastPos = stones.back();
      for (int x : stones)
         stone[x] = 1;
      if (stones[1] == 1)
         return solve(1, 1);
      return false;
   }
    
};

class Solution {
public:
    vector<vector<int>> graf;
    vector<int> nums;
    
    int comp, val;
    int dfs(int v, int par) {
        int tot = nums[v];
        for(auto x: graf[v]) {
            if(x == par) continue;
            tot += dfs(x, v);
        }
        
        if(tot == val) {
          
            comp--;
            return 0;
        }
       
        return tot;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        
        graf.resize(n);
        this->nums = nums;
        
        for(auto x: edges) {
            graf[x[0]].push_back(x[1]);
            graf[x[1]].push_back(x[0]);
        }
      
        if(count(nums.begin(), nums.end(), nums[0]) == n) return n - 1;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int res = 0;
        
       
        for(int i = 2; i * i <= sum; ++i) {
            if(sum % i == 0) {
                comp = i, val = sum / i;
                dfs(0, -1);
                if(comp == 0) res = max(res, i - 1);
                
                comp = sum / i, val = i;
                dfs(0, -1);
                if(comp == 0) res = max(res, (sum / i) - 1);
            }
        }
        
        return res;
    }
};

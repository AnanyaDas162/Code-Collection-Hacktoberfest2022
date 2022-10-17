class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int ans;
        
        long long max = getMax(nums);
        long long minPos = getMinPositive(nums);
        
        if(max <= 0) return 1;
        if(getMinPositive(nums) > 1) return 1;
        
        
        unordered_map<int,int> m;
        for(auto t: nums) { m[t]++; }
        
        //  for(auto x: m)
        // {
        //     cout << x.first << " : " << x.second << endl;
        // }
        
        for(long long i = 1; i <= max+1; i++)
        {
            if(m[i] == 0)
            {
                ans = i;
                break;
            }       
            
        }
        
        
        return ans;
        
    }
    
    int getMax(vector<int>& nums)
    {
        int max = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(max < nums[i])
            {
                max = nums[i];
            }
        }
        return max;
    }
    
    int getMinPositive(vector<int> &nums)
    {
        int min = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            if(min > nums[i] && nums[i] > 0)
            {
                min = nums[i];
            }
        }
        return min;
    }
    
};

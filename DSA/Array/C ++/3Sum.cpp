class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n<3) return res;
        sort(nums.begin(),nums.end());
        //two pointer apprach
        //fix nums[i]
        for (int i =0;i<n-2;i++){
            //if array contains duplicate we skip it
            // each element nums[i] gets only once in solutuion
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left = i+1,right = n-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if (sum==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    //removes duplicate from left and right
                    //so that same solution is not included second time
                    while(left+1<right&&nums[left]==nums[left+1]) left++;
                    while(left<right-1&&nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(sum>0)right--;
                else left++;
            }
        }
        return res;
        
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int id = abs(nums[i]) - 1;
            nums[id] *= -1;
            if(nums[id] > 0) return abs(nums[i]);
        }
        return -1;
    }
};
//https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    void subset(int ind, vector<int>& nums, vector<int>& ds,vector<vector<int>>& ans){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;//avoiding repetition if i and index are not same                                                       
            ds.push_back(nums[i]);
            subset(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());//to bring similar elements together
        subset(0,nums,ds,ans);
        return ans;
    }
};
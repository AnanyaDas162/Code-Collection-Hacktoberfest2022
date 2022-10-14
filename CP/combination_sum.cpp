//https://leetcode.com/problems/combination-sum/
class Solution {
public:
    void call(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        if(index==arr.size()){
            if(target==0) 
                ans.push_back(ds);
            return;
        }
        
        //for picked up part
        if(arr[index]<=target){
            ds.push_back(arr[index]);
            call(index, target-arr[index],arr, ans, ds);
            ds.pop_back();
        }
        //for not picked up part
        call(index+1,target,arr,ans,ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
        vector<int> ds;
        call(0,target,candidates,ans,ds);
        return ans;
    }
};
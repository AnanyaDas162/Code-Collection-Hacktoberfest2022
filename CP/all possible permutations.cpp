class Solution {
public:

    void permute(int i, vector<int>& nums, vector<vector<int> >& result, int &n) {
        if (i == n) { result.push_back(nums); return; }
        unordered_set<int> st;
        for (int j = i; j < nums.size(); ++j) {
            if (st.count(nums[j]) == 1) { continue; }
            st.insert(nums[j]);
            std::swap(nums[i], nums[j]);
            permute(i + 1, nums, result, n);
            std::swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        int n=nums.size();
        permute(0, nums, result, n);
        return result;
    }
};
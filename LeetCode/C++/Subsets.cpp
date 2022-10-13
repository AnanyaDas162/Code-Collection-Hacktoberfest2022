class Solution
{
public:
    set<vector<int>> arr;
    int n;
    void rec(vector<int> &nums, int i, vector<int> v)
    {
        if (i == n)
        {
            sort(v.begin(), v.end());
            arr.insert(v);
            return;
        }
        rec(nums, i + 1, v);
        v.push_back(nums[i]);
        rec(nums, i + 1, v);
        return;
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        n = nums.size();
        rec(nums, 0, {});
        vector<vector<int>> ans(arr.begin(), arr.end());
        return ans;
    }
};
class Solution
{
public:
    vector<vector<int>> ans;
    void fun(int start, int n, int k, vector<int> &ds)
    {
        if (ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            ds.push_back(i);
            fun(i + 1, n, k, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> ds;
        if (n < k)
            return ans;
        fun(1, n, k, ds);
        return ans;
    }
};
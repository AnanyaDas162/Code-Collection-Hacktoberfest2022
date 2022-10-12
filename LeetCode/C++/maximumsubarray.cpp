class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0, cur = 0, maxelem = -1e9;
        for (int i : nums) {
            cur += i;
            cur = max(0, cur);
            ans = max(cur, ans);
            maxelem = max(i, maxelem);
        }
        return (maxelem < 0) ? maxelem : ans;
    }
};

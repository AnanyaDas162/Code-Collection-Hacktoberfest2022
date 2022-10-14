//Leetcode 11
//Problem link
//https://leetcode.com/problems/container-with-most-water/description/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size()-1;
        int i = 0;
        int maxi=-1;
        int res;
        int m =0;
        while(n>i){
            m++;
            int j = height[i];
            int k = height[n];
            int h = min(j,k);
            res = (n-i)*h;
            maxi = max(maxi,res);
            if(j<=k){
                i++;
            }
            else{
                n--;
            }
        }
        return maxi;
    }
};
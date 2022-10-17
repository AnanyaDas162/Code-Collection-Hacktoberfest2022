class Solution {
public:
    int maxPoints(vector<vector<int>>& v) {
        int n = v.size();
        int ans = 2;
        int currMax = 0;
        
        // for flag if you dont want to check for the same pair again and again
        
        
        unordered_map<int,int> m;
        
        if(n == 1) return 1;
        if(n == 2) return 2;
              
        
        for(int i = 0; i < n -2; i++)
        {
            for(int j = i+1; j< n-1; j++)
            {
                if(m[i]==1 && m[j]==1) continue;
                currMax = 2;
                for(int k = j+1; k < n; k++)
                {
                    if(m[k]==1 && m[j]==1) continue;
                    
                    if(checkOnSameLine(v[k],v[i],v[j]))
                    {
                        currMax++;
                        m[k]++;
                        m[j]++;
                        m[i]++;
                        
                    }
                }
                
                if(currMax > ans) {ans = currMax;}
            }
        }
        
        return ans;
    }
    
    bool checkOnSameLine(vector<int>& p1, vector<int>& p2, vector<int>& p3)
    {
        // to check on the same line we must try the area method
        // if the area of triangle formed by given 3 points is 0 then all 3 points are on the same line
        
        float a = 0.5 *(p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) + p3[0] * (p1[1] - p2[1]));
        
        
        if (a < 0)
            return false;
        else if (a > 0)
            return false;
        else
            return true;
       
    }
};

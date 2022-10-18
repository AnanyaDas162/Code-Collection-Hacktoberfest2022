class Solution {
public:
 vector<int> grayCode(int n) {
        vector<int> ans={0};
        int value;
        for(int i=0;i<n;i++){
           vector<int> curr;
            for(auto it=ans.rbegin();it!=ans.rend();it++){
                curr.push_back((1<<i) | (*it) );
            }
            ans.insert(ans.end(),curr.begin(),curr.end());
        }
        return ans;
    }
};

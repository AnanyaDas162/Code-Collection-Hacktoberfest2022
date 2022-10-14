//Leetcode 3
//Problem link
//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size()==0){
            return 0;
        }
        if(s.size()==1){
            return 1;
        }
        int p = 0;
        int j = s.size()-1;
        int t = INT_MIN;
        unordered_set<char>u;
        int m = 0;
        for(int k=0;k<=j;k++){
            u.insert(s[k]);
            if(u.size()==m+1){
                m++;
            }
            else{
                k--;
                int i = u.size();
                t=max(i,t);
                u.erase(s[p]);
                p++;
                m--;
            }
        }
        int i = u.size();
        t=max(i,t);
        return t;
    }
   
};
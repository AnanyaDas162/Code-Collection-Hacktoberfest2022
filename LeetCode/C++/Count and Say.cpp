class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        string str = countAndSay(n-1);
        
        string res = "";
        int s = str.size();
        int i = 0;
        while(i<s)
        {
            char c = str[i];
            int count = 0;
            while(i<s and str[i]==c)
            {
                count++;
                i++;
            }
            res+='0'+count;
            res+=c;
        }
        return res;
    }
};

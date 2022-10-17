// You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

// Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
// Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
// Return the lexicographically smallest string that can be written on the paper.

 

// Example 1:

// Input: s = "zza"
// Output: "azz"
// Explanation: Let p denote the written string.
// Initially p="", s="zza", t="".
// Perform first operation three times p="", s="", t="zza".
// Perform second operation three times p="azz", s="", t="".



class Solution {
public:
    string robotWithString(string s) 
    {
       map<char,int>mp;
        
       for(auto x:s)  // store frequency of each character
           mp[x]++;
        char c='a'; 
        
        while(!mp[c]&&c<='z') // search for smallest element present in string  
            c++;
        string ans="";
        string rem="";
        for(int i=0;i<s.length();i++)
        {
            auto x = s[i];
            if(x==c) // if x is smallest in right , write it on paper immediately
            {
                ans+=c;
            }
            else
                rem+=x; // otherwise just append it to string rem (which is string t in question)
            mp[x]--;
            
            while(!mp[c]&&c<='z') // if frequency of smallest character in right becomes zero , look for next smallest element ahead
                c++;
            
            while(rem.length()>0&&c>=rem.back()) // if i can get element smaller than c from last of rem, pop it and write it on paper
                ans+=rem.back(),rem.pop_back();
        }
        
        reverse(rem.begin(),rem.end()); // Eventually , we have to write rem on paper by removing last char, so reverse it and append to answer
        
        ans+=rem;
        return ans;
    }
};

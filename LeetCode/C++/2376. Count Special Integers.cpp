/*
We call a positive integer special if all of its digits are distinct.

Given a positive integer n, return the number of special integers that belong to the interval [1, n].

 

Example 1:

Input: n = 20
Output: 19
Explanation: All the integers from 1 to 20, except 11, are special. Thus, there are 19 special integers.

*/

class Solution {
public:
    string s;
    long long dp[13][1 << 12][2];
    
    //ind -> current digit
    //mask -> (1 -> digit is used), (0 -> digit is not used)
    //greater -> represents whether the current formed number is smaller or not

    long long dfs(int ind, int mask, int greater) {
        if(ind == s.size()) return 1; //found a number
        if(dp[ind][mask][greater] != -1) return dp[ind][mask][greater];
        
        long long ans = 0;
        for(char c = '0'; c <= '9'; ++c) {
            if((ind == 0 and c == '0') or (mask >> (c - '0') & 1)) continue; // can't place 0 at the starting of a number or if a digit has already been used

            if(c < s[ind]) {                                    
                ans += dfs(ind + 1, mask | (1 << (c - '0')), 0);
                
                // if the current digit is lesser than the original digit at index
                // set greater to 0 because now further on we can use all the digits because now the number is smaller 
            } else if(c == s[ind]) {
                ans += dfs(ind + 1, mask | (1 << (c - '0')), greater); 
                
                //placing the exact digit at a position doesn't affect greater
            } else if(c > s[ind] and greater == 0) {                   
                ans += dfs(ind + 1, mask | (1 << (c - '0')), greater);

                // we can only place a digit greater than the original digit 
                // if our previous created answer is smaller i.e greater == 0
                // for example let the given input i.e n be 145 and 
                // we are at a stage where we have created number 13
                // now we can place all the digits from [0 ... 9] at the end because 
                // the created number will always be less than n  
            }
        }
        
        // use memoization
        return dp[ind][mask][greater] = ans;
    }

    int countSpecialNumbers(int n) {
        long long ans = 0, a = n;
        
        int digits = 0;
        while(a > 0) {
            digits++;
            a /= 10;
        }
        
        // count of numbers having distinct digits and digits less than the number of digits in n
        // numbers of size 1 = 9 ways
        // numbers of size 2 = 9 * 9 ways
        // numbers of size 3 = 9 * 9 * 8 ways
        // numbers of size 4 = 9 * 9 * 8 * 7 ways
        // ...
        for(int i = 1; i < digits; ++i) {
            long long cur = 1;
            for(int j = 1, l = 9; j <= i; ++j) {
                if(j <= 2) cur *= l;
                else cur *= (--l);
            }
            ans += cur;
        }
        

        // We use DP for calculating numbers having digits equal to the digits in given number and less than equal to n
        memset(dp, -1, sizeof dp);
        s = to_string(n);

        ans += dfs(0, 0, 1);
        
        return ans;
    }
};

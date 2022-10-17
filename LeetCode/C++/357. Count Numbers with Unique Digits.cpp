/*
Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

 

Example 1:

Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

Example 2:

Input: n = 0
Output: 1

*/

class Solution {
public:
    int permutation(int n, int r)
    {
        if(r == 0)
        {
            return 1;
        }else{
            return n * permutation(n - 1, r - 1);
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        if(n > 0)
        {
           int end = (n > 10)? 10 : n;
           for(int i = 0; i < end; i++)
           {
               sum += 9 * permutation(9, i);
           }
        }
        return sum;
    }
};

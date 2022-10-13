class Solution {
    public int climbStairs(int n) {
        int a=0;
        int b=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=a+b;
            a=b;
            b=sum;
        }
        return sum;
    }
}

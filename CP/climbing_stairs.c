//https://leetcode.com/problems/climbing-stairs/
int climbStairs(int n){
if(n<=2) return n;
    int x=1,y=2;
    for(int k=3;k<n;k++){
        int temp=y;
        y=y+x;
        x=temp;
            
    }return (x+y);
}
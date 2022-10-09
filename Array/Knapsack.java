import java.util.*;

class DP{
    static int Knapsack(int W, int wt[], int val[], int n)
    {
    	int []dp = new int[W + 1];
    	for (int i = 1; i < n + 1; i++) {
    	    for (int w = W; w >= 0; w--) {
    		    if (wt[i - 1] <= w)
    		    dp[w] = Math.max(dp[w],
    			dp[w - wt[i - 1]] + val[i - 1]);
    	    }
    	}
    	return dp[W];
    }
    public static void main(String[] args)
    {
	    int val[] = { 60, 100, 120 };
	    int wt[] = { 10, 20, 30 };
	    int W = 50;
	    int n = val.length;
	    System.out.print(Knapsack(W, wt, val, n));
    }
}

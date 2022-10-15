

 class MaximalNetworkRank {
	 class Solution 
	 {
	     public int maximalNetworkRank(int n, int[][] roads) 
	     {
	         int[] degree = new int[n];
	         HashSet<String> hs = new HashSet<>();
	         
	         for(int[] x:roads)
	         {
	             degree[x[0]]++;
	             degree[x[1]]++;
	             
	             hs.add(x[0]+"-"+x[1]);
	             hs.add(x[1]+"-"+x[0]);
	         }
	         
	         int res = 0;
	         for(int i=0;i<n;i++)
	         {
	             for(int j=i+1;j<n;j++)
	             {
	                 int val = degree[i] + degree[j];
	                 if(hs.contains((i+"-"+j)))
	                     val -= 1;
	                 
	                 res = Math.max(res, val);
	             }
	         }
	         return res;
	     }
	 }
}

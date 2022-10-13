 class PalindromePartitioning {

	 public int palindromePartition(String s, int k) {
	        if(s.length() == k) return 0;
	        int n = s.length();
	        int dp[][] = new int[n][n];
	        
	        //Counting no.of changes to make a substring palindrome for each substring
	        for(int i = n-1; i>=0; i--){
	            for(int j = i; j<n; j++){
	                if(i-j == 0) dp[i][j] = 0;
	                else{
	                    dp[i][j] = dp[i+1][j-1];
	                    if(s.charAt(i) != s.charAt(j)){
	                        dp[i][j] += 1;
	                    }
	                }
	            }
	        }
	       
	        int countdp[][] = new int [k+1][n];
	        
	        // Count min no. of changes for each substring for k partitions
	        for(int i = 1; i<=k; i++){
	            for(int j = 0; j<n; j++){
	                if(i == 1) countdp[i][j] = dp[i-1][j];
	                else{
	                    if(i - j < 1){
	                        int min = 100000;
	                        for(int l = j; l>=i-1 ; l--){
	                            min = Math.min(countdp[i-1][l-1] + dp[l][j], min);
	                            if(min == 0) break;
	                        }
	                        countdp[i][j] = min;
	                    }
	                }
	            }
	        }
	        return countdp[k][n-1];
	    }

}


 class SortTheMatrixDiagonally {
	 class Solution {
		    public void sum(int[] count) {
		        for(int i = 1; i < count.length; i++) {
		            count[i] = count[i] + count[i-1];
		        }
		    }
		    
		    public void sort(int[][] mat, int[][] res, int a, int b) {
		        int[] count = new int[101];
		        int i = a, j = b;
		        while(i < mat.length && j < mat[0].length) {
		            count[mat[i][j]]++;
		            i++; j++;
		        }
		        sum(count);
		        i = a; j = b;
		        while(i < mat.length && j < mat[0].length) {
		            int inx = --count[mat[i][j]] ;
		            res[a+inx][b+inx] = mat[i][j];
		            i++; j++;
		        }
		    }
		    
		    public int[][] diagonalSort(int[][] mat) {
		        int[][] res = new int[mat.length][mat[0].length];
		        
		        int a = mat.length-1;
		        int b = 0;
		        while(b < mat[0].length) {
		            sort(mat, res, a, b);
		            if (a < 1) {
		                b++;
		            } else {
		                a--;
		            }
		        }
		        return res;
		    }

}

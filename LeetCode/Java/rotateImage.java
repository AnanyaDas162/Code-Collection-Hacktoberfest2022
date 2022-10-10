class Solution {
    public void rotate(int[][] matrix) {
        //transpose
        int i,j;
        for(i=0;i<matrix.length;i++)
        {
            for(j=i;j<matrix[i].length;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(i=0;i<matrix.length;i++)
        {
            int l=0;
            int p=matrix[i].length-1;
            while(l<p)
            {
                int temp=matrix[i][l];
                matrix[i][l]=matrix[i][p];
                matrix[i][p]=temp;
                l++;
                p--;
            }
        }
    }
}

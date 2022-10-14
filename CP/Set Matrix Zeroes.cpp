//Leetcode 73
//Problem link
//https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int r[row];
        int c[col];
        for(int i=0;i<row;i++){
            r[i]=-1;
        }
        for(int i=0;i<col;i++){
            c[i]=-1;
        }
        for(int i=0;i<row;i++){
            for(int j=0; j<col;j++){
                if(matrix[i][j]==0){
                    r[i]=0;
                    c[j]=0;
                }
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0; j<col;j++){
                if(r[i]==0 || c[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
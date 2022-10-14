//Leetcode 51
//Problem link
//https://leetcode.com/problems/n-queens/
class Solution {
public:
    bool istrue(int col,int row,vector<string>&v,int n){
        int row1=row;
        int col1=col;
        while(row1>=0 && col1>=0){
            if(v[row1][col1]=='Q'){
                return false;
            }
            row1--;
            col1--;
        }
        row1=row;
        col1=col;
        while(row1<n && col1>=0){
            if(v[row1][col1]=='Q'){
                return false;
            }
            row1++;
            col1--;
        }
        row1=row;
        col1=col;
        while(col1>=0){
            if(v[row1][col1]=='Q'){
                return false;
            }
            col1--;
        }
        return true;
    }
    
    
    void sol(int col,vector<vector<string>>&ans,vector<string>&v,int n){
       if(col==n){
           ans.push_back(v);
           return;
        }
        for(int row=0;row<n;row++){
            if(istrue(col,row,v,n)){
                v[row][col]='Q';
                sol(col+1,ans,v,n);
                v[row][col]='.';
            }
        }  
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>v(n,string(n,'.'));
        sol(0,ans,v,n);
        return ans;
    }
};
#include<iostream>
#include<queue>
using namespace std;
void solve(int col, vector<string>board, vector<vector<string>>&ans, vector<int>leftrow, vector<int>upperDiagonal, vector<int>lowerDiagonal, int n){
    if(col==n){
        for(int i=0;i<n;i++){
            cout<<"|";
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<"|";
            }
            cout<<endl;
        }
        cout<<"+++++++++++"<<endl;
        return;
    }
    for(int row=0;row<n;row++){
        if(leftrow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
            //updating
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1+col-row] = 1;
            solve(col+1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n); //recursion
            //backtracking
            board[row][col] = '_';
            leftrow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1+col-row] = 0;
        }
    }
}

int main(){
    int n=6;
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'_');
    // cout<<s<<endl;
    for(int i=0;i<n;i++){
        board[i] = s;
    }
    // for(int i=0;i<n;i++){
    //     cout<<board[i]<<endl;
    // }

    vector<int>leftrow(n,0);
    vector<int>upperDiagonal(2*n -1,0);
    vector<int>lowerDiagonal(2*n -1,0);
    int col=0;
    solve(col,board,ans,leftrow,upperDiagonal,lowerDiagonal,n);
}
//https://leetcode.com/problems/n-queens-ii/
class Solution {
public:
 

bool isSafe(int row, int col, vector<string> board, int n){
    
    int tempRow = row;
    int tempCol = col;
    
    // Checking till top left diagonal end
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q'){
            return false;
        }
        
        row--;
        col--;
    }
    
    //Checking till left end
    row = tempRow;
    col = tempCol;
    while(col >= 0){
        if(board[row][col] == 'Q'){
            return false;
        }
        
        col--;
    }
    
    //Checking till down left diagonal end
    row = tempRow;
    col = tempCol;
    while(row < n && col >= 0){
        if(board[row][col] == 'Q'){
            return false;
        }
        
        row++;
        col--;
    }
    
    return true;
}



void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
    int k;
    
    if(col == n){
        ans.push_back(board);//push ans
        return ;
    }
    
    
    for(int row = 0 ; row < n ; row++){
        
        
        if(isSafe(row, col, board, n)){
            
            board[row][col] = 'Q';//if safe put Q
            solve(col + 1, board, ans, n);//call recursion for the n ext column
            board[row][col] = '.';//omit the Q after returning from recursion to check the next row 
        }
    }
    
}




/*vector<vector<string>> solveNQueens(int n){
    
    vector<vector<string>> ans;
    vector<string> board(n);
    
    string s(n, '.');
    for(int i=0 ; i<n ; i++){
        board[i] = s;
    }
    
    solve(0, board, ans, n);
    
    return ans;
}
};*/
    
    
    int totalNQueens(int n) {
         vector<vector<string>> ans;
    vector<string> board(n);
    
    string s(n, '.');
    for(int i=0 ; i<n ; i++){
        board[i] = s;
    }
    
    solve(0, board, ans, n);
    return ans.size();
    
    }
};
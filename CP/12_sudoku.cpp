// #include<iostream>
// #include<queue>
// using namespace std;
// bool SolveSudoku(int grid[N][N])  
//     { 
//         // Your code here
//         for(int i=0;i<9;i++){
//             for(int j=0;j<9;j++){
//                 if(grid[i][j]==0){
//                     for(int k=1;k<=9;k++){
//                         if(isValid(grid,i,j,k)){  //if that value can be placed
//                             grid[i][j]=k;
//                             if(SolveSudoku(grid)==true){ //recursion, stop once a result is found
//                                 return true;
//                             }
//                             else{
//                                 grid[i][j]=0; //backtracking if solution is not found
//                             }
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//    }
//     bool isValid(int grid[N][N],int row, int col, int k){
//         for(int i=0;i<9;i++){
//             if(grid[row][i]==k){   //checking every column of a row
//                 return false;
//             }
//             if(grid[i][col]==k){    // checking every row of a column
//                 return false;
//             }
//             if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==k){  //checking that 3x3 box
//                 return false;
//             }
//         }
//         return true;
//     }
    
//     //Function to print grids of the Sudoku.
//     void printGrid (int grid[N][N]) 
//     {
//         // Your code here 
//         for(int i=0;i<9;i++){
//             for(int j=0;j<9;j++){
//                 cout<<grid[i][j]<<" ";
//             }
//         }
//     }
// int main(){
//         int N = 9;

//     }
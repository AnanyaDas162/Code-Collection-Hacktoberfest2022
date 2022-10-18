class Solution {
public:
    int row, col;
    void dfs(vector<vector<char>> & grid, int y, int x){
        if(y < 0 || x < 0 || y >= row || x >= col || grid[y][x] != '1')
            return ;
        grid[y][x] = '#';
        dfs(grid, y + 1, x);
        dfs(grid, y - 1, x);
        dfs(grid, y, x - 1);
        dfs(grid, y, x + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if(!row) return 0;
        col = grid[0].size();
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

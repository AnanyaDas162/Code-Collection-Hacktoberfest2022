class Solution {
public:
   
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                if(i == 0)
                    peri++;
                else
                    peri += (grid[i - 1][j] == 0);
                if(j == 0)
                    peri++;
                else
                    peri += (grid[i][j - 1] == 0);
                if(i == grid.size() - 1)
                    peri++;
                else
                    peri += (grid[i + 1][j] == 0);
                if(j == grid[0].size()- 1)
                    peri++;
                else
                    peri += (grid[i][j + 1] == 0);
                }
            }
        }
        
        return peri;
    }
};

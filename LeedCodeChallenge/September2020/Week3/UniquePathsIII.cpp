class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {        
        int startX = -1, startY = -1;
        int fieldCounter = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 0)
                    ++fieldCounter;
                else if (grid[i][j] == 1){
                    startX = j;
                    startY = i;
                }
        return dfs(grid, startX, startY, fieldCounter);
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y, int fieldCounter) {
        if (x < 0 || x == grid[0].size() || y < 0 || y == grid.size() || grid[y][x] == -1)
            return 0;
        if (grid[y][x] == 2)
            return fieldCounter == -1;
        grid[y][x] = -1;
        int paths = dfs(grid, x + 1, y, fieldCounter-1) + dfs(grid, x - 1, y, fieldCounter-1)
                  + dfs(grid, x, y + 1, fieldCounter-1) + dfs(grid, x, y - 1, fieldCounter-1);
        grid[y][x] = 0;
        return paths;        
    }
};
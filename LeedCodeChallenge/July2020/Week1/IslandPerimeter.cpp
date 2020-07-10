class Solution {
public:
    
    void checkPerimeter(vector<vector<int>>& grid, int &posX, int &posY, int &perimeter){
        if(posX-1>=0){
            if(grid[posX-1][posY]==1)
                ++perimeter;
        }
        if(posX+1<grid.size()){
            if(grid[posX+1][posY]==1)
                ++perimeter;
        }
        if(posY-1>=0){
            if(grid[posX][posY-1]==1)
                ++perimeter;
        }
        if(posY+1<grid[0].size()){
            if(grid[posX][posY+1]==1)
                ++perimeter;
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;

        int perimeter=0;
        
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]==0)
                    checkPerimeter(grid, i, j, perimeter);

            } 
        }
        
        
        for(int i=0; i<grid[0].size(); i++){
            if(grid[0][i]==1)
                ++perimeter;
            if(grid[grid.size()-1][i]==1)
                ++perimeter;
        }
        
        for(int i=0; i<grid.size(); i++){
            if(grid[i][0]==1)
                ++perimeter;
            if(grid[i][grid[0].size()-1]==1)
                ++perimeter;
        }
        
        return perimeter;
    }
};
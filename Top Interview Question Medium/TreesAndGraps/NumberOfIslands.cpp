class Solution {
public:
    
    void zeroingNeighbours(vector<vector<char>> &temp, int x, int y){
        if(temp[x][y]=='1'){
            temp[x][y]='0';
            if(x+1<temp.size())
                zeroingNeighbours(temp,x+1,y);
            if(x-1>=0)
                zeroingNeighbours(temp,x-1,y);
            if(y-1>=0)
                zeroingNeighbours(temp,x,y-1);
            if(y+1<temp[x].size())
                zeroingNeighbours(temp,x,y+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
    int counter=0;
        
        for(int i=0; i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]=='1'){
                    ++counter;
                    zeroingNeighbours(grid,i,j);
                }
            }
        }
        return counter;
    }
};

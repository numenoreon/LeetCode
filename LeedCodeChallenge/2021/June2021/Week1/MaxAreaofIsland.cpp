class Solution {
public:
    
    void dfs(int X, int Y, const int &N, const int &M, vector<vector<int>>& grid, int &counter){
        ++counter;
        grid[X][Y]=0;
        if(X-1>=0 && grid[X-1][Y]==1){
            dfs(X-1, Y, N, M, grid, counter);
        }
        if(Y-1>=0 && grid[X][Y-1]==1){
            dfs(X, Y-1, N, M, grid, counter);
        }
        if(X+1<N && grid[X+1][Y]==1){
            dfs(X+1, Y, N, M, grid, counter);
        }
        if(Y+1<M && grid[X][Y+1]==1){
            dfs(X, Y+1, N, M, grid, counter);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int N=grid.size(), M=grid[0].size();
        int counter = 0, result=0;;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(grid[i][j]){
                    counter=0;
                    dfs(i,j,N,M,grid, counter);
                    result=max(result, counter);
                }
            }
        }
        
        return result;
    }
};
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int N = obstacleGrid.size(), M=obstacleGrid[0].size();
        vector <vector <int>> grid (N, vector <int> (M, 0));

        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(obstacleGrid[i][j]==1)
                    continue;
                if(i==0 && j==0)
                    grid[i][j]=1;
                else if(j==0){
                    grid[i][j]=+grid[i-1][j];
                }
                else if(i==0){
                    grid[i][j]=+grid[i][j-1];
                }
                else{
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
                }
               
            }
        }   
        
        return grid[N-1][M-1];
    }
};
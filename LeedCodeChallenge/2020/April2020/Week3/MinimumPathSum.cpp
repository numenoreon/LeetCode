class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int N=grid.size(), M=grid[0].size();
        vector<vector<int> > dp ( N , vector<int> (M));
        
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                dp[i][j]+=grid[i][j];
                if(i>0 && j>0)
                    dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
                else if(i>0)
                    dp[i][j]+=dp[i-1][j];
                else if(j>0)
                    dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[N-1][M-1];
    }
};

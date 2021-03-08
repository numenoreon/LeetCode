class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int N=dungeon.size(), M=dungeon[0].size();
        vector <vector <int>> dp (N, vector <int> (M,0));
        
        if(N==1 && M==1)
            return max(1, 1-dungeon[0][0]);
        
        int minVal=INT_MAX;
        
        for(int i=N-1; i>=0; --i){
            for(int j=M-1; j>=0; --j){
                if(j==M-1 && i == N-1){
                    dp[i][j]=max(1,1-dungeon[i][j]);
                }else if(j==M-1){
                    dp[i][j]=max(1, dp[i+1][j]-dungeon[i][j]);
                }
                else if(i==N-1){
                    dp[i][j]=max(1, dp[i][j+1]-dungeon[i][j]);
                }
                else{
                    dp[i][j]=max(1, min(dp[i+1][j], dp[i][j+1])-dungeon[i][j]);
                }
            }
        }

        return dp[0][0];
    }
};
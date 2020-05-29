class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
     
        vector < vector <int> > dp (A.size(), vector <int> (A[0].size(), 0));
        dp[0]=A[0];
        
        for(int i=1; i<A[0].size(); ++i){
            dp[i][0]=min(dp[i-1][0], dp[i-1][1])+A[i][0];
            dp[i][A.size()-1]=min(dp[i-1][A.size()-2], dp[i-1][A.size()-1])+A[i][A.size()-1];   
            for(int j=1; j<A.size()-1; ++j){
                dp[i][j]=min(min(dp[i-1][j],dp[i-1][j-1]), dp[i-1][j+1])+A[i][j];
            }
        }
        
        int minSum=INT_MAX;
        for(int i=0; i<A.size(); ++i){
            minSum=min(minSum, dp[A.size()-1][i]);
        }
        
        return minSum;
    }
};
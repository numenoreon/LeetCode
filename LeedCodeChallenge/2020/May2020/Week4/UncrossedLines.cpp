class Solution {
public:
int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    const int N=A.size(), M=B.size();
    
    vector<vector<int>> dp (N+1,vector<int>(M+1,0));

    for(int i=1; i<N+1 ;i++){
        for(int j=1; j<M+1 ;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return dp[N][M];
    }
};


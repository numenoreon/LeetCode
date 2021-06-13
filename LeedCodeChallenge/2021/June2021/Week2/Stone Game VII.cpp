class Solution {
public
    int stoneGameVII(vectorint& A) {
        const int N = A.size();
        vector int myVec(N + 1);
        for (int i = 0; i  N; ++i)
            myVec[i + 1] = myVec[i] + A[i];
        vector  vectorint  dp(N, vectorint(N));
        
        for (int pos = 2; pos = N; ++pos) {
            for (int i = 0; i = N - pos; ++i) {
                int j = i + pos - 1;
                dp[i][j] = max(myVec[j + 1] - myVec[i + 1] - dp[i + 1][j], myVec[j] - myVec[i] - dp[i][j - 1]);
            }
        }
        return dp[0][N - 1];
    }
};
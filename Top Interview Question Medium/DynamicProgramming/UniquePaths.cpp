class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
        int board[n][m];
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(i==0 || j==0)
                    board[i][j]=1;
                else
                    board[i][j]=board[i-1][j]+board[i][j-1];
            }
        }
        
        return board[n-1][m-1];
    }
};
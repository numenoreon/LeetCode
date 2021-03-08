class Solution {
    
void dfs(vector<vector <char>> &board, const int &N, const int &M, int posX, int posY){
    if(posX <0 || posY <0 || posY >= M || posX >=N)
        return ;
    if(board[posX][posY]=='O'){
        board[posX][posY]='C';
        dfs(board, N, M, posX+1 , posY);
        dfs(board, N, M, posX-1 , posY);
        dfs(board, N, M, posX , posY+1);
        dfs(board, N, M, posX , posY-1);
    }
}
    
public:
    void solve(vector<vector<char>>& board) {
        
        if(board.empty())
            return ;
        
        const int N=board.size(), M=board[0].size();

        for(int i=0; i<N; i++){
            if(board[i][0]=='O')
                dfs(board, N, M, i, 0);
            if(board[i][M-1])
                dfs(board, N, M, i, M-1);
        }

        for(int i=0; i<M; i++){
            if(board[0][i]=='O')
                dfs(board, N, M, 0, i);
            if(board[N-1][i]=='O')
                dfs(board,N, M, N-1, i);
        }
        
        for(auto &i : board)
            for(auto &j : i)
                j=='C' ? j='O' : j='X';
        
    }
};

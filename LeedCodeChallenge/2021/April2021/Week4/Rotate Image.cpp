class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        const int N = matrix.size(), M= matrix[0].size();
        
        for(int i=0; i<N; ++i){
            for(int j=0; j<M/2; ++j){
                swap(matrix[i][j], matrix[i][N-1-j]);
            }
        }
        
        int X = M-2;
            
        for(int i=0; i<N; ++i){
            for(int j=X; j>=0; --j){
                cout << matrix[i][j] << " " << matrix[N-1-j][N-1-i] << endl;
                swap(matrix[i][j] , matrix[N-1-j][N-i-1]);
            }
            --X;
        }

    }
};
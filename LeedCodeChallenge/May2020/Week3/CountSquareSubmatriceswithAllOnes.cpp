class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        for(int i=1; i<matrix.size(); ++i){
            for(int j=1; j<matrix[i].size(); ++j){
                if(matrix[i][j]==1)
                    matrix[i][j]=min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i][j-1]))+1;
            }
        }
        
        int counter=0;
        
        for(auto &i : matrix)
            for(auto &j : i)
                counter+=j;
  
        
        return counter;
    }
};

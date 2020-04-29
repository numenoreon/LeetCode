class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int maxSquare=0;
        vector < vector <int> >  nums (matrix.size(), vector <int> (matrix[0].size(), 0));
        
        for(int i=0; i<matrix.size(); ++i){ // changing to vector of integer
            for(int j=0; j<matrix[i].size(); ++j){
                if(matrix[i][j]=='0')
                    nums[i][j]=0;
                else{
                    maxSquare=1;
                    nums[i][j]=1;
                }
            }
        }
        
        for(int i=1; i<matrix.size(); ++i){
            for(int j=1; j<matrix[i].size(); ++j){
                 if(nums[i][j]==1){
                    nums[i][j] = min(nums[i][j-1], min(nums[i-1][j], nums[i-1][j-1])) + 1;
                    maxSquare=max(maxSquare, nums[i][j]);
                 }
                else
                    nums[i][j]=0;
            }
        }


        return maxSquare*maxSquare;
    }
};
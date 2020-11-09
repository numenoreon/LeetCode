class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        else if(matrix[0].empty())
            return false;
        
        int N = 0,  M=matrix[0].size()-1;
        
        while(M>=0 && N<matrix.size()){
            
            if(matrix[N][M]==target)
                return true;
            else if(matrix[N][M]>target){
                --M;
            }
            else if(matrix[N][M]<target){
                ++N;
            }
            if(N==matrix.size())
                return false;
        }
        
        return false;
    }
};
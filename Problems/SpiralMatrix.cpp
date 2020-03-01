class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(!matrix.size())
            return {};
        
        int condition = matrix.size() * matrix[0].size();
        vector <int> result;
        result.reserve(condition);
        
        int left = 0, right = matrix[0].size(), top = 0, bottom = matrix.size();
        
        while(condition > result.size())
        {
            for(int i=left; i<right && result.size()<condition; ++i){
                result.push_back(matrix[top][i]);
            }

            for(int i=top+1; i<bottom && result.size()<condition; ++i){
                result.push_back(matrix[i][right-1]);
            }

            for(int i=right-2; i>=left && result.size()<condition; --i){
                result.push_back(matrix[bottom-1][i]);
            }

            for(int i=bottom-2; i>top && result.size()<condition; --i){
                result.push_back(matrix[i][left]);
            }
            ++top, ++left, --bottom, --right;
        }
        
        return result;
    }
};
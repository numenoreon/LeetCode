class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return {};
        else if (numRows == 1)
            return {{1}};
        else if (numRows == 2)
            return {{1}, {1,1}};
        
        vector < vector <int> > result {{1}, {1,1}};
        for(int i=2; i<numRows; ++i){
            result.push_back({});
            for(int j=0; j<i+1; ++j){
                if(j==0 || j == i)
                    result[i].push_back(1);
                else
                    result[i].push_back(result[i-1][j-1]+result[i-1][j]);
            }
        }
        
        return result;
    }   
};
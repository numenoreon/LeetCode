class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)
            return {1};
        else if(rowIndex==1){
            return {1,1};
        }
        
        vector < vector<int> > result {{1}, {1,1}};
        result.reserve(rowIndex);
        
        for(int i=2; i<rowIndex+1; ++i){
            result.push_back({});
            for(int j=0; j<i+1; ++j){
                if(j==0 || j==i)
                    result[i].push_back(1);
                else
                    result[i].push_back(result[i-1][j-1]+result[i-1][j]);
            }
        }
        
        return result[rowIndex];
    }
};
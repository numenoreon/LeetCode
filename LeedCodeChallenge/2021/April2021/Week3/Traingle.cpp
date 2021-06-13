class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1)
            return triangle[0][0];
            
        vector < vector <int> > result {{triangle[0][0]}, 
                {triangle[1][0]+triangle[0][0], triangle[1][1]+triangle[0][0]}
        };
        
        for(int i=2; i<triangle.size(); ++i){
            vector <int> temp = triangle[i];
            for(int j=0; j<temp.size(); ++j){
                if(j==0){
                    temp[j]+=result[i-1][0];
                }
                else if(j==temp.size()-1){
                    temp[j]+=result[i-1][result[i-1].size()-1];
                }
                else{
                    temp[j]+=min(result[i-1][j-1], result[i-1][j]);
                }
                
            }
            result.push_back(temp);
        }
        
        int minVal=INT_MAX;
        for(int i=0; i<result[result.size()-1].size(); ++i){
            minVal=min(minVal, result[result.size()-1][i]);
        }
        return minVal;
    }
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector <vector <int> > result (n);
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                result[i].push_back(0);
            }
        }
        
        int counter = 0, left = 0,  up = 0, right = n, down = n;

        while(counter<n*n){
            for(int i=left; i < right; ++i){
                ++counter;
                result[up][i]=counter;
            }
            ++up;
            for(int i=up; i < down; ++i){
                ++counter;
                result[i][right-1]=counter;
            }
            --right;
            for(int i=right-1; i >= left; --i){
                ++counter;
                result[down-1][i]=counter;
            }
            --down;
            for(int i=down-1; i >= up; --i){
                ++counter;
                result[i][left]=counter;
            }
            ++left;
        }
        
        return result;
    }
};
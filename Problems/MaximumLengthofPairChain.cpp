class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(), pairs.end(), [](vector <int> &a, vector <int> &b){
            return a[1]<b[1];
        });

        int counter = 1, k=0;
        
        for(int i=0; i<pairs.size()-1; ++i){
            if(pairs[k][1]<pairs[i+1][0]){
                k=i+1;
                ++counter;
            }
        }
        
        return counter;
    }
};
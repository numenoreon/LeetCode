class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map <int, int> mapsMe;
        
        const int N = wall.size();
        
        for(int i=0; i<N; ++i){
            int temp=0;
            for(int j=0; j<wall[i].size()-1; ++j){
                temp+=wall[i][j];
                ++mapsMe[temp];
            }
        }
        
        int nonCross = 0;
        for(auto &i: mapsMe){
            nonCross=max(nonCross, i.second);
        }
        
        return N-nonCross;
    }
};
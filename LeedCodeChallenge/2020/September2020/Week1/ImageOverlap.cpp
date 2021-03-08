class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector <pair <int, int>> image1, image2;
        
        const int N = A.size();
        const int M = A[0].size();
        
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(A[i][j])
                    image1.push_back({i,j});
                if(B[i][j])
                    image2.push_back({i,j});
            }
        }
        
        unordered_map<string, int> mapsMe;
        int result = 0;
        
        for (auto& p1 : image1)
        {
            for (auto& p2 : image2)
            {
                string key = to_string(p2.first-p1.first) + " " + std::to_string(p2.second-p1.second);
                ++mapsMe[key];
                result = max(result, mapsMe[key]);
            }
        }
        return result;
    }
};
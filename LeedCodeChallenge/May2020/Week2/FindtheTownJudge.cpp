class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector <pair <int, int>> person (N);
        
        for(int i=0; i<trust.size(); ++i){
            ++person[trust[i][0]-1].first;
            ++person[trust[i][1]-1].second;
        }
        
        int candidate=-1;
        for(int i=0; i<person.size(); ++i){
            if(person[i].first == 0 && person[i].second == N-1){
                if(candidate != -1)
                    return -1;
                candidate=i+1;
            }
        }
        
        return candidate;
    }
};
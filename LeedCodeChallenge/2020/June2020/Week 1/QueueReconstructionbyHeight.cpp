class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        vector < vector <int> > result;
        result.reserve(people.size());
        
        auto comp = [&people](const vector <int> &one, const vector <int> &two){
            return (one[0]>two[0] || (one[0]==two[0] && one[1]<two[1]));
        };
        
        sort(people.begin(), people.end(), comp);
        
        for(auto &i : people){
            result.insert(result.begin()+i[1],i);
        }
        
        
        return result;
    }
};
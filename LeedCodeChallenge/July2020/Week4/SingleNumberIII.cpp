class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map <int, int> mapsMe;
        vector <int> result;
        
        for(auto &i : nums)
            ++mapsMe[i];
        for(auto &i : mapsMe){
            if(i.second==1)
                result.push_back(i.first);        }
        
        return result;
    }
};
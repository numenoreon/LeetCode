class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int N = nums.size()/3;

        unordered_map <int, int> mapsMe;
        vector <int> result;
        result.reserve(N);
        
        for(auto &i: nums)
            ++mapsMe[i];
        
        for(auto &x : mapsMe){
            if(x.second>N)
                result.push_back(x.first);
        }
        
        return result;
    }
};
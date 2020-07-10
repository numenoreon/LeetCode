class Solution {
public:
    
    unordered_map <int, int> mapsMe;
    
    int singleNumber(vector<int>& nums) {

        for(auto &i: nums)
            ++mapsMe[i];
        
        for(auto &i : mapsMe)
            if(i.second==1)
                return i.first;
            
        return -1;
    }
};
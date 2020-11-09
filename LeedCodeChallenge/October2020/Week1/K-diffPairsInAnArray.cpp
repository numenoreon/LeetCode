class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        if(nums.empty())
            return 0;
        
        
        unordered_map <int, int> mapsMe;
        int counter=0;
        
        for(auto &i : nums)
            ++mapsMe[i];
        
        if(k==0){
            for(auto &i : mapsMe){
                if(i.second>1)
                    ++counter;
            }
            return counter;
        }
        
        for(auto &i : mapsMe){
            if(mapsMe.count(i.first+k))
                ++counter;
        }
        
        
        return counter;
    }
};
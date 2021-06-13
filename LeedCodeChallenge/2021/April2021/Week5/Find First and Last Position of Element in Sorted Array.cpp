class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1,-1};
        
        auto low=find(nums.begin(), nums.end(), target);
        
        if(low==nums.end())
            return {-1,-1};
        
        auto up = low;
        
        while(up!=nums.end() && *up==target)
            ++up;
        
        int l = low-nums.begin(),u = up-nums.begin()-1; 
        return { l, u};
    }
};
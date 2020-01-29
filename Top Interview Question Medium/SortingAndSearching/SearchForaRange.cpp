class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low=std::lower_bound (nums.begin(), nums.end(), target);
        auto up= std::upper_bound (nums.begin(), nums.end(), target);
        
        return up==low ? {-1,-1} : {low-nums.begin(),up-nums.begin()-1} ;
    }
};
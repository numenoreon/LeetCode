class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i=i+2){
            if(i+1>=nums.size()) return nums[nums.size()-1];
            if(nums[i]!=nums[i+1]){
               return nums[i];
            }
        }
        return 0;
    }
};
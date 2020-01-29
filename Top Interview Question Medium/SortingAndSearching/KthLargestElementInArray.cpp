class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        if(k==nums.size())
            return nums[0];
        
        
        
        int i = nums.size()-2, j=1;
        
        int tempMax=nums[nums.size()-1];
        while(i>0 && j!=k){
            if(nums[i]<=tempMax){
                ++j;
                tempMax=nums[i];
            }
            --i;
        }
        
        return tempMax;
    }
};
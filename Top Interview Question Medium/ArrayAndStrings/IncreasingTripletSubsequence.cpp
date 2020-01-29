class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(!nums.size())
            return false;
        for(int i=1; i<nums.size()-1; ++i){
            int j=0,k=nums.size()-1;
            while(1){
                if(nums[j]<nums[i] && nums[i]<nums[k])
                    return true;
                if(nums[i]<=nums[j] && j+1!=i)
                    ++j;
                else if(nums[i]>=nums[k] && k-1!=i)
                    --k;
                else
                    break;
            }
        }
          
    return false;
    }
};
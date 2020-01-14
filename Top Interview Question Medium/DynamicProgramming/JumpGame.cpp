class Solution {
public:
    bool canJump(vector <int>& nums) {
        const int N=nums.size();
        
        if(!N)
            return false;
        
        int maximumReach=0;
        for(int i=0; i<=maximumReach; ++i){
            if(i+nums[i]>maximumReach)
                maximumReach=i+nums[i];
            if(maximumReach>=N-1)
                return true;
        }
        return false;
    }
};
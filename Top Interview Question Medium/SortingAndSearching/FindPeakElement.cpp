class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int N = nums.size();
        
        if(N==1)
            return 0;
        else if(nums[0]>nums[1])
            return 0;
        else if (nums[N-2]<nums[N-1])       
            return N-1;
        
        for(int i=1; i<nums.size()-1; ++i)
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1])
                return i;
    
        return -1;
    }
};
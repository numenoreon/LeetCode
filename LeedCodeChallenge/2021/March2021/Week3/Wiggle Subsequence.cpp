class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        int up=1,down=1;
        
        for(int i=1;i<nums.size();i++){    
            if(nums[i]>nums[i-1])
                up=down+1;
            else if(nums[i]<nums[i-1])
                down=up+1;
        }
        
        return max(up,down);
    }
};
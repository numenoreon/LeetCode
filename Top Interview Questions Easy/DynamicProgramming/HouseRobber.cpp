class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        else if(n==1)
            return nums[0];
        else if(n==2)
            return max(nums[0],nums[1]);

        int first = nums[0];
        int second = max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int x = max(nums[i]+first , second);
            first = second;
            second = x;
        }

        return second;
    }
};
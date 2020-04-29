class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector <int> maxSum (nums.size());
        int maxNumber=0;
        maxSum[0]=nums[0], maxNumber=nums[0];
        
        for(int i=1; i<nums.size(); ++i){
            maxSum[i]=max(maxSum[i-1]+nums[i],nums[i]);
            maxNumber=max(maxNumber,maxSum[i]);
        }
        return maxNumber;
    }
};

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int temp=0, globalMax=nums[0], localMax=nums[0], localMin=nums[0];
	
        for(int i=1; i<nums.size(); ++i){
            temp=localMax;
            localMax=max(nums[i], max(localMax*nums[i], localMin*nums[i]));
            localMin=min(nums[i], min(temp*nums[i], localMin*nums[i]));
            globalMax=max(globalMax, max(localMax, localMin));
            
        }
    
        return globalMax;
    }
};
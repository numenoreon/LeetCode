class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int lastBad=-1, lastGood=-1 ,result=0;
        
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]>=left && nums[i]<=right){
                result += i - lastBad;
                lastGood = i;
            }
            else if(nums[i]>right){
                lastBad=i;
            }
            else if(lastGood > lastBad){
                result += lastGood-lastBad;
            }
        }
        
        return result;
    }
};
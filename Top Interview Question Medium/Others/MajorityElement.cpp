class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        const int N = nums.size();
        for(int i=0; i<=N/2; ++i){
                if(nums[i+N/2]==nums[i])
                    return nums[i];
        }
        return 0;
    }
};
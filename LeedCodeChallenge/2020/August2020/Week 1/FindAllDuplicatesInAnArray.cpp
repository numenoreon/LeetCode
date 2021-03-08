class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        for(int nr : nums){
            nr = abs(nr);
            if(nums[nr-1] > 0)
                nums[nr-1] *= -1;
            else
                result.push_back(nr);
        }
        return result;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mapsMe; 
        
        int sum = 0, counter = 0; 
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
			if(sum == k)
                ++counter;
            if(mapsMe[sum-k])
                counter += mapsMe[sum-k];
            ++mapsMe[sum];
        }
        return counter;
    }
};
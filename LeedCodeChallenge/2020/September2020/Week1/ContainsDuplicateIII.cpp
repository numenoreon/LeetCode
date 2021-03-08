class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int N = nums.size();
        
        set<int> mySet(nums.begin(), nums.end());
        if(t == 0 && N == mySet.size()) //to avoid Time Limit Exceeded
            return false; 
            
        for(int i = 0; i < N; ++i){
            for(int j = i+1; j<i+1+k && j<N; ++j){
                if(abs((long long)nums[i] - (long long)nums[j]) <= t)
                    return true;
            }
        }
        return false;
    }
};
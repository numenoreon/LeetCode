class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map <int, int> mapsMe;
        
        for(auto &i : nums){
            ++mapsMe[i];
        }
        
        for(int i=1; i<nums.size()+1; ++i)
		if(!mapsMe.count(i))
			return i;
        
        return nums.size()+1;
    }
};
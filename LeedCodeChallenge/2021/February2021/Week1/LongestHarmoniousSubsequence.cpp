class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map <int, int> mapsMe;
        int maxLength=0;
        for(auto &i: nums){
            ++mapsMe[i];
        }
        
        for(auto &i: nums){
            if(mapsMe[i-1]>0 || mapsMe[i+1]>0)
            	maxLength=max({maxLength, mapsMe[i-1]+mapsMe[i], mapsMe[i+1]+mapsMe[i]});
        }
        
        return maxLength;
    }
};
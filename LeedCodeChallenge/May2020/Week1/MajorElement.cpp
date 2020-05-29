class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int N=nums.size();
        unordered_map <int, int> mapsMe;
        for(int i=0; i<N; ++i)
            if(++mapsMe[nums[i]]>N/2)
                return nums[i];
        return 0;
    }
};
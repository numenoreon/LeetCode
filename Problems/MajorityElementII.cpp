class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map <int, int> mapsMe;
        vector <int> result;
        for(int i=0; i<nums.size(); ++i){
            ++mapsMe[nums[i]];
        }
        
        for(auto &i : mapsMe)
            if(i.second > nums.size()/3)
                result.push_back(i.first);
        
        return result;
    }
};
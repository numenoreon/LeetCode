class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map <int, int> mapping;
        
        for(int i=0; i<nums.size(); i++){
            mapping[nums[i]]++;
        }
        
        for(auto &i : mapping){
            if(i.second>1)
                return i.first;
        }
        return 0;
    }
};
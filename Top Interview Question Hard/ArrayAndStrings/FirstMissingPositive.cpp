class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map <int,int> mapping;
        
        for(auto &i:nums){
            mapping[i]++;
        }
        
        for(int i=1; i<INT_MAX ; i++){
            if(mapping[i]==0)
                return i;
        }
        
        return 0;
    }
};


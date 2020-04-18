class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map <int,int> mapsMe;
        
        if(nums.empty())
            return 0;
        
        for(int i=0; i<nums.size(); ++i){
            ++mapsMe[nums[i]];
        }

        int counterTemp=1, counterMax=1, last=mapsMe.begin()->first;
        
        for(auto &it : mapsMe){
            if(it.first==last+1){
                ++counterTemp;
                counterMax=max(counterMax,counterTemp);
                last=it.first;
            }
            else{
                last=it.first;
                counterTemp=1;
            }
        }
        return counterMax;
    }
};


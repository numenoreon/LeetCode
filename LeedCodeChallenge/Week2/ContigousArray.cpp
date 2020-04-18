class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map <int, int> mapsMe;
        int counter=0, maxLeap=0;

        for(int i=0; i<nums.size(); ++i){
            
            if(nums[i]==0)
                --counter;
            else
                ++counter;
            
            if(counter==0){
                maxLeap=i+1;
            }
            else if(mapsMe.count(counter)){
                maxLeap=max(maxLeap, i-mapsMe[counter]);
            }
            else{
                mapsMe[counter]=i;
            }
            
        }
        
        return maxLeap;
    }
};
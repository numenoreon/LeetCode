class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map <int, int> mapsMe;
        int counter=0, maxLeap=0;

        for(int i=0; i<nums.size(); ++i){
            
            nums[i]==0 ? ++counter : --counter;
            
            if(counter==0){
                maxLeap=max(maxLeap, i+1);
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
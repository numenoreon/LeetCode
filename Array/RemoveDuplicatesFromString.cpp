class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0, i=0, counter=0;
        
        for(int i=0; i<nums.size(); i++){
            if(i==j){
                ++counter;
                continue;
            }
            else if(nums[i]==nums[j]){
                continue;
            }
            else if(nums[i]!=nums[j]){
                ++counter;
                
                if(i==j+1) {
                    j=j+1;
                    continue;
                }
                
                swap(nums[i],nums[j+1]);
                j=j+1;
            }
        }
        std::cout << counter;
        return counter;
    }
};
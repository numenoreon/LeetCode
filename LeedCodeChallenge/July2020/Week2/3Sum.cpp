class Solution {
public:
    vector <vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};

        sort(nums.begin(), nums.end());
        vector <vector<int>> result;
        
        for(int i=0; i<nums.size()-2; ++i){
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            
            int left=i+1, right=nums.size()-1;
            
            if(nums[i]>0)
                break;
            while(left < right){
                if(nums[left]+nums[right]+nums[i]==0){
                    result.push_back({nums[left],nums[i],nums[right]});
                    do{
                        ++left;
                    }while(nums[left]==nums[left-1] && left<right);
                    
                    do{
                        --right;
                    }while(nums[right]==nums[right+1] && left<right);
                }
                else if(nums[left]+nums[right]+nums[i]>0){
                    --right;
                }
                else if(nums[left]+nums[right]+nums[i]<0){
                    ++left;
                }
            }
            
        }
        
        return result;
    }
};
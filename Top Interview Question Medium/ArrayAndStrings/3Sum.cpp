class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if(nums.size()<3)
            return {};
        
        for(int i=0; i<nums.size();++i){
            if(nums[i]>0)
                break;
            else if(i>0 && nums[i]==nums[i-1])
                continue;
            cout << "i " << i << endl;
            for(int j=i+1,k=nums.size()-1; j<k;){
                
                if( j>i+1 && nums[j]==nums[j-1] || nums[j]+nums[k]<-nums[i]){
                    ++j;
                }
                else if( k<nums.size()-1 && nums[k]==nums[k+1] || nums[j]+nums[k]>-nums[i]){
                    --k;
                }
                else{
                    result.push_back({nums[i],nums[j],nums[k]});
                    ++j;
                }  
            }         
        }
    return result;
    
    }
};
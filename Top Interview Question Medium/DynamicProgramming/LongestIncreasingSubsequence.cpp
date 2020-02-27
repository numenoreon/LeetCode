class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N=nums.size();
        if(N==0)
            return 0;        
        vector <int> dp (N,1);
        int longest=1;
        
        for(int i=0; i<N;++i){
            for(int j=0; j<=i; ++j){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        
        for(int i=0; i<N;++i)
            longest=max(longest,dp[i]);
            
    return longest;
    }
};
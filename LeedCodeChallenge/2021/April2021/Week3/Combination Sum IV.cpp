class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned long long> dp(target+1,0);
		dp[0]=1;

		for(int i=0;i<=target;i++) {
			for(auto j: nums) {
				if(i+j>target) continue;
				dp[i+j]+=dp[i];
			}
		}
		return dp[target];
	}
};
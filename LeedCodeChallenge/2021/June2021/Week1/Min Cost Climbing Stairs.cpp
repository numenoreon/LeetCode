class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		const int N = cost.size();
		vector<int>dp(N+1, 0);
        
		if (N == 0 || N == 1)
			return 0;
		if (N    == 2)
			return min(cost[0], cost[1]);
        
		dp[0] = 0;
		dp[1] = 0;
		dp[2] = min(cost[0], cost[1]);
        
		for (int i = 3; i <= N ; i++) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[N];
	}
};
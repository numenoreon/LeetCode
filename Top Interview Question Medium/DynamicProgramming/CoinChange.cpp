class Solution {
public:
    int coinChange(vector<int>& coins, long int amount) {
	vector<long int> dp(amount + 1, INT_MAX);
	dp[0] = 0;

	for (long int i = 0; i < amount; ++i) {
		for (int j = 0; j < coins.size(); ++j) {
			if (dp[i] != INT_MAX) {
				if (i + coins[j] <= amount) 
					dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
			}
		}
	}

		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}

};


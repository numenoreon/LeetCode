DP solution:

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

_______________________________________________________________________________________________________________________
Recursion, works too but far too slow:

class Solution {
    void findSmalest(int tabSize, vector <int> &cost, int currentSum, int pos){
        if(pos>=tabSize)
            minCost=min(minCost, currentSum);
        else if (pos == tabSize-1){
            minCost=min(minCost, currentSum+cost[pos]);
        }
        else{
            findSmalest(tabSize, cost, currentSum+cost[pos], pos+1);
            findSmalest(tabSize, cost, currentSum+cost[pos], pos+2);
        }
    }
    
    int minCost = INT_MAX;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        findSmalest(cost.size(), cost, 0, 0);
        findSmalest(cost.size(), cost, 0, 1);
        
        return minCost;
    }

};
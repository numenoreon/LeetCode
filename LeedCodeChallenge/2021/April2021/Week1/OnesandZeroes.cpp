class Solution {
public:
int findMaxForm(vector<string>& strs, int m, int n) {
    if(strs.empty()) return 0;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    vector<pair<int,int>> info;
    for(int i = 0; i < strs.size(); ++i){
        int zeros = 0, ones = 0;
        for(auto s : strs[i]){
            if(s == '0') {zeros++;}
            else{ones++;}
        }
        info.push_back({zeros, ones});
    }
    	for(int k = 0; k < info.size(); ++k){
            for(int i = m; i >= 0; --i){
            	for(int j = n; j >=0; --j){
                	if(info[k].first <= i && info[k].second <= j){
                    		dp[i][j] = max(dp[i][j], dp[i - info[k].first][j - info[k].second] + 1);
                	}
            	}
            }
    	}
    return dp[m][n];
    }
};
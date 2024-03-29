class Solution {
public:
    array <array <int, 201>, 201> dp;
    
    int dfs(vector<vector<int>> &matrix, int i, int j, int pre) {
        if (i < 0 || j < 0 || i == matrix.size() ||
            j == matrix[0].size() || pre >= matrix[i][j])
            return 0;
        if (dp[i][j])
            return dp[i][j];
        int p = matrix[i][j];
        matrix[i][j] = -1;
        int l = dfs(matrix, i, j - 1, p);
        int r = dfs(matrix, i, j + 1, p);
        int u = dfs(matrix, i - 1, j, p);
        int d = dfs(matrix, i + 1, j, p);
        matrix[i][j] = p;
        return dp[i][j] = max({l, r, u, d}) + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxVal = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                maxVal = max(maxVal, dfs(matrix, i, j, -1));
        return maxVal;
    }
};
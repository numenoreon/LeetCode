class Solution {
public:
    
int countSubstrings(string s) {
    const int N = s.length();
    int pos = 0;
    vector<vector <int>> dp(s.length(),vector(s.length(),0));

    for(int i=0; i<N; i++)
    {
        dp[i][i] = 1;
        ++pos;
    }
    
    for(int i = 1; i < N; ++i)
    {
        for(int j = 0; j  < i; ++j)
        {
            if(j  == i - 1 && s[j ] == s[i])
            {
                dp[j ][i] = 1;
                pos++;
            }
            else if(dp[j +1][i-1] == 1 && s[j ] == s[i])
            {
                dp[j ][i] = 1;
                pos++;
            }
        }
    }
    
    return pos;
    }
};
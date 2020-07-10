class Solution {
public:
    int nthUglyNumber(int N) {
        vector <int> dp {1};
        dp.reserve(N);
        int pos2=0,pos3=0,pos5=0;
        int i=1;
        while(i<N){
            dp.push_back(min(2*dp[pos2],min(3*dp[pos3],5*dp[pos5])));

            if(dp[i]==dp[pos2]*2)
                ++pos2;
            if(dp[i]==dp[pos3]*3)
                ++pos3;
            if(dp[i]==dp[pos5]*5)
                ++pos5;
            ++i;
        }
        return dp[N-1];
    }
};
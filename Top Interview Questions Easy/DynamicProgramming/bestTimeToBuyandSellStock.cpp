class Solution {
public:
    int maxProfit(vector<int>& prices) {

    const int N=prices.size();
    int localMax=prices[N-1], max=0;
    
    for (int i=N-2;i>=0;i--)
        {
            int val = localMax-prices[i];
            if (val>max)
                max=val;
            if (prices[i]>localMax)
                localMax=prices[i];
        }
    return max;
    }
};
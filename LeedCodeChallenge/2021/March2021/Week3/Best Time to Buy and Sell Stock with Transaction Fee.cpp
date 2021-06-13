class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        if(prices.size() < 2)
            return 0;
            
        for(int i = 1; i < prices.size(); i++)
            prices[i - 1] = prices[i] - prices[i - 1];

        int maxIn = prices[0] - fee, maxGlobal = max(0, prices[0] - fee), prevMax= 0;
        for(int i = 1; i < prices.size() - 1; i++)
        {
            int sellANDbuy = maxGlobal + prices[i] - fee;
            int sell = prevMax + maxIn + prices[i];
            
            if(sellANDbuy > sell)
            {
                prevMax = maxGlobal;
                maxIn = prices[i] - fee;
            }
            else
                maxIn += prices[i];    
            maxGlobal = max(maxGlobal, maxIn + prevMax);
        }
        return max(maxGlobal, maxIn);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> buy(prices.size(), -1);
        vector<int> sell(prices.size(), 0);
        int result = INT_MIN;
        
        for(int i=0; i<prices.size(); i++)
            buy[i] = -prices[i];
        
        for(int i=0; i<prices.size(); ++i){
            if(i >= 3)
                for(int j=1; j<i-1; j++)
                    buy[i] = max(buy[i], sell[j] - prices[i]);
            
            for(int j=0; j<i; ++j)
                sell[i] = max(sell[i], buy[j] + prices[i]);
            result = max(result, sell[i]);
        }
        
        return result < 0 ? 0 : result;
    }
};
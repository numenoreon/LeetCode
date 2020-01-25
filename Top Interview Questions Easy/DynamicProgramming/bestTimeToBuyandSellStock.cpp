class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        const int N=prices.size();
        int localMax=prices[N-1], max=0;
    
        for(int i=N-2; i>=0; --i){
            if(max<localMax-prices[i])
                max=localMax-prices[i];
            if(prices[i]>localMax)
                localMax=prices[i];
        }    
        
    return max;
    }
};
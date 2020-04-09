class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        const int N = prices.size();
        if(!N) return 0;
        
        int maxSum=0;
        vector <int> profit (N);
        
        for(int i=0; i<N-1; i++){
            profit[i]=prices[i+1]-prices[i];
        }
        
        for(int i=0; i<N; i++){
            if(profit[i]>0) maxSum+=profit[i];
        }
        
        return maxSum;
    }
};
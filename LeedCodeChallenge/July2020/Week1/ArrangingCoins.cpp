class Solution {
public:
    int arrangeCoins(int n) {
        
        int counter=0, step =1;
        
        while(step<=n){
            n-=step;
            ++counter, ++step;
        }
        
        return counter;
    }
};
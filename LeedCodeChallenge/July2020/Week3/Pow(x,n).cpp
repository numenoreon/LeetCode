class Solution {
public:
    
    double calculate(long double x, long int n){
        if(n==0)
            return 1;
        long double temp=myPow(x, n/2);
        
        if(n%2)
            return temp * temp * x;
        else
            return temp * temp;
    }
    
    double myPow(long double x, long int n) {
        //cout << n << endl;
        if(n<0){
            x=1/x;
            n*=-1;
        }
        
        return calculate(x, n);
    }
};
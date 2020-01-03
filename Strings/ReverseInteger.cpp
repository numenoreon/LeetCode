class Solution {
public:
    int reverse(int x) {
        long int result=0,temp=0;
        
        while(x)
        {
            temp=x%10;
            result=result*10+temp;
            x/=10;
        }
        
        return result > INT_MAX || result < INT_MIN ? 0 : result;
    }
};
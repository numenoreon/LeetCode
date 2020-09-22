class Solution {
public:
    bool isPowerOfFour(double num) {
        while(num>0){
            if(num==1)
                return true;
            num=num/4;
        }
        
        return false;
    }
};
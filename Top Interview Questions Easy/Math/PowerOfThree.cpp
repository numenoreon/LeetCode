class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        
        bitset<32> check (n);
        
        if(check.count()==1)
            return true;
        else
            return false;
    }
};
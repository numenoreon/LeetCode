class Solution {
public:
    bool isPerfectSquare(int num) {
        int result = sqrt(num);
        
        return result*result==num ? true : false;
    }
};
class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x^y;
        
        bitset<32> result (temp);
        
        return result.count();
    }
};
class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::bitset<32> temp (n);
        
        return temp.count();
    }
};
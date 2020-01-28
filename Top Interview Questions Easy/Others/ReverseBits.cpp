class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> temp(n);
        string tempString = temp.to_string();
        reverse(tempString.begin(), tempString.end());    
        temp = bitset<32>(tempString);
        uint32_t result = temp.to_ulong();
        return result;
    }
};
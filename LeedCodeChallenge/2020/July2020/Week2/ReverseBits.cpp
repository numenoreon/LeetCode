class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset <32> myBitset (n);
        for(int i=0; i<16; ++i){
            bool temp = myBitset[i];
            myBitset[i]=myBitset[31-i];
            myBitset[31-i]=temp;
        }
        
        return myBitset.to_ulong();
    }
};
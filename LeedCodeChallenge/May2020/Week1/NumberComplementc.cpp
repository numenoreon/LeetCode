class Solution {
public:
    int findComplement(int num) {
        
        int counter = 0;
        bitset <32> bicik (num);
        while(num){
            ++counter;
            num/=2;
        }
        
        for(int i=0; i<counter; ++i){
            bicik[i]==0 ? bicik[i]=1 : bicik[i]=0;
        }

        int result = bicik.to_ulong();
        return result;
    }
};
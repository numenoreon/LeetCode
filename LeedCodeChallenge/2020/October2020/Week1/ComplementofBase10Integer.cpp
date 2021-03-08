class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)
            return 1;
        vector <int> binary;
        binary.reserve(32);
        
        while(N){
            binary.push_back(N%2);
            N=N/2;
        }

        for(auto &i : binary){
            i==0? i=1 : i=0;
        }
        
        int result=0;
        for(int i=0; i<binary.size(); ++i){
            result+=binary[i]*pow(2,i);
        }
        
        return result;
    }
};
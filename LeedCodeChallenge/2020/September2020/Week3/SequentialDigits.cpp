class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
            
        vector <int> result;
        
        int lowSize = 0, bigSize=0;
        int temp=low;
        
        while(temp>0){
            temp/=10;
            ++lowSize;
        }
        
        temp=high;
        while(temp>0){
            temp/=10;
            ++bigSize;
        }
        
        for(int sz=lowSize; sz<=bigSize; ++sz){
            temp=0;
            int licz=1;
            int adder=0;
            
            for(int i=sz-1; i>=0;--i){
                temp+=licz*pow(10,i);
                adder+=1*pow(10,i);
                ++licz;
            }
            
            int value=temp;
            long int limit = pow(10, sz);
            bool go = false;
            
            while(value<low && value < limit){
                if(value%10==9 && value<low){
                    go=true;
                    break;   
                }
                value+=adder;
            }
            
            if(go)
                continue;
                
            while(value<high && value < limit){
                if(value%10==9){
                    result.push_back(value);
                    break;
                }
                result.push_back(value);
                value+=adder;
            }
        }
        
        return result;
    }
};
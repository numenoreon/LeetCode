class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int N = digits.size();
        if(!N)
            return {};
        
        ++digits[N-1];
        for(int i=N-1; i>0; --i){
            if(digits[i]==10){
                digits[i]=0;
                ++digits[i-1];
            }
        }
        
        if(digits[0]==10){
            digits[0]=0;
            digits.insert(digits.begin(),1);
        }
        
        return digits;
    }
};
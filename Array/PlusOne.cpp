class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        const int N = digits.size()-1;
        ++digits[N];
        
        for(int i=N; i>0; i--){
            if(digits[i]==10){
                ++digits[i-1];
                digits[i]=0;
            }
        }
        
        if(digits[0]==10){
            digits.insert(digits.begin(),1);
            digits[1]=0;
        }
        
        return digits;
    }
};
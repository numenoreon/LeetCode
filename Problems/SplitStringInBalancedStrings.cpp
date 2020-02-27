class Solution {
public:
    int balancedStringSplit(string s) {
        int counterL=0, counterR=0;
        int counterBalanced=0;
        
        for(int i=0; i<s.length(); ++i){
            
            s[i] == 'L' ? ++counterL : ++counterR;
            
            if(counterL > 0 && counterL==counterR){
                counterL=counterR=0;
                ++counterBalanced;
            }
        }
    	return counterBalanced;
    }
};
class Solution {
public:
    int maxPower(string s) {
        if(s.empty())
            return 0;
        int counter=1, result=1;
        
        for(int i=1; i<s.length();++i){
            if(s[i]==s[i-1])
                ++counter;
            else{
                result=max(result, counter);
                counter=1;
            }
        }
        
        result=max(result, counter);
        return result;
    }
};
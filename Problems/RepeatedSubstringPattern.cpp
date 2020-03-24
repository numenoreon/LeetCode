class Solution {
public:
    
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        string temp, subString="";

        for(int i=0; i <len/2+1; ++i){
            subString += s[i];
            if(subString==s)
                return false;
            temp = subString;
            
            while(temp.size()<s.size()){
                    temp+=subString;
            }

            if(temp==s)
                return true;
            } 
        return false;   
    }
};
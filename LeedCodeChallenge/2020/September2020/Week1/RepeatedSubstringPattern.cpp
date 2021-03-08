class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        string temp = "", comparision="";
        for(int i=0; i<s.length()/2; ++i){
            temp+=s[i];
            comparision=temp;
            if(s.length()%comparision.length()!=0)
                continue;
            while(comparision.length()<s.length()){
                comparision+=temp;
            }
            if(s==comparision)
                return true;
        }
        return false;
    }
};
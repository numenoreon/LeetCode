class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter=0;
        for(int i = s.length()-1; i>=0; --i){
            if(s[i]==' ' && counter==0)
                continue;
            else if(s[i]==' ')
                break;
            ++counter;
        }
        return counter;
    }
};
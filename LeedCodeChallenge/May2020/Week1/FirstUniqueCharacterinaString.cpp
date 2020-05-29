class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> charCount (26,0);
        for(int i=0; i<s.size(); i++){
            ++charCount[s[i]-'a'];
        }
        
        for(int i=0; i<s.length(); ++i){
            if(charCount[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};
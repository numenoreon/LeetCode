class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        vector <int> occurenceS (26,0);
        vector <int> occurenceT (26,0);
        
        for(int i=0; i<s.size(); ++i){
            ++occurenceS[s[i]-'a'];
            ++occurenceT[t[i]-'a'];
        }

        
        for(int i=0; i<26; ++i){
            if(occurenceS[i]!=occurenceT[i]){
                return false;
            }
        }
        
        return true;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector <int> hashMap (26,0);
        
        for(int i=0; i<s.size(); ++i){
            --hashMap[s[i]-'a'];
            ++hashMap[t[i]-'a'];
        }
        
        ++hashMap[t[t.size()-1]-'a'];
        
        for(int i=0; i<26; ++i){
            if(hashMap[i]==1)
                return i+'a';
        }
            
        return ' ';
    }
};

___________________________________________________________________________________________________________________

class Solution {
public:
    char findTheDifference(string s, string t) {
        char c;
        
        for(int i=0; i<s.size(); ++i){
            c^=s[i]^t[i];
        }
        
        c^=t[t.size()-1];
        
        return c;
    }
};
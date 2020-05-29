class Solution {
public:
    bool checkInclusion(string p, string s) {
        if(p.size() > s.size())
            return false;
        
        vector <int> pCount (26,0), sCount(26,0);
        
        for(int i=0; i<p.size(); ++i){
            ++pCount[p[i]-'a'];
            ++sCount[s[i]-'a'];
        }
        
        for(int i=p.size(); i<s.size(); i++){
            if(pCount==sCount)
                return true;
            --sCount[s[i-p.size()]-'a'];
            ++sCount[s[i]-'a'];
        }
        
        if(pCount==sCount)
                return true;
            
        return false;
    }
};
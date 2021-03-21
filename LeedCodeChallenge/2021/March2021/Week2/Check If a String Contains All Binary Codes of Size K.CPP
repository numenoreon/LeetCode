class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<pow(2,k))
            return false;
        unordered_set <string> bSet;
        
        for(int i=0; i < s.size() - k + 1; ++i){
            bSet.insert(s.substr(i, k));
        }
        
        return bSet.size()==pow(2,k) ? 1 : 0;
    }
};
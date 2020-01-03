class Solution {
public:
    bool isAnagram(string s, string t) {
        map < char, int> mapping1, mapping2;
        
        for(int i=0; i<s.size(); i++){
            ++mapping1[s[i]];
        }
        
        for(int i=0; i<t.size(); i++){
            ++mapping2[t[i]];
        }
        
        if (mapping1.size()!=mapping2.size())
            return false;
        
        for(auto &i: mapping1)
        {
            if(i.second != mapping2[i.first])
                return false;
        }
        
        return true;
    }
};
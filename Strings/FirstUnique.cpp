class Solution {
public:
    int firstUniqChar(string s) {
        map < char, int> mapping;
        for(int i=0; i<s.size(); i++){
            ++mapping[s[i]];
        }
        
        for(int i=0; i<s.size(); i++){
            if(mapping[s[i]]==1) return i;    
        }
        
        return -1;
    }
};
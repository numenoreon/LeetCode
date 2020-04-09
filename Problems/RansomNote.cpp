class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char, int> mapsMe;
        
        for(auto &i : magazine)
            ++mapsMe[i];
        
        for(auto &i : ransomNote)
            if(--mapsMe[i]<0)
                return false;
            
        return true;
    }
};
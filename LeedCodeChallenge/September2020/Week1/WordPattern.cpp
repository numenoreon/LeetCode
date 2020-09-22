class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        unordered_map <string, char> mapsString;
        unordered_map <char, string> mapsChar;
        
        stringstream ss(str);
        string temp="";
        
        for(int i=0; i<pattern.size(); ++i){
            getline(ss, temp, ' ');
            if(mapsString.find(temp)==mapsString.end() && mapsChar.find(pattern[i])==mapsChar.end()){
                mapsString[temp]=pattern[i];
                mapsChar[pattern[i]]=temp;
            }
            else if(mapsString[temp]=!pattern[i] || mapsChar[pattern[i]]!=temp){
                return false;
            }
        }
        
        if(ss.good())
            return false;
        return true;
    }
};
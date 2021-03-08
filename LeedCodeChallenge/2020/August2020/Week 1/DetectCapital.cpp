class Solution {
public:
    bool isAllSmall(string &word){
        for(auto &i: word)
            if(isupper(i))
                return false;
        return true;
    }
    
    bool isNextSmall(string &word){
        for(int i=1;i<word.size();++i){
            if(isupper(word[i]))
                return false;
        }
        return true;
    }
    
    bool isAllBig(string &word){
        for(auto &i: word)
            if(islower(i))
                return false;
        return true;
    }
    bool detectCapitalUse(string word) {
        if(word.size()<=1)
            return true;
        
        if(isupper(word[0])&&isupper(word[1]))
            return isAllBig(word);
        else if(isupper(word[0]))
            return isNextSmall(word);
        return isAllSmall(word);

    }
};
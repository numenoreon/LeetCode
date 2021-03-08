class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &w : words)
            reverse(w.begin(), w.end());
        sort(words.begin(), words.end());
        
        int counter=words.back().size()+1;
        
        for(int i=1; i<words.size();++i){
            if(words[i-1]!=words[i].substr(0,words[i-1].size()))
                counter+=words[i-1].size()+1; //+1 because #
        }
        
        return counter;
    }
};

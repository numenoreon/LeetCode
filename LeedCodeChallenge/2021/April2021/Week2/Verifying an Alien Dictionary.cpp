class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map <char, int> dict;
        
        for(int i=0; i<order.size(); ++i){
            dict[order[i]]=i;
        }
        
        vector <string> copy = words;
        
        sort(words.begin(), words.end(), [&](string &a, string &b){
            int length1 = a.size(), length2 = b.size();
            int length = min(length1, length2);
            
            for(int i=0; i<length; ++i){
                if(dict[a[i]]>dict[b[i]])
                    return false;
                else if(dict[a[i]]<dict[b[i]])
                    return true;
            }
            
            return a.size()<b.size();
        });
        
        return words==copy;
    }
};
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map <char, int> mapping;

        for(int i=0; i<order.length();++i){
            mapping[order[i]]=i;
        }
        
        auto comp = [&mapping](const string &a, const string &b){
            int i=0;
            while(i<a.length() && i<b.length() ){
                if(mapping[a[i]]<mapping[b[i]])
                    return true; 
                else if(mapping[a[i]]>mapping[b[i]])
                    return false;
                else
                    ++i;
            }
            return a.length() < b.length() ? true : false; 
        };
    
        
        for(int i=0; i<words.size()-1; ++i){
            if(!comp(words[i],words[i+1]))
                return false;
        }
        
        return true;
        
    }

};
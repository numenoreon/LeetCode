class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S.empty())
            return {};
        vector <int> occurence (26,0);
        vector <int> result;
        int firstIndex=-1, lastIndex=0;
        
        for(int i=0; i<S.length();++i){
            occurence[S[i]-'a']=i;
        }
        
        for(int i=0; i<S.length();++i){
            lastIndex=max(lastIndex, occurence[S[i]-'a']);
            if(lastIndex==i){
                result.push_back(lastIndex-firstIndex);
                firstIndex=lastIndex;
            }
        }

        return result;
    }
};
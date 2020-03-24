class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector <int> possibleChar (27,0);
        int counter = 0;
        
        for(int i=0; i<chars.length(); ++i){
            ++possibleChar[chars[i]-'a'];
        }
        
        for(int j=0; j<words.size(); ++j){
            vector <int> candidate (27,0);
            for(int i=0; i<words[j].length(); ++i){
                if((++candidate[words[j][i]-'a'] > possibleChar[words[j][i]-'a']) 
                   || possibleChar[words[j][i]-'a']==0){
                    break;
                }
                if(i==words[j].length()-1)
                    counter+=words[j].length();
            }
        }
        return counter;
    }
};
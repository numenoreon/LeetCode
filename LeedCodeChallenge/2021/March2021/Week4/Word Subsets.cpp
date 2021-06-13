class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector <int> maxCounter(26, 0);
        
        for(string &word : B){
            vector<int> tempCounter(26, 0);
            for(char &c : word)
                tempCounter[c - 'a']++;
            
            for(int i = 0; i < 26; i++)
                maxCounter[i] = max(maxCounter[i], tempCounter[i]);
        }
        
        vector <string> dictionary;
        
        for(string &s : A){
            vector<int> CounterA(26, 0);
            
            for(char &c : s)
                CounterA[c - 'a']++;
            
            bool check = true;
            
            for(int i = 0; i < 26; i++){
                if(CounterA[i] < maxCounter[i]) {
                    check = false;
                    break;
                }
            }
            
            if(check == true)
                dictionary.push_back(s);
        }
        
        return dictionary;
    }
};
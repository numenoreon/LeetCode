class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char,vector<string> > charToNums = {
            {'f',{"five","5"}},
            {'g',{"eight","8"}},
            {'h',{"three","3"}},
            {'i',{"nine","9"}},
            {'n',{"one","1"}},
            {'s',{"seven","7"}},
            {'u',{"four","4"}},
            {'w',{"two","2"}},
            {'x',{"six","6"}},
            {'z',{"zero","0"}}
        };
        
        vector<char> order = {'z','x','w','u','g','f','h','s','i','n'};
        unordered_map<char,int> letters;
        int total = 0;
        for(auto &c : s){
            letters[c]++;
            total++;
        }
        
        string result;
        
        while(total){
            for(int i = 0; i < order.size();++i){
                if(letters.find(order[i]) != letters.end()){
                    auto w = charToNums[order[i]][0];
                    for(auto &c : w){
                        letters[c]--;
                        if(letters[c] == 0){
                            letters.erase(c);
                        }
                        total--;
                    }
                    
                    result += charToNums[order[i]][1];
                    break;
                }
            }
        }
        
        sort(begin(result),end(result),[](const char c, const char t)->bool{
            return (c - '0') < (t - '0');
        });
        
        return result;
        
    }
};
class Solution {
public:
    
    void helper(int pos, string &digits, string temp, vector <string> &result){
        if(pos>=digits.size()){
            result.push_back(temp);
            return;
        }
            
        string data = mapsMe[digits[pos]];
        
        for(int i=0; i<data.size(); ++i){
            helper(pos+1, digits, temp+data[i], result);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        
        vector <string> result {};
        helper(0, digits, "", result);
        
        
        return result;
    }
    
private:
    map <char, string> mapsMe {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
};
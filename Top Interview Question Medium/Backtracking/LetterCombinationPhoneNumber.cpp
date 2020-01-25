class Solution {
public:
    
    void dfs(string digits, string previous, const vector <string> &mapping, vector <string> &result, int index=0){
        if(index==digits.length()){
            result.push_back(previous);
        }
        else{
            string temp=mapping[digits[index]-'0'];
            for(int i=0; i<temp.length(); i++){
                dfs(digits,previous+temp[i],mapping,result,index+1);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        const vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if(digits.size() == 0)
            return {};
        dfs(digits, "", mapping, result, 0);
        return result;
    }
};
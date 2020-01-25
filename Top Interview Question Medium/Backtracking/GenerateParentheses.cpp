class Solution {
public:
    
    void generateString(int openBracket ,int closeBracket , int n ,string tempString , vector<string>& result){
        if(tempString.length() == 2*n){
            result.push_back(tempString);
        }
        else{
            if(openBracket<n && openBracket>=closeBracket){
                generateString(openBracket , closeBracket+1 , n , tempString + ')', result);
                generateString(openBracket+1 , closeBracket , n , tempString + '(', result);
            }
            else if(closeBracket<n){
                generateString(openBracket,closeBracket+1,n,tempString+')',result);
            }
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateString(0, 0, n, "", result);
        return result;
    }
};
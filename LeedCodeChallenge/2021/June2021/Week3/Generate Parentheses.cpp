class Solution {
public:
    void helper(string temp, int pos, int &n, int oCounter, int cCounter, vector <string> &result){
        if(pos==2*n){
            result.push_back(temp);
            return;
        }
        
        if(oCounter<n)
            helper(temp+'(', pos+1, n, oCounter+1, cCounter, result);
        if(cCounter<n && cCounter<oCounter)
            helper(temp+')', pos+1, n, oCounter, cCounter+1, result);
    }
    
    vector<string> generateParenthesis(int n) {
        if(n==0)
            return {};
        vector <string> result;
        
        helper("", 0, n, 0, 0, result);
        
        return result;
    }
};

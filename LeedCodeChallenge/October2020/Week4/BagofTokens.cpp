class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if(tokens.empty())
            return 0;
        
        sort(tokens.begin(), tokens.end());
        
        int i=0, counter=0, maksScore=0, bestToken=tokens.size()-1;
        if(P < tokens[i])
            return 0;
        
        while(i<=bestToken){
            
            while(P<tokens[i] && counter>0){
                    P+=tokens[bestToken];
                    --bestToken;
                    --counter;
            }
            
            if(P<tokens[i])
                break;
            
            P-=tokens[i];
            ++counter;
            ++i;
            maksScore=max(maksScore, counter);
            
        }
        
        
        return maksScore;
    }
};
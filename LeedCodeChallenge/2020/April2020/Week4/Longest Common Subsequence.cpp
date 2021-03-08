class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int len1 = text1.length(), len2 = text2.length();
        vector< vector <int> > matrix (len1+1, vector<int>(len2+1, 0));
        
        for(int i=0; i<len1; ++i){
            for(int j=0; j<len2; ++j){
                if(text1[i]==text2[j]){
                    matrix[i+1][j+1]=matrix[i][j]+1;
                }
                else{
                    matrix[i+1][j+1]=max(matrix[i+1][j],matrix[i][j+1]);
                }
            }
        }
        return matrix[len1][len2];
    }
};
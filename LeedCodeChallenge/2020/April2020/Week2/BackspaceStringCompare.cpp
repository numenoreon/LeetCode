class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string A="", B="";
        
        for(int i=0; i<S.length(); ++i){
            if(S[i]=='#' && A.length())
               A.pop_back();
            else if(S[i]!='#')
               A+=S[i]; 
        }
               
        for(int i=0; i<T.length(); ++i){
            if(T[i]=='#' && B.length())
               B.pop_back();
            else if(T[i]!='#')
               B+=T[i]; 
        }
        cout << A << " " << B << endl;
        return B==A;
    }
};
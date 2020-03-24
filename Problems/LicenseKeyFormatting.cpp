class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        
        string result;
        int counter =0;
        
        for(int i=0; i<S.length(); ++i){
            if(int(S[i])>=97 && int(S[i])<=122){
                S[i]=S[i]-' ';
                ++counter;
            }
            else if(int(S[i])>=65 && int(S[i])<=90 || (int(S[i])>=48 && int(S[i])<=57))
                ++counter;
        }
        
        bool prawda= false;
        int rest = counter%K, put = 0, i=0;
        
        for(i; put<rest; ++i){
            if(int(S[i])>=65 && int(S[i])<=90 || (int(S[i])>=48 && int(S[i])<=57)){
                result+=S[i];
                ++put;
            }
        }
        
        if(rest!=0){
            result+='-';
            put=0;
        }
        
        for(i; rest+put<counter; ++i){
            if(int(S[i])>=65 && int(S[i])<=90 || (int(S[i])>=48 && int(S[i])<=57)){
                result+=S[i];    
                ++put;
                prawda=true;
            }
            if(put%K==0 && prawda){
                result+='-';
                prawda=false;
            }
        }
        
        if(result.back()=='-')
            result.pop_back();
               
        return result;    
        }      
};
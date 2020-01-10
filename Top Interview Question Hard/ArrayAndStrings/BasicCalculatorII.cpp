class Solution {
public:
    int calculate(string s) {
        vector <char> sign;
        vector <long int> number;
        long int temp=0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*'){
                sign.push_back(s[i]);
                s[i]=' ';
            }
        }
        
        stringstream ss(s);
        while(ss >> temp){
            number.push_back(temp);
        }
        
        for(int i=0; i<sign.size();i++){
            if(sign[i]=='*'){
                number[i]*=number[i+1];
                number.erase(number.begin()+i+1);
                sign.erase(sign.begin()+i);
                --i;
            }
            else if( sign[i]=='/'){
                number[i]/=number[i+1];
                number.erase(number.begin()+i+1);
                sign.erase(sign.begin()+i);
                --i;
            }
        }
        
        long int result=number[0];

        for(int i=0; i<sign.size();i++){
            if(sign[i]=='+'){
                result+=number[i+1];
            }
            else if(sign[i]=='-'){
                result-=number[i+1];
            }
        }
        return result;
    }
};
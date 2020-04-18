class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int number=0;
       
        for(int i=0; i<shift.size(); ++i){
            if(shift[i][0]==0)
                number-=shift[i][1];
            else
                number+=shift[i][1];
        }
       
        int sft = abs(number)%s.length();
        string result;
       
        if(sft==0)
            return s;
        else if(number>0){
            for(int i=s.length()-sft; i<s.length(); ++i)
                result+=s[i];
            for(int i=0; i<s.length()-sft; ++i)
                result+=s[i];
        }
        else if(number<0){
            for(int i=sft; i<s.length(); ++i)
                result+=s[i];
            for(int i=0; i<sft; ++i)
                result+=s[i];
        }
       
        return result;
    }
};
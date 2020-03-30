class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        
        if(A.size()!=4)
            return {};
        
        string result="";
        sort(A.begin(),A.end());
        
        int maxTime=0,hours=0,minutes=0;
        do{
            if(A[0]>=3)
                continue;
            hours=A[0]*10+A[1];
            minutes=A[2]*10+A[3];
            if(hours>23)
                continue;
            if(minutes>=60)
                continue;
            if(hours*100+minutes>=maxTime){
                result="";
                maxTime=hours*100+minutes;
                for(int i=0;i<4;++i){ 
                    if(i==2)
                        result+=":";
                    result+=to_string(A[i]);
                }
            }
        }while(next_permutation(A.begin(),A.end()));
        
        return result;
    }
};
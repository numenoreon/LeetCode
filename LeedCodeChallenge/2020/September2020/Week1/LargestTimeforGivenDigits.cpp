class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        if(A.empty())
            return "";
        sort(A.begin(), A.end());
        
        int A0=-1, A1=-1, A2=-1, A3=-1;
        int maxDuration=-1;
        
        do {
            if(A[0]*10+A[1]>23 || A[2]*10+A[3]>59)
                continue;
            if((A[0]*10+A[1])*60+A[2]*10+A[3]>maxDuration){
                A0=A[0];
                A1=A[1];
                A2=A[2];
                A3=A[3];
                maxDuration=A[0]*10+A[1]*60+A[2]*10+A[3];
            }
                
        } while (next_permutation(A.begin(),A.end()));

        if(maxDuration==-1)
            return "";
        string result=to_string(A0)+to_string(A1)+":"+to_string(A2)+to_string(A3);
        
        return result;
    }
};
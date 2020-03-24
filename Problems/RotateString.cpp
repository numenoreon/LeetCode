class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size())
            return false;
        if(A==B)
            return true;
        vector <int> possiblePosition;
        for(int i=0; i<A.size(); ++i){
            if(A[0]==B[i])
                possiblePosition.push_back(i);
        }
        
        if(possiblePosition.empty())
            return false;
        
        for(int i=0; i<possiblePosition.size(); ++i){
            bool proper = true;
            int startA=0, startB=possiblePosition[i];

            for(startA; startA<A.length(); ++startA){
                if(A[startA]==B[startB]){
                    ++startB;
                    if(startB==B.length()){
                        startB=0;
                    }
                }
                else{
                    proper=false;
                    break;
                }
            }
            
            if(proper)
                return true;
        }
        
    return false;
    }
};
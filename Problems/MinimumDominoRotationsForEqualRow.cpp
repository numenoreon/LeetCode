class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int min1=min(helpSwaper(A[0],B,A), helpSwaper(A[0],A,B));
        int min2=min(helpSwaper(B[0],B,A), helpSwaper(B[0],A,B));   
        
        return min(min1, min2)==INT_MAX ? -1 : min(min1, min2);
    }
    
    int helpSwaper(int target, vector<int>& A, vector<int>& B){
        int minSwap=0;
        for(int i=0; i<A.size(); ++i){
            if(target==A[i]){
                continue;
            }
            else if(target==B[i]){
                ++minSwap;
            }
            else{
                return INT_MAX;
            }
        }
        return minSwap;
    }
};
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int N=A.size();
        const int M=B.size();
        
        vector <vector <int> > result {};
        
        if(A.empty() && B.empty())
            return result;
        
        int i=0, j=0;
        while(i!=N && j!=M){
            int left = max(A[i][0],B[j][0]);
            int right = min(A[i][1],B[j][1]);
        
            if(left<=right){
                result.push_back({left,right});
            }
            
            if(A[i][1]<=right)
                ++i;
            if(B[j][1]<=right)
                ++j;
        }
        
        return result;
    }
};
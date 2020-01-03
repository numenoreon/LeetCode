class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        const int N=a.size();

        for(int i=0;i<N;i++){
            for(int j=0;j<N-i;j++){
                swap(a[i][j],a[N-j-1][N-i-1]);
                }
        }
    
        for(int i=0;i<N/2;i++){
            for(int j=0;j<N;j++){
                swap(a[i][j],a[N-i-1][j]);
                }
            }
        
    }
    
};
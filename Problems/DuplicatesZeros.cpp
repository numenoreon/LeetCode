class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int j=0;
        const int N = arr.size();
        for(int i=0; i<N; ++i){
            if(arr[i]==0){
                arr.insert(arr.begin()+i,0);
                ++i;
            }
        }
        
        while(arr.size()>N)
            arr.pop_back();
    }
};
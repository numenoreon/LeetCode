class Solution {
public:
    string getPermutation(int n, int k) {
        
        string result = "";
        for(int i=0; i<n; ++i){
            result += to_string(i+1);
        }
        
        while(--k){
            next_permutation(result.begin(),result.begin()+n);
        }
        
        return result;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();
        vector <int> occurence (N+1, 0);
        
        for(int i=0; i<N; ++i){
            ++occurence[nums[i]];
        }
        
        for(int i=0; i<N; ++i){
            if(occurence[i]==0)
                return i;
        }
        
        return N;
    }
};
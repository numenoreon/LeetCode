class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.empty())
            return -1;
        
        const int N=nums.size();
        vector <int> sumLeft(N, nums[0]);
        vector <int> sumRight(N, nums[N-1]);
        
        for(int i=1; i<N; i++){
            sumLeft[i]=nums[i]+sumLeft[i-1];
        }
        
        for(int i=N-2; i>=0; --i){
            sumRight[i]=nums[i]+sumRight[i+1];
        }
        
        for(int i=0; i<N; ++i)
            if(sumLeft[i]==sumRight[i])
                return i;
        
        return -1;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) { // complexity O(3*n)
        vector <int> left(nums.size(),1);
        vector <int> right(nums.size(),1);
        vector <int> result(nums.size(),1);
        
        const int N = nums.size();

        for(int i=0;i<N-1;++i){
            left[i+1]=left[i]*nums[i];
        }
        
        for(int i=N-1;i>0;--i){
            right[i-1]=right[i]*nums[i];
        }
        
        for(int i=0; i<N; ++i){
            result[i]=right[i]*left[i];
        }
        
        return result;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        const int N = nums.size();
        
        int result=-1;
        for(int i = 0; i < N; i++){
            nums[nums[i]%N]+=N;
        }
        
        for(int i=0;i<N;i++){
            if(nums[i]/N > 1){
                result=i;
            }
            nums[i]=nums[i]%N; // restoring previous values;
        }

        return result;
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int N = nums.size();
        if (k>=N) k=k%N;
        int temp=0;
        vector <int> tempVec(N);
        for(int i=0; i<N; i++){
            tempVec[(i+k)%N]=nums[i];
        }
        
        for(int i=0; i<N; i++){
            nums[i]=tempVec[i];
        }
    }
};
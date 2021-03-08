class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int N = nums.size();
        vector <int> tempVec = nums;
        
        for(int i=0; i<N;++i){
            nums[(i+k)%N]=tempVec[i];
        }
    }
};
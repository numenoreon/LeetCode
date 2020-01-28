class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> original = nums;
        vector<vector<int> > result;
        do{
            result.push_back(nums);
            next_permutation(nums.begin(),nums.end());
        }while(original!=nums);
        
        return result;
    }
};
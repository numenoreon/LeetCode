class Solution {
public:
    TreeNode* makeTree(vector<int>& nums, int start, int stop) {
        if(start > stop ) return nullptr;
        int piwot = (start + stop) / 2;
        TreeNode* t = new TreeNode(nums[piwot]);
        t->left = makeTree(nums, start, piwot-1);
        t->right = makeTree(nums, piwot+1, stop);
        return t;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return makeTree(nums, 0, nums.size()-1);
    }
};
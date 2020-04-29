class Solution {
public:
    
    TreeNode* makeTree(vector<int>& nums, int start, int stop){
        if(start>stop)
            return nullptr;
        int middle = (start+stop)/2;
        TreeNode* root = new TreeNode(nums[middle]);
        
        root->left = makeTree(nums, start, middle-1);
        root->right = makeTree(nums, middle+1, stop);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = makeTree(nums, 0, nums.size()-1);
        return root;
    }
};
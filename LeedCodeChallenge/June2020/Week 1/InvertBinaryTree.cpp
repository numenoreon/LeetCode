class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;
        TreeNode *tempNode = root->left;
        root->left=root->right;
        root->right=tempNode;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
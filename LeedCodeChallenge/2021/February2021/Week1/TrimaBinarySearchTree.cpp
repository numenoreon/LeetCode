class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(!root)
            return nullptr;
        
        if(root->left)
            root->left = trimBST(root->left, low, high);
        if(root->right)
            root->right = trimBST(root->right, low, high);
        
        if(root->val < low || root->val > high)
        {
            if(root->left)
                root = root->left;
            else if(root->right)
                root = root->right;
            else if(!root->left && !root->right)
                root = nullptr;
        }
        
        return root;
    }
};
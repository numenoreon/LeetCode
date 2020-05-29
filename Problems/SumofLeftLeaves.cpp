class Solution {
public:
    void inOrder(TreeNode* root, int &counter, bool isLeft){
        if(!root)
            return ;
        if(isLeft && !root->left && !root->right){
            counter+=root->val;
            return ;
        }
        inOrder(root->left, counter, true);
        inOrder(root->right, counter, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int counter=0;
        inOrder(root, counter, false);
        return counter;
    }
};
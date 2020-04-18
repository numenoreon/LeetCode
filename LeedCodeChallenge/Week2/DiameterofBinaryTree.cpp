class Solution {
public:
    
    void findDepth(TreeNode* root, int depth, int &local){
        if(!root)
            return ;
        local=max(local, depth);
        if(root->left)
            findDepth(root->left, depth+1, local);
        if(root->right)
            findDepth(root->right, depth+1, local);
    }
    
    void inOrder(TreeNode* root){
        if(!root)
            return;
        
        int one=0,two=0;
        findDepth(root->left,1,one);
        findDepth(root->right,1,two);
        
        maxLength=max(maxLength, one+two);
        if(root->left)
            inOrder(root->left);
        if(root->right)
            inOrder(root->right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        inOrder(root);
        return maxLength;
    }
private:
    int maxLength=0;
};
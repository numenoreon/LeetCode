class Solution {
public:
    void inOrder1(TreeNode *root, int locD, int &depth){
        if(!root){
            depth = max(depth, locD-1);
            return ;
        }
        
        inOrder1(root->left, locD+1, depth);
        inOrder1(root->right, locD+1, depth);
    }
    
    void inOrder2(TreeNode *root, int locD, int &depth, int &sum){
        if(!root){
            return ;
        }
        if(locD == depth){
            sum+=root->val;
            return;
        }
        inOrder2(root->left, locD+1, depth, sum);
        inOrder2(root->right, locD+1, depth, sum);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        int depth = 0;
        
        inOrder1(root, 0, depth);
        inOrder2(root, 0, depth, sum);
        return sum;
    }
    
};
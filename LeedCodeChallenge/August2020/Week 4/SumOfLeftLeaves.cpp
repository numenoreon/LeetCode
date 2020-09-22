void inOrder(TreeNode *root, bool isLeft, int &sum){
    if(!root)
        return ;
    if(isLeft && !(root->left) && !(root->right)){
        sum+=root->val;
        return ;
    }
    
    inOrder(root->left, true, sum);
    inOrder(root->right, false, sum);
}

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum =0;
        if(!root)
            return 0;
        inOrder(root, false, sum);
        
        return sum;
        
    }
};
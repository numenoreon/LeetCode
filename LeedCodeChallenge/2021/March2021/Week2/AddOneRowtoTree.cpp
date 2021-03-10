class Solution {
public:
    void inOrder(TreeNode *root, int &val, int curD, int d){
        if(!root)
            return;
        if(curD == d-1){
            TreeNode *tempRight=root->right, *tempLeft = root->left;
            
            root->left = new TreeNode (val);
            root->left->left=tempLeft;
            
            root->right = new TreeNode(val);
            root->right->right=tempRight;
        }
        
        inOrder(root->left, val, curD+1, d);
        inOrder(root->right, val, curD+1, d);
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left=root;
            return newRoot;
        }
        inOrder(root, v, 1, d);
            
        return root;
    }
};
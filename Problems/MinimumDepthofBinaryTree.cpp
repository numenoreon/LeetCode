class Solution {
public:
    void minDep(TreeNode* root, int depth){
        if(!root->left && !root->right){
            minD=min(minD,depth);
        }
        if(root->left){
            minDep(root->left,depth+1);
        }
        if(root->right){
            minDep(root->right,depth+1);
        }
    }
    
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        minDep(root, 1);
        return minD;
    }
private:
    int minD=INT_MAX;
};
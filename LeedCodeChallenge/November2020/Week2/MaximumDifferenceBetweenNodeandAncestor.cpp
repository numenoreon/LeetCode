class Solution {
public:
    
    void inOrder(TreeNode *root, int &diffrence, int minValue, int maxValue){
        if(!root){
            diffrence = max(diffrence, maxValue-minValue);
            return;
        }
        diffrence = max(diffrence, maxValue-minValue);
        minValue=min(minValue, root->val);
        maxValue=max(maxValue, root->val);
        inOrder(root->left, diffrence, minValue, maxValue);
        inOrder(root->right, diffrence, minValue, maxValue);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        int diffrence = 0;
        
        inOrder(root, diffrence, root->val, root->val);
        
        return diffrence;
    }
};
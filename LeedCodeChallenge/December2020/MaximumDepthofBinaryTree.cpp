class Solution {
public:
    void count(TreeNode *root, int counter, int &maxD){
        if(!root){
            maxD=max(maxD, counter);
            return;
        }    
        count(root->left, counter+1, maxD);
        count(root->right, counter+1, maxD);
    }
    
    int maxDepth(TreeNode* root) {
        int maxD=0;
        count(root, 0, maxD); 
        return maxD;
    }
};
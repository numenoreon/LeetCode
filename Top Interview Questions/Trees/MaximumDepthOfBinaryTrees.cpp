/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int result=0;
    
    void count(TreeNode* node, int depth=1){
        if(!node) return;
        count(node->left,depth+1);
        count(node->right,depth+1);
        result=max(result,depth);
    }
    
    int maxDepth(TreeNode* root) {
        count(root);
        return result;
    }
};
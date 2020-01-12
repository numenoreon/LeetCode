class Solution {
public:
    void inOrder(TreeNode* root, vector<int> &temp){
        if(root){
        inOrder(root->left,temp);
        temp.push_back(root->val);
        inOrder(root->right, temp);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> result;
        inOrder(root, result);
        return result;
    }
};
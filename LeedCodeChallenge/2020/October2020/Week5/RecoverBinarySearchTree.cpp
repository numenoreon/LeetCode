class Solution {
public:
    void inOrder(TreeNode * root){
        if(!root)
            return;
        inOrder(root->left);
        if(prev && prev->val > root->val){
            myVec.push_back({prev,root});
        }
        prev=root;
        inOrder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inOrder(root);
        if(myVec.size()==1)
            swap(myVec[0].first->val, myVec[0].second->val);
        else if(myVec.size()==2)
            swap(myVec[0].first->val, myVec[1].second->val);
    }
private:
    vector <pair <TreeNode*, TreeNode*>> myVec;
    TreeNode *prev=nullptr;
};
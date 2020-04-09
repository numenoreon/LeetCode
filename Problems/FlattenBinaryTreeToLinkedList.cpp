class Solution {
public:
    
    void preOrder(TreeNode* root, vector <TreeNode*> &tempVec){
        if(!root)
            return ;
        
        tempVec.push_back(root);
        preOrder(root->left, tempVec);
        preOrder(root->right, tempVec);
    }
    
    void flatten(TreeNode* root) {
        if(!root)
            return ;
        
        vector <TreeNode*> tempVec;
        preOrder(root, tempVec);
        
        for(int i=0; i<tempVec.size()-1; ++i){
            tempVec[i]->right=tempVec[i+1];
            tempVec[i]->left=nullptr;
        }
        //    cout << tempVec[i]->val << " ";
        
        
        tempVec[tempVec.size()-1]->right=nullptr;
    }
};
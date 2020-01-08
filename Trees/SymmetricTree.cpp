class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue <TreeNode*> isSimetric;
        
        isSimetric.push(root);
        isSimetric.push(root);
        
        while(!isSimetric.empty()){
            TreeNode* leftNode = isSimetric.front();
            isSimetric.pop();
            TreeNode* rightNode = isSimetric.front();
            isSimetric.pop();
              
            if(leftNode == nullptr && rightNode == nullptr){
                continue;
            }
            else if(leftNode == nullptr || rightNode == nullptr){
                return false;
            }
            else if(leftNode->val != rightNode->val){
                return false;
            }
            
            isSimetric.push(leftNode->left);
            isSimetric.push(rightNode->right);
            isSimetric.push(leftNode->right);
            isSimetric.push(rightNode->left);
            
        }
        return true;
    }
};
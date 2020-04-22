class Solution {
public:
    TreeNode* helper(vector <int> &preorder, int start, int stop){
        if(start>stop)
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[start]);
    
        for(int i=start+1; i<=stop; ++i){
            if(preorder[i]>preorder[start]){
                root->left=helper(preorder, start+1,i-1);
                root->right=helper(preorder, i, stop);
                return root;
            }
        }
        root->left=helper(preorder,start+1, stop);
        return root;
    
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = nullptr;
        
        root = helper(preorder, 0, preorder.size()-1);
        
        return root;
    }
};
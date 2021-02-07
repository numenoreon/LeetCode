class Solution {
public:
    
    TreeNode* dfs(const vector<int>& inorder, int il, int ir, const vector<int>& postorder, int pl, int pr){
	    if (pl > pr) 
		    return nullptr;

        int n = 0;
	    for (n=0; n + il <= ir; ++ n)
		    if (inorder[n + il] == postorder[pr])
			    break;
		
	
	    TreeNode* root = new TreeNode(postorder[pr]);
	    root->left = dfs(inorder, il, il + n - 1, postorder, pl, pl + n - 1);
	    root->right = dfs(inorder, il + n + 1, ir, postorder, pl + n, pr - 1);
        
	    return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	    return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }


};
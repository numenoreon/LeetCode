class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int preorderLeft, int preorderRight, 
                        vector<int>& inorder, int inorderLeft, int inorderRight)
    {
        if(inorderLeft > inorderRight)
		    return nullptr;
        int temp = preorder[preorderLeft];
        TreeNode *Node = new TreeNode(temp);
        int i = inorderLeft;
        
        while(i<=inorderRight){
            if(inorder[i]==temp)
                break;
            ++i;
        }
        Node->left= buildTree(preorder, preorderLeft+1, preorderLeft+i-inorderLeft, inorder, inorderLeft, i-1);
        Node->right = buildTree(preorder, preorderLeft+i-inorderLeft+1, preorderRight, inorder, i+1, inorderRight);   
        return Node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
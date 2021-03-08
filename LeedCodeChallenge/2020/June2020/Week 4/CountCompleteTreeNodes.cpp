class Solution {
public
    void inOrder(TreeNode root){
        if(!root)
            return ;
        ++nodeCount;
        inOrder(root-left);
        inOrder(root-right);
    }
    
    int countNodes(TreeNode root) {
        inOrder(root);
        return nodeCount;
    }
private
    int nodeCount=0;
};
class Solution {
public
    int inOrder(TreeNode root, int &counter){
        if(!root)
            return 0;
        
        int temp1 = inOrder(root-left, counter);
        int temp2 = inOrder(root-right, counter);
        counter+=abs(temp1-temp2);
        return root->val+temp1+temp2;
    }
    
    int findTilt(TreeNode root) {
        if(!root)
            return 0;
        int counter=0;
        inOrder(root, counter);
        return counter;
    }
};
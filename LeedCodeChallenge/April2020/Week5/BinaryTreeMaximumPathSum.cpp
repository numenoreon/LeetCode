class Solution {
public:
    
    int sumOfNode(TreeNode*root){
        if(!root)
            return 0;

        int leftSum = sumOfNode(root->left)+root->val;
        int rightSum = sumOfNode(root->right)+root->val;
        int temp = max(leftSum, rightSum);
        maxSum = max(maxSum, temp);
        maxSum = max(maxSum, max(root->val,leftSum+rightSum-root->val));
        
        return max(root->val, temp);
    }
    
    int maxPathSum(TreeNode* root) {
        sumOfNode(root);
        return maxSum;
    }
    
private:
    int maxSum=INT_MIN;     
};
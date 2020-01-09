class Solution {
public:
    // long int casting because testing value, can't modify TreeNode
    
    int isBST(TreeNode* node, long int min, long int max)  
    {  
    if (node==NULL)  
        return 1;  
              
    if ((long int)node->val < min || (long int)node->val > max)  
        return 0; 
        
    return
        isBST(node->left, min, (long int)node->val-1) &&   
        isBST(node->right, (long int)node->val+1, max);
}      
  
    bool isValidBST(TreeNode* node)  
    {  
        return(isBST(node, INT_MIN, INT_MAX));  
    }  

};
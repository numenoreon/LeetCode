class Solution {
public:
    
    void count(TreeNode *Node, vector <TreeNode*> & temp){
        if(!Node)
            return ;
        count(Node->left,temp);
        temp.push_back(Node);
        count(Node->right,temp);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector <TreeNode*> result;
        
        count (root, result);
        return result[k-1]->val;
    }
};
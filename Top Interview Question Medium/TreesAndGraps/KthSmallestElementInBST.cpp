class Solution {
public:
    
    void count(TreeNode *Node, vector <TreeNode*> & temp){
        temp.push_back(Node);
        if(Node->left!=nullptr)
            count(Node->left,temp);
        if(Node->right!=nullptr)
            count(Node->right,temp);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector <TreeNode*> result;
        
        count (root, result);
        std::sort(result.begin(),result.end(),[](TreeNode* one, TreeNode *two){return one->val>two->val;});
                
        return result[result.size()-k]->val;
    }
};
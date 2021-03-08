class Solution {
public:
    void inOrderGet(TreeNode *root, vector <int> &value){
        if(!root)
            return;
        inOrderGet(root->left, value);
        value.push_back(root->val);
        inOrderGet(root->right, value);
    }
    
    void inOrderSet(TreeNode *root, vector <int> &value, int &pos){
        if(!root)
            return;
        inOrderSet(root->left, value, pos);
        root->val=value[pos++];
        inOrderSet(root->right, value, pos);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        vector <int> value;
        inOrderGet(root, value);


        for(int i=value.size()-2;i>=0; --i){
            value[i]+=value[i+1];
        }

        int pos=0;
        inOrderSet(root, value, pos);
        
        return root;
    }
};

________________________________________________________________________________________________________________________________________

class Solution {
public:
    void traverse(TreeNode* node, int &sum){
        if(!node)
            return;
        if(node->right)
            traverse(node->right, sum);
        
        sum+=node->val;
        node->val=sum;
        
        if(node->left, sum)
            traverse(node->left, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;

        int sum=0;
        traverse(root, sum);
        return root;
    }
};

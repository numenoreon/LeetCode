class Solution {
public:
    
    void returnLeaf(vector <string> &vec, TreeNode* node, string temp){
        if(!node){
            temp.pop_back();
            temp.pop_back();
            vec.push_back(temp);
            return ;
        } 
        temp+=to_string(node->val);
        temp+="->";
        
        if(!node->right)
            returnLeaf(vec, node->left, temp);
        else if(!node->left)    
            returnLeaf(vec, node->right, temp);
        else{
            returnLeaf(vec, node->left, temp);
            returnLeaf(vec, node->right, temp);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        vector <string> result;
        returnLeaf(result, root, "");
        return result;
    }
};
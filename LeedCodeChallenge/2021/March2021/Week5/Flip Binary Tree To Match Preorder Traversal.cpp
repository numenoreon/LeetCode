class Solution {
public:
    
    bool solve(TreeNode *node,vector<int>& vec, int &pos,vector<int> & result){
        if(!node)
            return true;
        pos=pos+1;
    
        if(node->val!=vec[pos])
            return false;
        if(node->left && node->left->val!=vec[pos+1]){
            result.push_back(vec[pos]);
        swap(node->left,node->right);
    }
    if(!solve(node->left,vec,pos,result))
        return false;
    return solve(node->right,vec,pos,result);
}

    
    vector<int> flipMatchVoyage(TreeNode *root, vector <int> & vec){
        vector <int> result;
        int pos = -1;
        if(!solve(root,vec,pos,result))
            return {-1};
        
        return result;
    }
};
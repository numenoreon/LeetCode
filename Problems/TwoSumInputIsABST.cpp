class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        queue <TreeNode*> makeVector;
        vector <int> findSum;
        
        makeVector.push(root);
        
        while(!makeVector.empty()){
            TreeNode* temp = makeVector.front();
            makeVector.pop();
            if(temp->left)
                makeVector.push(temp->left);
            if(temp->right)
                makeVector.push(temp->right);
            findSum.push_back(temp->val);
        }
        
        for(int i=0; i<findSum.size(); i++)
            for(int j=0; j<findSum.size(); ++j){
                if(i==j)
                    continue;
                else if(findSum[i]+findSum[j]==k)
                    return true;
            }
            
            
        return false;
        
    }
};
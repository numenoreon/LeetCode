class Solution {
public:
    void sumDown(TreeNode *root, int &result, vector <int> myVec){   
        if(!root)
            return;
        
        myVec.push_back(root->val);
        
        if(!root->left && !root->right){
            //cout << sum << " ";
            //result+=sum;
            int temp=1;
            for(int i=myVec.size()-1; i>-1; --i){
                result+=myVec[i]*temp;
                temp*=2;
            }
            
            return ;
        }
        sumDown(root->left, result, myVec);
        sumDown(root->right, result, myVec);
    }
    
    /*
    void TreeHeight(TreeNode* root, int &maxHeight, int pos){
        if(!root)
            return;
        maxHeight=max(maxHeight, pos);
        TreeHeight(root->left, maxHeight, pos+1);
        TreeHeight(root->right, maxHeight, pos+1);
    }
    */
    
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
            return 0;

        int result=0;
        sumDown(root, result, vector <int> ());
        
        return result;
    }
};
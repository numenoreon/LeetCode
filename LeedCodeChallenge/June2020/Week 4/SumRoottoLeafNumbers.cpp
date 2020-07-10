class Solution {
public:
    void inOrder(string temp, TreeNode* root, vector <string> &sum){
        if(!root)
            return ;
        
        temp+=to_string(root->val);
        if(!root->left && !root->right){
            sum.push_back(temp);
        }
        else{
            
            inOrder(temp, root->left, sum);
            inOrder(temp, root->right, sum);
        }
    }

    int sumNumbers(TreeNode* root) {
        vector <string> sum;
        inOrder("",root,sum);
        
        int result=0;
        for(auto &i : sum){
            cout << i << " ";
            result+=stoi(i);
        }
        
        return result;
    }
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        vector <int> result;
        queue <TreeNode*> myQueue;
        TreeNode *temp = nullptr;
        myQueue.push(root);
        while(myQueue.size()){
            int n=myQueue.size();
            while(n>1){
                temp=myQueue.front();
                myQueue.pop();
                if(temp->left)
                    myQueue.push(temp->left);
                if(temp->right)
                    myQueue.push(temp->right);
                --n;
            }
            temp=myQueue.front();
            result.push_back(temp->val);
            myQueue.pop();
                if(temp->left)
            myQueue.push(temp->left);
                if(temp->right)
            myQueue.push(temp->right);
                --n;            
        }
        
        return result;
    }
};
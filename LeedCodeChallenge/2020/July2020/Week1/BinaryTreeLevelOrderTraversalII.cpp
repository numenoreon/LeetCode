class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        queue <TreeNode*> myQueue;
        TreeNode* temp;
        myQueue.push(root);
        vector < vector <int> > results;

        while(!myQueue.empty()){
            int sz = myQueue.size();
            vector <int> tempVec;
            for(int i=0; i<sz; ++i){
                temp=myQueue.front();
                myQueue.pop();
                tempVec.push_back(temp->val);
                if(temp->left)
                    myQueue.push(temp->left);
                if(temp->right)
                    myQueue.push(temp->right);
            }
            results.push_back(tempVec);
        }
        reverse(results.begin(), results.end());
        return results;
    }
};
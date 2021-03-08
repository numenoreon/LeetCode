class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        vector<vector<int>> result;
        queue <TreeNode*> myQueue;
        TreeNode* tempNode = nullptr;
        myQueue.push(root);
        
        while (!myQueue.empty()) {
            int n=myQueue.size();
            vector <int> tempVec(n);
            
            for (int i=0; i<n; ++i) {
                tempNode=myQueue.front();
                myQueue.pop();
                if (result.size()%2==0)
                    tempVec[i]=tempNode->val;
                else
                    tempVec[n-1-i]=tempNode->val;
                
                if(tempNode->left)
                    myQueue.push(tempNode->left);
                if (tempNode->right)
                    myQueue.push(tempNode->right);
            }
            result.push_back(tempVec);
        }
        
        return result;
    }
};
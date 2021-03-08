class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue <TreeNode*> myQueue;
        double counter=0;
        vector <double> result {};
        myQueue.push(root);
        int qSize=0, divider=0;
        TreeNode *tempNode=nullptr;
        
        while(myQueue.size()){
            divider=qSize=myQueue.size();
            counter=0;
            while(qSize--){
                tempNode=myQueue.front();
                myQueue.pop();
                if(tempNode->left)
                    myQueue.push(tempNode->left);
                if(tempNode->right)
                    myQueue.push(tempNode->right);
                counter+=tempNode->val;
            }
            result.push_back(counter/divider);
        }
              
        return result;
    }
};
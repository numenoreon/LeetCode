class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue <TreeNode*> myQueue;
        if(!root)
            return {};
        vector <int> result;
        int maximum=INT_MIN;
        myQueue.push(root);
        while(!myQueue.empty()){
            int n=myQueue.size();
            maximum=INT_MIN;
            while(n--){
                maximum=max(maximum,myQueue.front()->val);
                if(myQueue.front()->left)
                    myQueue.push(myQueue.front()->left);
                if(myQueue.front()->right)
                    myQueue.push(myQueue.front()->right);
                myQueue.pop();
            }
            result.push_back(maximum);
        }
        return result;
    }
};
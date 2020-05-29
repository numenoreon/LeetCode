class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        vector <pair <int, int>> myVec;
        queue <pair<TreeNode*, pair<int, int>>> myQueue;
        myQueue.push({root, {0,0}});
        pair <int, int> tempPair;
        TreeNode* tempNode;
        
        while(!myQueue.empty()){
            int n=myQueue.size();
            while(n--){
                tempNode=myQueue.front().first;
                tempPair=myQueue.front().second;
                myQueue.pop();
                if(tempNode->val == x || tempNode->val == y)
                    myVec.push_back({tempPair.first, tempPair.second});

                if(tempNode->left)
                    myQueue.push({tempNode->left, {tempPair.first+1, 2*tempPair.second}});
                if(tempNode->right)
                    myQueue.push({tempNode->right, {tempPair.first+1, 2*tempPair.second+1}});
            }
        }
        
        if(myVec[0].first == myVec[1].first && myVec[0].second != myVec[1].second+1 
            && myVec[0].second != myVec[1].second && myVec[0].second+1 != myVec[1].second)
            return true;
        
        return false;
    }
};
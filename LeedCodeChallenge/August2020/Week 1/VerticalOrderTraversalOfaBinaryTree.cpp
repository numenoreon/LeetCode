class Solution {
public:
    
    int maxLeft(TreeNode *root){
        int counter=0;
        while(root){
            root=root->left;
            ++counter;
        }
        return counter;
    }
    
    int maxRight(TreeNode *root){
        int counter=0;
        while(root){
            root=root->right;
            ++counter;
        }
        return counter;
    }
    
    void maxWidth(TreeNode *root, int &left, int &right, int pos){
        if(!root)
            return;
        left=min(left, pos);
        right=max(right, pos);
        maxWidth(root->left, left, right, pos-1);
        maxWidth(root->right, left, right, pos+1);
    }
    
    void preOrder(TreeNode *root, int pos, vector <vector <int>> &result){
        if(!root)
            return ;
        result[pos].push_back(root->val);
        preOrder(root->left, pos-1, result);
        preOrder(root->right, pos+1, result);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        //int left=maxLeft(root);
        //int right=maxRight(root);
        int left=INT_MAX, right=INT_MIN;
        maxWidth(root, left, right, 0);
        cout << left << " " << right << endl;
        
        vector <vector <int>> result (right-left+1, vector <int> ());
        //cout << result.size();
        //preOrder(root, abs(left), result);
        
        queue <pair<TreeNode*, int>> myQueue;
        myQueue.push({root,abs(left)});
        //TreeNode *temp=nullptr;
        
        while(!myQueue.empty()){
            int sz = myQueue.size();
            //cout << sz;
            while(sz>0){
                auto temp=myQueue.front();
                myQueue.pop();
                if(temp.first->left)
                    myQueue.push({temp.first->left,temp.second-1});
                if(temp.first->right)
                    myQueue.push({temp.first->right,temp.second+1});
                result[temp.second].push_back(temp.first->val);
                --sz;
            }
        }
        
        return result;
    }
};
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int result = 0;
        
        while(!q.empty()) {
            int queueSize=q.size();
            if(queueSize == 1) // to avoid overflow
                q.front().second = 1;
            result = max(result, q.back().second - q.front().second+1);
            while(queueSize){
                auto current = q.front();
                q.pop();
                if(current.first->left)
                    q.push(make_pair(current.first->left, 2*current.second-1));
                if(current.first->right)
                    q.push(make_pair(current.first->right, 2*current.second));
                --queueSize;
            }
            
        }
        return result;
    }
};

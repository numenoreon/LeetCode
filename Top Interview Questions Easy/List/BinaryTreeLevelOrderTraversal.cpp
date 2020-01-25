class Solution {
public:
     vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};

            queue<TreeNode*> q;
            q.push(root);
            vector<int> temp;
            vector<vector<int>> result;
            while(!q.empty())
            {
                int count = q.size();
                while(count>0){
                    TreeNode* Node=q.front();
                    q.pop();
                    temp.push_back(Node->val);
                    if(Node->left!=nullptr)
                        q.push(Node->left);
                    if(Node->right!=nullptr)
                        q.push(Node->right);
                    --count;
                }  
                result.push_back(temp);
                temp.clear();
            }
             return result;
         }
};
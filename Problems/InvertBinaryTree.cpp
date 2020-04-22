class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        queue<TreeNode*> myQueue;
        TreeNode *tempNode;
        myQueue.push(root);
        while(!myQueue.empty()){
            tempNode = myQueue.front()->left;
            myQueue.front()->left = myQueue.front()->right;
            myQueue.front()->right = tempNode;
            
            if(myQueue.front()->left){
                myQueue.push(myQueue.front()->left);
            }
            if(myQueue.front()->right){
                myQueue.push(myQueue.front()->right);
            }
            myQueue.pop();
        }
        return root;
    }
};
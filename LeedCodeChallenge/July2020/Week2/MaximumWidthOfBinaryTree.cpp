struct NodeNr{
    TreeNode* Node;
    unsigned long long pos;
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue <NodeNr> myQueue;
        myQueue.push({root,0});
        NodeNr temp;
        while(myQueue.size()){
            unsigned long long sz = myQueue.size();
            maximumLength=max(maximumLength,myQueue.back().pos-myQueue.front().pos+1);
            while(sz--){
                temp=myQueue.front();
                myQueue.pop();
                if(temp.Node->left)
                    myQueue.push({temp.Node->left, temp.pos*2});
                if(temp.Node->right)
                    myQueue.push({temp.Node->right, temp.pos*2+1});
            }
            cout << maximumLength;
        }
        return maximumLength;
    }
private:
    unsigned long long maximumLength=1;
};
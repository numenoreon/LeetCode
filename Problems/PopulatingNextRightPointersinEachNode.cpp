class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        queue <Node*> myQueue;
        myQueue.push(root);
        Node* tempNode=nullptr;

        while(!myQueue.empty()){
            int count=myQueue.size();
            while(count--){
                tempNode=myQueue.front();
                myQueue.pop();
                
                if(tempNode->left!=nullptr)
                    myQueue.push(tempNode->left);
                if(tempNode->right!=nullptr)
                    myQueue.push(tempNode->right);
            
                if(count)
                    tempNode->next=myQueue.front();
                else
                    tempNode->next=nullptr;
            }
        }
        return root;
    }
};
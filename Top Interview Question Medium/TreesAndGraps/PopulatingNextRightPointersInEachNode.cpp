class Solution {
public:
    Node* connect(Node* root) {
    if(!root)
        return nullptr;
    queue <Node*> q;
    q.push(root);
    int n=0;
    int p=1;

    int counter=0;
    while(!q.empty()){
        ++n;
        Node *temp = q.front();
        
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        q.pop();
        
        if(n==p){
            n=0;
            p*=2;
            temp->next=nullptr;
        }
        else{
                temp->next=q.front();
        }

    }
    return root;   
    }
};

_______________________________________________________________________________________
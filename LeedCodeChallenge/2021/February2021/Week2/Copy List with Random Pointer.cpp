class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        
        vector <Node*> nodes;
        Node* temp = head;
        
        while(temp){
            nodes.push_back(temp);
            temp=temp->next;
        }
        
        vector <Node*> newNode (nodes.size(), nullptr);
        
        for(int i=0; i<nodes.size(); ++i){
            newNode[i]=new Node(nodes[i]->val);
        }
        
        for(int i=0; i<newNode.size()-1; ++i){
            newNode[i]->next=newNode[i+1];
        }
        
        for(int i=0; i<nodes.size(); ++i){
            if(nodes[i]->random){
                auto it = find(nodes.begin(), nodes.end(), nodes[i]->random);
                int position = it-nodes.begin();
                newNode[i]->random=newNode[position];
            }
        }
        
        return newNode[0];
    }
};

___________________________________________________________________________________________________________________________



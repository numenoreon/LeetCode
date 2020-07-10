class Solution {
public:
    
    void createQueue(Node* head){
        Node* temp = head;
        while(temp){
            myQueue.push(temp);
            if(temp->child){
                createQueue(temp->child);
                temp->child = nullptr;
            }
            temp=temp->next;
        }
    }
    
    Node* flatten(Node* head) {
        if(!head)
            return 0;
        createQueue(head);
        
        head=myQueue.front();
        myQueue.pop();
        Node* temp=head;
        while(!myQueue.empty()){
            temp->next=myQueue.front();
            myQueue.front()->prev=temp;
            temp=myQueue.front();
            myQueue.pop();
        }
        temp->next = nullptr;
        head->prev = nullptr;
        return head;
    }
private:
    queue <Node*> myQueue;
};
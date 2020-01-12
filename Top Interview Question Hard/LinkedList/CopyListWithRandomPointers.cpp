class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node *newHead = new Node (head->val);
        Node *temp = head;
        Node *tempNewHead = newHead;
        Node *tempRandom, *tempNext;
        
        while(temp->next){
            tempNewHead->next=new Node(temp->next->val);    
            tempNewHead=tempNewHead->next;
            temp=temp->next;
        }
        
        temp=head;
        tempNewHead=newHead;

        while(temp){

            if(temp->random==nullptr){
                temp=temp->next;
                tempNewHead=tempNewHead->next;
                continue;
            }   
            
            tempRandom = newHead, tempNext=head;
            
            while(tempNext!=temp->random){
                tempNext=tempNext->next;
                tempRandom=tempRandom->next;
            }
            
            tempNewHead->random=tempRandom;
            temp=temp->next;
            tempNewHead=tempNewHead->next;
        }
        
        return newHead;
    }
};
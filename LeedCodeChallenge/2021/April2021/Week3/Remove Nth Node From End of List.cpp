class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return nullptr;
        if(!head->next){
            delete head;
            return nullptr;
        }
    ListNode * tempHead = head, *temp;
    
    int counter=0;
      
    while(tempHead){
        ++counter;
        tempHead=tempHead->next;
    }
    
    tempHead=head;
    counter-=n;
    
    if(counter==0){
        head=head->next;
        delete tempHead;
        return head;
    }
        
    while(counter--)
    {
        temp=tempHead;
        tempHead=tempHead->next;
    }
    
    temp->next=tempHead->next;
    delete tempHead;
      
    return head;
    }
};
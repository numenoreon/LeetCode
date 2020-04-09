class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(!head)
            return {};
        
        ListNode* temp;
        
        while(head->val==val){
            temp=head;
            head=head->next;
            delete temp;
            if(!head)
                return {};
        }
        
        ListNode* before=head;
        temp=head->next;
        
        while(temp){
            if(temp->val==val){
                before->next=temp->next;
                delete temp;
                temp = before->next;
            }
            else{
                before=temp;
                temp=temp->next;
            }
        }
        
        return head;
    }
};
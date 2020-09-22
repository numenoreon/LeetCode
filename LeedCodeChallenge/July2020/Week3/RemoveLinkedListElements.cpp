class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(!head)
            return nullptr;
        
        while(head && head->val==val){
            ListNode *temp = head;
            head=head->next;
            delete temp;
        }

        if(!head)
            return nullptr;
        
        ListNode *temp1 = head, *temp2=head->next;
        
        while(temp2){
            if(temp2->val==val){
                ListNode *temp = temp2;
                temp1->next=temp2->next;
                temp2=temp2->next;
                delete temp;
                continue;
            }
            temp1=temp2;
            temp2=temp2->next;
        }
        
        
        return head;
    }
};
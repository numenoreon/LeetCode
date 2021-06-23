class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) {
            return nullptr;
        }
        
        ListNode* prev = nullptr;
        ListNode* temp = head;
        int counter=1;
        
        while(counter<left){
            prev=temp;
            temp=temp->next;
            ++counter;
        }
        
        ListNode* savedPosition = temp;
        ListNode* prev1 = prev;
        ListNode* temp1 = nullptr;
        
        int period = right-left+1;
        
        while(period>0){
            temp1=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
            --period;
        }
        
        if(prev1)
           prev1->next=prev;
        else
            head=prev;
        
        savedPosition->next=temp;
        
        return head;
    }
};
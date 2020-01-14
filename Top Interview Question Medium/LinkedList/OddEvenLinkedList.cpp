
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode *odd=head, *even=odd->next, *evenEnd=even, *temp=even->next;
        int c=1;
        while(temp){
            if(c%2==0){
                even->next=temp;
                even=even->next;
            }
            else if(c%2==1){
                odd->next=temp;
                odd=odd->next;
            }
        ++c;
        temp=temp->next;
        }
    odd->next=evenEnd;
    even->next=nullptr;
        
    return head;
    }
};

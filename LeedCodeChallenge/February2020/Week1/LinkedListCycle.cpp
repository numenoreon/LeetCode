class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        
        ListNode *temp1 = head, *temp2 = head;
        
        while(temp2 && temp2->next!=nullptr && temp1 != temp2->next ){
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        
        if(!temp2 || !temp2->next)
            return false;
        
        return true;
    }
};
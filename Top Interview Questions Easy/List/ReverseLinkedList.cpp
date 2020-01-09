class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next) return head;
        ListNode* tempHead = head;
        ListNode* temp1=nullptr;
        ListNode* temp2;
        
        while(tempHead){
            temp2=tempHead->next;
            tempHead->next=temp1;
        
            temp1=tempHead;
            tempHead=temp2;
        }   
        
        return temp1;
    }
};

________________________________________________________________________________________________________________

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    if(!head || !head->next)
            return head;
        return reverse(head, NULL);
    }
    ListNode* reverse(ListNode* head, ListNode* add){
        if(head == NULL)
            return add;
        ListNode* temp = head->next;
        head->next = add;
        return reverse(temp, head);
    }
};

Lepsze
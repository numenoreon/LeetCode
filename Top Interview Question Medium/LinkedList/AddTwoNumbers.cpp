
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    ListNode *newHead = new ListNode(l1->val+l2->val);
    ListNode *temp1=l1->next, *temp2=l2->next, *tempHead=newHead;
        
    while(temp1 && temp2){
        int temp = temp1->val+temp2->val;

        tempHead->next = new ListNode (temp);
        tempHead=tempHead->next;
        temp1=temp1->next;
        temp2=temp2->next;
    }
        
    while(temp1){
        tempHead->next = new ListNode (temp1->val);
        tempHead=tempHead->next;
        temp1=temp1->next;
    }
    
    while(temp2){
        tempHead->next = new ListNode (temp2->val);
        tempHead=tempHead->next;
        temp2=temp2->next;
    }
    
    tempHead = newHead;
        
    while(tempHead){
        if(tempHead->next == nullptr && tempHead->val >= 10){
        tempHead->next=new ListNode(tempHead->val/10);
        tempHead->val=tempHead->val%10;
        }
        else if(tempHead->val >= 10){
        tempHead->next->val+=tempHead->val/10;
        tempHead->val=tempHead->val%10;
        }
        tempHead=tempHead->next;
        
    }
    return newHead;
      
    }
};
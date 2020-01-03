class Solution {
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return nullptr;
        else if(!l1)
            return l2;
        else if(!l2)
            return l1;
        
        ListNode* l3 = new ListNode(0);
        ListNode* newHead=l3;
        
        if(l1->val > l2->val){
            l3->val = l2->val;
            l2=l2->next;
        }
        else{
            l3->val = l1->val;
            l1=l1->next;
        }
        
        while(l1 && l2){
            if(l1->val > l2->val){
                l3->next = l2;
                l3=l3->next;
                l2=l2->next;    
            }
            else{
                l3->next = l1;
                l3=l3->next;
                l1=l1->next;       
            }
        }
        
        while(l1){
            l3->next = l1;
            l3=l3->next;
            l1=l1->next; 
        }
        
        while(l2){
            l3->next = l2;
            l3=l3->next;
            l2=l2->next;   
        }
            return newHead;
    }

};